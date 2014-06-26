'' AST conversion nodes
'' l = expression to convert; r = NULL
''
'' chng: sep/2004 written [v1ctor]


#include once "fb.bi"
#include once "fbint.bi"
#include once "ir.bi"
#include once "rtl.bi"
#include once "ast.bi"

'':::::
private sub hCONVConstEvalInt _
	( _
		byval to_dtype as integer, _
		byval v as ASTNODE ptr _
	)

	dim as integer vdtype = typeGet( v->dtype )
	to_dtype = typeGet( to_dtype )

	select case as const vdtype
	case FB_DATATYPE_LONGINT, FB_DATATYPE_ULONGINT

		select case as const to_dtype
		case FB_DATATYPE_BYTE
			v->con.val.int = cbyte( v->con.val.long )

		case FB_DATATYPE_UBYTE
			v->con.val.int = cubyte( culngint( v->con.val.long ) )

		case FB_DATATYPE_SHORT
			v->con.val.int = cshort( v->con.val.long )

		case FB_DATATYPE_USHORT
			v->con.val.int = cushort( culngint( v->con.val.long ) )

		case FB_DATATYPE_INTEGER, FB_DATATYPE_ENUM, FB_DATATYPE_LONG
			v->con.val.int = cint( v->con.val.long )

		case FB_DATATYPE_UINT, FB_DATATYPE_POINTER, FB_DATATYPE_ULONG
			v->con.val.uint = cuint( culngint( v->con.val.long ) )

		end select

	case FB_DATATYPE_SINGLE, FB_DATATYPE_DOUBLE

		select case as const to_dtype
		case FB_DATATYPE_BYTE
			v->con.val.int = cbyte( v->con.val.float )

		case FB_DATATYPE_UBYTE
			v->con.val.int = cubyte( v->con.val.float )

		case FB_DATATYPE_SHORT
			v->con.val.int = cshort( v->con.val.float )

		case FB_DATATYPE_USHORT
			v->con.val.int = cushort( v->con.val.float )

		case FB_DATATYPE_INTEGER, FB_DATATYPE_ENUM, FB_DATATYPE_LONG
			v->con.val.int = cint( v->con.val.float )

		case FB_DATATYPE_UINT, FB_DATATYPE_POINTER, FB_DATATYPE_ULONG
			v->con.val.uint = cuint( v->con.val.float )

		end select

	case else
		select case as const( to_dtype )
		case FB_DATATYPE_BYTE
			v->con.val.int = cbyte( v->con.val.int )

		case FB_DATATYPE_UBYTE
			v->con.val.int = cubyte( cuint( v->con.val.int ) )

		case FB_DATATYPE_SHORT
			v->con.val.int = cshort( v->con.val.int )

		case FB_DATATYPE_USHORT
			v->con.val.int = cushort( cuint( v->con.val.int ) )

		end select

	end select

end sub

'':::::
private sub hCONVConstEvalFlt _
	( _
		byval to_dtype as integer, _
		byval v as ASTNODE ptr _
	)

	dim as integer vdtype = typeGet( v->dtype )
	to_dtype = typeGet( to_dtype )

	select case as const vdtype
	case FB_DATATYPE_SINGLE
		'' SINGLE to SINGLE|DOUBLE
		'' Nothing to do, since float constants are stored as DOUBLE

	case FB_DATATYPE_DOUBLE
		'' DOUBLE to SINGLE|DOUBLE
		if( to_dtype = FB_DATATYPE_SINGLE ) then
			'' Truncate DOUBLE to SINGLE
			dim as single f = any
			f = v->con.val.float
			v->con.val.float = f

			'' Alternative, relying on the fixed CSNG() of FB 0.25:
			'v->con.val.float = csng( v->con.val.float )
			'' (currently it's better to use the explicit temp var
			''  as done above, to avoid the broken CSNG() when
			''  bootstrapping with FB 0.24 or even earlier versions)
		end if

	case FB_DATATYPE_LONGINT
		if( to_dtype = FB_DATATYPE_SINGLE ) then
			v->con.val.float = csng( v->con.val.long )
		else
			v->con.val.float = cdbl( v->con.val.long )
		end if

	case FB_DATATYPE_ULONGINT
		if( to_dtype = FB_DATATYPE_SINGLE ) then
			v->con.val.float = csng( cunsg( v->con.val.long ) )
		else
			v->con.val.float = cdbl( cunsg( v->con.val.long ) )
		end if

	case FB_DATATYPE_UINT, FB_DATATYPE_POINTER
		if( to_dtype = FB_DATATYPE_SINGLE ) then
			v->con.val.float = csng( cunsg( v->con.val.int ) )
		else
			v->con.val.float = cdbl( cunsg( v->con.val.int ) )
		end if

	case FB_DATATYPE_LONG
		if( FB_LONGSIZE = len( integer ) ) then
			if( to_dtype = FB_DATATYPE_SINGLE ) then
				v->con.val.float = csng( v->con.val.int )
			else
				v->con.val.float = cdbl( v->con.val.int )
			end if
		else
			if( to_dtype = FB_DATATYPE_SINGLE ) then
				v->con.val.float = csng( v->con.val.long )
			else
				v->con.val.float = cdbl( v->con.val.long )
			end if
		end if

	case FB_DATATYPE_ULONG
		if( FB_LONGSIZE = len( integer ) ) then
			if( to_dtype = FB_DATATYPE_SINGLE ) then
				v->con.val.float = csng( cunsg( v->con.val.int ) )
			else
				v->con.val.float = cdbl( cunsg( v->con.val.int ) )
			end if
		else
			if( to_dtype = FB_DATATYPE_SINGLE ) then
				v->con.val.float = csng( cunsg( v->con.val.long ) )
			else
				v->con.val.float = cdbl( cunsg( v->con.val.long ) )
			end if
		end if

	case else
		if( to_dtype = FB_DATATYPE_SINGLE ) then
			v->con.val.float = csng( v->con.val.int )
		else
			v->con.val.float = cdbl( v->con.val.int )
		end if

	end select

end sub

'':::::
private sub hCONVConstEval64 _
	( _
		byval to_dtype as integer, _
		byval v as ASTNODE ptr _
	)

	dim as integer vdtype = typeGet( v->dtype )
	to_dtype = typeGet( to_dtype )

	select case as const vdtype
	case FB_DATATYPE_LONGINT, FB_DATATYPE_ULONGINT
		'' do nothing

	case FB_DATATYPE_SINGLE, FB_DATATYPE_DOUBLE

		if( to_dtype = FB_DATATYPE_LONGINT ) then
			v->con.val.long = clngint( v->con.val.float )
		else
			v->con.val.long = hCastFloatToULongint( v->con.val.float )
		end if

	case FB_DATATYPE_LONG

		if( FB_LONGSIZE = len( integer ) ) then
			if( to_dtype = FB_DATATYPE_LONGINT ) then
				v->con.val.long = clngint( v->con.val.int )
			else
				v->con.val.long = culngint( v->con.val.int )
			end if
		end if

	case FB_DATATYPE_ULONG
		if( FB_LONGSIZE = len( integer ) ) then
			if( to_dtype = FB_DATATYPE_LONGINT ) then
				v->con.val.long = clngint( cuint( v->con.val.int ) )
			else
				v->con.val.long = culngint( cuint( v->con.val.int ) )
			end if
		end if

	case else
		'' when expanding to 64bit, we must take care of signedness of source operand

		if( to_dtype = FB_DATATYPE_LONGINT ) then
			if( typeIsSigned( v->dtype ) ) then
				v->con.val.long = clngint( v->con.val.int )
			else
				v->con.val.long = clngint( cuint( v->con.val.int ) )
			end if
		else
			if( typeIsSigned( v->dtype ) ) then
				v->con.val.long = culngint( v->con.val.int )
			else
				v->con.val.long = culngint( cuint( v->con.val.int ) )
			end if
		end if

	end select

end sub

private function hGetTypeMismatchErrMsg( byval options as AST_CONVOPT ) as integer
	if( options and AST_CONVOPT_PTRONLY ) then
		function = FB_ERRMSG_EXPECTEDPOINTER
	else
		function = FB_ERRMSG_TYPEMISMATCH
	end if
end function

private function hCheckPtr _
	( _
		byval to_dtype as integer, _
		byval to_subtype as FBSYMBOL ptr, _
		byval expr_dtype as integer, _
		byval expr as ASTNODE ptr, _
		byval options as AST_CONVOPT _
	) as integer

	function = FB_ERRMSG_OK

	'' to pointer? only allow integers and pointers
	if( typeIsPtr( to_dtype ) ) then
		select case as const typeGet( expr_dtype )
		case FB_DATATYPE_INTEGER, FB_DATATYPE_UINT, FB_DATATYPE_ENUM, _
		     FB_DATATYPE_LONG, FB_DATATYPE_ULONG
			'' Allow integer/long-to-pointer casts
			exit function

		'' only allow other int dtypes if it's 0 (due QB's INTEGER = short)
		case FB_DATATYPE_BYTE, FB_DATATYPE_UBYTE, _
		     FB_DATATYPE_SHORT, FB_DATATYPE_USHORT
			if( astIsCONST( expr ) ) then
				if( astConstIsZero( expr ) ) then
					'' Allow 0-to-pointer casts
					exit function
				end if
			end if

			return hGetTypeMismatchErrMsg( options )

		case FB_DATATYPE_POINTER
			'' Both are pointers, fall through to checks below

		case else
			'' Nothing else allowed (strings, structs)
			return hGetTypeMismatchErrMsg( options )
		end select

	'' from pointer? only allow integers and pointers
	elseif( typeIsPtr( expr_dtype ) ) then
		select case as const typeGet( to_dtype )
		case FB_DATATYPE_INTEGER, FB_DATATYPE_UINT, FB_DATATYPE_ENUM, _
		     FB_DATATYPE_LONG, FB_DATATYPE_ULONG
			'' Allow pointer-to-integer/long casts
			exit function

		case FB_DATATYPE_POINTER
			'' Both are pointers, fall through to checks below

		case else
			'' Nothing else allowed (strings, structs)
			return hGetTypeMismatchErrMsg( options )
		end select
	else
		'' No pointers at all, nothing to do
		exit function
	end if

	''
	'' Both are pointers
	''
	'' If any of them is a pointer to a derived class,
	'' only allow casting to a pointer to a class from that
	'' inheritance hierarchy, or ANY PTR.
	''

	'' To derived pointer?
	if( typeGetDtOnly( to_dtype ) = FB_DATATYPE_STRUCT ) then
		if( to_subtype->udt.base <> NULL ) then
			if( typeGetDtOnly( expr_dtype ) <> FB_DATATYPE_STRUCT ) then
				if( typeGetDtOnly( expr_dtype ) <> FB_DATATYPE_VOID ) then
					return FB_ERRMSG_CASTDERIVEDPTRFROMINCOMPATIBLE
				end if
			else			
				'' not a upcasting?
				if( symbGetUDTBaseLevel( expr->subtype, to_subtype ) = 0 ) then
					'' try downcasting..
					if( symbGetUDTBaseLevel( to_subtype, expr->subtype ) = 0 ) then
						return FB_ERRMSG_CASTDERIVEDPTRFROMUNRELATED
					End If
				End If
			end if
		End If
	End If

	'' From derived pointer?
	if( typeGetDtOnly( expr_dtype ) = FB_DATATYPE_STRUCT ) then		
		if( expr->subtype->udt.base <> NULL ) then
			if( typeGetDtOnly( to_dtype ) <> FB_DATATYPE_STRUCT ) then
				if( typeGetDtOnly( to_dtype ) <> FB_DATATYPE_VOID ) then
					return FB_ERRMSG_CASTDERIVEDPTRTOINCOMPATIBLE
				end if
			else
				'' not a upcasting?
				if( symbGetUDTBaseLevel( to_subtype, expr->subtype ) = 0 ) then
					'' try downcasting..
					if( symbGetUDTBaseLevel( expr->subtype, to_subtype ) = 0 ) then
						return FB_ERRMSG_CASTDERIVEDPTRTOUNRELATED
					End If
				End If
			end if
		End If
	End If

end function

'':::::
function astCheckCONV _
	( _
		byval to_dtype as integer, _
		byval to_subtype as FBSYMBOL ptr, _
		byval l as ASTNODE ptr _
	) as integer

	dim as integer ldtype = any

	function = FALSE

	ldtype = astGetFullType( l )

	'' to or from UDT? only upcasting supported by now
	if( (typeGet( to_dtype ) = FB_DATATYPE_STRUCT) or _
	    (typeGet( ldtype   ) = FB_DATATYPE_STRUCT)      ) then
		if( (typeGet( to_dtype ) = FB_DATATYPE_STRUCT) and _
		    (typeGet( ldtype   ) = FB_DATATYPE_STRUCT)      ) then
			function = (symbGetUDTBaseLevel( l->subtype, to_subtype ) > 0)
		end if
		exit function
	end if

	'' string? neither
	if( typeGetClass( ldtype ) = FB_DATACLASS_STRING ) then
		exit function
	end if

	'' check pointers
	if( hCheckPtr( to_dtype, to_subtype, ldtype, l, 0 ) <> FB_ERRMSG_OK ) then
		exit function
	end if

	select case typeGet( ldtype )
	'' CHAR and WCHAR literals are also from the INTEGER class
	case FB_DATATYPE_CHAR, FB_DATATYPE_WCHAR
		'' don't allow, unless it's a deref pointer
		if( astIsDEREF( l ) = FALSE ) then
			exit function
		end if

	end select

	function = TRUE

end function

'':::::
#macro hDoGlobOpOverload( to_dtype, to_subtype, node )
	scope
		dim as FBSYMBOL ptr proc = any
		dim as FB_ERRMSG err_num = any

		proc = symbFindCastOvlProc( to_dtype, to_subtype, node, @err_num )
		if( proc <> NULL ) then
			'' build a proc call
			return astBuildCall( proc, l )
		else
			if( err_num <> FB_ERRMSG_OK ) then
				return NULL
			end if
		end if
	end scope
#endmacro

'':::::
function astNewCONV _
	( _
		byval to_dtype as integer, _
		byval to_subtype as FBSYMBOL ptr, _
		byval l as ASTNODE ptr, _
		byval options as AST_CONVOPT, _
		byval perrmsg as integer ptr _
	) as ASTNODE ptr

	dim as ASTNODE ptr n = any
	dim as integer ldclass = any, ldtype = any, errmsg = any, doconv = any

	if( perrmsg ) then
		*perrmsg = FB_ERRMSG_OK
	end if

	ldtype = astGetFullType( l )

	'' same type?
	if( typeGetDtAndPtrOnly( ldtype ) = typeGetDtAndPtrOnly( to_dtype ) ) then
		if( l->subtype = to_subtype ) then
			'' Only CONST bits changed?
			if( ldtype <> to_dtype ) then
				'' CONST node? Evaluate at compile-time
				if( astIsCONST( l ) ) then
					astSetType( l, to_dtype, to_subtype )
					n = l
				else
					'' Otherwise, add a CONV node to represent the changed CONST bits
					'' to the expression parser
					n = astNewNode( AST_NODECLASS_CONV, to_dtype, to_subtype )
					n->l = l
					n->cast.doconv = FALSE
					n->cast.do_convfd2fs = FALSE
				end if
			else
				n = l
			end if

			return n
		end if
	end if

	'' try casting op overloading
	hDoGlobOpOverload( to_dtype, to_subtype, l )

	select case as const typeGet( to_dtype )
	case FB_DATATYPE_VOID, FB_DATATYPE_STRING
		'' refuse void (used by uop/bop to cast to be most precise
		'' possible) and strings, as op overloading already failed
		exit function

	'' to UDT?
	case FB_DATATYPE_STRUCT ', FB_DATATYPE_CLASS
		'' not from UDT? op overloading already failed, refuse.
		if( typeGet( ldtype ) <> FB_DATATYPE_STRUCT ) then
			exit function
		end if

		if( symbGetUDTBaseLevel( l->subtype, to_subtype ) = 0 ) then
			exit function
		end if

	'' to anything else (integers/floats)
	case else
		'' from UDT? refuse, since op overloading already failed
		if( typeGet( ldtype ) = FB_DATATYPE_STRUCT ) then
			exit function
		end if

	end select

	ldclass = typeGetClass( ldtype )

	'' sign conversion?
	if( options and AST_CONVOPT_SIGNCONV ) then
		'' float? invalid
		if( ldclass <> FB_DATACLASS_INTEGER ) then
			exit function
		end if
	end if

	if( (options and AST_CONVOPT_DONTCHKPTR) = 0 ) then
		'' check pointers
		errmsg = hCheckPtr( to_dtype, to_subtype, ldtype, l, options )
		if( errmsg <> FB_ERRMSG_OK ) then
			if( perrmsg ) then
				*perrmsg = errmsg
			end if
			exit function
		end if
	end if

	'' string?
	if( options and AST_CONVOPT_CHECKSTR ) then
		select case as const typeGet( ldtype )
		case FB_DATATYPE_STRING, FB_DATATYPE_FIXSTR, _
			 FB_DATATYPE_CHAR, FB_DATATYPE_WCHAR
			return rtlStrToVal( l, to_dtype )
		end select
	else
		if( ldclass = FB_DATACLASS_STRING ) then
			exit function
		'' CHAR and WCHAR literals are also from the INTEGER class
		else
			select case typeGet( ldtype )
			case FB_DATATYPE_CHAR, FB_DATATYPE_WCHAR
				'' don't allow, unless it's a deref pointer
				if( astIsDEREF( l ) = FALSE ) then
					exit function
				end if
			end select
		end if
	end if

	'' constant? evaluate at compile-time
	if( astIsCONST( l ) ) then
		astCheckConst( to_dtype, l )

		select case as const typeGet( to_dtype )
		case FB_DATATYPE_LONGINT, FB_DATATYPE_ULONGINT
			hCONVConstEval64( to_dtype, l )

		case FB_DATATYPE_SINGLE, FB_DATATYPE_DOUBLE
			hCONVConstEvalFlt( to_dtype, l )

		case FB_DATATYPE_LONG, FB_DATATYPE_ULONG
			if( FB_LONGSIZE = len( integer ) ) then
				hCONVConstEvalInt( to_dtype, l )
			else
				hCONVConstEval64( to_dtype, l )
			end if

		case else
			'' bytes/shorts/integers/enum
			hCONVConstEvalInt( to_dtype, l )
		end select

		l->dtype = to_dtype
		l->subtype = to_subtype
		return l
	end if

	'' C backend?
	if( env.clopt.backend = FB_BACKEND_GCC ) then
		'' special case: if it's a float to int, use a builtin function
		if( (ldclass = FB_DATACLASS_FPOINT) and (typeGetClass( to_dtype ) = FB_DATACLASS_INTEGER) ) then
			return rtlMathFTOI( l, to_dtype )
		else
			select case( typeGetDtAndPtrOnly( to_dtype ) )
			case FB_DATATYPE_STRUCT '', FB_DATATYPE_CLASS
				'' C (not C++) doesn't support casting from a UDT to another, so do this instead: lhs = *((typeof(lhs)*)&rhs)
				return astNewDEREF( astNewCONV( typeAddrOf( to_dtype ), to_subtype, astNewADDROF( l ) ) )   
			end select
		end if
	end if

	doconv = TRUE

	'' only convert if the classes are different (ie, floating<->integer) or
	'' if sizes are different (ie, byte<->int)
	if( ldclass = typeGetClass( to_dtype ) ) then
		select case( typeGet( to_dtype ) )
		case FB_DATATYPE_STRUCT '', FB_DATATYPE_CLASS
			'' do nothing
			doconv = FALSE
		case else
			if( typeGetSize( ldtype ) = typeGetSize( to_dtype ) ) then
				doconv = FALSE
			end if
		end select
	end if

	if( irGetOption( IR_OPT_FPUCONV ) ) then
		if (ldclass = FB_DATACLASS_FPOINT) and ( typeGetClass( to_dtype ) = FB_DATACLASS_FPOINT ) then
			if( typeGetSize( ldtype ) <> typeGetSize( to_dtype ) ) then
				doconv = TRUE
			end if
		end if
	end if

	'' casting another cast?
	if( l->class = AST_NODECLASS_CONV ) then
		'' no conversion in both?
		if( l->cast.doconv = FALSE ) then
			if( doconv = FALSE ) then
				'' just replace the bottom cast()'s type
				astGetFullType( l ) = to_dtype
				l->subtype = to_subtype
				return l
			end if
		end if
	end if

	'' alloc new node
	n = astNewNode( AST_NODECLASS_CONV, to_dtype, to_subtype )

	n->l = l
	n->cast.doconv = doconv
	n->cast.do_convfd2fs = FALSE

	if( env.clopt.backend = FB_BACKEND_GAS ) then
		if( doconv ) then
			'' converting DOUBLE to SINGLE?
			if( typeGet( ldtype ) = FB_DATATYPE_DOUBLE ) then
				n->cast.do_convfd2fs = (typeGet( to_dtype ) = FB_DATATYPE_SINGLE)
			end if
		end if
	end if

	function = n

end function

'':::::
function astNewOvlCONV _
	( _
		byval to_dtype as integer, _
		byval to_subtype as FBSYMBOL ptr, _
		byval l as ASTNODE ptr _
	) as ASTNODE ptr

	'' try casting op overloading only
	hDoGlobOpOverload( to_dtype, to_subtype, l )

	'' nothing to do
	function = l

end function

sub astUpdateCONVFD2FS _
	( _
		byval n as ASTNODE ptr, _
		byval to_dtype as integer, _
		byval is_expr as integer _
	)

	assert( n->class = AST_NODECLASS_CONV )

	'' only when converting DOUBLE to SINGLE
	if( n->cast.do_convfd2fs = FALSE ) then
		exit sub
	end if

	assert( env.clopt.backend = FB_BACKEND_GAS )

	''
	'' x86 assumptions
	''
	'' Don't do the DOUBLE to SINGLE truncation unless needed.
	''
	'' If the target dtype cannot hold bigger values than SINGLE
	'' anyways, then we don't need to do the additional truncation,
	'' that will happen automatically when storing into the target.
	''
	'' This applies to stores (ASSIGN, ARG), and to expressions
	'' that do not use the FPU stack (ST(N) registers).
	''

	'' everything >= 4 bytes, assuming that 4 byte integers can hold values
	'' that still are too big for SINGLE
	n->cast.do_convfd2fs = (typeGetSize( to_dtype ) >= 4)

	'' to SINGLE itself? no need to do anything then, except if it's on
	'' the FPU stack, and won't be automatically truncated because of that.
	if( typeGet( to_dtype ) = FB_DATATYPE_SINGLE ) then
		n->cast.do_convfd2fs = is_expr
	end if

end sub

'':::::
function astLoadCONV _
	( _
		byval n as ASTNODE ptr _
	) as IRVREG ptr

	dim as ASTNODE ptr l = any
	dim as IRVREG ptr vs = any, vr = any

	l = n->l

	if( l = NULL ) then
		return NULL
	end if

	vs = astLoad( l )

	if( ast.doemit ) then
		vs->vector = n->vector
		if( n->cast.doconv ) then
			vr = irAllocVreg( astGetDataType( n ), n->subtype )
			vr->vector = n->vector
			irEmitConvert( vr, vs )

			if( n->cast.do_convfd2fs ) then
				'' converting DOUBLE to SINGLE?
				if( vs->dtype = FB_DATATYPE_DOUBLE ) then
					if( vr->dtype = FB_DATATYPE_SINGLE ) then
						if( vr->regFamily = IR_REG_FPU_STACK ) then
							'' Do additional conversion to truncate to SINGLE
							irEmitUOP( AST_OP_CONVFD2FS, vr, NULL )
						end if
					end if
				end if
			end if
		else
			vr = vs
			irSetVregDataType( vr, astGetDataType( n ), n->subtype )
		end if
	end if

	astDelNode( l )

	function = vr

end function


