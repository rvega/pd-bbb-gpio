'' complex/compound/composite symbols helper functions
''
'' chng: sep/2006 written [v1ctor]


#include once "fb.bi"
#include once "fbint.bi"

type FB_SYMBNEST
	sym				as FBSYMBOL ptr
	symtb			as FBSYMBOLTB ptr			'' prev symbol tb
	hashtb			as FBHASHTB ptr				'' prev hash tb
	ns				as FBSYMBOL ptr				'' prev namespace
end type

sub symbCompInit( )
	for i as integer = 0 to AST_OPCODES-1
		symb.globOpOvlTb(i).head = NULL
	next

	stackNew( @symb.neststk, 16, len( FB_SYMBNEST ), FALSE )
end sub

sub symbCompEnd( )
	stackFree( @symb.neststk )
end sub

sub symbUdtAllocExt( byval udt as FBSYMBOL ptr )
	assert( symbIsStruct( udt ) )
	if( udt->udt.ext = NULL ) then
		udt->udt.ext = xcallocate( sizeof( FB_STRUCTEXT ) )
	end if
end sub

''::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
'' default ctors
''::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

private function hDeclareProc _
	( _
		byval udt as FBSYMBOL ptr, _
		byval op as AST_OP, _
		byval add_rhs as integer, _
		byval attrib as FB_SYMBATTRIB _
	) as FBSYMBOL ptr

	dim as FBSYMBOL ptr proc = any

	'' Into the UDT namespace
	symbNestBegin( udt, TRUE )

	proc = symbPreAddProc( NULL )

	'' add "this"
	symbAddProcInstancePtr( udt, proc )

	'' add right-side hand param?
	if( add_rhs ) then
		assert( symbIsStruct( udt ) )
		symbAddProcParam( proc, "__FB_RHS__", FB_DATATYPE_STRUCT, udt, _
		                  FB_PARAMMODE_BYREF, FB_SYMBATTRIB_NONE )
	end if

	attrib or= FB_SYMBATTRIB_METHOD
	attrib or= FB_SYMBATTRIB_PRIVATE

	'' cons|destructor?
	if( op = INVALID ) then
		proc = symbAddCtor( proc, NULL, attrib, _
		                    FB_FUNCMODE_CDECL, FB_SYMBOPT_DECLARING )
	'' op..
	else
		proc = symbAddOperator( proc, op, NULL, FB_DATATYPE_VOID, NULL, attrib, _
		                        FB_FUNCMODE_CDECL, FB_SYMBOPT_DECLARING )
	end if

	'' Close the namespace again
	symbNestEnd( TRUE )

	function = proc
end function

private sub hSetMinimumVtableSize( byval udt as FBSYMBOL ptr )
	'' vtables always have at least 2 elements (following GCC):
	''    index 0: a NULL pointer
	''    index 1: the pointer to this type's RTTI table
	'' Slots for the pointers for virtual methods start at index 2.
	''
	'' Note: A vtable must be generated even if there are no virtuals,
	'' to support RTTI. In that case it will only have the first two
	'' elements (null and rtti pointers).

	if( udt->udt.ext->vtableelements = 0 ) then
		udt->udt.ext->vtableelements = 2
	end if
end sub

private sub hBuildRtti( byval udt as FBSYMBOL ptr )
	static as FBARRAYDIM dTB(0)
	dim as ASTNODE ptr initree = any, rttibase = any
	dim as FBSYMBOL ptr rtti = any, fld = any
	dim as string id

	'' static shared id as $fb_RTTI
	id = "_ZTS" + *symbGetMangledName( udt )
	rtti = symbAddVar( NULL, id, FB_DATATYPE_STRUCT, symb.rtti.fb_rtti, 0, 0, dTB(), _
	                   FB_SYMBATTRIB_CONST or FB_SYMBATTRIB_STATIC or FB_SYMBATTRIB_SHARED, _
	                   FB_SYMBOPT_PRESERVECASE )
	udt->udt.ext->rtti = rtti

	'' initializer
	initree = astTypeIniBegin( FB_DATATYPE_STRUCT, symb.rtti.fb_rtti, FALSE, 0 )
	astTypeIniScopeBegin( initree, rtti )

		'' stdlibvtable = NULL
		fld = symbUdtGetFirstField( symb.rtti.fb_rtti )
		astTypeIniAddAssign( initree, astNewCONSTi( 0, typeAddrOf( FB_DATATYPE_VOID ), NULL ), fld )

		'' id = @"mangled name"
		fld = symbUdtGetNextInitableField( fld )
		astTypeIniAddAssign( initree, astNewADDROF( astNewVAR( symbAllocStrConst( symbGetMangledName( udt ), -1 ) ) ), fld )

		'' rttibase = @(base's RTTI data) or NULL if there is no base
		fld = symbUdtGetNextInitableField( fld )
		if( udt->udt.base ) then
			rttibase = astNewADDROF( astNewVAR( udt->udt.base->subtype->udt.ext->rtti ) )
		else
			rttibase = astNewCONSTi( 0, typeAddrOf( FB_DATATYPE_VOID ) )
		end if
		astTypeIniAddAssign( initree, rttibase, fld )

	astTypeIniScopeEnd( initree, rtti )
	astTypeIniEnd( initree, TRUE )

	symbSetTypeIniTree( rtti, initree )
	symbSetIsInitialized( rtti )
end sub

private sub hBuildVtable( byval udt as FBSYMBOL ptr )
	static as FBARRAYDIM dTB(0)
	dim as ASTNODE ptr initree = any, basevtableinitree = any
	dim as FBSYMBOL ptr member = any, rtti = any, vtable = any
	dim as integer i = any, basevtableelements = any
	dim as string id

	'' The vtable is an array of pointers:
	''    0. null pointer (why? just following GCC...)
	''    1. rtti pointer
	''    2. and following: procptrs corresponding to virtual methods
	''                      in the order they were parsed.

	assert( udt->udt.ext->vtableelements >= 2 )

	'' static shared vtable(0 to elements-1) as any ptr
	id = "_ZTV" + *symbGetMangledName( udt )
	dTB(0).upper = udt->udt.ext->vtableelements - 1
	vtable = symbAddVar( NULL, id, typeAddrOf( FB_DATATYPE_VOID ), NULL, 0, 1, dTB(), _
	                     FB_SYMBATTRIB_CONST or FB_SYMBATTRIB_STATIC or FB_SYMBATTRIB_SHARED, _
	                     FB_SYMBOPT_PRESERVECASE )

	'' Find information about the base UDT's vtable:
	''    the number of elements,
	''    and the initree (so it can be copied into the new vtable)
	''
	'' - If the base has no virtuals, vtableelements will be 2
	''   (due to hSetMinimumVtableSize())
	'' - If the base is OBJECT, the vtable is hidden in the rtlib,
	''   thus there is no initree for us to use. Luckily we don't need it
	''   anyways, since OBJECT doesn't have any virtuals.
	assert( symbIsField( udt->udt.base ) )
	assert( symbGetType( udt->udt.base ) = FB_DATATYPE_STRUCT )
	assert( symbIsStruct( udt->udt.base->subtype ) )
	basevtableelements = udt->udt.base->subtype->udt.ext->vtableelements
	'' Any virtuals (more than the default 2 elements)?
	if( basevtableelements > 2 ) then
		assert( symbIsVar( udt->udt.base->subtype->udt.ext->vtable ) )
		basevtableinitree = udt->udt.base->subtype->udt.ext->vtable->var_.initree
	else
		basevtableinitree = NULL
	end if

	'' {
	initree = astTypeIniBegin( typeAddrOf( FB_DATATYPE_VOID ), NULL, FALSE, 0 )
	astTypeIniScopeBegin( initree, vtable )

	'' 0. null pointer = NULL
	astTypeIniAddAssign( initree, astNewCONSTi( 0, typeAddrOf( FB_DATATYPE_VOID ) ), vtable )

	'' 1. rtti pointer = @rtti
	rtti = udt->udt.ext->rtti
	astTypeIniAddAssign( initree, astNewADDROF( astNewVAR( rtti ) ), vtable )

	'' initialize inherited procptrs, to the same expression as in the
	'' base vtable's initializer
	i = 2
	if( basevtableinitree ) then
		'' Copy the typeini assigns from the base vtable's initializer,
		'' except the first 2 (they are set above already)
		astTypeIniCopyElements( initree, basevtableinitree, 2 )
		assert( basevtableelements > 2 )
		i += (basevtableelements - 2)
	end if

	'' Fill new vtable entries with NULLs first, to be safe, and also to
	'' initialize any new unimplemented pure-virtual slots.
	'' We could let them point to __cxa_pure_virtual() like gcc,
	'' but with a NULL pointer crash instead of the abort() we'll actually
	'' get a more useful run-time error under -exx.
	while( i <= dTB(0).upper )
		astTypeIniAddAssign( initree, astNewCONSTi( 0, typeAddrOf( FB_DATATYPE_VOID ) ), vtable )
		i += 1
	wend

	'' }
	astTypeIniScopeEnd( initree, vtable )
	astTypeIniEnd( initree, TRUE )

	symbSetTypeIniTree( vtable, initree )
	symbSetIsInitialized( vtable )

	'' 1. new (and not inherited) entries for ...
	''  - virtuals: must be set to point to their bodies for now.
	''    (not yet overridden)
	''  - abstracts: are set to point to fb_AbstractStub() (our version
	''    of GCC's __cxa_pure_virtual()), which will show a run-time
	''    error message and abort the program.
	''
	'' 2. any entries for inherited virtuals/abstracts that were overridden
	''    by a normal method must be updated to point to the normal method.

	'' For each member of this UDT (does not include inherited members)
	member = symbGetCompSymbTb( udt ).head
	while( member )
		'' procedure?
		if( symbIsProc( member ) ) then
			i = symbProcGetVtableIndex( member )
			if( (i > 0) and (not symbIsAbstract( member )) ) then
				astTypeIniReplaceElement( initree, i, astBuildProcAddrof( member ) )
			end if
		end if
		member = member->next
	wend

	udt->udt.ext->vtable = vtable
end sub

private sub hProcBegin( byval udt as FBSYMBOL ptr, byval proc as FBSYMBOL ptr )
	'' constructor|destructor|operator parent[.let]( ... )
	symbNestBegin( udt, TRUE )
	astProcBegin( proc, FALSE )
end sub

private sub hProcEnd( )
	'' end constructor|destructor|operator
	astProcEnd( FALSE )
	symbNestEnd( TRUE )
end sub

private sub hAddCtorBody _
	( _
		byval udt as FBSYMBOL ptr, _
		byval proc as FBSYMBOL ptr, _
		byval is_copyctor as integer _
	)

	dim as FBSYMBOL ptr this_ = any, src = any

	'' The AST will add any implicit base/field construction/destruction
	'' code automatically
	hProcBegin( udt, proc )

	if( is_copyctor ) then
		this_ = symbGetParamVar( symbGetProcHeadParam( proc ) )
		src = symbGetParamVar( symbGetProcTailParam( proc ) )

		'' assign op overload will do the rest
		astAdd( astNewASSIGN( astBuildInstPtr( this_ ), astBuildInstPtr( src ) ) )
	end if

	hProcEnd( )

	symbSetCantUndef( udt )
end sub

'':::::
private sub hAssignList _
	( _
		byval fld as FBSYMBOL ptr, _
		byval dstexpr as ASTNODE ptr, _
		byval srcexpr as ASTNODE ptr _
	) static

	dim as FBSYMBOL ptr cnt, label, dst, src, subtype

	subtype = symbGetSubtype( fld )

	cnt = symbAddTempVar( FB_DATATYPE_INTEGER )
    label = symbAddLabel( NULL )
    dst = symbAddTempVar( typeAddrOf( symbGetType( fld ) ), subtype )
    src = symbAddTempVar( typeAddrOf( symbGetType( fld ) ), subtype )

    '' dst = @this.dst(0)
    astAdd( astBuildVarAssign( dst, astNewADDROF( dstexpr ) ) )
    '' src = @this.src(0)
    astAdd( astBuildVarAssign( src, astNewADDROF( srcexpr ) ) )

	'' for cnt = 0 to symbGetArrayElements( dst )-1
	astAdd( astBuildForBegin( NULL, cnt, label, 0 ) )

    '' *dst = *src
    astAdd( astNewASSIGN( astBuildVarDeref( dst ), astBuildVarDeref( src ) ) )

	'' dst += 1
    astAdd( astBuildVarInc( dst, 1 ) )
	'' src += 1
    astAdd( astBuildVarInc( src, 1 ) )

	'' next
	astAdd( astBuildForEnd( NULL, cnt, label, 1, astNewCONSTi( symbGetArrayElements( fld ) ) ) )

end sub

'':::::
private function hCopyUnionFields _
	( _
		byval this_ as FBSYMBOL ptr, _
		byval rhs as FBSYMBOL ptr, _
		byval base_fld as FBSYMBOL ptr _
	) as FBSYMBOL ptr

	dim as FBSYMBOL ptr fld = any
	dim as integer bytes = any, lgt = any, base_ofs = any

	'' merge all union fields
	fld = base_fld
	bytes = 0
	base_ofs = symbGetOfs( base_fld )

	do
		lgt = (symbGetLen( fld ) * symbGetArrayElements( fld )) + _
			  (symbGetOfs( fld ) - base_ofs)
		if( lgt > bytes ) then
			bytes = lgt
		end if

		fld = fld->next
		if( fld = NULL ) then
			exit do
		end if
	loop while( symbGetIsUnionField( fld ) )

    '' copy all them at once
	astAdd( astNewMEM( AST_OP_MEMMOVE, _
    	  	  		   astBuildInstPtr( this_, base_fld ), _
    	  	  		   astBuildInstPtr( rhs, base_fld ), _
    	  	  		   bytes ) )

	function = fld

end function

private sub hAddLetOpBody _
	( _
		byval udt as FBSYMBOL ptr, _
		byval letproc as FBSYMBOL ptr _
	)

	dim as FBSYMBOL ptr fld = any, this_ = any, rhs = any
	dim as ASTNODE ptr dstexpr = any, srcexpr = any

	hProcBegin( udt, letproc )

	this_ = symbGetParamVar( symbGetProcHeadParam( letproc ) )
	rhs = symbGetParamVar( symbGetProcTailParam( letproc ) )

	'' for each field
	fld = symbGetCompSymbTb( udt ).head
	while( fld )
		if( symbIsField( fld ) ) then
			'' part of an union?
			if( symbGetIsUnionField( fld ) ) then
				fld = hCopyUnionFields( this_, rhs, fld )
				continue while
			end if

			dstexpr = astBuildInstPtr( this_, fld )
			srcexpr = astBuildInstPtr( rhs, fld )

			'' not an array?
			if( (symbGetArrayDimensions( fld ) = 0) or _
			    (symbGetArrayElements( fld ) = 1) ) then
				'' this.field = rhs.field
				astAdd( astNewASSIGN( dstexpr, srcexpr ) )
			'' array..
			else
				hAssignList( fld, dstexpr, srcexpr )
			end if
		end if

		fld = fld->next
	wend

	hProcEnd( )

	symbSetCantUndef( udt )

end sub

'' Declare & add any implicit/default members and global vars if needed
sub symbUdtAddDefaultMembers( byval udt as FBSYMBOL ptr )
	dim as FBSYMBOL ptr defctor = any, copyctor = any, letop = any, dtor = any
	dim as integer base_without_defaultctor = any

	''
	'' If this UDT has fields with ctors, we have to make sure to add
	'' default and copy ctors aswell as a dtor and a Let operator to the
	'' parent, if the user didn't do that yet. This ensures the fields'
	'' ctors/dtors will be called and also that they will be copied
	'' correctly: In case they have Let overloads themselves, we can't just
	'' do the default memcpy(). (If the parent already has a Let overload,
	'' we can assume it's correct already)
	''
	'' Besides that, in case there were any field initializers specified,
	'' we want to add a default constructor if there isn't any constructor
	'' yet, to ensure the field initializers are getting used.
	''

	'' Derived?
	if( udt->udt.base ) then
		assert( symbIsField( udt->udt.base ) )
		assert( symbGetType( udt->udt.base ) = FB_DATATYPE_STRUCT )
		assert( symbIsStruct( udt->udt.base->subtype ) )
		'' No default ctor?
		base_without_defaultctor = (symbGetCompDefCtor( udt->udt.base->subtype ) = NULL)
	else
		base_without_defaultctor = FALSE
	end if

	defctor = NULL
	copyctor = NULL
	letop = NULL
	dtor = NULL

	'' Ctor/inited fields and no ctor yet?
	if( (symbGetUDTHasCtorField( udt ) or symbGetUDTHasInitedField( udt )) and _
	    (symbGetCompCtorHead( udt ) = NULL) ) then
		if( base_without_defaultctor ) then
			'' Cannot implicitly generate a default ctor,
			'' show a nicer error message than astProcEnd() would.
			'' It would report the missing BASE() initializer,
			'' but from here we can show a more useful error.
			errReport( FB_ERRMSG_NEEDEXPLICITDEFCTOR )
		else
			'' Add default ctor
			defctor = hDeclareProc( udt, INVALID, FALSE, FB_SYMBATTRIB_OVERLOADED or FB_SYMBATTRIB_CONSTRUCTOR )
		end if
	end if

	if( symbGetUDTHasCtorField( udt ) ) then
		'' Let operator (must be defined before the copy ctor)
		if( symbGetCompCloneProc( udt ) = NULL ) then
			letop = hDeclareProc( udt, AST_OP_ASSIGN, TRUE, FB_SYMBATTRIB_OVERLOADED or FB_SYMBATTRIB_OPERATOR )

			'' Don't allow the implicit LET to override a FINAL LET from the base
			symbProcCheckOverridden( letop, TRUE )
		end if

		'' Copy ctor
		if( symbGetCompCopyCtor( udt ) = NULL ) then
			if( base_without_defaultctor ) then
				'' Cannot implicitly generate a copy ctor,
				'' same as with default ctor above.
				errReport( FB_ERRMSG_NEEDEXPLICITCOPYCTOR )
			else
				copyctor = hDeclareProc( udt, INVALID, TRUE, FB_SYMBATTRIB_OVERLOADED or FB_SYMBATTRIB_CONSTRUCTOR )
			end if
		end if
	end if

	'' has fields with dtors?
	if( symbGetUDTHasDtorField( udt ) ) then
		'' no default dtor explicitly defined?
		if( symbGetCompDtor( udt ) = NULL ) then
			'' Dtor
			dtor = hDeclareProc( udt, INVALID, FALSE, FB_SYMBATTRIB_DESTRUCTOR )

			'' Don't allow the implicit dtor to override a FINAL dtor from the base
			symbProcCheckOverridden( dtor, TRUE )
		end if
	end if

	''
	'' Add vtable and rtti global variables
	''
	'' - The vtable can only be created once all methods are known,
	''   how many virtuals there are, which method overrides virtuals
	''   from the base, etc.
	''   Even the implicit destructor (if any) must be declared before
	''   the vtable is added, in case it should override a virtual dtor.
	''
	'' - Creating the vtable depends on FBSYMBOL.udt.ext->rtti being set,
	''   because the vtable includes a pointer to the rtti table,
	''   thus the rtti table should be added before the vtable.
	''
	'' - Any constructor body depends on FBSYMBOL.udt.ext->vtable being set,
	''   so the vtable must be added before any constructor bodies.
	''
	if( symbGetHasRTTI( udt ) ) then
		symbUdtAllocExt( udt )
		hSetMinimumVtableSize( udt )

		'' only if it isn't FB's own Object base super class
		'' (for which the rtlib already contains these declarations)
		if( udt <> symb.rtti.fb_object ) then
			hBuildRtti( udt )
			hBuildVtable( udt )
		end if
	end if

	''
	'' Add bodies if any implicit ctor/dtor/let procs were declared above
	''
	if( defctor ) then
		hAddCtorBody( udt, defctor, FALSE )
	end if

	if( copyctor ) then
		hAddCtorBody( udt, copyctor, TRUE )
	end if

	if( letop ) then
		hAddLetOpBody( udt, letop )
	end if

	if( dtor ) then
		hAddCtorBody( udt, dtor, FALSE )
	end if
end sub

''::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
'' getters/setters
''::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

'':::::
private function hIsLhsEqRhs _
	( _
		byval parent as FBSYMBOL ptr, _
		byval proc as FBSYMBOL ptr _
	) as integer static

	dim as FBSYMBOL ptr param, subtype

	function = FALSE

	param = symbGetProcTailParam( proc )
	if( symbGetParamMode( param ) = FB_PARAMMODE_BYREF ) then
		subtype = symbGetSubtype( param )

		if( subtype = NULL ) then
			return FALSE
		end if

		'' forward?
		if( symbGetClass( subtype ) = FB_SYMBCLASS_FWDREF ) then
			'' not a pointer?
			if( symbGetType( param ) = FB_DATATYPE_FWDREF ) then
				'' same name?
				if( subtype->hash.index = parent->hash.index ) then
					return TRUE
				end if
			end if

			return FALSE
		end if

		if( subtype = parent ) then
			select case symbGetClass( parent )
			case FB_SYMBCLASS_STRUCT
				function = ( symbGetType( param ) = FB_DATATYPE_STRUCT )

			case FB_SYMBCLASS_CLASS
				'...
			end select
		end if
	end if

end function

'' Check whether UDT doesn't have either of dtor/copy ctor/virtual methods
'' (UDTs that have any of these are handled specially by BYVAL params and
'' function results. For example, BYVAL params do copy construction, and use
'' this function to check whether there is a copyctor and whether a temp copy
'' to be passed byref must be used or not)
function symbCompIsTrivial( byval sym as FBSYMBOL ptr ) as integer
	function = ((symbGetCompCopyCtor( sym ) = NULL) and _
	            (symbGetCompDtor( sym ) = NULL) and _
	            (not symbGetHasRTTI( sym )))
end function

sub symbSetCompCtorHead( byval sym as FBSYMBOL ptr, byval proc as FBSYMBOL ptr )
	if( symbIsStruct( sym ) ) then
		assert( symbIsConstructor( proc ) )

		symbUdtAllocExt( sym )
		if( sym->udt.ext->ctorhead = NULL ) then
			'' Add ctor head (first overload)
			sym->udt.ext->ctorhead = proc
		end if
	end if
end sub

sub symbCheckCompCtor( byval sym as FBSYMBOL ptr, byval proc as FBSYMBOL ptr )
	if( symbIsStruct( sym ) ) then
		select case( symbGetProcParams( proc ) )
		'' default?
		case 1
			'' only the THIS param  - it's a default ctor
			'' (this takes precedence over other ctors with all optional params)
			sym->udt.ext->defctor = proc
		'' copy?
		case 2
			'' 2 params - it could be a copy ctor
			if( sym->udt.ext->copyctor = NULL ) then
				if( hIsLhsEqRhs( sym, proc ) ) then
					sym->udt.ext->copyctor = proc
				end if
			end if
		end select

		'' all params optional? then it can be used as default ctor
		if( sym->udt.ext->defctor = NULL ) then
			if( symbGetProcOptParams( proc ) = symbGetProcParams( proc ) - 1 ) then
				sym->udt.ext->defctor = proc
			end if
		end if
	end if
end sub

sub symbSetCompDtor( byval sym as FBSYMBOL ptr, byval proc as FBSYMBOL ptr )
	if( symbIsStruct( sym ) ) then
		assert( symbIsDestructor( proc ) )
		symbUdtAllocExt( sym )
		if( sym->udt.ext->dtor = NULL ) then
			'' Add dtor
			sym->udt.ext->dtor = proc
		end if
	end if
end sub

function symbGetCompCtorHead( byval sym as FBSYMBOL ptr ) as FBSYMBOL ptr
	if( sym ) then
		if( symbIsStruct( sym ) ) then
			if( sym->udt.ext ) then
				function = sym->udt.ext->ctorhead
			end if
		end if
	end if
end function

function symbGetCompDefCtor( byval sym as FBSYMBOL ptr ) as FBSYMBOL ptr
	if( sym ) then
		if( symbIsStruct( sym ) ) then
			if( sym->udt.ext ) then
				function = sym->udt.ext->defctor
			end if
		end if
	end if
end function

function symbGetCompCopyCtor( byval sym as FBSYMBOL ptr ) as FBSYMBOL ptr
	if( sym ) then
		if( symbIsStruct( sym ) ) then
			if( sym->udt.ext ) then
				function = sym->udt.ext->copyctor
			end if
		end if
	end if
end function

function symbGetCompDtor( byval sym as FBSYMBOL ptr ) as FBSYMBOL ptr
	if( sym ) then
		if( symbIsStruct( sym ) ) then
			if( sym->udt.ext ) then
				function = sym->udt.ext->dtor
			end if
		end if
	end if
end function

sub symbCheckCompClone( byval sym as FBSYMBOL ptr, byval proc as FBSYMBOL ptr )
	if( symbIsStruct( sym ) ) then
		'' clone?
		if( hIsLhsEqRhs( sym, proc ) ) then
			symbUdtAllocExt( sym )
			sym->udt.ext->clone = proc
		end if
	end if
end sub

function symbGetCompCloneProc( byval sym as FBSYMBOL ptr ) as FBSYMBOL ptr
	if( sym ) then
		if( symbIsStruct( sym ) ) then
			if( sym->udt.ext ) then
				function = sym->udt.ext->clone
			end if
		end if
	end if
end function

'':::::
function symbGetCompOpOvlHead _
	( _
		byval sym as FBSYMBOL ptr, _
		byval op as AST_OP _
	) as FBSYMBOL ptr

   	'' self?
   	if( astGetOpIsSelf( op ) ) then
   		select case symbGetClass( sym )
   		case FB_SYMBCLASS_STRUCT
   			if( sym->udt.ext = NULL ) then
   				return NULL
   			end if

   			function = symbGetUDTOpOvlTb(sym)(op - AST_OP_SELFBASE)

   		case FB_SYMBCLASS_ENUM
   			function = NULL

   		case FB_SYMBCLASS_CLASS
   			'' ...

   		end select

   	'' not self..
   	else
   		function = symb.globOpOvlTb(op).head
   	end if

end function

'':::::
sub symbSetCompOpOvlHead _
	( _
		byval sym as FBSYMBOL ptr, _
		byval proc as FBSYMBOL ptr _
	)

	dim as AST_OP op = symbGetProcOpOvl( proc )

	'' self?
	if( astGetOpIsSelf( op ) ) then
		if( symbIsStruct( sym ) ) then
			symbUdtAllocExt( sym )
			symbGetUDTOpOvlTb(sym)(op - AST_OP_SELFBASE) = proc
		end if

		'' assign?
		if( op = AST_OP_ASSIGN ) then
			symbCheckCompClone( sym, proc )
		end if
	'' not self..
	else
		symb.globOpOvlTb(op).head = proc
	end if

end sub

'' Returns vtable index for new virtual method
function symbCompAddVirtual( byval udt as FBSYMBOL ptr ) as integer
	'' Virtuals require the vptr, i.e. the UDT must extend OBJECT
	assert( symbGetHasRTTI( udt ) )

	symbUdtAllocExt( udt )

	hSetMinimumVtableSize( udt )

	function = udt->udt.ext->vtableelements
	udt->udt.ext->vtableelements += 1
end function

function symbCompGetAbstractCount( byval udt as FBSYMBOL ptr ) as integer
	assert( symbIsStruct( udt ) )
	if( udt->udt.ext ) then
		function = udt->udt.ext->abstractcount
	end if
end function

''::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
'' nesting
''::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

/'private sub hDumpHashTb
    dim as FBHASHTB ptr hashtb = symb.hashlist.tail
    do
        dim as zstring ptr id = symbGetName( hashtb->owner )
        hashtb = hashtb->prev

        print *iif( id, id, @"main" );
        if( hashtb = NULL ) then
        	exit do
        end if
    	print ,
    loop

    print
end sub'/

'':::::
private sub hInsertNested _
	( _
		byval sym as FBSYMBOL ptr, _
		byval lasttb as FBHASHTB ptr, _
		byval base_ns as FBSYMBOL ptr _
	)

	dim as FBHASHTB ptr hashtb = any

	'' add all parents to hash list, but the base one

	dim as FBSYMBOL ptr ns = symbGetNamespace( sym )
	do until( ns = base_ns )
		hashtb = @symbGetCompHashTb( ns )

		if( symbGetCompExt( ns ) = NULL ) then
			symbGetCompExt( ns ) = symbCompAllocExt( )
		end if

		symbGetCompExt( ns )->cnt += 1
		if( symbGetCompExt( ns )->cnt <> 1 ) then
			'' remove from import hash tb list
			symbHashListRemoveNamespace( ns )
		end if

		'' add to nested hash tb list
		'' (in reverse other, child ns must be the tail, parents follow)
		symbHashListAddBefore( lasttb, hashtb )

		lasttb = hashtb

		ns = symbGetNamespace( ns )
	loop

end sub

'':::::
private sub hRemoveNested _
	( _
		byval sym as FBSYMBOL ptr, _
		byval base_ns as FBSYMBOL ptr _
	)

	'' remove all parents from the hash list, but the base one

	dim as FBSYMBOL ptr ns = symbGetNamespace( sym )
	do until( ns = base_ns )
		symbGetCompExt( ns )->cnt -= 1

		'' remove from nested hash tb list
		symbHashListDel( @symbGetCompHashTb( ns ) )

		if( symbGetCompExt( ns )->cnt <> 0 ) then
			'' add to import hash tb list
			symbHashListInsertNamespace( ns, _
										 symbGetCompSymbTb( ns ).head )
		end if

		ns = symbGetNamespace( ns )
	loop

end sub

'':::::
private sub hInsertImported _
	( _
		byval sym as FBSYMBOL ptr _
	)

	if( symbGetCompExt( sym ) = NULL ) then
		exit sub
	end if

	dim as FBSYMBOL ptr imp_ = symbGetCompImportHead( sym )
	do while( imp_ <> NULL )
		dim as FBSYMBOL ptr ns = symbGetImportNamespc( imp_ )

		if( ns <> NULL ) then
			symbGetCompExt( ns )->cnt += 1
			if( symbGetCompExt( ns )->cnt = 1 ) then
	  			'' add to import hash tb list
	  			symbHashListInsertNamespace( ns, _
	  										 symbGetCompSymbTb( ns ).head )
	  		end if
	  	end if

		imp_ = symbGetImportNext( imp_ )
	loop

end sub

'':::::
private sub hRemoveImported _
	( _
		byval sym as FBSYMBOL ptr _
	)

	if( symbGetCompExt( sym ) = NULL ) then
		exit sub
	end if

	dim as FBSYMBOL ptr imp_ = symbGetCompImportHead( sym )
	do while( imp_ <> NULL )
		dim as FBSYMBOL ptr ns = symbGetImportNamespc( imp_ )

        if( ns <> NULL ) then
        	symbGetCompExt( ns )->cnt -= 1
			if( symbGetCompExt( ns )->cnt = 0 ) then
	    		'' remove from import hash tb list
	    		symbHashListRemoveNamespace( ns )
	    	end if
	    end if

		imp_ = symbGetImportNext( imp_ )
	loop

end sub

'':::::
sub symbNestBegin _
	( _
		byval sym as FBSYMBOL ptr, _
		byval insert_chain as integer _
	)

	dim as FB_SYMBNEST ptr n = any
	dim as FBHASHTB ptr hashtb = any
	dim as FBSYMBOLTB ptr symbtb = any

	n = stackPush( @symb.neststk )

	n->sym = sym
	n->symtb = symbGetCurrentSymTb( )
	n->hashtb = symbGetCurrentHashTb( )

	if( symbGetClass( sym ) = FB_SYMBCLASS_PROC ) then
		symbtb = @symbGetProcSymbTb( sym )
		hashtb = NULL
	else
        symbtb = @symbGetCompSymbTb( sym )
        hashtb = @symbGetCompHashTb( sym )
	end if

	symbSetCurrentSymTb( symbtb )

	if( hashtb <> NULL ) then
		n->ns = symbGetCurrentNamespc( )
		symbSetCurrentNamespc( sym )

		symbSetCurrentHashTb( hashtb )

		if( symbGetCompExt( sym ) = NULL ) then
			symbGetCompExt( sym ) = symbCompAllocExt( )
		end if

		symbGetCompExt( sym )->cnt += 1
		if( symbGetCompExt( sym )->cnt <> 1 ) then
			'' remove from import hash tb list
			symbHashListRemoveNamespace( sym )
		end if

		'' add to the nested hash tb list
		symbHashListAdd( hashtb )

		if( insert_chain ) then
			hInsertNested( sym, hashtb, n->ns )
		end if

		'' add all USING's
		hInsertImported( sym )
	end if

end sub

'':::::
sub symbNestEnd _
	( _
		byval remove_chain as integer _
	)

	dim as FB_SYMBNEST ptr n = any
	dim as FBHASHTB ptr hashtb = any
	dim as FBSYMBOL ptr sym = any

	n = stackGetTOS( @symb.neststk )

	sym = n->sym

	if( symbGetClass( sym ) = FB_SYMBCLASS_PROC ) then
		hashtb = NULL
	else
        hashtb = @symbGetCompHashTb( sym )
	end if

	symbSetCurrentSymTb( n->symtb )

	if( hashtb <> NULL ) then
		'' removed all USING's
		hRemoveImported( sym )

		if( remove_chain ) then
			hRemoveNested( sym, n->ns )
		end if

		symbGetCompExt( sym )->cnt -= 1

		'' remove from nested hash tb list
		symbHashListDel( hashtb )

		if( symbGetCompExt( sym )->cnt <> 0 ) then
			'' add to import hash tb list
			symbHashListInsertNamespace( sym, _
										 symbGetCompSymbTb( sym ).head )
		end if

		symbSetCurrentHashTb( n->hashtb )

		symbSetCurrentNamespc( n->ns )
	end if

    stackPop( @symb.neststk )

end sub

''::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
'' import and export lists (USING stuff)
''::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

'':::::
sub symbCompAddToImportList _
	( _
		byval imp_ as FBSYMBOL ptr _
	)

	dim as FBSYMBOL ptr ns = symbGetExportNamespc( imp_ )

	if( symbGetCompExt( ns ) = NULL ) then
		symbGetCompExt( ns ) = symbCompAllocExt( )
	end if

	if( symbGetCompExt( ns )->implist.tail <> NULL ) then
		symbGetCompExt( ns )->implist.tail->nsimp.imp_next = imp_
	else
		symbGetCompExt( ns )->implist.head = imp_
	end if

	imp_->nsimp.imp_prev = symbGetCompExt( ns )->implist.tail
	imp_->nsimp.imp_next = NULL

	symbGetCompExt( ns )->implist.tail = imp_

end sub

'':::::
sub symbCompDelFromImportList _
	( _
		byval imp_ as FBSYMBOL ptr _
	)

	dim as FBSYMBOL ptr ns = symbGetExportNamespc( imp_ )

	if( imp_->nsimp.imp_prev = NULL ) then
		symbGetCompExt( ns )->implist.head = imp_->nsimp.imp_next
	else
		imp_->nsimp.imp_prev->nsimp.imp_next = imp_->nsimp.imp_next
	end if

	if( imp_->nsimp.imp_next = NULL ) then
		symbGetCompExt( ns )->implist.tail = imp_->nsimp.imp_prev
	else
		imp_->nsimp.imp_next->nsimp.imp_prev = imp_->nsimp.imp_prev
	end if

end sub

'':::::
sub symbCompAddToExportList _
	( _
		byval imp_ as FBSYMBOL ptr _
	)

	dim as FBSYMBOL ptr ns = symbGetImportNamespc( imp_ )

	if( symbGetCompExt( ns ) = NULL ) then
		symbGetCompExt( ns ) = symbCompAllocExt( )
	end if

	if( symbGetCompExt( ns )->explist.tail <> NULL ) then
		symbGetCompExt( ns )->explist.tail->nsimp.exp_next = imp_
	else
		symbGetCompExt( ns )->explist.head = imp_
	end if

	imp_->nsimp.exp_prev = symbGetCompExt( ns )->explist.tail
	imp_->nsimp.exp_next = NULL

	symbGetCompExt( ns )->explist.tail = imp_

end sub

'':::::
sub symbCompDelFromExportList _
	( _
		byval imp_ as FBSYMBOL ptr _
	)

	dim as FBSYMBOL ptr ns = symbGetImportNamespc( imp_ )

	if( imp_->nsimp.exp_prev = NULL ) then
		symbGetCompExt( ns )->explist.head = imp_->nsimp.exp_next
	else
		imp_->nsimp.exp_prev->nsimp.exp_next = imp_->nsimp.exp_next
	end if

	if( imp_->nsimp.exp_next = NULL ) then
		symbGetCompExt( ns )->explist.tail = imp_->nsimp.exp_prev
	else
		imp_->nsimp.exp_next->nsimp.exp_prev = imp_->nsimp.exp_prev
	end if

end sub

'':::::
sub symbCompDelImportList _
	( _
		byval sym as FBSYMBOL ptr _
	)

	if( symbGetCompExt( sym ) = NULL ) then
		exit sub
	end if

	'' for each namespace importing this ns (because one ns, when
	'' re-implemented, can include another ns that will be removed
	'' first)
	dim as FBSYMBOL ptr exp_ = symbGetCompExportHead( sym )
	do while( exp_ <> NULL )

	    symbCompDelFromImportList( exp_ )

	    dim as FBSYMBOL ptr nxt = symbGetExportNext( exp_ )
	    symbCompDelFromExportList( exp_ )

	    '' not a type, that's to tell NamespaceRemove() to not remove the same ns again
	    symbGetImportNamespc( exp_ ) = NULL

	    exp_ = nxt
	loop

end sub

''::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
'' RTTI
''::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

sub symbCompRTTIInit( )
	dim as FBSYMBOL ptr rttitype = any, objtype = any, objrtti = any, ctor = any

	static as FBARRAYDIM dTB(0)

	'' type $fb_RTTI
	rttitype = symbStructBegin( NULL, NULL, "$fb_RTTI", "$fb_RTTI", FALSE, 0, NULL, 0 )
	symb.rtti.fb_rtti = rttitype

	'' stdlibvtable as any ptr
	symbAddField( rttitype, "stdlibvtable", 0, dTB(), typeAddrOf( FB_DATATYPE_VOID ), NULL, 0, 0 )

	'' dim id as zstring ptr 
	symbAddField( rttitype, "id", 0, dTB(), typeAddrOf( FB_DATATYPE_CHAR ), NULL, 0, 0 )

	'' dim rttibase as $fb_RTTI ptr
	symbAddField( rttitype, "rttibase", 0, dTB(), typeAddrOf( FB_DATATYPE_STRUCT ), rttitype, 0, 0 )

	'' end type
	symbStructEnd( rttitype )

	'' type object
	dim as const zstring ptr ptypename = any
	if( fbLangIsSet( FB_LANG_QB ) ) then
		ptypename = @"__OBJECT"
	else
		ptypename = @"OBJECT"
	end if
	objtype = symbStructBegin( NULL, NULL, ptypename, "$fb_Object", FALSE, 0, NULL, 0 )
	symb.rtti.fb_object = objtype
	symbSetHasRTTI( objtype )
	symbSetIsUnique( objtype )
	symbNestBegin( objtype, FALSE )

	'' vptr as any ptr
	symbAddField( objtype, "$vptr", 0, dTB(), typeAddrOf( FB_DATATYPE_VOID ), NULL, 0, 0 )

	'' declare constructor( )
	ctor = symbPreAddProc( NULL )
	symbAddProcInstancePtr( objtype, ctor )
	symbAddCtor( ctor, NULL, FB_SYMBATTRIB_METHOD or FB_SYMBATTRIB_CONSTRUCTOR _
	                         or FB_SYMBATTRIB_OVERLOADED, FB_FUNCMODE_CDECL )

	'' end type
	symbStructEnd( objtype, TRUE )

	'' declare extern shared as $fb_RTTI __fb_ZTS6Object (the Object class RTTI instance created in C)
	objrtti = symbAddVar( NULL, "__fb_ZTS6Object", FB_DATATYPE_STRUCT, symb.rtti.fb_rtti, 0, 0, dTB(), _
	                      FB_SYMBATTRIB_EXTERN or FB_SYMBATTRIB_SHARED, FB_SYMBOPT_PRESERVECASE )

	'' update the obj struct RTTI (used to create the link with base classes)
	symbUdtAllocExt( objtype )
	objtype->udt.ext->rtti = objrtti
end sub

sub symbCompRTTIEnd()
end sub
