'' symbol table module for enumerations
''
'' chng: sep/2004 written [v1ctor]
''		 jan/2005 updated to use real linked-lists [v1ctor]


#include once "fb.bi"
#include once "fbint.bi"
#include once "parser.bi"
#include once "hash.bi"
#include once "list.bi"

'':::::
function symbAddEnum _
	( _
		byval id as zstring ptr, _
		byval id_alias as zstring ptr, _
		byval attrib as integer _
	) as FBSYMBOL ptr

    dim as FBSYMBOL ptr e = any

	'' no explict alias given?
    if( id_alias = NULL ) then
    	'' only preserve a case-sensitive version if in BASIC mangling
    	if( parser.mangling <> FB_MANGLING_BASIC ) then
    		id_alias = id
    	end if
    end if

    e = symbNewSymbol( FB_SYMBOPT_DOHASH, _
    				   NULL, _
    				   NULL, NULL, _
    				   FB_SYMBCLASS_ENUM, _
    				   id, id_alias, _
    				   FB_DATATYPE_ENUM, NULL, attrib )
	if( e = NULL ) then
		return NULL
	end if

	'' init tables
	symbSymbTbInit( e->enum_.ns.symtb, e )

	'' create a new hash if in BASIC mangling mode
	if( parser.mangling = FB_MANGLING_BASIC ) then
		symbHashTbInit( e->enum_.ns.hashtb, e, FB_INITFIELDNODES )
	else
		symbHashTbInit( e->enum_.ns.hashtb, e, 0 )
	end if

    '' unused (while mixins aren't supported)
    e->enum_.ns.ext = NULL

	e->enum_.elements = 0
	e->enum_.dbg.typenum = INVALID

	'' check for forward references
	if( symb.fwdrefcnt > 0 ) then
		symbCheckFwdRef( e )
	end if

	function = e

end function

'':::::
function symbAddEnumElement _
	( _
		byval parent as FBSYMBOL ptr, _
		byval id as zstring ptr, _
		byval intval as integer, _
		byval attrib as integer _
	) as FBSYMBOL ptr

	dim as FBSYMBOL ptr s = any

    s = symbNewSymbol( FB_SYMBOPT_DOHASH, _
    				   NULL, _
    				   NULL, NULL, _
    				   FB_SYMBCLASS_CONST, _
    				   id, NULL, _
    				   FB_DATATYPE_ENUM, parent, _
    				   attrib )
	if( s = NULL ) then
		return NULL
	end if

	s->con.val.int = intval

	parent->enum_.elements += 1

	function = s

end function

sub symbDelEnum( byval s as FBSYMBOL ptr )
	symbDelNamespaceMembers( s, (symbGetMangling( s ) = FB_MANGLING_BASIC) )
	symbFreeSymbol( s )
end sub

'':::::
function symbGetEnumFirstElm _
	( _
		byval parent as FBSYMBOL ptr _
	) as FBSYMBOL ptr

	dim as FBSYMBOL ptr sym = symbGetEnumSymbTbHead( parent )

	'' find the first const
	do while( sym <> NULL )
		if( symbIsConst( sym ) ) then
			return sym
		end if
		sym = sym->next
	loop

	function = NULL

end function

'':::::
function symbGetEnumNextElm _
	( _
		byval sym as FBSYMBOL ptr _
	) as FBSYMBOL ptr

	'' find the next const
	sym = sym->next
	do while( sym <> NULL )
		if( symbIsConst( sym ) ) then
			return sym
		end if
		sym = sym->next
	loop

	function = NULL

end function
