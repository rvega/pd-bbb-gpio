'' AST branch nodes (including jump tables)
''
'' chng: sep/2004 written [v1ctor]


#include once "fb.bi"
#include once "fbint.bi"
#include once "ir.bi"
#include once "ast.bi"

'':::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
'' branches (l = link to the stream to be also flushed, if any; r = NULL)
'':::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

'':::::
function astNewBRANCH _
	( _
		byval op as integer, _
		byval label as FBSYMBOL ptr, _
		byval l as ASTNODE ptr _
	) as ASTNODE ptr

    dim as ASTNODE ptr n = any
    dim as integer dtype = any

    if( l = NULL ) then
    	dtype = FB_DATATYPE_INVALID
    else
    	dtype = astGetFullType( l )
    end if

	'' alloc new node
	n = astNewNode( AST_NODECLASS_BRANCH, dtype )
	function = n

	n->l = l
	n->op.op = op
	n->op.ex = label
	n->op.options = AST_OPOPT_ALLOCRES

end function

'':::::
function astLoadBRANCH _
	( _
		byval n as ASTNODE ptr _
	) as IRVREG ptr

    dim as ASTNODE ptr l = any
    dim as IRVREG ptr vr = any

	l  = n->l

	if( l <> NULL ) then
		vr = astLoad( l )
		astDelNode( l )
	else
		vr = NULL
	end if

	if( ast.doemit ) then
		'' pointer?
		if( n->op.ex = NULL ) then
			'' jump or call?
			select case n->op.op
			case AST_OP_JUMPPTR
				irEmitJUMPPTR( vr )

			case AST_OP_CALLPTR
				irEmitCALLPTR( vr, NULL, 0, -1 )

			case AST_OP_RET
				irEmitRETURN( 0 )
			end select

		else
			irEmitBRANCH( n->op.op, n->op.ex )
		end if
	end if

	function = vr

end function

'' JMPTB (l = condition expr; r = NULL)
'' Takes a condition expression and two arrays representing constant value
'' and label pairs, and a fallback label.
private function astNewJMPTB _
	( _
		byval l as ASTNODE ptr, _
		byval tbsym as FBSYMBOL ptr, _
		byval values1 as uinteger ptr, _
		byval labels1 as FBSYMBOL ptr ptr, _
		byval labelcount as integer, _
		byval deflabel as FBSYMBOL ptr, _
		byval minval as uinteger, _
		byval maxval as uinteger _
	) as ASTNODE ptr

	dim as ASTNODE ptr n = any, tree = any
	dim as uinteger ptr values = any
	dim as FBSYMBOL ptr ptr labels = any

	tree = NULL

	'' The jump table can be empty, in case of a SELECT CASE AS CONST
	'' with only a CASE ELSE. (it's not worth it to "optimize" that useless
	'' case, but it must still be handled without crashing the compiler...)
	if( labelcount > 0 ) then
		'' Duplicate the values/labels arrays
		values = callocate( sizeof( uinteger ) * labelcount )
		labels = callocate( sizeof( FBSYMBOL ptr ) * labelcount )
		for i as integer = 0 to labelcount - 1
			values[i] = values1[i]
			labels[i] = labels1[i]
		next
	else
		values = NULL
		labels = NULL
	end if

	n = astNewNode( AST_NODECLASS_JMPTB, FB_DATATYPE_INVALID )

	n->l = l
	n->sym = tbsym
	n->jmptb.values = values
	n->jmptb.labels = labels
	n->jmptb.labelcount = labelcount
	n->jmptb.deflabel = deflabel
	n->jmptb.minval = minval
	n->jmptb.maxval = maxval

	function = astNewLINK( tree, n )
end function

function astLoadJMPTB( byval n as ASTNODE ptr ) as IRVREG ptr
	dim as IRVREG ptr v1 = any

	v1 = astLoad( n->l )
	astDelNode( n->l )

	if( ast.doemit ) then
		irEmitJMPTB( v1, n->sym, n->jmptb.values, n->jmptb.labels, _
		             n->jmptb.labelcount, n->jmptb.deflabel, _
		             n->jmptb.minval, n->jmptb.maxval )
	end if

	deallocate( n->jmptb.values )
	deallocate( n->jmptb.labels )

	function = NULL
end function

function astBuildJMPTB _
	( _
		byval tempvar as FBSYMBOL ptr, _
		byval values1 as uinteger ptr, _
		byval labels1 as FBSYMBOL ptr ptr, _
		byval labelcount as integer, _
		byval deflabel as FBSYMBOL ptr, _
		byval minval as uinteger, _
		byval maxval as uinteger _
	) as ASTNODE ptr

	dim as ASTNODE ptr tree = any, l = any
	static as FBARRAYDIM dTB(0)
	dim as FBSYMBOL ptr tbsym = any

	assert( symbGetType( tempvar ) = FB_DATATYPE_UINT )

	tree = NULL

	'' Empty jump table? Just jump to the ELSE block or the END SELECT
	'' (GAS/LLVM backends only, the GCC backend handles this case manually)
	select case( env.clopt.backend )
	case FB_BACKEND_GAS, FB_BACKEND_LLVM
		if( labelcount <= 0 ) then
			return astNewBRANCH( AST_OP_JMP, deflabel )
		end if
	end select

	''
	'' For the ASM backend, the checks and the jump are emitted separately,
	'' so the normal x86 backend code generation & register allocation
	'' can be re-used.
	''
	'' For the C and LLVM backends, the irEmitJMPTB() handles it all,
	'' because for C it's easy to enough to implement the checks "manually"
	'' and for the LLVM backend the LLVM instructions do it already anyways.
	''
	'' This means for the ASM backend we need to add a symbol representing
	'' the jump table, so we can do a VAR access on it. It won't be emitted
	'' like normal vars though, it just makes the jump table's label name
	'' available/known to the AST. This wouldn't be needed if the x86
	'' backend generated the checking code automatically, because then the
	'' jump table's name would be needed there (internally) only, not here
	'' in the AST.
	''
	if( env.clopt.backend = FB_BACKEND_GAS ) then
		tbsym = symbAddVar( symbUniqueLabel( ), NULL, _
		                    typeAddrOf( FB_DATATYPE_VOID ), NULL, 0, _
		                    1, dTB(), FB_SYMBATTRIB_SHARED )
		symbSetIsJumpTb( tbsym )
		symbSetIsInitialized( tbsym )

		if( minval > 0 ) then
			'' if( expr < minval ) then goto deflabel
			tree = astNewLINK( tree, _
				astNewBOP( AST_OP_LT, astNewVAR( tempvar ), _
					astNewCONSTi( minval, FB_DATATYPE_UINT ), _
					deflabel, AST_OPOPT_NONE ) )
		end if

		'' if( expr > maxval ) then goto deflabel
		tree = astNewLINK( tree, _
			astNewBOP( AST_OP_GT, astNewVAR( tempvar ), _
				astNewCONSTi( maxval, FB_DATATYPE_UINT ), _
				deflabel, AST_OPOPT_NONE ) )

		'' goto table[expr - minval]
		tree = astNewLINK( tree, _
			astNewBRANCH( AST_OP_JUMPPTR, NULL, _
				astNewIDX( astNewVAR( tbsym, -minval * FB_POINTERSIZE ), _
					astNewBOP( AST_OP_MUL, _
						astNewVAR( tempvar ), _
						astNewCONSTi( FB_POINTERSIZE, FB_DATATYPE_UINT ) ), _
					typeAddrOf( FB_DATATYPE_VOID ), NULL ) ) )
	else
		tbsym = NULL
	end if

	tree = astNewLINK( tree, _
		astNewJMPTB( astNewVAR( tempvar ), tbsym, _
			values1, labels1, labelcount, deflabel, minval, maxval ) )

	function = tree
end function

function astNewLOOP _
	( _
		byval label as FBSYMBOL ptr, _
		byval tree as ASTNODE ptr _
	) as ASTNODE ptr

	dim as ASTNODE ptr n = any

	n = astNewNode( AST_NODECLASS_LOOP, FB_DATATYPE_INVALID )
	function = n

	n->l = tree
	n->op.ex = label

	'' just faking something, so it's safe to handle LOOPs in the same
	'' context like BRANCH nodes
	n->op.op = AST_OP_FOR
	n->op.options = 0

end function

function astLoadLOOP( byval n as ASTNODE ptr ) as IRVREG ptr
	astLoad( n->l )
	astDelNode( n->l )
	function = NULL
end function