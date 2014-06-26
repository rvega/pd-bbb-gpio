// Compilation of hlp.bas started at 13:35:36 on 07-04-2013
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
		typedef int LEXCHECK;
	typedef struct ___FB_ARRAYDIMTB$ {
		integer ELEMENTS;
		integer LBOUND;
		integer UBOUND;
	} __FB_ARRAYDIMTB$;
	typedef int FB_DATATYPE;
			typedef int FB_ERRMSG;
typedef int FB_SYMBCLASS;
typedef int FB_SYMBATTRIB;
typedef int FB_SYMBSTATS;
typedef struct _FB_SYMBID {
	char* NAME;
	char* ALIAS;
	char* MANGLED;
} FB_SYMBID;
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
	typedef int FBFILE_FORMAT;
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
integer fb_FileOpen( string*, integer, integer, integer, integer, integer );
integer fb_FileClose( integer );
integer fb_FileGet( integer, uinteger, void*, integer );
integer fb_FileSeek( integer, uinteger );
integer fb_FileFree( void );
string* fb_StrAssign( void*, integer, void*, integer, integer );
void fb_StrDelete( string* );
string* fb_StrConcat( string*, void*, integer, void*, integer );
integer fb_StrCompare( void*, integer, void*, integer );
string* fb_StrAllocTempResult( string* );
string* fb_StrAllocTempDescZ( char* );
string* fb_StrAllocTempDescZEx( char*, integer );
string* fb_StrMid( string*, integer, integer );
integer fb_StrLen( void*, integer );
integer fb_StrInstr( integer, string*, string* );
string* fb_HEXEx_i( uinteger, integer );
string* fb_HEXEx_l( ulongint, integer );
string* fb_LEFT( string*, integer );
string* fb_LCASE( string* );
string* fb_UCASE( string* );
string* fb_CurDir( void );
static void fb_ctor__hlp( void )__attribute__(( constructor )) ;
void ERRREPORT( integer, integer, char* );
string* PATHSTRIPDIV( string* );
integer LEXGETTOKEN( LEXCHECK );
char* LEXGETTEXT( void );
void LEXSKIPTOKEN( LEXCHECK );
static integer STRISQUOTED( string* );
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
typedef int FB_DATACLASS;
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

integer HMATCHTEXT( char* TXT$ )
{
	integer fb$result$;
	#define vr$0 ((integer*)(&fb$result$))
	__builtin_memset( vr$0, 0, (integer)4 );
	label$10:;
	char* vr$1 = (char*)(LEXGETTEXT(  ));
	string* vr$2 = (string*)(fb_StrAllocTempDescZ( vr$1 ));
	string* vr$3 = (string*)(fb_UCASE( vr$2 ));
	integer vr$4 = (integer)(fb_StrCompare( vr$3, (integer)-1, TXT$, (integer)0 ));
	if (vr$4 != (integer)0) goto label$13;
	{
		LEXSKIPTOKEN( (LEXCHECK)0 );
		fb$result$ = ((integer)-1);
	};
	goto label$12;
	label$13:;
	{
		fb$result$ = ((integer)0);
	};
	label$12:;
	label$11:;
	#define vr$5 ((integer)(fb$result$))
	return vr$5;
}

integer HMATCH( integer TOKEN$ )
{
	integer fb$result$;
	#define vr$6 ((integer*)(&fb$result$))
	__builtin_memset( vr$6, 0, (integer)4 );
	label$14:;
	integer vr$7 = (integer)(LEXGETTOKEN( (LEXCHECK)0 ));
	if (vr$7 != TOKEN$) goto label$17;
	{
		LEXSKIPTOKEN( (LEXCHECK)0 );
		fb$result$ = ((integer)-1);
	};
	goto label$16;
	label$17:;
	{
		fb$result$ = ((integer)0);
	};
	label$16:;
	label$15:;
	#define vr$8 ((integer)(fb$result$))
	return vr$8;
}

char* HHEXUINT( uinteger VALUE$ )
{
	char* fb$result$;
	static char RES$[9];
	static char* P$;
	static integer LGT$;
	static integer MAXLEN$;
	static integer HEXTB$[16] = { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70 };
	typedef struct _TMP$74 {
		integer* DATA;
		integer* PTR;
		integer SIZE;
		integer ELEMENT_LEN;
		integer DIMENSIONS;
		__FB_ARRAYDIMTB$ DIMTB[1];
	} TMP$74;
	static TMP$74 tmp$73$ = { (void*)(integer*)&HEXTB$, (void*)(integer*)&HEXTB$, 64, 4, 1, { { 16, 0, 15 } } };
	#define vr$9 ((char**)(&fb$result$))
	__builtin_memset( vr$9, 0, (integer)4 );
	label$18:;
	MAXLEN$ = ((integer)4);
	if (VALUE$ <= (integer)65535) goto label$21;
	{
		MAXLEN$ = ((integer)8);
	};
	label$21:;
	label$20:;
	P$ = ((char*)((ubyte *)&RES$ + 7));
	LGT$ = ((integer)0);
	label$22:;
	{
		#define vr$10 ((uinteger)(VALUE$ & (integer)15))
		#define vr$11 ((uinteger)(vr$10 << (integer)2))
		#define vr$12 ((char)(*(integer*)((ubyte *)HEXTB$ + vr$11)))
		#define vr$13 ((char*)(P$))
		*(char*)((ubyte *)vr$13) = (vr$12);
		#define vr$14 ((integer)(LGT$ + (integer)1))
		LGT$ = (vr$14);
		if (LGT$ != MAXLEN$) goto label$26;
		{
			goto label$23;
		};
		label$26:;
		label$25:;
		#define vr$15 ((char*)((char*)((ubyte *)P$ + (integer)-1)))
		P$ = (vr$15);
		#define vr$16 ((uinteger)(VALUE$ >> (integer)4))
		VALUE$ = (vr$16);
	};
	label$24:;
	goto label$22;
	label$23:;
	fb$result$ = (P$);
	label$19:;
	#define vr$17 ((char*)(fb$result$))
	return vr$17;
}

string* HFLOATTOHEX( double VALUE$, integer DTYPE$ )
{
	string fb$result$;
	single SINGLEVALUE$;
	FB_DATATYPE TMP$90$;
	#define vr$18 ((string*)(&fb$result$))
	__builtin_memset( vr$18, 0, (integer)12 );
	label$27:;
	#define vr$19 ((integer)(DTYPE$ & (integer)480))
	if (vr$19 == (integer)0) goto label$29;
	TMP$90$ = ((FB_DATATYPE)23);
	goto label$32;
	label$29:;
	#define vr$20 ((integer)(DTYPE$ & (integer)31))
	#define vr$21 ((FB_DATATYPE)(vr$20))
	TMP$90$ = (vr$21);
	label$32:;
	if (TMP$90$ != (FB_DATATYPE)16) goto label$31;
	{
		string TMP$92$;
		#define vr$22 ((double*)(&VALUE$))
		#define vr$23 ((ulongint*)(vr$22))
		string* vr$24 = (string*)(fb_HEXEx_l( *(ulongint*)((ubyte *)vr$23), (integer)16 ));
		#define vr$25 ((string*)(&TMP$92$))
		__builtin_memset( vr$25, 0, (integer)12 );
		#define vr$26 ((string*)(&TMP$92$))
		string* vr$27 = (string*)(fb_StrConcat( vr$26, (char*)"0x", (integer)3, vr$24, (integer)-1 ));
		#define vr$28 ((string*)(&fb$result$))
		fb_StrAssign( vr$28, (integer)-1, vr$27, (integer)-1, (integer)0 );
	};
	goto label$30;
	label$31:;
	{
		string TMP$93$;
		#define vr$29 ((single)(VALUE$))
		SINGLEVALUE$ = (vr$29);
		#define vr$30 ((single*)(&SINGLEVALUE$))
		#define vr$31 ((uinteger*)(vr$30))
		string* vr$32 = (string*)(fb_HEXEx_i( *(uinteger*)((ubyte *)vr$31), (integer)8 ));
		#define vr$33 ((string*)(&TMP$93$))
		__builtin_memset( vr$33, 0, (integer)12 );
		#define vr$34 ((string*)(&TMP$93$))
		string* vr$35 = (string*)(fb_StrConcat( vr$34, (char*)"0x", (integer)3, vr$32, (integer)-1 ));
		#define vr$36 ((string*)(&fb$result$))
		fb_StrAssign( vr$36, (integer)-1, vr$35, (integer)-1, (integer)0 );
	};
	label$30:;
	label$28:;
	#define vr$37 ((string*)(&fb$result$))
	string* vr$38 = (string*)(fb_StrAllocTempResult( vr$37 ));
	#define vr$39 ((string*)(vr$38))
	return vr$39;
}

integer HFBRELOP2IRRELOP( integer TK$ )
{
	integer fb$result$;
	static integer OP$;
	#define vr$40 ((integer*)(&fb$result$))
	__builtin_memset( vr$40, 0, (integer)4 );
	label$33:;
	{
		static uinteger TMP$94$;
		#define vr$41 ((uinteger)(TK$))
		TMP$94$ = (vr$41);
		goto label$36;
		label$37:;
		{
			OP$ = ((integer)44);
		};
		goto label$35;
		label$38:;
		{
			OP$ = ((integer)45);
		};
		goto label$35;
		label$39:;
		{
			OP$ = ((integer)46);
		};
		goto label$35;
		label$40:;
		{
			OP$ = ((integer)47);
		};
		goto label$35;
		label$41:;
		{
			OP$ = ((integer)49);
		};
		goto label$35;
		label$42:;
		{
			OP$ = ((integer)48);
		};
		goto label$35;
		label$43:;
		{
			ERRREPORT( (FB_ERRMSG)267, (integer)0, (integer)0 );
			OP$ = ((integer)44);
		};
		goto label$35;
		label$36:;
		if (TMP$94$ < (uinteger)299u) goto label$43;
		if (TMP$94$ > (uinteger)304u) goto label$43;
		static const void * LABEL$44$[] = {
			&&label$37,
			&&label$38,
			&&label$39,
			&&label$40,
			&&label$41,
			&&label$42,
		(void *)0 };
		#define vr$42 ((uinteger)(TMP$94$ << (uinteger)2u))
		goto **(void**)((ubyte *)LABEL$44$ + vr$42 + -1196);
		label$35:;
	};
	fb$result$ = (OP$);
	label$34:;
	#define vr$43 ((integer)(fb$result$))
	return vr$43;
}

integer HFILEEXISTS( char* FILENAME$ )
{
	integer fb$result$;
	static integer F$;
	#define vr$44 ((integer*)(&fb$result$))
	__builtin_memset( vr$44, 0, (integer)4 );
	label$45:;
	integer vr$45 = (integer)(fb_FileFree(  ));
	F$ = (vr$45);
	string* vr$46 = (string*)(fb_StrAllocTempDescZ( FILENAME$ ));
	integer vr$47 = (integer)(fb_FileOpen( vr$46, (integer)2, (integer)0, (integer)0, F$, (integer)0 ));
	if (vr$47 != (integer)0) goto label$48;
	{
		fb$result$ = ((integer)-1);
		fb_FileClose( F$ );
	};
	goto label$47;
	label$48:;
	{
		fb$result$ = ((integer)0);
	};
	label$47:;
	label$46:;
	#define vr$48 ((integer)(fb$result$))
	return vr$48;
}

void HUCASE( char* SRC$, char* DST$ )
{
	static integer C$;
	static char* S$;
	static char* D$;
	label$49:;
	S$ = (SRC$);
	D$ = (DST$);
	label$51:;
	{
		#define vr$49 ((char*)(S$))
		#define vr$50 ((integer)(*(char*)((ubyte *)vr$49)))
		C$ = (vr$50);
		if (C$ < (integer)97) goto label$55;
		{
			if (C$ > (integer)122) goto label$57;
			{
				#define vr$51 ((integer)(C$ + (integer)-32))
				C$ = (vr$51);
			};
			label$57:;
			label$56:;
		};
		goto label$54;
		label$55:;
		if (C$ != (integer)0) goto label$58;
		{
			goto label$52;
		};
		label$58:;
		label$54:;
		#define vr$52 ((char)(C$))
		#define vr$53 ((char*)(D$))
		*(char*)((ubyte *)vr$53) = (vr$52);
		#define vr$54 ((char*)((char*)((ubyte *)S$ + (integer)1)))
		S$ = (vr$54);
		#define vr$55 ((char*)((char*)((ubyte *)D$ + (integer)1)))
		D$ = (vr$55);
	};
	label$53:;
	goto label$51;
	label$52:;
	#define vr$56 ((char*)(D$))
	*(char*)((ubyte *)vr$56) = ((char)0);
	label$50:;
}

void HCLEARNAME( char* SRC$ )
{
	static char* P$;
	label$59:;
	P$ = (SRC$);
	label$61:;
	{
		{
			static uinteger TMP$97$;
			#define vr$57 ((char*)(P$))
			#define vr$58 ((uinteger)(*(char*)((ubyte *)vr$57)))
			TMP$97$ = (vr$58);
			goto label$65;
			label$66:;
			{
				goto label$62;
			};
			goto label$64;
			label$67:;
			{
			};
			goto label$64;
			label$68:;
			{
				#define vr$59 ((char*)(P$))
				*(char*)((ubyte *)vr$59) = ((char)122);
			};
			goto label$64;
			label$65:;
			if (TMP$97$ > (uinteger)122u) goto label$68;
			static const void * LABEL$69$[] = {
				&&label$66,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$68,
				&&label$67,
				&&label$68,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
				&&label$67,
			(void *)0 };
			#define vr$60 ((uinteger)(TMP$97$ << (uinteger)2u))
			goto **(void**)((ubyte *)LABEL$69$ + vr$60);
			label$64:;
		};
		#define vr$61 ((char*)((char*)((ubyte *)P$ + (integer)1)))
		P$ = (vr$61);
	};
	label$63:;
	goto label$61;
	label$62:;
	label$60:;
}

string* HSTRIPEXT( char* FILENAME$ )
{
	string fb$result$;
	static integer P$;
	static integer LP$;
	#define vr$62 ((string*)(&fb$result$))
	__builtin_memset( vr$62, 0, (integer)12 );
	label$70:;
	LP$ = ((integer)0);
	label$72:;
	{
		string* vr$63 = (string*)(fb_StrAllocTempDescZEx( (char*)".", (integer)1 ));
		string* vr$64 = (string*)(fb_StrAllocTempDescZ( FILENAME$ ));
		#define vr$65 ((integer)(LP$ + (integer)1))
		integer vr$66 = (integer)(fb_StrInstr( vr$65, vr$64, vr$63 ));
		P$ = (vr$66);
		if (P$ != (integer)0) goto label$76;
		{
			goto label$73;
		};
		label$76:;
		label$75:;
		LP$ = (P$);
	};
	label$74:;
	goto label$72;
	label$73:;
	if (LP$ <= (integer)0) goto label$78;
	{
		#define vr$67 ((integer)(LP$ + (integer)-1))
		string* vr$68 = (string*)(fb_StrAllocTempDescZ( FILENAME$ ));
		string* vr$69 = (string*)(fb_LEFT( vr$68, vr$67 ));
		#define vr$70 ((string*)(&fb$result$))
		fb_StrAssign( vr$70, (integer)-1, vr$69, (integer)-1, (integer)0 );
	};
	goto label$77;
	label$78:;
	{
		#define vr$71 ((string*)(&fb$result$))
		fb_StrAssign( vr$71, (integer)-1, FILENAME$, (integer)0, (integer)0 );
	};
	label$77:;
	label$71:;
	#define vr$72 ((string*)(&fb$result$))
	string* vr$73 = (string*)(fb_StrAllocTempResult( vr$72 ));
	#define vr$74 ((string*)(vr$73))
	return vr$74;
}

string* HSTRIPPATH( char* FILENAME$ )
{
	string fb$result$;
	static integer LP$;
	static integer P_FOUND$;
	static integer P$[2];
	typedef struct _TMP$101 {
		integer* DATA;
		integer* PTR;
		integer SIZE;
		integer ELEMENT_LEN;
		integer DIMENSIONS;
		__FB_ARRAYDIMTB$ DIMTB[1];
	} TMP$101;
	static TMP$101 tmp$100$ = { (void*)(integer*)((ubyte *)&P$ + -4), (void*)(integer*)&P$, 8, 4, 1, { { 2, 1, 2 } } };
	#define vr$75 ((string*)(&fb$result$))
	__builtin_memset( vr$75, 0, (integer)12 );
	label$79:;
	LP$ = ((integer)0);
	label$81:;
	{
		string* vr$76 = (string*)(fb_StrAllocTempDescZEx( (char*)"\\", (integer)1 ));
		string* vr$77 = (string*)(fb_StrAllocTempDescZ( FILENAME$ ));
		#define vr$78 ((integer)(LP$ + (integer)1))
		integer vr$79 = (integer)(fb_StrInstr( vr$78, vr$77, vr$76 ));
		*(integer*)((ubyte *)P$) = (vr$79);
		string* vr$80 = (string*)(fb_StrAllocTempDescZEx( (char*)"/", (integer)1 ));
		string* vr$81 = (string*)(fb_StrAllocTempDescZ( FILENAME$ ));
		#define vr$82 ((integer)(LP$ + (integer)1))
		integer vr$83 = (integer)(fb_StrInstr( vr$82, vr$81, vr$80 ));
		*(integer*)((ubyte *)P$ + 4) = (vr$83);
		#define vr$84 ((integer)((-(*(integer*)((ubyte *)P$) == (integer)0))))
		#define vr$85 ((integer)((-(*(integer*)((ubyte *)P$ + 4) > (integer)0))))
		#define vr$86 ((integer)((-(*(integer*)((ubyte *)P$ + 4) < *(integer*)((ubyte *)P$)))))
		#define vr$87 ((integer)(vr$85 & vr$86))
		#define vr$88 ((integer)(vr$84 | vr$87))
		if (vr$88 == (integer)0) goto label$85;
		{
			P_FOUND$ = (*(integer*)((ubyte *)P$ + 4));
		};
		goto label$84;
		label$85:;
		{
			P_FOUND$ = (*(integer*)((ubyte *)P$));
		};
		label$84:;
		if (P_FOUND$ != (integer)0) goto label$87;
		{
			goto label$82;
		};
		label$87:;
		label$86:;
		LP$ = (P_FOUND$);
	};
	label$83:;
	goto label$81;
	label$82:;
	if (LP$ <= (integer)0) goto label$89;
	{
		#define vr$89 ((integer)(LP$ + (integer)1))
		string* vr$90 = (string*)(fb_StrAllocTempDescZ( FILENAME$ ));
		string* vr$91 = (string*)(fb_StrMid( vr$90, vr$89, (integer)-1 ));
		#define vr$92 ((string*)(&fb$result$))
		fb_StrAssign( vr$92, (integer)-1, vr$91, (integer)-1, (integer)0 );
	};
	goto label$88;
	label$89:;
	{
		#define vr$93 ((string*)(&fb$result$))
		fb_StrAssign( vr$93, (integer)-1, FILENAME$, (integer)0, (integer)0 );
	};
	label$88:;
	label$80:;
	#define vr$94 ((string*)(&fb$result$))
	string* vr$95 = (string*)(fb_StrAllocTempResult( vr$94 ));
	#define vr$96 ((string*)(vr$95))
	return vr$96;
}

string* HSTRIPFILENAME( char* FILENAME$ )
{
	string fb$result$;
	static integer LP$;
	static integer P_FOUND$;
	static integer P$[2];
	typedef struct _TMP$104 {
		integer* DATA;
		integer* PTR;
		integer SIZE;
		integer ELEMENT_LEN;
		integer DIMENSIONS;
		__FB_ARRAYDIMTB$ DIMTB[1];
	} TMP$104;
	static TMP$104 tmp$103$ = { (void*)(integer*)((ubyte *)&P$ + -4), (void*)(integer*)&P$, 8, 4, 1, { { 2, 1, 2 } } };
	#define vr$97 ((string*)(&fb$result$))
	__builtin_memset( vr$97, 0, (integer)12 );
	label$90:;
	LP$ = ((integer)0);
	label$92:;
	{
		string* vr$98 = (string*)(fb_StrAllocTempDescZEx( (char*)"\\", (integer)1 ));
		string* vr$99 = (string*)(fb_StrAllocTempDescZ( FILENAME$ ));
		#define vr$100 ((integer)(LP$ + (integer)1))
		integer vr$101 = (integer)(fb_StrInstr( vr$100, vr$99, vr$98 ));
		*(integer*)((ubyte *)P$) = (vr$101);
		string* vr$102 = (string*)(fb_StrAllocTempDescZEx( (char*)"/", (integer)1 ));
		string* vr$103 = (string*)(fb_StrAllocTempDescZ( FILENAME$ ));
		#define vr$104 ((integer)(LP$ + (integer)1))
		integer vr$105 = (integer)(fb_StrInstr( vr$104, vr$103, vr$102 ));
		*(integer*)((ubyte *)P$ + 4) = (vr$105);
		#define vr$106 ((integer)((-(*(integer*)((ubyte *)P$) == (integer)0))))
		#define vr$107 ((integer)((-(*(integer*)((ubyte *)P$ + 4) > (integer)0))))
		#define vr$108 ((integer)((-(*(integer*)((ubyte *)P$ + 4) < *(integer*)((ubyte *)P$)))))
		#define vr$109 ((integer)(vr$107 & vr$108))
		#define vr$110 ((integer)(vr$106 | vr$109))
		if (vr$110 == (integer)0) goto label$96;
		{
			P_FOUND$ = (*(integer*)((ubyte *)P$ + 4));
		};
		goto label$95;
		label$96:;
		{
			P_FOUND$ = (*(integer*)((ubyte *)P$));
		};
		label$95:;
		if (P_FOUND$ != (integer)0) goto label$98;
		{
			goto label$93;
		};
		label$98:;
		label$97:;
		LP$ = (P_FOUND$);
	};
	label$94:;
	goto label$92;
	label$93:;
	if (LP$ <= (integer)0) goto label$100;
	{
		string* vr$111 = (string*)(fb_StrAllocTempDescZ( FILENAME$ ));
		string* vr$112 = (string*)(fb_LEFT( vr$111, LP$ ));
		#define vr$113 ((string*)(&fb$result$))
		fb_StrAssign( vr$113, (integer)-1, vr$112, (integer)-1, (integer)0 );
	};
	goto label$99;
	label$100:;
	{
		#define vr$114 ((string*)(&fb$result$))
		fb_StrAssign( vr$114, (integer)-1, (char*)"", (integer)1, (integer)0 );
	};
	label$99:;
	label$91:;
	#define vr$115 ((string*)(&fb$result$))
	string* vr$116 = (string*)(fb_StrAllocTempResult( vr$115 ));
	#define vr$117 ((string*)(vr$116))
	return vr$117;
}

string* HGETFILEEXT( char* FNAME$ )
{
	string fb$result$;
	static integer P$;
	static integer LP$;
	static string RES$;
	#define vr$118 ((string*)(&fb$result$))
	__builtin_memset( vr$118, 0, (integer)12 );
	label$101:;
	LP$ = ((integer)0);
	label$103:;
	{
		string* vr$119 = (string*)(fb_StrAllocTempDescZEx( (char*)".", (integer)1 ));
		string* vr$120 = (string*)(fb_StrAllocTempDescZ( FNAME$ ));
		#define vr$121 ((integer)(LP$ + (integer)1))
		integer vr$122 = (integer)(fb_StrInstr( vr$121, vr$120, vr$119 ));
		P$ = (vr$122);
		if (P$ != (integer)0) goto label$107;
		{
			goto label$104;
		};
		label$107:;
		label$106:;
		LP$ = (P$);
	};
	label$105:;
	goto label$103;
	label$104:;
	if (LP$ != (integer)0) goto label$109;
	{
		#define vr$123 ((string*)(&fb$result$))
		fb_StrAssign( vr$123, (integer)-1, (char*)"", (integer)1, (integer)0 );
	};
	goto label$108;
	label$109:;
	{
		#define vr$124 ((integer)(LP$ + (integer)1))
		string* vr$125 = (string*)(fb_StrAllocTempDescZ( FNAME$ ));
		string* vr$126 = (string*)(fb_StrMid( vr$125, vr$124, (integer)-1 ));
		string* vr$127 = (string*)(fb_LCASE( vr$126 ));
		fb_StrAssign( (string*)&RES$, (integer)-1, vr$127, (integer)-1, (integer)0 );
		string* vr$128 = (string*)(fb_StrAllocTempDescZEx( (char*)"\\", (integer)1 ));
		integer vr$129 = (integer)(fb_StrInstr( (integer)1, (string*)&RES$, vr$128 ));
		#define vr$130 ((integer)((-(vr$129 > (integer)0))))
		string* vr$131 = (string*)(fb_StrAllocTempDescZEx( (char*)"/", (integer)1 ));
		integer vr$132 = (integer)(fb_StrInstr( (integer)1, (string*)&RES$, vr$131 ));
		#define vr$133 ((integer)((-(vr$132 > (integer)0))))
		#define vr$134 ((integer)(vr$130 | vr$133))
		if (vr$134 == (integer)0) goto label$111;
		{
			#define vr$135 ((string*)(&fb$result$))
			fb_StrAssign( vr$135, (integer)-1, (char*)"", (integer)1, (integer)0 );
		};
		goto label$110;
		label$111:;
		integer vr$136 = (integer)(fb_StrLen( (string*)&RES$, (integer)-1 ));
		if (vr$136 <= (integer)0) goto label$112;
		{
			#define vr$137 ((char**)((string*)&RES$))
			#define vr$138 ((ubyte*)(*(char**)((ubyte *)vr$137)))
			#define vr$139 ((uinteger)(*(ubyte*)((ubyte *)vr$138)))
			#define vr$140 ((integer)((-(vr$139 == (uinteger)92u))))
			#define vr$141 ((char**)((string*)&RES$))
			#define vr$142 ((ubyte*)(*(char**)((ubyte *)vr$141)))
			#define vr$143 ((uinteger)(*(ubyte*)((ubyte *)vr$142)))
			#define vr$144 ((integer)((-(vr$143 == (uinteger)47u))))
			#define vr$145 ((integer)(vr$140 | vr$144))
			if (vr$145 == (integer)0) goto label$114;
			{
				#define vr$146 ((string*)(&fb$result$))
				fb_StrAssign( vr$146, (integer)-1, (char*)"", (integer)1, (integer)0 );
			};
			goto label$113;
			label$114:;
			{
				#define vr$147 ((string*)(&fb$result$))
				fb_StrAssign( vr$147, (integer)-1, (string*)&RES$, (integer)-1, (integer)0 );
			};
			label$113:;
		};
		label$112:;
		label$110:;
	};
	label$108:;
	label$102:;
	#define vr$148 ((string*)(&fb$result$))
	string* vr$149 = (string*)(fb_StrAllocTempResult( vr$148 ));
	#define vr$150 ((string*)(vr$149))
	return vr$150;
}

void HREPLACESLASH( char* S$, integer CHAR$ )
{
	label$115:;
	{
		integer I$;
		integer TMP$105$;
		I$ = ((integer)0);
		integer vr$151 = (integer)(fb_StrLen( S$, (integer)0 ));
		#define vr$152 ((integer)(vr$151 + (integer)-1))
		TMP$105$ = (vr$152);
		goto label$117;
		label$120:;
		{
			#define vr$153 ((char*)((char*)((ubyte *)S$ + I$)))
			#define vr$154 ((uinteger)(*(char*)((ubyte *)vr$153)))
			#define vr$155 ((integer)((-(vr$154 == (integer)92))))
			#define vr$156 ((char*)((char*)((ubyte *)S$ + I$)))
			#define vr$157 ((uinteger)(*(char*)((ubyte *)vr$156)))
			#define vr$158 ((integer)((-(vr$157 == (integer)47))))
			#define vr$159 ((integer)(vr$155 | vr$158))
			if (vr$159 == (integer)0) goto label$122;
			{
				#define vr$160 ((char)(CHAR$))
				#define vr$161 ((char*)((char*)((ubyte *)S$ + I$)))
				*(char*)((ubyte *)vr$161) = (vr$160);
			};
			label$122:;
			label$121:;
		};
		label$118:;
		#define vr$162 ((integer)(I$ + (integer)1))
		I$ = (vr$162);
		label$117:;
		if (I$ <= TMP$105$) goto label$120;
		label$119:;
	};
	label$116:;
}

string* PATHSTRIPDIV( string* PATH$ )
{
	string fb$result$;
	integer LENGTH$;
	#define vr$163 ((string*)(&fb$result$))
	__builtin_memset( vr$163, 0, (integer)12 );
	label$123:;
	integer vr$164 = (integer)(fb_StrLen( (string*)(PATH$), (integer)-1 ));
	LENGTH$ = (vr$164);
	if (LENGTH$ <= (integer)0) goto label$126;
	{
		#define vr$165 ((integer)(LENGTH$ + (integer)-1))
		LENGTH$ = (vr$165);
		{
			ubyte TMP$106$;
			#define vr$166 ((char**)((string*)(PATH$)))
			#define vr$167 ((char*)((char*)((ubyte *)*(char**)((ubyte *)vr$166) + LENGTH$)))
			TMP$106$ = (*(ubyte*)((ubyte *)vr$167));
			#define vr$168 ((uinteger)(TMP$106$))
			if (vr$168 != (uinteger)47u) goto label$128;
			label$129:;
			{
				string* vr$169 = (string*)(fb_LEFT( (string*)(PATH$), LENGTH$ ));
				#define vr$170 ((string*)(&fb$result$))
				fb_StrAssign( vr$170, (integer)-1, vr$169, (integer)-1, (integer)0 );
				goto label$124;
			};
			label$128:;
			label$127:;
		};
	};
	label$126:;
	label$125:;
	#define vr$171 ((string*)(&fb$result$))
	fb_StrAssign( vr$171, (integer)-1, (string*)(PATH$), (integer)-1, (integer)0 );
	label$124:;
	#define vr$172 ((string*)(&fb$result$))
	string* vr$173 = (string*)(fb_StrAllocTempResult( vr$172 ));
	#define vr$174 ((string*)(vr$173))
	return vr$174;
}

integer PATHISABSOLUTE( char* PATH$ )
{
	integer fb$result$;
	#define vr$175 ((integer*)(&fb$result$))
	__builtin_memset( vr$175, 0, (integer)4 );
	label$130:;
	#define vr$176 ((ubyte*)(PATH$))
	#define vr$177 ((uinteger)(*(ubyte*)((ubyte *)vr$176)))
	#define vr$178 ((integer)((-(vr$177 == (uinteger)47u))))
	fb$result$ = (vr$178);
	label$131:;
	#define vr$179 ((integer)(fb$result$))
	return vr$179;
}

uinteger HTOPOW2( uinteger VALUE$ )
{
	uinteger fb$result$;
	static uinteger N$;
	static uinteger POW2TB$[64] = { 0u, 0u, 0u, 15u, 0u, 1u, 28u, 0u, 16u, 0u, 0u, 0u, 2u, 21u, 29u, 0u, 0u, 0u, 19u, 17u, 10u, 0u, 12u, 0u, 0u, 3u, 0u, 6u, 0u, 22u, 30u, 0u, 14u, 0u, 27u, 0u, 0u, 0u, 20u, 0u, 18u, 9u, 11u, 0u, 5u, 0u, 0u, 13u, 26u, 0u, 0u, 8u, 0u, 4u, 0u, 25u, 0u, 7u, 24u, 0u, 23u, 0u, 31u, 0u };
	typedef struct _TMP$108 {
		uinteger* DATA;
		uinteger* PTR;
		integer SIZE;
		integer ELEMENT_LEN;
		integer DIMENSIONS;
		__FB_ARRAYDIMTB$ DIMTB[1];
	} TMP$108;
	static TMP$108 tmp$107$ = { (void*)(uinteger*)&POW2TB$, (void*)(uinteger*)&POW2TB$, 256, 4, 1, { { 64, 0, 63 } } };
	#define vr$180 ((uinteger*)(&fb$result$))
	__builtin_memset( vr$180, 0, (integer)4 );
	label$132:;
	if (VALUE$ != (integer)0) goto label$135;
	{
		fb$result$ = ((uinteger)0u);
		goto label$133;
	};
	label$135:;
	label$134:;
	#define vr$181 ((uinteger)(VALUE$ + (integer)-1))
	#define vr$182 ((uinteger)(vr$181 ^ VALUE$))
	#define vr$183 ((uinteger)(vr$182 * (integer)116069625))
	N$ = (vr$183);
	#define vr$184 ((uinteger)(N$ >> (integer)26))
	#define vr$185 ((uinteger)(vr$184 << (integer)2))
	N$ = (*(uinteger*)((ubyte *)POW2TB$ + vr$185));
	#define vr$186 ((integer)((integer)1 << N$))
	#define vr$187 ((uinteger)(VALUE$ - vr$186))
	if (vr$187 != (integer)0) goto label$137;
	{
		fb$result$ = (N$);
	};
	goto label$136;
	label$137:;
	{
		fb$result$ = ((uinteger)0u);
	};
	label$136:;
	label$133:;
	#define vr$188 ((uinteger)(fb$result$))
	return vr$188;
}

void HCONVERTVALUE( FBVALUE* SRC$, integer SDTYPE$, FBVALUE* DST$, integer DDTYPE$ )
{
	label$138:;
	{
		static uinteger TMP$109$;
		#define vr$189 ((uinteger)(SDTYPE$))
		TMP$109$ = (vr$189);
		goto label$141;
		label$142:;
		{
			label$143:;
		};
		goto label$140;
		label$144:;
		{
			{
				static uinteger TMP$110$;
				#define vr$190 ((uinteger)(DDTYPE$))
				TMP$110$ = (vr$190);
				goto label$146;
				label$147:;
				{
					#define vr$191 ((double*)(SRC$))
					longint vr$192 = (longint)(fb_dtosl( *(double*)((ubyte *)vr$191) ));
					#define vr$193 ((longint*)(DST$))
					*(longint*)((ubyte *)vr$193) = (vr$192);
				};
				goto label$145;
				label$148:;
				{
					#define vr$194 ((double*)(SRC$))
					#define vr$195 ((double*)(DST$))
					*(double*)((ubyte *)vr$195) = (*(double*)((ubyte *)vr$194));
				};
				goto label$145;
				label$149:;
				{
					{
						#define vr$196 ((double*)(SRC$))
						integer vr$197 = (integer)(fb_dtosi( *(double*)((ubyte *)vr$196) ));
						#define vr$198 ((integer*)(DST$))
						*(integer*)((ubyte *)vr$198) = (vr$197);
					};
					goto label$150;
					label$151:;
					{
						#define vr$199 ((double*)(SRC$))
						longint vr$200 = (longint)(fb_dtosl( *(double*)((ubyte *)vr$199) ));
						#define vr$201 ((longint*)(DST$))
						*(longint*)((ubyte *)vr$201) = (vr$200);
					};
					label$150:;
				};
				goto label$145;
				label$152:;
				{
					#define vr$202 ((double*)(SRC$))
					integer vr$203 = (integer)(fb_dtosi( *(double*)((ubyte *)vr$202) ));
					#define vr$204 ((integer*)(DST$))
					*(integer*)((ubyte *)vr$204) = (vr$203);
				};
				goto label$145;
				label$146:;
				if (TMP$110$ < (uinteger)11u) goto label$152;
				if (TMP$110$ > (uinteger)16u) goto label$152;
				static const void * LABEL$153$[] = {
					&&label$149,
					&&label$149,
					&&label$147,
					&&label$147,
					&&label$148,
					&&label$148,
				(void *)0 };
				#define vr$205 ((uinteger)(TMP$110$ << (uinteger)2u))
				goto **(void**)((ubyte *)LABEL$153$ + vr$205 + -44);
				label$145:;
			};
		};
		goto label$140;
		label$154:;
		{
			{
				goto label$157;
			};
			goto label$155;
			label$156:;
			{
				goto label$143;
			};
			label$155:;
		};
		goto label$140;
		label$158:;
		{
			label$157:;
			{
				static uinteger TMP$113$;
				#define vr$206 ((uinteger)(DDTYPE$))
				TMP$113$ = (vr$206);
				goto label$160;
				label$161:;
				{
					#define vr$207 ((integer*)(SRC$))
					#define vr$208 ((longint)(*(integer*)((ubyte *)vr$207)))
					#define vr$209 ((longint*)(DST$))
					*(longint*)((ubyte *)vr$209) = (vr$208);
				};
				goto label$159;
				label$162:;
				{
					#define vr$210 ((integer*)(SRC$))
					#define vr$211 ((double)(*(integer*)((ubyte *)vr$210)))
					#define vr$212 ((double*)(DST$))
					*(double*)((ubyte *)vr$212) = (vr$211);
				};
				goto label$159;
				label$163:;
				{
					{
						#define vr$213 ((integer*)(SRC$))
						#define vr$214 ((integer*)(DST$))
						*(integer*)((ubyte *)vr$214) = (*(integer*)((ubyte *)vr$213));
					};
					goto label$164;
					label$165:;
					{
						#define vr$215 ((integer*)(SRC$))
						#define vr$216 ((longint)(*(integer*)((ubyte *)vr$215)))
						#define vr$217 ((longint*)(DST$))
						*(longint*)((ubyte *)vr$217) = (vr$216);
					};
					label$164:;
				};
				goto label$159;
				label$166:;
				{
					#define vr$218 ((integer*)(SRC$))
					#define vr$219 ((integer*)(DST$))
					*(integer*)((ubyte *)vr$219) = (*(integer*)((ubyte *)vr$218));
				};
				goto label$159;
				label$160:;
				if (TMP$113$ < (uinteger)11u) goto label$166;
				if (TMP$113$ > (uinteger)16u) goto label$166;
				static const void * LABEL$167$[] = {
					&&label$163,
					&&label$163,
					&&label$161,
					&&label$161,
					&&label$162,
					&&label$162,
				(void *)0 };
				#define vr$220 ((uinteger)(TMP$113$ << (uinteger)2u))
				goto **(void**)((ubyte *)LABEL$167$ + vr$220 + -44);
				label$159:;
			};
		};
		goto label$140;
		label$141:;
		if (TMP$109$ < (uinteger)11u) goto label$158;
		if (TMP$109$ > (uinteger)16u) goto label$158;
		static const void * LABEL$168$[] = {
			&&label$154,
			&&label$154,
			&&label$142,
			&&label$142,
			&&label$144,
			&&label$144,
		(void *)0 };
		#define vr$221 ((uinteger)(TMP$109$ << (uinteger)2u))
		goto **(void**)((ubyte *)LABEL$168$ + vr$221 + -44);
		label$140:;
	};
	label$139:;
}

integer HCHECKFILEFORMAT( integer F$ )
{
	integer fb$result$;
	integer BOM$;
	FBFILE_FORMAT FMT$;
	#define vr$222 ((integer*)(&fb$result$))
	__builtin_memset( vr$222, 0, (integer)4 );
	label$169:;
	#define vr$223 ((integer*)(&BOM$))
	__builtin_memset( vr$223, 0, (integer)4 );
	#define vr$224 ((FBFILE_FORMAT*)(&FMT$))
	__builtin_memset( vr$224, 0, (integer)4 );
	FMT$ = ((FBFILE_FORMAT)0);
	#define vr$225 ((integer*)(&BOM$))
	integer vr$226 = (integer)(fb_FileGet( F$, (integer)0, vr$225, (integer)4 ));
	if (vr$226 != (integer)0) goto label$172;
	{
		if (BOM$ != (integer)-131072) goto label$174;
		{
			FMT$ = ((FBFILE_FORMAT)5);
		};
		goto label$173;
		label$174:;
		if (BOM$ != (integer)65279) goto label$175;
		{
			FMT$ = ((FBFILE_FORMAT)4);
		};
		goto label$173;
		label$175:;
		{
			#define vr$227 ((integer)(BOM$ & (integer)16777215))
			BOM$ = (vr$227);
			if (BOM$ != (integer)12565487) goto label$177;
			{
				FMT$ = ((FBFILE_FORMAT)1);
			};
			goto label$176;
			label$177:;
			{
				#define vr$228 ((integer)(BOM$ & (integer)65535))
				BOM$ = (vr$228);
				if (BOM$ != (integer)65279) goto label$179;
				{
					FMT$ = ((FBFILE_FORMAT)2);
				};
				goto label$178;
				label$179:;
				if (BOM$ != (integer)65534) goto label$180;
				{
					FMT$ = ((FBFILE_FORMAT)3);
				};
				label$180:;
				label$178:;
			};
			label$176:;
		};
		label$173:;
		{
			FBFILE_FORMAT TMP$118$;
			TMP$118$ = (FMT$);
			if (*(integer*)(&TMP$118$) != (FBFILE_FORMAT)0) goto label$182;
			label$183:;
			{
				fb_FileSeek( F$, (integer)1 );
			};
			goto label$181;
			label$182:;
			if (*(integer*)(&TMP$118$) != (FBFILE_FORMAT)1) goto label$184;
			label$185:;
			{
				fb_FileSeek( F$, (integer)4 );
			};
			goto label$181;
			label$184:;
			if (*(integer*)(&TMP$118$) == (FBFILE_FORMAT)2) goto label$187;
			label$188:;
			if (*(integer*)(&TMP$118$) != (FBFILE_FORMAT)3) goto label$186;
			label$187:;
			{
				fb_FileSeek( F$, (integer)3 );
			};
			label$186:;
			label$181:;
		};
	};
	label$172:;
	label$171:;
	#define vr$229 ((integer)(FMT$))
	fb$result$ = (vr$229);
	label$170:;
	#define vr$230 ((integer)(fb$result$))
	return vr$230;
}

string* HCURDIR( void )
{
	string fb$result$;
	string TMP$119$;
	#define vr$231 ((string*)(&fb$result$))
	__builtin_memset( vr$231, 0, (integer)12 );
	label$189:;
	#define vr$232 ((string*)(&TMP$119$))
	__builtin_memset( vr$232, 0, (integer)12 );
	string* vr$233 = (string*)(fb_CurDir(  ));
	#define vr$234 ((string*)(&TMP$119$))
	fb_StrAssign( vr$234, (integer)-1, vr$233, (integer)-1, (integer)0 );
	#define vr$235 ((string*)(&TMP$119$))
	string* vr$236 = (string*)(PATHSTRIPDIV( vr$235 ));
	#define vr$237 ((string*)(&TMP$119$))
	fb_StrDelete( vr$237 );
	#define vr$238 ((string*)(&fb$result$))
	fb_StrAssign( vr$238, (integer)-1, vr$236, (integer)-1, (integer)0 );
	label$190:;
	#define vr$239 ((string*)(&fb$result$))
	string* vr$240 = (string*)(fb_StrAllocTempResult( vr$239 ));
	#define vr$241 ((string*)(vr$240))
	return vr$241;
}

integer HISVALIDSYMBOLNAME( char* SYM$ )
{
	integer fb$result$;
	integer SYMLEN$;
	integer TMP$122$;
	integer TMP$124$;
	integer TMP$125$;
	integer TMP$127$;
	#define vr$242 ((integer*)(&fb$result$))
	__builtin_memset( vr$242, 0, (integer)4 );
	label$191:;
	if (SYM$ != (integer)0) goto label$194;
	goto label$192;
	label$194:;
	integer vr$243 = (integer)(fb_StrLen( SYM$, (integer)0 ));
	SYMLEN$ = (vr$243);
	if (SYMLEN$ != (integer)0) goto label$196;
	goto label$192;
	label$196:;
	#define vr$244 ((char*)(SYM$))
	#define vr$245 ((uinteger)(*(char*)((ubyte *)vr$244)))
	#define vr$246 ((integer)((-(vr$245 >= (uinteger)97u))))
	if (vr$246 == (integer)0) goto label$197;
	#define vr$247 ((char*)(SYM$))
	#define vr$248 ((uinteger)(*(char*)((ubyte *)vr$247)))
	#define vr$249 ((integer)((-(vr$248 <= (uinteger)122u))))
	#define vr$250 ((integer)((-(vr$249 != (integer)0))))
	TMP$122$ = (vr$250);
	goto label$215;
	label$197:;
	TMP$122$ = ((integer)0);
	label$215:;
	if (TMP$122$ != (integer)0) goto label$199;
	#define vr$251 ((char*)(SYM$))
	#define vr$252 ((uinteger)(*(char*)((ubyte *)vr$251)))
	#define vr$253 ((integer)((-(vr$252 <= (uinteger)90u))))
	if (vr$253 == (integer)0) goto label$198;
	#define vr$254 ((char*)(SYM$))
	#define vr$255 ((uinteger)(*(char*)((ubyte *)vr$254)))
	#define vr$256 ((integer)((-(vr$255 >= (uinteger)65u))))
	#define vr$257 ((integer)((-(vr$256 != (integer)0))))
	TMP$124$ = (vr$257);
	goto label$217;
	label$198:;
	TMP$124$ = ((integer)0);
	label$217:;
	#define vr$258 ((integer)((-(TMP$124$ != (integer)0))))
	TMP$125$ = (vr$258);
	goto label$216;
	label$199:;
	TMP$125$ = ((integer)-1);
	label$216:;
	if (TMP$125$ != (integer)0) goto label$200;
	#define vr$259 ((char*)(SYM$))
	#define vr$260 ((uinteger)(*(char*)((ubyte *)vr$259)))
	#define vr$261 ((integer)((-(vr$260 == (uinteger)95u))))
	#define vr$262 ((integer)((-(vr$261 != (integer)0))))
	TMP$127$ = (vr$262);
	goto label$218;
	label$200:;
	TMP$127$ = ((integer)-1);
	label$218:;
	if (TMP$127$ != (integer)0) goto label$202;
	goto label$192;
	label$202:;
	{
		integer I$;
		integer TMP$128$;
		I$ = ((integer)1);
		#define vr$263 ((integer)(SYMLEN$ + (integer)-1))
		TMP$128$ = (vr$263);
		goto label$203;
		label$206:;
		{
			integer TMP$129$;
			integer TMP$130$;
			integer TMP$131$;
			integer TMP$132$;
			integer TMP$133$;
			integer TMP$134$;
			#define vr$264 ((char*)((char*)((ubyte *)SYM$ + I$)))
			#define vr$265 ((uinteger)(*(char*)((ubyte *)vr$264)))
			#define vr$266 ((integer)((-(vr$265 >= (uinteger)97u))))
			if (vr$266 == (integer)0) goto label$207;
			#define vr$267 ((char*)((char*)((ubyte *)SYM$ + I$)))
			#define vr$268 ((uinteger)(*(char*)((ubyte *)vr$267)))
			#define vr$269 ((integer)((-(vr$268 <= (uinteger)122u))))
			#define vr$270 ((integer)((-(vr$269 != (integer)0))))
			TMP$129$ = (vr$270);
			goto label$219;
			label$207:;
			TMP$129$ = ((integer)0);
			label$219:;
			if (TMP$129$ != (integer)0) goto label$209;
			#define vr$271 ((char*)((char*)((ubyte *)SYM$ + I$)))
			#define vr$272 ((uinteger)(*(char*)((ubyte *)vr$271)))
			#define vr$273 ((integer)((-(vr$272 <= (uinteger)90u))))
			if (vr$273 == (integer)0) goto label$208;
			#define vr$274 ((char*)((char*)((ubyte *)SYM$ + I$)))
			#define vr$275 ((uinteger)(*(char*)((ubyte *)vr$274)))
			#define vr$276 ((integer)((-(vr$275 >= (uinteger)65u))))
			#define vr$277 ((integer)((-(vr$276 != (integer)0))))
			TMP$130$ = (vr$277);
			goto label$221;
			label$208:;
			TMP$130$ = ((integer)0);
			label$221:;
			#define vr$278 ((integer)((-(TMP$130$ != (integer)0))))
			TMP$131$ = (vr$278);
			goto label$220;
			label$209:;
			TMP$131$ = ((integer)-1);
			label$220:;
			if (TMP$131$ != (integer)0) goto label$210;
			#define vr$279 ((char*)((char*)((ubyte *)SYM$ + I$)))
			#define vr$280 ((uinteger)(*(char*)((ubyte *)vr$279)))
			#define vr$281 ((integer)((-(vr$280 == (uinteger)95u))))
			#define vr$282 ((integer)((-(vr$281 != (integer)0))))
			TMP$132$ = (vr$282);
			goto label$222;
			label$210:;
			TMP$132$ = ((integer)-1);
			label$222:;
			if (TMP$132$ != (integer)0) goto label$212;
			#define vr$283 ((char*)((char*)((ubyte *)SYM$ + I$)))
			#define vr$284 ((uinteger)(*(char*)((ubyte *)vr$283)))
			#define vr$285 ((integer)((-(vr$284 <= (uinteger)57u))))
			if (vr$285 == (integer)0) goto label$211;
			#define vr$286 ((char*)((char*)((ubyte *)SYM$ + I$)))
			#define vr$287 ((uinteger)(*(char*)((ubyte *)vr$286)))
			#define vr$288 ((integer)((-(vr$287 >= (uinteger)48u))))
			#define vr$289 ((integer)((-(vr$288 != (integer)0))))
			TMP$133$ = (vr$289);
			goto label$224;
			label$211:;
			TMP$133$ = ((integer)0);
			label$224:;
			#define vr$290 ((integer)((-(TMP$133$ != (integer)0))))
			TMP$134$ = (vr$290);
			goto label$223;
			label$212:;
			TMP$134$ = ((integer)-1);
			label$223:;
			if (TMP$134$ != (integer)0) goto label$214;
			goto label$192;
			label$214:;
		};
		label$204:;
		#define vr$291 ((integer)(I$ + (integer)1))
		I$ = (vr$291);
		label$203:;
		if (I$ <= TMP$128$) goto label$206;
		label$205:;
	};
	fb$result$ = ((integer)-1);
	label$192:;
	#define vr$292 ((integer)(fb$result$))
	return vr$292;
}

string* STRUNQUOTE( string* S$ )
{
	string fb$result$;
	#define vr$293 ((string*)(&fb$result$))
	__builtin_memset( vr$293, 0, (integer)12 );
	label$229:;
	integer vr$294 = (integer)(STRISQUOTED( (string*)(S$) ));
	if (vr$294 == (integer)0) goto label$232;
	{
		integer vr$295 = (integer)(fb_StrLen( (string*)(S$), (integer)-1 ));
		#define vr$296 ((integer)(vr$295 + (integer)-2))
		string* vr$297 = (string*)(fb_StrMid( (string*)(S$), (integer)2, vr$296 ));
		#define vr$298 ((string*)(&fb$result$))
		fb_StrAssign( vr$298, (integer)-1, vr$297, (integer)-1, (integer)0 );
		goto label$230;
	};
	label$232:;
	label$231:;
	#define vr$299 ((string*)(&fb$result$))
	fb_StrAssign( vr$299, (integer)-1, (string*)(S$), (integer)-1, (integer)0 );
	goto label$230;
	label$230:;
	#define vr$300 ((string*)(&fb$result$))
	string* vr$301 = (string*)(fb_StrAllocTempResult( vr$300 ));
	#define vr$302 ((string*)(vr$301))
	return vr$302;
}

__attribute__(( constructor )) static void fb_ctor__hlp( void )
{
	label$0:;
	label$1:;
}

static void _ZN11TSTRSETITEMaSERS_( TSTRSETITEM* THIS$, TSTRSETITEM* __FB_RHS__$ )
{
	label$4:;
	fb_StrAssign( (TSTRSETITEM*)(THIS$), (integer)-1, (TSTRSETITEM*)(__FB_RHS__$), (integer)-1, (integer)0 );
	#define vr$303 ((integer*)((TSTRSETITEM*)(__FB_RHS__$)))
	#define vr$304 ((integer*)((TSTRSETITEM*)(THIS$)))
	*(integer*)((ubyte *)vr$304 + 12) = (*(integer*)((ubyte *)vr$303 + 12));
	label$5:;
}

static integer STRISQUOTED( string* S$ )
{
	integer fb$result$;
	integer LAST$;
	#define vr$305 ((integer*)(&fb$result$))
	__builtin_memset( vr$305, 0, (integer)4 );
	label$225:;
	integer vr$306 = (integer)(fb_StrLen( (string*)(S$), (integer)-1 ));
	#define vr$307 ((integer)(vr$306 + (integer)-1))
	LAST$ = (vr$307);
	if (LAST$ >= (integer)1) goto label$228;
	{
		fb$result$ = ((integer)0);
		goto label$226;
	};
	label$228:;
	label$227:;
	#define vr$308 ((char**)((string*)(S$)))
	#define vr$309 ((ubyte*)(*(char**)((ubyte *)vr$308)))
	#define vr$310 ((uinteger)(*(ubyte*)((ubyte *)vr$309)))
	#define vr$311 ((integer)((-(vr$310 == (uinteger)34u))))
	#define vr$312 ((char**)((string*)(S$)))
	#define vr$313 ((char*)((char*)((ubyte *)*(char**)((ubyte *)vr$312) + LAST$)))
	#define vr$314 ((uinteger)(*(ubyte*)((ubyte *)vr$313)))
	#define vr$315 ((integer)((-(vr$314 == (uinteger)34u))))
	#define vr$316 ((integer)(vr$311 & vr$315))
	#define vr$317 ((char**)((string*)(S$)))
	#define vr$318 ((ubyte*)(*(char**)((ubyte *)vr$317)))
	#define vr$319 ((uinteger)(*(ubyte*)((ubyte *)vr$318)))
	#define vr$320 ((integer)((-(vr$319 == (uinteger)39u))))
	#define vr$321 ((char**)((string*)(S$)))
	#define vr$322 ((char*)((char*)((ubyte *)*(char**)((ubyte *)vr$321) + LAST$)))
	#define vr$323 ((uinteger)(*(ubyte*)((ubyte *)vr$322)))
	#define vr$324 ((integer)((-(vr$323 == (uinteger)39u))))
	#define vr$325 ((integer)(vr$320 & vr$324))
	#define vr$326 ((integer)(vr$316 | vr$325))
	fb$result$ = (vr$326);
	goto label$226;
	label$226:;
	#define vr$327 ((integer)(fb$result$))
	return vr$327;
}
// Total compilation time: 0.0406189690111205 seconds. 
