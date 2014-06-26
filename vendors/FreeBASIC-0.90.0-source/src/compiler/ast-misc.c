// Compilation of ast-misc.bas started at 13:35:33 on 07-04-2013
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
	typedef struct _AST_DTORLIST_SCOPESTACK {
		integer* COOKIES;
		integer COUNT;
		integer ROOM;
	} AST_DTORLIST_SCOPESTACK;
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
	typedef int FB_DATATYPE;
typedef int AST_NODECLASS;
typedef int FB_SYMBCLASS;
typedef int FB_SYMBATTRIB;
typedef int FB_SYMBSTATS;
typedef struct _FB_SYMBID {
	char* NAME;
	char* ALIAS;
	char* MANGLED;
} FB_SYMBID;
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
					typedef int FB_DATACLASS;
		typedef int FB_WARNINGMSG;
		typedef int FB_ERRMSGOPT;
			typedef int FB_ERRMSG;
							typedef int IR_OPT;
	typedef struct _AST_DTORLIST_ITEM {
		FBSYMBOL$type* SYM;
		integer COOKIE;
		integer REFCOUNT;
	} AST_DTORLIST_ITEM;
typedef struct _TSTRSETITEM {
	string S;
	integer USERDATA;
} TSTRSETITEM;
static void _ZN11TSTRSETITEMC1Ev( TSTRSETITEM* );
static void _ZN11TSTRSETITEMaSERS_( TSTRSETITEM*, TSTRSETITEM* );
static void _ZN11TSTRSETITEMC1ERS_( TSTRSETITEM*, TSTRSETITEM* );
static void _ZN11TSTRSETITEMD1Ev( TSTRSETITEM* );
static inline longint fb_dtosl ( double value ) {
/* 	volatile longint result;
	__asm__ (
		"fldl %1;"
		"fistpq %0;"
		:"=m" (result)
		:"m" (value)
	);
	return result; */
  return (longint) value;
}
#define fabsl( temp_ppparam$0 ) __builtin_fabsl( temp_ppparam$0 )
void free( void* );
string* fb_StrAssign( void*, integer, void*, integer, integer );
void fb_StrDelete( string* );
string* fb_StrConcat( string*, void*, integer, void*, integer );
static void fb_ctor__astzmisc( void )__attribute__(( constructor )) ;
void* XREALLOCATE( void*, long );
void LISTINIT( TLIST*, integer, integer, LIST_FLAGS );
void LISTEND( TLIST* );
void* LISTNEWNODE( TLIST* );
void LISTDELNODE( TLIST*, void* );
void* LISTGETHEAD( TLIST* );
void* LISTGETTAIL( TLIST* );
void* LISTGETPREV( void* );
void ERRREPORT( integer, integer, char* );
void ERRREPORTWARN( integer, char*, FB_ERRMSGOPT );
void ASTDELNODE( ASTNODE$type* );
integer ASTISTREEEQUAL( ASTNODE$type*, ASTNODE$type* );
longint ASTGETVALUEASLONGINT( ASTNODE$type* );
double ASTGETVALUEASDOUBLE( ASTNODE$type* );
ASTNODE$type* ASTNEWNOP( void );
ASTNODE$type* ASTNEWBOP( integer, ASTNODE$type*, ASTNODE$type*, FBSYMBOL$type*, AST_OPOPT );
integer ASTCONSTISZERO( ASTNODE$type* );
ASTNODE$type* ASTNEWCONSTZ( integer, FBSYMBOL$type* );
ASTNODE$type* ASTNEWVAR( FBSYMBOL$type*, integer, integer, FBSYMBOL$type* );
ASTNODE$type* ASTNEWBRANCH( integer, FBSYMBOL$type*, ASTNODE$type* );
ASTNODE$type* ASTNEWLINK( ASTNODE$type*, ASTNODE$type*, integer );
ASTNODE$type* ASTOPTIMIZETREE( ASTNODE$type* );
ASTNODE$type* ASTUPDSTRCONCAT( ASTNODE$type* );
ASTNODE$type* ASTISCLASSONTREE( integer, ASTNODE$type* );
integer ASTISSYMBOLONTREE( FBSYMBOL$type*, ASTNODE$type* );
ASTNODE$type* ASTTYPEINIUPDATE( ASTNODE$type* );
integer ASTGETINVERSELOGOP( integer );
ASTNODE$type* _Z17ASTBUILDVARASSIGNP8FBSYMBOLP7ASTNODE( FBSYMBOL$type*, ASTNODE$type* );
ASTNODE$type* ASTBUILDCALL( FBSYMBOL$type*, ASTNODE$type*, ASTNODE$type*, ASTNODE$type* );
ASTNODE$type* ASTBUILDVARDTORCALL( FBSYMBOL$type*, integer );
void ASTREPLACESYMBOLONTREE( ASTNODE$type*, FBSYMBOL$type*, FBSYMBOL$type* );
void ASTREPLACEFWDREF( ASTNODE$type*, FBSYMBOL$type*, integer, FBSYMBOL$type* );
ASTNODE$type* ASTDTORLISTFLUSH( integer );
void ASTSETTYPE( ASTNODE$type*, integer, FBSYMBOL$type* );
integer ASTISACCESSTOLOCAL( ASTNODE$type* );
FBSYMBOL$type* SYMBFINDCASTOVLPROC( integer, FBSYMBOL$type*, ASTNODE$type*, FB_ERRMSG* );
FBSYMBOL$type* SYMBADDTEMPVAR( integer, FBSYMBOL$type* );
integer SYMBCALCLEN( integer, FBSYMBOL$type* );
integer SYMBISEQUAL( FBSYMBOL$type*, FBSYMBOL$type* );
integer SYMBHASDTOR( FBSYMBOL$type* );
integer TYPEREMAP( integer, FBSYMBOL$type* );
integer TYPEMERGE( integer, integer );
FBSYMBOL$type* SYMBGETCOMPOPOVLHEAD( FBSYMBOL$type*, AST_OP );
ASTNODE$type* RTLSTRCONCAT( ASTNODE$type*, integer, ASTNODE$type*, integer );
ASTNODE$type* RTLWSTRCONCAT( ASTNODE$type*, integer, ASTNODE$type*, integer );
void ASTREPLACESYMBOLONCALL( ASTNODE$type*, FBSYMBOL$type*, FBSYMBOL$type* );
static integer HHASDTOR( FBSYMBOL$type* );
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
ulongint AST_MAXLIMITTB$[14] = { 127ull, 255ull, 255ull, 32767ull, 65535ull, 65535ull, 2147483647ull, 4294967295ull, 2147483647ull, 4294967295ull, 2147483647ull, 4294967295ull, 9223372036854775807ull, 18446744073709551615ull };
extern longint AST_MINLIMITTB$[14];
longint AST_MINLIMITTB$[14] = { -128ll, 0ll, 0ll, -32768ll, 0ll, 0ll, -2147483648ll, 0ll, -2147483648ll, 0ll, -2147483648ll, 0ll, -9223372036854775808ull, 0ll };
typedef int AST_OPFLAGS;
typedef struct _AST_OPINFO {
	AST_NODECLASS CLASS;
	AST_OPFLAGS FLAGS;
	char* ID;
	AST_OP SELFOP;
} AST_OPINFO;
extern AST_OPINFO AST_OPTB$[114];
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

void ASTMISCINIT( void )
{
	AST_DTORLIST_SCOPESTACK* TMP$73$;
	label$10:;
	#define vr$0 ((TLIST*)(&*(TLIST*)((ubyte *)&AST$ + 148)))
	LISTINIT( vr$0, (integer)64, (integer)12, (LIST_FLAGS)6 );
	#define vr$1 ((AST_DTORLIST_SCOPESTACK*)(&*(AST_DTORLIST_SCOPESTACK*)((ubyte *)&AST$ + 180)))
	TMP$73$ = (vr$1);
	#define vr$2 ((integer**)(TMP$73$))
	*(integer**)((ubyte *)vr$2) = ((integer*)0);
	#define vr$3 ((integer*)(TMP$73$))
	*(integer*)((ubyte *)vr$3 + 4) = ((integer)0);
	#define vr$4 ((integer*)(TMP$73$))
	*(integer*)((ubyte *)vr$4 + 8) = ((integer)0);
	*(integer*)((ubyte *)&AST$ + 192) = ((integer)0);
	*(integer*)((ubyte *)&AST$ + 196) = ((integer)-1);
	#define vr$5 ((integer)(*(FB_DATATYPE*)((ubyte *)&ENV$ + 208)))
	#define vr$6 ((integer)(vr$5 << (integer)3))
	*(longint*)((ubyte *)AST_MINLIMITTB$ + 40) = (*(longint*)((ubyte *)AST_MINLIMITTB$ + vr$6 + -8));
	#define vr$7 ((integer)(*(FB_DATATYPE*)((ubyte *)&ENV$ + 208)))
	#define vr$8 ((integer)(vr$7 << (integer)3))
	*(ulongint*)((ubyte *)AST_MAXLIMITTB$ + 40) = (*(ulongint*)((ubyte *)AST_MAXLIMITTB$ + vr$8 + -8));
	label$11:;
}

void ASTMISCEND( void )
{
	AST_DTORLIST_SCOPESTACK* TMP$74$;
	label$12:;
	#define vr$9 ((AST_DTORLIST_SCOPESTACK*)(&*(AST_DTORLIST_SCOPESTACK*)((ubyte *)&AST$ + 180)))
	TMP$74$ = (vr$9);
	#define vr$10 ((integer**)(TMP$74$))
	free( *(integer**)((ubyte *)vr$10) );
	#define vr$11 ((TLIST*)(&*(TLIST*)((ubyte *)&AST$ + 148)))
	LISTEND( vr$11 );
	label$13:;
}

integer ASTISTREEEQUAL( ASTNODE$type* L$, ASTNODE$type* R$ )
{
	integer fb$result$;
	#define vr$12 ((integer*)(&fb$result$))
	__builtin_memset( vr$12, 0, (integer)4 );
	label$14:;
	fb$result$ = ((integer)0);
	#define vr$13 ((integer)((-(L$ == (integer)0))))
	#define vr$14 ((integer)((-(R$ == (integer)0))))
	#define vr$15 ((integer)(vr$13 | vr$14))
	if (vr$15 == (integer)0) goto label$17;
	{
		if (L$ != R$) goto label$19;
		{
			fb$result$ = ((integer)-1);
		};
		label$19:;
		label$18:;
		goto label$15;
	};
	label$17:;
	label$16:;
	#define vr$16 ((AST_NODECLASS*)(L$))
	#define vr$17 ((AST_NODECLASS*)(R$))
	if (*(AST_NODECLASS*)((ubyte *)vr$16) == *(AST_NODECLASS*)((ubyte *)vr$17)) goto label$21;
	{
		goto label$15;
	};
	label$21:;
	label$20:;
	#define vr$18 ((integer*)(L$))
	#define vr$19 ((integer*)(R$))
	if (*(integer*)((ubyte *)vr$18 + 4) == *(integer*)((ubyte *)vr$19 + 4)) goto label$23;
	{
		goto label$15;
	};
	label$23:;
	label$22:;
	#define vr$20 ((FBSYMBOL$type**)(L$))
	#define vr$21 ((FBSYMBOL$type**)(R$))
	if (*(FBSYMBOL$type**)((ubyte *)vr$20 + 8) == *(FBSYMBOL$type**)((ubyte *)vr$21 + 8)) goto label$25;
	{
		goto label$15;
	};
	label$25:;
	label$24:;
	{
		uinteger TMP$75$;
		#define vr$22 ((AST_NODECLASS*)(L$))
		#define vr$23 ((uinteger)(*(AST_NODECLASS*)((ubyte *)vr$22)))
		TMP$75$ = (vr$23);
		goto label$27;
		label$28:;
		{
			#define vr$24 ((FBSYMBOL$type**)(L$))
			#define vr$25 ((FBSYMBOL$type**)(R$))
			if (*(FBSYMBOL$type**)((ubyte *)vr$24 + 12) == *(FBSYMBOL$type**)((ubyte *)vr$25 + 12)) goto label$30;
			{
				goto label$15;
			};
			label$30:;
			label$29:;
			#define vr$26 ((integer*)(L$))
			#define vr$27 ((integer*)(R$))
			if (*(integer*)((ubyte *)vr$26 + 20) == *(integer*)((ubyte *)vr$27 + 20)) goto label$32;
			{
				goto label$15;
			};
			label$32:;
			label$31:;
		};
		goto label$26;
		label$33:;
		{
			#define vr$28 ((FBSYMBOL$type**)(L$))
			#define vr$29 ((FBSYMBOL$type**)(R$))
			if (*(FBSYMBOL$type**)((ubyte *)vr$28 + 12) == *(FBSYMBOL$type**)((ubyte *)vr$29 + 12)) goto label$35;
			{
				goto label$15;
			};
			label$35:;
			label$34:;
		};
		goto label$26;
		label$36:;
		{
			{
				uinteger TMP$76$;
				#define vr$30 ((integer*)(L$))
				#define vr$31 ((integer)(*(integer*)((ubyte *)vr$30 + 4) & (integer)511))
				#define vr$32 ((uinteger)(vr$31))
				TMP$76$ = (vr$32);
				goto label$38;
				label$39:;
				{
					#define vr$33 ((longint*)(L$))
					#define vr$34 ((longint*)(R$))
					if (*(longint*)((ubyte *)vr$33 + 20) == *(longint*)((ubyte *)vr$34 + 20)) goto label$41;
					{
						goto label$15;
					};
					label$41:;
					label$40:;
				};
				goto label$37;
				label$42:;
				{
					#define vr$35 ((double*)(L$))
					#define vr$36 ((double*)(R$))
					if (*(double*)((ubyte *)vr$35 + 20) == *(double*)((ubyte *)vr$36 + 20)) goto label$44;
					{
						goto label$15;
					};
					label$44:;
					label$43:;
				};
				goto label$37;
				label$45:;
				{
					{
						#define vr$37 ((integer*)(L$))
						#define vr$38 ((integer*)(R$))
						if (*(integer*)((ubyte *)vr$37 + 20) == *(integer*)((ubyte *)vr$38 + 20)) goto label$49;
						{
							goto label$15;
						};
						label$49:;
						label$48:;
					};
					goto label$46;
					label$47:;
					{
						#define vr$39 ((longint*)(L$))
						#define vr$40 ((longint*)(R$))
						if (*(longint*)((ubyte *)vr$39 + 20) == *(longint*)((ubyte *)vr$40 + 20)) goto label$51;
						{
							goto label$15;
						};
						label$51:;
						label$50:;
					};
					label$46:;
				};
				goto label$37;
				label$52:;
				{
					#define vr$41 ((integer*)(L$))
					#define vr$42 ((integer*)(R$))
					if (*(integer*)((ubyte *)vr$41 + 20) == *(integer*)((ubyte *)vr$42 + 20)) goto label$54;
					{
						goto label$15;
					};
					label$54:;
					label$53:;
				};
				goto label$37;
				label$38:;
				if (TMP$76$ < (uinteger)11u) goto label$52;
				if (TMP$76$ > (uinteger)16u) goto label$52;
				static const void * LABEL$55$[] = {
					&&label$45,
					&&label$45,
					&&label$39,
					&&label$39,
					&&label$42,
					&&label$42,
				(void *)0 };
				#define vr$43 ((uinteger)(TMP$76$ << (uinteger)2u))
				goto **(void**)((ubyte *)LABEL$55$ + vr$43 + -44);
				label$37:;
			};
		};
		goto label$26;
		label$56:;
		{
			#define vr$44 ((integer*)(L$))
			#define vr$45 ((integer*)(R$))
			if (*(integer*)((ubyte *)vr$44 + 20) == *(integer*)((ubyte *)vr$45 + 20)) goto label$58;
			{
				goto label$15;
			};
			label$58:;
			label$57:;
		};
		goto label$26;
		label$59:;
		{
			#define vr$46 ((integer*)(L$))
			#define vr$47 ((integer*)(R$))
			if (*(integer*)((ubyte *)vr$46 + 20) == *(integer*)((ubyte *)vr$47 + 20)) goto label$61;
			{
				goto label$15;
			};
			label$61:;
			label$60:;
			#define vr$48 ((integer*)(L$))
			#define vr$49 ((integer*)(R$))
			if (*(integer*)((ubyte *)vr$48 + 24) == *(integer*)((ubyte *)vr$49 + 24)) goto label$63;
			{
				goto label$15;
			};
			label$63:;
			label$62:;
		};
		goto label$26;
		label$64:;
		{
			#define vr$50 ((integer*)(L$))
			#define vr$51 ((integer*)(R$))
			if (*(integer*)((ubyte *)vr$50 + 20) == *(integer*)((ubyte *)vr$51 + 20)) goto label$66;
			{
				goto label$15;
			};
			label$66:;
			label$65:;
			#define vr$52 ((AST_OPOPT*)(L$))
			#define vr$53 ((AST_OPOPT*)(R$))
			if (*(AST_OPOPT*)((ubyte *)vr$52 + 24) == *(AST_OPOPT*)((ubyte *)vr$53 + 24)) goto label$68;
			{
				goto label$15;
			};
			label$68:;
			label$67:;
			#define vr$54 ((FBSYMBOL$type**)(L$))
			#define vr$55 ((FBSYMBOL$type**)(R$))
			if (*(FBSYMBOL$type**)((ubyte *)vr$54 + 28) == *(FBSYMBOL$type**)((ubyte *)vr$55 + 28)) goto label$70;
			{
				goto label$15;
			};
			label$70:;
			label$69:;
		};
		goto label$26;
		label$71:;
		{
			#define vr$56 ((integer*)(L$))
			#define vr$57 ((integer*)(R$))
			if (*(integer*)((ubyte *)vr$56 + 20) == *(integer*)((ubyte *)vr$57 + 20)) goto label$73;
			{
				goto label$15;
			};
			label$73:;
			label$72:;
			#define vr$58 ((AST_OPOPT*)(L$))
			#define vr$59 ((AST_OPOPT*)(R$))
			if (*(AST_OPOPT*)((ubyte *)vr$58 + 24) == *(AST_OPOPT*)((ubyte *)vr$59 + 24)) goto label$75;
			{
				goto label$15;
			};
			label$75:;
			label$74:;
		};
		goto label$26;
		label$76:;
		{
			#define vr$60 ((FBSYMBOL$type**)(L$))
			#define vr$61 ((FBSYMBOL$type**)(R$))
			if (*(FBSYMBOL$type**)((ubyte *)vr$60 + 12) == *(FBSYMBOL$type**)((ubyte *)vr$61 + 12)) goto label$78;
			{
				goto label$15;
			};
			label$78:;
			label$77:;
			#define vr$62 ((integer*)(L$))
			#define vr$63 ((integer*)(R$))
			if (*(integer*)((ubyte *)vr$62 + 20) == *(integer*)((ubyte *)vr$63 + 20)) goto label$80;
			{
				goto label$15;
			};
			label$80:;
			label$79:;
		};
		goto label$26;
		label$81:;
		{
			#define vr$64 ((FBSYMBOL$type**)(L$))
			#define vr$65 ((FBSYMBOL$type**)(R$))
			if (*(FBSYMBOL$type**)((ubyte *)vr$64 + 12) == *(FBSYMBOL$type**)((ubyte *)vr$65 + 12)) goto label$83;
			{
				goto label$15;
			};
			label$83:;
			label$82:;
			#define vr$66 ((integer*)(L$))
			#define vr$67 ((integer*)(R$))
			if (*(integer*)((ubyte *)vr$66 + 20) == *(integer*)((ubyte *)vr$67 + 20)) goto label$85;
			{
				goto label$15;
			};
			label$85:;
			label$84:;
		};
		goto label$26;
		label$86:;
		{
		};
		goto label$26;
		label$87:;
		{
			goto label$15;
		};
		goto label$26;
		label$27:;
		if (TMP$75$ < (uinteger)1u) goto label$26;
		if (TMP$75$ > (uinteger)23u) goto label$26;
		static const void * LABEL$88$[] = {
			&&label$87,
			&&label$87,
			&&label$64,
			&&label$71,
			&&label$86,
			&&label$76,
			&&label$87,
			&&label$26,
			&&label$87,
			&&label$26,
			&&label$26,
			&&label$26,
			&&label$26,
			&&label$26,
			&&label$87,
			&&label$36,
			&&label$28,
			&&label$59,
			&&label$33,
			&&label$56,
			&&label$26,
			&&label$26,
			&&label$81,
		(void *)0 };
		#define vr$68 ((uinteger)(TMP$75$ << (uinteger)2u))
		goto **(void**)((ubyte *)LABEL$88$ + vr$68 + -4);
		label$26:;
	};
	#define vr$69 ((ASTNODE$type**)(R$))
	#define vr$70 ((ASTNODE$type**)(L$))
	integer vr$71 = (integer)(ASTISTREEEQUAL( *(ASTNODE$type**)((ubyte *)vr$70 + 56), *(ASTNODE$type**)((ubyte *)vr$69 + 56) ));
	if (vr$71 != (integer)0) goto label$90;
	{
		goto label$15;
	};
	label$90:;
	label$89:;
	#define vr$72 ((ASTNODE$type**)(R$))
	#define vr$73 ((ASTNODE$type**)(L$))
	integer vr$74 = (integer)(ASTISTREEEQUAL( *(ASTNODE$type**)((ubyte *)vr$73 + 60), *(ASTNODE$type**)((ubyte *)vr$72 + 60) ));
	if (vr$74 != (integer)0) goto label$92;
	{
		goto label$15;
	};
	label$92:;
	label$91:;
	fb$result$ = ((integer)-1);
	label$15:;
	#define vr$75 ((integer)(fb$result$))
	return vr$75;
}

ASTNODE$type* ASTISCLASSONTREE( integer CLASS_$, ASTNODE$type* N$ )
{
	ASTNODE$type* fb$result$;
	ASTNODE$type* M$;
	#define vr$76 ((ASTNODE$type**)(&fb$result$))
	__builtin_memset( vr$76, 0, (integer)4 );
	label$93:;
	if (N$ != (integer)0) goto label$96;
	{
		fb$result$ = ((ASTNODE$type*)0);
		goto label$94;
	};
	label$96:;
	label$95:;
	#define vr$77 ((AST_NODECLASS*)(N$))
	if (*(AST_NODECLASS*)((ubyte *)vr$77) != CLASS_$) goto label$98;
	{
		fb$result$ = (N$);
		goto label$94;
	};
	label$98:;
	label$97:;
	#define vr$78 ((ASTNODE$type**)(N$))
	ASTNODE$type* vr$79 = (ASTNODE$type*)(ASTISCLASSONTREE( CLASS_$, *(ASTNODE$type**)((ubyte *)vr$78 + 56) ));
	M$ = (vr$79);
	if (M$ == (integer)0) goto label$100;
	{
		fb$result$ = (M$);
		goto label$94;
	};
	label$100:;
	label$99:;
	#define vr$80 ((ASTNODE$type**)(N$))
	ASTNODE$type* vr$81 = (ASTNODE$type*)(ASTISCLASSONTREE( CLASS_$, *(ASTNODE$type**)((ubyte *)vr$80 + 60) ));
	M$ = (vr$81);
	if (M$ == (integer)0) goto label$102;
	{
		fb$result$ = (M$);
		goto label$94;
	};
	label$102:;
	label$101:;
	fb$result$ = ((ASTNODE$type*)0);
	label$94:;
	#define vr$82 ((ASTNODE$type*)(fb$result$))
	return vr$82;
}

integer ASTISSYMBOLONTREE( FBSYMBOL$type* SYM$, ASTNODE$type* N$ )
{
	integer fb$result$;
	FBSYMBOL$type* S$;
	#define vr$83 ((integer*)(&fb$result$))
	__builtin_memset( vr$83, 0, (integer)4 );
	label$103:;
	if (N$ != (integer)0) goto label$106;
	{
		fb$result$ = ((integer)0);
		goto label$104;
	};
	label$106:;
	label$105:;
	{
		uinteger TMP$81$;
		#define vr$84 ((AST_NODECLASS*)(N$))
		#define vr$85 ((uinteger)(*(AST_NODECLASS*)((ubyte *)vr$84)))
		TMP$81$ = (vr$85);
		goto label$108;
		label$109:;
		{
			#define vr$86 ((FBSYMBOL$type**)(N$))
			S$ = (*(FBSYMBOL$type**)((ubyte *)vr$86 + 12));
			if (S$ != SYM$) goto label$111;
			{
				fb$result$ = ((integer)-1);
				goto label$104;
			};
			label$111:;
			label$110:;
			if (S$ == (integer)0) goto label$113;
			{
				#define vr$87 ((FB_SYMBATTRIB*)(S$))
				#define vr$88 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$87 + 4) & (FB_SYMBATTRIB)327680))
				if (vr$88 == (integer)0) goto label$115;
				{
					fb$result$ = ((integer)-1);
					goto label$104;
				};
				label$115:;
				label$114:;
			};
			label$113:;
			label$112:;
		};
		goto label$107;
		label$116:;
		{
			fb$result$ = ((integer)-1);
			goto label$104;
		};
		goto label$107;
		label$108:;
		if (TMP$81$ < (uinteger)6u) goto label$107;
		if (TMP$81$ > (uinteger)23u) goto label$107;
		static const void * LABEL$117$[] = {
			&&label$109,
			&&label$107,
			&&label$107,
			&&label$107,
			&&label$107,
			&&label$107,
			&&label$107,
			&&label$107,
			&&label$107,
			&&label$107,
			&&label$107,
			&&label$109,
			&&label$109,
			&&label$109,
			&&label$116,
			&&label$107,
			&&label$107,
			&&label$109,
		(void *)0 };
		#define vr$89 ((uinteger)(TMP$81$ << (uinteger)2u))
		goto **(void**)((ubyte *)LABEL$117$ + vr$89 + -24);
		label$107:;
	};
	#define vr$90 ((ASTNODE$type**)(N$))
	if (*(ASTNODE$type**)((ubyte *)vr$90 + 56) == (integer)0) goto label$119;
	{
		#define vr$91 ((ASTNODE$type**)(N$))
		integer vr$92 = (integer)(ASTISSYMBOLONTREE( SYM$, *(ASTNODE$type**)((ubyte *)vr$91 + 56) ));
		if (vr$92 == (integer)0) goto label$121;
		{
			fb$result$ = ((integer)-1);
			goto label$104;
		};
		label$121:;
		label$120:;
	};
	label$119:;
	label$118:;
	#define vr$93 ((ASTNODE$type**)(N$))
	if (*(ASTNODE$type**)((ubyte *)vr$93 + 60) == (integer)0) goto label$123;
	{
		#define vr$94 ((ASTNODE$type**)(N$))
		integer vr$95 = (integer)(ASTISSYMBOLONTREE( SYM$, *(ASTNODE$type**)((ubyte *)vr$94 + 60) ));
		if (vr$95 == (integer)0) goto label$125;
		{
			fb$result$ = ((integer)-1);
			goto label$104;
		};
		label$125:;
		label$124:;
	};
	label$123:;
	label$122:;
	fb$result$ = ((integer)0);
	label$104:;
	#define vr$96 ((integer)(fb$result$))
	return vr$96;
}

void ASTREPLACESYMBOLONTREE( ASTNODE$type* N$, FBSYMBOL$type* OLD_SYM$, FBSYMBOL$type* NEW_SYM$ )
{
	label$126:;
	if (N$ != (integer)0) goto label$129;
	{
		goto label$127;
	};
	label$129:;
	label$128:;
	#define vr$97 ((FBSYMBOL$type**)(N$))
	if (*(FBSYMBOL$type**)((ubyte *)vr$97 + 12) != OLD_SYM$) goto label$131;
	{
		#define vr$98 ((FBSYMBOL$type**)(N$))
		*(FBSYMBOL$type**)((ubyte *)vr$98 + 12) = (NEW_SYM$);
	};
	label$131:;
	label$130:;
	{
		uinteger TMP$84$;
		#define vr$99 ((AST_NODECLASS*)(N$))
		#define vr$100 ((uinteger)(*(AST_NODECLASS*)((ubyte *)vr$99)))
		TMP$84$ = (vr$100);
		goto label$133;
		label$134:;
		{
			#define vr$101 ((FBSYMBOL$type**)(N$))
			if (*(FBSYMBOL$type**)((ubyte *)vr$101 + 28) != OLD_SYM$) goto label$136;
			{
				#define vr$102 ((FBSYMBOL$type**)(N$))
				*(FBSYMBOL$type**)((ubyte *)vr$102 + 28) = (NEW_SYM$);
			};
			label$136:;
			label$135:;
		};
		goto label$132;
		label$137:;
		{
			#define vr$103 ((FBSYMBOL$type**)(N$))
			if (*(FBSYMBOL$type**)((ubyte *)vr$103 + 20) != OLD_SYM$) goto label$139;
			{
				#define vr$104 ((FBSYMBOL$type**)(N$))
				*(FBSYMBOL$type**)((ubyte *)vr$104 + 20) = (NEW_SYM$);
			};
			label$139:;
			label$138:;
		};
		goto label$132;
		label$140:;
		{
			ASTREPLACESYMBOLONCALL( N$, OLD_SYM$, NEW_SYM$ );
		};
		goto label$132;
		label$133:;
		if (TMP$84$ < (uinteger)3u) goto label$132;
		if (TMP$84$ > (uinteger)26u) goto label$132;
		static const void * LABEL$141$[] = {
			&&label$134,
			&&label$134,
			&&label$132,
			&&label$132,
			&&label$134,
			&&label$132,
			&&label$140,
			&&label$132,
			&&label$132,
			&&label$132,
			&&label$134,
			&&label$132,
			&&label$132,
			&&label$132,
			&&label$132,
			&&label$132,
			&&label$132,
			&&label$132,
			&&label$132,
			&&label$132,
			&&label$132,
			&&label$132,
			&&label$132,
			&&label$137,
		(void *)0 };
		#define vr$105 ((uinteger)(TMP$84$ << (uinteger)2u))
		goto **(void**)((ubyte *)LABEL$141$ + vr$105 + -12);
		label$132:;
	};
	#define vr$106 ((ASTNODE$type**)(N$))
	if (*(ASTNODE$type**)((ubyte *)vr$106 + 56) == (integer)0) goto label$143;
	{
		#define vr$107 ((ASTNODE$type**)(N$))
		ASTREPLACESYMBOLONTREE( *(ASTNODE$type**)((ubyte *)vr$107 + 56), OLD_SYM$, NEW_SYM$ );
	};
	label$143:;
	label$142:;
	#define vr$108 ((ASTNODE$type**)(N$))
	if (*(ASTNODE$type**)((ubyte *)vr$108 + 60) == (integer)0) goto label$145;
	{
		#define vr$109 ((ASTNODE$type**)(N$))
		ASTREPLACESYMBOLONTREE( *(ASTNODE$type**)((ubyte *)vr$109 + 60), OLD_SYM$, NEW_SYM$ );
	};
	label$145:;
	label$144:;
	label$127:;
}

void ASTREPLACEFWDREF( ASTNODE$type* N$, FBSYMBOL$type* OLDSUBTYPE$, integer NEWDTYPE$, FBSYMBOL$type* NEWSUBTYPE$ )
{
	label$146:;
	#define vr$110 ((integer*)(N$))
	#define vr$111 ((integer)(*(integer*)((ubyte *)vr$110 + 4) & (integer)31))
	#define vr$112 ((integer)((-(vr$111 == (FB_DATATYPE)22))))
	#define vr$113 ((FBSYMBOL$type**)(N$))
	#define vr$114 ((integer)((-(*(FBSYMBOL$type**)((ubyte *)vr$113 + 8) == OLDSUBTYPE$))))
	#define vr$115 ((integer)(vr$112 & vr$114))
	if (vr$115 == (integer)0) goto label$149;
	{
		#define vr$116 ((integer*)(N$))
		integer vr$117 = (integer)(TYPEMERGE( *(integer*)((ubyte *)vr$116 + 4), NEWDTYPE$ ));
		#define vr$118 ((integer*)(N$))
		*(integer*)((ubyte *)vr$118 + 4) = (vr$117);
		#define vr$119 ((FBSYMBOL$type**)(N$))
		*(FBSYMBOL$type**)((ubyte *)vr$119 + 8) = (NEWSUBTYPE$);
	};
	label$149:;
	label$148:;
	#define vr$120 ((ASTNODE$type**)(N$))
	if (*(ASTNODE$type**)((ubyte *)vr$120 + 56) == (ASTNODE$type*)0) goto label$151;
	{
		#define vr$121 ((ASTNODE$type**)(N$))
		ASTREPLACEFWDREF( *(ASTNODE$type**)((ubyte *)vr$121 + 56), OLDSUBTYPE$, NEWDTYPE$, NEWSUBTYPE$ );
	};
	label$151:;
	label$150:;
	#define vr$122 ((ASTNODE$type**)(N$))
	if (*(ASTNODE$type**)((ubyte *)vr$122 + 60) == (ASTNODE$type*)0) goto label$153;
	{
		#define vr$123 ((ASTNODE$type**)(N$))
		ASTREPLACEFWDREF( *(ASTNODE$type**)((ubyte *)vr$123 + 60), OLDSUBTYPE$, NEWDTYPE$, NEWSUBTYPE$ );
	};
	label$153:;
	label$152:;
	label$147:;
}

integer ASTISCONSTANT( ASTNODE$type* EXPR$ )
{
	integer fb$result$;
	#define vr$124 ((integer*)(&fb$result$))
	__builtin_memset( vr$124, 0, (integer)4 );
	label$154:;
	#define vr$125 ((FBSYMBOL$type**)(EXPR$))
	if (*(FBSYMBOL$type**)((ubyte *)vr$125 + 12) == (FBSYMBOL$type*)0) goto label$157;
	{
		#define vr$126 ((FBSYMBOL$type**)(EXPR$))
		#define vr$127 ((FB_SYMBATTRIB*)(*(FBSYMBOL$type**)((ubyte *)vr$126 + 12)))
		#define vr$128 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$127 + 4) & (FB_SYMBATTRIB)1048576))
		if (vr$128 == (integer)0) goto label$159;
		{
			fb$result$ = ((integer)-1);
			goto label$155;
		};
		label$159:;
		label$158:;
	};
	label$157:;
	label$156:;
	#define vr$129 ((AST_NODECLASS*)(EXPR$))
	#define vr$130 ((integer)((-(*(AST_NODECLASS*)((ubyte *)vr$129) == (AST_NODECLASS)16))))
	#define vr$131 ((integer*)(EXPR$))
	#define vr$132 ((integer)(*(integer*)((ubyte *)vr$131 + 4) & (integer)512))
	#define vr$133 ((integer)((-(vr$132 != (integer)0))))
	#define vr$134 ((integer)(vr$130 | vr$133))
	fb$result$ = (vr$134);
	goto label$155;
	label$155:;
	#define vr$135 ((integer)(fb$result$))
	return vr$135;
}

longint ASTGETVALUEASLONGINT( ASTNODE$type* N$ )
{
	longint fb$result$;
	#define vr$136 ((longint*)(&fb$result$))
	__builtin_memset( vr$136, 0, (integer)8 );
	label$160:;
	{
		uinteger TMP$87$;
		#define vr$137 ((integer*)(N$))
		#define vr$138 ((integer)(*(integer*)((ubyte *)vr$137 + 4) & (integer)511))
		#define vr$139 ((uinteger)(vr$138))
		TMP$87$ = (vr$139);
		goto label$163;
		label$164:;
		{
			#define vr$140 ((longint*)(N$))
			fb$result$ = (*(longint*)((ubyte *)vr$140 + 20));
		};
		goto label$162;
		label$165:;
		{
			#define vr$141 ((double*)(N$))
			longint vr$142 = (longint)(fb_dtosl( *(double*)((ubyte *)vr$141 + 20) ));
			fb$result$ = (vr$142);
		};
		goto label$162;
		label$166:;
		{
			{
				#define vr$143 ((integer*)(N$))
				#define vr$144 ((integer)(*(integer*)((ubyte *)vr$143 + 4) & (integer)511))
				if (vr$144 != (FB_DATATYPE)11) goto label$170;
				{
					#define vr$145 ((integer*)(N$))
					#define vr$146 ((longint)(*(integer*)((ubyte *)vr$145 + 20)))
					fb$result$ = (vr$146);
				};
				goto label$169;
				label$170:;
				{
					#define vr$147 ((integer*)(N$))
					#define vr$148 ((uinteger)(*(integer*)((ubyte *)vr$147 + 20)))
					#define vr$149 ((longint)(vr$148))
					fb$result$ = (vr$149);
				};
				label$169:;
			};
			goto label$167;
			label$168:;
			{
				#define vr$150 ((longint*)(N$))
				fb$result$ = (*(longint*)((ubyte *)vr$150 + 20));
			};
			label$167:;
		};
		goto label$162;
		label$171:;
		{
			FB_DATATYPE TMP$88$;
			#define vr$151 ((integer*)(N$))
			#define vr$152 ((integer)(*(integer*)((ubyte *)vr$151 + 4) & (integer)511))
			#define vr$153 ((integer)(vr$152 & (integer)480))
			if (vr$153 == (integer)0) goto label$172;
			TMP$88$ = ((FB_DATATYPE)23);
			goto label$176;
			label$172:;
			#define vr$154 ((integer*)(N$))
			#define vr$155 ((integer)(*(integer*)((ubyte *)vr$154 + 4) & (integer)511))
			#define vr$156 ((integer)(vr$155 & (integer)31))
			#define vr$157 ((FB_DATATYPE)(vr$156))
			TMP$88$ = (vr$157);
			label$176:;
			#define vr$158 ((integer)(TMP$88$))
			#define vr$159 ((integer)(vr$158 * (integer)28))
			if (*(integer*)((ubyte *)&SYMB_DTYPETB$ + vr$159 + 12) == (integer)0) goto label$174;
			{
				#define vr$160 ((integer*)(N$))
				#define vr$161 ((longint)(*(integer*)((ubyte *)vr$160 + 20)))
				fb$result$ = (vr$161);
			};
			goto label$173;
			label$174:;
			{
				#define vr$162 ((integer*)(N$))
				#define vr$163 ((uinteger)(*(integer*)((ubyte *)vr$162 + 20)))
				#define vr$164 ((longint)(vr$163))
				fb$result$ = (vr$164);
			};
			label$173:;
		};
		goto label$162;
		label$163:;
		if (TMP$87$ < (uinteger)11u) goto label$171;
		if (TMP$87$ > (uinteger)16u) goto label$171;
		static const void * LABEL$175$[] = {
			&&label$166,
			&&label$166,
			&&label$164,
			&&label$164,
			&&label$165,
			&&label$165,
		(void *)0 };
		#define vr$165 ((uinteger)(TMP$87$ << (uinteger)2u))
		goto **(void**)((ubyte *)LABEL$175$ + vr$165 + -44);
		label$162:;
	};
	label$161:;
	#define vr$166 ((longint)(fb$result$))
	return vr$166;
}

double ASTGETVALUEASDOUBLE( ASTNODE$type* N$ )
{
	double fb$result$;
	#define vr$167 ((double*)(&fb$result$))
	__builtin_memset( vr$167, 0, (integer)8 );
	label$177:;
	{
		uinteger TMP$91$;
		#define vr$168 ((integer*)(N$))
		#define vr$169 ((integer)(*(integer*)((ubyte *)vr$168 + 4) & (integer)511))
		#define vr$170 ((uinteger)(vr$169))
		TMP$91$ = (vr$170);
		goto label$180;
		label$181:;
		{
			#define vr$171 ((longint*)(N$))
			#define vr$172 ((ulongint)(*(longint*)((ubyte *)vr$171 + 20)))
			#define vr$173 ((double)(vr$172))
			fb$result$ = (vr$173);
		};
		goto label$179;
		label$182:;
		{
			#define vr$174 ((longint*)(N$))
			#define vr$175 ((double)(*(longint*)((ubyte *)vr$174 + 20)))
			fb$result$ = (vr$175);
		};
		goto label$179;
		label$183:;
		{
			#define vr$176 ((double*)(N$))
			fb$result$ = (*(double*)((ubyte *)vr$176 + 20));
		};
		goto label$179;
		label$184:;
		{
			{
				#define vr$177 ((longint*)(N$))
				#define vr$178 ((ulongint)(*(longint*)((ubyte *)vr$177 + 20)))
				#define vr$179 ((double)(vr$178))
				fb$result$ = (vr$179);
			};
			goto label$185;
			label$186:;
			{
				#define vr$180 ((integer*)(N$))
				#define vr$181 ((uinteger)(*(integer*)((ubyte *)vr$180 + 20)))
				#define vr$182 ((double)(vr$181))
				fb$result$ = (vr$182);
			};
			label$185:;
		};
		goto label$179;
		label$187:;
		{
			{
				#define vr$183 ((longint*)(N$))
				#define vr$184 ((double)(*(longint*)((ubyte *)vr$183 + 20)))
				fb$result$ = (vr$184);
			};
			goto label$188;
			label$189:;
			{
				#define vr$185 ((integer*)(N$))
				#define vr$186 ((double)(*(integer*)((ubyte *)vr$185 + 20)))
				fb$result$ = (vr$186);
			};
			label$188:;
		};
		goto label$179;
		label$190:;
		{
			#define vr$187 ((integer*)(N$))
			#define vr$188 ((uinteger)(*(integer*)((ubyte *)vr$187 + 20)))
			#define vr$189 ((double)(vr$188))
			fb$result$ = (vr$189);
		};
		goto label$179;
		label$191:;
		{
			#define vr$190 ((integer*)(N$))
			#define vr$191 ((double)(*(integer*)((ubyte *)vr$190 + 20)))
			fb$result$ = (vr$191);
		};
		goto label$179;
		label$180:;
		if (TMP$91$ < (uinteger)8u) goto label$191;
		if (TMP$91$ > (uinteger)16u) goto label$191;
		static const void * LABEL$192$[] = {
			&&label$190,
			&&label$191,
			&&label$191,
			&&label$187,
			&&label$184,
			&&label$182,
			&&label$181,
			&&label$183,
			&&label$183,
		(void *)0 };
		#define vr$192 ((uinteger)(TMP$91$ << (uinteger)2u))
		goto **(void**)((ubyte *)LABEL$192$ + vr$192 + -32);
		label$179:;
	};
	label$178:;
	#define vr$193 ((double)(fb$result$))
	return vr$193;
}

FBSYMBOL$type* ASTGETSTRLITSYMBOL( ASTNODE$type* N$ )
{
	FBSYMBOL$type* fb$result$;
	FBSYMBOL$type* S$;
	#define vr$194 ((FBSYMBOL$type**)(&fb$result$))
	__builtin_memset( vr$194, 0, (integer)4 );
	label$193:;
	fb$result$ = ((FBSYMBOL$type*)0);
	#define vr$195 ((AST_NODECLASS*)(N$))
	if (*(AST_NODECLASS*)((ubyte *)vr$195) != (AST_NODECLASS)17) goto label$196;
	{
		#define vr$196 ((FBSYMBOL$type**)(N$))
		S$ = (*(FBSYMBOL$type**)((ubyte *)vr$196 + 12));
		if (S$ == (integer)0) goto label$198;
		{
			#define vr$197 ((FB_SYMBATTRIB*)(S$))
			#define vr$198 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$197 + 4) & (FB_SYMBATTRIB)524288))
			if (vr$198 == (integer)0) goto label$200;
			{
				fb$result$ = (S$);
			};
			label$200:;
			label$199:;
		};
		label$198:;
		label$197:;
	};
	label$196:;
	label$195:;
	label$194:;
	#define vr$199 ((FBSYMBOL$type*)(fb$result$))
	return vr$199;
}

void ASTCHECKCONST( integer DTYPE$, ASTNODE$type* N$ )
{
	integer RESULT$;
	double DVAL$;
	single SVAL$;
	longint LVAL$;
	label$201:;
	RESULT$ = ((integer)-1);
	{
		FB_DATATYPE TMP$94$;
		uinteger TMP$95$;
		#define vr$200 ((integer)(DTYPE$ & (integer)480))
		if (vr$200 == (integer)0) goto label$203;
		TMP$94$ = ((FB_DATATYPE)23);
		goto label$230;
		label$203:;
		#define vr$201 ((integer)(DTYPE$ & (integer)31))
		#define vr$202 ((FB_DATATYPE)(vr$201))
		TMP$94$ = (vr$202);
		label$230:;
		#define vr$203 ((uinteger)(TMP$94$))
		TMP$95$ = (vr$203);
		goto label$205;
		label$206:;
		{
			double vr$204 = (double)(ASTGETVALUEASDOUBLE( N$ ));
			DVAL$ = (vr$204);
			{
				double TMP$96$;
				double vr$205 = (double)(fabsl( DVAL$ ));
				TMP$96$ = (vr$205);
				if (TMP$96$ == (double)0.0) goto label$209;
				label$210:;
				if (TMP$96$ < (double)2e-45) goto label$208;
				if (TMP$96$ > (double)3e+38) goto label$208;
				label$209:;
				{
					RESULT$ = ((integer)-1);
				};
				goto label$207;
				label$208:;
				{
					#define vr$206 ((single)(DVAL$))
					SVAL$ = (vr$206);
					#define vr$207 ((single)(SVAL$ + SVAL$))
					if (vr$207 != SVAL$) goto label$213;
					{
						#define vr$208 ((double)(DVAL$ + DVAL$))
						#define vr$209 ((integer)((-(vr$208 == DVAL$))))
						RESULT$ = (vr$209);
					};
					goto label$212;
					label$213:;
					{
						RESULT$ = ((integer)-1);
					};
					label$212:;
				};
				label$211:;
				label$207:;
			};
		};
		goto label$204;
		label$214:;
		{
			{
				FB_DATATYPE TMP$97$;
				uinteger TMP$98$;
				#define vr$210 ((integer)(DTYPE$ & (integer)480))
				if (vr$210 == (integer)0) goto label$215;
				TMP$97$ = ((FB_DATATYPE)23);
				goto label$231;
				label$215:;
				#define vr$211 ((integer)(DTYPE$ & (integer)31))
				#define vr$212 ((FB_DATATYPE)(vr$211))
				TMP$97$ = (vr$212);
				label$231:;
				#define vr$213 ((integer)(TMP$97$))
				#define vr$214 ((integer)(vr$213 * (integer)28))
				#define vr$215 ((uinteger)(*(integer*)((ubyte *)&SYMB_DTYPETB$ + vr$214 + 4)))
				TMP$98$ = (vr$215);
				goto label$217;
				label$218:;
				{
					longint vr$216 = (longint)(ASTGETVALUEASLONGINT( N$ ));
					LVAL$ = (vr$216);
					#define vr$217 ((integer)((-(LVAL$ >= (longint)-128ll))))
					#define vr$218 ((integer)((-(LVAL$ <= (longint)255ll))))
					#define vr$219 ((integer)(vr$217 & vr$218))
					RESULT$ = (vr$219);
				};
				goto label$216;
				label$219:;
				{
					longint vr$220 = (longint)(ASTGETVALUEASLONGINT( N$ ));
					LVAL$ = (vr$220);
					#define vr$221 ((integer)((-(LVAL$ >= (longint)-32768ll))))
					#define vr$222 ((integer)((-(LVAL$ <= (longint)65535ll))))
					#define vr$223 ((integer)(vr$221 & vr$222))
					RESULT$ = (vr$223);
				};
				goto label$216;
				label$220:;
				{
					longint vr$224 = (longint)(ASTGETVALUEASLONGINT( N$ ));
					LVAL$ = (vr$224);
					#define vr$225 ((integer)((-(LVAL$ >= (longint)-2147483648ll))))
					#define vr$226 ((integer)((-(LVAL$ <= (longint)4294967295ll))))
					#define vr$227 ((integer)(vr$225 & vr$226))
					RESULT$ = (vr$227);
				};
				goto label$216;
				label$221:;
				{
					FB_DATATYPE TMP$99$;
					#define vr$228 ((integer*)(N$))
					#define vr$229 ((integer)(*(integer*)((ubyte *)vr$228 + 4) & (integer)480))
					if (vr$229 == (integer)0) goto label$222;
					TMP$99$ = ((FB_DATATYPE)23);
					goto label$232;
					label$222:;
					#define vr$230 ((integer*)(N$))
					#define vr$231 ((integer)(*(integer*)((ubyte *)vr$230 + 4) & (integer)31))
					#define vr$232 ((FB_DATATYPE)(vr$231))
					TMP$99$ = (vr$232);
					label$232:;
					#define vr$233 ((integer)(TMP$99$))
					#define vr$234 ((integer)(vr$233 * (integer)28))
					if (*(FB_DATACLASS*)((ubyte *)&SYMB_DTYPETB$ + vr$234) != (FB_DATACLASS)1) goto label$224;
					{
						double vr$235 = (double)(ASTGETVALUEASDOUBLE( N$ ));
						DVAL$ = (vr$235);
						#define vr$236 ((integer)((-(DVAL$ >= (double)-9.223372036854776e+18))))
						#define vr$237 ((integer)((-(DVAL$ <= (double)1.844674407370955e+19))))
						#define vr$238 ((integer)(vr$236 & vr$237))
						RESULT$ = (vr$238);
					};
					label$224:;
					label$223:;
				};
				goto label$216;
				label$217:;
				if (TMP$98$ < (uinteger)1u) goto label$216;
				if (TMP$98$ > (uinteger)8u) goto label$216;
				static const void * LABEL$225$[] = {
					&&label$218,
					&&label$219,
					&&label$216,
					&&label$220,
					&&label$216,
					&&label$216,
					&&label$216,
					&&label$221,
				(void *)0 };
				#define vr$239 ((uinteger)(TMP$98$ << (uinteger)2u))
				goto **(void**)((ubyte *)LABEL$225$ + vr$239 + -4);
				label$216:;
			};
		};
		goto label$204;
		label$226:;
		{
		};
		goto label$204;
		label$205:;
		if (TMP$95$ < (uinteger)1u) goto label$204;
		if (TMP$95$ > (uinteger)15u) goto label$204;
		static const void * LABEL$227$[] = {
			&&label$214,
			&&label$214,
			&&label$214,
			&&label$214,
			&&label$214,
			&&label$214,
			&&label$214,
			&&label$214,
			&&label$214,
			&&label$226,
			&&label$214,
			&&label$214,
			&&label$214,
			&&label$214,
			&&label$206,
		(void *)0 };
		#define vr$240 ((uinteger)(TMP$95$ << (uinteger)2u))
		goto **(void**)((ubyte *)LABEL$227$ + vr$240 + -4);
		label$204:;
	};
	if (RESULT$ != (integer)0) goto label$229;
	{
		ERRREPORTWARN( (FB_WARNINGMSG)25, (integer)0, (FB_ERRMSGOPT)1 );
	};
	label$229:;
	label$228:;
	label$202:;
}

integer ASTPTRCHECK( integer PDTYPE$, FBSYMBOL$type* PSUBTYPE$, ASTNODE$type* EXPR$, integer STRICTCHECK$ )
{
	integer fb$result$;
	integer EDTYPE$;
	#define vr$241 ((integer*)(&fb$result$))
	__builtin_memset( vr$241, 0, (integer)4 );
	label$233:;
	fb$result$ = ((integer)0);
	#define vr$242 ((integer*)(EXPR$))
	EDTYPE$ = (*(integer*)((ubyte *)vr$242 + 4));
	#define vr$243 ((integer)(EDTYPE$ & (integer)480))
	#define vr$244 ((integer)((-(vr$243 != (integer)0))))
	if (vr$244 != (integer)0) goto label$236;
	{
		#define vr$245 ((AST_NODECLASS*)(EXPR$))
		if (*(AST_NODECLASS*)((ubyte *)vr$245) != (AST_NODECLASS)16) goto label$238;
		{
			FB_DATATYPE TMP$104$;
			#define vr$246 ((integer)(EDTYPE$ & (integer)480))
			if (vr$246 == (integer)0) goto label$239;
			TMP$104$ = ((FB_DATATYPE)23);
			goto label$263;
			label$239:;
			#define vr$247 ((integer)(EDTYPE$ & (integer)31))
			#define vr$248 ((FB_DATATYPE)(vr$247))
			TMP$104$ = (vr$248);
			label$263:;
			#define vr$249 ((integer)(TMP$104$))
			#define vr$250 ((integer)(vr$249 * (integer)28))
			if (*(FB_DATACLASS*)((ubyte *)&SYMB_DTYPETB$ + vr$250) != (FB_DATACLASS)0) goto label$241;
			{
				integer vr$251 = (integer)(ASTCONSTISZERO( EXPR$ ));
				fb$result$ = (vr$251);
			};
			label$241:;
			label$240:;
		};
		label$238:;
		label$237:;
		goto label$234;
	};
	label$236:;
	label$235:;
	if (STRICTCHECK$ == (integer)0) goto label$243;
	{
		#define vr$252 ((integer)(EDTYPE$ & (integer)261632))
		#define vr$253 ((integer)(vr$252 & (integer)-513))
		#define vr$254 ((integer)(PDTYPE$ & (integer)261632))
		#define vr$255 ((integer)(vr$254 & (integer)-513))
		if (vr$253 == vr$255) goto label$245;
		{
			goto label$234;
		};
		label$245:;
		label$244:;
	};
	label$243:;
	label$242:;
	#define vr$256 ((integer)(PDTYPE$ & (integer)511))
	#define vr$257 ((integer)(EDTYPE$ & (integer)511))
	if (vr$256 == vr$257) goto label$247;
	{
		integer PDTYPE_NP$;
		integer EDTYPE_NP$;
		#define vr$258 ((integer)(PDTYPE$ & (integer)31))
		PDTYPE_NP$ = (vr$258);
		#define vr$259 ((integer)(EDTYPE$ & (integer)31))
		EDTYPE_NP$ = (vr$259);
		if (PDTYPE_NP$ != (FB_DATATYPE)0) goto label$249;
		{
			fb$result$ = ((integer)-1);
			goto label$234;
		};
		goto label$248;
		label$249:;
		if (EDTYPE_NP$ != (FB_DATATYPE)0) goto label$250;
		{
			fb$result$ = ((integer)-1);
			goto label$234;
		};
		label$250:;
		label$248:;
		#define vr$260 ((integer)(PDTYPE$ & (integer)480))
		#define vr$261 ((integer)(vr$260 >> (integer)5))
		#define vr$262 ((integer)(EDTYPE$ & (integer)480))
		#define vr$263 ((integer)(vr$262 >> (integer)5))
		if (vr$261 == vr$263) goto label$252;
		{
			goto label$234;
		};
		label$252:;
		label$251:;
		#define vr$264 ((integer)((-(PDTYPE_NP$ <= (FB_DATATYPE)16))))
		#define vr$265 ((integer)((-(EDTYPE_NP$ <= (FB_DATATYPE)16))))
		#define vr$266 ((integer)(vr$264 & vr$265))
		if (vr$266 == (integer)0) goto label$254;
		{
			FB_DATATYPE TMP$105$;
			FB_DATATYPE TMP$106$;
			#define vr$267 ((integer)(PDTYPE_NP$ & (integer)480))
			if (vr$267 == (integer)0) goto label$255;
			TMP$105$ = ((FB_DATATYPE)23);
			goto label$264;
			label$255:;
			#define vr$268 ((integer)(PDTYPE_NP$ & (integer)31))
			#define vr$269 ((FB_DATATYPE)(vr$268))
			TMP$105$ = (vr$269);
			label$264:;
			#define vr$270 ((integer)(TMP$105$))
			#define vr$271 ((integer)(vr$270 * (integer)28))
			#define vr$272 ((integer)(EDTYPE_NP$ & (integer)480))
			if (vr$272 == (integer)0) goto label$256;
			TMP$106$ = ((FB_DATATYPE)23);
			goto label$265;
			label$256:;
			#define vr$273 ((integer)(EDTYPE_NP$ & (integer)31))
			#define vr$274 ((FB_DATATYPE)(vr$273))
			TMP$106$ = (vr$274);
			label$265:;
			#define vr$275 ((integer)(TMP$106$))
			#define vr$276 ((integer)(vr$275 * (integer)28))
			if (*(integer*)((ubyte *)&SYMB_DTYPETB$ + vr$271 + 4) != *(integer*)((ubyte *)&SYMB_DTYPETB$ + vr$276 + 4)) goto label$258;
			{
				FB_DATATYPE TMP$107$;
				FB_DATATYPE TMP$108$;
				#define vr$277 ((integer)(PDTYPE_NP$ & (integer)480))
				if (vr$277 == (integer)0) goto label$259;
				TMP$107$ = ((FB_DATATYPE)23);
				goto label$266;
				label$259:;
				#define vr$278 ((integer)(PDTYPE_NP$ & (integer)31))
				#define vr$279 ((FB_DATATYPE)(vr$278))
				TMP$107$ = (vr$279);
				label$266:;
				#define vr$280 ((integer)(TMP$107$))
				#define vr$281 ((integer)(vr$280 * (integer)28))
				#define vr$282 ((integer)(EDTYPE_NP$ & (integer)480))
				if (vr$282 == (integer)0) goto label$260;
				TMP$108$ = ((FB_DATATYPE)23);
				goto label$267;
				label$260:;
				#define vr$283 ((integer)(EDTYPE_NP$ & (integer)31))
				#define vr$284 ((FB_DATATYPE)(vr$283))
				TMP$108$ = (vr$284);
				label$267:;
				#define vr$285 ((integer)(TMP$108$))
				#define vr$286 ((integer)(vr$285 * (integer)28))
				if (*(FB_DATACLASS*)((ubyte *)&SYMB_DTYPETB$ + vr$281) != *(FB_DATACLASS*)((ubyte *)&SYMB_DTYPETB$ + vr$286)) goto label$262;
				{
					fb$result$ = ((integer)-1);
					goto label$234;
				};
				label$262:;
				label$261:;
			};
			label$258:;
			label$257:;
		};
		label$254:;
		label$253:;
		goto label$234;
	};
	label$247:;
	label$246:;
	#define vr$287 ((FBSYMBOL$type**)(EXPR$))
	integer vr$288 = (integer)(SYMBISEQUAL( *(FBSYMBOL$type**)((ubyte *)vr$287 + 8), PSUBTYPE$ ));
	fb$result$ = (vr$288);
	label$234:;
	#define vr$289 ((integer)(fb$result$))
	return vr$289;
}

ASTNODE$type* ASTUPDSTRCONCAT( ASTNODE$type* N$ )
{
	ASTNODE$type* fb$result$;
	ASTNODE$type* L$;
	ASTNODE$type* R$;
	#define vr$290 ((ASTNODE$type**)(&fb$result$))
	__builtin_memset( vr$290, 0, (integer)4 );
	label$268:;
	fb$result$ = (N$);
	if (N$ != (integer)0) goto label$271;
	{
		goto label$269;
	};
	label$271:;
	label$270:;
	{
		uinteger TMP$109$;
		#define vr$291 ((integer*)(N$))
		#define vr$292 ((integer)(*(integer*)((ubyte *)vr$291 + 4) & (integer)511))
		#define vr$293 ((uinteger)(vr$292))
		TMP$109$ = (vr$293);
		goto label$273;
		label$274:;
		{
		};
		goto label$272;
		label$275:;
		{
			goto label$269;
		};
		goto label$272;
		label$273:;
		if (TMP$109$ < (uinteger)6u) goto label$275;
		if (TMP$109$ > (uinteger)18u) goto label$275;
		static const void * LABEL$276$[] = {
			&&label$274,
			&&label$275,
			&&label$275,
			&&label$275,
			&&label$275,
			&&label$275,
			&&label$275,
			&&label$275,
			&&label$275,
			&&label$275,
			&&label$275,
			&&label$274,
			&&label$274,
		(void *)0 };
		#define vr$294 ((uinteger)(TMP$109$ << (uinteger)2u))
		goto **(void**)((ubyte *)LABEL$276$ + vr$294 + -24);
		label$272:;
	};
	#define vr$295 ((ASTNODE$type**)(N$))
	L$ = (*(ASTNODE$type**)((ubyte *)vr$295 + 56));
	if (L$ == (integer)0) goto label$278;
	{
		ASTNODE$type* vr$296 = (ASTNODE$type*)(ASTUPDSTRCONCAT( L$ ));
		#define vr$297 ((ASTNODE$type**)(N$))
		*(ASTNODE$type**)((ubyte *)vr$297 + 56) = (vr$296);
	};
	label$278:;
	label$277:;
	#define vr$298 ((ASTNODE$type**)(N$))
	R$ = (*(ASTNODE$type**)((ubyte *)vr$298 + 60));
	if (R$ == (integer)0) goto label$280;
	{
		ASTNODE$type* vr$299 = (ASTNODE$type*)(ASTUPDSTRCONCAT( R$ ));
		#define vr$300 ((ASTNODE$type**)(N$))
		*(ASTNODE$type**)((ubyte *)vr$300 + 60) = (vr$299);
	};
	label$280:;
	label$279:;
	#define vr$301 ((AST_NODECLASS*)(N$))
	if (*(AST_NODECLASS*)((ubyte *)vr$301) != (AST_NODECLASS)3) goto label$282;
	{
		#define vr$302 ((integer*)(N$))
		if (*(integer*)((ubyte *)vr$302 + 20) != (AST_OP)27) goto label$284;
		{
			integer LDTYPE$;
			integer RDTYPE$;
			#define vr$303 ((ASTNODE$type**)(N$))
			L$ = (*(ASTNODE$type**)((ubyte *)vr$303 + 56));
			#define vr$304 ((ASTNODE$type**)(N$))
			R$ = (*(ASTNODE$type**)((ubyte *)vr$304 + 60));
			#define vr$305 ((integer*)(L$))
			#define vr$306 ((integer)(*(integer*)((ubyte *)vr$305 + 4) & (integer)511))
			LDTYPE$ = (vr$306);
			#define vr$307 ((integer*)(R$))
			#define vr$308 ((integer)(*(integer*)((ubyte *)vr$307 + 4) & (integer)511))
			RDTYPE$ = (vr$308);
			#define vr$309 ((integer*)(N$))
			#define vr$310 ((integer)(*(integer*)((ubyte *)vr$309 + 4) & (integer)511))
			if (vr$310 == (FB_DATATYPE)6) goto label$286;
			{
				ASTNODE$type* vr$311 = (ASTNODE$type*)(RTLSTRCONCAT( L$, LDTYPE$, R$, RDTYPE$ ));
				fb$result$ = (vr$311);
			};
			goto label$285;
			label$286:;
			{
				ASTNODE$type* vr$312 = (ASTNODE$type*)(RTLWSTRCONCAT( L$, LDTYPE$, R$, RDTYPE$ ));
				fb$result$ = (vr$312);
			};
			label$285:;
			ASTDELNODE( N$ );
		};
		label$284:;
		label$283:;
	};
	label$282:;
	label$281:;
	label$269:;
	#define vr$313 ((ASTNODE$type*)(fb$result$))
	return vr$313;
}

ASTNODE$type* ASTBUILDBRANCH( ASTNODE$type* EXPR$, FBSYMBOL$type* LABEL$, integer IS_INVERSE$, integer IS_IIF$ )
{
	ASTNODE$type* fb$result$;
	ASTNODE$type* N$;
	ASTNODE$type* PARENTLINK$;
	ASTNODE$type* M$;
	integer DTYPE$;
	integer CALL_DTORS$;
	FBSYMBOL$type* TEMP$;
	FB_DATATYPE TMP$112$;
	AST_OP TMP$131$;
	#define vr$314 ((ASTNODE$type**)(&fb$result$))
	__builtin_memset( vr$314, 0, (integer)4 );
	label$287:;
	if (EXPR$ != (integer)0) goto label$290;
	{
		fb$result$ = ((ASTNODE$type*)0);
		goto label$288;
	};
	label$290:;
	label$289:;
	ASTNODE$type* vr$315 = (ASTNODE$type*)(ASTOPTIMIZETREE( EXPR$ ));
	EXPR$ = (vr$315);
	#define vr$316 ((integer*)(EXPR$))
	#define vr$317 ((integer)(*(integer*)((ubyte *)vr$316 + 4) & (integer)511))
	DTYPE$ = (vr$317);
	#define vr$318 ((integer)(DTYPE$ & (integer)480))
	if (vr$318 == (integer)0) goto label$291;
	TMP$112$ = ((FB_DATATYPE)23);
	goto label$356;
	label$291:;
	#define vr$319 ((integer)(DTYPE$ & (integer)31))
	#define vr$320 ((FB_DATATYPE)(vr$319))
	TMP$112$ = (vr$320);
	label$356:;
	#define vr$321 ((integer)(TMP$112$))
	#define vr$322 ((integer)(vr$321 * (integer)28))
	if (*(FB_DATACLASS*)((ubyte *)&SYMB_DTYPETB$ + vr$322) != (FB_DATACLASS)2) goto label$293;
	{
		fb$result$ = ((ASTNODE$type*)0);
		goto label$288;
	};
	label$293:;
	label$292:;
	{
		uinteger TMP$113$;
		#define vr$323 ((uinteger)(DTYPE$))
		TMP$113$ = (vr$323);
		goto label$295;
		label$296:;
		{
			#define vr$324 ((AST_NODECLASS*)(EXPR$))
			#define vr$325 ((integer)((-(*(AST_NODECLASS*)((ubyte *)vr$324) == (AST_NODECLASS)20))))
			if (vr$325 != (integer)0) goto label$298;
			{
				fb$result$ = ((ASTNODE$type*)0);
				goto label$288;
			};
			label$298:;
			label$297:;
		};
		goto label$294;
		label$299:;
		{
			FB_ERRMSG ERR_NUM$;
			FBSYMBOL$type* OVLPROC$;
			#define vr$326 ((FB_ERRMSG*)(&ERR_NUM$))
			FBSYMBOL$type* vr$327 = (FBSYMBOL$type*)(SYMBFINDCASTOVLPROC( (FB_DATATYPE)0, (integer)0, EXPR$, vr$326 ));
			OVLPROC$ = (vr$327);
			if (OVLPROC$ != (integer)0) goto label$301;
			{
				#define vr$328 ((FB_ERRMSG*)(&ERR_NUM$))
				FBSYMBOL$type* vr$329 = (FBSYMBOL$type*)(SYMBFINDCASTOVLPROC( (FB_DATATYPE)32, (integer)0, EXPR$, vr$328 ));
				OVLPROC$ = (vr$329);
				if (OVLPROC$ != (integer)0) goto label$303;
				{
					#define vr$330 ((FBSYMBOL$type**)(EXPR$))
					FBSYMBOL$type* vr$331 = (FBSYMBOL$type*)(SYMBGETCOMPOPOVLHEAD( *(FBSYMBOL$type**)((ubyte *)vr$330 + 8), (AST_OP)26 ));
					OVLPROC$ = (vr$331);
					if (OVLPROC$ != (integer)0) goto label$305;
					{
						#define vr$332 ((FBSYMBOL$type**)(EXPR$))
						if (*(FBSYMBOL$type**)((ubyte *)vr$332 + 8) == (FBSYMBOL$type*)0) goto label$307;
						{
							string TMP$116$;
							string TMP$117$;
							string TMP$118$;
							#define vr$333 ((string*)(&TMP$118$))
							__builtin_memset( vr$333, 0, (integer)12 );
							#define vr$334 ((FBSYMBOL$type**)(EXPR$))
							#define vr$335 ((char**)(*(FBSYMBOL$type**)((ubyte *)vr$334 + 8)))
							#define vr$336 ((string*)(&TMP$116$))
							__builtin_memset( vr$336, 0, (integer)12 );
							#define vr$337 ((string*)(&TMP$116$))
							string* vr$338 = (string*)(fb_StrConcat( vr$337, (char*)" \"", (integer)3, *(char**)((ubyte *)vr$335 + 12), (integer)0 ));
							#define vr$339 ((string*)(&TMP$117$))
							__builtin_memset( vr$339, 0, (integer)12 );
							#define vr$340 ((string*)(&TMP$117$))
							string* vr$341 = (string*)(fb_StrConcat( vr$340, vr$338, (integer)-1, (char*)".cast()\"", (integer)9 ));
							#define vr$342 ((string*)(&TMP$118$))
							fb_StrAssign( vr$342, (integer)-1, vr$341, (integer)-1, (integer)0 );
							#define vr$343 ((string*)(&TMP$118$))
							#define vr$344 ((char**)(vr$343))
							ERRREPORT( (FB_ERRMSG)91, (integer)-1, *(char**)((ubyte *)vr$344) );
							#define vr$345 ((string*)(&TMP$118$))
							fb_StrDelete( vr$345 );
							fb$result$ = ((ASTNODE$type*)0);
							goto label$288;
						};
						label$307:;
						label$306:;
					};
					label$305:;
					label$304:;
					ERRREPORT( (FB_ERRMSG)91, (integer)-1, (integer)0 );
					fb$result$ = ((ASTNODE$type*)0);
					goto label$288;
				};
				label$303:;
				label$302:;
			};
			label$301:;
			label$300:;
			ASTNODE$type* vr$346 = (ASTNODE$type*)(ASTBUILDCALL( OVLPROC$, EXPR$, (integer)0, (integer)0 ));
			EXPR$ = (vr$346);
			#define vr$347 ((integer*)(EXPR$))
			#define vr$348 ((integer)(*(integer*)((ubyte *)vr$347 + 4) & (integer)511))
			DTYPE$ = (vr$348);
		};
		goto label$294;
		label$295:;
		if (TMP$113$ < (uinteger)3u) goto label$294;
		if (TMP$113$ > (uinteger)19u) goto label$294;
		static const void * LABEL$308$[] = {
			&&label$296,
			&&label$294,
			&&label$294,
			&&label$296,
			&&label$294,
			&&label$294,
			&&label$294,
			&&label$294,
			&&label$294,
			&&label$294,
			&&label$294,
			&&label$294,
			&&label$294,
			&&label$294,
			&&label$294,
			&&label$294,
			&&label$299,
		(void *)0 };
		#define vr$349 ((uinteger)(TMP$113$ << (uinteger)2u))
		goto **(void**)((ubyte *)LABEL$308$ + vr$349 + -12);
		label$294:;
	};
	ASTNODE$type* vr$350 = (ASTNODE$type*)(ASTTYPEINIUPDATE( EXPR$ ));
	EXPR$ = (vr$350);
	#define vr$351 ((TLIST*)(&*(TLIST*)((ubyte *)&AST$ + 148)))
	void* vr$352 = (void*)(LISTGETHEAD( vr$351 ));
	#define vr$353 ((integer)((-(vr$352 == (integer)0))))
	#define vr$354 ((integer)(IS_IIF$ | vr$353))
	#define vr$355 ((integer)(~(vr$354)))
	CALL_DTORS$ = (vr$355);
	if (CALL_DTORS$ != (integer)0) goto label$310;
	{
		N$ = (EXPR$);
		PARENTLINK$ = ((ASTNODE$type*)0);
		label$311:;
		#define vr$356 ((AST_NODECLASS*)(N$))
		if (*(AST_NODECLASS*)((ubyte *)vr$356) != (AST_NODECLASS)15) goto label$312;
		{
			PARENTLINK$ = (N$);
			#define vr$357 ((integer*)(N$))
			if (*(integer*)((ubyte *)vr$357 + 20) == (integer)0) goto label$314;
			{
				#define vr$358 ((ASTNODE$type**)(N$))
				N$ = (*(ASTNODE$type**)((ubyte *)vr$358 + 56));
			};
			goto label$313;
			label$314:;
			{
				#define vr$359 ((ASTNODE$type**)(N$))
				N$ = (*(ASTNODE$type**)((ubyte *)vr$359 + 60));
			};
			label$313:;
		};
		goto label$311;
		label$312:;
		{
			AST_NODECLASS TMP$121$;
			#define vr$360 ((AST_NODECLASS*)(N$))
			TMP$121$ = (*(AST_NODECLASS*)((ubyte *)vr$360));
			if (*(integer*)(&TMP$121$) != (AST_NODECLASS)16) goto label$316;
			label$317:;
			{
				integer vr$361 = (integer)(ASTCONSTISZERO( N$ ));
				if (vr$361 == IS_INVERSE$) goto label$319;
				{
					ASTNODE$type* vr$362 = (ASTNODE$type*)(ASTNEWBRANCH( (AST_OP)95, LABEL$, (integer)0 ));
					M$ = (vr$362);
				};
				goto label$318;
				label$319:;
				{
					ASTNODE$type* vr$363 = (ASTNODE$type*)(ASTNEWNOP(  ));
					M$ = (vr$363);
				};
				label$318:;
				ASTDELNODE( N$ );
				N$ = (M$);
			};
			goto label$315;
			label$316:;
			if (*(integer*)(&TMP$121$) != (AST_NODECLASS)3) goto label$320;
			label$321:;
			{
				{
					uinteger TMP$122$;
					#define vr$364 ((integer*)(N$))
					#define vr$365 ((uinteger)(*(integer*)((ubyte *)vr$364 + 20)))
					TMP$122$ = (vr$365);
					goto label$323;
					label$324:;
					{
						#define vr$366 ((FBSYMBOL$type**)(N$))
						*(FBSYMBOL$type**)((ubyte *)vr$366 + 28) = (LABEL$);
						if (IS_INVERSE$ != (integer)0) goto label$326;
						{
							#define vr$367 ((integer*)(N$))
							integer vr$368 = (integer)(ASTGETINVERSELOGOP( *(integer*)((ubyte *)vr$367 + 20) ));
							#define vr$369 ((integer*)(N$))
							*(integer*)((ubyte *)vr$369 + 20) = (vr$368);
						};
						label$326:;
						label$325:;
					};
					goto label$322;
					label$327:;
					{
						integer DOOPT$;
						FB_DATATYPE TMP$123$;
						#define vr$370 ((integer)(DTYPE$ & (integer)480))
						if (vr$370 == (integer)0) goto label$328;
						TMP$123$ = ((FB_DATATYPE)23);
						goto label$357;
						label$328:;
						#define vr$371 ((integer)(DTYPE$ & (integer)31))
						#define vr$372 ((FB_DATATYPE)(vr$371))
						TMP$123$ = (vr$372);
						label$357:;
						#define vr$373 ((integer)(TMP$123$))
						#define vr$374 ((integer)(vr$373 * (integer)28))
						if (*(FB_DATACLASS*)((ubyte *)&SYMB_DTYPETB$ + vr$374) != (FB_DATACLASS)0) goto label$330;
						{
							#define vr$375 ((IR_OPT)(*(IR_OPT*)((ubyte *)&IR$ + 292) & (IR_OPT)256))
							#define vr$376 ((integer)((-(vr$375 != (integer)0))))
							DOOPT$ = (vr$376);
							if (DOOPT$ == (integer)0) goto label$332;
							{
								{
									uinteger TMP$124$;
									#define vr$377 ((uinteger)(DTYPE$))
									TMP$124$ = (vr$377);
									goto label$334;
									label$335:;
									{
										#define vr$378 ((IR_OPT)(*(IR_OPT*)((ubyte *)&IR$ + 292) & (IR_OPT)1024))
										#define vr$379 ((integer)((-(vr$378 != (integer)0))))
										DOOPT$ = (vr$379);
									};
									goto label$333;
									label$334:;
									if (TMP$124$ < (uinteger)13u) goto label$333;
									if (TMP$124$ > (uinteger)14u) goto label$333;
									static const void * LABEL$336$[] = {
										&&label$335,
										&&label$335,
									(void *)0 };
									#define vr$380 ((uinteger)(TMP$124$ << (uinteger)2u))
									goto **(void**)((ubyte *)LABEL$336$ + vr$380 + -52);
									label$333:;
								};
							};
							label$332:;
							label$331:;
						};
						goto label$329;
						label$330:;
						{
							#define vr$381 ((IR_OPT)(*(IR_OPT*)((ubyte *)&IR$ + 292) & (IR_OPT)4))
							#define vr$382 ((integer)((-(vr$381 != (integer)0))))
							DOOPT$ = (vr$382);
						};
						label$329:;
						if (DOOPT$ == (integer)0) goto label$338;
						{
							AST_OP TMP$127$;
							if (IS_INVERSE$ == (integer)0) goto label$339;
							TMP$127$ = ((AST_OP)92);
							goto label$358;
							label$339:;
							TMP$127$ = ((AST_OP)89);
							label$358:;
							ASTNODE$type* vr$383 = (ASTNODE$type*)(ASTNEWBRANCH( TMP$127$, LABEL$, N$ ));
							N$ = (vr$383);
						};
						goto label$337;
						label$338:;
						{
							N$ = ((ASTNODE$type*)0);
						};
						label$337:;
					};
					goto label$322;
					label$340:;
					{
						N$ = ((ASTNODE$type*)0);
					};
					goto label$322;
					label$323:;
					if (TMP$122$ < (uinteger)27u) goto label$340;
					if (TMP$122$ > (uinteger)49u) goto label$340;
					static const void * LABEL$341$[] = {
						&&label$327,
						&&label$327,
						&&label$340,
						&&label$340,
						&&label$340,
						&&label$340,
						&&label$327,
						&&label$327,
						&&label$340,
						&&label$340,
						&&label$327,
						&&label$340,
						&&label$327,
						&&label$327,
						&&label$327,
						&&label$340,
						&&label$340,
						&&label$324,
						&&label$324,
						&&label$324,
						&&label$324,
						&&label$324,
						&&label$324,
					(void *)0 };
					#define vr$384 ((uinteger)(TMP$122$ << (uinteger)2u))
					goto **(void**)((ubyte *)LABEL$341$ + vr$384 + -108);
					label$322:;
				};
			};
			goto label$315;
			label$320:;
			{
				N$ = ((ASTNODE$type*)0);
			};
			label$342:;
			label$315:;
		};
		if (N$ == (ASTNODE$type*)0) goto label$344;
		{
			if (PARENTLINK$ == (ASTNODE$type*)0) goto label$346;
			{
				#define vr$385 ((integer*)(PARENTLINK$))
				if (*(integer*)((ubyte *)vr$385 + 20) == (integer)0) goto label$348;
				{
					#define vr$386 ((ASTNODE$type**)(PARENTLINK$))
					*(ASTNODE$type**)((ubyte *)vr$386 + 56) = (N$);
				};
				goto label$347;
				label$348:;
				{
					#define vr$387 ((ASTNODE$type**)(PARENTLINK$))
					*(ASTNODE$type**)((ubyte *)vr$387 + 60) = (N$);
				};
				label$347:;
			};
			goto label$345;
			label$346:;
			{
				EXPR$ = (N$);
			};
			label$345:;
			fb$result$ = (EXPR$);
			goto label$288;
		};
		label$344:;
		label$343:;
	};
	goto label$309;
	label$310:;
	{
		N$ = ((ASTNODE$type*)0);
	};
	label$309:;
	{
		integer TMP$130$;
		TMP$130$ = (DTYPE$);
		if (TMP$130$ == (FB_DATATYPE)3) goto label$351;
		label$352:;
		if (TMP$130$ != (FB_DATATYPE)6) goto label$350;
		label$351:;
		{
			#define vr$388 ((FBSYMBOL$type**)(EXPR$))
			integer vr$389 = (integer)(TYPEREMAP( DTYPE$, *(FBSYMBOL$type**)((ubyte *)vr$388 + 8) ));
			DTYPE$ = (vr$389);
		};
		label$350:;
		label$349:;
	};
	if (CALL_DTORS$ == (integer)0) goto label$354;
	{
		#define vr$390 ((FBSYMBOL$type**)(EXPR$))
		FBSYMBOL$type* vr$391 = (FBSYMBOL$type*)(SYMBADDTEMPVAR( DTYPE$, *(FBSYMBOL$type**)((ubyte *)vr$390 + 8) ));
		TEMP$ = (vr$391);
		ASTNODE$type* vr$392 = (ASTNODE$type*)(_Z17ASTBUILDVARASSIGNP8FBSYMBOLP7ASTNODE( TEMP$, EXPR$ ));
		N$ = (vr$392);
		ASTNODE$type* vr$393 = (ASTNODE$type*)(ASTDTORLISTFLUSH( (integer)0 ));
		ASTNODE$type* vr$394 = (ASTNODE$type*)(ASTNEWLINK( N$, vr$393, (integer)-1 ));
		N$ = (vr$394);
		ASTNODE$type* vr$395 = (ASTNODE$type*)(ASTNEWVAR( TEMP$, (integer)0, (integer)-2147483648u, (integer)0 ));
		EXPR$ = (vr$395);
	};
	label$354:;
	label$353:;
	#define vr$396 ((FBSYMBOL$type**)(EXPR$))
	ASTNODE$type* vr$397 = (ASTNODE$type*)(ASTNEWCONSTZ( DTYPE$, *(FBSYMBOL$type**)((ubyte *)vr$396 + 8) ));
	if (IS_INVERSE$ == (integer)0) goto label$355;
	TMP$131$ = ((AST_OP)47);
	goto label$359;
	label$355:;
	TMP$131$ = ((AST_OP)44);
	label$359:;
	ASTNODE$type* vr$398 = (ASTNODE$type*)(ASTNEWBOP( TMP$131$, EXPR$, vr$397, LABEL$, (AST_OPOPT)0 ));
	ASTNODE$type* vr$399 = (ASTNODE$type*)(ASTNEWLINK( N$, vr$398, (integer)-1 ));
	N$ = (vr$399);
	fb$result$ = (N$);
	label$288:;
	#define vr$400 ((ASTNODE$type*)(fb$result$))
	return vr$400;
}

void ASTDTORLISTADD( FBSYMBOL$type* SYM$ )
{
	AST_DTORLIST_ITEM* N$;
	AST_DTORLIST_SCOPESTACK* TMP$133$;
	label$369:;
	integer vr$401 = (integer)(HHASDTOR( SYM$ ));
	if (vr$401 != (integer)0) goto label$372;
	{
		goto label$370;
	};
	label$372:;
	label$371:;
	#define vr$402 ((TLIST*)(&*(TLIST*)((ubyte *)&AST$ + 148)))
	void* vr$403 = (void*)(LISTNEWNODE( vr$402 ));
	N$ = (vr$403);
	#define vr$404 ((FBSYMBOL$type**)(N$))
	*(FBSYMBOL$type**)((ubyte *)vr$404) = (SYM$);
	#define vr$405 ((AST_DTORLIST_SCOPESTACK*)(&*(AST_DTORLIST_SCOPESTACK*)((ubyte *)&AST$ + 180)))
	TMP$133$ = (vr$405);
	#define vr$406 ((integer*)(TMP$133$))
	if (*(integer*)((ubyte *)vr$406 + 4) <= (integer)0) goto label$374;
	{
		#define vr$407 ((integer**)(TMP$133$))
		#define vr$408 ((integer*)(TMP$133$))
		#define vr$409 ((integer)(*(integer*)((ubyte *)vr$408 + 4) << (integer)2))
		#define vr$410 ((integer*)((integer*)((ubyte *)*(integer**)((ubyte *)vr$407) + vr$409)))
		#define vr$411 ((integer*)(N$))
		*(integer*)((ubyte *)vr$411 + 4) = (*(integer*)((ubyte *)vr$410 + -4));
	};
	goto label$373;
	label$374:;
	{
		#define vr$412 ((integer*)(N$))
		*(integer*)((ubyte *)vr$412 + 4) = ((integer)0);
	};
	label$373:;
	#define vr$413 ((integer*)(N$))
	*(integer*)((ubyte *)vr$413 + 8) = ((integer)0);
	label$370:;
}

void ASTDTORLISTADDREF( FBSYMBOL$type* SYM$ )
{
	AST_DTORLIST_ITEM* I$;
	label$375:;
	integer vr$414 = (integer)(HHASDTOR( SYM$ ));
	if (vr$414 != (integer)0) goto label$378;
	{
		goto label$376;
	};
	label$378:;
	label$377:;
	#define vr$415 ((TLIST*)(&*(TLIST*)((ubyte *)&AST$ + 148)))
	void* vr$416 = (void*)(LISTGETTAIL( vr$415 ));
	I$ = (vr$416);
	label$379:;
	if (I$ == (AST_DTORLIST_ITEM*)0) goto label$380;
	{
		#define vr$417 ((FBSYMBOL$type**)(I$))
		if (*(FBSYMBOL$type**)((ubyte *)vr$417) != SYM$) goto label$382;
		{
			#define vr$418 ((integer*)(I$))
			#define vr$419 ((integer)(*(integer*)((ubyte *)vr$418 + 8) + (integer)1))
			#define vr$420 ((integer*)(I$))
			*(integer*)((ubyte *)vr$420 + 8) = (vr$419);
			goto label$380;
		};
		label$382:;
		label$381:;
		void* vr$421 = (void*)(LISTGETPREV( I$ ));
		I$ = (vr$421);
	};
	goto label$379;
	label$380:;
	label$376:;
}

void ASTDTORLISTREMOVEREF( FBSYMBOL$type* SYM$ )
{
	AST_DTORLIST_ITEM* I$;
	label$383:;
	integer vr$422 = (integer)(HHASDTOR( SYM$ ));
	if (vr$422 != (integer)0) goto label$386;
	{
		goto label$384;
	};
	label$386:;
	label$385:;
	#define vr$423 ((TLIST*)(&*(TLIST*)((ubyte *)&AST$ + 148)))
	void* vr$424 = (void*)(LISTGETTAIL( vr$423 ));
	I$ = (vr$424);
	label$387:;
	if (I$ == (AST_DTORLIST_ITEM*)0) goto label$388;
	{
		#define vr$425 ((FBSYMBOL$type**)(I$))
		if (*(FBSYMBOL$type**)((ubyte *)vr$425) != SYM$) goto label$390;
		{
			#define vr$426 ((integer*)(I$))
			#define vr$427 ((integer)(*(integer*)((ubyte *)vr$426 + 8) + (integer)-1))
			#define vr$428 ((integer*)(I$))
			*(integer*)((ubyte *)vr$428 + 8) = (vr$427);
			#define vr$429 ((integer*)(I$))
			if (*(integer*)((ubyte *)vr$429 + 8) > (integer)0) goto label$392;
			{
				#define vr$430 ((TLIST*)(&*(TLIST*)((ubyte *)&AST$ + 148)))
				LISTDELNODE( vr$430, I$ );
			};
			label$392:;
			label$391:;
			goto label$388;
		};
		label$390:;
		label$389:;
		void* vr$431 = (void*)(LISTGETPREV( I$ ));
		I$ = (vr$431);
	};
	goto label$387;
	label$388:;
	label$384:;
}

ASTNODE$type* ASTDTORLISTFLUSH( integer COOKIE$ )
{
	ASTNODE$type* fb$result$;
	AST_DTORLIST_ITEM* N$;
	AST_DTORLIST_ITEM* P$;
	ASTNODE$type* T$;
	#define vr$432 ((ASTNODE$type**)(&fb$result$))
	__builtin_memset( vr$432, 0, (integer)4 );
	label$393:;
	T$ = ((ASTNODE$type*)0);
	#define vr$433 ((TLIST*)(&*(TLIST*)((ubyte *)&AST$ + 148)))
	void* vr$434 = (void*)(LISTGETTAIL( vr$433 ));
	N$ = (vr$434);
	label$395:;
	if (N$ == (AST_DTORLIST_ITEM*)0) goto label$396;
	{
		void* vr$435 = (void*)(LISTGETPREV( N$ ));
		P$ = (vr$435);
		#define vr$436 ((integer*)(N$))
		if (*(integer*)((ubyte *)vr$436 + 4) != COOKIE$) goto label$398;
		{
			#define vr$437 ((FBSYMBOL$type**)(N$))
			ASTNODE$type* vr$438 = (ASTNODE$type*)(ASTBUILDVARDTORCALL( *(FBSYMBOL$type**)((ubyte *)vr$437), (integer)0 ));
			ASTNODE$type* vr$439 = (ASTNODE$type*)(ASTNEWLINK( T$, vr$438, (integer)-1 ));
			T$ = (vr$439);
			#define vr$440 ((TLIST*)(&*(TLIST*)((ubyte *)&AST$ + 148)))
			LISTDELNODE( vr$440, N$ );
		};
		label$398:;
		label$397:;
		N$ = (P$);
	};
	goto label$395;
	label$396:;
	if (COOKIE$ != (integer)0) goto label$400;
	{
		*(integer*)((ubyte *)&AST$ + 192) = ((integer)0);
	};
	label$400:;
	label$399:;
	fb$result$ = (T$);
	label$394:;
	#define vr$441 ((ASTNODE$type*)(fb$result$))
	return vr$441;
}

void ASTDTORLISTDEL( FBSYMBOL$type* SYM$ )
{
	AST_DTORLIST_ITEM* N$;
	label$401:;
	integer vr$442 = (integer)(HHASDTOR( SYM$ ));
	if (vr$442 != (integer)0) goto label$404;
	{
		goto label$402;
	};
	label$404:;
	label$403:;
	#define vr$443 ((TLIST*)(&*(TLIST*)((ubyte *)&AST$ + 148)))
	void* vr$444 = (void*)(LISTGETTAIL( vr$443 ));
	N$ = (vr$444);
	label$405:;
	if (N$ == (AST_DTORLIST_ITEM*)0) goto label$406;
	{
		#define vr$445 ((FBSYMBOL$type**)(N$))
		if (*(FBSYMBOL$type**)((ubyte *)vr$445) != SYM$) goto label$408;
		{
			#define vr$446 ((TLIST*)(&*(TLIST*)((ubyte *)&AST$ + 148)))
			LISTDELNODE( vr$446, N$ );
			goto label$406;
		};
		label$408:;
		label$407:;
		void* vr$447 = (void*)(LISTGETPREV( N$ ));
		N$ = (vr$447);
	};
	goto label$405;
	label$406:;
	label$402:;
}

void ASTDTORLISTSCOPEBEGIN( integer COOKIE$ )
{
	AST_DTORLIST_SCOPESTACK* TMP$134$;
	label$409:;
	if (COOKIE$ != (integer)0) goto label$412;
	{
		#define vr$448 ((integer)(*(integer*)((ubyte *)&AST$ + 192) + (integer)1))
		*(integer*)((ubyte *)&AST$ + 192) = (vr$448);
		COOKIE$ = (*(integer*)((ubyte *)&AST$ + 192));
	};
	label$412:;
	label$411:;
	#define vr$449 ((AST_DTORLIST_SCOPESTACK*)(&*(AST_DTORLIST_SCOPESTACK*)((ubyte *)&AST$ + 180)))
	TMP$134$ = (vr$449);
	#define vr$450 ((integer*)(TMP$134$))
	#define vr$451 ((integer*)(TMP$134$))
	if (*(integer*)((ubyte *)vr$450 + 4) != *(integer*)((ubyte *)vr$451 + 8)) goto label$414;
	{
		#define vr$452 ((integer*)(TMP$134$))
		#define vr$453 ((integer)(*(integer*)((ubyte *)vr$452 + 8) + (integer)8))
		#define vr$454 ((integer*)(TMP$134$))
		*(integer*)((ubyte *)vr$454 + 8) = (vr$453);
		#define vr$455 ((integer*)(TMP$134$))
		#define vr$456 ((integer)((integer)4 * *(integer*)((ubyte *)vr$455 + 8)))
		#define vr$457 ((integer**)(TMP$134$))
		void* vr$458 = (void*)(XREALLOCATE( *(integer**)((ubyte *)vr$457), vr$456 ));
		#define vr$459 ((integer**)(TMP$134$))
		*(integer**)((ubyte *)vr$459) = (vr$458);
	};
	label$414:;
	label$413:;
	#define vr$460 ((integer**)(TMP$134$))
	#define vr$461 ((integer*)(TMP$134$))
	#define vr$462 ((integer)(*(integer*)((ubyte *)vr$461 + 4) << (integer)2))
	#define vr$463 ((integer*)((integer*)((ubyte *)*(integer**)((ubyte *)vr$460) + vr$462)))
	*(integer*)((ubyte *)vr$463) = (COOKIE$);
	#define vr$464 ((integer*)(TMP$134$))
	#define vr$465 ((integer)(*(integer*)((ubyte *)vr$464 + 4) + (integer)1))
	#define vr$466 ((integer*)(TMP$134$))
	*(integer*)((ubyte *)vr$466 + 4) = (vr$465);
	label$410:;
}

integer ASTDTORLISTSCOPEEND( void )
{
	integer fb$result$;
	AST_DTORLIST_SCOPESTACK* TMP$135$;
	#define vr$467 ((integer*)(&fb$result$))
	__builtin_memset( vr$467, 0, (integer)4 );
	label$415:;
	#define vr$468 ((AST_DTORLIST_SCOPESTACK*)(&*(AST_DTORLIST_SCOPESTACK*)((ubyte *)&AST$ + 180)))
	TMP$135$ = (vr$468);
	#define vr$469 ((integer**)(TMP$135$))
	#define vr$470 ((integer*)(TMP$135$))
	#define vr$471 ((integer)(*(integer*)((ubyte *)vr$470 + 4) << (integer)2))
	#define vr$472 ((integer*)((integer*)((ubyte *)*(integer**)((ubyte *)vr$469) + vr$471)))
	fb$result$ = (*(integer*)((ubyte *)vr$472 + -4));
	#define vr$473 ((integer*)(TMP$135$))
	#define vr$474 ((integer)(*(integer*)((ubyte *)vr$473 + 4) + (integer)-1))
	#define vr$475 ((integer*)(TMP$135$))
	*(integer*)((ubyte *)vr$475 + 4) = (vr$474);
	label$416:;
	#define vr$476 ((integer)(fb$result$))
	return vr$476;
}

void ASTDTORLISTUNSCOPE( integer COOKIE$ )
{
	AST_DTORLIST_ITEM* I$;
	label$417:;
	#define vr$477 ((TLIST*)(&*(TLIST*)((ubyte *)&AST$ + 148)))
	void* vr$478 = (void*)(LISTGETTAIL( vr$477 ));
	I$ = (vr$478);
	label$419:;
	if (I$ == (AST_DTORLIST_ITEM*)0) goto label$420;
	{
		#define vr$479 ((integer*)(I$))
		if (*(integer*)((ubyte *)vr$479 + 4) != COOKIE$) goto label$422;
		{
			#define vr$480 ((integer*)(I$))
			*(integer*)((ubyte *)vr$480 + 4) = ((integer)0);
		};
		label$422:;
		label$421:;
		void* vr$481 = (void*)(LISTGETPREV( I$ ));
		I$ = (vr$481);
	};
	goto label$419;
	label$420:;
	label$418:;
}

void ASTSETTYPE( ASTNODE$type* N$, integer DTYPE$, FBSYMBOL$type* SUBTYPE$ )
{
	label$423:;
	#define vr$482 ((integer*)(N$))
	*(integer*)((ubyte *)vr$482 + 4) = (DTYPE$);
	#define vr$483 ((FBSYMBOL$type**)(N$))
	*(FBSYMBOL$type**)((ubyte *)vr$483 + 8) = (SUBTYPE$);
	{
		AST_NODECLASS TMP$136$;
		#define vr$484 ((AST_NODECLASS*)(N$))
		TMP$136$ = (*(AST_NODECLASS*)((ubyte *)vr$484));
		if (*(integer*)(&TMP$136$) != (AST_NODECLASS)15) goto label$426;
		label$427:;
		{
			#define vr$485 ((integer*)(N$))
			if (*(integer*)((ubyte *)vr$485 + 20) == (integer)0) goto label$429;
			{
				#define vr$486 ((ASTNODE$type**)(N$))
				ASTSETTYPE( *(ASTNODE$type**)((ubyte *)vr$486 + 56), DTYPE$, SUBTYPE$ );
			};
			goto label$428;
			label$429:;
			{
				#define vr$487 ((ASTNODE$type**)(N$))
				ASTSETTYPE( *(ASTNODE$type**)((ubyte *)vr$487 + 60), DTYPE$, SUBTYPE$ );
			};
			label$428:;
		};
		goto label$425;
		label$426:;
		if (*(integer*)(&TMP$136$) != (AST_NODECLASS)19) goto label$430;
		label$431:;
		{
			#define vr$488 ((ASTNODE$type**)(N$))
			ASTSETTYPE( *(ASTNODE$type**)((ubyte *)vr$488 + 56), DTYPE$, SUBTYPE$ );
		};
		goto label$425;
		label$430:;
		if (*(integer*)(&TMP$136$) != (AST_NODECLASS)10) goto label$432;
		label$433:;
		{
			#define vr$489 ((ASTNODE$type**)(N$))
			ASTSETTYPE( *(ASTNODE$type**)((ubyte *)vr$489 + 60), DTYPE$, SUBTYPE$ );
		};
		goto label$425;
		label$432:;
		if (*(integer*)(&TMP$136$) != (AST_NODECLASS)26) goto label$434;
		label$435:;
		{
			#define vr$490 ((ASTNODE$type**)(N$))
			ASTSETTYPE( *(ASTNODE$type**)((ubyte *)vr$490 + 56), DTYPE$, SUBTYPE$ );
		};
		label$434:;
		label$425:;
	};
	label$424:;
}

integer ASTSIZEOF( ASTNODE$type* N$ )
{
	integer fb$result$;
	#define vr$491 ((integer*)(&fb$result$))
	__builtin_memset( vr$491, 0, (integer)4 );
	label$436:;
	#define vr$492 ((FBSYMBOL$type**)(N$))
	#define vr$493 ((integer*)(N$))
	integer vr$494 = (integer)(SYMBCALCLEN( *(integer*)((ubyte *)vr$493 + 4), *(FBSYMBOL$type**)((ubyte *)vr$492 + 8) ));
	fb$result$ = (vr$494);
	{
		integer TMP$137$;
		#define vr$495 ((integer*)(N$))
		#define vr$496 ((integer)(*(integer*)((ubyte *)vr$495 + 4) & (integer)511))
		TMP$137$ = (vr$496);
		if (TMP$137$ == (FB_DATATYPE)3) goto label$440;
		label$441:;
		if (TMP$137$ == (FB_DATATYPE)6) goto label$440;
		label$442:;
		if (TMP$137$ != (FB_DATATYPE)18) goto label$439;
		label$440:;
		{
			#define vr$497 ((FBSYMBOL$type**)(N$))
			if (*(FBSYMBOL$type**)((ubyte *)vr$497 + 12) == (FBSYMBOL$type*)0) goto label$444;
			{
				#define vr$498 ((FBSYMBOL$type**)(N$))
				#define vr$499 ((integer*)(*(FBSYMBOL$type**)((ubyte *)vr$498 + 12)))
				fb$result$ = (*(integer*)((ubyte *)vr$499 + 36));
			};
			label$444:;
			label$443:;
		};
		label$439:;
		label$438:;
	};
	label$437:;
	#define vr$500 ((integer)(fb$result$))
	return vr$500;
}

integer ASTISACCESSTOLOCAL( ASTNODE$type* EXPR$ )
{
	integer fb$result$;
	#define vr$501 ((integer*)(&fb$result$))
	__builtin_memset( vr$501, 0, (integer)4 );
	label$445:;
	fb$result$ = ((integer)0);
	{
		AST_NODECLASS TMP$138$;
		#define vr$502 ((AST_NODECLASS*)(EXPR$))
		TMP$138$ = (*(AST_NODECLASS*)((ubyte *)vr$502));
		if (*(integer*)(&TMP$138$) == (AST_NODECLASS)17) goto label$449;
		label$450:;
		if (*(integer*)(&TMP$138$) != (AST_NODECLASS)18) goto label$448;
		label$449:;
		{
			#define vr$503 ((FBSYMBOL$type**)(EXPR$))
			#define vr$504 ((FB_SYMBATTRIB*)(*(FBSYMBOL$type**)((ubyte *)vr$503 + 12)))
			#define vr$505 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$504 + 4) & (FB_SYMBATTRIB)128))
			#define vr$506 ((integer)((-(vr$505 != (integer)0))))
			#define vr$507 ((FBSYMBOL$type**)(EXPR$))
			#define vr$508 ((FB_SYMBATTRIB*)(*(FBSYMBOL$type**)((ubyte *)vr$507 + 12)))
			#define vr$509 ((FB_SYMBATTRIB)(*(FB_SYMBATTRIB*)((ubyte *)vr$508 + 4) & (FB_SYMBATTRIB)2))
			#define vr$510 ((integer)((-(vr$509 != (integer)0))))
			#define vr$511 ((integer)(~(vr$510)))
			#define vr$512 ((integer)(vr$506 & vr$511))
			fb$result$ = (vr$512);
		};
		goto label$447;
		label$448:;
		if (*(integer*)(&TMP$138$) != (AST_NODECLASS)9) goto label$451;
		label$452:;
		{
			fb$result$ = ((integer)-1);
		};
		goto label$447;
		label$451:;
		if (*(integer*)(&TMP$138$) != (AST_NODECLASS)19) goto label$453;
		label$454:;
		{
			#define vr$513 ((ASTNODE$type**)(EXPR$))
			#define vr$514 ((AST_NODECLASS*)(*(ASTNODE$type**)((ubyte *)vr$513 + 56)))
			if (*(AST_NODECLASS*)((ubyte *)vr$514) != (AST_NODECLASS)20) goto label$456;
			{
				integer TMP$139$;
				#define vr$515 ((ASTNODE$type**)(EXPR$))
				#define vr$516 ((ASTNODE$type**)(*(ASTNODE$type**)((ubyte *)vr$515 + 56)))
				#define vr$517 ((AST_NODECLASS*)(*(ASTNODE$type**)((ubyte *)vr$516 + 56)))
				#define vr$518 ((integer)((-(*(AST_NODECLASS*)((ubyte *)vr$517) == (AST_NODECLASS)3))))
				if (vr$518 == (integer)0) goto label$457;
				#define vr$519 ((ASTNODE$type**)(EXPR$))
				#define vr$520 ((ASTNODE$type**)(*(ASTNODE$type**)((ubyte *)vr$519 + 56)))
				#define vr$521 ((integer*)(*(ASTNODE$type**)((ubyte *)vr$520 + 56)))
				#define vr$522 ((integer)((-(*(integer*)((ubyte *)vr$521 + 20) == (AST_OP)27))))
				#define vr$523 ((integer)((-(vr$522 != (integer)0))))
				TMP$139$ = (vr$523);
				goto label$462;
				label$457:;
				TMP$139$ = ((integer)0);
				label$462:;
				if (TMP$139$ == (integer)0) goto label$459;
				{
					#define vr$524 ((ASTNODE$type**)(EXPR$))
					#define vr$525 ((ASTNODE$type**)(*(ASTNODE$type**)((ubyte *)vr$524 + 56)))
					#define vr$526 ((ASTNODE$type**)(*(ASTNODE$type**)((ubyte *)vr$525 + 56)))
					#define vr$527 ((AST_NODECLASS*)(*(ASTNODE$type**)((ubyte *)vr$526 + 56)))
					if (*(AST_NODECLASS*)((ubyte *)vr$527) != (AST_NODECLASS)6) goto label$461;
					{
						#define vr$528 ((ASTNODE$type**)(EXPR$))
						#define vr$529 ((ASTNODE$type**)(*(ASTNODE$type**)((ubyte *)vr$528 + 56)))
						#define vr$530 ((ASTNODE$type**)(*(ASTNODE$type**)((ubyte *)vr$529 + 56)))
						#define vr$531 ((ASTNODE$type**)(*(ASTNODE$type**)((ubyte *)vr$530 + 56)))
						integer vr$532 = (integer)(ASTISACCESSTOLOCAL( *(ASTNODE$type**)((ubyte *)vr$531 + 56) ));
						fb$result$ = (vr$532);
					};
					label$461:;
					label$460:;
				};
				label$459:;
				label$458:;
			};
			label$456:;
			label$455:;
		};
		label$453:;
		label$447:;
	};
	label$446:;
	#define vr$533 ((integer)(fb$result$))
	return vr$533;
}

__attribute__(( constructor )) static void fb_ctor__astzmisc( void )
{
	label$0:;
	label$1:;
}

static void _ZN11TSTRSETITEMaSERS_( TSTRSETITEM* THIS$, TSTRSETITEM* __FB_RHS__$ )
{
	label$4:;
	fb_StrAssign( (TSTRSETITEM*)(THIS$), (integer)-1, (TSTRSETITEM*)(__FB_RHS__$), (integer)-1, (integer)0 );
	#define vr$534 ((integer*)((TSTRSETITEM*)(__FB_RHS__$)))
	#define vr$535 ((integer*)((TSTRSETITEM*)(THIS$)))
	*(integer*)((ubyte *)vr$535 + 12) = (*(integer*)((ubyte *)vr$534 + 12));
	label$5:;
}

static integer HHASDTOR( FBSYMBOL$type* SYM$ )
{
	integer fb$result$;
	#define vr$536 ((integer*)(&fb$result$))
	__builtin_memset( vr$536, 0, (integer)4 );
	label$360:;
	integer vr$537 = (integer)(SYMBHASDTOR( SYM$ ));
	fb$result$ = (vr$537);
	{
		FB_DATATYPE TMP$132$;
		#define vr$538 ((FB_DATATYPE*)(SYM$))
		#define vr$539 ((FB_DATATYPE)(*(FB_DATATYPE*)((ubyte *)vr$538 + 24) & (integer)511))
		TMP$132$ = (vr$539);
		if (*(integer*)(&TMP$132$) != (FB_DATATYPE)17) goto label$363;
		label$364:;
		{
			fb$result$ = ((integer)-1);
		};
		goto label$362;
		label$363:;
		if (*(integer*)(&TMP$132$) != (FB_DATATYPE)38) goto label$365;
		label$366:;
		{
			#define vr$540 ((FB_SYMBSTATS*)(SYM$))
			#define vr$541 ((FB_SYMBSTATS)(*(FB_SYMBSTATS*)((ubyte *)vr$540 + 8) & (FB_SYMBSTATS)16777216))
			if (vr$541 == (integer)0) goto label$368;
			{
				fb$result$ = ((integer)-1);
			};
			label$368:;
			label$367:;
		};
		label$365:;
		label$362:;
	};
	label$361:;
	#define vr$542 ((integer)(fb$result$))
	return vr$542;
}
// Total compilation time: 0.05678991321474314 seconds. 
