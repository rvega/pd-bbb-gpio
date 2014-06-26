// Compilation of ast-node-conv.bas started at 13:35:34 on 07-04-2013
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
	typedef int FB_DATACLASS;
	typedef int FB_ERRMSG;
typedef int AST_CONVOPT;
	typedef int FB_BACKEND;
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
			typedef void (*tmp$30)( IRVREG$type*, IRVREG$type* );
							typedef void (*tmp$37)( integer, IRVREG$type*, IRVREG$type* );
			typedef void (*tmp$60)( IRVREG$type*, integer, FBSYMBOL$type* );
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
#define fb_dtoui( v ) (uinteger)fb_dtosl( v )
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
#define fb_dtoss( v ) (short)fb_dtosi( v )
#define fb_dtous( v ) (ushort)fb_dtosi( v )
#define fb_dtosb( v ) (byte)fb_dtosi( v )
#define fb_dtoub( v ) (ubyte)fb_dtosi( v )
string* fb_StrAssign( void*, integer, void*, integer, integer );
void fb_StrDelete( string* );
static void fb_ctor__astznodezconv( void )__attribute__(( constructor )) ;
void ASTDELNODE( ASTNODE$type* );
ASTNODE$type* ASTNEWCONV( integer, FBSYMBOL$type*, ASTNODE$type*, AST_CONVOPT, integer* );
integer ASTCONSTISZERO( ASTNODE$type* );
ASTNODE$type* ASTNEWDEREF( ASTNODE$type*, integer, FBSYMBOL$type*, integer );
ASTNODE$type* ASTNEWADDROF( ASTNODE$type* );
ASTNODE$type* ASTNEWNODE( integer, integer, FBSYMBOL$type* );
IRVREG$type* ASTLOAD( ASTNODE$type* );
void ASTCHECKCONST( integer, ASTNODE$type* );
ASTNODE$type* ASTBUILDCALL( FBSYMBOL$type*, ASTNODE$type*, ASTNODE$type*, ASTNODE$type* );
void ASTSETTYPE( ASTNODE$type*, integer, FBSYMBOL$type* );
FBSYMBOL$type* SYMBFINDCASTOVLPROC( integer, FBSYMBOL$type*, ASTNODE$type*, FB_ERRMSG* );
integer SYMBGETUDTBASELEVEL( FBSYMBOL$type*, FBSYMBOL$type* );
ASTNODE$type* RTLSTRTOVAL( ASTNODE$type*, integer );
ASTNODE$type* RTLMATHFTOI( ASTNODE$type*, integer );
static void HCONVCONSTEVALINT( integer, ASTNODE$type* );
static void HCONVCONSTEVALFLT( integer, ASTNODE$type* );
static void HCONVCONSTEVAL64( integer, ASTNODE$type* );
static integer HGETTYPEMISMATCHERRMSG( AST_CONVOPT );
static integer HCHECKPTR( integer, FBSYMBOL$type*, integer, ASTNODE$type*, AST_CONVOPT );
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

integer ASTCHECKCONV( integer TO_DTYPE$, FBSYMBOL$type* TO_SUBTYPE$, ASTNODE$type* L$ )
{
	integer fb$result$;
	integer LDTYPE$;
	FB_DATATYPE TMP$108$;
	FB_DATATYPE TMP$109$;
	FB_DATATYPE TMP$112$;
	#define vr$0 ((integer*)(&fb$result$))
	__builtin_memset( vr$0, 0, (integer)4 );
	label$165:;
	fb$result$ = ((integer)0);
	#define vr$1 ((integer*)(L$))
	LDTYPE$ = (*(integer*)((ubyte *)vr$1 + 4));
	#define vr$2 ((integer)(TO_DTYPE$ & (integer)480))
	if (vr$2 == (integer)0) goto label$167;
	TMP$108$ = ((FB_DATATYPE)23);
	goto label$187;
	label$167:;
	#define vr$3 ((integer)(TO_DTYPE$ & (integer)31))
	#define vr$4 ((FB_DATATYPE)(vr$3))
	TMP$108$ = (vr$4);
	label$187:;
	#define vr$5 ((integer)((-(TMP$108$ == (FB_DATATYPE)19))))
	#define vr$6 ((integer)(LDTYPE$ & (integer)480))
	if (vr$6 == (integer)0) goto label$168;
	TMP$109$ = ((FB_DATATYPE)23);
	goto label$188;
	label$168:;
	#define vr$7 ((integer)(LDTYPE$ & (integer)31))
	#define vr$8 ((FB_DATATYPE)(vr$7))
	TMP$109$ = (vr$8);
	label$188:;
	#define vr$9 ((integer)((-(TMP$109$ == (FB_DATATYPE)19))))
	#define vr$10 ((integer)(vr$5 | vr$9))
	if (vr$10 == (integer)0) goto label$170;
	{
		FB_DATATYPE TMP$110$;
		FB_DATATYPE TMP$111$;
		#define vr$11 ((integer)(TO_DTYPE$ & (integer)480))
		if (vr$11 == (integer)0) goto label$171;
		TMP$110$ = ((FB_DATATYPE)23);
		goto label$189;
		label$171:;
		#define vr$12 ((integer)(TO_DTYPE$ & (integer)31))
		#define vr$13 ((FB_DATATYPE)(vr$12))
		TMP$110$ = (vr$13);
		label$189:;
		#define vr$14 ((integer)((-(TMP$110$ == (FB_DATATYPE)19))))
		#define vr$15 ((integer)(LDTYPE$ & (integer)480))
		if (vr$15 == (integer)0) goto label$172;
		TMP$111$ = ((FB_DATATYPE)23);
		goto label$190;
		label$172:;
		#define vr$16 ((integer)(LDTYPE$ & (integer)31))
		#define vr$17 ((FB_DATATYPE)(vr$16))
		TMP$111$ = (vr$17);
		label$190:;
		#define vr$18 ((integer)((-(TMP$111$ == (FB_DATATYPE)19))))
		#define vr$19 ((integer)(vr$14 & vr$18))
		if (vr$19 == (integer)0) goto label$174;
		{
			#define vr$20 ((FBSYMBOL$type**)(L$))
			integer vr$21 = (integer)(SYMBGETUDTBASELEVEL( *(FBSYMBOL$type**)((ubyte *)vr$20 + 8), TO_SUBTYPE$ ));
			#define vr$22 ((integer)((-(vr$21 > (integer)0))))
			fb$result$ = (vr$22);
		};
		label$174:;
		label$173:;
		goto label$166;
	};
	label$170:;
	label$169:;
	#define vr$23 ((integer)(LDTYPE$ & (integer)480))
	if (vr$23 == (integer)0) goto label$175;
	TMP$112$ = ((FB_DATATYPE)23);
	goto label$191;
	label$175:;
	#define vr$24 ((integer)(LDTYPE$ & (integer)31))
	#define vr$25 ((FB_DATATYPE)(vr$24))
	TMP$112$ = (vr$25);
	label$191:;
	#define vr$26 ((integer)(TMP$112$))
	#define vr$27 ((integer)(vr$26 * (integer)28))
	if (*(FB_DATACLASS*)((ubyte *)&SYMB_DTYPETB$ + vr$27) != (FB_DATACLASS)2) goto label$177;
	{
		goto label$166;
	};
	label$177:;
	label$176:;
	integer vr$28 = (integer)(HCHECKPTR( TO_DTYPE$, TO_SUBTYPE$, LDTYPE$, L$, (integer)0 ));
	if (vr$28 == (FB_ERRMSG)0) goto label$179;
	{
		goto label$166;
	};
	label$179:;
	label$178:;
	{
		FB_DATATYPE TMP$113$;
		FB_DATATYPE TMP$114$;
		#define vr$29 ((integer)(LDTYPE$ & (integer)480))
		if (vr$29 == (integer)0) goto label$180;
		TMP$113$ = ((FB_DATATYPE)23);
		goto label$192;
		label$180:;
		#define vr$30 ((integer)(LDTYPE$ & (integer)31))
		#define vr$31 ((FB_DATATYPE)(vr$30))
		TMP$113$ = (vr$31);
		label$192:;
		TMP$114$ = (TMP$113$);
		if (*(integer*)(&TMP$114$) == (FB_DATATYPE)3) goto label$183;
		label$184:;
		if (*(integer*)(&TMP$114$) != (FB_DATATYPE)6) goto label$182;
		label$183:;
		{
			#define vr$32 ((AST_NODECLASS*)(L$))
			#define vr$33 ((integer)((-(*(AST_NODECLASS*)((ubyte *)vr$32) == (AST_NODECLASS)20))))
			if (vr$33 != (integer)0) goto label$186;
			{
				goto label$166;
			};
			label$186:;
			label$185:;
		};
		label$182:;
		label$181:;
	};
	fb$result$ = ((integer)-1);
	label$166:;
	#define vr$34 ((integer)(fb$result$))
	return vr$34;
}

ASTNODE$type* ASTNEWCONV( integer TO_DTYPE$, FBSYMBOL$type* TO_SUBTYPE$, ASTNODE$type* L$, AST_CONVOPT OPTIONS$, integer* PERRMSG$ )
{
	ASTNODE$type* fb$result$;
	ASTNODE$type* N$;
	integer LDCLASS$;
	integer LDTYPE$;
	integer ERRMSG$;
	integer DOCONV$;
	FB_DATATYPE TMP$121$;
	FB_DATATYPE TMP$134$;
	#define vr$35 ((ASTNODE$type**)(&fb$result$))
	__builtin_memset( vr$35, 0, (integer)4 );
	label$193:;
	if (PERRMSG$ == (integer*)0) goto label$196;
	{
		#define vr$36 ((integer*)(PERRMSG$))
		*(integer*)((ubyte *)vr$36) = ((integer)0);
	};
	label$196:;
	label$195:;
	#define vr$37 ((integer*)(L$))
	LDTYPE$ = (*(integer*)((ubyte *)vr$37 + 4));
	#define vr$38 ((integer)(LDTYPE$ & (integer)511))
	#define vr$39 ((integer)(TO_DTYPE$ & (integer)511))
	if (vr$38 != vr$39) goto label$198;
	{
		#define vr$40 ((FBSYMBOL$type**)(L$))
		if (*(FBSYMBOL$type**)((ubyte *)vr$40 + 8) != TO_SUBTYPE$) goto label$200;
		{
			if (LDTYPE$ == TO_DTYPE$) goto label$202;
			{
				#define vr$41 ((AST_NODECLASS*)(L$))
				if (*(AST_NODECLASS*)((ubyte *)vr$41) != (AST_NODECLASS)16) goto label$204;
				{
					ASTSETTYPE( L$, TO_DTYPE$, TO_SUBTYPE$ );
					N$ = (L$);
				};
				goto label$203;
				label$204:;
				{
					ASTNODE$type* vr$42 = (ASTNODE$type*)(ASTNEWNODE( (AST_NODECLASS)5, TO_DTYPE$, TO_SUBTYPE$ ));
					N$ = (vr$42);
					#define vr$43 ((ASTNODE$type**)(N$))
					*(ASTNODE$type**)((ubyte *)vr$43 + 56) = (L$);
					#define vr$44 ((integer*)(N$))
					*(integer*)((ubyte *)vr$44 + 20) = ((integer)0);
					#define vr$45 ((integer*)(N$))
					*(integer*)((ubyte *)vr$45 + 24) = ((integer)0);
				};
				label$203:;
			};
			goto label$201;
			label$202:;
			{
				N$ = (L$);
			};
			label$201:;
			fb$result$ = (N$);
			goto label$194;
		};
		label$200:;
		label$199:;
	};
	label$198:;
	label$197:;
	{
		FBSYMBOL$type* PROC$;
		FB_ERRMSG ERR_NUM$;
		#define vr$46 ((FB_ERRMSG*)(&ERR_NUM$))
		FBSYMBOL$type* vr$47 = (FBSYMBOL$type*)(SYMBFINDCASTOVLPROC( TO_DTYPE$, TO_SUBTYPE$, L$, vr$46 ));
		PROC$ = (vr$47);
		if (PROC$ == (integer)0) goto label$206;
		{
			ASTNODE$type* vr$48 = (ASTNODE$type*)(ASTBUILDCALL( PROC$, L$, (integer)0, (integer)0 ));
			fb$result$ = (vr$48);
			goto label$194;
		};
		goto label$205;
		label$206:;
		{
			if (ERR_NUM$ == (FB_ERRMSG)0) goto label$208;
			{
				fb$result$ = ((ASTNODE$type*)0);
				goto label$194;
			};
			label$208:;
			label$207:;
		};
		label$205:;
	};
	{
		FB_DATATYPE TMP$115$;
		uinteger TMP$116$;
		#define vr$49 ((integer)(TO_DTYPE$ & (integer)480))
		if (vr$49 == (integer)0) goto label$209;
		TMP$115$ = ((FB_DATATYPE)23);
		goto label$306;
		label$209:;
		#define vr$50 ((integer)(TO_DTYPE$ & (integer)31))
		#define vr$51 ((FB_DATATYPE)(vr$50))
		TMP$115$ = (vr$51);
		label$306:;
		#define vr$52 ((uinteger)(TMP$115$))
		TMP$116$ = (vr$52);
		goto label$211;
		label$212:;
		{
			goto label$194;
		};
		goto label$210;
		label$213:;
		{
			FB_DATATYPE TMP$117$;
			#define vr$53 ((integer)(LDTYPE$ & (integer)480))
			if (vr$53 == (integer)0) goto label$214;
			TMP$117$ = ((FB_DATATYPE)23);
			goto label$307;
			label$214:;
			#define vr$54 ((integer)(LDTYPE$ & (integer)31))
			#define vr$55 ((FB_DATATYPE)(vr$54))
			TMP$117$ = (vr$55);
			label$307:;
			if (TMP$117$ == (FB_DATATYPE)19) goto label$216;
			{
				goto label$194;
			};
			label$216:;
			label$215:;
			#define vr$56 ((FBSYMBOL$type**)(L$))
			integer vr$57 = (integer)(SYMBGETUDTBASELEVEL( *(FBSYMBOL$type**)((ubyte *)vr$56 + 8), TO_SUBTYPE$ ));
			if (vr$57 != (integer)0) goto label$218;
			{
				goto label$194;
			};
			label$218:;
			label$217:;
		};
		goto label$210;
		label$219:;
		{
			FB_DATATYPE TMP$118$;
			#define vr$58 ((integer)(LDTYPE$ & (integer)480))
			if (vr$58 == (integer)0) goto label$220;
			TMP$118$ = ((FB_DATATYPE)23);
			goto label$308;
			label$220:;
			#define vr$59 ((integer)(LDTYPE$ & (integer)31))
			#define vr$60 ((FB_DATATYPE)(vr$59))
			TMP$118$ = (vr$60);
			label$308:;
			if (TMP$118$ != (FB_DATATYPE)19) goto label$222;
			{
				goto label$194;
			};
			label$222:;
			label$221:;
		};
		goto label$210;
		label$211:;
		if (TMP$116$ > (uinteger)19u) goto label$219;
		static const void * LABEL$223$[] = {
			&&label$212,
			&&label$219,
			&&label$219,
			&&label$219,
			&&label$219,
			&&label$219,
			&&label$219,
			&&label$219,
			&&label$219,
			&&label$219,
			&&label$219,
			&&label$219,
			&&label$219,
			&&label$219,
			&&label$219,
			&&label$219,
			&&label$219,
			&&label$212,
			&&label$219,
			&&label$213,
		(void *)0 };
		#define vr$61 ((uinteger)(TMP$116$ << (uinteger)2u))
		goto **(void**)((ubyte *)LABEL$223$ + vr$61);
		label$210:;
	};
	#define vr$62 ((integer)(LDTYPE$ & (integer)480))
	if (vr$62 == (integer)0) goto label$224;
	TMP$121$ = ((FB_DATATYPE)23);
	goto label$309;
	label$224:;
	#define vr$63 ((integer)(LDTYPE$ & (integer)31))
	#define vr$64 ((FB_DATATYPE)(vr$63))
	TMP$121$ = (vr$64);
	label$309:;
	#define vr$65 ((integer)(TMP$121$))
	#define vr$66 ((integer)(vr$65 * (integer)28))
	#define vr$67 ((integer)(*(FB_DATACLASS*)((ubyte *)&SYMB_DTYPETB$ + vr$66)))
	LDCLASS$ = (vr$67);
	#define vr$68 ((AST_CONVOPT)(OPTIONS$ & (AST_CONVOPT)1))
	if (vr$68 == (AST_CONVOPT)0) goto label$226;
	{
		if (LDCLASS$ == (FB_DATACLASS)0) goto label$228;
		{
			goto label$194;
		};
		label$228:;
		label$227:;
	};
	label$226:;
	label$225:;
	#define vr$69 ((AST_CONVOPT)(OPTIONS$ & (AST_CONVOPT)8))
	if (vr$69 != (integer)0) goto label$230;
	{
		integer vr$70 = (integer)(HCHECKPTR( TO_DTYPE$, TO_SUBTYPE$, LDTYPE$, L$, OPTIONS$ ));
		ERRMSG$ = (vr$70);
		if (ERRMSG$ == (FB_ERRMSG)0) goto label$232;
		{
			if (PERRMSG$ == (integer*)0) goto label$234;
			{
				#define vr$71 ((integer*)(PERRMSG$))
				*(integer*)((ubyte *)vr$71) = (ERRMSG$);
			};
			label$234:;
			label$233:;
			goto label$194;
		};
		label$232:;
		label$231:;
	};
	label$230:;
	label$229:;
	#define vr$72 ((AST_CONVOPT)(OPTIONS$ & (AST_CONVOPT)2))
	if (vr$72 == (AST_CONVOPT)0) goto label$236;
	{
		{
			FB_DATATYPE TMP$122$;
			uinteger TMP$123$;
			#define vr$73 ((integer)(LDTYPE$ & (integer)480))
			if (vr$73 == (integer)0) goto label$237;
			TMP$122$ = ((FB_DATATYPE)23);
			goto label$310;
			label$237:;
			#define vr$74 ((integer)(LDTYPE$ & (integer)31))
			#define vr$75 ((FB_DATATYPE)(vr$74))
			TMP$122$ = (vr$75);
			label$310:;
			#define vr$76 ((uinteger)(TMP$122$))
			TMP$123$ = (vr$76);
			goto label$239;
			label$240:;
			{
				ASTNODE$type* vr$77 = (ASTNODE$type*)(RTLSTRTOVAL( L$, TO_DTYPE$ ));
				fb$result$ = (vr$77);
				goto label$194;
			};
			goto label$238;
			label$239:;
			if (TMP$123$ < (uinteger)3u) goto label$238;
			if (TMP$123$ > (uinteger)18u) goto label$238;
			static const void * LABEL$241$[] = {
				&&label$240,
				&&label$238,
				&&label$238,
				&&label$240,
				&&label$238,
				&&label$238,
				&&label$238,
				&&label$238,
				&&label$238,
				&&label$238,
				&&label$238,
				&&label$238,
				&&label$238,
				&&label$238,
				&&label$240,
				&&label$240,
			(void *)0 };
			#define vr$78 ((uinteger)(TMP$123$ << (uinteger)2u))
			goto **(void**)((ubyte *)LABEL$241$ + vr$78 + -12);
			label$238:;
		};
	};
	goto label$235;
	label$236:;
	{
		if (LDCLASS$ != (FB_DATACLASS)2) goto label$243;
		{
			goto label$194;
		};
		goto label$242;
		label$243:;
		{
			{
				FB_DATATYPE TMP$126$;
				FB_DATATYPE TMP$127$;
				#define vr$79 ((integer)(LDTYPE$ & (integer)480))
				if (vr$79 == (integer)0) goto label$244;
				TMP$126$ = ((FB_DATATYPE)23);
				goto label$311;
				label$244:;
				#define vr$80 ((integer)(LDTYPE$ & (integer)31))
				#define vr$81 ((FB_DATATYPE)(vr$80))
				TMP$126$ = (vr$81);
				label$311:;
				TMP$127$ = (TMP$126$);
				if (*(integer*)(&TMP$127$) == (FB_DATATYPE)3) goto label$247;
				label$248:;
				if (*(integer*)(&TMP$127$) != (FB_DATATYPE)6) goto label$246;
				label$247:;
				{
					#define vr$82 ((AST_NODECLASS*)(L$))
					#define vr$83 ((integer)((-(*(AST_NODECLASS*)((ubyte *)vr$82) == (AST_NODECLASS)20))))
					if (vr$83 != (integer)0) goto label$250;
					{
						goto label$194;
					};
					label$250:;
					label$249:;
				};
				label$246:;
				label$245:;
			};
		};
		label$242:;
	};
	label$235:;
	#define vr$84 ((AST_NODECLASS*)(L$))
	if (*(AST_NODECLASS*)((ubyte *)vr$84) != (AST_NODECLASS)16) goto label$252;
	{
		ASTCHECKCONST( TO_DTYPE$, L$ );
		{
			FB_DATATYPE TMP$128$;
			uinteger TMP$129$;
			#define vr$85 ((integer)(TO_DTYPE$ & (integer)480))
			if (vr$85 == (integer)0) goto label$253;
			TMP$128$ = ((FB_DATATYPE)23);
			goto label$312;
			label$253:;
			#define vr$86 ((integer)(TO_DTYPE$ & (integer)31))
			#define vr$87 ((FB_DATATYPE)(vr$86))
			TMP$128$ = (vr$87);
			label$312:;
			#define vr$88 ((uinteger)(TMP$128$))
			TMP$129$ = (vr$88);
			goto label$255;
			label$256:;
			{
				HCONVCONSTEVAL64( TO_DTYPE$, L$ );
			};
			goto label$254;
			label$257:;
			{
				HCONVCONSTEVALFLT( TO_DTYPE$, L$ );
			};
			goto label$254;
			label$258:;
			{
				{
					HCONVCONSTEVALINT( TO_DTYPE$, L$ );
				};
				goto label$259;
				label$260:;
				{
					HCONVCONSTEVAL64( TO_DTYPE$, L$ );
				};
				label$259:;
			};
			goto label$254;
			label$261:;
			{
				HCONVCONSTEVALINT( TO_DTYPE$, L$ );
			};
			goto label$254;
			label$255:;
			if (TMP$129$ < (uinteger)11u) goto label$261;
			if (TMP$129$ > (uinteger)16u) goto label$261;
			static const void * LABEL$262$[] = {
				&&label$258,
				&&label$258,
				&&label$256,
				&&label$256,
				&&label$257,
				&&label$257,
			(void *)0 };
			#define vr$89 ((uinteger)(TMP$129$ << (uinteger)2u))
			goto **(void**)((ubyte *)LABEL$262$ + vr$89 + -44);
			label$254:;
		};
		#define vr$90 ((integer*)(L$))
		*(integer*)((ubyte *)vr$90 + 4) = (TO_DTYPE$);
		#define vr$91 ((FBSYMBOL$type**)(L$))
		*(FBSYMBOL$type**)((ubyte *)vr$91 + 8) = (TO_SUBTYPE$);
		fb$result$ = (L$);
		goto label$194;
	};
	label$252:;
	label$251:;
	if (*(FB_BACKEND*)((ubyte *)&ENV$ + 104) != (FB_BACKEND)1) goto label$264;
	{
		FB_DATATYPE TMP$132$;
		#define vr$92 ((integer)((-(LDCLASS$ == (FB_DATACLASS)1))))
		#define vr$93 ((integer)(TO_DTYPE$ & (integer)480))
		if (vr$93 == (integer)0) goto label$265;
		TMP$132$ = ((FB_DATATYPE)23);
		goto label$313;
		label$265:;
		#define vr$94 ((integer)(TO_DTYPE$ & (integer)31))
		#define vr$95 ((FB_DATATYPE)(vr$94))
		TMP$132$ = (vr$95);
		label$313:;
		#define vr$96 ((integer)(TMP$132$))
		#define vr$97 ((integer)(vr$96 * (integer)28))
		#define vr$98 ((integer)((-(*(FB_DATACLASS*)((ubyte *)&SYMB_DTYPETB$ + vr$97) == (FB_DATACLASS)0))))
		#define vr$99 ((integer)(vr$92 & vr$98))
		if (vr$99 == (integer)0) goto label$267;
		{
			ASTNODE$type* vr$100 = (ASTNODE$type*)(RTLMATHFTOI( L$, TO_DTYPE$ ));
			fb$result$ = (vr$100);
			goto label$194;
		};
		goto label$266;
		label$267:;
		{
			{
				integer TMP$133$;
				#define vr$101 ((integer)(TO_DTYPE$ & (integer)511))
				TMP$133$ = (vr$101);
				if (TMP$133$ != (FB_DATATYPE)19) goto label$269;
				label$270:;
				{
					ASTNODE$type* vr$102 = (ASTNODE$type*)(ASTNEWADDROF( L$ ));
					#define vr$103 ((integer)(TO_DTYPE$ & (integer)31))
					#define vr$104 ((integer)(TO_DTYPE$ & (integer)480))
					#define vr$105 ((integer)(vr$104 + (integer)32))
					#define vr$106 ((integer)(vr$103 | vr$105))
					#define vr$107 ((integer)(TO_DTYPE$ & (integer)261632))
					#define vr$108 ((integer)(vr$107 << (integer)1))
					#define vr$109 ((integer)(vr$106 | vr$108))
					ASTNODE$type* vr$110 = (ASTNODE$type*)(ASTNEWCONV( vr$109, TO_SUBTYPE$, vr$102, (integer)0, (integer)0 ));
					ASTNODE$type* vr$111 = (ASTNODE$type*)(ASTNEWDEREF( vr$110, (integer)-2147483648u, (integer)0, (integer)0 ));
					fb$result$ = (vr$111);
					goto label$194;
				};
				label$269:;
				label$268:;
			};
		};
		label$266:;
	};
	label$264:;
	label$263:;
	DOCONV$ = ((integer)-1);
	#define vr$112 ((integer)(TO_DTYPE$ & (integer)480))
	if (vr$112 == (integer)0) goto label$271;
	TMP$134$ = ((FB_DATATYPE)23);
	goto label$314;
	label$271:;
	#define vr$113 ((integer)(TO_DTYPE$ & (integer)31))
	#define vr$114 ((FB_DATATYPE)(vr$113))
	TMP$134$ = (vr$114);
	label$314:;
	#define vr$115 ((integer)(TMP$134$))
	#define vr$116 ((integer)(vr$115 * (integer)28))
	if (LDCLASS$ != *(FB_DATACLASS*)((ubyte *)&SYMB_DTYPETB$ + vr$116)) goto label$273;
	{
		{
			FB_DATATYPE TMP$135$;
			FB_DATATYPE TMP$136$;
			#define vr$117 ((integer)(TO_DTYPE$ & (integer)480))
			if (vr$117 == (integer)0) goto label$274;
			TMP$135$ = ((FB_DATATYPE)23);
			goto label$315;
			label$274:;
			#define vr$118 ((integer)(TO_DTYPE$ & (integer)31))
			#define vr$119 ((FB_DATATYPE)(vr$118))
			TMP$135$ = (vr$119);
			label$315:;
			TMP$136$ = (TMP$135$);
			if (*(integer*)(&TMP$136$) != (FB_DATATYPE)19) goto label$276;
			label$277:;
			{
				DOCONV$ = ((integer)0);
			};
			goto label$275;
			label$276:;
			{
				FB_DATATYPE TMP$137$;
				FB_DATATYPE TMP$138$;
				#define vr$120 ((integer)(LDTYPE$ & (integer)480))
				if (vr$120 == (integer)0) goto label$279;
				TMP$137$ = ((FB_DATATYPE)23);
				goto label$316;
				label$279:;
				#define vr$121 ((integer)(LDTYPE$ & (integer)31))
				#define vr$122 ((FB_DATATYPE)(vr$121))
				TMP$137$ = (vr$122);
				label$316:;
				#define vr$123 ((integer)(TMP$137$))
				#define vr$124 ((integer)(vr$123 * (integer)28))
				#define vr$125 ((integer)(TO_DTYPE$ & (integer)480))
				if (vr$125 == (integer)0) goto label$280;
				TMP$138$ = ((FB_DATATYPE)23);
				goto label$317;
				label$280:;
				#define vr$126 ((integer)(TO_DTYPE$ & (integer)31))
				#define vr$127 ((FB_DATATYPE)(vr$126))
				TMP$138$ = (vr$127);
				label$317:;
				#define vr$128 ((integer)(TMP$138$))
				#define vr$129 ((integer)(vr$128 * (integer)28))
				if (*(integer*)((ubyte *)&SYMB_DTYPETB$ + vr$124 + 4) != *(integer*)((ubyte *)&SYMB_DTYPETB$ + vr$129 + 4)) goto label$282;
				{
					DOCONV$ = ((integer)0);
				};
				label$282:;
				label$281:;
			};
			label$278:;
			label$275:;
		};
	};
	label$273:;
	label$272:;
	#define vr$130 ((IR_OPT)(*(IR_OPT*)((ubyte *)&IR$ + 292) & (IR_OPT)1))
	if (vr$130 == (integer)0) goto label$284;
	{
		FB_DATATYPE TMP$139$;
		#define vr$131 ((integer)((-(LDCLASS$ == (FB_DATACLASS)1))))
		#define vr$132 ((integer)(TO_DTYPE$ & (integer)480))
		if (vr$132 == (integer)0) goto label$285;
		TMP$139$ = ((FB_DATATYPE)23);
		goto label$318;
		label$285:;
		#define vr$133 ((integer)(TO_DTYPE$ & (integer)31))
		#define vr$134 ((FB_DATATYPE)(vr$133))
		TMP$139$ = (vr$134);
		label$318:;
		#define vr$135 ((integer)(TMP$139$))
		#define vr$136 ((integer)(vr$135 * (integer)28))
		#define vr$137 ((integer)((-(*(FB_DATACLASS*)((ubyte *)&SYMB_DTYPETB$ + vr$136) == (FB_DATACLASS)1))))
		#define vr$138 ((integer)(vr$131 & vr$137))
		if (vr$138 == (integer)0) goto label$287;
		{
			FB_DATATYPE TMP$140$;
			FB_DATATYPE TMP$141$;
			#define vr$139 ((integer)(LDTYPE$ & (integer)480))
			if (vr$139 == (integer)0) goto label$288;
			TMP$140$ = ((FB_DATATYPE)23);
			goto label$319;
			label$288:;
			#define vr$140 ((integer)(LDTYPE$ & (integer)31))
			#define vr$141 ((FB_DATATYPE)(vr$140))
			TMP$140$ = (vr$141);
			label$319:;
			#define vr$142 ((integer)(TMP$140$))
			#define vr$143 ((integer)(vr$142 * (integer)28))
			#define vr$144 ((integer)(TO_DTYPE$ & (integer)480))
			if (vr$144 == (integer)0) goto label$289;
			TMP$141$ = ((FB_DATATYPE)23);
			goto label$320;
			label$289:;
			#define vr$145 ((integer)(TO_DTYPE$ & (integer)31))
			#define vr$146 ((FB_DATATYPE)(vr$145))
			TMP$141$ = (vr$146);
			label$320:;
			#define vr$147 ((integer)(TMP$141$))
			#define vr$148 ((integer)(vr$147 * (integer)28))
			if (*(integer*)((ubyte *)&SYMB_DTYPETB$ + vr$143 + 4) == *(integer*)((ubyte *)&SYMB_DTYPETB$ + vr$148 + 4)) goto label$291;
			{
				DOCONV$ = ((integer)-1);
			};
			label$291:;
			label$290:;
		};
		label$287:;
		label$286:;
	};
	label$284:;
	label$283:;
	#define vr$149 ((AST_NODECLASS*)(L$))
	if (*(AST_NODECLASS*)((ubyte *)vr$149) != (AST_NODECLASS)5) goto label$293;
	{
		#define vr$150 ((integer*)(L$))
		if (*(integer*)((ubyte *)vr$150 + 20) != (integer)0) goto label$295;
		{
			if (DOCONV$ != (integer)0) goto label$297;
			{
				#define vr$151 ((integer*)(L$))
				*(integer*)((ubyte *)vr$151 + 4) = (TO_DTYPE$);
				#define vr$152 ((FBSYMBOL$type**)(L$))
				*(FBSYMBOL$type**)((ubyte *)vr$152 + 8) = (TO_SUBTYPE$);
				fb$result$ = (L$);
				goto label$194;
			};
			label$297:;
			label$296:;
		};
		label$295:;
		label$294:;
	};
	label$293:;
	label$292:;
	ASTNODE$type* vr$153 = (ASTNODE$type*)(ASTNEWNODE( (AST_NODECLASS)5, TO_DTYPE$, TO_SUBTYPE$ ));
	N$ = (vr$153);
	#define vr$154 ((ASTNODE$type**)(N$))
	*(ASTNODE$type**)((ubyte *)vr$154 + 56) = (L$);
	#define vr$155 ((integer*)(N$))
	*(integer*)((ubyte *)vr$155 + 20) = (DOCONV$);
	#define vr$156 ((integer*)(N$))
	*(integer*)((ubyte *)vr$156 + 24) = ((integer)0);
	if (*(FB_BACKEND*)((ubyte *)&ENV$ + 104) != (FB_BACKEND)0) goto label$299;
	{
		if (DOCONV$ == (integer)0) goto label$301;
		{
			FB_DATATYPE TMP$142$;
			#define vr$157 ((integer)(LDTYPE$ & (integer)480))
			if (vr$157 == (integer)0) goto label$302;
			TMP$142$ = ((FB_DATATYPE)23);
			goto label$321;
			label$302:;
			#define vr$158 ((integer)(LDTYPE$ & (integer)31))
			#define vr$159 ((FB_DATATYPE)(vr$158))
			TMP$142$ = (vr$159);
			label$321:;
			if (TMP$142$ != (FB_DATATYPE)16) goto label$304;
			{
				FB_DATATYPE TMP$143$;
				#define vr$160 ((integer)(TO_DTYPE$ & (integer)480))
				if (vr$160 == (integer)0) goto label$305;
				TMP$143$ = ((FB_DATATYPE)23);
				goto label$322;
				label$305:;
				#define vr$161 ((integer)(TO_DTYPE$ & (integer)31))
				#define vr$162 ((FB_DATATYPE)(vr$161))
				TMP$143$ = (vr$162);
				label$322:;
				#define vr$163 ((integer)((-(TMP$143$ == (FB_DATATYPE)15))))
				#define vr$164 ((integer*)(N$))
				*(integer*)((ubyte *)vr$164 + 24) = (vr$163);
			};
			label$304:;
			label$303:;
		};
		label$301:;
		label$300:;
	};
	label$299:;
	label$298:;
	fb$result$ = (N$);
	label$194:;
	#define vr$165 ((ASTNODE$type*)(fb$result$))
	return vr$165;
}

ASTNODE$type* ASTNEWOVLCONV( integer TO_DTYPE$, FBSYMBOL$type* TO_SUBTYPE$, ASTNODE$type* L$ )
{
	ASTNODE$type* fb$result$;
	#define vr$166 ((ASTNODE$type**)(&fb$result$))
	__builtin_memset( vr$166, 0, (integer)4 );
	label$323:;
	{
		FBSYMBOL$type* PROC$;
		FB_ERRMSG ERR_NUM$;
		#define vr$167 ((FB_ERRMSG*)(&ERR_NUM$))
		FBSYMBOL$type* vr$168 = (FBSYMBOL$type*)(SYMBFINDCASTOVLPROC( TO_DTYPE$, TO_SUBTYPE$, L$, vr$167 ));
		PROC$ = (vr$168);
		if (PROC$ == (integer)0) goto label$326;
		{
			ASTNODE$type* vr$169 = (ASTNODE$type*)(ASTBUILDCALL( PROC$, L$, (integer)0, (integer)0 ));
			fb$result$ = (vr$169);
			goto label$324;
		};
		goto label$325;
		label$326:;
		{
			if (ERR_NUM$ == (FB_ERRMSG)0) goto label$328;
			{
				fb$result$ = ((ASTNODE$type*)0);
				goto label$324;
			};
			label$328:;
			label$327:;
		};
		label$325:;
	};
	fb$result$ = (L$);
	label$324:;
	#define vr$170 ((ASTNODE$type*)(fb$result$))
	return vr$170;
}

void ASTUPDATECONVFD2FS( ASTNODE$type* N$, integer TO_DTYPE$, integer IS_EXPR$ )
{
	FB_DATATYPE TMP$144$;
	FB_DATATYPE TMP$145$;
	label$329:;
	#define vr$171 ((integer*)(N$))
	if (*(integer*)((ubyte *)vr$171 + 24) != (integer)0) goto label$332;
	{
		goto label$330;
	};
	label$332:;
	label$331:;
	#define vr$172 ((integer)(TO_DTYPE$ & (integer)480))
	if (vr$172 == (integer)0) goto label$333;
	TMP$144$ = ((FB_DATATYPE)23);
	goto label$337;
	label$333:;
	#define vr$173 ((integer)(TO_DTYPE$ & (integer)31))
	#define vr$174 ((FB_DATATYPE)(vr$173))
	TMP$144$ = (vr$174);
	label$337:;
	#define vr$175 ((integer)(TMP$144$))
	#define vr$176 ((integer)(vr$175 * (integer)28))
	#define vr$177 ((integer)((-(*(integer*)((ubyte *)&SYMB_DTYPETB$ + vr$176 + 4) >= (integer)4))))
	#define vr$178 ((integer*)(N$))
	*(integer*)((ubyte *)vr$178 + 24) = (vr$177);
	#define vr$179 ((integer)(TO_DTYPE$ & (integer)480))
	if (vr$179 == (integer)0) goto label$334;
	TMP$145$ = ((FB_DATATYPE)23);
	goto label$338;
	label$334:;
	#define vr$180 ((integer)(TO_DTYPE$ & (integer)31))
	#define vr$181 ((FB_DATATYPE)(vr$180))
	TMP$145$ = (vr$181);
	label$338:;
	if (TMP$145$ != (FB_DATATYPE)15) goto label$336;
	{
		#define vr$182 ((integer*)(N$))
		*(integer*)((ubyte *)vr$182 + 24) = (IS_EXPR$);
	};
	label$336:;
	label$335:;
	label$330:;
}

IRVREG$type* ASTLOADCONV( ASTNODE$type* N$ )
{
	IRVREG$type* fb$result$;
	ASTNODE$type* L$;
	IRVREG$type* VS$;
	IRVREG$type* VR$;
	#define vr$183 ((IRVREG$type**)(&fb$result$))
	__builtin_memset( vr$183, 0, (integer)4 );
	label$339:;
	#define vr$184 ((ASTNODE$type**)(N$))
	L$ = (*(ASTNODE$type**)((ubyte *)vr$184 + 56));
	if (L$ != (integer)0) goto label$342;
	{
		fb$result$ = ((IRVREG$type*)0);
		goto label$340;
	};
	label$342:;
	label$341:;
	IRVREG$type* vr$185 = (IRVREG$type*)(ASTLOAD( L$ ));
	VS$ = (vr$185);
	if (*(integer*)((ubyte *)&AST$ + 136) == (integer)0) goto label$344;
	{
		#define vr$186 ((integer*)(N$))
		#define vr$187 ((integer*)(VS$))
		*(integer*)((ubyte *)vr$187 + 20) = (*(integer*)((ubyte *)vr$186 + 16));
		#define vr$188 ((integer*)(N$))
		if (*(integer*)((ubyte *)vr$188 + 20) == (integer)0) goto label$346;
		{
			#define vr$189 ((FBSYMBOL$type**)(N$))
			#define vr$190 ((integer*)(N$))
			#define vr$191 ((integer)(*(integer*)((ubyte *)vr$190 + 4) & (integer)511))
			IRVREG$type* vr$192 = (IRVREG$type*)((*(tmp$53*)((ubyte *)&IR$ + 240))( vr$191, *(FBSYMBOL$type**)((ubyte *)vr$189 + 8) ));
			VR$ = (vr$192);
			#define vr$193 ((integer*)(N$))
			#define vr$194 ((integer*)(VR$))
			*(integer*)((ubyte *)vr$194 + 20) = (*(integer*)((ubyte *)vr$193 + 16));
			(*(tmp$30*)((ubyte *)&IR$ + 56))( VR$, VS$ );
			#define vr$195 ((integer*)(N$))
			if (*(integer*)((ubyte *)vr$195 + 24) == (integer)0) goto label$348;
			{
				#define vr$196 ((FB_DATATYPE*)(VS$))
				if (*(FB_DATATYPE*)((ubyte *)vr$196 + 4) != (FB_DATATYPE)16) goto label$350;
				{
					#define vr$197 ((FB_DATATYPE*)(VR$))
					if (*(FB_DATATYPE*)((ubyte *)vr$197 + 4) != (FB_DATATYPE)15) goto label$352;
					{
						#define vr$198 ((IR_REGFAMILY*)(VR$))
						if (*(IR_REGFAMILY*)((ubyte *)vr$198 + 16) != (IR_REGFAMILY)0) goto label$354;
						{
							(*(tmp$37*)((ubyte *)&IR$ + 108))( (AST_OP)72, VR$, (integer)0 );
						};
						label$354:;
						label$353:;
					};
					label$352:;
					label$351:;
				};
				label$350:;
				label$349:;
			};
			label$348:;
			label$347:;
		};
		goto label$345;
		label$346:;
		{
			VR$ = (VS$);
			#define vr$199 ((FBSYMBOL$type**)(N$))
			#define vr$200 ((integer*)(N$))
			#define vr$201 ((integer)(*(integer*)((ubyte *)vr$200 + 4) & (integer)511))
			(*(tmp$60*)((ubyte *)&IR$ + 272))( VR$, vr$201, *(FBSYMBOL$type**)((ubyte *)vr$199 + 8) );
		};
		label$345:;
	};
	label$344:;
	label$343:;
	ASTDELNODE( L$ );
	fb$result$ = (VR$);
	label$340:;
	#define vr$202 ((IRVREG$type*)(fb$result$))
	return vr$202;
}

__attribute__(( constructor )) static void fb_ctor__astznodezconv( void )
{
	label$0:;
	label$1:;
}

static void _ZN11TSTRSETITEMaSERS_( TSTRSETITEM* THIS$, TSTRSETITEM* __FB_RHS__$ )
{
	label$4:;
	fb_StrAssign( (TSTRSETITEM*)(THIS$), (integer)-1, (TSTRSETITEM*)(__FB_RHS__$), (integer)-1, (integer)0 );
	#define vr$203 ((integer*)((TSTRSETITEM*)(__FB_RHS__$)))
	#define vr$204 ((integer*)((TSTRSETITEM*)(THIS$)))
	*(integer*)((ubyte *)vr$204 + 12) = (*(integer*)((ubyte *)vr$203 + 12));
	label$5:;
}

static void HCONVCONSTEVALINT( integer TO_DTYPE$, ASTNODE$type* V$ )
{
	integer VDTYPE$;
	FB_DATATYPE TMP$73$;
	FB_DATATYPE TMP$74$;
	label$10:;
	#define vr$205 ((integer*)(V$))
	#define vr$206 ((integer)(*(integer*)((ubyte *)vr$205 + 4) & (integer)480))
	if (vr$206 == (integer)0) goto label$12;
	TMP$73$ = ((FB_DATATYPE)23);
	goto label$355;
	label$12:;
	#define vr$207 ((integer*)(V$))
	#define vr$208 ((integer)(*(integer*)((ubyte *)vr$207 + 4) & (integer)31))
	#define vr$209 ((FB_DATATYPE)(vr$208))
	TMP$73$ = (vr$209);
	label$355:;
	#define vr$210 ((integer)(TMP$73$))
	VDTYPE$ = (vr$210);
	#define vr$211 ((integer)(TO_DTYPE$ & (integer)480))
	if (vr$211 == (integer)0) goto label$13;
	TMP$74$ = ((FB_DATATYPE)23);
	goto label$356;
	label$13:;
	#define vr$212 ((integer)(TO_DTYPE$ & (integer)31))
	#define vr$213 ((FB_DATATYPE)(vr$212))
	TMP$74$ = (vr$213);
	label$356:;
	#define vr$214 ((integer)(TMP$74$))
	TO_DTYPE$ = (vr$214);
	{
		uinteger TMP$75$;
		#define vr$215 ((uinteger)(VDTYPE$))
		TMP$75$ = (vr$215);
		goto label$15;
		label$16:;
		{
			{
				uinteger TMP$76$;
				#define vr$216 ((uinteger)(TO_DTYPE$))
				TMP$76$ = (vr$216);
				goto label$18;
				label$19:;
				{
					#define vr$217 ((longint*)(V$))
					#define vr$218 ((byte)(*(longint*)((ubyte *)vr$217 + 20)))
					#define vr$219 ((integer)(vr$218))
					#define vr$220 ((integer*)(V$))
					*(integer*)((ubyte *)vr$220 + 20) = (vr$219);
				};
				goto label$17;
				label$20:;
				{
					#define vr$221 ((longint*)(V$))
					#define vr$222 ((ulongint)(*(longint*)((ubyte *)vr$221 + 20)))
					#define vr$223 ((ubyte)(vr$222))
					#define vr$224 ((integer)(vr$223))
					#define vr$225 ((integer*)(V$))
					*(integer*)((ubyte *)vr$225 + 20) = (vr$224);
				};
				goto label$17;
				label$21:;
				{
					#define vr$226 ((longint*)(V$))
					#define vr$227 ((short)(*(longint*)((ubyte *)vr$226 + 20)))
					#define vr$228 ((integer)(vr$227))
					#define vr$229 ((integer*)(V$))
					*(integer*)((ubyte *)vr$229 + 20) = (vr$228);
				};
				goto label$17;
				label$22:;
				{
					#define vr$230 ((longint*)(V$))
					#define vr$231 ((ulongint)(*(longint*)((ubyte *)vr$230 + 20)))
					#define vr$232 ((ushort)(vr$231))
					#define vr$233 ((integer)(vr$232))
					#define vr$234 ((integer*)(V$))
					*(integer*)((ubyte *)vr$234 + 20) = (vr$233);
				};
				goto label$17;
				label$23:;
				{
					#define vr$235 ((longint*)(V$))
					#define vr$236 ((integer)(*(longint*)((ubyte *)vr$235 + 20)))
					#define vr$237 ((integer*)(V$))
					*(integer*)((ubyte *)vr$237 + 20) = (vr$236);
				};
				goto label$17;
				label$24:;
				{
					#define vr$238 ((longint*)(V$))
					#define vr$239 ((ulongint)(*(longint*)((ubyte *)vr$238 + 20)))
					#define vr$240 ((uinteger)(vr$239))
					#define vr$241 ((uinteger*)(V$))
					*(uinteger*)((ubyte *)vr$241 + 20) = (vr$240);
				};
				goto label$17;
				label$18:;
				if (TMP$76$ < (uinteger)1u) goto label$17;
				if (TMP$76$ > (uinteger)23u) goto label$17;
				static const void * LABEL$25$[] = {
					&&label$19,
					&&label$20,
					&&label$17,
					&&label$21,
					&&label$22,
					&&label$17,
					&&label$23,
					&&label$24,
					&&label$23,
					&&label$17,
					&&label$23,
					&&label$24,
					&&label$17,
					&&label$17,
					&&label$17,
					&&label$17,
					&&label$17,
					&&label$17,
					&&label$17,
					&&label$17,
					&&label$17,
					&&label$17,
					&&label$24,
				(void *)0 };
				#define vr$242 ((uinteger)(TMP$76$ << (uinteger)2u))
				goto **(void**)((ubyte *)LABEL$25$ + vr$242 + -4);
				label$17:;
			};
		};
		goto label$14;
		label$26:;
		{
			{
				uinteger TMP$79$;
				#define vr$243 ((uinteger)(TO_DTYPE$))
				TMP$79$ = (vr$243);
				goto label$28;
				label$29:;
				{
					#define vr$244 ((double*)(V$))
					byte vr$245 = (byte)(fb_dtosb( *(double*)((ubyte *)vr$244 + 20) ));
					#define vr$246 ((integer)(vr$245))
					#define vr$247 ((integer*)(V$))
					*(integer*)((ubyte *)vr$247 + 20) = (vr$246);
				};
				goto label$27;
				label$30:;
				{
					#define vr$248 ((double*)(V$))
					ubyte vr$249 = (ubyte)(fb_dtoub( *(double*)((ubyte *)vr$248 + 20) ));
					#define vr$250 ((integer)(vr$249))
					#define vr$251 ((integer*)(V$))
					*(integer*)((ubyte *)vr$251 + 20) = (vr$250);
				};
				goto label$27;
				label$31:;
				{
					#define vr$252 ((double*)(V$))
					short vr$253 = (short)(fb_dtoss( *(double*)((ubyte *)vr$252 + 20) ));
					#define vr$254 ((integer)(vr$253))
					#define vr$255 ((integer*)(V$))
					*(integer*)((ubyte *)vr$255 + 20) = (vr$254);
				};
				goto label$27;
				label$32:;
				{
					#define vr$256 ((double*)(V$))
					ushort vr$257 = (ushort)(fb_dtous( *(double*)((ubyte *)vr$256 + 20) ));
					#define vr$258 ((integer)(vr$257))
					#define vr$259 ((integer*)(V$))
					*(integer*)((ubyte *)vr$259 + 20) = (vr$258);
				};
				goto label$27;
				label$33:;
				{
					#define vr$260 ((double*)(V$))
					integer vr$261 = (integer)(fb_dtosi( *(double*)((ubyte *)vr$260 + 20) ));
					#define vr$262 ((integer*)(V$))
					*(integer*)((ubyte *)vr$262 + 20) = (vr$261);
				};
				goto label$27;
				label$34:;
				{
					#define vr$263 ((double*)(V$))
					uinteger vr$264 = (uinteger)(fb_dtoui( *(double*)((ubyte *)vr$263 + 20) ));
					#define vr$265 ((uinteger*)(V$))
					*(uinteger*)((ubyte *)vr$265 + 20) = (vr$264);
				};
				goto label$27;
				label$28:;
				if (TMP$79$ < (uinteger)1u) goto label$27;
				if (TMP$79$ > (uinteger)23u) goto label$27;
				static const void * LABEL$35$[] = {
					&&label$29,
					&&label$30,
					&&label$27,
					&&label$31,
					&&label$32,
					&&label$27,
					&&label$33,
					&&label$34,
					&&label$33,
					&&label$27,
					&&label$33,
					&&label$34,
					&&label$27,
					&&label$27,
					&&label$27,
					&&label$27,
					&&label$27,
					&&label$27,
					&&label$27,
					&&label$27,
					&&label$27,
					&&label$27,
					&&label$34,
				(void *)0 };
				#define vr$266 ((uinteger)(TMP$79$ << (uinteger)2u))
				goto **(void**)((ubyte *)LABEL$35$ + vr$266 + -4);
				label$27:;
			};
		};
		goto label$14;
		label$36:;
		{
			{
				uinteger TMP$82$;
				#define vr$267 ((uinteger)(TO_DTYPE$))
				TMP$82$ = (vr$267);
				goto label$38;
				label$39:;
				{
					#define vr$268 ((integer*)(V$))
					#define vr$269 ((byte)(*(integer*)((ubyte *)vr$268 + 20)))
					#define vr$270 ((integer)(vr$269))
					#define vr$271 ((integer*)(V$))
					*(integer*)((ubyte *)vr$271 + 20) = (vr$270);
				};
				goto label$37;
				label$40:;
				{
					#define vr$272 ((integer*)(V$))
					#define vr$273 ((uinteger)(*(integer*)((ubyte *)vr$272 + 20)))
					#define vr$274 ((ubyte)(vr$273))
					#define vr$275 ((integer)(vr$274))
					#define vr$276 ((integer*)(V$))
					*(integer*)((ubyte *)vr$276 + 20) = (vr$275);
				};
				goto label$37;
				label$41:;
				{
					#define vr$277 ((integer*)(V$))
					#define vr$278 ((short)(*(integer*)((ubyte *)vr$277 + 20)))
					#define vr$279 ((integer)(vr$278))
					#define vr$280 ((integer*)(V$))
					*(integer*)((ubyte *)vr$280 + 20) = (vr$279);
				};
				goto label$37;
				label$42:;
				{
					#define vr$281 ((integer*)(V$))
					#define vr$282 ((uinteger)(*(integer*)((ubyte *)vr$281 + 20)))
					#define vr$283 ((ushort)(vr$282))
					#define vr$284 ((integer)(vr$283))
					#define vr$285 ((integer*)(V$))
					*(integer*)((ubyte *)vr$285 + 20) = (vr$284);
				};
				goto label$37;
				label$38:;
				if (TMP$82$ < (uinteger)1u) goto label$37;
				if (TMP$82$ > (uinteger)5u) goto label$37;
				static const void * LABEL$43$[] = {
					&&label$39,
					&&label$40,
					&&label$37,
					&&label$41,
					&&label$42,
				(void *)0 };
				#define vr$286 ((uinteger)(TMP$82$ << (uinteger)2u))
				goto **(void**)((ubyte *)LABEL$43$ + vr$286 + -4);
				label$37:;
			};
		};
		goto label$14;
		label$15:;
		if (TMP$75$ < (uinteger)13u) goto label$36;
		if (TMP$75$ > (uinteger)16u) goto label$36;
		static const void * LABEL$44$[] = {
			&&label$16,
			&&label$16,
			&&label$26,
			&&label$26,
		(void *)0 };
		#define vr$287 ((uinteger)(TMP$75$ << (uinteger)2u))
		goto **(void**)((ubyte *)LABEL$44$ + vr$287 + -52);
		label$14:;
	};
	label$11:;
}

static void HCONVCONSTEVALFLT( integer TO_DTYPE$, ASTNODE$type* V$ )
{
	integer VDTYPE$;
	FB_DATATYPE TMP$87$;
	FB_DATATYPE TMP$88$;
	label$45:;
	#define vr$288 ((integer*)(V$))
	#define vr$289 ((integer)(*(integer*)((ubyte *)vr$288 + 4) & (integer)480))
	if (vr$289 == (integer)0) goto label$47;
	TMP$87$ = ((FB_DATATYPE)23);
	goto label$357;
	label$47:;
	#define vr$290 ((integer*)(V$))
	#define vr$291 ((integer)(*(integer*)((ubyte *)vr$290 + 4) & (integer)31))
	#define vr$292 ((FB_DATATYPE)(vr$291))
	TMP$87$ = (vr$292);
	label$357:;
	#define vr$293 ((integer)(TMP$87$))
	VDTYPE$ = (vr$293);
	#define vr$294 ((integer)(TO_DTYPE$ & (integer)480))
	if (vr$294 == (integer)0) goto label$48;
	TMP$88$ = ((FB_DATATYPE)23);
	goto label$358;
	label$48:;
	#define vr$295 ((integer)(TO_DTYPE$ & (integer)31))
	#define vr$296 ((FB_DATATYPE)(vr$295))
	TMP$88$ = (vr$296);
	label$358:;
	#define vr$297 ((integer)(TMP$88$))
	TO_DTYPE$ = (vr$297);
	{
		uinteger TMP$89$;
		#define vr$298 ((uinteger)(VDTYPE$))
		TMP$89$ = (vr$298);
		goto label$50;
		label$51:;
		{
		};
		goto label$49;
		label$52:;
		{
			if (TO_DTYPE$ != (FB_DATATYPE)15) goto label$54;
			{
				single F$;
				#define vr$299 ((double*)(V$))
				#define vr$300 ((single)(*(double*)((ubyte *)vr$299 + 20)))
				F$ = (vr$300);
				#define vr$301 ((double)(F$))
				#define vr$302 ((double*)(V$))
				*(double*)((ubyte *)vr$302 + 20) = (vr$301);
			};
			label$54:;
			label$53:;
		};
		goto label$49;
		label$55:;
		{
			if (TO_DTYPE$ != (FB_DATATYPE)15) goto label$57;
			{
				#define vr$303 ((longint*)(V$))
				#define vr$304 ((single)(*(longint*)((ubyte *)vr$303 + 20)))
				#define vr$305 ((double)(vr$304))
				#define vr$306 ((double*)(V$))
				*(double*)((ubyte *)vr$306 + 20) = (vr$305);
			};
			goto label$56;
			label$57:;
			{
				#define vr$307 ((longint*)(V$))
				#define vr$308 ((double)(*(longint*)((ubyte *)vr$307 + 20)))
				#define vr$309 ((double*)(V$))
				*(double*)((ubyte *)vr$309 + 20) = (vr$308);
			};
			label$56:;
		};
		goto label$49;
		label$58:;
		{
			if (TO_DTYPE$ != (FB_DATATYPE)15) goto label$60;
			{
				#define vr$310 ((longint*)(V$))
				#define vr$311 ((ulongint)(*(longint*)((ubyte *)vr$310 + 20)))
				#define vr$312 ((single)(vr$311))
				#define vr$313 ((double)(vr$312))
				#define vr$314 ((double*)(V$))
				*(double*)((ubyte *)vr$314 + 20) = (vr$313);
			};
			goto label$59;
			label$60:;
			{
				#define vr$315 ((longint*)(V$))
				#define vr$316 ((ulongint)(*(longint*)((ubyte *)vr$315 + 20)))
				#define vr$317 ((double)(vr$316))
				#define vr$318 ((double*)(V$))
				*(double*)((ubyte *)vr$318 + 20) = (vr$317);
			};
			label$59:;
		};
		goto label$49;
		label$61:;
		{
			if (TO_DTYPE$ != (FB_DATATYPE)15) goto label$63;
			{
				#define vr$319 ((integer*)(V$))
				#define vr$320 ((uinteger)(*(integer*)((ubyte *)vr$319 + 20)))
				#define vr$321 ((single)(vr$320))
				#define vr$322 ((double)(vr$321))
				#define vr$323 ((double*)(V$))
				*(double*)((ubyte *)vr$323 + 20) = (vr$322);
			};
			goto label$62;
			label$63:;
			{
				#define vr$324 ((integer*)(V$))
				#define vr$325 ((uinteger)(*(integer*)((ubyte *)vr$324 + 20)))
				#define vr$326 ((double)(vr$325))
				#define vr$327 ((double*)(V$))
				*(double*)((ubyte *)vr$327 + 20) = (vr$326);
			};
			label$62:;
		};
		goto label$49;
		label$64:;
		{
			{
				if (TO_DTYPE$ != (FB_DATATYPE)15) goto label$68;
				{
					#define vr$328 ((integer*)(V$))
					#define vr$329 ((single)(*(integer*)((ubyte *)vr$328 + 20)))
					#define vr$330 ((double)(vr$329))
					#define vr$331 ((double*)(V$))
					*(double*)((ubyte *)vr$331 + 20) = (vr$330);
				};
				goto label$67;
				label$68:;
				{
					#define vr$332 ((integer*)(V$))
					#define vr$333 ((double)(*(integer*)((ubyte *)vr$332 + 20)))
					#define vr$334 ((double*)(V$))
					*(double*)((ubyte *)vr$334 + 20) = (vr$333);
				};
				label$67:;
			};
			goto label$65;
			label$66:;
			{
				if (TO_DTYPE$ != (FB_DATATYPE)15) goto label$70;
				{
					#define vr$335 ((longint*)(V$))
					#define vr$336 ((single)(*(longint*)((ubyte *)vr$335 + 20)))
					#define vr$337 ((double)(vr$336))
					#define vr$338 ((double*)(V$))
					*(double*)((ubyte *)vr$338 + 20) = (vr$337);
				};
				goto label$69;
				label$70:;
				{
					#define vr$339 ((longint*)(V$))
					#define vr$340 ((double)(*(longint*)((ubyte *)vr$339 + 20)))
					#define vr$341 ((double*)(V$))
					*(double*)((ubyte *)vr$341 + 20) = (vr$340);
				};
				label$69:;
			};
			label$65:;
		};
		goto label$49;
		label$71:;
		{
			{
				if (TO_DTYPE$ != (FB_DATATYPE)15) goto label$75;
				{
					#define vr$342 ((integer*)(V$))
					#define vr$343 ((uinteger)(*(integer*)((ubyte *)vr$342 + 20)))
					#define vr$344 ((single)(vr$343))
					#define vr$345 ((double)(vr$344))
					#define vr$346 ((double*)(V$))
					*(double*)((ubyte *)vr$346 + 20) = (vr$345);
				};
				goto label$74;
				label$75:;
				{
					#define vr$347 ((integer*)(V$))
					#define vr$348 ((uinteger)(*(integer*)((ubyte *)vr$347 + 20)))
					#define vr$349 ((double)(vr$348))
					#define vr$350 ((double*)(V$))
					*(double*)((ubyte *)vr$350 + 20) = (vr$349);
				};
				label$74:;
			};
			goto label$72;
			label$73:;
			{
				if (TO_DTYPE$ != (FB_DATATYPE)15) goto label$77;
				{
					#define vr$351 ((longint*)(V$))
					#define vr$352 ((ulongint)(*(longint*)((ubyte *)vr$351 + 20)))
					#define vr$353 ((single)(vr$352))
					#define vr$354 ((double)(vr$353))
					#define vr$355 ((double*)(V$))
					*(double*)((ubyte *)vr$355 + 20) = (vr$354);
				};
				goto label$76;
				label$77:;
				{
					#define vr$356 ((longint*)(V$))
					#define vr$357 ((ulongint)(*(longint*)((ubyte *)vr$356 + 20)))
					#define vr$358 ((double)(vr$357))
					#define vr$359 ((double*)(V$))
					*(double*)((ubyte *)vr$359 + 20) = (vr$358);
				};
				label$76:;
			};
			label$72:;
		};
		goto label$49;
		label$78:;
		{
			if (TO_DTYPE$ != (FB_DATATYPE)15) goto label$80;
			{
				#define vr$360 ((integer*)(V$))
				#define vr$361 ((single)(*(integer*)((ubyte *)vr$360 + 20)))
				#define vr$362 ((double)(vr$361))
				#define vr$363 ((double*)(V$))
				*(double*)((ubyte *)vr$363 + 20) = (vr$362);
			};
			goto label$79;
			label$80:;
			{
				#define vr$364 ((integer*)(V$))
				#define vr$365 ((double)(*(integer*)((ubyte *)vr$364 + 20)))
				#define vr$366 ((double*)(V$))
				*(double*)((ubyte *)vr$366 + 20) = (vr$365);
			};
			label$79:;
		};
		goto label$49;
		label$50:;
		if (TMP$89$ < (uinteger)8u) goto label$78;
		if (TMP$89$ > (uinteger)23u) goto label$78;
		static const void * LABEL$81$[] = {
			&&label$61,
			&&label$78,
			&&label$78,
			&&label$64,
			&&label$71,
			&&label$55,
			&&label$58,
			&&label$51,
			&&label$52,
			&&label$78,
			&&label$78,
			&&label$78,
			&&label$78,
			&&label$78,
			&&label$78,
			&&label$61,
		(void *)0 };
		#define vr$367 ((uinteger)(TMP$89$ << (uinteger)2u))
		goto **(void**)((ubyte *)LABEL$81$ + vr$367 + -32);
		label$49:;
	};
	label$46:;
}

static void HCONVCONSTEVAL64( integer TO_DTYPE$, ASTNODE$type* V$ )
{
	integer VDTYPE$;
	FB_DATATYPE TMP$92$;
	FB_DATATYPE TMP$93$;
	label$82:;
	#define vr$368 ((integer*)(V$))
	#define vr$369 ((integer)(*(integer*)((ubyte *)vr$368 + 4) & (integer)480))
	if (vr$369 == (integer)0) goto label$84;
	TMP$92$ = ((FB_DATATYPE)23);
	goto label$359;
	label$84:;
	#define vr$370 ((integer*)(V$))
	#define vr$371 ((integer)(*(integer*)((ubyte *)vr$370 + 4) & (integer)31))
	#define vr$372 ((FB_DATATYPE)(vr$371))
	TMP$92$ = (vr$372);
	label$359:;
	#define vr$373 ((integer)(TMP$92$))
	VDTYPE$ = (vr$373);
	#define vr$374 ((integer)(TO_DTYPE$ & (integer)480))
	if (vr$374 == (integer)0) goto label$85;
	TMP$93$ = ((FB_DATATYPE)23);
	goto label$360;
	label$85:;
	#define vr$375 ((integer)(TO_DTYPE$ & (integer)31))
	#define vr$376 ((FB_DATATYPE)(vr$375))
	TMP$93$ = (vr$376);
	label$360:;
	#define vr$377 ((integer)(TMP$93$))
	TO_DTYPE$ = (vr$377);
	{
		uinteger TMP$94$;
		#define vr$378 ((uinteger)(VDTYPE$))
		TMP$94$ = (vr$378);
		goto label$87;
		label$88:;
		{
		};
		goto label$86;
		label$89:;
		{
			if (TO_DTYPE$ != (FB_DATATYPE)13) goto label$91;
			{
				#define vr$379 ((double*)(V$))
				longint vr$380 = (longint)(fb_dtosl( *(double*)((ubyte *)vr$379 + 20) ));
				#define vr$381 ((longint*)(V$))
				*(longint*)((ubyte *)vr$381 + 20) = (vr$380);
			};
			goto label$90;
			label$91:;
			{
				longint TMP$95$;
				#define vr$382 ((double*)(V$))
				if (*(double*)((ubyte *)vr$382 + 20) < (double)1e+16) goto label$92;
				#define vr$383 ((double*)(V$))
				#define vr$384 ((double)(*(double*)((ubyte *)vr$383 + 20) * (double)0.5))
				longint vr$385 = (longint)(fb_dtosl( vr$384 ));
				#define vr$386 ((longint)(vr$385 << (integer)1))
				TMP$95$ = (vr$386);
				goto label$361;
				label$92:;
				#define vr$387 ((double*)(V$))
				longint vr$388 = (longint)(fb_dtosl( *(double*)((ubyte *)vr$387 + 20) ));
				TMP$95$ = (vr$388);
				label$361:;
				#define vr$389 ((ulongint)(TMP$95$))
				#define vr$390 ((longint)(vr$389))
				#define vr$391 ((longint*)(V$))
				*(longint*)((ubyte *)vr$391 + 20) = (vr$390);
			};
			label$90:;
		};
		goto label$86;
		label$93:;
		{
			{
				if (TO_DTYPE$ != (FB_DATATYPE)13) goto label$97;
				{
					#define vr$392 ((integer*)(V$))
					#define vr$393 ((longint)(*(integer*)((ubyte *)vr$392 + 20)))
					#define vr$394 ((longint*)(V$))
					*(longint*)((ubyte *)vr$394 + 20) = (vr$393);
				};
				goto label$96;
				label$97:;
				{
					#define vr$395 ((integer*)(V$))
					#define vr$396 ((ulongint)(*(integer*)((ubyte *)vr$395 + 20)))
					#define vr$397 ((longint)(vr$396))
					#define vr$398 ((longint*)(V$))
					*(longint*)((ubyte *)vr$398 + 20) = (vr$397);
				};
				label$96:;
			};
			label$95:;
			label$94:;
		};
		goto label$86;
		label$98:;
		{
			{
				if (TO_DTYPE$ != (FB_DATATYPE)13) goto label$102;
				{
					#define vr$399 ((integer*)(V$))
					#define vr$400 ((uinteger)(*(integer*)((ubyte *)vr$399 + 20)))
					#define vr$401 ((longint)(vr$400))
					#define vr$402 ((longint*)(V$))
					*(longint*)((ubyte *)vr$402 + 20) = (vr$401);
				};
				goto label$101;
				label$102:;
				{
					#define vr$403 ((integer*)(V$))
					#define vr$404 ((uinteger)(*(integer*)((ubyte *)vr$403 + 20)))
					#define vr$405 ((ulongint)(vr$404))
					#define vr$406 ((longint)(vr$405))
					#define vr$407 ((longint*)(V$))
					*(longint*)((ubyte *)vr$407 + 20) = (vr$406);
				};
				label$101:;
			};
			label$100:;
			label$99:;
		};
		goto label$86;
		label$103:;
		{
			if (TO_DTYPE$ != (FB_DATATYPE)13) goto label$105;
			{
				FB_DATATYPE TMP$96$;
				#define vr$408 ((integer*)(V$))
				#define vr$409 ((integer)(*(integer*)((ubyte *)vr$408 + 4) & (integer)480))
				if (vr$409 == (integer)0) goto label$106;
				TMP$96$ = ((FB_DATATYPE)23);
				goto label$362;
				label$106:;
				#define vr$410 ((integer*)(V$))
				#define vr$411 ((integer)(*(integer*)((ubyte *)vr$410 + 4) & (integer)31))
				#define vr$412 ((FB_DATATYPE)(vr$411))
				TMP$96$ = (vr$412);
				label$362:;
				#define vr$413 ((integer)(TMP$96$))
				#define vr$414 ((integer)(vr$413 * (integer)28))
				if (*(integer*)((ubyte *)&SYMB_DTYPETB$ + vr$414 + 12) == (integer)0) goto label$108;
				{
					#define vr$415 ((integer*)(V$))
					#define vr$416 ((longint)(*(integer*)((ubyte *)vr$415 + 20)))
					#define vr$417 ((longint*)(V$))
					*(longint*)((ubyte *)vr$417 + 20) = (vr$416);
				};
				goto label$107;
				label$108:;
				{
					#define vr$418 ((integer*)(V$))
					#define vr$419 ((uinteger)(*(integer*)((ubyte *)vr$418 + 20)))
					#define vr$420 ((longint)(vr$419))
					#define vr$421 ((longint*)(V$))
					*(longint*)((ubyte *)vr$421 + 20) = (vr$420);
				};
				label$107:;
			};
			goto label$104;
			label$105:;
			{
				FB_DATATYPE TMP$97$;
				#define vr$422 ((integer*)(V$))
				#define vr$423 ((integer)(*(integer*)((ubyte *)vr$422 + 4) & (integer)480))
				if (vr$423 == (integer)0) goto label$109;
				TMP$97$ = ((FB_DATATYPE)23);
				goto label$363;
				label$109:;
				#define vr$424 ((integer*)(V$))
				#define vr$425 ((integer)(*(integer*)((ubyte *)vr$424 + 4) & (integer)31))
				#define vr$426 ((FB_DATATYPE)(vr$425))
				TMP$97$ = (vr$426);
				label$363:;
				#define vr$427 ((integer)(TMP$97$))
				#define vr$428 ((integer)(vr$427 * (integer)28))
				if (*(integer*)((ubyte *)&SYMB_DTYPETB$ + vr$428 + 12) == (integer)0) goto label$111;
				{
					#define vr$429 ((integer*)(V$))
					#define vr$430 ((ulongint)(*(integer*)((ubyte *)vr$429 + 20)))
					#define vr$431 ((longint)(vr$430))
					#define vr$432 ((longint*)(V$))
					*(longint*)((ubyte *)vr$432 + 20) = (vr$431);
				};
				goto label$110;
				label$111:;
				{
					#define vr$433 ((integer*)(V$))
					#define vr$434 ((uinteger)(*(integer*)((ubyte *)vr$433 + 20)))
					#define vr$435 ((ulongint)(vr$434))
					#define vr$436 ((longint)(vr$435))
					#define vr$437 ((longint*)(V$))
					*(longint*)((ubyte *)vr$437 + 20) = (vr$436);
				};
				label$110:;
			};
			label$104:;
		};
		goto label$86;
		label$87:;
		if (TMP$94$ < (uinteger)11u) goto label$103;
		if (TMP$94$ > (uinteger)16u) goto label$103;
		static const void * LABEL$112$[] = {
			&&label$93,
			&&label$98,
			&&label$88,
			&&label$88,
			&&label$89,
			&&label$89,
		(void *)0 };
		#define vr$438 ((uinteger)(TMP$94$ << (uinteger)2u))
		goto **(void**)((ubyte *)LABEL$112$ + vr$438 + -44);
		label$86:;
	};
	label$83:;
}

static integer HGETTYPEMISMATCHERRMSG( AST_CONVOPT OPTIONS$ )
{
	integer fb$result$;
	#define vr$439 ((integer*)(&fb$result$))
	__builtin_memset( vr$439, 0, (integer)4 );
	label$113:;
	#define vr$440 ((AST_CONVOPT)(OPTIONS$ & (AST_CONVOPT)4))
	if (vr$440 == (AST_CONVOPT)0) goto label$116;
	{
		fb$result$ = ((integer)28);
	};
	goto label$115;
	label$116:;
	{
		fb$result$ = ((integer)20);
	};
	label$115:;
	label$114:;
	#define vr$441 ((integer)(fb$result$))
	return vr$441;
}

static integer HCHECKPTR( integer TO_DTYPE$, FBSYMBOL$type* TO_SUBTYPE$, integer EXPR_DTYPE$, ASTNODE$type* EXPR$, AST_CONVOPT OPTIONS$ )
{
	integer fb$result$;
	#define vr$442 ((integer*)(&fb$result$))
	__builtin_memset( vr$442, 0, (integer)4 );
	label$117:;
	fb$result$ = ((integer)0);
	#define vr$443 ((integer)(TO_DTYPE$ & (integer)480))
	if (vr$443 == (integer)0) goto label$120;
	{
		{
			FB_DATATYPE TMP$100$;
			uinteger TMP$101$;
			#define vr$444 ((integer)(EXPR_DTYPE$ & (integer)480))
			if (vr$444 == (integer)0) goto label$121;
			TMP$100$ = ((FB_DATATYPE)23);
			goto label$364;
			label$121:;
			#define vr$445 ((integer)(EXPR_DTYPE$ & (integer)31))
			#define vr$446 ((FB_DATATYPE)(vr$445))
			TMP$100$ = (vr$446);
			label$364:;
			#define vr$447 ((uinteger)(TMP$100$))
			TMP$101$ = (vr$447);
			goto label$123;
			label$124:;
			{
				goto label$118;
			};
			goto label$122;
			label$125:;
			{
				#define vr$448 ((AST_NODECLASS*)(EXPR$))
				if (*(AST_NODECLASS*)((ubyte *)vr$448) != (AST_NODECLASS)16) goto label$127;
				{
					integer vr$449 = (integer)(ASTCONSTISZERO( EXPR$ ));
					if (vr$449 == (integer)0) goto label$129;
					{
						goto label$118;
					};
					label$129:;
					label$128:;
				};
				label$127:;
				label$126:;
				integer vr$450 = (integer)(HGETTYPEMISMATCHERRMSG( OPTIONS$ ));
				fb$result$ = (vr$450);
				goto label$118;
			};
			goto label$122;
			label$130:;
			{
			};
			goto label$122;
			label$131:;
			{
				integer vr$451 = (integer)(HGETTYPEMISMATCHERRMSG( OPTIONS$ ));
				fb$result$ = (vr$451);
				goto label$118;
			};
			goto label$122;
			label$123:;
			if (TMP$101$ < (uinteger)1u) goto label$131;
			if (TMP$101$ > (uinteger)23u) goto label$131;
			static const void * LABEL$132$[] = {
				&&label$125,
				&&label$125,
				&&label$131,
				&&label$125,
				&&label$125,
				&&label$131,
				&&label$124,
				&&label$124,
				&&label$124,
				&&label$131,
				&&label$124,
				&&label$124,
				&&label$131,
				&&label$131,
				&&label$131,
				&&label$131,
				&&label$131,
				&&label$131,
				&&label$131,
				&&label$131,
				&&label$131,
				&&label$131,
				&&label$130,
			(void *)0 };
			#define vr$452 ((uinteger)(TMP$101$ << (uinteger)2u))
			goto **(void**)((ubyte *)LABEL$132$ + vr$452 + -4);
			label$122:;
		};
	};
	goto label$119;
	label$120:;
	#define vr$453 ((integer)(EXPR_DTYPE$ & (integer)480))
	if (vr$453 == (integer)0) goto label$133;
	{
		{
			FB_DATATYPE TMP$104$;
			uinteger TMP$105$;
			#define vr$454 ((integer)(TO_DTYPE$ & (integer)480))
			if (vr$454 == (integer)0) goto label$134;
			TMP$104$ = ((FB_DATATYPE)23);
			goto label$365;
			label$134:;
			#define vr$455 ((integer)(TO_DTYPE$ & (integer)31))
			#define vr$456 ((FB_DATATYPE)(vr$455))
			TMP$104$ = (vr$456);
			label$365:;
			#define vr$457 ((uinteger)(TMP$104$))
			TMP$105$ = (vr$457);
			goto label$136;
			label$137:;
			{
				goto label$118;
			};
			goto label$135;
			label$138:;
			{
			};
			goto label$135;
			label$139:;
			{
				integer vr$458 = (integer)(HGETTYPEMISMATCHERRMSG( OPTIONS$ ));
				fb$result$ = (vr$458);
				goto label$118;
			};
			goto label$135;
			label$136:;
			if (TMP$105$ < (uinteger)7u) goto label$139;
			if (TMP$105$ > (uinteger)23u) goto label$139;
			static const void * LABEL$140$[] = {
				&&label$137,
				&&label$137,
				&&label$137,
				&&label$139,
				&&label$137,
				&&label$137,
				&&label$139,
				&&label$139,
				&&label$139,
				&&label$139,
				&&label$139,
				&&label$139,
				&&label$139,
				&&label$139,
				&&label$139,
				&&label$139,
				&&label$138,
			(void *)0 };
			#define vr$459 ((uinteger)(TMP$105$ << (uinteger)2u))
			goto **(void**)((ubyte *)LABEL$140$ + vr$459 + -28);
			label$135:;
		};
	};
	goto label$119;
	label$133:;
	{
		goto label$118;
	};
	label$119:;
	#define vr$460 ((integer)(TO_DTYPE$ & (integer)31))
	if (vr$460 != (FB_DATATYPE)19) goto label$142;
	{
		#define vr$461 ((FBSYMBOL$type**)(TO_SUBTYPE$))
		if (*(FBSYMBOL$type**)((ubyte *)vr$461 + 84) == (integer)0) goto label$144;
		{
			#define vr$462 ((integer)(EXPR_DTYPE$ & (integer)31))
			if (vr$462 == (FB_DATATYPE)19) goto label$146;
			{
				#define vr$463 ((integer)(EXPR_DTYPE$ & (integer)31))
				if (vr$463 == (FB_DATATYPE)0) goto label$148;
				{
					fb$result$ = ((integer)282);
					goto label$118;
				};
				label$148:;
				label$147:;
			};
			goto label$145;
			label$146:;
			{
				#define vr$464 ((FBSYMBOL$type**)(EXPR$))
				integer vr$465 = (integer)(SYMBGETUDTBASELEVEL( *(FBSYMBOL$type**)((ubyte *)vr$464 + 8), TO_SUBTYPE$ ));
				if (vr$465 != (integer)0) goto label$150;
				{
					#define vr$466 ((FBSYMBOL$type**)(EXPR$))
					integer vr$467 = (integer)(SYMBGETUDTBASELEVEL( TO_SUBTYPE$, *(FBSYMBOL$type**)((ubyte *)vr$466 + 8) ));
					if (vr$467 != (integer)0) goto label$152;
					{
						fb$result$ = ((integer)283);
						goto label$118;
					};
					label$152:;
					label$151:;
				};
				label$150:;
				label$149:;
			};
			label$145:;
		};
		label$144:;
		label$143:;
	};
	label$142:;
	label$141:;
	#define vr$468 ((integer)(EXPR_DTYPE$ & (integer)31))
	if (vr$468 != (FB_DATATYPE)19) goto label$154;
	{
		#define vr$469 ((FBSYMBOL$type**)(EXPR$))
		#define vr$470 ((FBSYMBOL$type**)(*(FBSYMBOL$type**)((ubyte *)vr$469 + 8)))
		if (*(FBSYMBOL$type**)((ubyte *)vr$470 + 84) == (integer)0) goto label$156;
		{
			#define vr$471 ((integer)(TO_DTYPE$ & (integer)31))
			if (vr$471 == (FB_DATATYPE)19) goto label$158;
			{
				#define vr$472 ((integer)(TO_DTYPE$ & (integer)31))
				if (vr$472 == (FB_DATATYPE)0) goto label$160;
				{
					fb$result$ = ((integer)284);
					goto label$118;
				};
				label$160:;
				label$159:;
			};
			goto label$157;
			label$158:;
			{
				#define vr$473 ((FBSYMBOL$type**)(EXPR$))
				integer vr$474 = (integer)(SYMBGETUDTBASELEVEL( TO_SUBTYPE$, *(FBSYMBOL$type**)((ubyte *)vr$473 + 8) ));
				if (vr$474 != (integer)0) goto label$162;
				{
					#define vr$475 ((FBSYMBOL$type**)(EXPR$))
					integer vr$476 = (integer)(SYMBGETUDTBASELEVEL( *(FBSYMBOL$type**)((ubyte *)vr$475 + 8), TO_SUBTYPE$ ));
					if (vr$476 != (integer)0) goto label$164;
					{
						fb$result$ = ((integer)285);
						goto label$118;
					};
					label$164:;
					label$163:;
				};
				label$162:;
				label$161:;
			};
			label$157:;
		};
		label$156:;
		label$155:;
	};
	label$154:;
	label$153:;
	label$118:;
	#define vr$477 ((integer)(fb$result$))
	return vr$477;
}
// Total compilation time: 0.0492100176634267 seconds. 
