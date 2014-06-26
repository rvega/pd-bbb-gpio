// Compilation of symb-proc.bas started at 13:35:44 on 07-04-2013
typedef char byte;
typedef unsigned char ubyte;
typedef unsigned short ushort;
typedef int integer;
typedef unsigned int uinteger;
typedef unsigned long ulong;
typedef long long longint;
typedef unsigned long long ulongint;
typedef float single;
typedef struct _string { char *data; int len; int size; } string;
typedef char fixstr;
typedef integer wchar;
	typedef int FB_SYMBCLASS;
	typedef int FB_SYMBATTRIB;
	typedef int FB_SYMBSTATS;
	typedef struct _FB_SYMBID {
		char* NAME;
		char* ALIAS;
		char* MANGLED;
	} FB_SYMBID;
	typedef int FB_DATATYPE;
	typedef struct _FBSYMBOL FBSYMBOL$type;
	typedef int AST_NODECLASS;
	typedef union _FBVALUE {
		FBSYMBOL$type* STR;
		integer INT;
		uinteger UINT;
		double FLOAT;
		longint LONG;
		ulongint ULONG;
	} FBVALUE;
	typedef struct _AST_NODE_CONST {
		FBVALUE VAL;
	} AST_NODE_CONST;
	typedef struct _AST_NODE_VAR {
		integer OFS;
	} AST_NODE_VAR;
	typedef struct _AST_NODE_IDX {
		integer OFS;
		integer MULT;
	} AST_NODE_IDX;
	typedef struct _AST_NODE_PTR {
		integer OFS;
	} AST_NODE_PTR;
	typedef struct _ASTNODE ASTNODE$type;
	typedef struct _AST_TMPSTRLIST_ITEM AST_TMPSTRLIST_ITEM$type;
	typedef struct _AST_TMPSTRLIST_ITEM {
		FBSYMBOL$type* SYM;
		ASTNODE$type* SRCTREE;
		AST_TMPSTRLIST_ITEM$type* PREV;
	} AST_TMPSTRLIST_ITEM;
	typedef struct _AST_NODE_CALL {
		integer ISRTL;
		integer ARGS;
		FBSYMBOL$type* CURRARG;
		ASTNODE$type* ARGTAIL;
		AST_TMPSTRLIST_ITEM$type* STRTAIL;
		FBSYMBOL$type* TMPRES;
	} AST_NODE_CALL;
	typedef struct _AST_NODE_ARG {
		integer MODE;
		integer LGT;
	} AST_NODE_ARG;
	typedef struct _AST_NODE_IIF {
		FBSYMBOL$type* FALSELABEL;
	} AST_NODE_IIF;
	typedef int AST_OPOPT;
	typedef struct _AST_NODE_OP {
		integer OP;
		AST_OPOPT OPTIONS;
		FBSYMBOL$type* EX;
	} AST_NODE_OP;
	typedef struct _AST_NODE_LOAD {
		integer ISRES;
	} AST_NODE_LOAD;
	typedef struct _AST_NODE_LABEL {
		integer FLUSH;
	} AST_NODE_LABEL;
	typedef struct _AST_NODE_OFFS {
		integer OFS;
	} AST_NODE_OFFS;
	typedef struct _AST_NODE_LIT {
		char* TEXT;
	} AST_NODE_LIT;
	typedef int AST_ASMTOKTYPE;
	typedef struct _ASTASMTOK ASTASMTOK$type;
	typedef struct _ASTASMTOK {
		AST_ASMTOKTYPE TYPE;
		FBSYMBOL$type* SYM;
		char* TEXT;
		ASTASMTOK$type* NEXT;
	} ASTASMTOK;
	typedef struct _AST_NODE_ASM {
		ASTASMTOK$type* TOKHEAD;
	} AST_NODE_ASM;
	typedef struct _AST_NODE_JMPTB {
		uinteger* VALUES;
		FBSYMBOL$type** LABELS;
		integer LABELCOUNT;
		FBSYMBOL$type* DEFLABEL;
		uinteger MINVAL;
		uinteger MAXVAL;
	} AST_NODE_JMPTB;
	typedef struct _AST_NODE_DBG {
		integer EX;
		integer OP;
	} AST_NODE_DBG;
	typedef struct _AST_NODE_MEM {
		integer BYTES;
		integer OP;
	} AST_NODE_MEM;
	typedef struct _AST_NODE_STACK {
		integer OP;
	} AST_NODE_STACK;
	typedef struct _AST_NODE_TYPEINI {
		integer OFS;
		integer BYTES;
		integer ELEMENTS;
		FBSYMBOL$type* SCP;
		FBSYMBOL$type* LASTSCP;
	} AST_NODE_TYPEINI;
	typedef struct _AST_BREAKLIST {
		ASTNODE$type* HEAD;
		ASTNODE$type* TAIL;
	} AST_BREAKLIST;
	typedef struct _AST_NODE_PROC {
		integer ISMAIN;
		ASTNODE$type* DECL_LAST;
	} AST_NODE_PROC;
	typedef struct _AST_NODE_BLOCK {
		ASTNODE$type* PARENT;
		integer INISTMT;
		integer ENDSTMT;
		FBSYMBOL$type* INITLABEL;
		FBSYMBOL$type* EXITLABEL;
		AST_BREAKLIST BREAKLIST;
		AST_NODE_PROC PROC;
	} AST_NODE_BLOCK;
	typedef struct _AST_NODE_BREAK {
		ASTNODE$type* PARENT;
		integer SCOPE;
		integer LINENUM;
		integer STMTNUM;
	} AST_NODE_BREAK;
	typedef struct _AST_NODE_DATASTMT {
		integer ID;
		integer ELMTS;
	} AST_NODE_DATASTMT;
	typedef struct _AST_NODE_LINK {
		integer RET_LEFT;
	} AST_NODE_LINK;
	typedef struct _AST_NODE_CAST {
		integer DOCONV;
		integer DO_CONVFD2FS;
	} AST_NODE_CAST;
	typedef struct _ASTNODE {
		AST_NODECLASS CLASS;
		integer DTYPE;
		FBSYMBOL$type* SUBTYPE;
		FBSYMBOL$type* SYM;
		integer VECTOR;
		AST_NODE_CONST CON;
		AST_NODE_VAR VAR_;
		AST_NODE_IDX IDX;
		AST_NODE_PTR PTR;
		AST_NODE_CALL CALL;
		AST_NODE_ARG ARG;
		AST_NODE_IIF IIF;
		AST_NODE_OP OP;
		AST_NODE_LOAD LOD;
		AST_NODE_LABEL LBL;
		AST_NODE_OFFS OFS;
		AST_NODE_LIT LIT;
		AST_NODE_ASM ASM;
		AST_NODE_JMPTB JMPTB;
		AST_NODE_DBG DBG;
		AST_NODE_MEM MEM;
		AST_NODE_STACK STACK;
		AST_NODE_TYPEINI TYPEINI;
		AST_NODE_BLOCK BLOCK;
		AST_NODE_BREAK BREAK;
		AST_NODE_DATASTMT DATA;
		AST_NODE_LINK LINK;
		AST_NODE_CAST CAST;
		ASTNODE$type* L;
		ASTNODE$type* R;
		ASTNODE$type* PREV;
		ASTNODE$type* NEXT;
	} ASTNODE;
	typedef struct _FBVARDIM FBVARDIM$type;
	typedef struct _FBVARDIM {
		integer LOWER;
		integer UPPER;
		FBVARDIM$type* NEXT;
	} FBVARDIM;
	typedef struct _FBS_ARRAY {
		integer DIMS;
		FBVARDIM$type* DIMHEAD;
		FBVARDIM$type* DIMTAIL;
		integer DIF;
		integer ELMS;
		FBSYMBOL$type* DESC;
		integer HAS_ELLIPSIS;
	} FBS_ARRAY;
	typedef struct _FBVAR_DESC {
		FBSYMBOL$type* ARRAY;
	} FBVAR_DESC;
	typedef struct _FBVAR_DATA {
		FBSYMBOL$type* PREV;
	} FBVAR_DATA;
	typedef struct _FBS_VAR {
		char* LITTEXT;
		wchar* LITTEXTW;
		ASTNODE$type* INITREE;
		FBS_ARRAY ARRAY;
		FBVAR_DESC DESC;
		integer STMTNUM;
		integer ALIGN;
		FBVAR_DATA DATA;
	} FBS_VAR;
	typedef struct _FBS_CONST {
		FBVALUE VAL;
	} FBS_CONST;
	typedef struct _FBSYMBOLTB {
		FBSYMBOL$type* OWNER;
		FBSYMBOL$type* HEAD;
		FBSYMBOL$type* TAIL;
	} FBSYMBOLTB;
	typedef struct _HASHITEM HASHITEM$type;
	typedef struct _HASHITEM {
		char* NAME;
		void* DATA;
		HASHITEM$type* PREV;
		HASHITEM$type* NEXT;
	} HASHITEM;
	typedef struct _HASHLIST {
		HASHITEM$type* HEAD;
		HASHITEM$type* TAIL;
	} HASHLIST;
	typedef struct _THASH {
		HASHLIST* LIST;
		integer NODES;
		integer DELSTR;
	} THASH;
	typedef struct _FBHASHTB FBHASHTB$type;
	typedef struct _FBHASHTB {
		FBSYMBOL$type* OWNER;
		THASH TB;
		FBHASHTB$type* PREV;
		FBHASHTB$type* NEXT;
	} FBHASHTB;
	typedef struct _FBSYMLIST {
		FBSYMBOL$type* HEAD;
		FBSYMBOL$type* TAIL;
	} FBSYMLIST;
	typedef struct _FBSYMCHAIN FBSYMCHAIN$type;
	typedef struct _FBSYMCHAIN {
		FBSYMBOL$type* SYM;
		FBSYMCHAIN$type* NEXT;
		integer ISIMPORT;
		FBSYMCHAIN$type* PREV;
		HASHITEM$type* ITEM;
		FBSYMCHAIN$type* IMP_NEXT;
	} FBSYMCHAIN;
	typedef struct _FBNAMESPC_EXT {
		FBSYMLIST IMPLIST;
		FBSYMLIST EXPLIST;
		integer CNT;
		FBSYMCHAIN$type* IMPSYM_HEAD;
		FBSYMCHAIN$type* IMPSYM_TAIL;
	} FBNAMESPC_EXT;
	typedef struct _FBNAMESPC {
		FBSYMBOLTB SYMTB;
		FBHASHTB$type HASHTB;
		FBNAMESPC_EXT* EXT;
	} FBNAMESPC;
	typedef struct _FB_STRUCT_DBG {
		integer TYPENUM;
	} FB_STRUCT_DBG;
	typedef struct _FB_STRUCTEXT {
		FBSYMBOL$type* CTORHEAD;
		FBSYMBOL$type* DEFCTOR;
		FBSYMBOL$type* COPYCTOR;
		FBSYMBOL$type* DTOR;
		FBSYMBOL$type* CLONE;
		FBSYMBOL$type* OPOVLTB[27];
		integer VTABLEELEMENTS;
		FBSYMBOL$type* VTABLE;
		FBSYMBOL$type* RTTI;
		integer ABSTRACTCOUNT;
	} FB_STRUCTEXT;
	typedef struct _FBS_STRUCT {
		FBNAMESPC NS;
		FBSYMBOL$type* BASE;
		FBSYMBOL$type* ANONPARENT;
		integer NATALIGN;
		integer UNPADLGT;
		short OPTIONS;
		ubyte BITPOS;
		ubyte ALIGN;
		FB_DATATYPE RETDTYPE;
		FB_STRUCT_DBG DBG;
		FB_STRUCTEXT* EXT;
	} FBS_STRUCT;
	typedef struct _FBS_BITFLD {
		integer BITPOS;
		integer BITS;
	} FBS_BITFLD;
	typedef struct _FBS_ENUM {
		FBNAMESPC NS;
		integer ELEMENTS;
		FB_STRUCT_DBG DBG;
	} FBS_ENUM;
	typedef int FB_FUNCMODE;
	typedef int FB_PROC_RETURN_METHOD;
	typedef integer (*tmp$22)( FBSYMBOL$type* );
	typedef struct _FB_PROCRTL {
		tmp$22 CALLBACK;
	} FB_PROCRTL;
	typedef struct _FB_PROCOVL {
		short MINPARAMS;
		short MAXPARAMS;
		FBSYMBOL$type* NEXT;
	} FB_PROCOVL;
	typedef struct _FB_PROCSTK {
		integer ARGOFS;
		integer LOCALOFS;
		integer LOCALMAX;
	} FB_PROCSTK;
	typedef struct _FB_PROCDBG {
		integer INILINE;
		integer ENDLINE;
		char* INCFILE;
	} FB_PROCDBG;
	typedef struct _FB_PROCERR {
		FBSYMBOL$type* LASTHND;
		FBSYMBOL$type* LASTMOD;
		FBSYMBOL$type* LASTFUN;
	} FB_PROCERR;
	typedef int AST_OP;
	typedef struct _FB_PROCOPOVL {
		AST_OP OP;
	} FB_PROCOPOVL;
	typedef struct _TLISTTB TLISTTB$type;
	typedef struct _TLISTTB {
		TLISTTB$type* NEXT;
		void* NODETB;
		integer NODES;
	} TLISTTB;
	typedef struct _TLISTNODE TLISTNODE$type;
	typedef struct _TLISTNODE {
		TLISTNODE$type* PREV;
		TLISTNODE$type* NEXT;
	} TLISTNODE;
	typedef int LIST_FLAGS;
	typedef struct _TLIST {
		TLISTTB$type* TBHEAD;
		TLISTTB$type* TBTAIL;
		integer NODES;
		integer NODELEN;
		TLISTNODE$type* FHEAD;
		void* HEAD;
		void* TAIL;
		LIST_FLAGS FLAGS;
	} TLIST;
	typedef int FB_PROCSTATS;
	typedef struct _FB_PROCGSB {
		FBSYMBOL$type* CTX;
	} FB_PROCGSB;
	typedef struct _FB_PROCEXT {
		FBSYMBOL$type* RES;
		FB_PROCSTK STK;
		FB_PROCDBG DBG;
		FB_PROCERR ERR;
		FB_PROCOPOVL OPOVL;
		TLIST* STATDTOR;
		FB_PROCSTATS STATS;
		integer STMTNUM;
		integer PRIORITY;
		FB_PROCGSB GOSUB;
		ASTNODE$type* BASE_INITREE;
		integer VTABLEINDEX;
		FBSYMBOL$type* OVERRIDDEN;
	} FB_PROCEXT;
	typedef struct _FBS_PROC {
		FBSYMBOLTB SYMTB;
		short PARAMS;
		short OPTPARAMS;
		FBSYMBOLTB PARAMTB;
		FB_FUNCMODE MODE;
		FB_DATATYPE REALDTYPE;
		FBSYMBOL$type* REALSUBTYPE;
		FB_PROC_RETURN_METHOD RETURNMETHOD;
		FB_PROCRTL RTL;
		FB_PROCOVL OVL;
		FB_PROCEXT* EXT;
	} FBS_PROC;
	typedef int FB_PARAMMODE;
	typedef struct _FBS_PARAM {
		FB_PARAMMODE MODE;
		FBSYMBOL$type* VAR;
		ASTNODE$type* OPTEXPR;
	} FBS_PARAM;
	typedef struct _FBS_LABEL {
		FBSYMBOL$type* PARENT;
		integer DECLARED;
		integer STMTNUM;
	} FBS_LABEL;
	typedef struct _FB_DEFPARAM FB_DEFPARAM$type;
	typedef struct _FB_DEFPARAM {
		char* NAME;
		integer NUM;
		FB_DEFPARAM$type* NEXT;
	} FB_DEFPARAM;
	typedef int FB_DEFTOK_TYPE;
	typedef struct _FB_DEFTOK FB_DEFTOK$type;
	typedef struct _FB_DEFTOK {
		FB_DEFTOK_TYPE TYPE;
		char* TEXT;
		wchar* TEXTW;
		integer PARAMNUM;
		FB_DEFTOK$type* PREV;
		FB_DEFTOK$type* NEXT;
	} FB_DEFTOK;
	typedef int FB_DEFINE_FLAGS;
	typedef string* (*tmp$21)( void );
	typedef struct _FBS_DEFINE {
		integer PARAMS;
		FB_DEFPARAM$type* PARAMHEAD;
		FB_DEFTOK$type* TOKHEAD;
		char* TEXT;
		wchar* TEXTW;
		integer ISARGLESS;
		FB_DEFINE_FLAGS FLAGS;
		tmp$21 PROC;
	} FBS_DEFINE;
	typedef int FB_TKCLASS;
	typedef struct _FBS_KEYWORD {
		integer ID;
		FB_TKCLASS TKCLASS;
	} FBS_KEYWORD;
	typedef struct _FBFWDREF FBFWDREF$type;
	typedef struct _FBFWDREF {
		FBSYMBOL$type* REF;
		FBFWDREF$type* PREV;
	} FBFWDREF;
	typedef struct _FBS_FWDREF {
		FBFWDREF$type* TAIL;
	} FBS_FWDREF;
	typedef struct _FB_SCOPEDBG {
		integer INILINE;
		integer ENDLINE;
		FBSYMBOL$type* INILABEL;
		FBSYMBOL$type* ENDLABEL;
	} FB_SCOPEDBG;
	typedef struct _FB_SCOPEEMIT {
		integer BASEOFS;
	} FB_SCOPEEMIT;
	typedef struct _FBS_SCOPE {
		ASTNODE$type* BACKNODE;
		FBSYMBOLTB SYMTB;
		FB_SCOPEDBG DBG;
		FB_SCOPEEMIT EMIT;
	} FBS_SCOPE;
	typedef struct _FBS_NAMESPACE {
		FBNAMESPC NS;
		integer CNT;
		FBSYMBOL$type* LAST_TAIL;
	} FBS_NAMESPACE;
	typedef struct _FBS_NSIMPORT {
		FBSYMBOL$type* IMP_NS;
		FBSYMBOL$type* IMP_PREV;
		FBSYMBOL$type* IMP_NEXT;
		FBSYMBOL$type* EXP_NS;
		FBSYMBOL$type* EXP_PREV;
		FBSYMBOL$type* EXP_NEXT;
	} FBS_NSIMPORT;
	typedef struct _FBSYMHASH {
		FBHASHTB$type* TB;
		HASHITEM$type* ITEM;
		uinteger INDEX;
		FBSYMBOL$type* PREV;
		FBSYMBOL$type* NEXT;
	} FBSYMHASH;
	typedef struct _FBSYMBOL {
		FB_SYMBCLASS CLASS;
		FB_SYMBATTRIB ATTRIB;
		FB_SYMBSTATS STATS;
		FB_SYMBID ID;
		FB_DATATYPE TYP;
		FBSYMBOL$type* SUBTYPE;
		ushort SCOPE;
		short MANGLING;
		integer LGT;
		integer OFS;
		FBS_VAR VAR_;
		FBS_CONST CON;
		FBS_STRUCT UDT;
		FBS_BITFLD BITFLD;
		FBS_ENUM ENUM_;
		FBS_PROC PROC;
		FBS_PARAM PARAM;
		FBS_LABEL LBL;
		FBS_DEFINE DEF;
		FBS_KEYWORD KEY;
		FBS_FWDREF FWD;
		FBS_SCOPE SCP;
		FBS_NAMESPACE NSPC;
		FBS_NSIMPORT NSIMP;
		FBSYMHASH HASH;
		FBSYMBOLTB* SYMTB;
		FBSYMBOL$type* PARENT;
		FBSYMBOL$type* PREV;
		FBSYMBOL$type* NEXT;
	} FBSYMBOL;
	typedef struct _FB_GLOBCTORLIST_ITEM FB_GLOBCTORLIST_ITEM$type;
	typedef struct _FB_GLOBCTORLIST_ITEM {
		FBSYMBOL$type* SYM;
		FB_GLOBCTORLIST_ITEM$type* NEXT;
	} FB_GLOBCTORLIST_ITEM;
	typedef int FB_SYMBOPT;
				typedef int FB_UDTOPT;
	typedef struct _FBARRAYDIM {
		integer LOWER;
		integer UPPER;
	} FBARRAYDIM;
	typedef struct ___FB_ARRAYDIMTB$ {
		integer ELEMENTS;
		integer LBOUND;
		integer UBOUND;
	} __FB_ARRAYDIMTB$;
	typedef struct ___FB_ARRAYDESC$ {
		void* DATA;
		void* PTR;
		integer SIZE;
		integer ELEMENT_LEN;
		integer DIMENSIONS;
		__FB_ARRAYDIMTB$ DIMTB[8];
	} __FB_ARRAYDESC$;
typedef int FB_SYMBLOOKUPOPT;
typedef struct _FB_CALL_ARG FB_CALL_ARG$type;
typedef struct _FB_CALL_ARG {
	ASTNODE$type* EXPR;
	FB_PARAMMODE MODE;
	FB_CALL_ARG$type* NEXT;
} FB_CALL_ARG;
typedef int FB_ERRMSG;
	typedef struct _FBHASHTBLIST {
		FBHASHTB$type* HEAD;
		FBHASHTB$type* TAIL;
	} FBHASHTBLIST;
	typedef struct _TSTACKTB TSTACKTB$type;
	typedef struct _TSTACKNODE TSTACKNODE$type;
	typedef struct _TSTACKNODE {
		TSTACKNODE$type* PREV;
		TSTACKNODE$type* NEXT;
	} TSTACKNODE;
	typedef struct _TSTACKTB {
		TSTACKTB$type* NEXT;
		TSTACKNODE$type* NODETB;
		integer NODES;
	} TSTACKTB;
	typedef struct _TSTACK {
		TSTACKTB$type* TBHEAD;
		TSTACKTB$type* TBTAIL;
		integer NODES;
		integer NODELEN;
		TSTACKNODE$type* TOS;
		integer CLEAR;
	} TSTACK;
	typedef struct _TPOOL {
		integer CHUNKS;
		integer CHUNKSIZE;
		TLIST* CHUNKTB;
	} TPOOL;
	typedef struct _SYMB_DEF_PARAM {
		HASHITEM$type* ITEM;
		uinteger INDEX;
	} SYMB_DEF_PARAM;
	typedef struct _SYMB_DEF_CTX {
		TLIST PARAMLIST;
		TLIST TOKLIST;
		integer PARAM;
		THASH PARAMHASH;
		SYMB_DEF_PARAM HASH[32];
	} SYMB_DEF_CTX;
	typedef struct _FB_GLOBCTORLIST {
		FB_GLOBCTORLIST_ITEM$type* HEAD;
		FB_GLOBCTORLIST_ITEM$type* TAIL;
		TLIST LIST;
	} FB_GLOBCTORLIST;
	typedef struct _SYMB_OVLOP {
		FBSYMBOL$type* HEAD;
	} SYMB_OVLOP;
	typedef struct _FB_RTTICTX {
		FBSYMBOL$type* FB_RTTI;
		FBSYMBOL$type* FB_OBJECT;
	} FB_RTTICTX;
	typedef struct _SYMBCTX {
		integer INITED;
		TLIST SYMLIST;
		FBHASHTBLIST HASHLIST;
		FBSYMCHAIN$type CHAINPOOL[32];
		integer CHAINPOOLHEAD;
		FBSYMBOL$type GLOBNSPC;
		FBSYMBOL$type* NAMESPC;
		FBHASHTB$type* HASHTB;
		FBSYMBOLTB* SYMTB;
		TSTACK NESTSTK;
		THASH IMPHASHTB;
		TLIST IMPHASHLIST;
		TPOOL NAMEPOOL;
		TLIST DIMLIST;
		TLIST FWDLIST;
		TLIST NSEXTLIST;
		integer FWDREFCNT;
		SYMB_DEF_CTX DEF;
		FBSYMBOL$type* LASTLBL;
		FB_GLOBCTORLIST GLOBCTORLIST;
		FB_GLOBCTORLIST GLOBDTORLIST;
		SYMB_OVLOP GLOBOPOVLTB[114];
		FBSYMBOL$type* ARRDESCTYPE;
		FB_RTTICTX RTTI;
	} SYMBCTX;
			typedef int FB_ERRMSGOPT;
typedef struct _FB_CALL_ARG_LIST {
	integer ARGS;
	FB_CALL_ARG$type* HEAD;
	FB_CALL_ARG$type* TAIL;
} FB_CALL_ARG_LIST;
typedef struct _TSTRSETITEM {
	string S;
	integer USERDATA;
} TSTRSETITEM;
static void _ZN11TSTRSETITEMC1Ev( TSTRSETITEM* );
static void _ZN11TSTRSETITEMaSERS_( TSTRSETITEM*, TSTRSETITEM* );
static void _ZN11TSTRSETITEMC1ERS_( TSTRSETITEM*, TSTRSETITEM* );
static void _ZN11TSTRSETITEMD1Ev( TSTRSETITEM* );
		typedef int FB_MANGLING;
				typedef int FB_LANG_OPT;
	typedef int FB_TOKEN;
	typedef int FB_DATACLASS;
static inline integer fb_dtosi ( double value ) {
/* 	volatile integer result;
	__asm__ (
		"fldl %1;"
		"fistpl %0;"
		:"=m" (result)
		:"m" (value)
	);
	return result; */
  return (integer) value;
}
#define abs( temp_ppparam$0 ) __builtin_abs( temp_ppparam$0 )
void free( void* );
string* fb_StrAssign( void*, integer, void*, integer, integer );
void fb_StrDelete( string* );
string* fb_StrConcat( string*, void*, integer, void*, integer );
string* fb_StrConcatAssign( void*, integer, void*, integer, integer );
string* fb_HEX_i( uinteger );
static void fb_ctor__symbzproc( void )__attribute__(( constructor )) ;
void* XCALLOCATE( long );
void LISTINIT( TLIST*, integer, integer, LIST_FLAGS );
void LISTEND( TLIST* );
void* LISTNEWNODE( TLIST* );
void LISTDELNODE( TLIST*, void* );
void ERRREPORTEX( integer, char*, integer, FB_ERRMSGOPT, char* );
void ERRREPORT( integer, integer, char* );
void ERRREPORTPARAM( FBSYMBOL$type*, integer, char*, integer );
ASTNODE$type* ASTADD( ASTNODE$type* );
integer ASTPTRCHECK( integer, FBSYMBOL$type*, ASTNODE$type*, integer );
ASTNODE$type* ASTNEWDECL( FBSYMBOL$type*, integer );
FBSYMCHAIN$type* SYMBLOOKUPAT( FBSYMBOL$type*, char*, integer, integer );
FBSYMBOL$type* SYMBLOOKUPBYNAMEANDCLASS( FBSYMBOL$type*, char*, integer, integer, integer );
FBSYMBOL$type* SYMBFINDOVERLOADPROC( FBSYMBOL$type*, FBSYMBOL$type*, FB_SYMBLOOKUPOPT );
FBSYMBOL$type* SYMBFINDOPOVLPROC( AST_OP, FBSYMBOL$type*, FBSYMBOL$type* );
FBSYMBOL$type* SYMBFINDCLOSESTOVLPROC( FBSYMBOL$type*, integer, FB_CALL_ARG$type*, FB_ERRMSG*, FB_SYMBLOOKUPOPT );
FBSYMBOL$type* SYMBFINDCASTOVLPROC( integer, FBSYMBOL$type*, ASTNODE$type*, FB_ERRMSG* );
FBSYMBOL$type* SYMBFINDCTOROVLPROC( FBSYMBOL$type*, ASTNODE$type*, FB_PARAMMODE, FB_ERRMSG* );
void SYMBPROCSETVTABLEINDEX( FBSYMBOL$type*, integer );
integer SYMBPROCGETVTABLEINDEX( FBSYMBOL$type* );
FBSYMBOL$type* SYMBPROCGETOVERRIDDEN( FBSYMBOL$type* );
FBSYMBOL$type* SYMBGETPROCRESULT( FBSYMBOL$type* );
integer SYMBAREPROCMODESEQUAL( FBSYMBOL$type*, FBSYMBOL$type* );
FBSYMBOL$type* SYMBADDVAR( char*, char*, integer, FBSYMBOL$type*, integer, integer, __FB_ARRAYDESC$*, integer, FB_SYMBOPT );
FBSYMBOL$type* SYMBADDPROCPARAM( FBSYMBOL$type*, char*, integer, FBSYMBOL$type*, integer, FB_SYMBATTRIB );
void SYMBMAKEPARAMOPTIONAL( FBSYMBOL$type*, FBSYMBOL$type*, ASTNODE$type* );
FBSYMBOL$type* SYMBADDPROC( FBSYMBOL$type*, char*, char*, integer, FBSYMBOL$type*, integer, integer, FB_SYMBOPT );
FBSYMBOL$type* SYMBADDPROCPTR( FBSYMBOL$type*, integer, FBSYMBOL$type*, integer, integer );
FBSYMBOL$type* SYMBPREADDPROC( char* );
void SYMBPROCALLOCEXT( FBSYMBOL$type* );
void SYMBPROCFREEEXT( FBSYMBOL$type* );
integer SYMBPROCRETURNSONSTACK( FBSYMBOL$type* );
integer SYMBCALCARGLEN( integer, FBSYMBOL$type*, integer );
integer SYMBCALCPARAMLEN( integer, FBSYMBOL$type*, FB_PARAMMODE );
FBSYMBOL$type* SYMBNEWSYMBOL( FB_SYMBOPT, FBSYMBOL$type*, FBSYMBOLTB*, FBHASHTB$type*, FB_SYMBCLASS, char*, char*, integer, FBSYMBOL$type*, FB_SYMBATTRIB );
void SYMBFREESYMBOL( FBSYMBOL$type* );
integer SYMBCALCLEN( integer, FBSYMBOL$type* );
integer TYPEREMAP( integer, FBSYMBOL$type* );
char* SYMBUNIQUEID( void );
void SYMBMANGLEINITABBREV( void );
void SYMBMANGLEENDABBREV( void );
void SYMBMANGLETYPE( string*, integer, FBSYMBOL$type* );
void SYMBMANGLEPARAM( string*, FBSYMBOL$type* );
char* SYMBTYPETOSTR( integer, FBSYMBOL$type*, integer );
integer SYMBGETDEFTYPE( char* );
integer SYMBCOMPISTRIVIAL( FBSYMBOL$type* );
void SYMBSETCOMPCTORHEAD( FBSYMBOL$type*, FBSYMBOL$type* );
void SYMBCHECKCOMPCTOR( FBSYMBOL$type*, FBSYMBOL$type* );
void SYMBSETCOMPDTOR( FBSYMBOL$type*, FBSYMBOL$type* );
FBSYMBOL$type* SYMBGETCOMPCTORHEAD( FBSYMBOL$type* );
FBSYMBOL$type* SYMBGETCOMPDTOR( FBSYMBOL$type* );
void SYMBCHECKCOMPCLONE( FBSYMBOL$type*, FBSYMBOL$type* );
FBSYMBOL$type* SYMBGETCOMPOPOVLHEAD( FBSYMBOL$type*, AST_OP );
void SYMBSETCOMPOPOVLHEAD( FBSYMBOL$type*, FBSYMBOL$type* );
integer SYMBCOMPADDVIRTUAL( FBSYMBOL$type* );
integer SYMBCHECKACCESS( FBSYMBOL$type* );
char* SYMBGETFULLPROCNAME( FBSYMBOL$type* );
integer SYMBCHECKCONSTASSIGN( FB_DATATYPE, FB_DATATYPE, FBSYMBOL$type*, FBSYMBOL$type*, FB_PARAMMODE, integer* );
integer SYMBGETUDTBASELEVEL( FBSYMBOL$type*, FBSYMBOL$type* );
void SYMBPROCRECALCREALTYPE( FBSYMBOL$type* );
static char* HMANGLEFUNCTIONPTR( FBSYMBOL$type*, integer, FBSYMBOL$type*, integer, integer );
static char* HDEMANGLEPARAMS( FBSYMBOL$type* );
static integer HCANOVERLOAD( FBSYMBOL$type* );
static FBSYMBOL$type* HADDOVLPROC( FBSYMBOL$type*, FBSYMBOL$type*, FBSYMBOLTB*, FBHASHTB$type*, char*, char*, integer, FBSYMBOL$type*, FB_SYMBATTRIB, integer );
static FBSYMBOL$type* HADDOPOVLPROC( FBSYMBOL$type*, FBSYMBOL$type*, FBSYMBOLTB*, FBHASHTB$type*, AST_OP, char*, integer, FBSYMBOL$type*, FB_SYMBATTRIB );
static FBSYMBOL$type* HSETUPPROC( FBSYMBOL$type*, FBSYMBOL$type*, FBSYMBOLTB*, FBHASHTB$type*, char*, char*, integer, FBSYMBOL$type*, integer, integer, FB_SYMBOPT );
static integer HCALCTYPESDIFF( integer, FBSYMBOL$type*, integer, integer, FBSYMBOL$type*, ASTNODE$type*, FB_PARAMMODE );
static integer HCHECKOVLPARAM( FBSYMBOL$type*, FBSYMBOL$type*, ASTNODE$type*, integer, integer* );
static integer HCHECKCASTOVL( FBSYMBOL$type*, integer, FBSYMBOL$type* );
static void HDELPARAMS( FBSYMBOL$type* );
static FB_GLOBCTORLIST_ITEM$type* HADDTOGLOBCTORLIST( FB_GLOBCTORLIST*, FBSYMBOL$type* );
static integer HAREMETHODSCOMPATIBLE( FBSYMBOL$type*, FBSYMBOL$type* );
typedef struct _$fb_RTTI $fb_RTTI$type;
typedef struct _$fb_RTTI {
	void* STDLIBVT;
	char* ID;
	$fb_RTTI$type* PRTTIBASE;
} $fb_RTTI;
extern $fb_RTTI$type __fb_ZTS6Object;
typedef void (*tmp$23)( void );
typedef integer (*tmp$24)( void );
typedef void (*tmp$25)( double );
typedef int IR_OPTIONVALUE;
typedef integer (*tmp$26)( IR_OPTIONVALUE );
typedef void (*tmp$27)( FBSYMBOL$type* );
typedef integer (*tmp$28)( FBSYMBOL$type*, FBSYMBOL$type*, integer );
typedef char* (*tmp$29)( void );
typedef int IRVREGTYPE_ENUM;
typedef int IR_REGFAMILY;
typedef struct _IRVREG IRVREG$type;
typedef struct _IRTACVREG IRTACVREG$type;
typedef struct _IRTACVREG {
	IRVREG$type* VREG;
	IRVREG$type** PPARENT;
	IRTACVREG$type* NEXT;
} IRTACVREG;
typedef struct _IRTACVREG_GRP {
	IRTACVREG$type REG;
	IRTACVREG$type IDX;
	IRTACVREG$type AUX;
} IRTACVREG_GRP;
typedef struct _IRTAC {
	integer POS;
	AST_OP OP;
	IRTACVREG_GRP VR;
	IRTACVREG_GRP V1;
	IRTACVREG_GRP V2;
	FBSYMBOL$type* EX1;
	integer EX2;
} IRTAC;
typedef struct _IRVREG {
	IRVREGTYPE_ENUM TYP;
	FB_DATATYPE DTYPE;
	FBSYMBOL$type* SUBTYPE;
	integer REG;
	IR_REGFAMILY REGFAMILY;
	integer VECTOR;
	FBVALUE VALUE;
	FBSYMBOL$type* SYM;
	integer OFS;
	integer MULT;
	IRVREG$type* VIDX;
	IRVREG$type* VAUX;
	IRTACVREG$type* TACVHEAD;
	IRTACVREG$type* TACVTAIL;
	IRTAC* TACLAST;
} IRVREG;
typedef void (*tmp$30)( IRVREG$type*, IRVREG$type* );
typedef void (*tmp$31)( integer );
typedef void (*tmp$32)( FBSYMBOL$type*, FBSYMBOL$type* );
typedef void (*tmp$33)( FBSYMBOL$type*, FBSYMBOL$type*, FBSYMBOL$type* );
typedef void (*tmp$34)( IRVREG$type*, integer, integer );
typedef void (*tmp$35)( char* );
typedef void (*tmp$36)( integer, IRVREG$type*, IRVREG$type*, IRVREG$type*, FBSYMBOL$type* );
typedef void (*tmp$37)( integer, IRVREG$type*, IRVREG$type* );
typedef void (*tmp$38)( IRVREG$type* );
typedef void (*tmp$39)( integer, IRVREG$type* );
typedef void (*tmp$40)( IRVREG$type*, integer );
typedef void (*tmp$41)( FBSYMBOL$type*, integer, IRVREG$type*, integer );
typedef void (*tmp$42)( IRVREG$type*, IRVREG$type*, integer, integer );
typedef void (*tmp$43)( integer, FBSYMBOL$type* );
typedef void (*tmp$44)( IRVREG$type*, FBSYMBOL$type*, uinteger*, FBSYMBOL$type**, integer, FBSYMBOL$type*, uinteger, uinteger );
typedef void (*tmp$45)( integer, IRVREG$type*, IRVREG$type*, integer );
typedef void (*tmp$46)( integer, FBSYMBOL$type*, integer );
typedef void (*tmp$47)( integer, integer );
typedef void (*tmp$48)( integer, double );
typedef void (*tmp$49)( integer, longint );
typedef void (*tmp$50)( FBSYMBOL$type*, integer );
typedef void (*tmp$51)( integer, char*, integer );
typedef void (*tmp$52)( integer, wchar*, integer );
typedef IRVREG$type* (*tmp$53)( integer, FBSYMBOL$type* );
typedef IRVREG$type* (*tmp$54)( integer, FBSYMBOL$type*, integer );
typedef IRVREG$type* (*tmp$55)( integer, FBSYMBOL$type*, longint );
typedef IRVREG$type* (*tmp$56)( integer, FBSYMBOL$type*, double );
typedef IRVREG$type* (*tmp$57)( integer, FBSYMBOL$type*, FBSYMBOL$type*, integer );
typedef IRVREG$type* (*tmp$58)( integer, FBSYMBOL$type*, FBSYMBOL$type*, integer, integer, IRVREG$type* );
typedef IRVREG$type* (*tmp$59)( integer, FBSYMBOL$type*, integer, IRVREG$type* );
typedef void (*tmp$60)( IRVREG$type*, integer, FBSYMBOL$type* );
typedef uinteger (*tmp$61)( IRVREG$type* );
typedef void (*tmp$62)( integer, IRVREG$type*, integer );
typedef struct _IR_VTBL {
	tmp$23 INIT;
	tmp$23 END;
	tmp$24 EMITBEGIN;
	tmp$25 EMITEND;
	tmp$26 GETOPTIONVALUE;
	tmp$27 PROCBEGIN;
	tmp$27 PROCEND;
	tmp$28 PROCALLOCARG;
	tmp$28 PROCALLOCLOCAL;
	tmp$29 PROCGETFRAMEREGNAME;
	tmp$27 SCOPEBEGIN;
	tmp$27 SCOPEEND;
	tmp$27 PROCALLOCSTATICVARS;
	tmp$30 EMITCONVERT;
	tmp$27 EMITLABEL;
	tmp$27 EMITLABELNF;
	tmp$31 EMITRETURN;
	tmp$32 EMITPROCBEGIN;
	tmp$33 EMITPROCEND;
	tmp$34 EMITPUSHARG;
	tmp$23 EMITASMBEGIN;
	tmp$35 EMITASMTEXT;
	tmp$27 EMITASMSYMB;
	tmp$23 EMITASMEND;
	tmp$35 EMITCOMMENT;
	tmp$36 EMITBOP;
	tmp$37 EMITUOP;
	tmp$30 EMITSTORE;
	tmp$23 EMITSPILLREGS;
	tmp$38 EMITLOAD;
	tmp$30 EMITLOADRES;
	tmp$39 EMITSTACK;
	tmp$40 EMITPUSHUDT;
	tmp$37 EMITADDR;
	tmp$41 EMITCALL;
	tmp$42 EMITCALLPTR;
	tmp$31 EMITSTACKALIGN;
	tmp$38 EMITJUMPPTR;
	tmp$43 EMITBRANCH;
	tmp$44 EMITJMPTB;
	tmp$45 EMITMEM;
	tmp$27 EMITSCOPEBEGIN;
	tmp$27 EMITSCOPEEND;
	tmp$27 EMITDECL;
	tmp$46 EMITDBG;
	tmp$27 EMITVARINIBEGIN;
	tmp$27 EMITVARINIEND;
	tmp$47 EMITVARINII;
	tmp$48 EMITVARINIF;
	tmp$49 EMITVARINII64;
	tmp$50 EMITVARINIOFS;
	tmp$51 EMITVARINISTR;
	tmp$52 EMITVARINIWSTR;
	tmp$31 EMITVARINIPAD;
	tmp$23 EMITVARINISCOPEBEGIN;
	tmp$23 EMITVARINISCOPEEND;
	tmp$23 EMITFBCTINFBEGIN;
	tmp$35 EMITFBCTINFSTRING;
	tmp$23 EMITFBCTINFEND;
	tmp$53 ALLOCVREG;
	tmp$54 ALLOCVRIMM;
	tmp$55 ALLOCVRIMM64;
	tmp$56 ALLOCVRIMMF;
	tmp$57 ALLOCVRVAR;
	tmp$58 ALLOCVRIDX;
	tmp$59 ALLOCVRPTR;
	tmp$57 ALLOCVROFS;
	tmp$60 SETVREGDATATYPE;
	tmp$61 GETDISTANCE;
	tmp$62 LOADVR;
	tmp$40 STOREVR;
	tmp$31 XCHGTOS;
} IR_VTBL;
extern IR_VTBL IRTAC_VTBL$;
extern IR_VTBL IRHLC_VTBL$;
extern IR_VTBL IRLLVM_VTBL$;
typedef int IR_OPT;
typedef struct _IRCTX {
	integer INITED;
	IR_VTBL VTBL;
	IR_OPT OPTIONS;
} IRCTX;
extern IRCTX IR$;
typedef struct _AST_PROC_CTX {
	ASTNODE$type* HEAD;
	ASTNODE$type* TAIL;
	ASTNODE$type* CURR;
} AST_PROC_CTX;
typedef struct _AST_CALL_CTX {
	TLIST TMPSTRLIST;
} AST_CALL_CTX;
typedef struct _AST_GLOBINST_CTX {
	TLIST LIST;
	integer CTORCNT;
	integer DTORCNT;
} AST_GLOBINST_CTX;
typedef struct _AST_DATASTMT_CTX {
	FBSYMBOL$type* DESC;
	FBSYMBOL$type* LASTSYM;
	FBSYMBOL$type* FIRSTSYM;
	FBSYMBOL$type* LASTLBL;
} AST_DATASTMT_CTX;
typedef struct _AST_DTORLIST_SCOPESTACK {
	integer* COOKIES;
	integer COUNT;
	integer ROOM;
} AST_DTORLIST_SCOPESTACK;
typedef struct _ASTCTX {
	TLIST ASTTB;
	AST_PROC_CTX PROC;
	AST_CALL_CTX CALL;
	AST_GLOBINST_CTX GLOBINST;
	AST_DATASTMT_CTX DATA;
	ASTNODE$type* CURRBLOCK;
	integer DOEMIT;
	integer TYPEINICOUNT;
	integer BITFIELDCOUNT;
	TLIST DTORLIST;
	AST_DTORLIST_SCOPESTACK DTORLISTSCOPES;
	integer DTORLISTCOOKIES;
	integer FLUSHDTORLIST;
	TLIST ASMTOKLIST;
} ASTCTX;
extern ASTCTX AST$;
extern uinteger AST_BITMASKTB$[33];
extern ulongint AST_MAXLIMITTB$[14];
extern longint AST_MINLIMITTB$[14];
typedef int AST_OPFLAGS;
typedef struct _AST_OPINFO {
	AST_NODECLASS CLASS;
	AST_OPFLAGS FLAGS;
	char* ID;
	AST_OP SELFOP;
} AST_OPINFO;
extern AST_OPINFO AST_OPTB$[114];
extern SYMBCTX SYMB$;
typedef struct _SYMB_DATATYPE {
	FB_DATACLASS CLASS;
	integer SIZE;
	integer BITS;
	integer SIGNED;
	integer INTRANK;
	FB_DATATYPE REMAPTYPE;
	char* NAME;
} SYMB_DATATYPE;
extern SYMB_DATATYPE SYMB_DTYPETB$[25];
typedef int FB_OUTTYPE;
typedef int FB_BACKEND;
typedef int FB_COMPTARGET;
typedef int FB_CPUTYPE;
typedef int FB_FPUTYPE;
typedef int FB_FPMODE;
typedef int FB_VECTORIZELEVEL;
typedef int FB_ASMSYNTAX;
typedef int FB_LANG;
typedef int FB_PDCHECK;
typedef struct _FBCMMLINEOPT {
	FB_OUTTYPE OUTTYPE;
	integer PPONLY;
	FB_BACKEND BACKEND;
	FB_COMPTARGET TARGET;
	FB_CPUTYPE CPUTYPE;
	FB_FPUTYPE FPUTYPE;
	FB_FPMODE FPMODE;
	FB_VECTORIZELEVEL VECTORIZE;
	integer OPTLEVEL;
	FB_ASMSYNTAX ASMSYNTAX;
	FB_LANG LANG;
	integer FORCELANG;
	integer DEBUG;
	integer ERRORCHECK;
	integer RESUMEERR;
	integer EXTRAERRCHK;
	integer PROFILE;
	integer WARNINGLEVEL;
	integer SHOWERROR;
	integer MAXERRORS;
	FB_PDCHECK PDCHECKOPT;
	integer GOSUBSETJMP;
	integer EXPORT;
	integer MSBITFIELDS;
	integer MULTITHREADED;
	integer STACKSIZE;
} FBCMMLINEOPT;
typedef int FB_TARGETOPT;
typedef struct _FBTARGET {
	char* ID;
	FB_DATATYPE SIZE_T;
	FB_DATATYPE WCHAR;
	FB_FUNCMODE FBCALL;
	FB_FUNCMODE STDCALL;
	FB_TARGETOPT OPTIONS;
} FBTARGET;
typedef int FBFILE_FORMAT;
typedef struct _FBFILE {
	integer NUM;
	char NAME[261];
	char* INCFILE;
	integer ISMAIN;
	FBFILE_FORMAT FORMAT;
} FBFILE;
typedef struct _FBMAIN {
	FBSYMBOL$type* PROC;
	ASTNODE$type* INITNODE;
} FBMAIN;
typedef struct _FB_LANG_TYPEREMAP {
	FB_DATATYPE INTEGER;
	FB_DATATYPE LONG;
} FB_LANG_TYPEREMAP;
typedef struct _FB_LANG_SIZEREMAP {
	integer INTEGER;
	integer LONG;
} FB_LANG_SIZEREMAP;
typedef struct _FB_LANG_LITREMAP {
	FB_DATATYPE SHORT;
	FB_DATATYPE USHORT;
	FB_DATATYPE INTEGER;
	FB_DATATYPE UINT;
	FB_DATATYPE DOUBLE;
} FB_LANG_LITREMAP;
typedef struct _FB_LANG_CTX {
	FB_LANG_OPT OPT;
	FB_LANG_TYPEREMAP TYPEREMAP;
	FB_LANG_SIZEREMAP SIZEREMAP;
	FB_LANG_LITREMAP LITREMAP;
} FB_LANG_CTX;
typedef struct _FBOPTION {
	integer BASE;
	integer PARAMMODE;
	integer EXPLICIT;
	integer PROCPUBLIC;
	integer ESCAPESTR;
	integer DYNAMIC;
	integer GOSUB;
} FBOPTION;
typedef struct _TSTRSET {
	TLIST LIST;
	THASH HASH;
} TSTRSET;
typedef struct _FBENV {
	TLIST PREDEFINES;
	TLIST PREINCLUDES;
	TLIST INCLUDEPATHS;
	FBCMMLINEOPT CLOPT;
	FBTARGET TARGET;
	integer WCHAR_DOCONV;
	FBFILE INF;
	FBFILE OUTF;
	integer PPFILE_NUM;
	THASH INCFILEHASH;
	THASH INCONCEHASH;
	integer INCLUDEREC;
	FBMAIN MAIN;
	FB_LANG_CTX LANG;
	FBOPTION OPT;
	integer RESTARTS;
	integer DORESTART;
	TSTRSET LIBS;
	TSTRSET LIBPATHS;
	integer FBCTINF_STARTED;
} FBENV;
extern FBENV ENV$;
FBENV ENV$ __attribute__((common));
typedef struct _FBTOKEN FBTOKEN$type;
typedef struct _FBTOKEN {
	integer ID;
	integer CLASS;
	integer DTYPE;
	char TEXT[1025];
	wchar TEXTW[1025];
	integer LEN;
	FBSYMCHAIN$type* SYM_CHAIN;
	integer PRDPOS;
	integer HASESC;
	integer AFTER_SPACE;
	FBTOKEN$type* NEXT;
} FBTOKEN;
typedef struct _DZSTRING {
	char* DATA;
	integer LEN;
	integer SIZE;
} DZSTRING;
typedef struct _DWSTRING {
	wchar* DATA;
	integer LEN;
	integer SIZE;
} DWSTRING;
typedef struct _LEX_TKCTX {
	FBTOKEN$type TOKENTB[4];
	integer K;
	FBTOKEN$type* HEAD;
	FBTOKEN$type* TAIL;
	uinteger CURRCHAR;
	uinteger LAHDCHAR;
	integer LINENUM;
	integer LASTTK_ID;
	integer RECLEVEL;
	FBSYMBOL$type* CURRMACRO;
	FBSYMBOL$type* KWDNS;
	integer DEFLEN;
	char* DEFPTR;
	DZSTRING DEFTEXT;
	wchar* DEFPTRW;
	DWSTRING DEFTEXTW;
	integer BUFFLEN;
	char* BUFFPTR;
	char BUFF[8193];
	wchar* BUFFPTRW;
	wchar BUFFW[8193];
	integer FILEPOS;
	integer LASTFILEPOS;
	DZSTRING CURRLINE;
	integer AFTER_SPACE;
} LEX_TKCTX;
typedef struct _LEX_CTX {
	LEX_TKCTX CTXTB[17];
	LEX_TKCTX* CTX;
	integer INSIDEMACRO;
} LEX_CTX;
extern LEX_CTX LEX$;
typedef int FB_CMPSTMT_MASK;
typedef struct _FB_CMPSTMT_FORELM {
	FBSYMBOL$type* SYM;
	FBVALUE VALUE;
	integer DTYPE;
} FB_CMPSTMT_FORELM;
typedef struct _FB_CMPSTMTSTK FB_CMPSTMTSTK$type;
typedef struct _FB_CMPSTMT_FOR {
	ASTNODE$type* OUTERSCOPENODE;
	FB_CMPSTMT_FORELM CNT;
	FB_CMPSTMT_FORELM END;
	FB_CMPSTMT_FORELM STP;
	FB_CMPSTMT_FORELM ISPOS;
	FBSYMBOL$type* TESTLABEL;
	FBSYMBOL$type* INILABEL;
	FBSYMBOL$type* CMPLABEL;
	FBSYMBOL$type* ENDLABEL;
	FB_CMPSTMTSTK$type* LAST;
	integer EXPLICIT_STEP;
} FB_CMPSTMT_FOR;
typedef struct _FB_CMPSTMT_DO {
	integer ATTOP;
	FBSYMBOL$type* INILABEL;
	FBSYMBOL$type* CMPLABEL;
	FBSYMBOL$type* ENDLABEL;
	FB_CMPSTMTSTK$type* LAST;
} FB_CMPSTMT_DO;
typedef struct _FB_CMPSTMT_WHILE {
	FBSYMBOL$type* CMPLABEL;
	FBSYMBOL$type* ENDLABEL;
	FB_CMPSTMTSTK$type* LAST;
} FB_CMPSTMT_WHILE;
typedef struct _FB_CMPSTMT_IF {
	integer ISSINGLE;
	FBSYMBOL$type* NXTLABEL;
	FBSYMBOL$type* ENDLABEL;
	integer ELSECNT;
} FB_CMPSTMT_IF;
typedef struct _FB_CMPSTMT_PROC {
	FB_TOKEN TKN;
	integer IS_NESTED;
	FBSYMBOL$type* ENDLABEL;
	FB_CMPSTMTSTK$type* LAST;
} FB_CMPSTMT_PROC;
typedef struct _FB_CMPSTMT_SELCONST {
	integer BASE;
	FBSYMBOL$type* DEFLABEL;
	uinteger MINVAL;
	uinteger MAXVAL;
} FB_CMPSTMT_SELCONST;
typedef struct _FB_CMPSTMT_SELECT {
	integer ISCONST;
	FBSYMBOL$type* SYM;
	integer CASECNT;
	FB_CMPSTMT_SELCONST CONST_;
	FBSYMBOL$type* CMPLABEL;
	FBSYMBOL$type* ENDLABEL;
	FB_CMPSTMTSTK$type* LAST;
	ASTNODE$type* OUTERSCOPENODE;
} FB_CMPSTMT_SELECT;
typedef struct _FB_CMPSTMT_WITH {
	FBSYMBOL$type* SYM;
	integer IS_PTR;
} FB_CMPSTMT_WITH;
typedef struct _FB_CMPSTMT_NAMESPACE {
	FBSYMBOL$type* SYM;
	integer LEVELS;
} FB_CMPSTMT_NAMESPACE;
typedef struct _FB_CMPSTMT_EXTERN {
	FB_MANGLING LASTMANG;
} FB_CMPSTMT_EXTERN;
typedef struct _FB_CMPSTMT_SCOPE {
	integer LASTIS_SCOPE;
} FB_CMPSTMT_SCOPE;
typedef struct _FB_CMPSTMTSTK {
	integer ID;
	FB_CMPSTMT_MASK ALLOWMASK;
	ASTNODE$type* SCOPENODE;
	FB_CMPSTMT_FOR FOR;
	FB_CMPSTMT_DO DO;
	FB_CMPSTMT_WHILE WHILE;
	FB_CMPSTMT_IF IF;
	FB_CMPSTMT_PROC PROC;
	FB_CMPSTMT_SELECT SELECT;
	FB_CMPSTMT_WITH WITH;
	FB_CMPSTMT_NAMESPACE NSPC;
	FB_CMPSTMT_EXTERN EXT;
	FB_CMPSTMT_SCOPE SCP;
} FB_CMPSTMTSTK;
typedef struct _FBPARSER_STMT_LET {
	TLIST LIST;
} FBPARSER_STMT_LET;
typedef struct _FBPARSER_STMT {
	TSTACK STK;
	FB_TOKEN ID;
	integer CNT;
	FB_CMPSTMTSTK$type* FOR;
	FB_CMPSTMTSTK$type* DO;
	FB_CMPSTMTSTK$type* WHILE;
	FB_CMPSTMTSTK$type* SELECT;
	FB_CMPSTMTSTK$type* PROC;
	FB_CMPSTMT_WITH WITH;
	FBPARSER_STMT_LET LET;
} FBPARSER_STMT;
typedef int FB_PARSEROPT;
typedef struct _PARSERCTX {
	FBPARSER_STMT STMT;
	integer NSPCREC;
	uinteger SCOPE;
	FB_MANGLING MANGLING;
	FBSYMBOL$type* CURRPROC;
	FBSYMBOL$type* CURRBLOCK;
	TLIST OVLARGLIST;
	integer PRNTCNT;
	FB_PARSEROPT OPTIONS;
	integer CTX_DTYPE;
	FBSYMBOL$type* CTXSYM;
	integer HAVE_EQ_OUTSIDE_PARENS;
} PARSERCTX;
extern PARSERCTX PARSER$;

void SYMBPROCINIT( void )
{
	label$10:;
	*(FB_GLOBCTORLIST_ITEM$type**)((ubyte *)&SYMB$ + 1500) = ((FB_GLOBCTORLIST_ITEM$type*)0);
	*(FB_GLOBCTORLIST_ITEM$type**)((ubyte *)&SYMB$ + 1504) = ((FB_GLOBCTORLIST_ITEM$type*)0);
	#define vr$0 ((TLIST*)(&*(TLIST*)((ubyte *)&SYMB$ + 1508)))
	LISTINIT( vr$0, (integer)8, (integer)8, (LIST_FLAGS)6 );
	*(FB_GLOBCTORLIST_ITEM$type**)((ubyte *)&SYMB$ + 1540) = ((FB_GLOBCTORLIST_ITEM$type*)0);
	*(FB_GLOBCTORLIST_ITEM$type**)((ubyte *)&SYMB$ + 1544) = ((FB_GLOBCTORLIST_ITEM$type*)0);
	#define vr$1 ((TLIST*)(&*(TLIST*)((ubyte *)&SYMB$ + 1548)))
	LISTINIT( vr$1, (integer)8, (integer)8, (LIST_FLAGS)6 );
	label$11:;
}

void SYMBPROCEND( void )
{
	label$12:;
	#define vr$2 ((TLIST*)(&*(TLIST*)((ubyte *)&SYMB$ + 1548)))
	LISTEND( vr$2 );
	#define vr$3 ((TLIST*)(&*(TLIST*)((ubyte *)&SYMB$ + 1508)))
	LISTEND( vr$3 );
	label$13:;
}

void SYMBPROCALLOCEXT( FBSYMBOL$type* PROC$ )
{
	label$14:;
	#define vr$4 ((FB_PROCEXT**)(PROC$))
	if (*(FB_PROCEXT**)((ubyte *)vr$4 + 100) != (integer)0) goto label$17;
	{
		void* vr$5 = (void*)(XCALLOCATE( (integer)76 ));
		#define vr$6 ((FB_PROCEXT**)(PROC$))
		*(FB_PROCEXT**)((ubyte *)vr$6 + 100) = (vr$5);
	};
	label$17:;
	label$16:;
	label$15:;
}

void SYMBPROCFREEEXT( FBSYMBOL$type* PROC$ )
{
	label$18:;
	#define vr$7 ((FB_PROCEXT**)(PROC$))
	if (*(FB_PROCEXT**)((ubyte *)vr$7 + 100) == (FB_PROCEXT*)0) goto label$21;
	{
		#define vr$8 ((FB_PROCEXT**)(PROC$))
		free( *(FB_PROCEXT**)((ubyte *)vr$8 + 100) );
		#define vr$9 ((FB_PROCEXT**)(PROC$))
		*(FB_PROCEXT**)((ubyte *)vr$9 + 100) = ((FB_PROCEXT*)0);
	};
	label$21:;
	label$20:;
	label$19:;
}

integer SYMBPROCRETURNSONSTACK( FBSYMBOL$type* PROC$ )
{
	integer fb$result$;
	#define vr$10 ((integer*)(&fb$result$))
	__builtin_memset( vr$10, 0, (integer)4 );
	label$22:;
	#define vr$11 ((FB_SYMBATTRIB*)(PROC$))
	#define vr$12 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$11 + 4) & (FB_SYMBATTRIB)33554432))
	if (vr$12 == (integer)0) goto label$25;
	{
		goto label$23;
	};
	label$25:;
	label$24:;
	#define vr$13 ((FB_DATATYPE*)(PROC$))
	#define vr$14 ((FB_DATATYPE)(*(FB_DATATYPE*)((ubyte *)vr$13 + 24) & (integer)511))
	if (vr$14 != (FB_DATATYPE)19) goto label$27;
	{
		#define vr$15 ((FB_DATATYPE*)(PROC$))
		#define vr$16 ((FB_DATATYPE)(*(FB_DATATYPE*)((ubyte *)vr$15 + 76) & (integer)511))
		#define vr$17 ((integer)((-(vr$16 == (FB_DATATYPE)51))))
		fb$result$ = (vr$17);
	};
	label$27:;
	label$26:;
	label$23:;
	#define vr$18 ((integer)(fb$result$))
	return vr$18;
}

integer SYMBCALCARGLEN( integer DTYPE$, FBSYMBOL$type* SUBTYPE$, integer MODE$ )
{
	integer fb$result$;
	#define vr$19 ((integer*)(&fb$result$))
	__builtin_memset( vr$19, 0, (integer)4 );
	label$28:;
	{
		integer TMP$73$;
		TMP$73$ = (MODE$);
		if (TMP$73$ == (FB_PARAMMODE)2) goto label$32;
		label$33:;
		if (TMP$73$ != (FB_PARAMMODE)3) goto label$31;
		label$32:;
		{
			fb$result$ = ((integer)4);
			goto label$29;
		};
		label$31:;
		label$30:;
	};
	{
		integer TMP$74$;
		#define vr$20 ((integer)(DTYPE$ & (integer)511))
		TMP$74$ = (vr$20);
		if (TMP$74$ != (FB_DATATYPE)17) goto label$35;
		label$36:;
		{
			fb$result$ = ((integer)4);
			goto label$29;
		};
		goto label$34;
		label$35:;
		if (TMP$74$ != (FB_DATATYPE)19) goto label$37;
		label$38:;
		{
			integer vr$21 = (integer)(SYMBCOMPISTRIVIAL( SUBTYPE$ ));
			if (vr$21 != (integer)0) goto label$40;
			{
				fb$result$ = ((integer)4);
				goto label$29;
			};
			label$40:;
			label$39:;
		};
		label$37:;
		label$34:;
	};
	integer vr$22 = (integer)(SYMBCALCLEN( DTYPE$, SUBTYPE$ ));
	#define vr$23 ((integer)(vr$22 + (integer)3))
	#define vr$24 ((integer)(vr$23 & (integer)-4))
	fb$result$ = (vr$24);
	label$29:;
	#define vr$25 ((integer)(fb$result$))
	return vr$25;
}

integer SYMBCALCPARAMLEN( integer DTYPE$, FBSYMBOL$type* SUBTYPE$, FB_PARAMMODE MODE$ )
{
	integer fb$result$;
	#define vr$26 ((integer*)(&fb$result$))
	__builtin_memset( vr$26, 0, (integer)4 );
	label$41:;
	if (MODE$ != (FB_PARAMMODE)4) goto label$44;
	{
		fb$result$ = ((integer)0);
	};
	goto label$43;
	label$44:;
	{
		integer vr$27 = (integer)(SYMBCALCARGLEN( DTYPE$, SUBTYPE$, MODE$ ));
		fb$result$ = (vr$27);
	};
	label$43:;
	label$42:;
	#define vr$28 ((integer)(fb$result$))
	return vr$28;
}

integer SYMBCALCPROCPARAMSLEN( FBSYMBOL$type* PROC$ )
{
	integer fb$result$;
	integer LENGTH$;
	FBSYMBOL$type* PARAM$;
	#define vr$29 ((integer*)(&fb$result$))
	__builtin_memset( vr$29, 0, (integer)4 );
	label$45:;
	#define vr$30 ((FBSYMBOL$type**)(PROC$))
	PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$30 + 64));
	LENGTH$ = ((integer)0);
	label$47:;
	if (PARAM$ == (FBSYMBOL$type*)0) goto label$48;
	{
		#define vr$31 ((integer*)(PARAM$))
		#define vr$32 ((integer)(LENGTH$ + *(integer*)((ubyte *)vr$31 + 36)))
		LENGTH$ = (vr$32);
		#define vr$33 ((FBSYMBOL$type**)(PARAM$))
		PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$33 + 148));
	};
	goto label$47;
	label$48:;
	fb$result$ = (LENGTH$);
	label$46:;
	#define vr$34 ((integer)(fb$result$))
	return vr$34;
}

FBSYMBOL$type* SYMBADDPROCPARAM( FBSYMBOL$type* PROC$, char* ID$, integer DTYPE$, FBSYMBOL$type* SUBTYPE$, integer MODE$, FB_SYMBATTRIB ATTRIB$ )
{
	FBSYMBOL$type* fb$result$;
	FBSYMBOL$type* PARAM$;
	FB_DATATYPE TMP$75$;
	#define vr$35 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$35, 0, (integer)4 );
	label$49:;
	fb$result$ = ((FBSYMBOL$type*)0);
	#define vr$36 ((FBSYMBOLTB*)(PROC$))
	#define vr$37 ((FBSYMBOLTB*)(&*(FBSYMBOLTB*)((ubyte *)vr$36 + 60)))
	FBSYMBOL$type* vr$38 = (FBSYMBOL$type*)(SYMBNEWSYMBOL( (FB_SYMBOPT)1, (integer)0, vr$37, (integer)0, (FB_SYMBCLASS)4, ID$, (integer)0, DTYPE$, SUBTYPE$, ATTRIB$ ));
	PARAM$ = (vr$38);
	if (PARAM$ != (integer)0) goto label$52;
	{
		goto label$50;
	};
	label$52:;
	label$51:;
	#define vr$39 ((short*)(PROC$))
	#define vr$40 ((integer)(*(short*)((ubyte *)vr$39 + 56)))
	#define vr$41 ((integer)(vr$40 + (integer)1))
	#define vr$42 ((short)(vr$41))
	#define vr$43 ((short*)(PROC$))
	*(short*)((ubyte *)vr$43 + 56) = (vr$42);
	integer vr$44 = (integer)(SYMBCALCPARAMLEN( DTYPE$, SUBTYPE$, MODE$ ));
	#define vr$45 ((integer*)(PARAM$))
	*(integer*)((ubyte *)vr$45 + 36) = (vr$44);
	#define vr$46 ((FB_PARAMMODE)(MODE$))
	#define vr$47 ((FB_PARAMMODE*)(PARAM$))
	*(FB_PARAMMODE*)((ubyte *)vr$47 + 44) = (vr$46);
	#define vr$48 ((ASTNODE$type**)(PARAM$))
	*(ASTNODE$type**)((ubyte *)vr$48 + 52) = ((ASTNODE$type*)0);
	#define vr$49 ((integer)(DTYPE$ & (integer)480))
	if (vr$49 == (integer)0) goto label$53;
	TMP$75$ = ((FB_DATATYPE)23);
	goto label$60;
	label$53:;
	#define vr$50 ((integer)(DTYPE$ & (integer)31))
	#define vr$51 ((FB_DATATYPE)(vr$50))
	TMP$75$ = (vr$51);
	label$60:;
	if (TMP$75$ != (FB_DATATYPE)19) goto label$55;
	{
		if (MODE$ != (FB_PARAMMODE)1) goto label$57;
		{
			if (SUBTYPE$ != *(FBSYMBOL$type**)((ubyte *)&SYMB$ + 968)) goto label$59;
			{
				#define vr$52 ((short*)(SUBTYPE$))
				#define vr$53 ((FB_UDTOPT)(*(short*)((ubyte *)vr$52 + 100)))
				#define vr$54 ((FB_UDTOPT)(vr$53 | (FB_UDTOPT)32))
				#define vr$55 ((short)(vr$54))
				#define vr$56 ((short*)(SUBTYPE$))
				*(short*)((ubyte *)vr$56 + 100) = (vr$55);
			};
			label$59:;
			label$58:;
		};
		label$57:;
		label$56:;
	};
	label$55:;
	label$54:;
	fb$result$ = (PARAM$);
	label$50:;
	#define vr$57 ((FBSYMBOL$type*)(fb$result$))
	return vr$57;
}

void SYMBMAKEPARAMOPTIONAL( FBSYMBOL$type* PROC$, FBSYMBOL$type* PARAM$, ASTNODE$type* OPTEXPR$ )
{
	label$61:;
	if (OPTEXPR$ != (integer)0) goto label$64;
	{
		goto label$62;
	};
	label$64:;
	label$63:;
	#define vr$58 ((FB_SYMBATTRIB*)(PARAM$))
	#define vr$59 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$58 + 4) | (FB_SYMBATTRIB)2097152))
	#define vr$60 ((FB_SYMBATTRIB*)(PARAM$))
	*(FB_SYMBATTRIB*)((ubyte *)vr$60 + 4) = (vr$59);
	#define vr$61 ((ASTNODE$type**)(PARAM$))
	*(ASTNODE$type**)((ubyte *)vr$61 + 52) = (OPTEXPR$);
	#define vr$62 ((short*)(PROC$))
	#define vr$63 ((integer)(*(short*)((ubyte *)vr$62 + 58)))
	#define vr$64 ((integer)(vr$63 + (integer)1))
	#define vr$65 ((short)(vr$64))
	#define vr$66 ((short*)(PROC$))
	*(short*)((ubyte *)vr$66 + 58) = (vr$65);
	label$62:;
}

integer SYMBISPROCOVERLOADOF( FBSYMBOL$type* PROC$, FBSYMBOL$type* HEAD_PROC$ )
{
	integer fb$result$;
	FBSYMBOL$type* F$;
	#define vr$67 ((integer*)(&fb$result$))
	__builtin_memset( vr$67, 0, (integer)4 );
	label$65:;
	if (HEAD_PROC$ != (integer)0) goto label$68;
	{
		fb$result$ = ((integer)0);
		goto label$66;
	};
	label$68:;
	label$67:;
	if (PROC$ != HEAD_PROC$) goto label$70;
	{
		fb$result$ = ((integer)-1);
		goto label$66;
	};
	label$70:;
	label$69:;
	#define vr$68 ((FB_SYMBATTRIB*)(HEAD_PROC$))
	#define vr$69 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$68 + 4) & (FB_SYMBATTRIB)1024))
	#define vr$70 ((integer)((-(vr$69 != (integer)0))))
	if (vr$70 != (integer)0) goto label$72;
	{
		fb$result$ = ((integer)0);
		goto label$66;
	};
	label$72:;
	label$71:;
	#define vr$71 ((FBSYMBOL$type**)(HEAD_PROC$))
	F$ = (*(FBSYMBOL$type**)((ubyte *)vr$71 + 96));
	label$73:;
	if (F$ == (integer)0) goto label$74;
	{
		if (PROC$ != F$) goto label$76;
		{
			fb$result$ = ((integer)-1);
			goto label$66;
		};
		label$76:;
		label$75:;
		#define vr$72 ((FBSYMBOL$type**)(F$))
		F$ = (*(FBSYMBOL$type**)((ubyte *)vr$72 + 96));
	};
	goto label$73;
	label$74:;
	fb$result$ = ((integer)0);
	goto label$66;
	label$66:;
	#define vr$73 ((integer)(fb$result$))
	return vr$73;
}

void SYMBPROCRECALCREALTYPE( FBSYMBOL$type* PROC$ )
{
	integer DTYPE$;
	FBSYMBOL$type* SUBTYPE$;
	label$77:;
	#define vr$74 ((FB_DATATYPE*)(PROC$))
	#define vr$75 ((integer)(*(FB_DATATYPE*)((ubyte *)vr$74 + 24)))
	DTYPE$ = (vr$75);
	#define vr$76 ((FBSYMBOL$type**)(PROC$))
	SUBTYPE$ = (*(FBSYMBOL$type**)((ubyte *)vr$76 + 28));
	#define vr$77 ((FB_SYMBATTRIB*)(PROC$))
	#define vr$78 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$77 + 4) & (FB_SYMBATTRIB)33554432))
	if (vr$78 == (integer)0) goto label$80;
	{
		#define vr$79 ((integer)(DTYPE$ & (integer)31))
		#define vr$80 ((integer)(DTYPE$ & (integer)480))
		#define vr$81 ((integer)(vr$80 + (integer)32))
		#define vr$82 ((integer)(vr$79 | vr$81))
		#define vr$83 ((integer)(DTYPE$ & (integer)261632))
		#define vr$84 ((integer)(vr$83 << (integer)1))
		#define vr$85 ((integer)(vr$82 | vr$84))
		DTYPE$ = (vr$85);
	};
	label$80:;
	label$79:;
	{
		integer TMP$76$;
		#define vr$86 ((integer)(DTYPE$ & (integer)511))
		TMP$76$ = (vr$86);
		if (TMP$76$ == (FB_DATATYPE)17) goto label$83;
		label$84:;
		if (TMP$76$ != (FB_DATATYPE)6) goto label$82;
		label$83:;
		{
			#define vr$87 ((integer)(DTYPE$ & (integer)31))
			#define vr$88 ((integer)(DTYPE$ & (integer)480))
			#define vr$89 ((integer)(vr$88 + (integer)32))
			#define vr$90 ((integer)(vr$87 | vr$89))
			#define vr$91 ((integer)(DTYPE$ & (integer)261632))
			#define vr$92 ((integer)(vr$91 << (integer)1))
			#define vr$93 ((integer)(vr$90 | vr$92))
			DTYPE$ = (vr$93);
		};
		goto label$81;
		label$82:;
		if (TMP$76$ != (FB_DATATYPE)19) goto label$85;
		label$86:;
		{
			if (SUBTYPE$ != *(FBSYMBOL$type**)((ubyte *)&SYMB$ + 968)) goto label$88;
			{
				#define vr$94 ((short*)(SUBTYPE$))
				#define vr$95 ((FB_UDTOPT)(*(short*)((ubyte *)vr$94 + 100)))
				#define vr$96 ((FB_UDTOPT)(vr$95 | (FB_UDTOPT)64))
				#define vr$97 ((short)(vr$96))
				#define vr$98 ((short*)(SUBTYPE$))
				*(short*)((ubyte *)vr$98 + 100) = (vr$97);
			};
			goto label$87;
			label$88:;
			{
				#define vr$99 ((FB_DATATYPE*)(SUBTYPE$))
				#define vr$100 ((integer)(*(FB_DATATYPE*)((ubyte *)vr$99 + 104)))
				DTYPE$ = (vr$100);
				#define vr$101 ((integer)(DTYPE$ & (integer)31))
				if (vr$101 == (FB_DATATYPE)19) goto label$90;
				{
					SUBTYPE$ = ((FBSYMBOL$type*)0);
				};
				label$90:;
				label$89:;
			};
			label$87:;
		};
		label$85:;
		label$81:;
	};
	#define vr$102 ((FB_DATATYPE)(DTYPE$))
	#define vr$103 ((FB_DATATYPE*)(PROC$))
	*(FB_DATATYPE*)((ubyte *)vr$103 + 76) = (vr$102);
	#define vr$104 ((FBSYMBOL$type**)(PROC$))
	*(FBSYMBOL$type**)((ubyte *)vr$104 + 80) = (SUBTYPE$);
	label$78:;
}

FBSYMBOL$type* SYMBADDPROC( FBSYMBOL$type* PROC$, char* ID$, char* ID_ALIAS$, integer DTYPE$, FBSYMBOL$type* SUBTYPE$, integer ATTRIB$, integer MODE$, FB_SYMBOPT OPTIONS$ )
{
	FBSYMBOL$type* fb$result$;
	FBSYMBOL$type* PARENT$;
	FBSYMBOLTB* SYMTB$;
	FBHASHTB$type* HASHTB$;
	#define vr$105 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$105, 0, (integer)4 );
	label$281:;
	PARENT$ = (*(FBSYMBOL$type**)((ubyte *)&SYMB$ + 968));
	#define vr$106 ((FBSYMBOLTB*)(PARENT$))
	#define vr$107 ((FBSYMBOLTB*)(&*(FBSYMBOLTB*)((ubyte *)vr$106 + 44)))
	SYMTB$ = (vr$107);
	#define vr$108 ((FBHASHTB$type*)(PARENT$))
	#define vr$109 ((FBHASHTB$type*)(&*(FBHASHTB$type*)((ubyte *)vr$108 + 56)))
	HASHTB$ = (vr$109);
	#define vr$110 ((FB_SYMBATTRIB)(ATTRIB$ | (FB_SYMBATTRIB)1))
	#define vr$111 ((integer)(vr$110))
	ATTRIB$ = (vr$111);
	FBSYMBOL$type* vr$112 = (FBSYMBOL$type*)(HSETUPPROC( PROC$, PARENT$, SYMTB$, HASHTB$, ID$, ID_ALIAS$, DTYPE$, SUBTYPE$, ATTRIB$, MODE$, OPTIONS$ ));
	fb$result$ = (vr$112);
	label$282:;
	#define vr$113 ((FBSYMBOL$type*)(fb$result$))
	return vr$113;
}

FBSYMBOL$type* SYMBADDOPERATOR( FBSYMBOL$type* PROC$, AST_OP OP$, char* ID_ALIAS$, integer DTYPE$, FBSYMBOL$type* SUBTYPE$, integer ATTRIB$, integer MODE$, FB_SYMBOPT OPTIONS$ )
{
	FBSYMBOL$type* fb$result$;
	FBSYMBOL$type* SYM$;
	#define vr$114 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$114, 0, (integer)4 );
	label$283:;
	SYMBPROCALLOCEXT( PROC$ );
	#define vr$115 ((FB_PROCEXT**)(PROC$))
	#define vr$116 ((AST_OP*)(*(FB_PROCEXT**)((ubyte *)vr$115 + 100)))
	*(AST_OP*)((ubyte *)vr$116 + 40) = (OP$);
	FBSYMBOL$type* vr$117 = (FBSYMBOL$type*)(SYMBADDPROC( PROC$, (integer)0, ID_ALIAS$, DTYPE$, SUBTYPE$, ATTRIB$, MODE$, OPTIONS$ ));
	SYM$ = (vr$117);
	if (SYM$ != (integer)0) goto label$286;
	{
		SYMBPROCFREEEXT( PROC$ );
		goto label$284;
	};
	label$286:;
	label$285:;
	fb$result$ = (SYM$);
	label$284:;
	#define vr$118 ((FBSYMBOL$type*)(fb$result$))
	return vr$118;
}

FBSYMBOL$type* SYMBADDCTOR( FBSYMBOL$type* PROC$, char* ID_ALIAS$, integer ATTRIB$, integer MODE$, FB_SYMBOPT OPTIONS$ )
{
	FBSYMBOL$type* fb$result$;
	#define vr$119 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$119, 0, (integer)4 );
	label$287:;
	FBSYMBOL$type* vr$120 = (FBSYMBOL$type*)(SYMBADDPROC( PROC$, (integer)0, ID_ALIAS$, (FB_DATATYPE)0, (integer)0, ATTRIB$, MODE$, OPTIONS$ ));
	fb$result$ = (vr$120);
	label$288:;
	#define vr$121 ((FBSYMBOL$type*)(fb$result$))
	return vr$121;
}

FBSYMBOL$type* SYMBADDPROCPTR( FBSYMBOL$type* PROC$, integer DTYPE$, FBSYMBOL$type* SUBTYPE$, integer ATTRIB$, integer MODE$ )
{
	FBSYMBOL$type* fb$result$;
	char* ID$;
	FBSYMCHAIN$type* CHAIN_$;
	FBSYMBOL$type* SYM$;
	FBSYMBOL$type* PARENT$;
	FBSYMBOLTB* SYMTB$;
	FBHASHTB$type* HASHTB$;
	#define vr$122 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$122, 0, (integer)4 );
	label$289:;
	char* vr$123 = (char*)(HMANGLEFUNCTIONPTR( PROC$, DTYPE$, SUBTYPE$, ATTRIB$, MODE$ ));
	ID$ = (vr$123);
	if (*(uinteger*)((ubyte *)&PARSER$ + 96) != (integer)0) goto label$292;
	{
		#define vr$124 ((FBSYMBOL$type*)(&*(FBSYMBOL$type*)((ubyte *)&SYMB$ + 816)))
		PARENT$ = (vr$124);
		#define vr$125 ((FBSYMBOLTB*)(PARENT$))
		#define vr$126 ((FBSYMBOLTB*)(&*(FBSYMBOLTB*)((ubyte *)vr$125 + 44)))
		SYMTB$ = (vr$126);
		#define vr$127 ((FBHASHTB$type*)(PARENT$))
		#define vr$128 ((FBHASHTB$type*)(&*(FBHASHTB$type*)((ubyte *)vr$127 + 56)))
		HASHTB$ = (vr$128);
		#define vr$129 ((FB_SYMBATTRIB)(ATTRIB$ | (FB_SYMBATTRIB)1))
		#define vr$130 ((integer)(vr$129))
		ATTRIB$ = (vr$130);
	};
	goto label$291;
	label$292:;
	{
		PARENT$ = (*(FBSYMBOL$type**)((ubyte *)&SYMB$ + 968));
		SYMTB$ = (*(FBSYMBOLTB**)((ubyte *)&SYMB$ + 976));
		#define vr$131 ((FBHASHTB$type*)(PARENT$))
		#define vr$132 ((FBHASHTB$type*)(&*(FBHASHTB$type*)((ubyte *)vr$131 + 56)))
		HASHTB$ = (vr$132);
		#define vr$133 ((FB_SYMBATTRIB)(ATTRIB$ | (FB_SYMBATTRIB)128))
		#define vr$134 ((integer)(vr$133))
		ATTRIB$ = (vr$134);
	};
	label$291:;
	FBSYMCHAIN$type* vr$135 = (FBSYMCHAIN$type*)(SYMBLOOKUPAT( PARENT$, ID$, (integer)-1, (integer)0 ));
	CHAIN_$ = (vr$135);
	if (CHAIN_$ == (integer)0) goto label$294;
	{
		#define vr$136 ((FBSYMBOL$type**)(CHAIN_$))
		fb$result$ = (*(FBSYMBOL$type**)((ubyte *)vr$136));
		goto label$290;
	};
	label$294:;
	label$293:;
	char* vr$137 = (char*)(SYMBUNIQUEID(  ));
	FBSYMBOL$type* vr$138 = (FBSYMBOL$type*)(HSETUPPROC( PROC$, PARENT$, SYMTB$, HASHTB$, ID$, vr$137, DTYPE$, SUBTYPE$, ATTRIB$, MODE$, (FB_SYMBOPT)5 ));
	SYM$ = (vr$138);
	if (SYM$ == (integer)0) goto label$296;
	{
		#define vr$139 ((FB_SYMBSTATS*)(SYM$))
		#define vr$140 ((FB_SYMBSTATS)(*(FB_SYMBSTATS*)((ubyte *)vr$139 + 8) | (FB_SYMBSTATS)16384))
		#define vr$141 ((FB_SYMBSTATS*)(SYM$))
		*(FB_SYMBSTATS*)((ubyte *)vr$141 + 8) = (vr$140);
	};
	label$296:;
	label$295:;
	fb$result$ = (SYM$);
	label$290:;
	#define vr$142 ((FBSYMBOL$type*)(fb$result$))
	return vr$142;
}

FBSYMBOL$type* SYMBADDPROCPTRFROMFUNCTION( FBSYMBOL$type* BASE_PROC$ )
{
	FBSYMBOL$type* fb$result$;
	FBSYMBOL$type* PROC$;
	FBSYMBOL$type* PARAM$;
	#define vr$143 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$143, 0, (integer)4 );
	label$297:;
	FBSYMBOL$type* vr$144 = (FBSYMBOL$type*)(SYMBPREADDPROC( (integer)0 ));
	PROC$ = (vr$144);
	#define vr$145 ((FB_PROC_RETURN_METHOD*)(BASE_PROC$))
	#define vr$146 ((FB_PROC_RETURN_METHOD*)(PROC$))
	*(FB_PROC_RETURN_METHOD*)((ubyte *)vr$146 + 84) = (*(FB_PROC_RETURN_METHOD*)((ubyte *)vr$145 + 84));
	#define vr$147 ((FBSYMBOL$type**)(BASE_PROC$))
	PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$147 + 64));
	label$299:;
	if (PARAM$ == (integer)0) goto label$300;
	{
		FBSYMBOL$type* P$;
		#define vr$148 ((FB_SYMBATTRIB*)(PARAM$))
		#define vr$149 ((FB_PARAMMODE*)(PARAM$))
		#define vr$150 ((FBSYMBOL$type**)(PARAM$))
		#define vr$151 ((FB_DATATYPE*)(PARAM$))
		FBSYMBOL$type* vr$152 = (FBSYMBOL$type*)(SYMBADDPROCPARAM( PROC$, (integer)0, *(FB_DATATYPE*)((ubyte *)vr$151 + 24), *(FBSYMBOL$type**)((ubyte *)vr$150 + 28), *(FB_PARAMMODE*)((ubyte *)vr$149 + 44), *(FB_SYMBATTRIB*)((ubyte *)vr$148 + 4) ));
		P$ = (vr$152);
		#define vr$153 ((FB_SYMBSTATS*)(PARAM$))
		#define vr$154 ((FB_SYMBSTATS)(*(FB_SYMBSTATS*)((ubyte *)vr$153 + 8) & (FB_SYMBSTATS)2048))
		if (vr$154 == (integer)0) goto label$302;
		{
			#define vr$155 ((FB_SYMBSTATS*)(P$))
			#define vr$156 ((FB_SYMBSTATS)(*(FB_SYMBSTATS*)((ubyte *)vr$155 + 8) | (FB_SYMBSTATS)2048))
			#define vr$157 ((FB_SYMBSTATS*)(P$))
			*(FB_SYMBSTATS*)((ubyte *)vr$157 + 8) = (vr$156);
		};
		label$302:;
		label$301:;
		#define vr$158 ((ASTNODE$type**)(PARAM$))
		SYMBMAKEPARAMOPTIONAL( PROC$, P$, *(ASTNODE$type**)((ubyte *)vr$158 + 52) );
		#define vr$159 ((FBSYMBOL$type**)(PARAM$))
		PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$159 + 148));
	};
	goto label$299;
	label$300:;
	#define vr$160 ((FB_FUNCMODE*)(BASE_PROC$))
	#define vr$161 ((FB_SYMBATTRIB*)(BASE_PROC$))
	#define vr$162 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$161 + 4) & (FB_SYMBATTRIB)33554432))
	#define vr$163 ((FBSYMBOL$type**)(BASE_PROC$))
	#define vr$164 ((FB_DATATYPE*)(BASE_PROC$))
	FBSYMBOL$type* vr$165 = (FBSYMBOL$type*)(SYMBADDPROCPTR( PROC$, *(FB_DATATYPE*)((ubyte *)vr$164 + 24), *(FBSYMBOL$type**)((ubyte *)vr$163 + 28), vr$162, *(FB_FUNCMODE*)((ubyte *)vr$160 + 72) ));
	fb$result$ = (vr$165);
	label$298:;
	#define vr$166 ((FBSYMBOL$type*)(fb$result$))
	return vr$166;
}

FBSYMBOL$type* SYMBPREADDPROC( char* SYMBOL$ )
{
	FBSYMBOL$type* fb$result$;
	FBSYMBOL$type* PROC$;
	#define vr$167 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$167, 0, (integer)4 );
	label$303:;
	#define vr$168 ((TLIST*)(&*(TLIST*)((ubyte *)&SYMB$ + 4)))
	void* vr$169 = (void*)(LISTNEWNODE( vr$168 ));
	PROC$ = (vr$169);
	#define vr$170 ((FB_SYMBCLASS*)(PROC$))
	*(FB_SYMBCLASS*)((ubyte *)vr$170) = ((FB_SYMBCLASS)3);
	#define vr$171 ((FB_SYMBATTRIB*)(PROC$))
	*(FB_SYMBATTRIB*)((ubyte *)vr$171 + 4) = ((FB_SYMBATTRIB)0);
	#define vr$172 ((FB_SYMBSTATS*)(PROC$))
	*(FB_SYMBSTATS*)((ubyte *)vr$172 + 8) = ((FB_SYMBSTATS)0);
	#define vr$173 ((char**)(PROC$))
	*(char**)((ubyte *)vr$173 + 12) = (SYMBOL$);
	#define vr$174 ((char**)(PROC$))
	*(char**)((ubyte *)vr$174 + 16) = ((char*)0);
	#define vr$175 ((char**)(PROC$))
	*(char**)((ubyte *)vr$175 + 20) = ((char*)0);
	#define vr$176 ((FB_DATATYPE*)(PROC$))
	*(FB_DATATYPE*)((ubyte *)vr$176 + 24) = ((FB_DATATYPE)-2147483648u);
	#define vr$177 ((FBSYMBOL$type**)(PROC$))
	*(FBSYMBOL$type**)((ubyte *)vr$177 + 28) = ((FBSYMBOL$type*)0);
	#define vr$178 ((ushort*)(PROC$))
	*(ushort*)((ubyte *)vr$178 + 32) = ((ushort)0);
	#define vr$179 ((short*)(PROC$))
	*(short*)((ubyte *)vr$179 + 34) = ((short)0);
	#define vr$180 ((integer*)(PROC$))
	*(integer*)((ubyte *)vr$180 + 36) = ((integer)0);
	#define vr$181 ((integer*)(PROC$))
	*(integer*)((ubyte *)vr$181 + 40) = ((integer)0);
	#define vr$182 ((short*)(PROC$))
	*(short*)((ubyte *)vr$182 + 56) = ((short)0);
	#define vr$183 ((short*)(PROC$))
	*(short*)((ubyte *)vr$183 + 58) = ((short)0);
	#define vr$184 ((FBSYMBOL$type**)(PROC$))
	*(FBSYMBOL$type**)((ubyte *)vr$184 + 60) = (PROC$);
	#define vr$185 ((FBSYMBOL$type**)(PROC$))
	*(FBSYMBOL$type**)((ubyte *)vr$185 + 64) = ((FBSYMBOL$type*)0);
	#define vr$186 ((FBSYMBOL$type**)(PROC$))
	*(FBSYMBOL$type**)((ubyte *)vr$186 + 68) = ((FBSYMBOL$type*)0);
	#define vr$187 ((FB_FUNCMODE*)(PROC$))
	*(FB_FUNCMODE*)((ubyte *)vr$187 + 72) = (*(FB_FUNCMODE*)((ubyte *)&ENV$ + 212));
	#define vr$188 ((FB_DATATYPE*)(PROC$))
	*(FB_DATATYPE*)((ubyte *)vr$188 + 76) = ((FB_DATATYPE)-2147483648u);
	#define vr$189 ((FBSYMBOL$type**)(PROC$))
	*(FBSYMBOL$type**)((ubyte *)vr$189 + 80) = ((FBSYMBOL$type*)0);
	#define vr$190 ((FB_PROC_RETURN_METHOD*)(PROC$))
	*(FB_PROC_RETURN_METHOD*)((ubyte *)vr$190 + 84) = ((FB_PROC_RETURN_METHOD)0);
	#define vr$191 ((tmp$22*)(PROC$))
	*(tmp$22*)((ubyte *)vr$191 + 88) = ((tmp$22)0);
	#define vr$192 ((short*)(PROC$))
	*(short*)((ubyte *)vr$192 + 92) = ((short)0);
	#define vr$193 ((short*)(PROC$))
	*(short*)((ubyte *)vr$193 + 94) = ((short)0);
	#define vr$194 ((FBSYMBOL$type**)(PROC$))
	*(FBSYMBOL$type**)((ubyte *)vr$194 + 96) = ((FBSYMBOL$type*)0);
	#define vr$195 ((FB_PROCEXT**)(PROC$))
	*(FB_PROCEXT**)((ubyte *)vr$195 + 100) = ((FB_PROCEXT*)0);
	#define vr$196 ((FBSYMBOLTB*)(*(FBSYMBOL$type**)((ubyte *)&SYMB$ + 968)))
	#define vr$197 ((FBSYMBOLTB*)(&*(FBSYMBOLTB*)((ubyte *)vr$196 + 44)))
	#define vr$198 ((FBSYMBOLTB**)(PROC$))
	*(FBSYMBOLTB**)((ubyte *)vr$198 + 136) = (vr$197);
	#define vr$199 ((FBHASHTB$type*)(*(FBSYMBOL$type**)((ubyte *)&SYMB$ + 968)))
	#define vr$200 ((FBHASHTB$type*)(&*(FBHASHTB$type*)((ubyte *)vr$199 + 56)))
	#define vr$201 ((FBHASHTB$type**)(PROC$))
	*(FBHASHTB$type**)((ubyte *)vr$201 + 116) = (vr$200);
	#define vr$202 ((HASHITEM$type**)(PROC$))
	*(HASHITEM$type**)((ubyte *)vr$202 + 120) = ((HASHITEM$type*)0);
	#define vr$203 ((uinteger*)(PROC$))
	*(uinteger*)((ubyte *)vr$203 + 124) = ((uinteger)0u);
	#define vr$204 ((FBSYMBOL$type**)(PROC$))
	*(FBSYMBOL$type**)((ubyte *)vr$204 + 128) = ((FBSYMBOL$type*)0);
	#define vr$205 ((FBSYMBOL$type**)(PROC$))
	*(FBSYMBOL$type**)((ubyte *)vr$205 + 132) = ((FBSYMBOL$type*)0);
	#define vr$206 ((FBSYMBOL$type**)(PROC$))
	*(FBSYMBOL$type**)((ubyte *)vr$206 + 140) = ((FBSYMBOL$type*)0);
	#define vr$207 ((FBSYMBOL$type**)(PROC$))
	*(FBSYMBOL$type**)((ubyte *)vr$207 + 144) = ((FBSYMBOL$type*)0);
	#define vr$208 ((FBSYMBOL$type**)(PROC$))
	*(FBSYMBOL$type**)((ubyte *)vr$208 + 148) = ((FBSYMBOL$type*)0);
	fb$result$ = (PROC$);
	label$304:;
	#define vr$209 ((FBSYMBOL$type*)(fb$result$))
	return vr$209;
}

FBSYMBOL$type* SYMBADDVARFORPARAM( FBSYMBOL$type* PARAM$ )
{
	FBSYMBOL$type* fb$result$;
	FBARRAYDIM DTB$[1];
	typedef struct _TMP$80 {
		FBARRAYDIM* DATA;
		FBARRAYDIM* PTR;
		integer SIZE;
		integer ELEMENT_LEN;
		integer DIMENSIONS;
		__FB_ARRAYDIMTB$ DIMTB[1];
	} TMP$80;
	TMP$80 tmp$79$;
	FBSYMBOL$type* S$;
	integer ATTRIB$;
	integer DTYPE$;
	#define vr$210 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$210, 0, (integer)4 );
	label$305:;
	#define vr$211 ((FBARRAYDIM*)(&*(FBARRAYDIM*)((ubyte *)DTB$)))
	*(FBARRAYDIM**)(&tmp$79$) = (vr$211);
	#define vr$212 ((FBARRAYDIM*)(&*(FBARRAYDIM*)((ubyte *)DTB$)))
	*(FBARRAYDIM**)((ubyte *)&tmp$79$ + 4) = (vr$212);
	*(integer*)((ubyte *)&tmp$79$ + 8) = ((integer)8);
	*(integer*)((ubyte *)&tmp$79$ + 12) = ((integer)8);
	*(integer*)((ubyte *)&tmp$79$ + 16) = ((integer)1);
	*(integer*)((ubyte *)&tmp$79$ + 20) = ((integer)1);
	*(integer*)((ubyte *)&tmp$79$ + 24) = ((integer)0);
	*(integer*)((ubyte *)&tmp$79$ + 28) = ((integer)0);
	fb$result$ = ((FBSYMBOL$type*)0);
	#define vr$213 ((FB_DATATYPE*)(PARAM$))
	#define vr$214 ((integer)(*(FB_DATATYPE*)((ubyte *)vr$213 + 24)))
	DTYPE$ = (vr$214);
	{
		uinteger TMP$81$;
		#define vr$215 ((FB_PARAMMODE*)(PARAM$))
		#define vr$216 ((uinteger)(*(FB_PARAMMODE*)((ubyte *)vr$215 + 44)))
		TMP$81$ = (vr$216);
		goto label$308;
		label$309:;
		{
			ATTRIB$ = ((integer)131072);
			{
				FB_DATATYPE TMP$82$;
				#define vr$217 ((FB_DATATYPE*)(PARAM$))
				#define vr$218 ((FB_DATATYPE)(*(FB_DATATYPE*)((ubyte *)vr$217 + 24) & (integer)511))
				TMP$82$ = (vr$218);
				if (*(integer*)(&TMP$82$) != (FB_DATATYPE)17) goto label$311;
				label$312:;
				{
					ATTRIB$ = ((integer)262144);
					#define vr$219 ((integer)(DTYPE$ & (integer)-512))
					#define vr$220 ((FB_DATATYPE)(vr$219 | (FB_DATATYPE)3))
					#define vr$221 ((integer)(vr$220))
					DTYPE$ = (vr$221);
				};
				goto label$310;
				label$311:;
				if (*(integer*)(&TMP$82$) != (FB_DATATYPE)19) goto label$313;
				label$314:;
				{
					#define vr$222 ((FBSYMBOL$type**)(PARAM$))
					integer vr$223 = (integer)(SYMBCOMPISTRIVIAL( *(FBSYMBOL$type**)((ubyte *)vr$222 + 28) ));
					if (vr$223 != (integer)0) goto label$316;
					{
						ATTRIB$ = ((integer)262144);
					};
					label$316:;
					label$315:;
				};
				label$313:;
				label$310:;
			};
		};
		goto label$307;
		label$317:;
		{
			ATTRIB$ = ((integer)262144);
		};
		goto label$307;
		label$318:;
		{
			ATTRIB$ = ((integer)65536);
		};
		goto label$307;
		label$319:;
		{
			goto label$306;
		};
		goto label$307;
		label$308:;
		if (TMP$81$ < (uinteger)1u) goto label$319;
		if (TMP$81$ > (uinteger)3u) goto label$319;
		static const void * LABEL$320$[] = {
			&&label$309,
			&&label$317,
			&&label$318,
		(void *)0 };
		#define vr$224 ((uinteger)(TMP$81$ << (uinteger)2u))
		goto **(void**)((ubyte *)LABEL$320$ + vr$224 + -4);
		label$307:;
	};
	#define vr$225 ((FB_SYMBATTRIB*)(PARAM$))
	#define vr$226 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$225 + 4) & (FB_SYMBATTRIB)2048))
	if (vr$226 == (integer)0) goto label$322;
	{
		#define vr$227 ((FB_SYMBATTRIB)(ATTRIB$ | (FB_SYMBATTRIB)2048))
		#define vr$228 ((integer)(vr$227))
		ATTRIB$ = (vr$228);
	};
	label$322:;
	label$321:;
	#define vr$229 ((FB_SYMBATTRIB*)(PARAM$))
	#define vr$230 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$229 + 4) & (FB_SYMBATTRIB)268435456))
	if (vr$230 == (integer)0) goto label$324;
	{
		#define vr$231 ((FB_SYMBATTRIB)(ATTRIB$ | (FB_SYMBATTRIB)268435456))
		#define vr$232 ((integer)(vr$231))
		ATTRIB$ = (vr$232);
	};
	label$324:;
	label$323:;
	#define vr$233 ((__FB_ARRAYDESC$*)(&*(__FB_ARRAYDESC$*)(&tmp$79$)))
	#define vr$234 ((void*)(vr$233))
	#define vr$235 ((FBSYMBOL$type**)(PARAM$))
	#define vr$236 ((char**)(PARAM$))
	FBSYMBOL$type* vr$237 = (FBSYMBOL$type*)(SYMBADDVAR( *(char**)((ubyte *)vr$236 + 12), (integer)0, DTYPE$, *(FBSYMBOL$type**)((ubyte *)vr$235 + 28), (integer)0, (integer)0, vr$234, ATTRIB$, (FB_SYMBOPT)0 ));
	S$ = (vr$237);
	if (S$ != (integer)0) goto label$326;
	{
		goto label$306;
	};
	label$326:;
	label$325:;
	#define vr$238 ((FB_SYMBSTATS*)(S$))
	#define vr$239 ((FB_SYMBSTATS)(*(FB_SYMBSTATS*)((ubyte *)vr$238 + 8) | (FB_SYMBSTATS)8))
	#define vr$240 ((FB_SYMBSTATS*)(S$))
	*(FB_SYMBSTATS*)((ubyte *)vr$240 + 8) = (vr$239);
	#define vr$241 ((FB_SYMBSTATS*)(PARAM$))
	#define vr$242 ((FB_SYMBSTATS)(*(FB_SYMBSTATS*)((ubyte *)vr$241 + 8) & (FB_SYMBSTATS)2048))
	if (vr$242 == (integer)0) goto label$328;
	{
		#define vr$243 ((FB_SYMBSTATS*)(S$))
		#define vr$244 ((FB_SYMBSTATS)(*(FB_SYMBSTATS*)((ubyte *)vr$243 + 8) | (FB_SYMBSTATS)2048))
		#define vr$245 ((FB_SYMBSTATS*)(S$))
		*(FB_SYMBSTATS*)((ubyte *)vr$245 + 8) = (vr$244);
	};
	label$328:;
	label$327:;
	fb$result$ = (S$);
	label$306:;
	#define vr$246 ((FBSYMBOL$type*)(fb$result$))
	return vr$246;
}

FBSYMBOL$type* SYMBADDPROCRESULTPARAM( FBSYMBOL$type* PROC$ )
{
	FBSYMBOL$type* fb$result$;
	FBARRAYDIM DTB$[1];
	typedef struct _TMP$86 {
		FBARRAYDIM* DATA;
		FBARRAYDIM* PTR;
		integer SIZE;
		integer ELEMENT_LEN;
		integer DIMENSIONS;
		__FB_ARRAYDIMTB$ DIMTB[1];
	} TMP$86;
	TMP$86 tmp$85$;
	FBSYMBOL$type* S$;
	static string ID$;
	#define vr$247 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$247, 0, (integer)4 );
	label$329:;
	#define vr$248 ((FBARRAYDIM*)(&*(FBARRAYDIM*)((ubyte *)DTB$)))
	*(FBARRAYDIM**)(&tmp$85$) = (vr$248);
	#define vr$249 ((FBARRAYDIM*)(&*(FBARRAYDIM*)((ubyte *)DTB$)))
	*(FBARRAYDIM**)((ubyte *)&tmp$85$ + 4) = (vr$249);
	*(integer*)((ubyte *)&tmp$85$ + 8) = ((integer)8);
	*(integer*)((ubyte *)&tmp$85$ + 12) = ((integer)8);
	*(integer*)((ubyte *)&tmp$85$ + 16) = ((integer)1);
	*(integer*)((ubyte *)&tmp$85$ + 20) = ((integer)1);
	*(integer*)((ubyte *)&tmp$85$ + 24) = ((integer)0);
	*(integer*)((ubyte *)&tmp$85$ + 28) = ((integer)0);
	integer vr$250 = (integer)(SYMBPROCRETURNSONSTACK( PROC$ ));
	if (vr$250 != (integer)0) goto label$332;
	{
		fb$result$ = ((FBSYMBOL$type*)0);
		goto label$330;
	};
	label$332:;
	label$331:;
	char* vr$251 = (char*)(SYMBUNIQUEID(  ));
	fb_StrAssign( (string*)&ID$, (integer)-1, vr$251, (integer)0, (integer)0 );
	#define vr$252 ((__FB_ARRAYDESC$*)(&*(__FB_ARRAYDESC$*)(&tmp$85$)))
	#define vr$253 ((void*)(vr$252))
	#define vr$254 ((FBSYMBOL$type**)(PROC$))
	#define vr$255 ((char**)((string*)&ID$))
	FBSYMBOL$type* vr$256 = (FBSYMBOL$type*)(SYMBADDVAR( *(char**)((ubyte *)vr$255), (integer)0, (FB_DATATYPE)19, *(FBSYMBOL$type**)((ubyte *)vr$254 + 28), (integer)4, (integer)0, vr$253, (FB_SYMBATTRIB)262144, (FB_SYMBOPT)1 ));
	S$ = (vr$256);
	SYMBPROCALLOCEXT( PROC$ );
	#define vr$257 ((FB_PROCEXT**)(PROC$))
	#define vr$258 ((FBSYMBOL$type**)(*(FB_PROCEXT**)((ubyte *)vr$257 + 100)))
	*(FBSYMBOL$type**)((ubyte *)vr$258) = (S$);
	#define vr$259 ((FB_SYMBSTATS*)(S$))
	#define vr$260 ((FB_SYMBSTATS)(*(FB_SYMBSTATS*)((ubyte *)vr$259 + 8) | (FB_SYMBSTATS)8))
	#define vr$261 ((FB_SYMBSTATS*)(S$))
	*(FB_SYMBSTATS*)((ubyte *)vr$261 + 8) = (vr$260);
	fb$result$ = (S$);
	label$330:;
	#define vr$262 ((FBSYMBOL$type*)(fb$result$))
	return vr$262;
}

FBSYMBOL$type* SYMBADDPROCRESULT( FBSYMBOL$type* PROC$ )
{
	FBSYMBOL$type* fb$result$;
	FBARRAYDIM DTB$[1];
	typedef struct _TMP$88 {
		FBARRAYDIM* DATA;
		FBARRAYDIM* PTR;
		integer SIZE;
		integer ELEMENT_LEN;
		integer DIMENSIONS;
		__FB_ARRAYDIMTB$ DIMTB[1];
	} TMP$88;
	TMP$88 tmp$87$;
	FBSYMBOL$type* RES$;
	integer DTYPE$;
	char* ID$;
	#define vr$263 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$263, 0, (integer)4 );
	label$333:;
	#define vr$264 ((FBARRAYDIM*)(&*(FBARRAYDIM*)((ubyte *)DTB$)))
	*(FBARRAYDIM**)(&tmp$87$) = (vr$264);
	#define vr$265 ((FBARRAYDIM*)(&*(FBARRAYDIM*)((ubyte *)DTB$)))
	*(FBARRAYDIM**)((ubyte *)&tmp$87$ + 4) = (vr$265);
	*(integer*)((ubyte *)&tmp$87$ + 8) = ((integer)8);
	*(integer*)((ubyte *)&tmp$87$ + 12) = ((integer)8);
	*(integer*)((ubyte *)&tmp$87$ + 16) = ((integer)1);
	*(integer*)((ubyte *)&tmp$87$ + 20) = ((integer)1);
	*(integer*)((ubyte *)&tmp$87$ + 24) = ((integer)0);
	*(integer*)((ubyte *)&tmp$87$ + 28) = ((integer)0);
	integer vr$266 = (integer)(SYMBPROCRETURNSONSTACK( PROC$ ));
	if (vr$266 == (integer)0) goto label$336;
	{
		FBSYMBOL$type* vr$267 = (FBSYMBOL$type*)(SYMBGETPROCRESULT( PROC$ ));
		fb$result$ = (vr$267);
		goto label$334;
	};
	label$336:;
	label$335:;
	#define vr$268 ((FB_DATATYPE*)(PROC$))
	#define vr$269 ((integer)(*(FB_DATATYPE*)((ubyte *)vr$268 + 24)))
	DTYPE$ = (vr$269);
	#define vr$270 ((FB_SYMBATTRIB*)(PROC$))
	#define vr$271 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$270 + 4) & (FB_SYMBATTRIB)33554432))
	if (vr$271 == (integer)0) goto label$338;
	{
		#define vr$272 ((integer)(DTYPE$ & (integer)31))
		#define vr$273 ((integer)(DTYPE$ & (integer)480))
		#define vr$274 ((integer)(vr$273 + (integer)32))
		#define vr$275 ((integer)(vr$272 | vr$274))
		#define vr$276 ((integer)(DTYPE$ & (integer)261632))
		#define vr$277 ((integer)(vr$276 << (integer)1))
		#define vr$278 ((integer)(vr$275 | vr$277))
		DTYPE$ = (vr$278);
	};
	label$338:;
	label$337:;
	#define vr$279 ((__FB_ARRAYDESC$*)(&*(__FB_ARRAYDESC$*)(&tmp$87$)))
	#define vr$280 ((void*)(vr$279))
	#define vr$281 ((FBSYMBOL$type**)(PROC$))
	FBSYMBOL$type* vr$282 = (FBSYMBOL$type*)(SYMBADDVAR( (char*)"fb$result", (integer)0, DTYPE$, *(FBSYMBOL$type**)((ubyte *)vr$281 + 28), (integer)0, (integer)0, vr$280, (FB_SYMBATTRIB)16777216, (FB_SYMBOPT)1 ));
	RES$ = (vr$282);
	SYMBPROCALLOCEXT( PROC$ );
	#define vr$283 ((FB_PROCEXT**)(PROC$))
	#define vr$284 ((FBSYMBOL$type**)(*(FB_PROCEXT**)((ubyte *)vr$283 + 100)))
	*(FBSYMBOL$type**)((ubyte *)vr$284) = (RES$);
	ASTNODE$type* vr$285 = (ASTNODE$type*)(ASTNEWDECL( RES$, (integer)-1 ));
	ASTADD( vr$285 );
	#define vr$286 ((FB_SYMBSTATS*)(RES$))
	#define vr$287 ((FB_SYMBSTATS)(*(FB_SYMBSTATS*)((ubyte *)vr$286 + 8) | (FB_SYMBSTATS)8))
	#define vr$288 ((FB_SYMBSTATS*)(RES$))
	*(FB_SYMBSTATS*)((ubyte *)vr$288 + 8) = (vr$287);
	fb$result$ = (RES$);
	label$334:;
	#define vr$289 ((FBSYMBOL$type*)(fb$result$))
	return vr$289;
}

void SYMBADDPROCINSTANCEPTR( FBSYMBOL$type* PARENT$, FBSYMBOL$type* PROC$ )
{
	integer DTYPE$;
	label$339:;
	{
		FB_SYMBCLASS TMP$90$;
		#define vr$290 ((FB_SYMBCLASS*)(PARENT$))
		TMP$90$ = (*(FB_SYMBCLASS*)((ubyte *)vr$290));
		if (*(integer*)(&TMP$90$) != (FB_SYMBCLASS)10) goto label$342;
		label$343:;
		{
			DTYPE$ = ((integer)19);
		};
		goto label$341;
		label$342:;
		if (*(integer*)(&TMP$90$) != (FB_SYMBCLASS)11) goto label$344;
		label$345:;
		{
		};
		label$344:;
		label$341:;
	};
	#define vr$291 ((FB_SYMBATTRIB*)(PROC$))
	#define vr$292 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$291 + 4) & (FB_SYMBATTRIB)1048576))
	if (vr$292 == (integer)0) goto label$347;
	{
		#define vr$293 ((integer)(DTYPE$ | (integer)512))
		DTYPE$ = (vr$293);
	};
	label$347:;
	label$346:;
	SYMBADDPROCPARAM( PROC$, (char*)"THIS", DTYPE$, PARENT$, (FB_PARAMMODE)2, (FB_SYMBATTRIB)2048 );
	label$340:;
}

FBSYMBOL$type* SYMBFINDOVERLOADPROC( FBSYMBOL$type* OVL_HEAD_PROC$, FBSYMBOL$type* PROC$, FB_SYMBLOOKUPOPT OPTIONS$ )
{
	FBSYMBOL$type* fb$result$;
	FBSYMBOL$type* OVL$;
	FBSYMBOL$type* OVL_PARAM$;
	FBSYMBOL$type* PARAM$;
	FBSYMBOL$type* OVL_SUBTYPE$;
	FBSYMBOL$type* SUBTYPE$;
	integer OVL_PARAMS$;
	integer PARAMS$;
	integer I$;
	integer IS_PROPERTY$;
	#define vr$294 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$294, 0, (integer)4 );
	label$348:;
	#define vr$295 ((integer)((-(OVL_HEAD_PROC$ == (integer)0))))
	#define vr$296 ((integer)((-(PROC$ == (integer)0))))
	#define vr$297 ((integer)(vr$295 | vr$296))
	if (vr$297 == (integer)0) goto label$351;
	{
		fb$result$ = ((FBSYMBOL$type*)0);
		goto label$349;
	};
	label$351:;
	label$350:;
	#define vr$298 ((FB_SYMBCLASS*)(OVL_HEAD_PROC$))
	#define vr$299 ((integer)((-(*(FB_SYMBCLASS*)((ubyte *)vr$298) != (FB_SYMBCLASS)3))))
	#define vr$300 ((FB_SYMBCLASS*)(PROC$))
	#define vr$301 ((integer)((-(*(FB_SYMBCLASS*)((ubyte *)vr$300) != (FB_SYMBCLASS)3))))
	#define vr$302 ((integer)(vr$299 | vr$301))
	if (vr$302 == (integer)0) goto label$353;
	{
		fb$result$ = ((FBSYMBOL$type*)0);
		goto label$349;
	};
	label$353:;
	label$352:;
	#define vr$303 ((short*)(PROC$))
	#define vr$304 ((integer)(*(short*)((ubyte *)vr$303 + 56)))
	PARAMS$ = (vr$304);
	#define vr$305 ((FB_SYMBATTRIB*)(PROC$))
	#define vr$306 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$305 + 4) & (FB_SYMBATTRIB)2048))
	if (vr$306 == (integer)0) goto label$355;
	{
		#define vr$307 ((integer)(PARAMS$ + (integer)-1))
		PARAMS$ = (vr$307);
	};
	label$355:;
	label$354:;
	#define vr$308 ((FB_SYMBATTRIB*)(OVL_HEAD_PROC$))
	#define vr$309 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$308 + 4) & (FB_SYMBATTRIB)32768))
	#define vr$310 ((integer)((-(vr$309 != (integer)0))))
	IS_PROPERTY$ = (vr$310);
	OVL$ = (OVL_HEAD_PROC$);
	label$356:;
	{
		#define vr$311 ((short*)(OVL$))
		#define vr$312 ((integer)(*(short*)((ubyte *)vr$311 + 56)))
		OVL_PARAMS$ = (vr$312);
		#define vr$313 ((FB_SYMBATTRIB*)(OVL$))
		#define vr$314 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$313 + 4) & (FB_SYMBATTRIB)2048))
		if (vr$314 == (integer)0) goto label$360;
		{
			#define vr$315 ((integer)(OVL_PARAMS$ + (integer)-1))
			OVL_PARAMS$ = (vr$315);
		};
		label$360:;
		label$359:;
		if (IS_PROPERTY$ == (integer)0) goto label$362;
		{
			#define vr$316 ((FB_SYMBLOOKUPOPT)(OPTIONS$ & (FB_SYMBLOOKUPOPT)1))
			if (vr$316 == (integer)0) goto label$364;
			{
				#define vr$317 ((FB_DATATYPE*)(OVL$))
				#define vr$318 ((FB_DATATYPE)(*(FB_DATATYPE*)((ubyte *)vr$317 + 24) & (integer)511))
				if (vr$318 != (FB_DATATYPE)0) goto label$366;
				{
					OVL_PARAMS$ = ((integer)-1);
				};
				label$366:;
				label$365:;
			};
			goto label$363;
			label$364:;
			{
				#define vr$319 ((FB_DATATYPE*)(OVL$))
				#define vr$320 ((FB_DATATYPE)(*(FB_DATATYPE*)((ubyte *)vr$319 + 24) & (integer)511))
				if (vr$320 == (FB_DATATYPE)0) goto label$368;
				{
					OVL_PARAMS$ = ((integer)-1);
				};
				label$368:;
				label$367:;
			};
			label$363:;
		};
		label$362:;
		label$361:;
		if (PARAMS$ != OVL_PARAMS$) goto label$370;
		{
			if (PARAMS$ != (integer)0) goto label$372;
			{
				fb$result$ = (OVL$);
				goto label$349;
			};
			label$372:;
			label$371:;
			#define vr$321 ((FBSYMBOL$type**)(OVL$))
			OVL_PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$321 + 68));
			#define vr$322 ((FBSYMBOL$type**)(PROC$))
			PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$322 + 68));
			label$373:;
			{
				#define vr$323 ((FB_PARAMMODE*)(PARAM$))
				#define vr$324 ((FB_PARAMMODE*)(OVL_PARAM$))
				if (*(FB_PARAMMODE*)((ubyte *)vr$323 + 44) == *(FB_PARAMMODE*)((ubyte *)vr$324 + 44)) goto label$377;
				{
					#define vr$325 ((FB_PARAMMODE*)(PARAM$))
					if (*(FB_PARAMMODE*)((ubyte *)vr$325 + 44) != (FB_PARAMMODE)3) goto label$379;
					{
						goto label$374;
					};
					goto label$378;
					label$379:;
					#define vr$326 ((FB_PARAMMODE*)(OVL_PARAM$))
					if (*(FB_PARAMMODE*)((ubyte *)vr$326 + 44) != (FB_PARAMMODE)3) goto label$380;
					{
						goto label$374;
					};
					label$380:;
					label$378:;
				};
				label$377:;
				label$376:;
				#define vr$327 ((FB_DATATYPE*)(PARAM$))
				#define vr$328 ((FB_DATATYPE*)(OVL_PARAM$))
				if (*(FB_DATATYPE*)((ubyte *)vr$327 + 24) == *(FB_DATATYPE*)((ubyte *)vr$328 + 24)) goto label$382;
				{
					goto label$374;
				};
				label$382:;
				label$381:;
				#define vr$329 ((FBSYMBOL$type**)(PARAM$))
				#define vr$330 ((FBSYMBOL$type**)(OVL_PARAM$))
				if (*(FBSYMBOL$type**)((ubyte *)vr$329 + 28) == *(FBSYMBOL$type**)((ubyte *)vr$330 + 28)) goto label$384;
				{
					goto label$374;
				};
				label$384:;
				label$383:;
				#define vr$331 ((FBSYMBOL$type**)(PARAM$))
				PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$331 + 144));
				#define vr$332 ((FBSYMBOL$type**)(OVL_PARAM$))
				OVL_PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$332 + 144));
				#define vr$333 ((integer)(OVL_PARAMS$ + (integer)-1))
				OVL_PARAMS$ = (vr$333);
			};
			label$375:;
			if (OVL_PARAMS$ > (integer)0) goto label$373;
			label$374:;
			if (OVL_PARAMS$ != (integer)0) goto label$386;
			{
				fb$result$ = (OVL$);
				goto label$349;
			};
			label$386:;
			label$385:;
		};
		label$370:;
		label$369:;
		#define vr$334 ((FBSYMBOL$type**)(OVL$))
		OVL$ = (*(FBSYMBOL$type**)((ubyte *)vr$334 + 96));
	};
	label$358:;
	if (OVL$ != (integer)0) goto label$356;
	label$357:;
	fb$result$ = ((FBSYMBOL$type*)0);
	label$349:;
	#define vr$335 ((FBSYMBOL$type*)(fb$result$))
	return vr$335;
}

FBSYMBOL$type* SYMBFINDOPOVLPROC( AST_OP OP$, FBSYMBOL$type* OVL_HEAD_PROC$, FBSYMBOL$type* PROC$ )
{
	FBSYMBOL$type* fb$result$;
	FBSYMBOL$type* OVL$;
	#define vr$336 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$336, 0, (integer)4 );
	label$387:;
	if (OP$ == (AST_OP)26) goto label$390;
	{
		FBSYMBOL$type* vr$337 = (FBSYMBOL$type*)(SYMBFINDOVERLOADPROC( OVL_HEAD_PROC$, PROC$, (FB_SYMBLOOKUPOPT)0 ));
		fb$result$ = (vr$337);
		goto label$388;
	};
	label$390:;
	label$389:;
	OVL$ = (OVL_HEAD_PROC$);
	label$391:;
	if (OVL$ == (integer)0) goto label$392;
	{
		#define vr$338 ((FB_DATATYPE*)(PROC$))
		#define vr$339 ((FB_DATATYPE*)(OVL$))
		if (*(FB_DATATYPE*)((ubyte *)vr$338 + 24) != *(FB_DATATYPE*)((ubyte *)vr$339 + 24)) goto label$394;
		{
			#define vr$340 ((FBSYMBOL$type**)(PROC$))
			#define vr$341 ((FBSYMBOL$type**)(OVL$))
			if (*(FBSYMBOL$type**)((ubyte *)vr$340 + 28) != *(FBSYMBOL$type**)((ubyte *)vr$341 + 28)) goto label$396;
			{
				fb$result$ = (OVL$);
				goto label$388;
			};
			label$396:;
			label$395:;
		};
		label$394:;
		label$393:;
		#define vr$342 ((FBSYMBOL$type**)(OVL$))
		OVL$ = (*(FBSYMBOL$type**)((ubyte *)vr$342 + 96));
	};
	goto label$391;
	label$392:;
	fb$result$ = ((FBSYMBOL$type*)0);
	label$388:;
	#define vr$343 ((FBSYMBOL$type*)(fb$result$))
	return vr$343;
}

FBSYMBOL$type* SYMBFINDCTORPROC( FBSYMBOL$type* OVL_HEAD_PROC$, FBSYMBOL$type* PROC$ )
{
	FBSYMBOL$type* fb$result$;
	#define vr$344 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$344, 0, (integer)4 );
	label$397:;
	#define vr$345 ((FB_SYMBATTRIB*)(OVL_HEAD_PROC$))
	#define vr$346 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$345 + 4) & (FB_SYMBATTRIB)8192))
	if (vr$346 == (integer)0) goto label$400;
	{
		fb$result$ = (OVL_HEAD_PROC$);
		goto label$398;
	};
	goto label$399;
	label$400:;
	{
		FBSYMBOL$type* vr$347 = (FBSYMBOL$type*)(SYMBFINDOVERLOADPROC( OVL_HEAD_PROC$, PROC$, (FB_SYMBLOOKUPOPT)0 ));
		fb$result$ = (vr$347);
		goto label$398;
	};
	label$399:;
	label$398:;
	#define vr$348 ((FBSYMBOL$type*)(fb$result$))
	return vr$348;
}

FBSYMBOL$type* SYMBFINDCLOSESTOVLPROC( FBSYMBOL$type* OVL_HEAD_PROC$, integer ARGS$, FB_CALL_ARG$type* ARG_HEAD$, FB_ERRMSG* ERR_NUM$, FB_SYMBLOOKUPOPT OPTIONS$ )
{
	FBSYMBOL$type* fb$result$;
	FBSYMBOL$type* OVL$;
	FBSYMBOL$type* CLOSEST_PROC$;
	FBSYMBOL$type* PARAM$;
	integer I$;
	integer ARG_MATCHES$;
	integer MATCHES$;
	integer MAX_MATCHES$;
	integer AMB_CNT$;
	integer EXACT_MATCHES$;
	integer CONSTONLY_DIFF$;
	FB_CALL_ARG$type* ARG$;
	integer IS_PROPERTY$;
	#define vr$349 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$349, 0, (integer)4 );
	label$573:;
	#define vr$350 ((FB_ERRMSG*)(ERR_NUM$))
	*(FB_ERRMSG*)((ubyte *)vr$350) = ((FB_ERRMSG)0);
	if (OVL_HEAD_PROC$ != (integer)0) goto label$576;
	{
		fb$result$ = ((FBSYMBOL$type*)0);
		goto label$574;
	};
	label$576:;
	label$575:;
	CLOSEST_PROC$ = ((FBSYMBOL$type*)0);
	MAX_MATCHES$ = ((integer)0);
	AMB_CNT$ = ((integer)0);
	#define vr$351 ((FB_SYMBATTRIB*)(OVL_HEAD_PROC$))
	#define vr$352 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$351 + 4) & (FB_SYMBATTRIB)32768))
	#define vr$353 ((integer)((-(vr$352 != (integer)0))))
	IS_PROPERTY$ = (vr$353);
	OVL$ = (OVL_HEAD_PROC$);
	label$577:;
	{
		integer PARAMS$;
		#define vr$354 ((short*)(OVL$))
		#define vr$355 ((integer)(*(short*)((ubyte *)vr$354 + 56)))
		PARAMS$ = (vr$355);
		#define vr$356 ((FB_SYMBATTRIB*)(OVL$))
		#define vr$357 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$356 + 4) & (FB_SYMBATTRIB)2048))
		if (vr$357 == (integer)0) goto label$581;
		{
			#define vr$358 ((integer)(PARAMS$ + (integer)-1))
			PARAMS$ = (vr$358);
		};
		label$581:;
		label$580:;
		if (IS_PROPERTY$ == (integer)0) goto label$583;
		{
			#define vr$359 ((FB_SYMBLOOKUPOPT)(OPTIONS$ & (FB_SYMBLOOKUPOPT)1))
			if (vr$359 == (integer)0) goto label$585;
			{
				#define vr$360 ((FB_DATATYPE*)(OVL$))
				#define vr$361 ((FB_DATATYPE)(*(FB_DATATYPE*)((ubyte *)vr$360 + 24) & (integer)511))
				if (vr$361 != (FB_DATATYPE)0) goto label$587;
				{
					PARAMS$ = ((integer)-1);
				};
				label$587:;
				label$586:;
			};
			goto label$584;
			label$585:;
			{
				#define vr$362 ((FB_DATATYPE*)(OVL$))
				#define vr$363 ((FB_DATATYPE)(*(FB_DATATYPE*)((ubyte *)vr$362 + 24) & (integer)511))
				if (vr$363 == (FB_DATATYPE)0) goto label$589;
				{
					PARAMS$ = ((integer)-1);
				};
				label$589:;
				label$588:;
			};
			label$584:;
		};
		label$583:;
		label$582:;
		if (ARGS$ > PARAMS$) goto label$591;
		{
			integer TOTAL_ARGS$;
			if (PARAMS$ != (integer)0) goto label$593;
			{
				fb$result$ = (OVL$);
				goto label$574;
			};
			label$593:;
			label$592:;
			#define vr$364 ((FBSYMBOL$type**)(OVL$))
			PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$364 + 64));
			#define vr$365 ((FB_SYMBATTRIB*)(OVL$))
			#define vr$366 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$365 + 4) & (FB_SYMBATTRIB)2048))
			if (vr$366 == (integer)0) goto label$595;
			{
				#define vr$367 ((FBSYMBOL$type**)(PARAM$))
				PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$367 + 148));
			};
			label$595:;
			label$594:;
			MATCHES$ = ((integer)0);
			EXACT_MATCHES$ = ((integer)0);
			ARG$ = (ARG_HEAD$);
			{
				integer TMP$127$;
				I$ = ((integer)0);
				#define vr$368 ((integer)(ARGS$ + (integer)-1))
				TMP$127$ = (vr$368);
				goto label$596;
				label$599:;
				{
					#define vr$369 ((integer*)(&CONSTONLY_DIFF$))
					#define vr$370 ((FB_PARAMMODE*)(ARG$))
					#define vr$371 ((ASTNODE$type**)(ARG$))
					integer vr$372 = (integer)(HCHECKOVLPARAM( OVL$, PARAM$, *(ASTNODE$type**)((ubyte *)vr$371), *(FB_PARAMMODE*)((ubyte *)vr$370 + 4), vr$369 ));
					ARG_MATCHES$ = (vr$372);
					if (ARG_MATCHES$ != (integer)0) goto label$601;
					{
						MATCHES$ = ((integer)0);
						goto label$598;
					};
					label$601:;
					label$600:;
					#define vr$373 ((FB_SYMBLOOKUPOPT)(OPTIONS$ & (FB_SYMBLOOKUPOPT)2))
					if (vr$373 == (FB_SYMBLOOKUPOPT)0) goto label$603;
					{
						if (ARG_MATCHES$ != (FB_DATATYPE)50) goto label$605;
						{
							#define vr$374 ((integer)(EXACT_MATCHES$ + (integer)1))
							EXACT_MATCHES$ = (vr$374);
						};
						label$605:;
						label$604:;
					};
					label$603:;
					label$602:;
					#define vr$375 ((integer)(MATCHES$ + ARG_MATCHES$))
					MATCHES$ = (vr$375);
					#define vr$376 ((FBSYMBOL$type**)(PARAM$))
					PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$376 + 148));
					#define vr$377 ((FB_CALL_ARG$type**)(ARG$))
					ARG$ = (*(FB_CALL_ARG$type**)((ubyte *)vr$377 + 8));
				};
				label$597:;
				#define vr$378 ((integer)(I$ + (integer)1))
				I$ = (vr$378);
				label$596:;
				if (I$ <= TMP$127$) goto label$599;
				label$598:;
			};
			TOTAL_ARGS$ = (ARGS$);
			if (ARGS$ >= PARAMS$) goto label$607;
			{
				#define vr$379 ((integer)((-(MATCHES$ > (integer)0))))
				#define vr$380 ((integer)((-(ARGS$ == (integer)0))))
				#define vr$381 ((integer)(vr$379 | vr$380))
				if (vr$381 == (integer)0) goto label$609;
				{
					label$610:;
					if (PARAM$ == (integer)0) goto label$611;
					{
						#define vr$382 ((FB_SYMBATTRIB*)(PARAM$))
						#define vr$383 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$382 + 4) & (FB_SYMBATTRIB)2097152))
						#define vr$384 ((integer)((-(vr$383 != (integer)0))))
						if (vr$384 != (integer)0) goto label$613;
						{
							MATCHES$ = ((integer)0);
							goto label$611;
						};
						goto label$612;
						label$613:;
						{
							#define vr$385 ((integer)(MATCHES$ + (integer)50))
							#define vr$386 ((integer)(vr$385))
							MATCHES$ = (vr$386);
						};
						label$612:;
						#define vr$387 ((integer)(TOTAL_ARGS$ + (integer)1))
						TOTAL_ARGS$ = (vr$387);
						#define vr$388 ((FBSYMBOL$type**)(PARAM$))
						PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$388 + 148));
					};
					goto label$610;
					label$611:;
				};
				label$609:;
				label$608:;
			};
			label$607:;
			label$606:;
			#define vr$389 ((double)(MATCHES$))
			#define vr$390 ((double)(TOTAL_ARGS$))
			#define vr$391 ((double)((double)vr$389 / (double)vr$390))
			integer vr$392 = (integer)(fb_dtosi( vr$391 ));
			MATCHES$ = (vr$392);
			if (MATCHES$ <= MAX_MATCHES$) goto label$615;
			{
				integer ELIGIBLE$;
				ELIGIBLE$ = ((integer)-1);
				#define vr$393 ((FB_SYMBLOOKUPOPT)(OPTIONS$ & (FB_SYMBLOOKUPOPT)2))
				if (vr$393 == (FB_SYMBLOOKUPOPT)0) goto label$617;
				{
					#define vr$394 ((integer)((-(EXACT_MATCHES$ == (integer)0))))
					#define vr$395 ((integer)((-(CONSTONLY_DIFF$ == (integer)0))))
					#define vr$396 ((integer)(vr$394 & vr$395))
					if (vr$396 == (integer)0) goto label$619;
					{
						ELIGIBLE$ = ((integer)0);
					};
					label$619:;
					label$618:;
				};
				label$617:;
				label$616:;
				if (ELIGIBLE$ == (integer)0) goto label$621;
				{
					CLOSEST_PROC$ = (OVL$);
					MAX_MATCHES$ = (MATCHES$);
					AMB_CNT$ = ((integer)0);
				};
				label$621:;
				label$620:;
			};
			goto label$614;
			label$615:;
			if (MATCHES$ != MAX_MATCHES$) goto label$622;
			{
				if (MAX_MATCHES$ <= (integer)0) goto label$624;
				{
					#define vr$397 ((integer)(AMB_CNT$ + (integer)1))
					AMB_CNT$ = (vr$397);
				};
				label$624:;
				label$623:;
			};
			label$622:;
			label$614:;
		};
		label$591:;
		label$590:;
		#define vr$398 ((FBSYMBOL$type**)(OVL$))
		OVL$ = (*(FBSYMBOL$type**)((ubyte *)vr$398 + 96));
	};
	label$579:;
	if (OVL$ != (integer)0) goto label$577;
	label$578:;
	if (AMB_CNT$ <= (integer)0) goto label$626;
	{
		#define vr$399 ((FB_ERRMSG*)(ERR_NUM$))
		*(FB_ERRMSG*)((ubyte *)vr$399) = ((FB_ERRMSG)90);
		fb$result$ = ((FBSYMBOL$type*)0);
	};
	goto label$625;
	label$626:;
	{
		fb$result$ = (CLOSEST_PROC$);
	};
	label$625:;
	label$574:;
	#define vr$400 ((FBSYMBOL$type*)(fb$result$))
	return vr$400;
}

FBSYMBOL$type* SYMBFINDBOPOVLPROC( AST_OP OP$, ASTNODE$type* L$, ASTNODE$type* R$, FB_ERRMSG* ERR_NUM$ )
{
	FBSYMBOL$type* fb$result$;
	FB_CALL_ARG$type ARG1$;
	FB_CALL_ARG$type ARG2$;
	FBSYMBOL$type* PROC$;
	#define vr$401 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$401, 0, (integer)4 );
	label$627:;
	#define vr$402 ((FB_ERRMSG*)(ERR_NUM$))
	*(FB_ERRMSG*)((ubyte *)vr$402) = ((FB_ERRMSG)0);
	{
		integer TMP$128$;
		#define vr$403 ((integer*)(L$))
		#define vr$404 ((integer)(*(integer*)((ubyte *)vr$403 + 4) & (integer)511))
		TMP$128$ = (vr$404);
		if (TMP$128$ == (FB_DATATYPE)19) goto label$631;
		label$632:;
		if (TMP$128$ != (FB_DATATYPE)9) goto label$630;
		label$631:;
		{
		};
		goto label$629;
		label$630:;
		{
			{
				integer TMP$129$;
				#define vr$405 ((integer*)(R$))
				#define vr$406 ((integer)(*(integer*)((ubyte *)vr$405 + 4) & (integer)511))
				TMP$129$ = (vr$406);
				if (TMP$129$ == (FB_DATATYPE)19) goto label$636;
				label$637:;
				if (TMP$129$ != (FB_DATATYPE)9) goto label$635;
				label$636:;
				{
				};
				goto label$634;
				label$635:;
				{
					fb$result$ = ((FBSYMBOL$type*)0);
					goto label$628;
				};
				label$638:;
				label$634:;
			};
		};
		label$633:;
		label$629:;
	};
	*(ASTNODE$type**)(&ARG1$) = (L$);
	*(FB_PARAMMODE*)((ubyte *)&ARG1$ + 4) = ((FB_PARAMMODE)-1);
	#define vr$407 ((FB_CALL_ARG$type*)(&ARG2$))
	*(FB_CALL_ARG$type**)((ubyte *)&ARG1$ + 8) = (vr$407);
	*(ASTNODE$type**)(&ARG2$) = (R$);
	*(FB_PARAMMODE*)((ubyte *)&ARG2$ + 4) = ((FB_PARAMMODE)-1);
	*(FB_CALL_ARG$type**)((ubyte *)&ARG2$ + 8) = ((FB_CALL_ARG$type*)0);
	#define vr$408 ((FB_CALL_ARG$type*)(&ARG1$))
	#define vr$409 ((integer)(OP$))
	#define vr$410 ((integer)(vr$409 << (integer)2))
	#define vr$411 ((SYMBCTX*)((SYMBCTX*)((ubyte *)(SYMBCTX*)((ubyte *)&SYMB$ + 1580) + vr$410)))
	FBSYMBOL$type* vr$412 = (FBSYMBOL$type*)(SYMBFINDCLOSESTOVLPROC( *(FBSYMBOL$type**)((ubyte *)vr$411), (integer)2, vr$408, ERR_NUM$, (FB_SYMBLOOKUPOPT)2 ));
	PROC$ = (vr$412);
	if (PROC$ != (integer)0) goto label$640;
	{
		#define vr$413 ((FB_ERRMSG*)(ERR_NUM$))
		if (*(FB_ERRMSG*)((ubyte *)vr$413) == (FB_ERRMSG)0) goto label$642;
		{
			#define vr$414 ((FB_ERRMSG*)(ERR_NUM$))
			ERRREPORT( *(FB_ERRMSG*)((ubyte *)vr$414), (integer)-1, (integer)0 );
		};
		label$642:;
		label$641:;
	};
	label$640:;
	label$639:;
	fb$result$ = (PROC$);
	label$628:;
	#define vr$415 ((FBSYMBOL$type*)(fb$result$))
	return vr$415;
}

FBSYMBOL$type* SYMBFINDSELFBOPOVLPROC( AST_OP OP$, ASTNODE$type* L$, ASTNODE$type* R$, FB_ERRMSG* ERR_NUM$ )
{
	FBSYMBOL$type* fb$result$;
	FB_CALL_ARG$type ARG1$;
	FBSYMBOL$type* PROC$;
	FBSYMBOL$type* HEAD_PROC$;
	#define vr$416 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$416, 0, (integer)4 );
	label$643:;
	#define vr$417 ((FB_ERRMSG*)(ERR_NUM$))
	*(FB_ERRMSG*)((ubyte *)vr$417) = ((FB_ERRMSG)0);
	{
		integer TMP$130$;
		#define vr$418 ((integer*)(L$))
		#define vr$419 ((integer)(*(integer*)((ubyte *)vr$418 + 4) & (integer)511))
		TMP$130$ = (vr$419);
		if (TMP$130$ != (FB_DATATYPE)19) goto label$646;
		label$647:;
		{
			FBSYMBOL$type* SUBTYPE$;
			#define vr$420 ((FBSYMBOL$type**)(L$))
			SUBTYPE$ = (*(FBSYMBOL$type**)((ubyte *)vr$420 + 8));
			#define vr$421 ((FB_STRUCTEXT**)(SUBTYPE$))
			if (*(FB_STRUCTEXT**)((ubyte *)vr$421 + 112) != (integer)0) goto label$649;
			{
				fb$result$ = ((FBSYMBOL$type*)0);
				goto label$644;
			};
			label$649:;
			label$648:;
			#define vr$422 ((FB_STRUCTEXT**)(SUBTYPE$))
			#define vr$423 ((integer)(OP$))
			#define vr$424 ((integer)(vr$423 << (integer)2))
			#define vr$425 ((FB_STRUCTEXT*)((FB_STRUCTEXT*)((ubyte *)*(FB_STRUCTEXT**)((ubyte *)vr$422 + 112) + vr$424)))
			HEAD_PROC$ = (*(FBSYMBOL$type**)((ubyte *)vr$425 + 20));
		};
		goto label$645;
		label$646:;
		{
			fb$result$ = ((FBSYMBOL$type*)0);
			goto label$644;
		};
		label$650:;
		label$645:;
	};
	if (HEAD_PROC$ != (integer)0) goto label$652;
	{
		fb$result$ = ((FBSYMBOL$type*)0);
		goto label$644;
	};
	label$652:;
	label$651:;
	*(ASTNODE$type**)(&ARG1$) = (R$);
	*(FB_PARAMMODE*)((ubyte *)&ARG1$ + 4) = ((FB_PARAMMODE)-1);
	*(FB_CALL_ARG$type**)((ubyte *)&ARG1$ + 8) = ((FB_CALL_ARG$type*)0);
	#define vr$426 ((FB_CALL_ARG$type*)(&ARG1$))
	FBSYMBOL$type* vr$427 = (FBSYMBOL$type*)(SYMBFINDCLOSESTOVLPROC( HEAD_PROC$, (integer)1, vr$426, ERR_NUM$, (FB_SYMBLOOKUPOPT)0 ));
	PROC$ = (vr$427);
	if (PROC$ != (integer)0) goto label$654;
	{
		#define vr$428 ((FB_ERRMSG*)(ERR_NUM$))
		if (*(FB_ERRMSG*)((ubyte *)vr$428) == (FB_ERRMSG)0) goto label$656;
		{
			#define vr$429 ((FB_ERRMSG*)(ERR_NUM$))
			ERRREPORT( *(FB_ERRMSG*)((ubyte *)vr$429), (integer)-1, (integer)0 );
		};
		label$656:;
		label$655:;
	};
	goto label$653;
	label$654:;
	{
		integer vr$430 = (integer)(SYMBCHECKACCESS( PROC$ ));
		if (vr$430 != (integer)0) goto label$658;
		{
			#define vr$431 ((FB_ERRMSG*)(ERR_NUM$))
			*(FB_ERRMSG*)((ubyte *)vr$431) = ((FB_ERRMSG)189);
			char* vr$432 = (char*)(SYMBGETFULLPROCNAME( PROC$ ));
			ERRREPORTEX( (FB_ERRMSG)189, vr$432, (integer)0, (FB_ERRMSGOPT)1, (integer)0 );
			PROC$ = ((FBSYMBOL$type*)0);
		};
		label$658:;
		label$657:;
	};
	label$653:;
	fb$result$ = (PROC$);
	label$644:;
	#define vr$433 ((FBSYMBOL$type*)(fb$result$))
	return vr$433;
}

FBSYMBOL$type* SYMBFINDUOPOVLPROC( AST_OP OP$, ASTNODE$type* L$, FB_ERRMSG* ERR_NUM$ )
{
	FBSYMBOL$type* fb$result$;
	FB_CALL_ARG$type ARG1$;
	FBSYMBOL$type* PROC$;
	#define vr$434 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$434, 0, (integer)4 );
	label$659:;
	#define vr$435 ((FB_ERRMSG*)(ERR_NUM$))
	*(FB_ERRMSG*)((ubyte *)vr$435) = ((FB_ERRMSG)0);
	{
		integer TMP$131$;
		#define vr$436 ((integer*)(L$))
		#define vr$437 ((integer)(*(integer*)((ubyte *)vr$436 + 4) & (integer)511))
		TMP$131$ = (vr$437);
		if (TMP$131$ == (FB_DATATYPE)19) goto label$663;
		label$664:;
		if (TMP$131$ != (FB_DATATYPE)9) goto label$662;
		label$663:;
		{
		};
		goto label$661;
		label$662:;
		{
			fb$result$ = ((FBSYMBOL$type*)0);
			goto label$660;
		};
		label$665:;
		label$661:;
	};
	*(ASTNODE$type**)(&ARG1$) = (L$);
	*(FB_PARAMMODE*)((ubyte *)&ARG1$ + 4) = ((FB_PARAMMODE)-1);
	*(FB_CALL_ARG$type**)((ubyte *)&ARG1$ + 8) = ((FB_CALL_ARG$type*)0);
	#define vr$438 ((FB_CALL_ARG$type*)(&ARG1$))
	#define vr$439 ((integer)(OP$))
	#define vr$440 ((integer)(vr$439 << (integer)2))
	#define vr$441 ((SYMBCTX*)((SYMBCTX*)((ubyte *)(SYMBCTX*)((ubyte *)&SYMB$ + 1580) + vr$440)))
	FBSYMBOL$type* vr$442 = (FBSYMBOL$type*)(SYMBFINDCLOSESTOVLPROC( *(FBSYMBOL$type**)((ubyte *)vr$441), (integer)1, vr$438, ERR_NUM$, (FB_SYMBLOOKUPOPT)0 ));
	PROC$ = (vr$442);
	if (PROC$ != (integer)0) goto label$667;
	{
		#define vr$443 ((FB_ERRMSG*)(ERR_NUM$))
		if (*(FB_ERRMSG*)((ubyte *)vr$443) == (FB_ERRMSG)0) goto label$669;
		{
			#define vr$444 ((FB_ERRMSG*)(ERR_NUM$))
			ERRREPORT( *(FB_ERRMSG*)((ubyte *)vr$444), (integer)-1, (integer)0 );
		};
		label$669:;
		label$668:;
	};
	label$667:;
	label$666:;
	fb$result$ = (PROC$);
	label$660:;
	#define vr$445 ((FBSYMBOL$type*)(fb$result$))
	return vr$445;
}

FBSYMBOL$type* SYMBFINDSELFUOPOVLPROC( AST_OP OP$, ASTNODE$type* L$, FB_ERRMSG* ERR_NUM$ )
{
	FBSYMBOL$type* fb$result$;
	FBSYMBOL$type* PROC$;
	FBSYMBOL$type* HEAD_PROC$;
	#define vr$446 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$446, 0, (integer)4 );
	label$670:;
	#define vr$447 ((FB_ERRMSG*)(ERR_NUM$))
	*(FB_ERRMSG*)((ubyte *)vr$447) = ((FB_ERRMSG)0);
	{
		integer TMP$132$;
		#define vr$448 ((integer*)(L$))
		#define vr$449 ((integer)(*(integer*)((ubyte *)vr$448 + 4) & (integer)511))
		TMP$132$ = (vr$449);
		if (TMP$132$ != (FB_DATATYPE)19) goto label$673;
		label$674:;
		{
			FBSYMBOL$type* SUBTYPE$;
			#define vr$450 ((FBSYMBOL$type**)(L$))
			SUBTYPE$ = (*(FBSYMBOL$type**)((ubyte *)vr$450 + 8));
			#define vr$451 ((FB_STRUCTEXT**)(SUBTYPE$))
			if (*(FB_STRUCTEXT**)((ubyte *)vr$451 + 112) != (integer)0) goto label$676;
			{
				fb$result$ = ((FBSYMBOL$type*)0);
				goto label$671;
			};
			label$676:;
			label$675:;
			#define vr$452 ((FB_STRUCTEXT**)(SUBTYPE$))
			#define vr$453 ((integer)(OP$))
			#define vr$454 ((integer)(vr$453 << (integer)2))
			#define vr$455 ((FB_STRUCTEXT*)((FB_STRUCTEXT*)((ubyte *)*(FB_STRUCTEXT**)((ubyte *)vr$452 + 112) + vr$454)))
			HEAD_PROC$ = (*(FBSYMBOL$type**)((ubyte *)vr$455 + 20));
		};
		goto label$672;
		label$673:;
		{
			fb$result$ = ((FBSYMBOL$type*)0);
			goto label$671;
		};
		label$677:;
		label$672:;
	};
	if (HEAD_PROC$ != (integer)0) goto label$679;
	{
		fb$result$ = ((FBSYMBOL$type*)0);
		goto label$671;
	};
	label$679:;
	label$678:;
	FBSYMBOL$type* vr$456 = (FBSYMBOL$type*)(SYMBFINDCLOSESTOVLPROC( HEAD_PROC$, (integer)0, (integer)0, ERR_NUM$, (FB_SYMBLOOKUPOPT)0 ));
	PROC$ = (vr$456);
	if (PROC$ != (integer)0) goto label$681;
	{
		#define vr$457 ((FB_ERRMSG*)(ERR_NUM$))
		if (*(FB_ERRMSG*)((ubyte *)vr$457) == (FB_ERRMSG)0) goto label$683;
		{
			#define vr$458 ((FB_ERRMSG*)(ERR_NUM$))
			ERRREPORT( *(FB_ERRMSG*)((ubyte *)vr$458), (integer)-1, (integer)0 );
		};
		label$683:;
		label$682:;
	};
	goto label$680;
	label$681:;
	{
		integer vr$459 = (integer)(SYMBCHECKACCESS( PROC$ ));
		if (vr$459 != (integer)0) goto label$685;
		{
			#define vr$460 ((FB_ERRMSG*)(ERR_NUM$))
			*(FB_ERRMSG*)((ubyte *)vr$460) = ((FB_ERRMSG)189);
			char* vr$461 = (char*)(SYMBGETFULLPROCNAME( PROC$ ));
			ERRREPORTEX( (FB_ERRMSG)189, vr$461, (integer)0, (FB_ERRMSGOPT)1, (integer)0 );
			PROC$ = ((FBSYMBOL$type*)0);
		};
		label$685:;
		label$684:;
	};
	label$680:;
	fb$result$ = (PROC$);
	label$671:;
	#define vr$462 ((FBSYMBOL$type*)(fb$result$))
	return vr$462;
}

FBSYMBOL$type* SYMBFINDCASTOVLPROC( integer TO_DTYPE$, FBSYMBOL$type* TO_SUBTYPE$, ASTNODE$type* L$, FB_ERRMSG* ERR_NUM$ )
{
	FBSYMBOL$type* fb$result$;
	FBSYMBOL$type* PROC_HEAD$;
	FBSYMBOL$type* P$;
	FBSYMBOL$type* PROC$;
	FBSYMBOL$type* CLOSEST_PROC$;
	integer MATCHES$;
	integer MAX_MATCHES$;
	integer AMB_CNT$;
	FB_DATATYPE TMP$138$;
	#define vr$463 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$463, 0, (integer)4 );
	label$704:;
	#define vr$464 ((FB_ERRMSG*)(ERR_NUM$))
	*(FB_ERRMSG*)((ubyte *)vr$464) = ((FB_ERRMSG)0);
	{
		integer TMP$137$;
		#define vr$465 ((integer*)(L$))
		#define vr$466 ((integer)(*(integer*)((ubyte *)vr$465 + 4) & (integer)511))
		TMP$137$ = (vr$466);
		if (TMP$137$ != (FB_DATATYPE)19) goto label$707;
		label$708:;
		{
			FBSYMBOL$type* SUBTYPE$;
			#define vr$467 ((FBSYMBOL$type**)(L$))
			SUBTYPE$ = (*(FBSYMBOL$type**)((ubyte *)vr$467 + 8));
			if (SUBTYPE$ != (integer)0) goto label$710;
			{
				fb$result$ = ((FBSYMBOL$type*)0);
				goto label$705;
			};
			label$710:;
			label$709:;
			#define vr$468 ((FB_STRUCTEXT**)(SUBTYPE$))
			if (*(FB_STRUCTEXT**)((ubyte *)vr$468 + 112) != (integer)0) goto label$712;
			{
				fb$result$ = ((FBSYMBOL$type*)0);
				goto label$705;
			};
			label$712:;
			label$711:;
			#define vr$469 ((FB_STRUCTEXT**)(SUBTYPE$))
			#define vr$470 ((FBSYMBOL$type**)(*(FB_STRUCTEXT**)((ubyte *)vr$469 + 112)))
			PROC_HEAD$ = (*(FBSYMBOL$type**)((ubyte *)vr$470 + 124));
		};
		goto label$706;
		label$707:;
		{
			fb$result$ = ((FBSYMBOL$type*)0);
			goto label$705;
		};
		label$713:;
		label$706:;
	};
	if (PROC_HEAD$ != (integer)0) goto label$715;
	{
		fb$result$ = ((FBSYMBOL$type*)0);
		goto label$705;
	};
	label$715:;
	label$714:;
	CLOSEST_PROC$ = ((FBSYMBOL$type*)0);
	MAX_MATCHES$ = ((integer)0);
	AMB_CNT$ = ((integer)0);
	#define vr$471 ((integer)(TO_DTYPE$ & (integer)480))
	if (vr$471 == (integer)0) goto label$716;
	TMP$138$ = ((FB_DATATYPE)23);
	goto label$740;
	label$716:;
	#define vr$472 ((integer)(TO_DTYPE$ & (integer)31))
	#define vr$473 ((FB_DATATYPE)(vr$472))
	TMP$138$ = (vr$473);
	label$740:;
	if (TMP$138$ == (FB_DATATYPE)0) goto label$718;
	{
		PROC$ = (PROC_HEAD$);
		label$719:;
		if (PROC$ == (integer)0) goto label$720;
		{
			integer vr$474 = (integer)(HCHECKCASTOVL( PROC$, TO_DTYPE$, TO_SUBTYPE$ ));
			MATCHES$ = (vr$474);
			if (MATCHES$ <= MAX_MATCHES$) goto label$722;
			{
				CLOSEST_PROC$ = (PROC$);
				MAX_MATCHES$ = (MATCHES$);
				AMB_CNT$ = ((integer)0);
			};
			goto label$721;
			label$722:;
			if (MATCHES$ != MAX_MATCHES$) goto label$723;
			{
				if (MAX_MATCHES$ <= (integer)0) goto label$725;
				{
					#define vr$475 ((integer)(AMB_CNT$ + (integer)1))
					AMB_CNT$ = (vr$475);
				};
				label$725:;
				label$724:;
			};
			label$723:;
			label$721:;
			#define vr$476 ((FBSYMBOL$type**)(PROC$))
			PROC$ = (*(FBSYMBOL$type**)((ubyte *)vr$476 + 96));
		};
		goto label$719;
		label$720:;
	};
	goto label$717;
	label$718:;
	{
		PROC$ = (PROC_HEAD$);
		label$726:;
		if (PROC$ == (integer)0) goto label$727;
		{
			#define vr$477 ((FBSYMBOL$type**)(PROC$))
			if (*(FBSYMBOL$type**)((ubyte *)vr$477 + 28) != (integer)0) goto label$729;
			{
				#define vr$478 ((FB_DATATYPE*)(PROC$))
				#define vr$479 ((FB_DATATYPE)(*(FB_DATATYPE*)((ubyte *)vr$478 + 24) & (integer)511))
				if (vr$479 > (FB_DATATYPE)16) goto label$731;
				{
					#define vr$480 ((FB_DATATYPE*)(PROC$))
					#define vr$481 ((FB_DATATYPE)(*(FB_DATATYPE*)((ubyte *)vr$480 + 24) & (integer)511))
					if (vr$481 <= TO_DTYPE$) goto label$733;
					{
						CLOSEST_PROC$ = (PROC$);
						#define vr$482 ((FB_DATATYPE*)(PROC$))
						#define vr$483 ((FB_DATATYPE)(*(FB_DATATYPE*)((ubyte *)vr$482 + 24) & (integer)511))
						#define vr$484 ((integer)(vr$483))
						TO_DTYPE$ = (vr$484);
					};
					label$733:;
					label$732:;
				};
				label$731:;
				label$730:;
			};
			label$729:;
			label$728:;
			#define vr$485 ((FBSYMBOL$type**)(PROC$))
			PROC$ = (*(FBSYMBOL$type**)((ubyte *)vr$485 + 96));
		};
		goto label$726;
		label$727:;
	};
	label$717:;
	if (AMB_CNT$ <= (integer)0) goto label$735;
	{
		#define vr$486 ((FB_ERRMSG*)(ERR_NUM$))
		*(FB_ERRMSG*)((ubyte *)vr$486) = ((FB_ERRMSG)90);
		ERRREPORTPARAM( PROC_HEAD$, (integer)0, (integer)0, (FB_ERRMSG)90 );
		CLOSEST_PROC$ = ((FBSYMBOL$type*)0);
	};
	goto label$734;
	label$735:;
	{
		if (CLOSEST_PROC$ == (integer)0) goto label$737;
		{
			integer vr$487 = (integer)(SYMBCHECKACCESS( CLOSEST_PROC$ ));
			if (vr$487 != (integer)0) goto label$739;
			{
				#define vr$488 ((FB_ERRMSG*)(ERR_NUM$))
				*(FB_ERRMSG*)((ubyte *)vr$488) = ((FB_ERRMSG)189);
				char* vr$489 = (char*)(SYMBGETFULLPROCNAME( CLOSEST_PROC$ ));
				ERRREPORTEX( (FB_ERRMSG)189, vr$489, (integer)0, (FB_ERRMSGOPT)1, (integer)0 );
				CLOSEST_PROC$ = ((FBSYMBOL$type*)0);
			};
			label$739:;
			label$738:;
		};
		label$737:;
		label$736:;
	};
	label$734:;
	fb$result$ = (CLOSEST_PROC$);
	label$705:;
	#define vr$490 ((FBSYMBOL$type*)(fb$result$))
	return vr$490;
}

FBSYMBOL$type* SYMBFINDCTOROVLPROC( FBSYMBOL$type* SYM$, ASTNODE$type* EXPR$, FB_PARAMMODE ARG_MODE$, FB_ERRMSG* ERR_NUM$ )
{
	FBSYMBOL$type* fb$result$;
	FB_CALL_ARG$type ARG1$;
	#define vr$491 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$491, 0, (integer)4 );
	label$741:;
	*(ASTNODE$type**)(&ARG1$) = (EXPR$);
	*(FB_PARAMMODE*)((ubyte *)&ARG1$ + 4) = (ARG_MODE$);
	*(FB_CALL_ARG$type**)((ubyte *)&ARG1$ + 8) = ((FB_CALL_ARG$type*)0);
	#define vr$492 ((FB_CALL_ARG$type*)(&ARG1$))
	FBSYMBOL$type* vr$493 = (FBSYMBOL$type*)(SYMBGETCOMPCTORHEAD( SYM$ ));
	FBSYMBOL$type* vr$494 = (FBSYMBOL$type*)(SYMBFINDCLOSESTOVLPROC( vr$493, (integer)1, vr$492, ERR_NUM$, (FB_SYMBLOOKUPOPT)0 ));
	fb$result$ = (vr$494);
	label$742:;
	#define vr$495 ((FBSYMBOL$type*)(fb$result$))
	return vr$495;
}

void SYMBDELPROTOTYPE( FBSYMBOL$type* S$ )
{
	label$747:;
	#define vr$496 ((short*)(S$))
	#define vr$497 ((integer)(*(short*)((ubyte *)vr$496 + 56)))
	if (vr$497 <= (integer)0) goto label$750;
	{
		HDELPARAMS( S$ );
	};
	label$750:;
	label$749:;
	SYMBPROCFREEEXT( S$ );
	SYMBFREESYMBOL( S$ );
	label$748:;
}

FB_GLOBCTORLIST_ITEM$type* SYMBADDGLOBALCTOR( FBSYMBOL$type* PROC$ )
{
	FB_GLOBCTORLIST_ITEM$type* fb$result$;
	#define vr$498 ((FB_GLOBCTORLIST_ITEM$type**)(&fb$result$))
	__builtin_memset( vr$498, 0, (integer)4 );
	label$755:;
	#define vr$499 ((FB_SYMBSTATS*)(PROC$))
	#define vr$500 ((FB_SYMBSTATS)(*(FB_SYMBSTATS*)((ubyte *)vr$499 + 8) | (FB_SYMBSTATS)65538))
	#define vr$501 ((FB_SYMBSTATS*)(PROC$))
	*(FB_SYMBSTATS*)((ubyte *)vr$501 + 8) = (vr$500);
	#define vr$502 ((FB_GLOBCTORLIST*)(&*(FB_GLOBCTORLIST*)((ubyte *)&SYMB$ + 1500)))
	FB_GLOBCTORLIST_ITEM$type* vr$503 = (FB_GLOBCTORLIST_ITEM$type*)(HADDTOGLOBCTORLIST( vr$502, PROC$ ));
	fb$result$ = (vr$503);
	label$756:;
	#define vr$504 ((FB_GLOBCTORLIST_ITEM$type*)(fb$result$))
	return vr$504;
}

FB_GLOBCTORLIST_ITEM$type* SYMBADDGLOBALDTOR( FBSYMBOL$type* PROC$ )
{
	FB_GLOBCTORLIST_ITEM$type* fb$result$;
	#define vr$505 ((FB_GLOBCTORLIST_ITEM$type**)(&fb$result$))
	__builtin_memset( vr$505, 0, (integer)4 );
	label$757:;
	#define vr$506 ((FB_SYMBSTATS*)(PROC$))
	#define vr$507 ((FB_SYMBSTATS)(*(FB_SYMBSTATS*)((ubyte *)vr$506 + 8) | (FB_SYMBSTATS)131074))
	#define vr$508 ((FB_SYMBSTATS*)(PROC$))
	*(FB_SYMBSTATS*)((ubyte *)vr$508 + 8) = (vr$507);
	#define vr$509 ((FB_GLOBCTORLIST*)(&*(FB_GLOBCTORLIST*)((ubyte *)&SYMB$ + 1540)))
	FB_GLOBCTORLIST_ITEM$type* vr$510 = (FB_GLOBCTORLIST_ITEM$type*)(HADDTOGLOBCTORLIST( vr$509, PROC$ ));
	fb$result$ = (vr$510);
	label$758:;
	#define vr$511 ((FB_GLOBCTORLIST_ITEM$type*)(fb$result$))
	return vr$511;
}

void SYMBPROCCHECKOVERRIDDEN( FBSYMBOL$type* PROC$, integer IS_IMPLICIT$ )
{
	FBSYMBOL$type* OVERRIDDEN$;
	integer ERRMSG$;
	label$775:;
	FBSYMBOL$type* vr$512 = (FBSYMBOL$type*)(SYMBPROCGETOVERRIDDEN( PROC$ ));
	OVERRIDDEN$ = (vr$512);
	if (OVERRIDDEN$ == (FBSYMBOL$type*)0) goto label$778;
	{
		integer vr$513 = (integer)(HAREMETHODSCOMPATIBLE( OVERRIDDEN$, PROC$ ));
		ERRMSG$ = (vr$513);
		if (ERRMSG$ == (FB_ERRMSG)0) goto label$780;
		{
			#define vr$514 ((integer)((-(ERRMSG$ == (FB_ERRMSG)213))))
			#define vr$515 ((integer)(IS_IMPLICIT$ & vr$514))
			if (vr$515 == (integer)0) goto label$782;
			{
				#define vr$516 ((FB_SYMBATTRIB*)(PROC$))
				#define vr$517 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$516 + 4) & (FB_SYMBATTRIB)8192))
				if (vr$517 == (integer)0) goto label$784;
				{
					ERRMSG$ = ((integer)214);
				};
				goto label$783;
				label$784:;
				{
					ERRMSG$ = ((integer)215);
				};
				label$783:;
			};
			label$782:;
			label$781:;
			ERRREPORT( ERRMSG$, (integer)0, (integer)0 );
		};
		label$780:;
		label$779:;
	};
	label$778:;
	label$777:;
	label$776:;
}

void SYMBPROCSETVTABLEINDEX( FBSYMBOL$type* PROC$, integer I$ )
{
	label$785:;
	SYMBPROCALLOCEXT( PROC$ );
	#define vr$518 ((FB_PROCEXT**)(PROC$))
	#define vr$519 ((integer*)(*(FB_PROCEXT**)((ubyte *)vr$518 + 100)))
	*(integer*)((ubyte *)vr$519 + 68) = (I$);
	label$786:;
}

integer SYMBPROCGETVTABLEINDEX( FBSYMBOL$type* PROC$ )
{
	integer fb$result$;
	#define vr$520 ((integer*)(&fb$result$))
	__builtin_memset( vr$520, 0, (integer)4 );
	label$787:;
	#define vr$521 ((FB_PROCEXT**)(PROC$))
	if (*(FB_PROCEXT**)((ubyte *)vr$521 + 100) == (FB_PROCEXT*)0) goto label$790;
	{
		#define vr$522 ((FB_PROCEXT**)(PROC$))
		#define vr$523 ((integer*)(*(FB_PROCEXT**)((ubyte *)vr$522 + 100)))
		fb$result$ = (*(integer*)((ubyte *)vr$523 + 68));
	};
	label$790:;
	label$789:;
	label$788:;
	#define vr$524 ((integer)(fb$result$))
	return vr$524;
}

FBSYMBOL$type* SYMBPROCGETOVERRIDDEN( FBSYMBOL$type* PROC$ )
{
	FBSYMBOL$type* fb$result$;
	#define vr$525 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$525, 0, (integer)4 );
	label$791:;
	#define vr$526 ((FB_PROCEXT**)(PROC$))
	if (*(FB_PROCEXT**)((ubyte *)vr$526 + 100) == (FB_PROCEXT*)0) goto label$794;
	{
		#define vr$527 ((FB_PROCEXT**)(PROC$))
		#define vr$528 ((FBSYMBOL$type**)(*(FB_PROCEXT**)((ubyte *)vr$527 + 100)))
		fb$result$ = (*(FBSYMBOL$type**)((ubyte *)vr$528 + 72));
	};
	label$794:;
	label$793:;
	label$792:;
	#define vr$529 ((FBSYMBOL$type*)(fb$result$))
	return vr$529;
}

FBSYMBOL$type* SYMBGETPROCRESULT( FBSYMBOL$type* PROC$ )
{
	FBSYMBOL$type* fb$result$;
	#define vr$530 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$530, 0, (integer)4 );
	label$795:;
	#define vr$531 ((FB_PROCEXT**)(PROC$))
	if (*(FB_PROCEXT**)((ubyte *)vr$531 + 100) == (FB_PROCEXT*)0) goto label$798;
	{
		#define vr$532 ((FB_PROCEXT**)(PROC$))
		#define vr$533 ((FBSYMBOL$type**)(*(FB_PROCEXT**)((ubyte *)vr$532 + 100)))
		fb$result$ = (*(FBSYMBOL$type**)((ubyte *)vr$533));
	};
	label$798:;
	label$797:;
	label$796:;
	#define vr$534 ((FBSYMBOL$type*)(fb$result$))
	return vr$534;
}

char* SYMBDEMANGLEFUNCTIONPTR( FBSYMBOL$type* PROC$ )
{
	char* fb$result$;
	static string RES$;
	string TMP$167$;
	#define vr$535 ((char**)(&fb$result$))
	__builtin_memset( vr$535, 0, (integer)4 );
	label$828:;
	#define vr$536 ((FB_DATATYPE*)(PROC$))
	if (*(FB_DATATYPE*)((ubyte *)vr$536 + 24) == (FB_DATATYPE)0) goto label$831;
	{
		fb_StrAssign( (string*)&RES$, (integer)-1, (char*)"function(", (integer)10, (integer)0 );
	};
	goto label$830;
	label$831:;
	{
		fb_StrAssign( (string*)&RES$, (integer)-1, (char*)"sub(", (integer)5, (integer)0 );
	};
	label$830:;
	char* vr$537 = (char*)(HDEMANGLEPARAMS( PROC$ ));
	#define vr$538 ((string*)(&TMP$167$))
	__builtin_memset( vr$538, 0, (integer)12 );
	#define vr$539 ((string*)(&TMP$167$))
	string* vr$540 = (string*)(fb_StrConcat( vr$539, (string*)&RES$, (integer)-1, vr$537, (integer)0 ));
	fb_StrAssign( (string*)&RES$, (integer)-1, vr$540, (integer)-1, (integer)0 );
	fb_StrConcatAssign( (string*)&RES$, (integer)-1, (char*)")", (integer)2, (integer)0 );
	#define vr$541 ((FB_DATATYPE*)(PROC$))
	if (*(FB_DATATYPE*)((ubyte *)vr$541 + 24) == (FB_DATATYPE)0) goto label$833;
	{
		string TMP$168$;
		fb_StrConcatAssign( (string*)&RES$, (integer)-1, (char*)" as ", (integer)5, (integer)0 );
		#define vr$542 ((FBSYMBOL$type**)(PROC$))
		#define vr$543 ((FB_DATATYPE*)(PROC$))
		char* vr$544 = (char*)(SYMBTYPETOSTR( *(FB_DATATYPE*)((ubyte *)vr$543 + 24), *(FBSYMBOL$type**)((ubyte *)vr$542 + 28), (integer)0 ));
		#define vr$545 ((string*)(&TMP$168$))
		__builtin_memset( vr$545, 0, (integer)12 );
		#define vr$546 ((string*)(&TMP$168$))
		string* vr$547 = (string*)(fb_StrConcat( vr$546, (string*)&RES$, (integer)-1, vr$544, (integer)0 ));
		fb_StrAssign( (string*)&RES$, (integer)-1, vr$547, (integer)-1, (integer)0 );
	};
	label$833:;
	label$832:;
	#define vr$548 ((char**)((string*)&RES$))
	fb$result$ = (*(char**)((ubyte *)vr$548));
	label$829:;
	#define vr$549 ((char*)(fb$result$))
	return vr$549;
}

char* SYMBGETFULLPROCNAME( FBSYMBOL$type* PROC$ )
{
	char* fb$result$;
	static string RES$;
	FBSYMBOL$type* NS$;
	#define vr$550 ((char**)(&fb$result$))
	__builtin_memset( vr$550, 0, (integer)4 );
	label$834:;
	fb_StrAssign( (string*)&RES$, (integer)-1, (char*)"", (integer)1, (integer)0 );
	#define vr$551 ((FBHASHTB$type**)(PROC$))
	#define vr$552 ((FBSYMBOL$type**)(*(FBHASHTB$type**)((ubyte *)vr$551 + 116)))
	NS$ = (*(FBSYMBOL$type**)((ubyte *)vr$552));
	label$836:;
	#define vr$553 ((FBSYMBOL$type*)(&*(FBSYMBOL$type*)((ubyte *)&SYMB$ + 816)))
	if (NS$ == vr$553) goto label$837;
	{
		string TMP$169$;
		string TMP$170$;
		#define vr$554 ((char**)(NS$))
		#define vr$555 ((string*)(&TMP$169$))
		__builtin_memset( vr$555, 0, (integer)12 );
		#define vr$556 ((string*)(&TMP$169$))
		string* vr$557 = (string*)(fb_StrConcat( vr$556, *(char**)((ubyte *)vr$554 + 12), (integer)0, (char*)".", (integer)2 ));
		#define vr$558 ((string*)(&TMP$170$))
		__builtin_memset( vr$558, 0, (integer)12 );
		#define vr$559 ((string*)(&TMP$170$))
		string* vr$560 = (string*)(fb_StrConcat( vr$559, vr$557, (integer)-1, (string*)&RES$, (integer)-1 ));
		fb_StrAssign( (string*)&RES$, (integer)-1, vr$560, (integer)-1, (integer)0 );
		#define vr$561 ((FBHASHTB$type**)(NS$))
		#define vr$562 ((FBSYMBOL$type**)(*(FBHASHTB$type**)((ubyte *)vr$561 + 116)))
		NS$ = (*(FBSYMBOL$type**)((ubyte *)vr$562));
	};
	goto label$836;
	label$837:;
	#define vr$563 ((FB_SYMBATTRIB*)(PROC$))
	#define vr$564 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$563 + 4) & (FB_SYMBATTRIB)4096))
	if (vr$564 == (integer)0) goto label$839;
	{
		fb_StrConcatAssign( (string*)&RES$, (integer)-1, (char*)"constructor", (integer)12, (integer)0 );
	};
	goto label$838;
	label$839:;
	#define vr$565 ((FB_SYMBATTRIB*)(PROC$))
	#define vr$566 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$565 + 4) & (FB_SYMBATTRIB)8192))
	if (vr$566 == (integer)0) goto label$840;
	{
		fb_StrConcatAssign( (string*)&RES$, (integer)-1, (char*)"destructor", (integer)11, (integer)0 );
	};
	goto label$838;
	label$840:;
	#define vr$567 ((FB_SYMBATTRIB*)(PROC$))
	#define vr$568 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$567 + 4) & (FB_SYMBATTRIB)16384))
	if (vr$568 == (integer)0) goto label$841;
	{
		fb_StrConcatAssign( (string*)&RES$, (integer)-1, (char*)"operator.", (integer)10, (integer)0 );
		#define vr$569 ((FB_PROCEXT**)(PROC$))
		if (*(FB_PROCEXT**)((ubyte *)vr$569 + 100) == (integer)0) goto label$843;
		{
			string TMP$174$;
			#define vr$570 ((FB_PROCEXT**)(PROC$))
			#define vr$571 ((AST_OP*)(*(FB_PROCEXT**)((ubyte *)vr$570 + 100)))
			#define vr$572 ((integer)(*(AST_OP*)((ubyte *)vr$571 + 40)))
			#define vr$573 ((integer)(vr$572 << (integer)4))
			#define vr$574 ((string*)(&TMP$174$))
			__builtin_memset( vr$574, 0, (integer)12 );
			#define vr$575 ((string*)(&TMP$174$))
			string* vr$576 = (string*)(fb_StrConcat( vr$575, (string*)&RES$, (integer)-1, *(char**)((ubyte *)&AST_OPTB$ + vr$573 + 8), (integer)0 ));
			fb_StrAssign( (string*)&RES$, (integer)-1, vr$576, (integer)-1, (integer)0 );
		};
		label$843:;
		label$842:;
	};
	goto label$838;
	label$841:;
	#define vr$577 ((FB_SYMBATTRIB*)(PROC$))
	#define vr$578 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$577 + 4) & (FB_SYMBATTRIB)32768))
	if (vr$578 == (integer)0) goto label$844;
	{
		string TMP$175$;
		#define vr$579 ((char**)(PROC$))
		#define vr$580 ((string*)(&TMP$175$))
		__builtin_memset( vr$580, 0, (integer)12 );
		#define vr$581 ((string*)(&TMP$175$))
		string* vr$582 = (string*)(fb_StrConcat( vr$581, (string*)&RES$, (integer)-1, *(char**)((ubyte *)vr$579 + 12), (integer)0 ));
		fb_StrAssign( (string*)&RES$, (integer)-1, vr$582, (integer)-1, (integer)0 );
		fb_StrConcatAssign( (string*)&RES$, (integer)-1, (char*)".property.", (integer)11, (integer)0 );
		#define vr$583 ((FB_DATATYPE*)(PROC$))
		#define vr$584 ((FB_DATATYPE)(*(FB_DATATYPE*)((ubyte *)vr$583 + 24) & (integer)511))
		if (vr$584 == (FB_DATATYPE)0) goto label$846;
		{
			fb_StrConcatAssign( (string*)&RES$, (integer)-1, (char*)"get", (integer)4, (integer)0 );
		};
		goto label$845;
		label$846:;
		{
			fb_StrConcatAssign( (string*)&RES$, (integer)-1, (char*)"set", (integer)4, (integer)0 );
		};
		label$845:;
	};
	goto label$838;
	label$844:;
	{
		string TMP$179$;
		#define vr$585 ((char**)(PROC$))
		#define vr$586 ((string*)(&TMP$179$))
		__builtin_memset( vr$586, 0, (integer)12 );
		#define vr$587 ((string*)(&TMP$179$))
		string* vr$588 = (string*)(fb_StrConcat( vr$587, (string*)&RES$, (integer)-1, *(char**)((ubyte *)vr$585 + 12), (integer)0 ));
		fb_StrAssign( (string*)&RES$, (integer)-1, vr$588, (integer)-1, (integer)0 );
	};
	label$838:;
	#define vr$589 ((char**)((string*)&RES$))
	fb$result$ = (*(char**)((ubyte *)vr$589));
	label$835:;
	#define vr$590 ((char*)(fb$result$))
	return vr$590;
}

char* SYMBDEMANGLEMETHOD( FBSYMBOL$type* PROC$ )
{
	char* fb$result$;
	static string RES$;
	string TMP$181$;
	#define vr$591 ((char**)(&fb$result$))
	__builtin_memset( vr$591, 0, (integer)4 );
	label$847:;
	char* vr$592 = (char*)(SYMBGETFULLPROCNAME( PROC$ ));
	fb_StrAssign( (string*)&RES$, (integer)-1, vr$592, (integer)0, (integer)0 );
	fb_StrConcatAssign( (string*)&RES$, (integer)-1, (char*)"(", (integer)2, (integer)0 );
	char* vr$593 = (char*)(HDEMANGLEPARAMS( PROC$ ));
	#define vr$594 ((string*)(&TMP$181$))
	__builtin_memset( vr$594, 0, (integer)12 );
	#define vr$595 ((string*)(&TMP$181$))
	string* vr$596 = (string*)(fb_StrConcat( vr$595, (string*)&RES$, (integer)-1, vr$593, (integer)0 ));
	fb_StrAssign( (string*)&RES$, (integer)-1, vr$596, (integer)-1, (integer)0 );
	fb_StrConcatAssign( (string*)&RES$, (integer)-1, (char*)")", (integer)2, (integer)0 );
	#define vr$597 ((FB_DATATYPE*)(PROC$))
	if (*(FB_DATATYPE*)((ubyte *)vr$597 + 24) == (FB_DATATYPE)0) goto label$850;
	{
		string TMP$182$;
		fb_StrConcatAssign( (string*)&RES$, (integer)-1, (char*)" as ", (integer)5, (integer)0 );
		#define vr$598 ((FBSYMBOL$type**)(PROC$))
		#define vr$599 ((FB_DATATYPE*)(PROC$))
		char* vr$600 = (char*)(SYMBTYPETOSTR( *(FB_DATATYPE*)((ubyte *)vr$599 + 24), *(FBSYMBOL$type**)((ubyte *)vr$598 + 28), (integer)0 ));
		#define vr$601 ((string*)(&TMP$182$))
		__builtin_memset( vr$601, 0, (integer)12 );
		#define vr$602 ((string*)(&TMP$182$))
		string* vr$603 = (string*)(fb_StrConcat( vr$602, (string*)&RES$, (integer)-1, vr$600, (integer)0 ));
		fb_StrAssign( (string*)&RES$, (integer)-1, vr$603, (integer)-1, (integer)0 );
	};
	label$850:;
	label$849:;
	#define vr$604 ((char**)((string*)&RES$))
	fb$result$ = (*(char**)((ubyte *)vr$604));
	label$848:;
	#define vr$605 ((char*)(fb$result$))
	return vr$605;
}

integer SYMBGETDEFAULTCALLCONV( integer DTYPE$, FBSYMBOL$type* SUBTYPE$ )
{
	integer fb$result$;
	#define vr$606 ((integer*)(&fb$result$))
	__builtin_memset( vr$606, 0, (integer)4 );
	label$851:;
	{
		uinteger TMP$183$;
		#define vr$607 ((uinteger)(DTYPE$))
		TMP$183$ = (vr$607);
		goto label$854;
		label$855:;
		{
			fb$result$ = ((integer)2);
			goto label$852;
		};
		goto label$853;
		label$856:;
		{
			fb$result$ = ((integer)1);
			goto label$852;
		};
		goto label$853;
		label$854:;
		if (TMP$183$ < (uinteger)3u) goto label$856;
		if (TMP$183$ > (uinteger)22u) goto label$856;
		static const void * LABEL$857$[] = {
			&&label$855,
			&&label$856,
			&&label$856,
			&&label$855,
			&&label$856,
			&&label$856,
			&&label$856,
			&&label$856,
			&&label$856,
			&&label$856,
			&&label$856,
			&&label$856,
			&&label$856,
			&&label$856,
			&&label$855,
			&&label$855,
			&&label$855,
			&&label$856,
			&&label$856,
			&&label$855,
		(void *)0 };
		#define vr$608 ((uinteger)(TMP$183$ << (uinteger)2u))
		goto **(void**)((ubyte *)LABEL$857$ + vr$608 + -12);
		label$853:;
	};
	label$852:;
	#define vr$609 ((integer)(fb$result$))
	return vr$609;
}

integer SYMBAREPROCMODESEQUAL( FBSYMBOL$type* PROCA$, FBSYMBOL$type* PROCB$ )
{
	integer fb$result$;
	integer A$;
	integer B$;
	#define vr$610 ((integer*)(&fb$result$))
	__builtin_memset( vr$610, 0, (integer)4 );
	label$858:;
	#define vr$611 ((FB_FUNCMODE*)(PROCA$))
	#define vr$612 ((integer)(*(FB_FUNCMODE*)((ubyte *)vr$611 + 72)))
	A$ = (vr$612);
	#define vr$613 ((FB_FUNCMODE*)(PROCB$))
	#define vr$614 ((integer)(*(FB_FUNCMODE*)((ubyte *)vr$613 + 72)))
	B$ = (vr$614);
	{
		integer TMP$186$;
		TMP$186$ = (A$);
		if (TMP$186$ == (FB_FUNCMODE)1) goto label$862;
		label$863:;
		if (TMP$186$ != (FB_FUNCMODE)2) goto label$861;
		label$862:;
		{
			{
				integer TMP$187$;
				TMP$187$ = (B$);
				if (TMP$187$ == (FB_FUNCMODE)1) goto label$866;
				label$867:;
				if (TMP$187$ != (FB_FUNCMODE)2) goto label$865;
				label$866:;
				{
					fb$result$ = ((integer)-1);
					goto label$859;
				};
				label$865:;
				label$864:;
			};
		};
		label$861:;
		label$860:;
	};
	#define vr$615 ((integer)((-(A$ == B$))))
	fb$result$ = (vr$615);
	label$859:;
	#define vr$616 ((integer)(fb$result$))
	return vr$616;
}

FB_CALL_ARG$type* SYMBALLOCOVLCALLARG( TLIST* LIST$, FB_CALL_ARG_LIST* ARG_LIST$, integer TO_HEAD$ )
{
	FB_CALL_ARG$type* fb$result$;
	FB_CALL_ARG$type* ARG$;
	#define vr$617 ((FB_CALL_ARG$type**)(&fb$result$))
	__builtin_memset( vr$617, 0, (integer)4 );
	label$868:;
	void* vr$618 = (void*)(LISTNEWNODE( LIST$ ));
	ARG$ = (vr$618);
	if (TO_HEAD$ != (integer)0) goto label$871;
	{
		#define vr$619 ((FB_CALL_ARG$type**)(ARG_LIST$))
		if (*(FB_CALL_ARG$type**)((ubyte *)vr$619 + 4) != (integer)0) goto label$873;
		{
			#define vr$620 ((FB_CALL_ARG$type**)(ARG_LIST$))
			*(FB_CALL_ARG$type**)((ubyte *)vr$620 + 4) = (ARG$);
		};
		goto label$872;
		label$873:;
		{
			#define vr$621 ((FB_CALL_ARG$type**)(ARG_LIST$))
			#define vr$622 ((FB_CALL_ARG$type**)(*(FB_CALL_ARG$type**)((ubyte *)vr$621 + 8)))
			*(FB_CALL_ARG$type**)((ubyte *)vr$622 + 8) = (ARG$);
		};
		label$872:;
		#define vr$623 ((FB_CALL_ARG$type**)(ARG$))
		*(FB_CALL_ARG$type**)((ubyte *)vr$623 + 8) = ((FB_CALL_ARG$type*)0);
		#define vr$624 ((FB_CALL_ARG$type**)(ARG_LIST$))
		*(FB_CALL_ARG$type**)((ubyte *)vr$624 + 8) = (ARG$);
	};
	goto label$870;
	label$871:;
	{
		#define vr$625 ((FB_CALL_ARG$type**)(ARG_LIST$))
		if (*(FB_CALL_ARG$type**)((ubyte *)vr$625 + 8) != (integer)0) goto label$875;
		{
			#define vr$626 ((FB_CALL_ARG$type**)(ARG_LIST$))
			*(FB_CALL_ARG$type**)((ubyte *)vr$626 + 8) = (ARG$);
		};
		label$875:;
		label$874:;
		#define vr$627 ((FB_CALL_ARG$type**)(ARG_LIST$))
		#define vr$628 ((FB_CALL_ARG$type**)(ARG$))
		*(FB_CALL_ARG$type**)((ubyte *)vr$628 + 8) = (*(FB_CALL_ARG$type**)((ubyte *)vr$627 + 4));
		#define vr$629 ((FB_CALL_ARG$type**)(ARG_LIST$))
		*(FB_CALL_ARG$type**)((ubyte *)vr$629 + 4) = (ARG$);
	};
	label$870:;
	#define vr$630 ((integer*)(ARG_LIST$))
	#define vr$631 ((integer)(*(integer*)((ubyte *)vr$630) + (integer)1))
	#define vr$632 ((integer*)(ARG_LIST$))
	*(integer*)((ubyte *)vr$632) = (vr$631);
	fb$result$ = (ARG$);
	label$869:;
	#define vr$633 ((FB_CALL_ARG$type*)(fb$result$))
	return vr$633;
}

void SYMBFREEOVLCALLARGS( TLIST* LIST$, FB_CALL_ARG_LIST* ARG_LIST$ )
{
	FB_CALL_ARG$type* ARG$;
	FB_CALL_ARG$type* NXT$;
	label$876:;
	#define vr$634 ((FB_CALL_ARG$type**)(&ARG$))
	__builtin_memset( vr$634, 0, (integer)4 );
	#define vr$635 ((FB_CALL_ARG$type**)(&NXT$))
	__builtin_memset( vr$635, 0, (integer)4 );
	#define vr$636 ((FB_CALL_ARG$type**)(ARG_LIST$))
	ARG$ = (*(FB_CALL_ARG$type**)((ubyte *)vr$636 + 4));
	label$878:;
	if (ARG$ == (integer)0) goto label$879;
	{
		#define vr$637 ((FB_CALL_ARG$type**)(ARG$))
		NXT$ = (*(FB_CALL_ARG$type**)((ubyte *)vr$637 + 8));
		LISTDELNODE( LIST$, ARG$ );
		ARG$ = (NXT$);
	};
	goto label$878;
	label$879:;
	label$877:;
}

__attribute__(( constructor )) static void fb_ctor__symbzproc( void )
{
	label$0:;
	label$1:;
}

static void _ZN11TSTRSETITEMaSERS_( TSTRSETITEM* THIS$, TSTRSETITEM* __FB_RHS__$ )
{
	label$4:;
	fb_StrAssign( (TSTRSETITEM*)(THIS$), (integer)-1, (TSTRSETITEM*)(__FB_RHS__$), (integer)-1, (integer)0 );
	#define vr$638 ((integer*)((TSTRSETITEM*)(__FB_RHS__$)))
	#define vr$639 ((integer*)((TSTRSETITEM*)(THIS$)))
	*(integer*)((ubyte *)vr$639 + 12) = (*(integer*)((ubyte *)vr$638 + 12));
	label$5:;
}

static integer HCANOVERLOAD( FBSYMBOL$type* PROC$ )
{
	integer fb$result$;
	FBSYMBOL$type* PPARAM$;
	#define vr$640 ((integer*)(&fb$result$))
	__builtin_memset( vr$640, 0, (integer)4 );
	label$91:;
	#define vr$641 ((short*)(PROC$))
	#define vr$642 ((integer)(*(short*)((ubyte *)vr$641 + 56)))
	if (vr$642 != (integer)0) goto label$94;
	{
		fb$result$ = ((integer)-1);
		goto label$92;
	};
	label$94:;
	label$93:;
	#define vr$643 ((FBSYMBOL$type**)(PROC$))
	PPARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$643 + 68));
	#define vr$644 ((FB_PARAMMODE*)(PPARAM$))
	if (*(FB_PARAMMODE*)((ubyte *)vr$644 + 44) != (FB_PARAMMODE)4) goto label$96;
	{
		fb$result$ = ((integer)0);
		goto label$92;
	};
	label$96:;
	label$95:;
	label$97:;
	if (PPARAM$ == (integer)0) goto label$98;
	{
		#define vr$645 ((FB_DATATYPE*)(PPARAM$))
		if (*(FB_DATATYPE*)((ubyte *)vr$645 + 24) != (FB_DATATYPE)0) goto label$100;
		{
			fb$result$ = ((integer)0);
			goto label$92;
		};
		label$100:;
		label$99:;
		#define vr$646 ((FBSYMBOL$type**)(PPARAM$))
		PPARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$646 + 144));
	};
	goto label$97;
	label$98:;
	fb$result$ = ((integer)-1);
	label$92:;
	#define vr$647 ((integer)(fb$result$))
	return vr$647;
}

static FBSYMBOL$type* HADDOVLPROC( FBSYMBOL$type* PROC$, FBSYMBOL$type* OVL_HEAD_PROC$, FBSYMBOLTB* SYMTB$, FBHASHTB$type* HASHTB$, char* ID$, char* ID_ALIAS$, integer DTYPE$, FBSYMBOL$type* SUBTYPE$, FB_SYMBATTRIB ATTRIB$, integer PRESERVECASE$ )
{
	FBSYMBOL$type* fb$result$;
	FBSYMBOL$type* OVL$;
	FBSYMBOL$type* OVL_PARAM$;
	FBSYMBOL$type* PARAM$;
	integer OVL_PARAMS$;
	integer PARAMS$;
	FB_SYMBOPT TMP$78$;
	#define vr$648 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$648, 0, (integer)4 );
	label$101:;
	fb$result$ = ((FBSYMBOL$type*)0);
	if (OVL_HEAD_PROC$ != (integer)0) goto label$104;
	{
		goto label$102;
	};
	label$104:;
	label$103:;
	#define vr$649 ((FB_SYMBATTRIB)(ATTRIB$ & (FB_SYMBATTRIB)32768))
	if (vr$649 == (integer)0) goto label$106;
	{
		#define vr$650 ((FB_SYMBATTRIB*)(OVL_HEAD_PROC$))
		#define vr$651 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$650 + 4) & (FB_SYMBATTRIB)32768))
		#define vr$652 ((integer)((-(vr$651 != (integer)0))))
		if (vr$652 != (integer)0) goto label$108;
		{
			goto label$102;
		};
		label$108:;
		label$107:;
	};
	goto label$105;
	label$106:;
	#define vr$653 ((FB_SYMBATTRIB*)(OVL_HEAD_PROC$))
	#define vr$654 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$653 + 4) & (FB_SYMBATTRIB)32768))
	if (vr$654 == (integer)0) goto label$109;
	{
		#define vr$655 ((FB_SYMBATTRIB)(ATTRIB$ & (FB_SYMBATTRIB)32768))
		if (vr$655 != (integer)0) goto label$111;
		{
			goto label$102;
		};
		label$111:;
		label$110:;
	};
	label$109:;
	label$105:;
	#define vr$656 ((short*)(PROC$))
	#define vr$657 ((integer)(*(short*)((ubyte *)vr$656 + 56)))
	PARAMS$ = (vr$657);
	#define vr$658 ((FB_SYMBATTRIB)(ATTRIB$ & (FB_SYMBATTRIB)2048))
	if (vr$658 == (integer)0) goto label$113;
	{
		#define vr$659 ((integer)(PARAMS$ + (integer)-1))
		PARAMS$ = (vr$659);
	};
	label$113:;
	label$112:;
	if (PARAMS$ <= (integer)0) goto label$115;
	{
		#define vr$660 ((FBSYMBOL$type**)(PROC$))
		PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$660 + 68));
		#define vr$661 ((FB_PARAMMODE*)(PARAM$))
		if (*(FB_PARAMMODE*)((ubyte *)vr$661 + 44) != (FB_PARAMMODE)4) goto label$117;
		{
			goto label$102;
		};
		label$117:;
		label$116:;
		label$118:;
		if (PARAM$ == (integer)0) goto label$119;
		{
			#define vr$662 ((FB_DATATYPE*)(PARAM$))
			if (*(FB_DATATYPE*)((ubyte *)vr$662 + 24) != (FB_DATATYPE)0) goto label$121;
			{
				goto label$102;
			};
			label$121:;
			label$120:;
			#define vr$663 ((FBSYMBOL$type**)(PARAM$))
			PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$663 + 144));
		};
		goto label$118;
		label$119:;
	};
	label$115:;
	label$114:;
	OVL$ = (OVL_HEAD_PROC$);
	label$122:;
	{
		#define vr$664 ((short*)(OVL$))
		#define vr$665 ((integer)(*(short*)((ubyte *)vr$664 + 56)))
		OVL_PARAMS$ = (vr$665);
		#define vr$666 ((FB_SYMBATTRIB*)(OVL$))
		#define vr$667 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$666 + 4) & (FB_SYMBATTRIB)2048))
		if (vr$667 == (integer)0) goto label$126;
		{
			#define vr$668 ((integer)(OVL_PARAMS$ + (integer)-1))
			OVL_PARAMS$ = (vr$668);
		};
		label$126:;
		label$125:;
		#define vr$669 ((FB_SYMBATTRIB)(ATTRIB$ & (FB_SYMBATTRIB)32768))
		if (vr$669 == (integer)0) goto label$128;
		{
			if (DTYPE$ == (FB_DATATYPE)0) goto label$130;
			{
				#define vr$670 ((FB_DATATYPE*)(OVL$))
				#define vr$671 ((FB_DATATYPE)(*(FB_DATATYPE*)((ubyte *)vr$670 + 24) & (integer)511))
				if (vr$671 != (FB_DATATYPE)0) goto label$132;
				{
					OVL_PARAMS$ = ((integer)-1);
				};
				label$132:;
				label$131:;
			};
			goto label$129;
			label$130:;
			{
				#define vr$672 ((FB_DATATYPE*)(OVL$))
				#define vr$673 ((FB_DATATYPE)(*(FB_DATATYPE*)((ubyte *)vr$672 + 24) & (integer)511))
				if (vr$673 == (FB_DATATYPE)0) goto label$134;
				{
					OVL_PARAMS$ = ((integer)-1);
				};
				label$134:;
				label$133:;
			};
			label$129:;
		};
		label$128:;
		label$127:;
		if (OVL_PARAMS$ != PARAMS$) goto label$136;
		{
			if (PARAMS$ != (integer)0) goto label$138;
			{
				goto label$102;
			};
			label$138:;
			label$137:;
			#define vr$674 ((FBSYMBOL$type**)(PROC$))
			PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$674 + 68));
			#define vr$675 ((FBSYMBOL$type**)(OVL$))
			OVL_PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$675 + 68));
			label$139:;
			{
				integer PDTYPE$;
				integer ODTYPE$;
				#define vr$676 ((FB_PARAMMODE*)(PARAM$))
				#define vr$677 ((FB_PARAMMODE*)(OVL_PARAM$))
				if (*(FB_PARAMMODE*)((ubyte *)vr$676 + 44) == *(FB_PARAMMODE*)((ubyte *)vr$677 + 44)) goto label$143;
				{
					#define vr$678 ((FB_PARAMMODE*)(PARAM$))
					if (*(FB_PARAMMODE*)((ubyte *)vr$678 + 44) != (FB_PARAMMODE)3) goto label$145;
					{
						goto label$140;
					};
					goto label$144;
					label$145:;
					#define vr$679 ((FB_PARAMMODE*)(OVL_PARAM$))
					if (*(FB_PARAMMODE*)((ubyte *)vr$679 + 44) != (FB_PARAMMODE)3) goto label$146;
					{
						goto label$140;
					};
					label$146:;
					label$144:;
				};
				label$143:;
				label$142:;
				#define vr$680 ((FB_DATATYPE*)(PARAM$))
				#define vr$681 ((integer)(*(FB_DATATYPE*)((ubyte *)vr$680 + 24)))
				PDTYPE$ = (vr$681);
				#define vr$682 ((FB_DATATYPE*)(OVL_PARAM$))
				#define vr$683 ((integer)(*(FB_DATATYPE*)((ubyte *)vr$682 + 24)))
				ODTYPE$ = (vr$683);
				#define vr$684 ((integer)(PDTYPE$ & (integer)261632))
				#define vr$685 ((integer)(ODTYPE$ & (integer)261632))
				#define vr$686 ((integer)(vr$684 | vr$685))
				if (vr$686 == (integer)0) goto label$148;
				{
					#define vr$687 ((FB_PARAMMODE*)(PARAM$))
					#define vr$688 ((integer)((-(*(FB_PARAMMODE*)((ubyte *)vr$687 + 44) == (FB_PARAMMODE)2))))
					#define vr$689 ((FB_PARAMMODE*)(OVL_PARAM$))
					#define vr$690 ((integer)((-(*(FB_PARAMMODE*)((ubyte *)vr$689 + 44) == (FB_PARAMMODE)2))))
					#define vr$691 ((integer)(vr$688 & vr$690))
					if (vr$691 == (integer)0) goto label$150;
					{
						#define vr$692 ((integer)(PDTYPE$ & (integer)261632))
						#define vr$693 ((integer)(ODTYPE$ & (integer)261632))
						if (vr$692 == vr$693) goto label$152;
						{
							goto label$140;
						};
						label$152:;
						label$151:;
					};
					label$150:;
					label$149:;
					#define vr$694 ((integer)(PDTYPE$ & (integer)261632))
					#define vr$695 ((integer)(vr$694 & (integer)-513))
					#define vr$696 ((integer)(ODTYPE$ & (integer)261632))
					#define vr$697 ((integer)(vr$696 & (integer)-513))
					if (vr$695 == vr$697) goto label$154;
					{
						goto label$140;
					};
					label$154:;
					label$153:;
					#define vr$698 ((integer)(PDTYPE$ & (integer)511))
					PDTYPE$ = (vr$698);
					#define vr$699 ((integer)(ODTYPE$ & (integer)511))
					ODTYPE$ = (vr$699);
				};
				label$148:;
				label$147:;
				if (PDTYPE$ == ODTYPE$) goto label$156;
				{
					{
						integer TMP$77$;
						TMP$77$ = (PDTYPE$);
						if (TMP$77$ != (FB_DATATYPE)35) goto label$158;
						label$159:;
						{
							if (ODTYPE$ == (FB_DATATYPE)17) goto label$161;
							{
								goto label$140;
							};
							label$161:;
							label$160:;
						};
						goto label$157;
						label$158:;
						if (TMP$77$ != (FB_DATATYPE)17) goto label$162;
						label$163:;
						{
							if (ODTYPE$ == (FB_DATATYPE)35) goto label$165;
							{
								goto label$140;
							};
							label$165:;
							label$164:;
						};
						goto label$157;
						label$162:;
						{
							goto label$140;
						};
						label$166:;
						label$157:;
					};
				};
				label$156:;
				label$155:;
				#define vr$700 ((FBSYMBOL$type**)(PARAM$))
				#define vr$701 ((FBSYMBOL$type**)(OVL_PARAM$))
				if (*(FBSYMBOL$type**)((ubyte *)vr$700 + 28) == *(FBSYMBOL$type**)((ubyte *)vr$701 + 28)) goto label$168;
				{
					goto label$140;
				};
				label$168:;
				label$167:;
				#define vr$702 ((FBSYMBOL$type**)(PARAM$))
				PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$702 + 144));
				#define vr$703 ((FBSYMBOL$type**)(OVL_PARAM$))
				OVL_PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$703 + 144));
				#define vr$704 ((integer)(OVL_PARAMS$ + (integer)-1))
				OVL_PARAMS$ = (vr$704);
			};
			label$141:;
			if (OVL_PARAMS$ > (integer)0) goto label$139;
			label$140:;
			if (OVL_PARAMS$ != (integer)0) goto label$170;
			{
				goto label$102;
			};
			label$170:;
			label$169:;
		};
		label$136:;
		label$135:;
		#define vr$705 ((FBSYMBOL$type**)(OVL$))
		OVL$ = (*(FBSYMBOL$type**)((ubyte *)vr$705 + 96));
	};
	label$124:;
	if (OVL$ != (integer)0) goto label$122;
	label$123:;
	if (PRESERVECASE$ == (integer)0) goto label$171;
	TMP$78$ = ((FB_SYMBOPT)1);
	goto label$880;
	label$171:;
	TMP$78$ = ((FB_SYMBOPT)0);
	label$880:;
	FBSYMBOL$type* vr$706 = (FBSYMBOL$type*)(SYMBNEWSYMBOL( TMP$78$, PROC$, SYMTB$, HASHTB$, (FB_SYMBCLASS)3, ID$, ID_ALIAS$, DTYPE$, SUBTYPE$, ATTRIB$ ));
	PROC$ = (vr$706);
	if (PROC$ != (integer)0) goto label$173;
	{
		goto label$102;
	};
	label$173:;
	label$172:;
	if (ID$ == (integer)0) goto label$175;
	{
		FBSYMBOL$type* NXT$;
		#define vr$707 ((uinteger*)(OVL_HEAD_PROC$))
		#define vr$708 ((uinteger*)(PROC$))
		*(uinteger*)((ubyte *)vr$708 + 124) = (*(uinteger*)((ubyte *)vr$707 + 124));
		#define vr$709 ((HASHITEM$type**)(OVL_HEAD_PROC$))
		#define vr$710 ((HASHITEM$type**)(PROC$))
		*(HASHITEM$type**)((ubyte *)vr$710 + 120) = (*(HASHITEM$type**)((ubyte *)vr$709 + 120));
		#define vr$711 ((FBSYMBOL$type**)(OVL_HEAD_PROC$))
		NXT$ = (*(FBSYMBOL$type**)((ubyte *)vr$711 + 132));
		#define vr$712 ((FBSYMBOL$type**)(OVL_HEAD_PROC$))
		*(FBSYMBOL$type**)((ubyte *)vr$712 + 132) = (PROC$);
		#define vr$713 ((FBSYMBOL$type**)(PROC$))
		*(FBSYMBOL$type**)((ubyte *)vr$713 + 128) = (OVL_HEAD_PROC$);
		#define vr$714 ((FBSYMBOL$type**)(PROC$))
		*(FBSYMBOL$type**)((ubyte *)vr$714 + 132) = (NXT$);
		if (NXT$ == (integer)0) goto label$177;
		{
			#define vr$715 ((FBSYMBOL$type**)(NXT$))
			*(FBSYMBOL$type**)((ubyte *)vr$715 + 128) = (PROC$);
		};
		label$177:;
		label$176:;
	};
	label$175:;
	label$174:;
	fb$result$ = (PROC$);
	label$102:;
	#define vr$716 ((FBSYMBOL$type*)(fb$result$))
	return vr$716;
}

static FBSYMBOL$type* HADDOPOVLPROC( FBSYMBOL$type* PROC$, FBSYMBOL$type* OVL_HEAD_PROC$, FBSYMBOLTB* SYMTB$, FBHASHTB$type* HASHTB$, AST_OP OP$, char* ID_ALIAS$, integer DTYPE$, FBSYMBOL$type* SUBTYPE$, FB_SYMBATTRIB ATTRIB$ )
{
	FBSYMBOL$type* fb$result$;
	FBSYMBOL$type* OVL$;
	#define vr$717 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$717, 0, (integer)4 );
	label$178:;
	if (OP$ == (AST_OP)26) goto label$181;
	{
		FBSYMBOL$type* vr$718 = (FBSYMBOL$type*)(HADDOVLPROC( PROC$, OVL_HEAD_PROC$, SYMTB$, HASHTB$, (integer)0, ID_ALIAS$, DTYPE$, SUBTYPE$, ATTRIB$, (integer)0 ));
		fb$result$ = (vr$718);
		goto label$179;
	};
	label$181:;
	label$180:;
	OVL$ = (OVL_HEAD_PROC$);
	label$182:;
	if (OVL$ == (integer)0) goto label$183;
	{
		#define vr$719 ((FB_DATATYPE*)(PROC$))
		#define vr$720 ((FB_DATATYPE*)(OVL$))
		if (*(FB_DATATYPE*)((ubyte *)vr$719 + 24) != *(FB_DATATYPE*)((ubyte *)vr$720 + 24)) goto label$185;
		{
			#define vr$721 ((FBSYMBOL$type**)(PROC$))
			#define vr$722 ((FBSYMBOL$type**)(OVL$))
			if (*(FBSYMBOL$type**)((ubyte *)vr$721 + 28) != *(FBSYMBOL$type**)((ubyte *)vr$722 + 28)) goto label$187;
			{
				fb$result$ = ((FBSYMBOL$type*)0);
				goto label$179;
			};
			label$187:;
			label$186:;
		};
		label$185:;
		label$184:;
		#define vr$723 ((FBSYMBOL$type**)(OVL$))
		OVL$ = (*(FBSYMBOL$type**)((ubyte *)vr$723 + 96));
	};
	goto label$182;
	label$183:;
	FBSYMBOL$type* vr$724 = (FBSYMBOL$type*)(SYMBNEWSYMBOL( (FB_SYMBOPT)0, PROC$, SYMTB$, HASHTB$, (FB_SYMBCLASS)3, (integer)0, ID_ALIAS$, DTYPE$, SUBTYPE$, ATTRIB$ ));
	PROC$ = (vr$724);
	fb$result$ = (PROC$);
	label$179:;
	#define vr$725 ((FBSYMBOL$type*)(fb$result$))
	return vr$725;
}

static FBSYMBOL$type* HSETUPPROC( FBSYMBOL$type* SYM$, FBSYMBOL$type* PARENT$, FBSYMBOLTB* SYMTB$, FBHASHTB$type* HASHTB$, char* ID$, char* ID_ALIAS$, integer DTYPE$, FBSYMBOL$type* SUBTYPE$, integer ATTRIB$, integer MODE$, FB_SYMBOPT OPTIONS$ )
{
	FBSYMBOL$type* fb$result$;
	integer STATS$;
	integer PRESERVE_CASE$;
	integer LOOKUPOPTIONS$;
	FBSYMBOL$type* PROC$;
	FBSYMBOL$type* HEAD_PROC$;
	FBSYMBOL$type* OVERRIDDEN$;
	#define vr$726 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$726, 0, (integer)4 );
	label$188:;
	fb$result$ = ((FBSYMBOL$type*)0);
	if (DTYPE$ != (integer)-2147483648u) goto label$191;
	{
		integer vr$727 = (integer)(SYMBGETDEFTYPE( ID$ ));
		DTYPE$ = (vr$727);
		SUBTYPE$ = ((FBSYMBOL$type*)0);
	};
	label$191:;
	label$190:;
	if (ID_ALIAS$ != (integer)0) goto label$193;
	{
		if (*(FB_MANGLING*)((ubyte *)&PARSER$ + 100) == (FB_MANGLING)0) goto label$195;
		{
			ID_ALIAS$ = (ID$);
		};
		label$195:;
		label$194:;
		STATS$ = ((integer)0);
	};
	goto label$192;
	label$193:;
	{
		STATS$ = ((integer)512);
	};
	label$192:;
	HEAD_PROC$ = ((FBSYMBOL$type*)0);
	#define vr$728 ((FB_SYMBATTRIB)(ATTRIB$ & (FB_SYMBATTRIB)12288))
	if (vr$728 == (integer)0) goto label$197;
	{
		#define vr$729 ((FB_SYMBATTRIB)(ATTRIB$ & (FB_SYMBATTRIB)4096))
		if (vr$729 == (integer)0) goto label$199;
		{
			FBSYMBOL$type* vr$730 = (FBSYMBOL$type*)(SYMBGETCOMPCTORHEAD( PARENT$ ));
			HEAD_PROC$ = (vr$730);
		};
		goto label$198;
		label$199:;
		{
			FBSYMBOL$type* vr$731 = (FBSYMBOL$type*)(SYMBGETCOMPDTOR( PARENT$ ));
			HEAD_PROC$ = (vr$731);
		};
		label$198:;
		if (HEAD_PROC$ != (integer)0) goto label$201;
		{
			FBSYMBOL$type* vr$732 = (FBSYMBOL$type*)(SYMBNEWSYMBOL( (FB_SYMBOPT)0, SYM$, SYMTB$, HASHTB$, (FB_SYMBCLASS)3, (integer)0, ID_ALIAS$, (FB_DATATYPE)0, (integer)0, ATTRIB$ ));
			PROC$ = (vr$732);
			#define vr$733 ((FB_SYMBATTRIB)(ATTRIB$ & (FB_SYMBATTRIB)4096))
			if (vr$733 == (integer)0) goto label$203;
			{
				SYMBSETCOMPCTORHEAD( PARENT$, PROC$ );
			};
			goto label$202;
			label$203:;
			{
				SYMBSETCOMPDTOR( PARENT$, PROC$ );
			};
			label$202:;
		};
		goto label$200;
		label$201:;
		{
			#define vr$734 ((FB_SYMBATTRIB)(ATTRIB$ & (FB_SYMBATTRIB)8192))
			if (vr$734 == (integer)0) goto label$205;
			{
				fb$result$ = ((FBSYMBOL$type*)0);
				goto label$189;
			};
			label$205:;
			label$204:;
			FBSYMBOL$type* vr$735 = (FBSYMBOL$type*)(HADDOVLPROC( SYM$, HEAD_PROC$, SYMTB$, HASHTB$, (integer)0, ID_ALIAS$, (FB_DATATYPE)0, (integer)0, ATTRIB$, (integer)0 ));
			PROC$ = (vr$735);
			if (PROC$ != (integer)0) goto label$207;
			{
				goto label$189;
			};
			label$207:;
			label$206:;
		};
		label$200:;
		#define vr$736 ((FB_SYMBATTRIB)(ATTRIB$ & (FB_SYMBATTRIB)4096))
		if (vr$736 == (integer)0) goto label$209;
		{
			SYMBCHECKCOMPCTOR( PARENT$, PROC$ );
		};
		label$209:;
		label$208:;
	};
	goto label$196;
	label$197:;
	#define vr$737 ((FB_SYMBATTRIB)(ATTRIB$ & (FB_SYMBATTRIB)16384))
	if (vr$737 == (integer)0) goto label$210;
	{
		AST_OP OP$;
		#define vr$738 ((FB_PROCEXT**)(SYM$))
		if (*(FB_PROCEXT**)((ubyte *)vr$738 + 100) != (integer)0) goto label$212;
		{
			goto label$213;
		};
		label$212:;
		label$211:;
		#define vr$739 ((AST_OP*)(&OP$))
		__builtin_memset( vr$739, 0, (integer)4 );
		#define vr$740 ((FB_PROCEXT**)(SYM$))
		#define vr$741 ((AST_OP*)(*(FB_PROCEXT**)((ubyte *)vr$740 + 100)))
		OP$ = (*(AST_OP*)((ubyte *)vr$741 + 40));
		FBSYMBOL$type* vr$742 = (FBSYMBOL$type*)(SYMBGETCOMPOPOVLHEAD( PARENT$, OP$ ));
		HEAD_PROC$ = (vr$742);
		if (HEAD_PROC$ != (integer)0) goto label$215;
		{
			FBSYMBOL$type* vr$743 = (FBSYMBOL$type*)(SYMBNEWSYMBOL( (FB_SYMBOPT)0, SYM$, SYMTB$, HASHTB$, (FB_SYMBCLASS)3, (integer)0, ID_ALIAS$, DTYPE$, SUBTYPE$, ATTRIB$ ));
			PROC$ = (vr$743);
			SYMBSETCOMPOPOVLHEAD( PARENT$, PROC$ );
		};
		goto label$214;
		label$215:;
		{
			FBSYMBOL$type* vr$744 = (FBSYMBOL$type*)(HADDOPOVLPROC( SYM$, HEAD_PROC$, SYMTB$, HASHTB$, OP$, ID_ALIAS$, DTYPE$, SUBTYPE$, ATTRIB$ ));
			PROC$ = (vr$744);
			if (PROC$ != (integer)0) goto label$217;
			{
				goto label$189;
			};
			label$217:;
			label$216:;
			if (OP$ != (AST_OP)0) goto label$219;
			{
				SYMBCHECKCOMPCLONE( PARENT$, PROC$ );
			};
			label$219:;
			label$218:;
		};
		label$214:;
	};
	goto label$196;
	label$210:;
	{
		label$213:;
		#define vr$745 ((FB_SYMBOPT)(OPTIONS$ & (FB_SYMBOPT)1))
		#define vr$746 ((integer)((-(vr$745 != (integer)0))))
		PRESERVE_CASE$ = (vr$746);
		#define vr$747 ((FB_SYMBOPT)(OPTIONS$ | (FB_SYMBOPT)32))
		FBSYMBOL$type* vr$748 = (FBSYMBOL$type*)(SYMBNEWSYMBOL( vr$747, SYM$, SYMTB$, HASHTB$, (FB_SYMBCLASS)3, ID$, ID_ALIAS$, DTYPE$, SUBTYPE$, ATTRIB$ ));
		PROC$ = (vr$748);
		if (PROC$ != (integer)0) goto label$221;
		{
			FBSYMBOL$type* vr$749 = (FBSYMBOL$type*)(SYMBLOOKUPBYNAMEANDCLASS( PARENT$, ID$, (FB_SYMBCLASS)3, PRESERVE_CASE$, (integer)0 ));
			HEAD_PROC$ = (vr$749);
			if (HEAD_PROC$ != (integer)0) goto label$223;
			{
				goto label$189;
			};
			label$223:;
			label$222:;
			#define vr$750 ((FB_SYMBATTRIB*)(HEAD_PROC$))
			#define vr$751 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$750 + 4) & (FB_SYMBATTRIB)1024))
			#define vr$752 ((integer)((-(vr$751 != (integer)0))))
			if (vr$752 != (integer)0) goto label$225;
			{
				#define vr$753 ((FB_LANG_OPT)(*(FB_LANG_OPT*)((ubyte *)&ENV$ + 828) & (FB_LANG_OPT)1024))
				#define vr$754 ((integer)((-(vr$753 != (integer)0))))
				if (vr$754 != (integer)0) goto label$227;
				{
					goto label$189;
				};
				label$227:;
				label$226:;
			};
			label$225:;
			label$224:;
			FBSYMBOL$type* vr$755 = (FBSYMBOL$type*)(HADDOVLPROC( SYM$, HEAD_PROC$, SYMTB$, HASHTB$, ID$, ID_ALIAS$, DTYPE$, SUBTYPE$, ATTRIB$, PRESERVE_CASE$ ));
			PROC$ = (vr$755);
			if (PROC$ != (integer)0) goto label$229;
			{
				goto label$189;
			};
			label$229:;
			label$228:;
			#define vr$756 ((FB_SYMBATTRIB*)(PROC$))
			#define vr$757 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$756 + 4) | (FB_SYMBATTRIB)1024))
			#define vr$758 ((FB_SYMBATTRIB*)(PROC$))
			*(FB_SYMBATTRIB*)((ubyte *)vr$758 + 4) = (vr$757);
		};
		goto label$220;
		label$221:;
		{
			#define vr$759 ((FB_SYMBOPT)(OPTIONS$ & (FB_SYMBOPT)16))
			if (vr$759 != (integer)0) goto label$231;
			{
				#define vr$760 ((FB_SYMBATTRIB)(ATTRIB$ & (FB_SYMBATTRIB)1024))
				if (vr$760 == (integer)0) goto label$233;
				{
					integer vr$761 = (integer)(HCANOVERLOAD( SYM$ ));
					if (vr$761 != (integer)0) goto label$235;
					{
						goto label$189;
					};
					label$235:;
					label$234:;
				};
				goto label$232;
				label$233:;
				#define vr$762 ((FB_LANG_OPT)(*(FB_LANG_OPT*)((ubyte *)&ENV$ + 828) & (FB_LANG_OPT)1024))
				if (vr$762 == (integer)0) goto label$236;
				{
					integer vr$763 = (integer)(HCANOVERLOAD( SYM$ ));
					if (vr$763 == (integer)0) goto label$238;
					{
						#define vr$764 ((FB_SYMBATTRIB*)(PROC$))
						#define vr$765 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$764 + 4) | (FB_SYMBATTRIB)1024))
						#define vr$766 ((FB_SYMBATTRIB*)(PROC$))
						*(FB_SYMBATTRIB*)((ubyte *)vr$766 + 4) = (vr$765);
					};
					label$238:;
					label$237:;
				};
				label$236:;
				label$232:;
			};
			label$231:;
			label$230:;
		};
		label$220:;
	};
	label$196:;
	#define vr$767 ((FB_SYMBOPT)(OPTIONS$ & (FB_SYMBOPT)16))
	if (vr$767 == (integer)0) goto label$240;
	{
		#define vr$768 ((FB_SYMBSTATS)(STATS$ | (FB_SYMBSTATS)32))
		#define vr$769 ((integer)(vr$768))
		STATS$ = (vr$769);
	};
	label$240:;
	label$239:;
	#define vr$770 ((FB_FUNCMODE)(MODE$))
	#define vr$771 ((FB_FUNCMODE*)(PROC$))
	*(FB_FUNCMODE*)((ubyte *)vr$771 + 72) = (vr$770);
	if (*(FB_TOKEN*)((ubyte *)&PARSER$ + 24) != (FB_TOKEN)306) goto label$242;
	{
		if (*(FB_MANGLING*)((ubyte *)&PARSER$ + 100) == (FB_MANGLING)4) goto label$244;
		{
			#define vr$772 ((FB_SYMBSTATS)(STATS$ | (FB_SYMBSTATS)2048))
			#define vr$773 ((integer)(vr$772))
			STATS$ = (vr$773);
		};
		label$244:;
		label$243:;
	};
	label$242:;
	label$241:;
	SYMBPROCRECALCREALTYPE( PROC$ );
	#define vr$774 ((FB_SYMBOPT)(OPTIONS$ & (FB_SYMBOPT)4))
	if (vr$774 == (integer)0) goto label$246;
	{
		#define vr$775 ((FB_SYMBSTATS)(STATS$ | (FB_SYMBSTATS)8))
		#define vr$776 ((integer)(vr$775))
		STATS$ = (vr$776);
	};
	label$246:;
	label$245:;
	#define vr$777 ((tmp$22*)(PROC$))
	*(tmp$22*)((ubyte *)vr$777 + 88) = ((tmp$22)0);
	#define vr$778 ((FB_SYMBATTRIB*)(PROC$))
	#define vr$779 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$778 + 4) & (FB_SYMBATTRIB)1024))
	if (vr$779 == (integer)0) goto label$248;
	{
		integer PARAMS$;
		#define vr$780 ((short*)(PROC$))
		#define vr$781 ((integer)(*(short*)((ubyte *)vr$780 + 56)))
		PARAMS$ = (vr$781);
		#define vr$782 ((FB_SYMBATTRIB*)(PROC$))
		#define vr$783 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$782 + 4) & (FB_SYMBATTRIB)2048))
		if (vr$783 == (integer)0) goto label$250;
		{
			#define vr$784 ((integer)(PARAMS$ + (integer)-1))
			PARAMS$ = (vr$784);
		};
		label$250:;
		label$249:;
		if (HEAD_PROC$ == (integer)0) goto label$252;
		{
			#define vr$785 ((FBSYMBOL$type**)(HEAD_PROC$))
			#define vr$786 ((FBSYMBOL$type**)(PROC$))
			*(FBSYMBOL$type**)((ubyte *)vr$786 + 96) = (*(FBSYMBOL$type**)((ubyte *)vr$785 + 96));
			#define vr$787 ((FBSYMBOL$type**)(HEAD_PROC$))
			*(FBSYMBOL$type**)((ubyte *)vr$787 + 96) = (PROC$);
			#define vr$788 ((short*)(HEAD_PROC$))
			#define vr$789 ((integer)(*(short*)((ubyte *)vr$788 + 92)))
			if (PARAMS$ >= vr$789) goto label$254;
			{
				#define vr$790 ((short)(PARAMS$))
				#define vr$791 ((short*)(HEAD_PROC$))
				*(short*)((ubyte *)vr$791 + 92) = (vr$790);
			};
			label$254:;
			label$253:;
			#define vr$792 ((short*)(HEAD_PROC$))
			#define vr$793 ((integer)(*(short*)((ubyte *)vr$792 + 94)))
			if (PARAMS$ <= vr$793) goto label$256;
			{
				#define vr$794 ((short)(PARAMS$))
				#define vr$795 ((short*)(HEAD_PROC$))
				*(short*)((ubyte *)vr$795 + 94) = (vr$794);
			};
			label$256:;
			label$255:;
		};
		goto label$251;
		label$252:;
		{
			#define vr$796 ((FBSYMBOL$type**)(PROC$))
			*(FBSYMBOL$type**)((ubyte *)vr$796 + 96) = ((FBSYMBOL$type*)0);
			#define vr$797 ((short)(PARAMS$))
			#define vr$798 ((short*)(PROC$))
			*(short*)((ubyte *)vr$798 + 92) = (vr$797);
			#define vr$799 ((short)(PARAMS$))
			#define vr$800 ((short*)(PROC$))
			*(short*)((ubyte *)vr$800 + 94) = (vr$799);
		};
		label$251:;
	};
	label$248:;
	label$247:;
	#define vr$801 ((FB_SYMBSTATS*)(PROC$))
	#define vr$802 ((FB_SYMBSTATS)(*(FB_SYMBSTATS*)((ubyte *)vr$801 + 8) | STATS$))
	#define vr$803 ((FB_SYMBSTATS*)(PROC$))
	*(FB_SYMBSTATS*)((ubyte *)vr$803 + 8) = (vr$802);
	#define vr$804 ((FB_SYMBATTRIB*)(PROC$))
	#define vr$805 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$804 + 4) & (FB_SYMBATTRIB)2048))
	if (vr$805 == (integer)0) goto label$258;
	{
		#define vr$806 ((FB_SYMBATTRIB*)(PROC$))
		#define vr$807 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$806 + 4) & (FB_SYMBATTRIB)1073741824))
		if (vr$807 == (integer)0) goto label$260;
		{
			#define vr$808 ((FB_STRUCTEXT**)(PARENT$))
			#define vr$809 ((integer*)(*(FB_STRUCTEXT**)((ubyte *)vr$808 + 112)))
			#define vr$810 ((integer)(*(integer*)((ubyte *)vr$809 + 140) + (integer)1))
			#define vr$811 ((FB_STRUCTEXT**)(PARENT$))
			#define vr$812 ((integer*)(*(FB_STRUCTEXT**)((ubyte *)vr$811 + 112)))
			*(integer*)((ubyte *)vr$812 + 140) = (vr$810);
		};
		label$260:;
		label$259:;
		OVERRIDDEN$ = ((FBSYMBOL$type*)0);
		#define vr$813 ((FBSYMBOL$type**)(PARENT$))
		if (*(FBSYMBOL$type**)((ubyte *)vr$813 + 84) == (FBSYMBOL$type*)0) goto label$262;
		{
			#define vr$814 ((FB_SYMBATTRIB*)(PROC$))
			#define vr$815 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$814 + 4) & (FB_SYMBATTRIB)8192))
			if (vr$815 == (integer)0) goto label$264;
			{
				#define vr$816 ((FBSYMBOL$type**)(PARENT$))
				#define vr$817 ((FBSYMBOL$type**)(*(FBSYMBOL$type**)((ubyte *)vr$816 + 84)))
				FBSYMBOL$type* vr$818 = (FBSYMBOL$type*)(SYMBGETCOMPDTOR( *(FBSYMBOL$type**)((ubyte *)vr$817 + 28) ));
				OVERRIDDEN$ = (vr$818);
			};
			goto label$263;
			label$264:;
			#define vr$819 ((FB_SYMBATTRIB*)(PROC$))
			#define vr$820 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$819 + 4) & (FB_SYMBATTRIB)16384))
			if (vr$820 == (integer)0) goto label$265;
			{
				#define vr$821 ((FB_PROCEXT**)(PROC$))
				#define vr$822 ((AST_OP*)(*(FB_PROCEXT**)((ubyte *)vr$821 + 100)))
				#define vr$823 ((FBSYMBOL$type**)(PARENT$))
				#define vr$824 ((FBSYMBOL$type**)(*(FBSYMBOL$type**)((ubyte *)vr$823 + 84)))
				FBSYMBOL$type* vr$825 = (FBSYMBOL$type*)(SYMBGETCOMPOPOVLHEAD( *(FBSYMBOL$type**)((ubyte *)vr$824 + 28), *(AST_OP*)((ubyte *)vr$822 + 40) ));
				OVERRIDDEN$ = (vr$825);
				#define vr$826 ((FB_PROCEXT**)(PROC$))
				#define vr$827 ((AST_OP*)(*(FB_PROCEXT**)((ubyte *)vr$826 + 100)))
				FBSYMBOL$type* vr$828 = (FBSYMBOL$type*)(SYMBFINDOPOVLPROC( *(AST_OP*)((ubyte *)vr$827 + 40), OVERRIDDEN$, PROC$ ));
				OVERRIDDEN$ = (vr$828);
			};
			goto label$263;
			label$265:;
			if (ID$ == (char*)0) goto label$266;
			{
				#define vr$829 ((FB_SYMBOPT)(OPTIONS$ & (FB_SYMBOPT)1))
				#define vr$830 ((integer)((-(vr$829 != (integer)0))))
				#define vr$831 ((FBSYMBOL$type**)(PARENT$))
				#define vr$832 ((FBSYMBOL$type**)(*(FBSYMBOL$type**)((ubyte *)vr$831 + 84)))
				FBSYMBOL$type* vr$833 = (FBSYMBOL$type*)(SYMBLOOKUPBYNAMEANDCLASS( *(FBSYMBOL$type**)((ubyte *)vr$832 + 28), ID$, (FB_SYMBCLASS)3, vr$830, (integer)-1 ));
				OVERRIDDEN$ = (vr$833);
				LOOKUPOPTIONS$ = ((integer)0);
				#define vr$834 ((FB_SYMBATTRIB*)(PROC$))
				#define vr$835 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$834 + 4) & (FB_SYMBATTRIB)32768))
				if (vr$835 == (integer)0) goto label$268;
				{
					#define vr$836 ((FB_DATATYPE*)(PROC$))
					#define vr$837 ((FB_DATATYPE)(*(FB_DATATYPE*)((ubyte *)vr$836 + 24) & (integer)511))
					if (vr$837 == (FB_DATATYPE)0) goto label$270;
					{
						LOOKUPOPTIONS$ = ((integer)1);
					};
					label$270:;
					label$269:;
				};
				label$268:;
				label$267:;
				FBSYMBOL$type* vr$838 = (FBSYMBOL$type*)(SYMBFINDOVERLOADPROC( OVERRIDDEN$, PROC$, LOOKUPOPTIONS$ ));
				OVERRIDDEN$ = (vr$838);
			};
			label$266:;
			label$263:;
			if (OVERRIDDEN$ == (FBSYMBOL$type*)0) goto label$272;
			{
				#define vr$839 ((FB_SYMBATTRIB*)(OVERRIDDEN$))
				#define vr$840 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$839 + 4) & (FB_SYMBATTRIB)536870912))
				#define vr$841 ((integer)((-(vr$840 != (integer)0))))
				if (vr$841 != (integer)0) goto label$274;
				{
					OVERRIDDEN$ = ((FBSYMBOL$type*)0);
				};
				label$274:;
				label$273:;
			};
			label$272:;
			label$271:;
		};
		label$262:;
		label$261:;
		if (OVERRIDDEN$ == (FBSYMBOL$type*)0) goto label$276;
		{
			#define vr$842 ((FB_SYMBATTRIB*)(OVERRIDDEN$))
			#define vr$843 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$842 + 4) & (FB_SYMBATTRIB)1073741824))
			if (vr$843 == (integer)0) goto label$278;
			{
				#define vr$844 ((FB_STRUCTEXT**)(PARENT$))
				#define vr$845 ((integer*)(*(FB_STRUCTEXT**)((ubyte *)vr$844 + 112)))
				#define vr$846 ((integer)(*(integer*)((ubyte *)vr$845 + 140) + (integer)-1))
				#define vr$847 ((FB_STRUCTEXT**)(PARENT$))
				#define vr$848 ((integer*)(*(FB_STRUCTEXT**)((ubyte *)vr$847 + 112)))
				*(integer*)((ubyte *)vr$848 + 140) = (vr$846);
			};
			label$278:;
			label$277:;
			integer vr$849 = (integer)(SYMBPROCGETVTABLEINDEX( OVERRIDDEN$ ));
			SYMBPROCSETVTABLEINDEX( PROC$, vr$849 );
			#define vr$850 ((FB_PROCEXT**)(PROC$))
			#define vr$851 ((FBSYMBOL$type**)(*(FB_PROCEXT**)((ubyte *)vr$850 + 100)))
			*(FBSYMBOL$type**)((ubyte *)vr$851 + 72) = (OVERRIDDEN$);
		};
		goto label$275;
		label$276:;
		{
			#define vr$852 ((FB_SYMBATTRIB*)(PROC$))
			#define vr$853 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$852 + 4) & (FB_SYMBATTRIB)536870912))
			if (vr$853 == (integer)0) goto label$280;
			{
				integer vr$854 = (integer)(SYMBCOMPADDVIRTUAL( PARENT$ ));
				SYMBPROCSETVTABLEINDEX( PROC$, vr$854 );
			};
			label$280:;
			label$279:;
		};
		label$275:;
	};
	label$258:;
	label$257:;
	fb$result$ = (PROC$);
	label$189:;
	#define vr$855 ((FBSYMBOL$type*)(fb$result$))
	return vr$855;
}

static integer HCALCTYPESDIFF( integer PARAM_DTYPE$, FBSYMBOL$type* PARAM_SUBTYPE$, integer PARAM_PTRCNT$, integer ARG_DTYPE$, FBSYMBOL$type* ARG_SUBTYPE$, ASTNODE$type* ARG_EXPR$, FB_PARAMMODE MODE$ )
{
	integer fb$result$;
	integer ARG_DCLASS$;
	FB_DATATYPE TMP$91$;
	#define vr$856 ((integer*)(&fb$result$))
	__builtin_memset( vr$856, 0, (integer)4 );
	label$401:;
	#define vr$857 ((integer)(PARAM_DTYPE$ & (integer)511))
	PARAM_DTYPE$ = (vr$857);
	#define vr$858 ((integer)(ARG_DTYPE$ & (integer)511))
	ARG_DTYPE$ = (vr$858);
	#define vr$859 ((integer)(ARG_DTYPE$ & (integer)480))
	if (vr$859 == (integer)0) goto label$403;
	TMP$91$ = ((FB_DATATYPE)23);
	goto label$881;
	label$403:;
	#define vr$860 ((integer)(ARG_DTYPE$ & (integer)31))
	#define vr$861 ((FB_DATATYPE)(vr$860))
	TMP$91$ = (vr$861);
	label$881:;
	#define vr$862 ((integer)(TMP$91$))
	#define vr$863 ((integer)(vr$862 * (integer)28))
	#define vr$864 ((integer)(*(FB_DATACLASS*)((ubyte *)&SYMB_DTYPETB$ + vr$863)))
	ARG_DCLASS$ = (vr$864);
	{
		FB_DATATYPE TMP$92$;
		uinteger TMP$93$;
		#define vr$865 ((integer)(PARAM_DTYPE$ & (integer)480))
		if (vr$865 == (integer)0) goto label$404;
		TMP$92$ = ((FB_DATATYPE)23);
		goto label$882;
		label$404:;
		#define vr$866 ((integer)(PARAM_DTYPE$ & (integer)31))
		#define vr$867 ((FB_DATATYPE)(vr$866))
		TMP$92$ = (vr$867);
		label$882:;
		#define vr$868 ((integer)(TMP$92$))
		#define vr$869 ((integer)(vr$868 * (integer)28))
		#define vr$870 ((uinteger)(*(FB_DATACLASS*)((ubyte *)&SYMB_DTYPETB$ + vr$869)))
		TMP$93$ = (vr$870);
		goto label$406;
		label$407:;
		{
			{
				uinteger TMP$94$;
				#define vr$871 ((uinteger)(ARG_DCLASS$))
				TMP$94$ = (vr$871);
				goto label$409;
				label$410:;
				{
					FB_DATATYPE TMP$101$;
					FB_DATATYPE TMP$102$;
					{
						uinteger TMP$95$;
						#define vr$872 ((uinteger)(ARG_DTYPE$))
						TMP$95$ = (vr$872);
						goto label$412;
						label$413:;
						{
							{
								integer TMP$96$;
								TMP$96$ = (PARAM_DTYPE$);
								if (TMP$96$ == (FB_DATATYPE)35) goto label$416;
								label$417:;
								if (TMP$96$ != (FB_DATATYPE)3) goto label$415;
								label$416:;
								{
									fb$result$ = ((integer)50);
									goto label$402;
								};
								goto label$414;
								label$415:;
								if (TMP$96$ == (FB_DATATYPE)38) goto label$419;
								label$420:;
								if (TMP$96$ != (FB_DATATYPE)6) goto label$418;
								label$419:;
								{
									fb$result$ = ((integer)25);
									goto label$402;
								};
								label$418:;
								label$414:;
							};
						};
						goto label$411;
						label$421:;
						{
							{
								integer TMP$97$;
								TMP$97$ = (PARAM_DTYPE$);
								if (TMP$97$ == (FB_DATATYPE)38) goto label$424;
								label$425:;
								if (TMP$97$ != (FB_DATATYPE)6) goto label$423;
								label$424:;
								{
									fb$result$ = ((integer)50);
									goto label$402;
								};
								goto label$422;
								label$423:;
								if (TMP$97$ == (FB_DATATYPE)35) goto label$427;
								label$428:;
								if (TMP$97$ != (FB_DATATYPE)3) goto label$426;
								label$427:;
								{
									fb$result$ = ((integer)25);
									goto label$402;
								};
								label$426:;
								label$422:;
							};
						};
						goto label$411;
						label$429:;
						{
							integer vr$873 = (integer)(TYPEREMAP( ARG_DTYPE$, ARG_SUBTYPE$ ));
							ARG_DTYPE$ = (vr$873);
						};
						goto label$411;
						label$412:;
						if (TMP$95$ < (uinteger)3u) goto label$411;
						if (TMP$95$ > (uinteger)10u) goto label$411;
						static const void * LABEL$430$[] = {
							&&label$413,
							&&label$411,
							&&label$411,
							&&label$421,
							&&label$411,
							&&label$411,
							&&label$429,
							&&label$429,
						(void *)0 };
						#define vr$874 ((uinteger)(TMP$95$ << (uinteger)2u))
						goto **(void**)((ubyte *)LABEL$430$ + vr$874 + -12);
						label$411:;
					};
					#define vr$875 ((integer)(PARAM_DTYPE$ & (integer)480))
					if (vr$875 == (integer)0) goto label$432;
					{
						#define vr$876 ((integer)(ARG_DTYPE$ & (integer)480))
						#define vr$877 ((integer)((-(vr$876 != (integer)0))))
						if (vr$877 != (integer)0) goto label$434;
						{
							FB_DATATYPE TMP$100$;
							if (ARG_EXPR$ != (integer)0) goto label$436;
							{
								fb$result$ = ((integer)0);
								goto label$402;
							};
							label$436:;
							label$435:;
							#define vr$878 ((AST_NODECLASS*)(ARG_EXPR$))
							#define vr$879 ((integer)((-(*(AST_NODECLASS*)((ubyte *)vr$878) == (AST_NODECLASS)16))))
							if (vr$879 != (integer)0) goto label$438;
							{
								fb$result$ = ((integer)0);
								goto label$402;
							};
							label$438:;
							label$437:;
							if (ARG_DTYPE$ != (FB_DATATYPE)7) goto label$440;
							{
								#define vr$880 ((integer*)(ARG_EXPR$))
								if (*(integer*)((ubyte *)vr$880 + 20) == (integer)0) goto label$442;
								{
									fb$result$ = ((integer)0);
									goto label$402;
								};
								label$442:;
								label$441:;
							};
							goto label$439;
							label$440:;
							{
								#define vr$881 ((longint*)(ARG_EXPR$))
								if (*(longint*)((ubyte *)vr$881 + 20) == (longint)0ll) goto label$444;
								{
									fb$result$ = ((integer)0);
									goto label$402;
								};
								label$444:;
								label$443:;
							};
							label$439:;
							#define vr$882 ((integer)(ARG_DTYPE$ & (integer)480))
							if (vr$882 == (integer)0) goto label$445;
							TMP$100$ = ((FB_DATATYPE)23);
							goto label$883;
							label$445:;
							#define vr$883 ((integer)(ARG_DTYPE$ & (integer)31))
							#define vr$884 ((FB_DATATYPE)(vr$883))
							TMP$100$ = (vr$884);
							label$883:;
							#define vr$885 ((integer)(TMP$100$))
							#define vr$886 ((integer)(vr$885 * (integer)28))
							if (*(integer*)((ubyte *)&SYMB_DTYPETB$ + vr$886 + 4) == (integer)4) goto label$447;
							{
								fb$result$ = ((integer)0);
								goto label$402;
							};
							label$447:;
							label$446:;
							fb$result$ = ((integer)25);
							goto label$402;
						};
						label$434:;
						label$433:;
						#define vr$887 ((integer)((-(PARAM_DTYPE$ == (FB_DATATYPE)32))))
						#define vr$888 ((integer)((-(ARG_DTYPE$ == (FB_DATATYPE)32))))
						#define vr$889 ((integer)(vr$887 | vr$888))
						if (vr$889 == (integer)0) goto label$449;
						{
							fb$result$ = ((integer)25);
							goto label$402;
						};
						label$449:;
						label$448:;
						fb$result$ = ((integer)0);
						goto label$402;
					};
					goto label$431;
					label$432:;
					#define vr$890 ((integer)(ARG_DTYPE$ & (integer)480))
					if (vr$890 == (integer)0) goto label$450;
					{
						fb$result$ = ((integer)0);
						goto label$402;
					};
					label$450:;
					label$431:;
					#define vr$891 ((integer)(PARAM_DTYPE$ & (integer)480))
					if (vr$891 == (integer)0) goto label$451;
					TMP$101$ = ((FB_DATATYPE)23);
					goto label$884;
					label$451:;
					#define vr$892 ((integer)(PARAM_DTYPE$ & (integer)31))
					#define vr$893 ((FB_DATATYPE)(vr$892))
					TMP$101$ = (vr$893);
					label$884:;
					#define vr$894 ((integer)(ARG_DTYPE$ & (integer)480))
					if (vr$894 == (integer)0) goto label$452;
					TMP$102$ = ((FB_DATATYPE)23);
					goto label$885;
					label$452:;
					#define vr$895 ((integer)(ARG_DTYPE$ & (integer)31))
					#define vr$896 ((FB_DATATYPE)(vr$895))
					TMP$102$ = (vr$896);
					label$885:;
					#define vr$897 ((FB_DATATYPE)(TMP$101$ - TMP$102$))
					integer vr$898 = (integer)(abs( vr$897 ));
					#define vr$899 ((FB_DATATYPE)((FB_DATATYPE)25 - vr$898))
					#define vr$900 ((integer)(vr$899))
					fb$result$ = (vr$900);
					goto label$402;
				};
				goto label$408;
				label$453:;
				{
					FB_DATATYPE TMP$103$;
					FB_DATATYPE TMP$104$;
					#define vr$901 ((integer)(PARAM_DTYPE$ & (integer)480))
					if (vr$901 == (integer)0) goto label$455;
					{
						fb$result$ = ((integer)0);
						goto label$402;
					};
					label$455:;
					label$454:;
					#define vr$902 ((integer)(PARAM_DTYPE$ & (integer)480))
					if (vr$902 == (integer)0) goto label$456;
					TMP$103$ = ((FB_DATATYPE)23);
					goto label$886;
					label$456:;
					#define vr$903 ((integer)(PARAM_DTYPE$ & (integer)31))
					#define vr$904 ((FB_DATATYPE)(vr$903))
					TMP$103$ = (vr$904);
					label$886:;
					#define vr$905 ((integer)(ARG_DTYPE$ & (integer)480))
					if (vr$905 == (integer)0) goto label$457;
					TMP$104$ = ((FB_DATATYPE)23);
					goto label$887;
					label$457:;
					#define vr$906 ((integer)(ARG_DTYPE$ & (integer)31))
					#define vr$907 ((FB_DATATYPE)(vr$906))
					TMP$104$ = (vr$907);
					label$887:;
					#define vr$908 ((FB_DATATYPE)(TMP$103$ - TMP$104$))
					integer vr$909 = (integer)(abs( vr$908 ));
					#define vr$910 ((FB_DATATYPE)((FB_DATATYPE)25 - vr$909))
					#define vr$911 ((integer)(vr$910))
					fb$result$ = (vr$911);
					goto label$402;
				};
				goto label$408;
				label$458:;
				{
					{
						integer TMP$105$;
						TMP$105$ = (PARAM_DTYPE$);
						if (TMP$105$ != (FB_DATATYPE)35) goto label$460;
						label$461:;
						{
							fb$result$ = ((integer)50);
							goto label$402;
						};
						goto label$459;
						label$460:;
						if (TMP$105$ != (FB_DATATYPE)38) goto label$462;
						label$463:;
						{
							fb$result$ = ((integer)25);
							goto label$402;
						};
						goto label$459;
						label$462:;
						{
							fb$result$ = ((integer)0);
							goto label$402;
						};
						label$464:;
						label$459:;
					};
				};
				goto label$408;
				label$465:;
				{
					fb$result$ = ((integer)0);
					goto label$402;
				};
				goto label$408;
				label$409:;
				if (TMP$94$ > (uinteger)2u) goto label$465;
				static const void * LABEL$466$[] = {
					&&label$410,
					&&label$453,
					&&label$458,
				(void *)0 };
				#define vr$912 ((uinteger)(TMP$94$ << (uinteger)2u))
				goto **(void**)((ubyte *)LABEL$466$ + vr$912);
				label$408:;
			};
		};
		goto label$405;
		label$467:;
		{
			{
				uinteger TMP$108$;
				#define vr$913 ((uinteger)(ARG_DCLASS$))
				TMP$108$ = (vr$913);
				goto label$469;
				label$470:;
				{
					FB_DATATYPE TMP$110$;
					FB_DATATYPE TMP$111$;
					#define vr$914 ((integer)(ARG_DTYPE$ & (integer)480))
					if (vr$914 == (integer)0) goto label$472;
					{
						fb$result$ = ((integer)0);
						goto label$402;
					};
					label$472:;
					label$471:;
					{
						integer TMP$109$;
						TMP$109$ = (ARG_DTYPE$);
						if (TMP$109$ == (FB_DATATYPE)10) goto label$475;
						label$476:;
						if (TMP$109$ != (FB_DATATYPE)9) goto label$474;
						label$475:;
						{
							integer vr$915 = (integer)(TYPEREMAP( ARG_DTYPE$, ARG_SUBTYPE$ ));
							ARG_DTYPE$ = (vr$915);
						};
						label$474:;
						label$473:;
					};
					#define vr$916 ((integer)(PARAM_DTYPE$ & (integer)480))
					if (vr$916 == (integer)0) goto label$477;
					TMP$110$ = ((FB_DATATYPE)23);
					goto label$888;
					label$477:;
					#define vr$917 ((integer)(PARAM_DTYPE$ & (integer)31))
					#define vr$918 ((FB_DATATYPE)(vr$917))
					TMP$110$ = (vr$918);
					label$888:;
					#define vr$919 ((integer)(ARG_DTYPE$ & (integer)480))
					if (vr$919 == (integer)0) goto label$478;
					TMP$111$ = ((FB_DATATYPE)23);
					goto label$889;
					label$478:;
					#define vr$920 ((integer)(ARG_DTYPE$ & (integer)31))
					#define vr$921 ((FB_DATATYPE)(vr$920))
					TMP$111$ = (vr$921);
					label$889:;
					#define vr$922 ((FB_DATATYPE)(TMP$110$ - TMP$111$))
					integer vr$923 = (integer)(abs( vr$922 ));
					#define vr$924 ((FB_DATATYPE)((FB_DATATYPE)25 - vr$923))
					#define vr$925 ((integer)(vr$924))
					fb$result$ = (vr$925);
					goto label$402;
				};
				goto label$468;
				label$479:;
				{
					FB_DATATYPE TMP$112$;
					FB_DATATYPE TMP$113$;
					#define vr$926 ((integer)(PARAM_DTYPE$ & (integer)480))
					if (vr$926 == (integer)0) goto label$480;
					TMP$112$ = ((FB_DATATYPE)23);
					goto label$890;
					label$480:;
					#define vr$927 ((integer)(PARAM_DTYPE$ & (integer)31))
					#define vr$928 ((FB_DATATYPE)(vr$927))
					TMP$112$ = (vr$928);
					label$890:;
					#define vr$929 ((integer)(ARG_DTYPE$ & (integer)480))
					if (vr$929 == (integer)0) goto label$481;
					TMP$113$ = ((FB_DATATYPE)23);
					goto label$891;
					label$481:;
					#define vr$930 ((integer)(ARG_DTYPE$ & (integer)31))
					#define vr$931 ((FB_DATATYPE)(vr$930))
					TMP$113$ = (vr$931);
					label$891:;
					#define vr$932 ((FB_DATATYPE)(TMP$112$ - TMP$113$))
					integer vr$933 = (integer)(abs( vr$932 ));
					#define vr$934 ((FB_DATATYPE)((FB_DATATYPE)25 - vr$933))
					#define vr$935 ((integer)(vr$934))
					fb$result$ = (vr$935);
					goto label$402;
				};
				goto label$468;
				label$482:;
				{
					fb$result$ = ((integer)0);
					goto label$402;
				};
				goto label$468;
				label$469:;
				if (TMP$108$ > (uinteger)1u) goto label$482;
				static const void * LABEL$483$[] = {
					&&label$470,
					&&label$479,
				(void *)0 };
				#define vr$936 ((uinteger)(TMP$108$ << (uinteger)2u))
				goto **(void**)((ubyte *)LABEL$483$ + vr$936);
				label$468:;
			};
		};
		goto label$405;
		label$484:;
		{
			{
				integer TMP$116$;
				TMP$116$ = (ARG_DCLASS$);
				if (TMP$116$ != (FB_DATACLASS)2) goto label$486;
				label$487:;
				{
					fb$result$ = ((integer)50);
					goto label$402;
				};
				goto label$485;
				label$486:;
				if (TMP$116$ != (FB_DATACLASS)0) goto label$488;
				label$489:;
				{
					{
						integer TMP$117$;
						TMP$117$ = (ARG_DTYPE$);
						if (TMP$117$ != (FB_DATATYPE)3) goto label$491;
						label$492:;
						{
							fb$result$ = ((integer)50);
							goto label$402;
						};
						goto label$490;
						label$491:;
						if (TMP$117$ != (FB_DATATYPE)6) goto label$493;
						label$494:;
						{
							fb$result$ = ((integer)25);
							goto label$402;
						};
						goto label$490;
						label$493:;
						{
							fb$result$ = ((integer)0);
							goto label$402;
						};
						label$495:;
						label$490:;
					};
				};
				goto label$485;
				label$488:;
				{
					fb$result$ = ((integer)0);
					goto label$402;
				};
				label$496:;
				label$485:;
			};
		};
		goto label$405;
		label$497:;
		{
			fb$result$ = ((integer)0);
			goto label$402;
		};
		goto label$405;
		label$406:;
		if (TMP$93$ > (uinteger)2u) goto label$497;
		static const void * LABEL$498$[] = {
			&&label$407,
			&&label$467,
			&&label$484,
		(void *)0 };
		#define vr$937 ((uinteger)(TMP$93$ << (uinteger)2u))
		goto **(void**)((ubyte *)LABEL$498$ + vr$937);
		label$405:;
	};
	label$402:;
	#define vr$938 ((integer)(fb$result$))
	return vr$938;
}

static integer HCHECKOVLPARAM( FBSYMBOL$type* PARENT$, FBSYMBOL$type* PARAM$, ASTNODE$type* ARG_EXPR$, integer ARG_MODE$, integer* CONSTONLY_DIFF$ )
{
	integer fb$result$;
	integer PARAM_DTYPE$;
	integer ARG_DTYPE$;
	integer PARAM_PTRCNT$;
	FBSYMBOL$type* PARAM_SUBTYPE$;
	FBSYMBOL$type* ARG_SUBTYPE$;
	static integer CAST_REC_CNT$ = 0;
	static integer CTOR_REC_CNT$ = 0;
	#define vr$939 ((integer*)(&fb$result$))
	__builtin_memset( vr$939, 0, (integer)4 );
	label$499:;
	#define vr$940 ((integer*)((integer*)(CONSTONLY_DIFF$)))
	*(integer*)((ubyte *)vr$940) = ((integer)0);
	if (ARG_EXPR$ != (integer)0) goto label$502;
	{
		#define vr$941 ((FB_SYMBATTRIB*)(PARAM$))
		#define vr$942 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$941 + 4) & (FB_SYMBATTRIB)2097152))
		if (vr$942 == (integer)0) goto label$504;
		{
			fb$result$ = ((integer)50);
			goto label$500;
		};
		goto label$503;
		label$504:;
		{
			fb$result$ = ((integer)0);
			goto label$500;
		};
		label$503:;
	};
	label$502:;
	label$501:;
	#define vr$943 ((FB_DATATYPE*)(PARAM$))
	#define vr$944 ((integer)(*(FB_DATATYPE*)((ubyte *)vr$943 + 24)))
	PARAM_DTYPE$ = (vr$944);
	#define vr$945 ((FBSYMBOL$type**)(PARAM$))
	PARAM_SUBTYPE$ = (*(FBSYMBOL$type**)((ubyte *)vr$945 + 28));
	#define vr$946 ((FB_DATATYPE*)(PARAM$))
	#define vr$947 ((FB_DATATYPE)(*(FB_DATATYPE*)((ubyte *)vr$946 + 24) & (integer)511))
	#define vr$948 ((FB_DATATYPE)(vr$947 & (integer)480))
	#define vr$949 ((FB_DATATYPE)(vr$948 >> (integer)5))
	#define vr$950 ((integer)(vr$949))
	PARAM_PTRCNT$ = (vr$950);
	#define vr$951 ((integer*)(ARG_EXPR$))
	ARG_DTYPE$ = (*(integer*)((ubyte *)vr$951 + 4));
	#define vr$952 ((FBSYMBOL$type**)(ARG_EXPR$))
	ARG_SUBTYPE$ = (*(FBSYMBOL$type**)((ubyte *)vr$952 + 8));
	{
		FB_PARAMMODE TMP$120$;
		#define vr$953 ((FB_PARAMMODE*)(PARAM$))
		TMP$120$ = (*(FB_PARAMMODE*)((ubyte *)vr$953 + 44));
		if (*(integer*)(&TMP$120$) != (FB_PARAMMODE)3) goto label$506;
		label$507:;
		{
			if (ARG_MODE$ == (FB_PARAMMODE)3) goto label$509;
			{
				fb$result$ = ((integer)0);
				goto label$500;
			};
			label$509:;
			label$508:;
			if (PARAM_DTYPE$ == ARG_DTYPE$) goto label$511;
			{
				fb$result$ = ((integer)0);
				goto label$500;
			};
			label$511:;
			label$510:;
			if (PARAM_SUBTYPE$ == ARG_SUBTYPE$) goto label$513;
			{
				fb$result$ = ((integer)0);
				goto label$500;
			};
			label$513:;
			label$512:;
			fb$result$ = ((integer)50);
			goto label$500;
		};
		goto label$505;
		label$506:;
		if (*(integer*)(&TMP$120$) != (FB_PARAMMODE)2) goto label$514;
		label$515:;
		{
			if (ARG_MODE$ != (FB_PARAMMODE)1) goto label$517;
			{
				FB_DATATYPE TMP$121$;
				FB_DATATYPE TMP$122$;
				#define vr$954 ((integer)(ARG_DTYPE$ & (integer)480))
				if (vr$954 == (integer)0) goto label$518;
				TMP$121$ = ((FB_DATATYPE)23);
				goto label$892;
				label$518:;
				#define vr$955 ((integer)(ARG_DTYPE$ & (integer)31))
				#define vr$956 ((FB_DATATYPE)(vr$955))
				TMP$121$ = (vr$956);
				label$892:;
				#define vr$957 ((integer)(TMP$121$))
				#define vr$958 ((integer)(vr$957 * (integer)28))
				#define vr$959 ((integer)((-(*(FB_DATACLASS*)((ubyte *)&SYMB_DTYPETB$ + vr$958) != (FB_DATACLASS)0))))
				#define vr$960 ((integer)(ARG_DTYPE$ & (integer)480))
				if (vr$960 == (integer)0) goto label$519;
				TMP$122$ = ((FB_DATATYPE)23);
				goto label$893;
				label$519:;
				#define vr$961 ((integer)(ARG_DTYPE$ & (integer)31))
				#define vr$962 ((FB_DATATYPE)(vr$961))
				TMP$122$ = (vr$962);
				label$893:;
				#define vr$963 ((integer)(TMP$122$))
				#define vr$964 ((integer)(vr$963 * (integer)28))
				#define vr$965 ((integer)((-(*(integer*)((ubyte *)&SYMB_DTYPETB$ + vr$964 + 4) != (integer)4))))
				#define vr$966 ((integer)(vr$959 | vr$965))
				if (vr$966 == (integer)0) goto label$521;
				{
					fb$result$ = ((integer)0);
					goto label$500;
				};
				label$521:;
				label$520:;
				#define vr$967 ((integer)(PARAM_DTYPE$ & (integer)31))
				#define vr$968 ((integer)(PARAM_DTYPE$ & (integer)480))
				#define vr$969 ((integer)(vr$968 + (integer)32))
				#define vr$970 ((integer)(vr$967 | vr$969))
				#define vr$971 ((integer)(PARAM_DTYPE$ & (integer)261632))
				#define vr$972 ((integer)(vr$971 << (integer)1))
				#define vr$973 ((integer)(vr$970 | vr$972))
				PARAM_DTYPE$ = (vr$973);
				#define vr$974 ((integer)(PARAM_PTRCNT$ + (integer)1))
				PARAM_PTRCNT$ = (vr$974);
			};
			label$517:;
			label$516:;
		};
		label$514:;
		label$505:;
	};
	if (ARG_MODE$ != (FB_PARAMMODE)3) goto label$523;
	{
		fb$result$ = ((integer)0);
		goto label$500;
	};
	label$523:;
	label$522:;
	#define vr$975 ((integer)(PARAM_DTYPE$ & (integer)511))
	#define vr$976 ((integer)(ARG_DTYPE$ & (integer)511))
	if (vr$975 != vr$976) goto label$525;
	{
		#define vr$977 ((integer)(PARAM_DTYPE$ & (integer)261632))
		#define vr$978 ((integer)(ARG_DTYPE$ & (integer)261632))
		if (vr$977 != vr$978) goto label$527;
		{
			if (PARAM_SUBTYPE$ != ARG_SUBTYPE$) goto label$529;
			{
				fb$result$ = ((integer)50);
				goto label$500;
			};
			goto label$528;
			label$529:;
			{
				if (PARAM_SUBTYPE$ == (integer)0) goto label$531;
				{
					{
						FB_DATATYPE TMP$123$;
						#define vr$979 ((FB_DATATYPE*)(PARAM_SUBTYPE$))
						#define vr$980 ((FB_DATATYPE)(*(FB_DATATYPE*)((ubyte *)vr$979 + 24) & (integer)511))
						TMP$123$ = (vr$980);
						if (*(integer*)(&TMP$123$) != (FB_DATATYPE)19) goto label$533;
						label$534:;
						{
							integer LEVEL$;
							integer vr$981 = (integer)(SYMBGETUDTBASELEVEL( ARG_SUBTYPE$, PARAM_SUBTYPE$ ));
							LEVEL$ = (vr$981);
							if (LEVEL$ <= (integer)0) goto label$536;
							{
								#define vr$982 ((FB_DATATYPE)((FB_DATATYPE)50 - LEVEL$))
								#define vr$983 ((integer)(vr$982))
								fb$result$ = (vr$983);
								goto label$500;
							};
							label$536:;
							label$535:;
						};
						label$533:;
						label$532:;
					};
				};
				label$531:;
				label$530:;
			};
			label$528:;
		};
		goto label$526;
		label$527:;
		#define vr$984 ((integer)(PARAM_DTYPE$ & (integer)261632))
		if (vr$984 == (integer)0) goto label$537;
		{
			if (PARAM_SUBTYPE$ != ARG_SUBTYPE$) goto label$539;
			{
				integer TMP$124$;
				TMP$124$ = ((integer)0);
				#define vr$985 ((integer*)(&TMP$124$))
				integer vr$986 = (integer)(SYMBCHECKCONSTASSIGN( PARAM_DTYPE$, ARG_DTYPE$, PARAM_SUBTYPE$, ARG_SUBTYPE$, (integer)0, vr$985 ));
				if (vr$986 == (integer)0) goto label$541;
				{
					#define vr$987 ((integer*)((integer*)(CONSTONLY_DIFF$)))
					*(integer*)((ubyte *)vr$987) = ((integer)-1);
					fb$result$ = ((integer)25);
					goto label$500;
				};
				label$541:;
				label$540:;
			};
			label$539:;
			label$538:;
		};
		label$537:;
		label$526:;
		#define vr$988 ((FB_SYMBSTATS*)(PARENT$))
		#define vr$989 ((FB_SYMBSTATS)(*(FB_SYMBSTATS*)((ubyte *)vr$988 + 8) & (FB_SYMBSTATS)32))
		#define vr$990 ((integer)((-(vr$989 != (integer)0))))
		#define vr$991 ((integer)((-(vr$990 == (integer)0))))
		#define vr$992 ((FB_SYMBSTATS*)(PARAM$))
		#define vr$993 ((FB_SYMBSTATS)(*(FB_SYMBSTATS*)((ubyte *)vr$992 + 8) & (FB_SYMBSTATS)33554432))
		#define vr$994 ((integer)((-(vr$993 != (integer)0))))
		#define vr$995 ((integer)(vr$991 | vr$994))
		if (vr$995 == (integer)0) goto label$543;
		{
			integer CONST_MATCHES$;
			#define vr$996 ((integer*)(&CONST_MATCHES$))
			#define vr$997 ((FB_PARAMMODE*)(PARAM$))
			integer vr$998 = (integer)(SYMBCHECKCONSTASSIGN( PARAM_DTYPE$, ARG_DTYPE$, PARAM_SUBTYPE$, ARG_SUBTYPE$, *(FB_PARAMMODE*)((ubyte *)vr$997 + 44), vr$996 ));
			if (vr$998 != (integer)0) goto label$545;
			{
				fb$result$ = ((integer)0);
				goto label$500;
			};
			goto label$544;
			label$545:;
			{
				if (CONST_MATCHES$ == (integer)0) goto label$547;
				{
					integer PTRCNT$;
					#define vr$999 ((integer)(ARG_DTYPE$ & (integer)480))
					#define vr$1000 ((integer)(vr$999 >> (integer)5))
					PTRCNT$ = (vr$1000);
					#define vr$1001 ((integer)(PTRCNT$ + (integer)2))
					#define vr$1002 ((double)(vr$1001))
					#define vr$1003 ((double)((double)(double)25.0 / (double)vr$1002))
					#define vr$1004 ((double)(vr$1003 * CONST_MATCHES$))
					integer vr$1005 = (integer)(fb_dtosi( vr$1004 ));
					fb$result$ = (vr$1005);
					goto label$500;
				};
				label$547:;
				label$546:;
			};
			label$544:;
		};
		label$543:;
		label$542:;
		#define vr$1006 ((integer)(PARAM_DTYPE$ & (integer)480))
		if (vr$1006 == (integer)0) goto label$549;
		{
			integer vr$1007 = (integer)(ASTPTRCHECK( PARAM_DTYPE$, PARAM_SUBTYPE$, ARG_EXPR$, (integer)-1 ));
			if (vr$1007 == (integer)0) goto label$551;
			{
				fb$result$ = ((integer)50);
				goto label$500;
			};
			label$551:;
			label$550:;
			fb$result$ = ((integer)0);
			goto label$500;
		};
		label$549:;
		label$548:;
	};
	label$525:;
	label$524:;
	{
		integer TMP$125$;
		TMP$125$ = (PARAM_DTYPE$);
		if (TMP$125$ != (FB_DATATYPE)19) goto label$553;
		label$554:;
		{
			if (CTOR_REC_CNT$ != (integer)0) goto label$556;
			{
				integer ERR_NUM$;
				FBSYMBOL$type* PROC$;
				#define vr$1008 ((integer)(CTOR_REC_CNT$ + (integer)1))
				CTOR_REC_CNT$ = (vr$1008);
				#define vr$1009 ((integer*)(&ERR_NUM$))
				FBSYMBOL$type* vr$1010 = (FBSYMBOL$type*)(SYMBFINDCTOROVLPROC( PARAM_SUBTYPE$, ARG_EXPR$, ARG_MODE$, vr$1009 ));
				PROC$ = (vr$1010);
				#define vr$1011 ((integer)(CTOR_REC_CNT$ + (integer)-1))
				CTOR_REC_CNT$ = (vr$1011);
				if (PROC$ == (integer)0) goto label$558;
				{
					fb$result$ = ((integer)6);
					goto label$500;
				};
				label$558:;
				label$557:;
			};
			label$556:;
			label$555:;
			if (CAST_REC_CNT$ != (integer)0) goto label$560;
			{
				integer ERR_NUM$;
				FBSYMBOL$type* PROC$;
				#define vr$1012 ((integer)(CAST_REC_CNT$ + (integer)1))
				CAST_REC_CNT$ = (vr$1012);
				#define vr$1013 ((integer*)(&ERR_NUM$))
				FBSYMBOL$type* vr$1014 = (FBSYMBOL$type*)(SYMBFINDCASTOVLPROC( PARAM_DTYPE$, PARAM_SUBTYPE$, ARG_EXPR$, vr$1013 ));
				PROC$ = (vr$1014);
				#define vr$1015 ((integer)(CAST_REC_CNT$ + (integer)-1))
				CAST_REC_CNT$ = (vr$1015);
				if (PROC$ == (integer)0) goto label$562;
				{
					fb$result$ = ((integer)6);
					goto label$500;
				};
				label$562:;
				label$561:;
			};
			label$560:;
			label$559:;
			fb$result$ = ((integer)0);
			goto label$500;
		};
		goto label$552;
		label$553:;
		if (TMP$125$ != (FB_DATATYPE)9) goto label$563;
		label$564:;
		{
			fb$result$ = ((integer)0);
			goto label$500;
		};
		goto label$552;
		label$563:;
		{
			{
				integer TMP$126$;
				TMP$126$ = (ARG_DTYPE$);
				if (TMP$126$ != (FB_DATATYPE)19) goto label$567;
				label$568:;
				{
					if (CAST_REC_CNT$ != (integer)0) goto label$570;
					{
						integer ERR_NUM$;
						FBSYMBOL$type* PROC$;
						#define vr$1016 ((integer)(CAST_REC_CNT$ + (integer)1))
						CAST_REC_CNT$ = (vr$1016);
						#define vr$1017 ((integer*)(&ERR_NUM$))
						#define vr$1018 ((FB_DATATYPE*)(PARAM$))
						FBSYMBOL$type* vr$1019 = (FBSYMBOL$type*)(SYMBFINDCASTOVLPROC( *(FB_DATATYPE*)((ubyte *)vr$1018 + 24), PARAM_SUBTYPE$, ARG_EXPR$, vr$1017 ));
						PROC$ = (vr$1019);
						#define vr$1020 ((integer)(CAST_REC_CNT$ + (integer)-1))
						CAST_REC_CNT$ = (vr$1020);
						if (PROC$ == (integer)0) goto label$572;
						{
							fb$result$ = ((integer)6);
							goto label$500;
						};
						label$572:;
						label$571:;
					};
					label$570:;
					label$569:;
					fb$result$ = ((integer)0);
					goto label$500;
				};
				label$567:;
				label$566:;
			};
		};
		label$565:;
		label$552:;
	};
	#define vr$1021 ((FB_PARAMMODE*)(PARAM$))
	#define vr$1022 ((integer*)(ARG_EXPR$))
	#define vr$1023 ((FB_DATATYPE*)(PARAM$))
	integer vr$1024 = (integer)(HCALCTYPESDIFF( *(FB_DATATYPE*)((ubyte *)vr$1023 + 24), PARAM_SUBTYPE$, PARAM_PTRCNT$, *(integer*)((ubyte *)vr$1022 + 4), ARG_SUBTYPE$, ARG_EXPR$, *(FB_PARAMMODE*)((ubyte *)vr$1021 + 44) ));
	fb$result$ = (vr$1024);
	label$500:;
	#define vr$1025 ((integer)(fb$result$))
	return vr$1025;
}

static integer HCHECKCASTOVL( FBSYMBOL$type* PROC$, integer TO_DTYPE$, FBSYMBOL$type* TO_SUBTYPE$ )
{
	integer fb$result$;
	integer PROC_DTYPE$;
	FBSYMBOL$type* PROC_SUBTYPE$;
	#define vr$1026 ((integer*)(&fb$result$))
	__builtin_memset( vr$1026, 0, (integer)4 );
	label$686:;
	#define vr$1027 ((FB_DATATYPE*)(PROC$))
	#define vr$1028 ((integer)(*(FB_DATATYPE*)((ubyte *)vr$1027 + 24)))
	PROC_DTYPE$ = (vr$1028);
	#define vr$1029 ((FBSYMBOL$type**)(PROC$))
	PROC_SUBTYPE$ = (*(FBSYMBOL$type**)((ubyte *)vr$1029 + 28));
	#define vr$1030 ((integer)(PROC_DTYPE$ & (integer)511))
	#define vr$1031 ((integer)(TO_DTYPE$ & (integer)511))
	if (vr$1030 != vr$1031) goto label$689;
	{
		if (PROC_SUBTYPE$ != TO_SUBTYPE$) goto label$691;
		{
			fb$result$ = ((integer)50);
			goto label$687;
		};
		label$691:;
		label$690:;
		#define vr$1032 ((integer)(PROC_DTYPE$ & (integer)480))
		if (vr$1032 == (integer)0) goto label$693;
		{
			fb$result$ = ((integer)0);
			goto label$687;
		};
		label$693:;
		label$692:;
	};
	label$689:;
	label$688:;
	{
		FB_DATATYPE TMP$133$;
		FB_DATATYPE TMP$134$;
		#define vr$1033 ((integer)(PROC_DTYPE$ & (integer)480))
		if (vr$1033 == (integer)0) goto label$694;
		TMP$133$ = ((FB_DATATYPE)23);
		goto label$894;
		label$694:;
		#define vr$1034 ((integer)(PROC_DTYPE$ & (integer)31))
		#define vr$1035 ((FB_DATATYPE)(vr$1034))
		TMP$133$ = (vr$1035);
		label$894:;
		TMP$134$ = (TMP$133$);
		if (*(integer*)(&TMP$134$) == (FB_DATATYPE)19) goto label$697;
		label$698:;
		if (*(integer*)(&TMP$134$) != (FB_DATATYPE)9) goto label$696;
		label$697:;
		{
			fb$result$ = ((integer)0);
			goto label$687;
		};
		goto label$695;
		label$696:;
		{
			{
				FB_DATATYPE TMP$135$;
				FB_DATATYPE TMP$136$;
				#define vr$1036 ((integer)(TO_DTYPE$ & (integer)480))
				if (vr$1036 == (integer)0) goto label$700;
				TMP$135$ = ((FB_DATATYPE)23);
				goto label$895;
				label$700:;
				#define vr$1037 ((integer)(TO_DTYPE$ & (integer)31))
				#define vr$1038 ((FB_DATATYPE)(vr$1037))
				TMP$135$ = (vr$1038);
				label$895:;
				TMP$136$ = (TMP$135$);
				if (*(integer*)(&TMP$136$) != (FB_DATATYPE)19) goto label$702;
				label$703:;
				{
					fb$result$ = ((integer)0);
					goto label$687;
				};
				label$702:;
				label$701:;
			};
		};
		label$699:;
		label$695:;
	};
	#define vr$1039 ((FB_DATATYPE*)(PROC$))
	#define vr$1040 ((FB_DATATYPE)(*(FB_DATATYPE*)((ubyte *)vr$1039 + 24) & (integer)511))
	#define vr$1041 ((FB_DATATYPE)(vr$1040 & (integer)480))
	#define vr$1042 ((FB_DATATYPE)(vr$1041 >> (integer)5))
	integer vr$1043 = (integer)(HCALCTYPESDIFF( PROC_DTYPE$, PROC_SUBTYPE$, vr$1042, TO_DTYPE$, TO_SUBTYPE$, (integer)0, (integer)0 ));
	fb$result$ = (vr$1043);
	label$687:;
	#define vr$1044 ((integer)(fb$result$))
	return vr$1044;
}

static void HDELPARAMS( FBSYMBOL$type* PROC$ )
{
	FBSYMBOL$type* PARAM$;
	FBSYMBOL$type* NXT$;
	label$743:;
	#define vr$1045 ((FBSYMBOL$type**)(PROC$))
	PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$1045 + 64));
	label$745:;
	if (PARAM$ == (FBSYMBOL$type*)0) goto label$746;
	{
		#define vr$1046 ((FBSYMBOL$type**)(PARAM$))
		NXT$ = (*(FBSYMBOL$type**)((ubyte *)vr$1046 + 148));
		SYMBFREESYMBOL( PARAM$ );
		PARAM$ = (NXT$);
	};
	goto label$745;
	label$746:;
	label$744:;
}

static FB_GLOBCTORLIST_ITEM$type* HADDTOGLOBCTORLIST( FB_GLOBCTORLIST* LIST$, FBSYMBOL$type* PROC$ )
{
	FB_GLOBCTORLIST_ITEM$type* fb$result$;
	FB_GLOBCTORLIST_ITEM$type* N$;
	#define vr$1047 ((FB_GLOBCTORLIST_ITEM$type**)(&fb$result$))
	__builtin_memset( vr$1047, 0, (integer)4 );
	label$751:;
	#define vr$1048 ((TLIST*)(LIST$))
	#define vr$1049 ((TLIST*)(&*(TLIST*)((ubyte *)vr$1048 + 8)))
	void* vr$1050 = (void*)(LISTNEWNODE( vr$1049 ));
	N$ = (vr$1050);
	#define vr$1051 ((FB_GLOBCTORLIST_ITEM$type**)(LIST$))
	if (*(FB_GLOBCTORLIST_ITEM$type**)((ubyte *)vr$1051 + 4) == (integer)0) goto label$754;
	{
		#define vr$1052 ((FB_GLOBCTORLIST_ITEM$type**)(LIST$))
		#define vr$1053 ((FB_GLOBCTORLIST_ITEM$type**)(*(FB_GLOBCTORLIST_ITEM$type**)((ubyte *)vr$1052 + 4)))
		*(FB_GLOBCTORLIST_ITEM$type**)((ubyte *)vr$1053 + 4) = (N$);
	};
	goto label$753;
	label$754:;
	{
		#define vr$1054 ((FB_GLOBCTORLIST_ITEM$type**)(LIST$))
		*(FB_GLOBCTORLIST_ITEM$type**)((ubyte *)vr$1054) = (N$);
	};
	label$753:;
	#define vr$1055 ((FB_GLOBCTORLIST_ITEM$type**)(N$))
	*(FB_GLOBCTORLIST_ITEM$type**)((ubyte *)vr$1055 + 4) = ((FB_GLOBCTORLIST_ITEM$type*)0);
	#define vr$1056 ((FB_GLOBCTORLIST_ITEM$type**)(LIST$))
	*(FB_GLOBCTORLIST_ITEM$type**)((ubyte *)vr$1056 + 4) = (N$);
	#define vr$1057 ((FBSYMBOL$type**)(N$))
	*(FBSYMBOL$type**)((ubyte *)vr$1057) = (PROC$);
	fb$result$ = (N$);
	label$752:;
	#define vr$1058 ((FB_GLOBCTORLIST_ITEM$type*)(fb$result$))
	return vr$1058;
}

static integer HAREMETHODSCOMPATIBLE( FBSYMBOL$type* V$, FBSYMBOL$type* O$ )
{
	integer fb$result$;
	FBSYMBOL$type* VPARAM$;
	FBSYMBOL$type* OPARAM$;
	FBSYMBOL$type* TMP$139$;
	FBSYMBOL$type* TMP$140$;
	#define vr$1059 ((integer*)(&fb$result$))
	__builtin_memset( vr$1059, 0, (integer)4 );
	label$759:;
	#define vr$1060 ((FB_DATATYPE*)(V$))
	#define vr$1061 ((FB_DATATYPE)(*(FB_DATATYPE*)((ubyte *)vr$1060 + 24) & (integer)511))
	#define vr$1062 ((FB_DATATYPE*)(O$))
	#define vr$1063 ((FB_DATATYPE)(*(FB_DATATYPE*)((ubyte *)vr$1062 + 24) & (integer)511))
	#define vr$1064 ((integer)((-(vr$1061 != vr$1063))))
	#define vr$1065 ((FBSYMBOL$type**)(V$))
	#define vr$1066 ((FBSYMBOL$type**)(O$))
	#define vr$1067 ((integer)((-(*(FBSYMBOL$type**)((ubyte *)vr$1065 + 28) != *(FBSYMBOL$type**)((ubyte *)vr$1066 + 28)))))
	#define vr$1068 ((integer)(vr$1064 | vr$1067))
	if (vr$1068 == (integer)0) goto label$762;
	{
		fb$result$ = ((integer)212);
		goto label$760;
	};
	label$762:;
	label$761:;
	#define vr$1069 ((FB_SYMBATTRIB*)(V$))
	#define vr$1070 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$1069 + 4) & (FB_SYMBATTRIB)33554432))
	#define vr$1071 ((integer)((-(vr$1070 != (integer)0))))
	#define vr$1072 ((FB_SYMBATTRIB*)(O$))
	#define vr$1073 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$1072 + 4) & (FB_SYMBATTRIB)33554432))
	#define vr$1074 ((integer)((-(vr$1073 != (integer)0))))
	if (vr$1071 == vr$1074) goto label$764;
	{
		fb$result$ = ((integer)212);
		goto label$760;
	};
	label$764:;
	label$763:;
	integer vr$1075 = (integer)(SYMBAREPROCMODESEQUAL( V$, O$ ));
	if (vr$1075 != (integer)0) goto label$766;
	{
		fb$result$ = ((integer)213);
		goto label$760;
	};
	label$766:;
	label$765:;
	#define vr$1076 ((short*)(V$))
	#define vr$1077 ((short*)(O$))
	if (*(short*)((ubyte *)vr$1076 + 56) == *(short*)((ubyte *)vr$1077 + 56)) goto label$768;
	{
		fb$result$ = ((integer)216);
		goto label$760;
	};
	label$768:;
	label$767:;
	#define vr$1078 ((FB_FUNCMODE*)(V$))
	if (*(FB_FUNCMODE*)((ubyte *)vr$1078 + 72) != (FB_FUNCMODE)4) goto label$769;
	#define vr$1079 ((FBSYMBOL$type**)(V$))
	TMP$139$ = (*(FBSYMBOL$type**)((ubyte *)vr$1079 + 68));
	goto label$896;
	label$769:;
	#define vr$1080 ((FBSYMBOL$type**)(V$))
	TMP$139$ = (*(FBSYMBOL$type**)((ubyte *)vr$1080 + 64));
	label$896:;
	VPARAM$ = (TMP$139$);
	#define vr$1081 ((FB_FUNCMODE*)(O$))
	if (*(FB_FUNCMODE*)((ubyte *)vr$1081 + 72) != (FB_FUNCMODE)4) goto label$770;
	#define vr$1082 ((FBSYMBOL$type**)(O$))
	TMP$140$ = (*(FBSYMBOL$type**)((ubyte *)vr$1082 + 68));
	goto label$897;
	label$770:;
	#define vr$1083 ((FBSYMBOL$type**)(O$))
	TMP$140$ = (*(FBSYMBOL$type**)((ubyte *)vr$1083 + 64));
	label$897:;
	OPARAM$ = (TMP$140$);
	#define vr$1084 ((FBSYMBOL$type**)(VPARAM$))
	VPARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$1084 + 148));
	#define vr$1085 ((FBSYMBOL$type**)(OPARAM$))
	OPARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$1085 + 148));
	label$771:;
	if (VPARAM$ == (FBSYMBOL$type*)0) goto label$772;
	{
		#define vr$1086 ((FB_PARAMMODE*)(VPARAM$))
		#define vr$1087 ((FB_PARAMMODE*)(OPARAM$))
		#define vr$1088 ((integer)((-(*(FB_PARAMMODE*)((ubyte *)vr$1086 + 44) != *(FB_PARAMMODE*)((ubyte *)vr$1087 + 44)))))
		#define vr$1089 ((FB_DATATYPE*)(VPARAM$))
		#define vr$1090 ((FB_DATATYPE*)(OPARAM$))
		#define vr$1091 ((integer)((-(*(FB_DATATYPE*)((ubyte *)vr$1089 + 24) != *(FB_DATATYPE*)((ubyte *)vr$1090 + 24)))))
		#define vr$1092 ((integer)(vr$1088 | vr$1091))
		#define vr$1093 ((FBSYMBOL$type**)(VPARAM$))
		#define vr$1094 ((FBSYMBOL$type**)(OPARAM$))
		#define vr$1095 ((integer)((-(*(FBSYMBOL$type**)((ubyte *)vr$1093 + 28) != *(FBSYMBOL$type**)((ubyte *)vr$1094 + 28)))))
		#define vr$1096 ((integer)(vr$1092 | vr$1095))
		if (vr$1096 == (integer)0) goto label$774;
		{
			fb$result$ = ((integer)216);
			goto label$760;
		};
		label$774:;
		label$773:;
		#define vr$1097 ((FBSYMBOL$type**)(VPARAM$))
		VPARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$1097 + 148));
		#define vr$1098 ((FBSYMBOL$type**)(OPARAM$))
		OPARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$1098 + 148));
	};
	goto label$771;
	label$772:;
	fb$result$ = ((integer)0);
	label$760:;
	#define vr$1099 ((integer)(fb$result$))
	return vr$1099;
}

static char* HMANGLEFUNCTIONPTR( FBSYMBOL$type* PROC$, integer DTYPE$, FBSYMBOL$type* SUBTYPE$, integer ATTRIB$, integer MODE$ )
{
	char* fb$result$;
	static string ID$;
	integer I$;
	FBSYMBOL$type* PARAM$;
	#define vr$1100 ((char**)(&fb$result$))
	__builtin_memset( vr$1100, 0, (integer)4 );
	label$799:;
	fb_StrAssign( (string*)&ID$, (integer)-1, (char*)"{fbfp}(", (integer)8, (integer)0 );
	SYMBMANGLEINITABBREV(  );
	#define vr$1101 ((FBSYMBOL$type**)(PROC$))
	PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$1101 + 64));
	{
		integer TMP$142$;
		I$ = ((integer)0);
		#define vr$1102 ((short*)(PROC$))
		#define vr$1103 ((integer)(*(short*)((ubyte *)vr$1102 + 56)))
		#define vr$1104 ((integer)(vr$1103 + (integer)-1))
		TMP$142$ = (vr$1104);
		goto label$801;
		label$804:;
		{
			if (I$ <= (integer)0) goto label$806;
			{
				fb_StrConcatAssign( (string*)&ID$, (integer)-1, (char*)",", (integer)2, (integer)0 );
			};
			label$806:;
			label$805:;
			#define vr$1105 ((FBSYMBOL$type**)(PARAM$))
			if (*(FBSYMBOL$type**)((ubyte *)vr$1105 + 28) != (integer)0) goto label$808;
			{
				string TMP$145$;
				string TMP$146$;
				string TMP$147$;
				#define vr$1106 ((FB_PARAMMODE*)(PARAM$))
				#define vr$1107 ((integer)(*(FB_PARAMMODE*)((ubyte *)vr$1106 + 44)))
				string* vr$1108 = (string*)(fb_HEX_i( vr$1107 ));
				#define vr$1109 ((FB_DATATYPE*)(PARAM$))
				string* vr$1110 = (string*)(fb_HEX_i( *(FB_DATATYPE*)((ubyte *)vr$1109 + 24) ));
				#define vr$1111 ((string*)(&TMP$145$))
				__builtin_memset( vr$1111, 0, (integer)12 );
				#define vr$1112 ((string*)(&TMP$145$))
				string* vr$1113 = (string*)(fb_StrConcat( vr$1112, vr$1110, (integer)-1, (char*)"M", (integer)2 ));
				#define vr$1114 ((string*)(&TMP$146$))
				__builtin_memset( vr$1114, 0, (integer)12 );
				#define vr$1115 ((string*)(&TMP$146$))
				string* vr$1116 = (string*)(fb_StrConcat( vr$1115, vr$1113, (integer)-1, vr$1108, (integer)-1 ));
				#define vr$1117 ((string*)(&TMP$147$))
				__builtin_memset( vr$1117, 0, (integer)12 );
				#define vr$1118 ((string*)(&TMP$147$))
				string* vr$1119 = (string*)(fb_StrConcat( vr$1118, (string*)&ID$, (integer)-1, vr$1116, (integer)-1 ));
				fb_StrAssign( (string*)&ID$, (integer)-1, vr$1119, (integer)-1, (integer)0 );
			};
			goto label$807;
			label$808:;
			{
				SYMBMANGLEPARAM( (string*)&ID$, PARAM$ );
			};
			label$807:;
			#define vr$1120 ((FBSYMBOL$type**)(PARAM$))
			PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$1120 + 148));
		};
		label$802:;
		#define vr$1121 ((integer)(I$ + (integer)1))
		I$ = (vr$1121);
		label$801:;
		if (I$ <= TMP$142$) goto label$804;
		label$803:;
	};
	fb_StrConcatAssign( (string*)&ID$, (integer)-1, (char*)")", (integer)2, (integer)0 );
	if (SUBTYPE$ != (integer)0) goto label$810;
	{
		string* vr$1122 = (string*)(fb_HEX_i( DTYPE$ ));
		fb_StrConcatAssign( (string*)&ID$, (integer)-1, vr$1122, (integer)-1, (integer)0 );
	};
	goto label$809;
	label$810:;
	{
		SYMBMANGLETYPE( (string*)&ID$, DTYPE$, SUBTYPE$ );
	};
	label$809:;
	SYMBMANGLEENDABBREV(  );
	#define vr$1123 ((FB_SYMBATTRIB)(ATTRIB$ & (FB_SYMBATTRIB)33554432))
	if (vr$1123 == (FB_SYMBATTRIB)0) goto label$812;
	{
		fb_StrConcatAssign( (string*)&ID$, (integer)-1, (char*)"$", (integer)2, (integer)0 );
		fb_StrConcatAssign( (string*)&ID$, (integer)-1, (char*)"R", (integer)2, (integer)0 );
	};
	label$812:;
	label$811:;
	fb_StrConcatAssign( (string*)&ID$, (integer)-1, (char*)"$", (integer)2, (integer)0 );
	string* vr$1124 = (string*)(fb_HEX_i( MODE$ ));
	fb_StrConcatAssign( (string*)&ID$, (integer)-1, vr$1124, (integer)-1, (integer)0 );
	#define vr$1125 ((char**)((string*)&ID$))
	fb$result$ = (*(char**)((ubyte *)vr$1125));
	label$800:;
	#define vr$1126 ((char*)(fb$result$))
	return vr$1126;
}

static char* HDEMANGLEPARAMS( FBSYMBOL$type* PROC$ )
{
	char* fb$result$;
	static string RES$;
	FBSYMBOL$type* PARAM$;
	static char* PARAMMODETB$[4] = { (void*)(char*)"byval", (void*)(char*)"byref", (void*)(char*)"bydesc", (void*)(char*)"vararg" };
	typedef struct _TMP$152 {
		char** DATA;
		char** PTR;
		integer SIZE;
		integer ELEMENT_LEN;
		integer DIMENSIONS;
		__FB_ARRAYDIMTB$ DIMTB[1];
	} TMP$152;
	static TMP$152 tmp$151$ = { (void*)(char**)((ubyte *)&PARAMMODETB$ + -4), (void*)(char**)&PARAMMODETB$, 16, 4, 1, { { 4, 1, 4 } } };
	#define vr$1127 ((char**)(&fb$result$))
	__builtin_memset( vr$1127, 0, (integer)4 );
	label$813:;
	fb_StrAssign( (string*)&RES$, (integer)-1, (char*)"", (integer)1, (integer)0 );
	#define vr$1128 ((FBSYMBOL$type**)(PROC$))
	PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$1128 + 64));
	if (PARAM$ == (integer)0) goto label$816;
	{
		#define vr$1129 ((FB_SYMBATTRIB*)(PROC$))
		#define vr$1130 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$1129 + 4) & (FB_SYMBATTRIB)2048))
		if (vr$1130 == (integer)0) goto label$818;
		{
			#define vr$1131 ((FBSYMBOL$type**)(PARAM$))
			PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$1131 + 148));
		};
		label$818:;
		label$817:;
	};
	label$816:;
	label$815:;
	label$819:;
	if (PARAM$ == (integer)0) goto label$820;
	{
		{
			uinteger TMP$157$;
			#define vr$1132 ((FB_PARAMMODE*)(PARAM$))
			#define vr$1133 ((uinteger)(*(FB_PARAMMODE*)((ubyte *)vr$1132 + 44)))
			TMP$157$ = (vr$1133);
			goto label$822;
			label$823:;
			{
				string TMP$158$;
				string TMP$160$;
				#define vr$1134 ((FB_PARAMMODE*)(PARAM$))
				#define vr$1135 ((integer)(*(FB_PARAMMODE*)((ubyte *)vr$1134 + 44)))
				#define vr$1136 ((integer)(vr$1135 << (integer)2))
				#define vr$1137 ((string*)(&TMP$158$))
				__builtin_memset( vr$1137, 0, (integer)12 );
				#define vr$1138 ((string*)(&TMP$158$))
				string* vr$1139 = (string*)(fb_StrConcat( vr$1138, (string*)&RES$, (integer)-1, *(char**)((ubyte *)PARAMMODETB$ + vr$1136 + -4), (integer)0 ));
				fb_StrAssign( (string*)&RES$, (integer)-1, vr$1139, (integer)-1, (integer)0 );
				fb_StrConcatAssign( (string*)&RES$, (integer)-1, (char*)" as ", (integer)5, (integer)0 );
				#define vr$1140 ((FBSYMBOL$type**)(PARAM$))
				#define vr$1141 ((FB_DATATYPE*)(PARAM$))
				char* vr$1142 = (char*)(SYMBTYPETOSTR( *(FB_DATATYPE*)((ubyte *)vr$1141 + 24), *(FBSYMBOL$type**)((ubyte *)vr$1140 + 28), (integer)0 ));
				#define vr$1143 ((string*)(&TMP$160$))
				__builtin_memset( vr$1143, 0, (integer)12 );
				#define vr$1144 ((string*)(&TMP$160$))
				string* vr$1145 = (string*)(fb_StrConcat( vr$1144, (string*)&RES$, (integer)-1, vr$1142, (integer)0 ));
				fb_StrAssign( (string*)&RES$, (integer)-1, vr$1145, (integer)-1, (integer)0 );
			};
			goto label$821;
			label$824:;
			{
				fb_StrConcatAssign( (string*)&RES$, (integer)-1, (char*)"...", (integer)4, (integer)0 );
			};
			goto label$821;
			label$822:;
			if (TMP$157$ < (uinteger)1u) goto label$821;
			if (TMP$157$ > (uinteger)4u) goto label$821;
			static const void * LABEL$825$[] = {
				&&label$823,
				&&label$823,
				&&label$823,
				&&label$824,
			(void *)0 };
			#define vr$1146 ((uinteger)(TMP$157$ << (uinteger)2u))
			goto **(void**)((ubyte *)LABEL$825$ + vr$1146 + -4);
			label$821:;
		};
		#define vr$1147 ((FBSYMBOL$type**)(PARAM$))
		PARAM$ = (*(FBSYMBOL$type**)((ubyte *)vr$1147 + 148));
		if (PARAM$ == (integer)0) goto label$827;
		{
			fb_StrConcatAssign( (string*)&RES$, (integer)-1, (char*)", ", (integer)3, (integer)0 );
		};
		label$827:;
		label$826:;
	};
	goto label$819;
	label$820:;
	#define vr$1148 ((char**)((string*)&RES$))
	fb$result$ = (*(char**)((ubyte *)vr$1148));
	label$814:;
	#define vr$1149 ((char*)(fb$result$))
	return vr$1149;
}
// Total compilation time: 0.07109996047802269 seconds. 
