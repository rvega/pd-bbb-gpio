// Compilation of ast-node-uop.bas started at 13:35:35 on 07-04-2013
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
typedef int AST_NODECLASS;
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
typedef struct _ASTNODE ASTNODE$type;
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
typedef union _FBVALUE {
	FBSYMBOL$type* STR;
	integer INT;
	uinteger UINT;
	double FLOAT;
	longint LONG;
	ulongint ULONG;
} FBVALUE;
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
	typedef struct _FB_GLOBCTORLIST_ITEM FB_GLOBCTORLIST_ITEM$type;
	typedef struct _FB_GLOBCTORLIST_ITEM {
		FBSYMBOL$type* SYM;
		FB_GLOBCTORLIST_ITEM$type* NEXT;
	} FB_GLOBCTORLIST_ITEM;
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
		typedef int FB_ERRMSG;
	typedef int FB_DATACLASS;
	typedef int FB_LANG;
									typedef int FB_WARNINGMSG;
									typedef int FB_ERRMSGOPT;
	typedef int IR_OPT;
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
			typedef IRVREG$type* (*tmp$53)( integer, FBSYMBOL$type* );
		typedef void (*tmp$37)( integer, IRVREG$type*, IRVREG$type* );
typedef struct _TSTRSETITEM {
	string S;
	integer USERDATA;
} TSTRSETITEM;
static void _ZN11TSTRSETITEMC1Ev( TSTRSETITEM* );
static void _ZN11TSTRSETITEMaSERS_( TSTRSETITEM*, TSTRSETITEM* );
static void _ZN11TSTRSETITEMC1ERS_( TSTRSETITEM*, TSTRSETITEM* );
static void _ZN11TSTRSETITEMD1Ev( TSTRSETITEM* );
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
#define sinl( temp_ppparam$0 ) __builtin_sinl( temp_ppparam$0 )
#define asinl( temp_ppparam$0 ) __builtin_asinl( temp_ppparam$0 )
#define cosl( temp_ppparam$0 ) __builtin_cosl( temp_ppparam$0 )
#define acosl( temp_ppparam$0 ) __builtin_acosl( temp_ppparam$0 )
#define tanl( temp_ppparam$0 ) __builtin_tanl( temp_ppparam$0 )
#define atanl( temp_ppparam$0 ) __builtin_atanl( temp_ppparam$0 )
#define sqrtl( temp_ppparam$0 ) __builtin_sqrtl( temp_ppparam$0 )
#define logl( temp_ppparam$0 ) __builtin_logl( temp_ppparam$0 )
#define expl( temp_ppparam$0 ) __builtin_expl( temp_ppparam$0 )
#define floorl( temp_ppparam$0 ) __builtin_floorl( temp_ppparam$0 )
#define abs( temp_ppparam$0 ) __builtin_abs( temp_ppparam$0 )
#define llabs( temp_ppparam$0 ) __builtin_llabs( temp_ppparam$0 )
#define fabsl( temp_ppparam$0 ) __builtin_fabsl( temp_ppparam$0 )
integer fb_SGNi( integer );
integer fb_SGNl( longint );
integer fb_SGNDouble( double );
double fb_FIXDouble( double );
double fb_FRACd( double );
string* fb_StrAssign( void*, integer, void*, integer, integer );
void fb_StrDelete( string* );
static void fb_ctor__astznodezuop( void )__attribute__(( constructor )) ;
void ERRREPORTWARN( integer, char*, FB_ERRMSGOPT );
void ASTDELNODE( ASTNODE$type* );
longint ASTGETVALUEASLONGINT( ASTNODE$type* );
typedef int AST_CONVOPT;
ASTNODE$type* ASTNEWCONV( integer, FBSYMBOL$type*, ASTNODE$type*, AST_CONVOPT, integer* );
void ASTUPDATECONVFD2FS( ASTNODE$type*, integer, integer );
ASTNODE$type* ASTNEWBOP( integer, ASTNODE$type*, ASTNODE$type*, FBSYMBOL$type*, AST_OPOPT );
ASTNODE$type* ASTNEWCONSTI( integer, integer, FBSYMBOL$type* );
ASTNODE$type* ASTNEWNODE( integer, integer, FBSYMBOL$type* );
IRVREG$type* ASTLOAD( ASTNODE$type* );
ASTNODE$type* ASTBUILDCALL( FBSYMBOL$type*, ASTNODE$type*, ASTNODE$type*, ASTNODE$type* );
FBSYMBOL$type* SYMBFINDUOPOVLPROC( AST_OP, ASTNODE$type*, FB_ERRMSG* );
integer TYPETOSIGNED( integer );
ASTNODE$type* RTLMATHUOP( integer, ASTNODE$type* );
static ASTNODE$type* HUOPCONSTFOLDINT( integer, ASTNODE$type* );
static void HUOPCONSTFOLDFLT( integer, ASTNODE$type* );
static void HUOPCONSTFOLD64( integer, ASTNODE$type* );
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
typedef void (*tmp$30)( IRVREG$type*, IRVREG$type* );
typedef void (*tmp$31)( integer );
typedef void (*tmp$32)( FBSYMBOL$type*, FBSYMBOL$type* );
typedef void (*tmp$33)( FBSYMBOL$type*, FBSYMBOL$type*, FBSYMBOL$type* );
typedef void (*tmp$34)( IRVREG$type*, integer, integer );
typedef void (*tmp$35)( char* );
typedef void (*tmp$36)( integer, IRVREG$type*, IRVREG$type*, IRVREG$type*, FBSYMBOL$type* );
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
typedef int FB_LANG_OPT;
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

ASTNODE$type* ASTNEWUOP( integer OP$, ASTNODE$type* O$ )
{
	ASTNODE$type* fb$result$;
	ASTNODE$type* N$;
	integer DTYPE$;
	integer RANK$;
	integer INTRANK$;
	integer UINTRANK$;
	FBSYMBOL$type* SUBTYPE$;
	FB_DATATYPE TMP$82$;
	FB_DATATYPE TMP$87$;
	#define vr$0 ((ASTNODE$type**)(&fb$result$))
	__builtin_memset( vr$0, 0, (integer)4 );
	label$49:;
	fb$result$ = ((ASTNODE$type*)0);
	if (O$ != (integer)0) goto label$52;
	{
		goto label$50;
	};
	label$52:;
	label$51:;
	#define vr$1 ((integer)(OP$ << (integer)2))
	#define vr$2 ((SYMBCTX*)((SYMBCTX*)((ubyte *)(SYMBCTX*)((ubyte *)&SYMB$ + 1580) + vr$1)))
	if (*(FBSYMBOL$type**)((ubyte *)vr$2) == (integer)0) goto label$54;
	{
		FBSYMBOL$type* PROC$;
		FB_ERRMSG ERR_NUM$;
		#define vr$3 ((FB_ERRMSG*)(&ERR_NUM$))
		FBSYMBOL$type* vr$4 = (FBSYMBOL$type*)(SYMBFINDUOPOVLPROC( OP$, O$, vr$3 ));
		PROC$ = (vr$4);
		if (PROC$ == (integer)0) goto label$56;
		{
			ASTNODE$type* vr$5 = (ASTNODE$type*)(ASTBUILDCALL( PROC$, O$, (integer)0, (integer)0 ));
			fb$result$ = (vr$5);
			goto label$50;
		};
		goto label$55;
		label$56:;
		{
			if (ERR_NUM$ == (FB_ERRMSG)0) goto label$58;
			{
				goto label$50;
			};
			label$58:;
			label$57:;
		};
		label$55:;
	};
	label$54:;
	label$53:;
	if (OP$ != (AST_OP)73) goto label$60;
	{
		#define vr$6 ((FBSYMBOL$type**)(O$))
		#define vr$7 ((integer*)(O$))
		ASTNODE$type* vr$8 = (ASTNODE$type*)(ASTNEWNODE( (AST_NODECLASS)4, *(integer*)((ubyte *)vr$7 + 4), *(FBSYMBOL$type**)((ubyte *)vr$6 + 8) ));
		N$ = (vr$8);
		#define vr$9 ((ASTNODE$type**)(N$))
		*(ASTNODE$type**)((ubyte *)vr$9 + 56) = (O$);
		#define vr$10 ((ASTNODE$type**)(N$))
		*(ASTNODE$type**)((ubyte *)vr$10 + 60) = ((ASTNODE$type*)0);
		#define vr$11 ((integer*)(N$))
		*(integer*)((ubyte *)vr$11 + 20) = (OP$);
		#define vr$12 ((FBSYMBOL$type**)(N$))
		*(FBSYMBOL$type**)((ubyte *)vr$12 + 28) = ((FBSYMBOL$type*)0);
		#define vr$13 ((AST_OPOPT*)(N$))
		*(AST_OPOPT*)((ubyte *)vr$13 + 24) = ((AST_OPOPT)1);
		fb$result$ = (N$);
		goto label$50;
	};
	label$60:;
	label$59:;
	#define vr$14 ((integer*)(O$))
	#define vr$15 ((integer)(*(integer*)((ubyte *)vr$14 + 4) & (integer)480))
	if (vr$15 == (integer)0) goto label$61;
	TMP$82$ = ((FB_DATATYPE)23);
	goto label$160;
	label$61:;
	#define vr$16 ((integer*)(O$))
	#define vr$17 ((integer)(*(integer*)((ubyte *)vr$16 + 4) & (integer)31))
	#define vr$18 ((FB_DATATYPE)(vr$17))
	TMP$82$ = (vr$18);
	label$160:;
	#define vr$19 ((integer)(TMP$82$))
	#define vr$20 ((integer)(vr$19 * (integer)28))
	if (*(FB_DATACLASS*)((ubyte *)&SYMB_DTYPETB$ + vr$20) != (FB_DATACLASS)2) goto label$63;
	{
		goto label$50;
	};
	label$63:;
	label$62:;
	{
		FB_DATATYPE TMP$83$;
		uinteger TMP$84$;
		#define vr$21 ((integer*)(O$))
		#define vr$22 ((integer)(*(integer*)((ubyte *)vr$21 + 4) & (integer)480))
		if (vr$22 == (integer)0) goto label$64;
		TMP$83$ = ((FB_DATATYPE)23);
		goto label$161;
		label$64:;
		#define vr$23 ((integer*)(O$))
		#define vr$24 ((integer)(*(integer*)((ubyte *)vr$23 + 4) & (integer)31))
		#define vr$25 ((FB_DATATYPE)(vr$24))
		TMP$83$ = (vr$25);
		label$161:;
		#define vr$26 ((uinteger)(TMP$83$))
		TMP$84$ = (vr$26);
		goto label$66;
		label$67:;
		{
			#define vr$27 ((AST_NODECLASS*)(O$))
			#define vr$28 ((integer)((-(*(AST_NODECLASS*)((ubyte *)vr$27) == (AST_NODECLASS)20))))
			if (vr$28 != (integer)0) goto label$69;
			{
				goto label$50;
			};
			label$69:;
			label$68:;
		};
		goto label$65;
		label$70:;
		{
			#define vr$29 ((integer*)(O$))
			#define vr$30 ((integer)(*(integer*)((ubyte *)vr$29 + 4) & (integer)-512))
			ASTNODE$type* vr$31 = (ASTNODE$type*)(ASTNEWCONV( vr$30, (integer)0, O$, (integer)0, (integer)0 ));
			O$ = (vr$31);
			if (O$ != (integer)0) goto label$72;
			{
				goto label$50;
			};
			label$72:;
			label$71:;
		};
		goto label$65;
		label$73:;
		{
			#define vr$32 ((integer*)(O$))
			#define vr$33 ((integer)(*(integer*)((ubyte *)vr$32 + 4) & (integer)-512))
			#define vr$34 ((FB_DATATYPE)(vr$33 | (FB_DATATYPE)7))
			ASTNODE$type* vr$35 = (ASTNODE$type*)(ASTNEWCONV( vr$34, (integer)0, O$, (integer)0, (integer)0 ));
			O$ = (vr$35);
		};
		goto label$65;
		label$74:;
		{
			if (OP$ == (AST_OP)51) goto label$76;
			{
				goto label$50;
			};
			label$76:;
			label$75:;
		};
		goto label$65;
		label$66:;
		if (TMP$84$ < (uinteger)3u) goto label$65;
		if (TMP$84$ > (uinteger)23u) goto label$65;
		static const void * LABEL$77$[] = {
			&&label$67,
			&&label$65,
			&&label$65,
			&&label$67,
			&&label$65,
			&&label$65,
			&&label$73,
			&&label$65,
			&&label$65,
			&&label$65,
			&&label$65,
			&&label$65,
			&&label$65,
			&&label$65,
			&&label$65,
			&&label$65,
			&&label$70,
			&&label$65,
			&&label$65,
			&&label$65,
			&&label$74,
		(void *)0 };
		#define vr$36 ((uinteger)(TMP$84$ << (uinteger)2u))
		goto **(void**)((ubyte *)LABEL$77$ + vr$36 + -12);
		label$65:;
	};
	#define vr$37 ((integer)((-(*(FB_LANG*)((ubyte *)&ENV$ + 136) != (FB_LANG)3))))
	#define vr$38 ((integer*)(O$))
	#define vr$39 ((integer)(*(integer*)((ubyte *)vr$38 + 4) & (integer)480))
	if (vr$39 == (integer)0) goto label$78;
	TMP$87$ = ((FB_DATATYPE)23);
	goto label$162;
	label$78:;
	#define vr$40 ((integer*)(O$))
	#define vr$41 ((integer)(*(integer*)((ubyte *)vr$40 + 4) & (integer)31))
	#define vr$42 ((FB_DATATYPE)(vr$41))
	TMP$87$ = (vr$42);
	label$162:;
	#define vr$43 ((integer)(TMP$87$))
	#define vr$44 ((integer)(vr$43 * (integer)28))
	#define vr$45 ((integer)((-(*(FB_DATACLASS*)((ubyte *)&SYMB_DTYPETB$ + vr$44) == (FB_DATACLASS)0))))
	#define vr$46 ((integer)(vr$37 & vr$45))
	if (vr$46 == (integer)0) goto label$80;
	{
		FB_DATATYPE TMP$88$;
		FB_DATATYPE TMP$89$;
		FB_DATATYPE TMP$90$;
		#define vr$47 ((integer*)(O$))
		#define vr$48 ((integer)(*(integer*)((ubyte *)vr$47 + 4) & (integer)480))
		if (vr$48 == (integer)0) goto label$81;
		TMP$88$ = ((FB_DATATYPE)23);
		goto label$163;
		label$81:;
		#define vr$49 ((integer*)(O$))
		#define vr$50 ((integer)(*(integer*)((ubyte *)vr$49 + 4) & (integer)31))
		#define vr$51 ((FB_DATATYPE)(vr$50))
		TMP$88$ = (vr$51);
		label$163:;
		#define vr$52 ((integer)(TMP$88$))
		#define vr$53 ((integer)(vr$52 * (integer)28))
		#define vr$54 ((FB_DATATYPE)(*(FB_DATATYPE*)((ubyte *)&SYMB_DTYPETB$ + vr$53 + 20) & (integer)480))
		if (vr$54 == (FB_DATATYPE)0) goto label$83;
		TMP$90$ = ((FB_DATATYPE)23);
		goto label$164;
		label$83:;
		#define vr$55 ((integer*)(O$))
		#define vr$56 ((integer)(*(integer*)((ubyte *)vr$55 + 4) & (integer)480))
		if (vr$56 == (integer)0) goto label$82;
		TMP$89$ = ((FB_DATATYPE)23);
		goto label$165;
		label$82:;
		#define vr$57 ((integer*)(O$))
		#define vr$58 ((integer)(*(integer*)((ubyte *)vr$57 + 4) & (integer)31))
		#define vr$59 ((FB_DATATYPE)(vr$58))
		TMP$89$ = (vr$59);
		label$165:;
		#define vr$60 ((integer)(TMP$89$))
		#define vr$61 ((integer)(vr$60 * (integer)28))
		#define vr$62 ((FB_DATATYPE)(*(FB_DATATYPE*)((ubyte *)&SYMB_DTYPETB$ + vr$61 + 20) & (integer)31))
		TMP$90$ = (vr$62);
		label$164:;
		#define vr$63 ((integer)(TMP$90$))
		#define vr$64 ((integer)(vr$63 * (integer)28))
		RANK$ = (*(integer*)((ubyte *)&SYMB_DTYPETB$ + vr$64 + 16));
		INTRANK$ = (*(integer*)((ubyte *)&SYMB_DTYPETB$ + 212));
		UINTRANK$ = (*(integer*)((ubyte *)&SYMB_DTYPETB$ + 240));
		if (RANK$ >= INTRANK$) goto label$85;
		{
			#define vr$65 ((integer*)(O$))
			#define vr$66 ((integer)(*(integer*)((ubyte *)vr$65 + 4) & (integer)-512))
			#define vr$67 ((FB_DATATYPE)(vr$66 | (FB_DATATYPE)7))
			ASTNODE$type* vr$68 = (ASTNODE$type*)(ASTNEWCONV( vr$67, (integer)0, O$, (integer)0, (integer)0 ));
			O$ = (vr$68);
		};
		goto label$84;
		label$85:;
		{
			#define vr$69 ((integer)((-(INTRANK$ < RANK$))))
			#define vr$70 ((integer)((-(RANK$ < UINTRANK$))))
			#define vr$71 ((integer)(vr$69 & vr$70))
			if (vr$71 == (integer)0) goto label$87;
			{
				#define vr$72 ((integer*)(O$))
				#define vr$73 ((integer)(*(integer*)((ubyte *)vr$72 + 4) & (integer)-512))
				#define vr$74 ((FB_DATATYPE)(vr$73 | (FB_DATATYPE)8))
				ASTNODE$type* vr$75 = (ASTNODE$type*)(ASTNEWCONV( vr$74, (integer)0, O$, (integer)0, (integer)0 ));
				O$ = (vr$75);
			};
			label$87:;
			label$86:;
		};
		label$84:;
	};
	label$80:;
	label$79:;
	#define vr$76 ((integer*)(O$))
	DTYPE$ = (*(integer*)((ubyte *)vr$76 + 4));
	#define vr$77 ((FBSYMBOL$type**)(O$))
	SUBTYPE$ = (*(FBSYMBOL$type**)((ubyte *)vr$77 + 8));
	{
		uinteger TMP$91$;
		#define vr$78 ((uinteger)(OP$))
		TMP$91$ = (vr$78);
		goto label$89;
		label$90:;
		{
			FB_DATATYPE TMP$92$;
			#define vr$79 ((integer*)(O$))
			#define vr$80 ((integer)(*(integer*)((ubyte *)vr$79 + 4) & (integer)480))
			if (vr$80 == (integer)0) goto label$91;
			TMP$92$ = ((FB_DATATYPE)23);
			goto label$166;
			label$91:;
			#define vr$81 ((integer*)(O$))
			#define vr$82 ((integer)(*(integer*)((ubyte *)vr$81 + 4) & (integer)31))
			#define vr$83 ((FB_DATATYPE)(vr$82))
			TMP$92$ = (vr$83);
			label$166:;
			#define vr$84 ((integer)(TMP$92$))
			#define vr$85 ((integer)(vr$84 * (integer)28))
			if (*(FB_DATACLASS*)((ubyte *)&SYMB_DTYPETB$ + vr$85) == (FB_DATACLASS)0) goto label$93;
			{
				#define vr$86 ((integer*)(O$))
				#define vr$87 ((integer)(*(integer*)((ubyte *)vr$86 + 4) & (integer)-512))
				#define vr$88 ((FB_DATATYPE)(vr$87 | (FB_DATATYPE)7))
				ASTNODE$type* vr$89 = (ASTNODE$type*)(ASTNEWCONV( vr$88, (integer)0, O$, (integer)0, (integer)0 ));
				O$ = (vr$89);
				#define vr$90 ((integer*)(O$))
				DTYPE$ = (*(integer*)((ubyte *)vr$90 + 4));
				#define vr$91 ((FBSYMBOL$type**)(O$))
				SUBTYPE$ = (*(FBSYMBOL$type**)((ubyte *)vr$91 + 8));
			};
			label$93:;
			label$92:;
		};
		goto label$88;
		label$94:;
		{
			FB_DATATYPE TMP$93$;
			#define vr$92 ((integer*)(O$))
			#define vr$93 ((integer)(*(integer*)((ubyte *)vr$92 + 4) & (integer)480))
			if (vr$93 == (integer)0) goto label$95;
			TMP$93$ = ((FB_DATATYPE)23);
			goto label$167;
			label$95:;
			#define vr$94 ((integer*)(O$))
			#define vr$95 ((integer)(*(integer*)((ubyte *)vr$94 + 4) & (integer)31))
			#define vr$96 ((FB_DATATYPE)(vr$95))
			TMP$93$ = (vr$96);
			label$167:;
			#define vr$97 ((integer)(TMP$93$))
			#define vr$98 ((integer)(vr$97 * (integer)28))
			if (*(FB_DATACLASS*)((ubyte *)&SYMB_DTYPETB$ + vr$98) != (FB_DATACLASS)0) goto label$97;
			{
				integer vr$99 = (integer)(TYPETOSIGNED( DTYPE$ ));
				DTYPE$ = (vr$99);
			};
			label$97:;
			label$96:;
		};
		goto label$88;
		label$98:;
		{
			FB_DATATYPE TMP$94$;
			#define vr$100 ((integer*)(O$))
			#define vr$101 ((integer)(*(integer*)((ubyte *)vr$100 + 4) & (integer)480))
			if (vr$101 == (integer)0) goto label$99;
			TMP$94$ = ((FB_DATATYPE)23);
			goto label$168;
			label$99:;
			#define vr$102 ((integer*)(O$))
			#define vr$103 ((integer)(*(integer*)((ubyte *)vr$102 + 4) & (integer)31))
			#define vr$104 ((FB_DATATYPE)(vr$103))
			TMP$94$ = (vr$104);
			label$168:;
			#define vr$105 ((integer)(TMP$94$))
			#define vr$106 ((integer)(vr$105 * (integer)28))
			if (*(FB_DATACLASS*)((ubyte *)&SYMB_DTYPETB$ + vr$106) == (FB_DATACLASS)1) goto label$101;
			{
				#define vr$107 ((integer*)(O$))
				#define vr$108 ((integer)(*(integer*)((ubyte *)vr$107 + 4) & (integer)-512))
				#define vr$109 ((FB_DATATYPE)(vr$108 | (FB_DATATYPE)16))
				ASTNODE$type* vr$110 = (ASTNODE$type*)(ASTNEWCONV( vr$109, (integer)0, O$, (integer)0, (integer)0 ));
				O$ = (vr$110);
				#define vr$111 ((integer*)(O$))
				DTYPE$ = (*(integer*)((ubyte *)vr$111 + 4));
				#define vr$112 ((FBSYMBOL$type**)(O$))
				SUBTYPE$ = (*(FBSYMBOL$type**)((ubyte *)vr$112 + 8));
			};
			label$101:;
			label$100:;
		};
		goto label$88;
		label$102:;
		{
			FB_DATATYPE TMP$95$;
			#define vr$113 ((integer*)(O$))
			#define vr$114 ((integer)(*(integer*)((ubyte *)vr$113 + 4) & (integer)480))
			if (vr$114 == (integer)0) goto label$103;
			TMP$95$ = ((FB_DATATYPE)23);
			goto label$169;
			label$103:;
			#define vr$115 ((integer*)(O$))
			#define vr$116 ((integer)(*(integer*)((ubyte *)vr$115 + 4) & (integer)31))
			#define vr$117 ((FB_DATATYPE)(vr$116))
			TMP$95$ = (vr$117);
			label$169:;
			#define vr$118 ((integer)(TMP$95$))
			#define vr$119 ((integer)(vr$118 * (integer)28))
			if (*(FB_DATACLASS*)((ubyte *)&SYMB_DTYPETB$ + vr$119) != (FB_DATACLASS)0) goto label$105;
			{
				ASTNODE$type* vr$120 = (ASTNODE$type*)(ASTNEWCONSTI( (integer)0, DTYPE$, (integer)0 ));
				ASTNODE$type* vr$121 = (ASTNODE$type*)(ASTNEWBOP( (AST_OP)27, O$, vr$120, (integer)0, (AST_OPOPT)1 ));
				fb$result$ = (vr$121);
				goto label$50;
			};
			label$105:;
			label$104:;
		};
		goto label$88;
		label$106:;
		{
			FB_DATATYPE TMP$96$;
			#define vr$122 ((integer*)(O$))
			#define vr$123 ((integer)(*(integer*)((ubyte *)vr$122 + 4) & (integer)480))
			if (vr$123 == (integer)0) goto label$107;
			TMP$96$ = ((FB_DATATYPE)23);
			goto label$170;
			label$107:;
			#define vr$124 ((integer*)(O$))
			#define vr$125 ((integer)(*(integer*)((ubyte *)vr$124 + 4) & (integer)31))
			#define vr$126 ((FB_DATATYPE)(vr$125))
			TMP$96$ = (vr$126);
			label$170:;
			#define vr$127 ((integer)(TMP$96$))
			#define vr$128 ((integer)(vr$127 * (integer)28))
			if (*(FB_DATACLASS*)((ubyte *)&SYMB_DTYPETB$ + vr$128) != (FB_DATACLASS)0) goto label$109;
			{
				ASTNODE$type* vr$129 = (ASTNODE$type*)(ASTNEWCONSTI( (integer)0, DTYPE$, (integer)0 ));
				ASTNODE$type* vr$130 = (ASTNODE$type*)(ASTNEWBOP( (AST_OP)33, O$, vr$129, (integer)0, (AST_OPOPT)1 ));
				fb$result$ = (vr$130);
				goto label$50;
			};
			label$109:;
			label$108:;
		};
		goto label$88;
		label$110:;
		{
			fb$result$ = (O$);
			goto label$50;
		};
		goto label$88;
		label$89:;
		if (TMP$91$ < (uinteger)51u) goto label$88;
		if (TMP$91$ > (uinteger)71u) goto label$88;
		static const void * LABEL$111$[] = {
			&&label$90,
			&&label$110,
			&&label$88,
			&&label$88,
			&&label$88,
			&&label$94,
			&&label$98,
			&&label$98,
			&&label$98,
			&&label$98,
			&&label$98,
			&&label$98,
			&&label$88,
			&&label$98,
			&&label$88,
			&&label$88,
			&&label$98,
			&&label$98,
			&&label$102,
			&&label$102,
			&&label$106,
		(void *)0 };
		#define vr$131 ((uinteger)(TMP$91$ << (uinteger)2u))
		goto **(void**)((ubyte *)LABEL$111$ + vr$131 + -204);
		label$88:;
	};
	#define vr$132 ((AST_NODECLASS*)(O$))
	if (*(AST_NODECLASS*)((ubyte *)vr$132) != (AST_NODECLASS)16) goto label$113;
	{
		if (OP$ != (AST_OP)53) goto label$115;
		{
			FB_DATATYPE TMP$99$;
			#define vr$133 ((integer*)(O$))
			#define vr$134 ((integer)(*(integer*)((ubyte *)vr$133 + 4) & (integer)480))
			if (vr$134 == (integer)0) goto label$116;
			TMP$99$ = ((FB_DATATYPE)23);
			goto label$171;
			label$116:;
			#define vr$135 ((integer*)(O$))
			#define vr$136 ((integer)(*(integer*)((ubyte *)vr$135 + 4) & (integer)31))
			#define vr$137 ((FB_DATATYPE)(vr$136))
			TMP$99$ = (vr$137);
			label$171:;
			#define vr$138 ((integer)(TMP$99$))
			#define vr$139 ((integer)(vr$138 * (integer)28))
			if (*(FB_DATACLASS*)((ubyte *)&SYMB_DTYPETB$ + vr$139) != (FB_DATACLASS)0) goto label$118;
			{
				FB_DATATYPE TMP$100$;
				#define vr$140 ((integer*)(O$))
				#define vr$141 ((integer)(*(integer*)((ubyte *)vr$140 + 4) & (integer)480))
				if (vr$141 == (integer)0) goto label$119;
				TMP$100$ = ((FB_DATATYPE)23);
				goto label$172;
				label$119:;
				#define vr$142 ((integer*)(O$))
				#define vr$143 ((integer)(*(integer*)((ubyte *)vr$142 + 4) & (integer)31))
				#define vr$144 ((FB_DATATYPE)(vr$143))
				TMP$100$ = (vr$144);
				label$172:;
				#define vr$145 ((integer)(TMP$100$))
				#define vr$146 ((integer)(vr$145 * (integer)28))
				if (*(integer*)((ubyte *)&SYMB_DTYPETB$ + vr$146 + 12) != (integer)0) goto label$121;
				{
					{
						integer TMP$101$;
						#define vr$147 ((integer*)(O$))
						#define vr$148 ((integer)(*(integer*)((ubyte *)vr$147 + 4) & (integer)511))
						TMP$101$ = (vr$148);
						if (TMP$101$ != (FB_DATATYPE)8) goto label$123;
						label$124:;
						{
							label$125:;
							#define vr$149 ((integer*)(O$))
							#define vr$150 ((integer)(*(integer*)((ubyte *)vr$149 + 20) & (integer)-2147483648u))
							if (vr$150 == (integer)0) goto label$127;
							{
								#define vr$151 ((integer*)(O$))
								if (*(integer*)((ubyte *)vr$151 + 20) == (integer)-2147483648u) goto label$129;
								{
									ERRREPORTWARN( (FB_WARNINGMSG)5, (integer)0, (FB_ERRMSGOPT)1 );
								};
								label$129:;
								label$128:;
							};
							label$127:;
							label$126:;
						};
						goto label$122;
						label$123:;
						if (TMP$101$ != (FB_DATATYPE)14) goto label$130;
						label$131:;
						{
							label$132:;
							#define vr$152 ((longint*)(O$))
							#define vr$153 ((longint)(*(longint*)((ubyte *)vr$152 + 20) & (longint)-9223372036854775808ull))
							if (vr$153 == (longint)0ll) goto label$134;
							{
								#define vr$154 ((longint*)(O$))
								if (*(longint*)((ubyte *)vr$154 + 20) == (longint)-9223372036854775808ull) goto label$136;
								{
									ERRREPORTWARN( (FB_WARNINGMSG)5, (integer)0, (FB_ERRMSGOPT)1 );
								};
								label$136:;
								label$135:;
							};
							label$134:;
							label$133:;
						};
						goto label$122;
						label$130:;
						if (TMP$101$ != (FB_DATATYPE)12) goto label$137;
						label$138:;
						{
							{
								goto label$125;
							};
							goto label$139;
							label$140:;
							{
								goto label$132;
							};
							label$139:;
						};
						goto label$122;
						label$137:;
						{
							FB_DATATYPE TMP$102$;
							longint vr$155 = (longint)(ASTGETVALUEASLONGINT( O$ ));
							#define vr$156 ((longint)(-(vr$155)))
							#define vr$157 ((integer*)(O$))
							#define vr$158 ((integer)(*(integer*)((ubyte *)vr$157 + 4) & (integer)480))
							if (vr$158 == (integer)0) goto label$142;
							TMP$102$ = ((FB_DATATYPE)23);
							goto label$173;
							label$142:;
							#define vr$159 ((integer*)(O$))
							#define vr$160 ((integer)(*(integer*)((ubyte *)vr$159 + 4) & (integer)31))
							#define vr$161 ((FB_DATATYPE)(vr$160))
							TMP$102$ = (vr$161);
							label$173:;
							#define vr$162 ((integer)(TMP$102$))
							#define vr$163 ((integer)(vr$162 << (integer)3))
							if (vr$156 >= *(longint*)((ubyte *)AST_MINLIMITTB$ + vr$163 + -8)) goto label$144;
							{
								ERRREPORTWARN( (FB_WARNINGMSG)5, (integer)0, (FB_ERRMSGOPT)1 );
							};
							label$144:;
							label$143:;
						};
						label$141:;
						label$122:;
					};
					integer vr$164 = (integer)(TYPETOSIGNED( DTYPE$ ));
					DTYPE$ = (vr$164);
				};
				label$121:;
				label$120:;
			};
			label$118:;
			label$117:;
		};
		label$115:;
		label$114:;
		{
			uinteger TMP$103$;
			#define vr$165 ((integer*)(O$))
			#define vr$166 ((integer)(*(integer*)((ubyte *)vr$165 + 4) & (integer)511))
			#define vr$167 ((uinteger)(vr$166))
			TMP$103$ = (vr$167);
			goto label$146;
			label$147:;
			{
				HUOPCONSTFOLD64( OP$, O$ );
			};
			goto label$145;
			label$148:;
			{
				HUOPCONSTFOLDFLT( OP$, O$ );
			};
			goto label$145;
			label$149:;
			{
				{
					HUOPCONSTFOLDINT( OP$, O$ );
				};
				goto label$150;
				label$151:;
				{
					HUOPCONSTFOLD64( OP$, O$ );
				};
				label$150:;
			};
			goto label$145;
			label$152:;
			{
				HUOPCONSTFOLDINT( OP$, O$ );
			};
			goto label$145;
			label$146:;
			if (TMP$103$ < (uinteger)11u) goto label$152;
			if (TMP$103$ > (uinteger)16u) goto label$152;
			static const void * LABEL$153$[] = {
				&&label$149,
				&&label$149,
				&&label$147,
				&&label$147,
				&&label$148,
				&&label$148,
			(void *)0 };
			#define vr$168 ((uinteger)(TMP$103$ << (uinteger)2u))
			goto **(void**)((ubyte *)LABEL$153$ + vr$168 + -44);
			label$145:;
		};
		#define vr$169 ((integer*)(O$))
		*(integer*)((ubyte *)vr$169 + 4) = (DTYPE$);
		fb$result$ = (O$);
		goto label$50;
	};
	label$113:;
	label$112:;
	#define vr$170 ((IR_OPT)(*(IR_OPT*)((ubyte *)&IR$ + 292) & (IR_OPT)131072))
	if (vr$170 == (integer)0) goto label$155;
	{
		{
			uinteger TMP$106$;
			#define vr$171 ((uinteger)(OP$))
			TMP$106$ = (vr$171);
			goto label$157;
			label$158:;
			{
				ASTNODE$type* vr$172 = (ASTNODE$type*)(RTLMATHUOP( OP$, O$ ));
				fb$result$ = (vr$172);
				goto label$50;
			};
			goto label$156;
			label$157:;
			if (TMP$106$ < (uinteger)55u) goto label$156;
			if (TMP$106$ > (uinteger)71u) goto label$156;
			static const void * LABEL$159$[] = {
				&&label$158,
				&&label$158,
				&&label$158,
				&&label$158,
				&&label$158,
				&&label$158,
				&&label$158,
				&&label$158,
				&&label$156,
				&&label$158,
				&&label$156,
				&&label$156,
				&&label$158,
				&&label$158,
				&&label$158,
				&&label$158,
				&&label$158,
			(void *)0 };
			#define vr$173 ((uinteger)(TMP$106$ << (uinteger)2u))
			goto **(void**)((ubyte *)LABEL$159$ + vr$173 + -220);
			label$156:;
		};
	};
	label$155:;
	label$154:;
	ASTNODE$type* vr$174 = (ASTNODE$type*)(ASTNEWNODE( (AST_NODECLASS)4, DTYPE$, SUBTYPE$ ));
	N$ = (vr$174);
	#define vr$175 ((ASTNODE$type**)(N$))
	*(ASTNODE$type**)((ubyte *)vr$175 + 56) = (O$);
	#define vr$176 ((ASTNODE$type**)(N$))
	*(ASTNODE$type**)((ubyte *)vr$176 + 60) = ((ASTNODE$type*)0);
	#define vr$177 ((integer*)(N$))
	*(integer*)((ubyte *)vr$177 + 20) = (OP$);
	#define vr$178 ((FBSYMBOL$type**)(N$))
	*(FBSYMBOL$type**)((ubyte *)vr$178 + 28) = ((FBSYMBOL$type*)0);
	#define vr$179 ((AST_OPOPT*)(N$))
	*(AST_OPOPT*)((ubyte *)vr$179 + 24) = ((AST_OPOPT)1);
	fb$result$ = (N$);
	label$50:;
	#define vr$180 ((ASTNODE$type*)(fb$result$))
	return vr$180;
}

IRVREG$type* ASTLOADUOP( ASTNODE$type* N$ )
{
	IRVREG$type* fb$result$;
	ASTNODE$type* O$;
	integer OP$;
	IRVREG$type* V1$;
	IRVREG$type* VR$;
	#define vr$181 ((IRVREG$type**)(&fb$result$))
	__builtin_memset( vr$181, 0, (integer)4 );
	label$174:;
	#define vr$182 ((ASTNODE$type**)(N$))
	O$ = (*(ASTNODE$type**)((ubyte *)vr$182 + 56));
	#define vr$183 ((integer*)(N$))
	OP$ = (*(integer*)((ubyte *)vr$183 + 20));
	if (O$ != (integer)0) goto label$177;
	{
		fb$result$ = ((IRVREG$type*)0);
		goto label$175;
	};
	label$177:;
	label$176:;
	#define vr$184 ((AST_NODECLASS*)(O$))
	if (*(AST_NODECLASS*)((ubyte *)vr$184) != (AST_NODECLASS)5) goto label$179;
	{
		#define vr$185 ((integer*)(N$))
		ASTUPDATECONVFD2FS( O$, *(integer*)((ubyte *)vr$185 + 4), (integer)-1 );
	};
	label$179:;
	label$178:;
	IRVREG$type* vr$186 = (IRVREG$type*)(ASTLOAD( O$ ));
	V1$ = (vr$186);
	if (*(integer*)((ubyte *)&AST$ + 136) == (integer)0) goto label$181;
	{
		#define vr$187 ((AST_OPOPT*)(N$))
		#define vr$188 ((AST_OPOPT)(*(AST_OPOPT*)((ubyte *)vr$187 + 24) & (AST_OPOPT)1))
		if (vr$188 == (integer)0) goto label$183;
		{
			#define vr$189 ((FBSYMBOL$type**)(O$))
			#define vr$190 ((integer*)(O$))
			#define vr$191 ((integer)(*(integer*)((ubyte *)vr$190 + 4) & (integer)511))
			IRVREG$type* vr$192 = (IRVREG$type*)((*(tmp$53*)((ubyte *)&IR$ + 240))( vr$191, *(FBSYMBOL$type**)((ubyte *)vr$189 + 8) ));
			VR$ = (vr$192);
			#define vr$193 ((integer*)(N$))
			#define vr$194 ((integer*)(V1$))
			*(integer*)((ubyte *)vr$194 + 20) = (*(integer*)((ubyte *)vr$193 + 16));
			#define vr$195 ((integer*)(N$))
			#define vr$196 ((integer*)(VR$))
			*(integer*)((ubyte *)vr$196 + 20) = (*(integer*)((ubyte *)vr$195 + 16));
		};
		goto label$182;
		label$183:;
		{
			VR$ = ((IRVREG$type*)0);
			#define vr$197 ((integer*)(N$))
			#define vr$198 ((integer*)(V1$))
			*(integer*)((ubyte *)vr$198 + 20) = (*(integer*)((ubyte *)vr$197 + 16));
		};
		label$182:;
		(*(tmp$37*)((ubyte *)&IR$ + 108))( OP$, V1$, VR$ );
		if (VR$ != (integer)0) goto label$185;
		{
			VR$ = (V1$);
		};
		label$185:;
		label$184:;
	};
	label$181:;
	label$180:;
	ASTDELNODE( O$ );
	fb$result$ = (VR$);
	label$175:;
	#define vr$199 ((IRVREG$type*)(fb$result$))
	return vr$199;
}

__attribute__(( constructor )) static void fb_ctor__astznodezuop( void )
{
	label$0:;
	label$1:;
}

static void _ZN11TSTRSETITEMaSERS_( TSTRSETITEM* THIS$, TSTRSETITEM* __FB_RHS__$ )
{
	label$4:;
	fb_StrAssign( (TSTRSETITEM*)(THIS$), (integer)-1, (TSTRSETITEM*)(__FB_RHS__$), (integer)-1, (integer)0 );
	#define vr$200 ((integer*)((TSTRSETITEM*)(__FB_RHS__$)))
	#define vr$201 ((integer*)((TSTRSETITEM*)(THIS$)))
	*(integer*)((ubyte *)vr$201 + 12) = (*(integer*)((ubyte *)vr$200 + 12));
	label$5:;
}

static ASTNODE$type* HUOPCONSTFOLDINT( integer OP$, ASTNODE$type* V$ )
{
	ASTNODE$type* fb$result$;
	integer LDFULL$;
	FBSYMBOL$type* LSUBTYPE$;
	#define vr$202 ((ASTNODE$type**)(&fb$result$))
	__builtin_memset( vr$202, 0, (integer)4 );
	label$10:;
	{
		uinteger TMP$73$;
		#define vr$203 ((uinteger)(OP$))
		TMP$73$ = (vr$203);
		goto label$13;
		label$14:;
		{
			#define vr$204 ((integer*)(V$))
			#define vr$205 ((integer)(~(*(integer*)((ubyte *)vr$204 + 20))))
			#define vr$206 ((integer*)(V$))
			*(integer*)((ubyte *)vr$206 + 20) = (vr$205);
		};
		goto label$12;
		label$15:;
		{
			#define vr$207 ((integer*)(V$))
			#define vr$208 ((integer)(-(*(integer*)((ubyte *)vr$207 + 20))))
			#define vr$209 ((integer*)(V$))
			*(integer*)((ubyte *)vr$209 + 20) = (vr$208);
		};
		goto label$12;
		label$16:;
		{
			#define vr$210 ((integer*)(V$))
			integer vr$211 = (integer)(abs( *(integer*)((ubyte *)vr$210 + 20) ));
			#define vr$212 ((integer*)(V$))
			*(integer*)((ubyte *)vr$212 + 20) = (vr$211);
		};
		goto label$12;
		label$17:;
		{
			#define vr$213 ((integer*)(V$))
			integer vr$214 = (integer)(fb_SGNi( *(integer*)((ubyte *)vr$213 + 20) ));
			#define vr$215 ((integer*)(V$))
			*(integer*)((ubyte *)vr$215 + 20) = (vr$214);
		};
		goto label$12;
		label$13:;
		if (TMP$73$ < (uinteger)51u) goto label$12;
		if (TMP$73$ > (uinteger)56u) goto label$12;
		static const void * LABEL$18$[] = {
			&&label$14,
			&&label$12,
			&&label$15,
			&&label$12,
			&&label$16,
			&&label$17,
		(void *)0 };
		#define vr$216 ((uinteger)(TMP$73$ << (uinteger)2u))
		goto **(void**)((ubyte *)LABEL$18$ + vr$216 + -204);
		label$12:;
	};
	#define vr$217 ((integer*)(V$))
	LDFULL$ = (*(integer*)((ubyte *)vr$217 + 4));
	#define vr$218 ((FBSYMBOL$type**)(V$))
	LSUBTYPE$ = (*(FBSYMBOL$type**)((ubyte *)vr$218 + 8));
	#define vr$219 ((integer*)(V$))
	*(integer*)((ubyte *)vr$219 + 4) = ((integer)7);
	#define vr$220 ((FBSYMBOL$type**)(V$))
	*(FBSYMBOL$type**)((ubyte *)vr$220 + 8) = ((FBSYMBOL$type*)0);
	ASTNODE$type* vr$221 = (ASTNODE$type*)(ASTNEWCONV( LDFULL$, LSUBTYPE$, V$, (integer)0, (integer)0 ));
	fb$result$ = (vr$221);
	label$11:;
	#define vr$222 ((ASTNODE$type*)(fb$result$))
	return vr$222;
}

static void HUOPCONSTFOLDFLT( integer OP$, ASTNODE$type* V$ )
{
	label$19:;
	{
		static uinteger TMP$76$;
		#define vr$223 ((uinteger)(OP$))
		TMP$76$ = (vr$223);
		goto label$22;
		label$23:;
		{
			#define vr$224 ((double*)(V$))
			integer vr$225 = (integer)(fb_dtosi( *(double*)((ubyte *)vr$224 + 20) ));
			#define vr$226 ((integer)(~(vr$225)))
			#define vr$227 ((integer*)(V$))
			*(integer*)((ubyte *)vr$227 + 20) = (vr$226);
		};
		goto label$21;
		label$24:;
		{
			#define vr$228 ((double*)(V$))
			#define vr$229 ((double)(-(*(double*)((ubyte *)vr$228 + 20))))
			#define vr$230 ((double*)(V$))
			*(double*)((ubyte *)vr$230 + 20) = (vr$229);
		};
		goto label$21;
		label$25:;
		{
			#define vr$231 ((double*)(V$))
			double vr$232 = (double)(fabsl( *(double*)((ubyte *)vr$231 + 20) ));
			#define vr$233 ((double*)(V$))
			*(double*)((ubyte *)vr$233 + 20) = (vr$232);
		};
		goto label$21;
		label$26:;
		{
			#define vr$234 ((double*)(V$))
			integer vr$235 = (integer)(fb_SGNDouble( *(double*)((ubyte *)vr$234 + 20) ));
			#define vr$236 ((double)(vr$235))
			#define vr$237 ((double*)(V$))
			*(double*)((ubyte *)vr$237 + 20) = (vr$236);
		};
		goto label$21;
		label$27:;
		{
			#define vr$238 ((double*)(V$))
			double vr$239 = (double)(sinl( *(double*)((ubyte *)vr$238 + 20) ));
			#define vr$240 ((double*)(V$))
			*(double*)((ubyte *)vr$240 + 20) = (vr$239);
		};
		goto label$21;
		label$28:;
		{
			#define vr$241 ((double*)(V$))
			double vr$242 = (double)(asinl( *(double*)((ubyte *)vr$241 + 20) ));
			#define vr$243 ((double*)(V$))
			*(double*)((ubyte *)vr$243 + 20) = (vr$242);
		};
		goto label$21;
		label$29:;
		{
			#define vr$244 ((double*)(V$))
			double vr$245 = (double)(cosl( *(double*)((ubyte *)vr$244 + 20) ));
			#define vr$246 ((double*)(V$))
			*(double*)((ubyte *)vr$246 + 20) = (vr$245);
		};
		goto label$21;
		label$30:;
		{
			#define vr$247 ((double*)(V$))
			double vr$248 = (double)(acosl( *(double*)((ubyte *)vr$247 + 20) ));
			#define vr$249 ((double*)(V$))
			*(double*)((ubyte *)vr$249 + 20) = (vr$248);
		};
		goto label$21;
		label$31:;
		{
			#define vr$250 ((double*)(V$))
			double vr$251 = (double)(tanl( *(double*)((ubyte *)vr$250 + 20) ));
			#define vr$252 ((double*)(V$))
			*(double*)((ubyte *)vr$252 + 20) = (vr$251);
		};
		goto label$21;
		label$32:;
		{
			#define vr$253 ((double*)(V$))
			double vr$254 = (double)(atanl( *(double*)((ubyte *)vr$253 + 20) ));
			#define vr$255 ((double*)(V$))
			*(double*)((ubyte *)vr$255 + 20) = (vr$254);
		};
		goto label$21;
		label$33:;
		{
			#define vr$256 ((double*)(V$))
			double vr$257 = (double)(sqrtl( *(double*)((ubyte *)vr$256 + 20) ));
			#define vr$258 ((double*)(V$))
			*(double*)((ubyte *)vr$258 + 20) = (vr$257);
		};
		goto label$21;
		label$34:;
		{
			#define vr$259 ((double*)(V$))
			double vr$260 = (double)(logl( *(double*)((ubyte *)vr$259 + 20) ));
			#define vr$261 ((double*)(V$))
			*(double*)((ubyte *)vr$261 + 20) = (vr$260);
		};
		goto label$21;
		label$35:;
		{
			#define vr$262 ((double*)(V$))
			double vr$263 = (double)(expl( *(double*)((ubyte *)vr$262 + 20) ));
			#define vr$264 ((double*)(V$))
			*(double*)((ubyte *)vr$264 + 20) = (vr$263);
		};
		goto label$21;
		label$36:;
		{
			#define vr$265 ((double*)(V$))
			double vr$266 = (double)(floorl( *(double*)((ubyte *)vr$265 + 20) ));
			#define vr$267 ((double*)(V$))
			*(double*)((ubyte *)vr$267 + 20) = (vr$266);
		};
		goto label$21;
		label$37:;
		{
			#define vr$268 ((double*)(V$))
			double vr$269 = (double)(fb_FIXDouble( *(double*)((ubyte *)vr$268 + 20) ));
			#define vr$270 ((double*)(V$))
			*(double*)((ubyte *)vr$270 + 20) = (vr$269);
		};
		goto label$21;
		label$38:;
		{
			#define vr$271 ((double*)(V$))
			double vr$272 = (double)(fb_FRACd( *(double*)((ubyte *)vr$271 + 20) ));
			#define vr$273 ((double*)(V$))
			*(double*)((ubyte *)vr$273 + 20) = (vr$272);
		};
		goto label$21;
		label$22:;
		if (TMP$76$ < (uinteger)51u) goto label$21;
		if (TMP$76$ > (uinteger)71u) goto label$21;
		static const void * LABEL$39$[] = {
			&&label$23,
			&&label$21,
			&&label$24,
			&&label$21,
			&&label$25,
			&&label$26,
			&&label$27,
			&&label$28,
			&&label$29,
			&&label$30,
			&&label$31,
			&&label$32,
			&&label$21,
			&&label$33,
			&&label$21,
			&&label$21,
			&&label$34,
			&&label$35,
			&&label$36,
			&&label$37,
			&&label$38,
		(void *)0 };
		#define vr$274 ((uinteger)(TMP$76$ << (uinteger)2u))
		goto **(void**)((ubyte *)LABEL$39$ + vr$274 + -204);
		label$21:;
	};
	label$20:;
}

static void HUOPCONSTFOLD64( integer OP$, ASTNODE$type* V$ )
{
	label$40:;
	{
		static uinteger TMP$79$;
		#define vr$275 ((uinteger)(OP$))
		TMP$79$ = (vr$275);
		goto label$43;
		label$44:;
		{
			#define vr$276 ((longint*)(V$))
			#define vr$277 ((longint)(~(*(longint*)((ubyte *)vr$276 + 20))))
			#define vr$278 ((longint*)(V$))
			*(longint*)((ubyte *)vr$278 + 20) = (vr$277);
		};
		goto label$42;
		label$45:;
		{
			#define vr$279 ((longint*)(V$))
			#define vr$280 ((longint)(-(*(longint*)((ubyte *)vr$279 + 20))))
			#define vr$281 ((longint*)(V$))
			*(longint*)((ubyte *)vr$281 + 20) = (vr$280);
		};
		goto label$42;
		label$46:;
		{
			#define vr$282 ((longint*)(V$))
			longint vr$283 = (longint)(llabs( *(longint*)((ubyte *)vr$282 + 20) ));
			#define vr$284 ((longint*)(V$))
			*(longint*)((ubyte *)vr$284 + 20) = (vr$283);
		};
		goto label$42;
		label$47:;
		{
			#define vr$285 ((longint*)(V$))
			integer vr$286 = (integer)(fb_SGNl( *(longint*)((ubyte *)vr$285 + 20) ));
			#define vr$287 ((longint)(vr$286))
			#define vr$288 ((longint*)(V$))
			*(longint*)((ubyte *)vr$288 + 20) = (vr$287);
		};
		goto label$42;
		label$43:;
		if (TMP$79$ < (uinteger)51u) goto label$42;
		if (TMP$79$ > (uinteger)56u) goto label$42;
		static const void * LABEL$48$[] = {
			&&label$44,
			&&label$42,
			&&label$45,
			&&label$42,
			&&label$46,
			&&label$47,
		(void *)0 };
		#define vr$289 ((uinteger)(TMP$79$ << (uinteger)2u))
		goto **(void**)((ubyte *)LABEL$48$ + vr$289 + -204);
		label$42:;
	};
	label$41:;
}
// Total compilation time: 0.0453649926930666 seconds. 
