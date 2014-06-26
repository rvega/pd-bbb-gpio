// Compilation of objinfo.bas started at 13:35:37 on 07-04-2013
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
	typedef struct _DATABUFFER {
		ubyte* P;
		integer SIZE;
	} DATABUFFER;
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
	typedef struct _TSTRSETITEM {
		string S;
		integer USERDATA;
	} TSTRSETITEM;
	static void _ZN11TSTRSETITEMC1Ev( TSTRSETITEM* );
	static void _ZN11TSTRSETITEMaSERS_( TSTRSETITEM*, TSTRSETITEM* );
	static void _ZN11TSTRSETITEMC1ERS_( TSTRSETITEM*, TSTRSETITEM* );
	static void _ZN11TSTRSETITEMD1Ev( TSTRSETITEM* );
				typedef int TMP$16;
typedef struct _OBJINFOPARSERCTX {
	integer I;
	string FILENAME;
	integer IS_OLD;
	integer OLD_SECTION;
} OBJINFOPARSERCTX;
static void _ZN16OBJINFOPARSERCTXC1Ev( OBJINFOPARSERCTX* );
static void _ZN16OBJINFOPARSERCTXaSERS_( OBJINFOPARSERCTX*, OBJINFOPARSERCTX* );
static void _ZN16OBJINFOPARSERCTXC1ERS_( OBJINFOPARSERCTX*, OBJINFOPARSERCTX* );
static void _ZN16OBJINFOPARSERCTXD1Ev( OBJINFOPARSERCTX* );
typedef struct _ELF32_SH {
	ulong SH_NAME __attribute__((packed));
	ulong SH_TYPE __attribute__((packed));
	ulong SH_FLAGS __attribute__((packed));
	ulong SH_ADDR __attribute__((packed));
	ulong SH_OFFSET __attribute__((packed));
	ulong SH_SIZE __attribute__((packed));
	ulong SH_LINK __attribute__((packed));
	ulong SH_INFO __attribute__((packed));
	ulong SH_ADDRALIGN __attribute__((packed));
	ulong SH_ENTSIZE __attribute__((packed));
} ELF32_SH;
typedef struct _ELF32_H {
	ubyte E_IDENT[16] __attribute__((packed));
	ushort E_TYPE __attribute__((packed));
	ushort E_MACHINE __attribute__((packed));
	ulong E_VERSION __attribute__((packed));
	ulong E_ENTRY __attribute__((packed));
	ulong E_PHOFF __attribute__((packed));
	ulong E_SHOFF __attribute__((packed));
	ulong E_FLAGS __attribute__((packed));
	ushort E_EHSIZE __attribute__((packed));
	ushort E_PHENTSIZE __attribute__((packed));
	ushort E_PHNUM __attribute__((packed));
	ushort E_SHENTSIZE __attribute__((packed));
	ushort E_SHNUM __attribute__((packed));
	ushort E_SHSTRNDX __attribute__((packed));
} ELF32_H;
	typedef struct _COFF_H {
		ushort MAGIC __attribute__((packed));
		ushort SECCOUNT __attribute__((packed));
		ulong TIMESTAMP __attribute__((packed));
		ulong SYMTBOFFSET __attribute__((packed));
		ulong SYMCOUNT __attribute__((packed));
		ushort OPTHEADSIZE __attribute__((packed));
		ushort FLAGS __attribute__((packed));
	} COFF_H;
	typedef struct _COFF_SH {
		ubyte NAME[8] __attribute__((packed));
		ulong PADDR __attribute__((packed));
		ulong VADDR __attribute__((packed));
		ulong SIZE __attribute__((packed));
		ulong DATAOFFSET __attribute__((packed));
		ulong RELOFFSET __attribute__((packed));
		ulong LNOFFSET __attribute__((packed));
		ushort RELCOUNT __attribute__((packed));
		ushort LNCOUNT __attribute__((packed));
		ulong FLAGS __attribute__((packed));
	} COFF_SH;
	typedef struct _AR_H {
		ubyte NAME[16] __attribute__((packed));
		ubyte MODIFYTIME[12] __attribute__((packed));
		ubyte OWNERID[6] __attribute__((packed));
		ubyte GROUPID[6] __attribute__((packed));
		ubyte MODE[8] __attribute__((packed));
		ubyte SIZE[10] __attribute__((packed));
		ubyte MAGIC[2] __attribute__((packed));
	} AR_H;
		typedef int FB_COMPOPT;
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
integer fb_FileGetIOB( integer, uinteger, void*, integer, uinteger* );
integer fb_FileFree( void );
longint fb_FileSize( integer );
void* malloc( integer );
void free( void* );
string* fb_StrAssign( void*, integer, void*, integer, integer );
void fb_StrDelete( string* );
string* fb_StrConcat( string*, void*, integer, void*, integer );
integer fb_StrCompare( void*, integer, void*, integer );
string* fb_StrAllocTempDescZ( char* );
integer fb_StrLen( void*, integer );
double fb_VAL( string* );
static void fb_ctor__objinfo( void )__attribute__(( constructor )) ;
void* LISTGETHEAD( TLIST* );
void* LISTGETNEXT( void* );
void OBJINFOREADLIBFILE( string* );
integer FBGETOPTION( integer );
integer HFILEEXISTS( char* );
static ELF32_SH* HCHECKELF32_SH( ELF32_H*, integer );
static char* HGETELF32SECTIONNAME( ELF32_H*, integer, integer );
static void HLOADFBCTINFFROMELF32( void );
static void HLOADFBCTINFFROMCOFF( void );
static char* HLOADARSTRING( ubyte*, integer );
static void HLOADOBJFROMAR( void );
static void HLOADFILE( string*, DATABUFFER* );
static void HLOADFBCTINFFROMOBJ( void );
static void HRESETBUFFERS( void );
static void OBJINFOINIT( string* );
static char* HGETNEXTSTRING( void );
static void _GLOBAL__I( void )__attribute__(( constructor )) ;
static void _GLOBAL__D( void )__attribute__(( destructor )) ;
typedef struct _$fb_RTTI $fb_RTTI$type;
typedef struct _$fb_RTTI {
	void* STDLIBVT;
	char* ID;
	$fb_RTTI$type* PRTTIBASE;
} $fb_RTTI;
extern $fb_RTTI$type __fb_ZTS6Object;
static DATABUFFER ARDATA$;
static DATABUFFER OBJDATA$;
static DATABUFFER FBCTINF$;
static OBJINFOPARSERCTX PARSER$;
static char FBCTINFNAME$[9] = ".fbctinf";
static ubyte ELF32MAGIC$[16] = { 127u, 69u, 76u, 70u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u };
static ubyte ARMAGIC$[8] = { 33u, 60u, 97u, 114u, 99u, 104u, 62u, 10u };
typedef struct _ENTRYINFO {
	char* TEXT;
	integer HAS_PARAM;
} ENTRYINFO;
static ENTRYINFO ENTRIES$[4] = { { (void*)(char*)"-l", -1 }, { (void*)(char*)"-p", -1 }, { (void*)(char*)"-mt", 0 }, { (void*)(char*)"-lang", -1 } };

void OBJINFOREADOBJ( string* OBJFILE$ )
{
	label$150:;
	OBJINFOINIT( (string*)(OBJFILE$) );
	HLOADFILE( (string*)(OBJFILE$), (DATABUFFER*)&OBJDATA$ );
	if (*(integer*)((ubyte *)&OBJDATA$ + 4) != (integer)0) goto label$153;
	{
		goto label$151;
	};
	label$153:;
	label$152:;
	HLOADFBCTINFFROMOBJ(  );
	label$151:;
}

void OBJINFOREADLIBFILE( string* LIBFILE$ )
{
	label$154:;
	OBJINFOINIT( (string*)(LIBFILE$) );
	HLOADFILE( (string*)(LIBFILE$), (DATABUFFER*)&ARDATA$ );
	if (*(integer*)((ubyte *)&ARDATA$ + 4) != (integer)0) goto label$157;
	{
		goto label$155;
	};
	label$157:;
	label$156:;
	HLOADOBJFROMAR(  );
	if (*(integer*)((ubyte *)&OBJDATA$ + 4) != (integer)0) goto label$159;
	{
		goto label$155;
	};
	label$159:;
	label$158:;
	HLOADFBCTINFFROMOBJ(  );
	label$155:;
}

void OBJINFOREADLIB( string* LIBNAME$, TLIST* LIBPATHS$ )
{
	static string LIBFILE$;
	static string FILENAME$;
	TSTRSETITEM* PATH$;
	string TMP$48$;
	string TMP$49$;
	label$160:;
	#define vr$0 ((string*)(&TMP$48$))
	__builtin_memset( vr$0, 0, (integer)12 );
	#define vr$1 ((string*)(&TMP$48$))
	string* vr$2 = (string*)(fb_StrConcat( vr$1, (char*)"lib", (integer)4, (string*)(LIBNAME$), (integer)-1 ));
	#define vr$3 ((string*)(&TMP$49$))
	__builtin_memset( vr$3, 0, (integer)12 );
	#define vr$4 ((string*)(&TMP$49$))
	string* vr$5 = (string*)(fb_StrConcat( vr$4, vr$2, (integer)-1, (char*)".a", (integer)3 ));
	fb_StrAssign( (string*)&FILENAME$, (integer)-1, vr$5, (integer)-1, (integer)0 );
	void* vr$6 = (void*)(LISTGETHEAD( LIBPATHS$ ));
	PATH$ = (vr$6);
	label$162:;
	if (PATH$ == (TSTRSETITEM*)0) goto label$163;
	{
		string TMP$50$;
		string TMP$51$;
		#define vr$7 ((string*)(&TMP$50$))
		__builtin_memset( vr$7, 0, (integer)12 );
		#define vr$8 ((string*)(&TMP$50$))
		string* vr$9 = (string*)(fb_StrConcat( vr$8, PATH$, (integer)-1, (char*)"/", (integer)2 ));
		#define vr$10 ((string*)(&TMP$51$))
		__builtin_memset( vr$10, 0, (integer)12 );
		#define vr$11 ((string*)(&TMP$51$))
		string* vr$12 = (string*)(fb_StrConcat( vr$11, vr$9, (integer)-1, (string*)&FILENAME$, (integer)-1 ));
		fb_StrAssign( (string*)&LIBFILE$, (integer)-1, vr$12, (integer)-1, (integer)0 );
		#define vr$13 ((char**)((string*)&LIBFILE$))
		integer vr$14 = (integer)(HFILEEXISTS( *(char**)((ubyte *)vr$13) ));
		if (vr$14 == (integer)0) goto label$165;
		{
			goto label$163;
		};
		label$165:;
		label$164:;
		void* vr$15 = (void*)(LISTGETNEXT( PATH$ ));
		PATH$ = (vr$15);
	};
	goto label$162;
	label$163:;
	if (PATH$ != (integer)0) goto label$167;
	{
		goto label$161;
	};
	label$167:;
	label$166:;
	OBJINFOREADLIBFILE( (string*)&LIBFILE$ );
	label$161:;
}

integer OBJINFOREADNEXT( string* DAT$ )
{
	integer fb$result$;
	#define vr$16 ((integer*)(&fb$result$))
	__builtin_memset( vr$16, 0, (integer)4 );
	label$174:;
	if (*(integer*)((ubyte *)&FBCTINF$ + 4) > (integer)0) goto label$177;
	{
		fb$result$ = ((integer)-1);
		goto label$175;
	};
	label$177:;
	label$176:;
	if (*(integer*)((ubyte *)&PARSER$ + 16) == (integer)0) goto label$179;
	{
		label$180:;
		if (*(integer*)(&PARSER$) >= *(integer*)((ubyte *)&FBCTINF$ + 4)) goto label$181;
		{
			if (*(integer*)((ubyte *)&PARSER$ + 20) >= (integer)0) goto label$183;
			{
				#define vr$17 ((ubyte*)((ubyte*)((ubyte *)*(ubyte**)(&FBCTINF$) + *(integer*)(&PARSER$))))
				#define vr$18 ((integer)(*(ubyte*)((ubyte *)vr$17)))
				*(integer*)((ubyte *)&PARSER$ + 20) = (vr$18);
				#define vr$19 ((integer)(*(integer*)(&PARSER$) + (integer)1))
				*(integer*)(&PARSER$) = (vr$19);
				#define vr$20 ((integer)((-(*(integer*)((ubyte *)&PARSER$ + 20) <= (TMP$16)0))))
				#define vr$21 ((integer)((-(*(integer*)((ubyte *)&PARSER$ + 20) > (TMP$16)3))))
				#define vr$22 ((integer)(vr$20 | vr$21))
				if (vr$22 == (integer)0) goto label$185;
				{
					*(integer*)((ubyte *)&PARSER$ + 20) = ((integer)-1);
					*(integer*)(&PARSER$) = (*(integer*)((ubyte *)&FBCTINF$ + 4));
					fb$result$ = ((integer)-1);
					goto label$175;
				};
				label$185:;
				label$184:;
			};
			label$183:;
			label$182:;
			if (*(integer*)(&PARSER$) < *(integer*)((ubyte *)&FBCTINF$ + 4)) goto label$187;
			{
				fb$result$ = ((integer)-1);
				goto label$175;
			};
			label$187:;
			label$186:;
			#define vr$23 ((integer)(*(integer*)(&PARSER$) + (integer)1))
			*(integer*)(&PARSER$) = (vr$23);
			#define vr$24 ((ubyte*)((ubyte*)((ubyte *)*(ubyte**)(&FBCTINF$) + *(integer*)(&PARSER$))))
			#define vr$25 ((uinteger)(*(ubyte*)((ubyte *)vr$24 + -1)))
			if (vr$25 != (integer)0) goto label$189;
			{
				*(integer*)((ubyte *)&PARSER$ + 20) = ((integer)-1);
				goto label$180;
			};
			label$189:;
			label$188:;
			char* vr$26 = (char*)(HGETNEXTSTRING(  ));
			fb_StrAssign( (string*)(DAT$), (integer)-1, vr$26, (integer)0, (integer)0 );
			{
				integer TMP$52$;
				TMP$52$ = (*(integer*)((ubyte *)&PARSER$ + 20));
				if (TMP$52$ != (TMP$16)1) goto label$191;
				label$192:;
				{
					fb$result$ = ((integer)0);
					goto label$175;
				};
				goto label$190;
				label$191:;
				if (TMP$52$ != (TMP$16)2) goto label$193;
				label$194:;
				{
					fb$result$ = ((integer)1);
					goto label$175;
				};
				goto label$190;
				label$193:;
				if (TMP$52$ != (TMP$16)3) goto label$195;
				label$196:;
				{
					{
						string TMP$53$;
						#define vr$27 ((string*)(&TMP$53$))
						__builtin_memset( vr$27, 0, (integer)12 );
						#define vr$28 ((string*)(&TMP$53$))
						fb_StrAssign( vr$28, (integer)-1, (string*)(DAT$), (integer)-1, (integer)0 );
						#define vr$29 ((string*)(&TMP$53$))
						integer vr$30 = (integer)(fb_StrCompare( vr$29, (integer)-1, (char*)"-lang", (integer)6 ));
						if (vr$30 != (integer)0) goto label$198;
						label$199:;
						{
							char* vr$31 = (char*)(HGETNEXTSTRING(  ));
							fb_StrAssign( (string*)(DAT$), (integer)-1, vr$31, (integer)0, (integer)0 );
							integer vr$32 = (integer)(fb_StrLen( (string*)(DAT$), (integer)-1 ));
							if (vr$32 <= (integer)0) goto label$201;
							{
								fb$result$ = ((integer)3);
								#define vr$33 ((string*)(&TMP$53$))
								fb_StrDelete( vr$33 );
								goto label$175;
							};
							label$201:;
							label$200:;
						};
						goto label$197;
						label$198:;
						#define vr$34 ((string*)(&TMP$53$))
						integer vr$35 = (integer)(fb_StrCompare( vr$34, (integer)-1, (char*)"-mt", (integer)4 ));
						if (vr$35 != (integer)0) goto label$202;
						label$203:;
						{
							fb$result$ = ((integer)2);
							#define vr$36 ((string*)(&TMP$53$))
							fb_StrDelete( vr$36 );
							goto label$175;
						};
						label$202:;
						label$197:;
						#define vr$37 ((string*)(&TMP$53$))
						fb_StrDelete( vr$37 );
					};
				};
				label$195:;
				label$190:;
			};
		};
		goto label$180;
		label$181:;
	};
	goto label$178;
	label$179:;
	{
		char* vr$38 = (char*)(HGETNEXTSTRING(  ));
		fb_StrAssign( (string*)(DAT$), (integer)-1, vr$38, (integer)0, (integer)0 );
		{
			integer I$;
			I$ = ((integer)0);
			label$207:;
			{
				#define vr$39 ((integer)(I$ << (integer)3))
				integer vr$40 = (integer)(fb_StrCompare( (string*)(DAT$), (integer)-1, *(char**)((ubyte *)&ENTRIES$ + vr$39), (integer)0 ));
				if (vr$40 != (integer)0) goto label$209;
				{
					#define vr$41 ((integer)(I$ << (integer)3))
					if (*(integer*)((ubyte *)&ENTRIES$ + vr$41 + 4) == (integer)0) goto label$211;
					{
						char* vr$42 = (char*)(HGETNEXTSTRING(  ));
						fb_StrAssign( (string*)(DAT$), (integer)-1, vr$42, (integer)0, (integer)0 );
					};
					goto label$210;
					label$211:;
					{
					};
					label$210:;
					fb$result$ = (I$);
					goto label$175;
				};
				label$209:;
				label$208:;
			};
			label$205:;
			#define vr$43 ((integer)(I$ + (integer)1))
			I$ = (vr$43);
			label$204:;
			if (I$ <= (integer)3) goto label$207;
			label$206:;
		};
	};
	label$178:;
	fb$result$ = ((integer)-1);
	label$175:;
	#define vr$44 ((integer)(fb$result$))
	return vr$44;
}

char* OBJINFOGETFILENAME( void )
{
	char* fb$result$;
	#define vr$45 ((char**)(&fb$result$))
	__builtin_memset( vr$45, 0, (integer)4 );
	label$212:;
	#define vr$46 ((string*)(&*(string*)((ubyte *)&PARSER$ + 4)))
	#define vr$47 ((char**)(vr$46))
	fb$result$ = (*(char**)((ubyte *)vr$47));
	label$213:;
	#define vr$48 ((char*)(fb$result$))
	return vr$48;
}

void OBJINFOREADEND( void )
{
	label$214:;
	if (*(ubyte**)(&ARDATA$) == (ubyte*)0) goto label$217;
	{
		free( *(ubyte**)(&ARDATA$) );
	};
	goto label$216;
	label$217:;
	if (*(ubyte**)(&OBJDATA$) == (ubyte*)0) goto label$218;
	{
		free( *(ubyte**)(&OBJDATA$) );
	};
	label$218:;
	label$216:;
	HRESETBUFFERS(  );
	label$215:;
}

char* OBJINFOENCODE( integer ENTRY$ )
{
	char* fb$result$;
	#define vr$49 ((char**)(&fb$result$))
	__builtin_memset( vr$49, 0, (integer)4 );
	label$219:;
	#define vr$50 ((integer)(ENTRY$ << (integer)3))
	fb$result$ = (*(char**)((ubyte *)&ENTRIES$ + vr$50));
	label$220:;
	#define vr$51 ((char*)(fb$result$))
	return vr$51;
}

__attribute__(( constructor )) static void fb_ctor__objinfo( void )
{
	label$0:;
	label$1:;
}

static void _ZN11TSTRSETITEMaSERS_( TSTRSETITEM* THIS$, TSTRSETITEM* __FB_RHS__$ )
{
	label$4:;
	fb_StrAssign( (TSTRSETITEM*)(THIS$), (integer)-1, (TSTRSETITEM*)(__FB_RHS__$), (integer)-1, (integer)0 );
	#define vr$52 ((integer*)((TSTRSETITEM*)(__FB_RHS__$)))
	#define vr$53 ((integer*)((TSTRSETITEM*)(THIS$)))
	*(integer*)((ubyte *)vr$53 + 12) = (*(integer*)((ubyte *)vr$52 + 12));
	label$5:;
}

static void _ZN16OBJINFOPARSERCTXC1Ev( OBJINFOPARSERCTX* THIS$ )
{
	#define vr$54 ((integer*)((OBJINFOPARSERCTX*)(THIS$)))
	#define vr$55 ((integer*)(&*(integer*)((ubyte *)vr$54)))
	__builtin_memset( vr$55, 0, (integer)4 );
	#define vr$56 ((string*)((OBJINFOPARSERCTX*)(THIS$)))
	#define vr$57 ((string*)(&*(string*)((ubyte *)vr$56 + 4)))
	__builtin_memset( vr$57, 0, (integer)12 );
	#define vr$58 ((integer*)((OBJINFOPARSERCTX*)(THIS$)))
	#define vr$59 ((integer*)(&*(integer*)((ubyte *)vr$58 + 16)))
	__builtin_memset( vr$59, 0, (integer)4 );
	#define vr$60 ((integer*)((OBJINFOPARSERCTX*)(THIS$)))
	#define vr$61 ((integer*)(&*(integer*)((ubyte *)vr$60 + 20)))
	__builtin_memset( vr$61, 0, (integer)4 );
	label$10:;
	label$11:;
}

static void _ZN16OBJINFOPARSERCTXaSERS_( OBJINFOPARSERCTX* THIS$, OBJINFOPARSERCTX* __FB_RHS__$ )
{
	label$12:;
	#define vr$62 ((integer*)((OBJINFOPARSERCTX*)(__FB_RHS__$)))
	#define vr$63 ((integer*)((OBJINFOPARSERCTX*)(THIS$)))
	*(integer*)((ubyte *)vr$63) = (*(integer*)((ubyte *)vr$62));
	#define vr$64 ((string*)((OBJINFOPARSERCTX*)(__FB_RHS__$)))
	#define vr$65 ((string*)(&*(string*)((ubyte *)vr$64 + 4)))
	#define vr$66 ((string*)((OBJINFOPARSERCTX*)(THIS$)))
	#define vr$67 ((string*)(&*(string*)((ubyte *)vr$66 + 4)))
	fb_StrAssign( vr$67, (integer)-1, vr$65, (integer)-1, (integer)0 );
	#define vr$68 ((integer*)((OBJINFOPARSERCTX*)(__FB_RHS__$)))
	#define vr$69 ((integer*)((OBJINFOPARSERCTX*)(THIS$)))
	*(integer*)((ubyte *)vr$69 + 16) = (*(integer*)((ubyte *)vr$68 + 16));
	#define vr$70 ((integer*)((OBJINFOPARSERCTX*)(__FB_RHS__$)))
	#define vr$71 ((integer*)((OBJINFOPARSERCTX*)(THIS$)))
	*(integer*)((ubyte *)vr$71 + 20) = (*(integer*)((ubyte *)vr$70 + 20));
	label$13:;
}

static void _ZN16OBJINFOPARSERCTXD1Ev( OBJINFOPARSERCTX* THIS$ )
{
	label$16:;
	label$17:;
	#define vr$72 ((string*)((OBJINFOPARSERCTX*)(THIS$)))
	#define vr$73 ((string*)(&*(string*)((ubyte *)vr$72 + 4)))
	fb_StrDelete( vr$73 );
}

static ELF32_SH* HCHECKELF32_SH( ELF32_H* H$, integer INDEX$ )
{
	ELF32_SH* fb$result$;
	ELF32_SH* SH$;
	integer HEADEROFFSET$;
	#define vr$74 ((ELF32_SH**)(&fb$result$))
	__builtin_memset( vr$74, 0, (integer)4 );
	label$18:;
	#define vr$75 ((ulong*)(H$))
	#define vr$76 ((integer)(INDEX$ * (integer)40))
	#define vr$77 ((ulong)(*(ulong*)((ubyte *)vr$75 + 32) + vr$76))
	#define vr$78 ((integer)(vr$77))
	HEADEROFFSET$ = (vr$78);
	#define vr$79 ((ulongint)(HEADEROFFSET$))
	#define vr$80 ((ulongint)(vr$79 + (ulongint)40ull))
	#define vr$81 ((ulongint)(*(integer*)((ubyte *)&OBJDATA$ + 4)))
	if (vr$80 <= vr$81) goto label$21;
	{
		goto label$19;
	};
	label$21:;
	label$20:;
	#define vr$82 ((void*)(*(ubyte**)(&OBJDATA$)))
	#define vr$83 ((void*)((void*)((ubyte *)vr$82 + HEADEROFFSET$)))
	SH$ = (vr$83);
	#define vr$84 ((ulong*)(SH$))
	#define vr$85 ((ulongint)(*(ulong*)((ubyte *)vr$84 + 16)))
	#define vr$86 ((ulong*)(SH$))
	#define vr$87 ((ulongint)(*(ulong*)((ubyte *)vr$86 + 20)))
	#define vr$88 ((ulongint)(vr$85 + vr$87))
	#define vr$89 ((ulongint)(*(integer*)((ubyte *)&OBJDATA$ + 4)))
	if (vr$88 <= vr$89) goto label$23;
	{
		goto label$19;
	};
	label$23:;
	label$22:;
	fb$result$ = (SH$);
	label$19:;
	#define vr$90 ((ELF32_SH*)(fb$result$))
	return vr$90;
}

static char* HGETELF32SECTIONNAME( ELF32_H* H$, integer INDEX$, integer NAMETB$ )
{
	char* fb$result$;
	static char SECTIONNAME$[33];
	ELF32_SH* SH$;
	integer I$;
	integer J$;
	integer CH$;
	#define vr$91 ((char**)(&fb$result$))
	__builtin_memset( vr$91, 0, (integer)4 );
	label$24:;
	ELF32_SH* vr$92 = (ELF32_SH*)(HCHECKELF32_SH( H$, INDEX$ ));
	SH$ = (vr$92);
	if (SH$ != (integer)0) goto label$27;
	{
		goto label$25;
	};
	label$27:;
	label$26:;
	#define vr$93 ((ulong*)(SH$))
	#define vr$94 ((integer)(NAMETB$ + *(ulong*)((ubyte *)vr$93)))
	I$ = (vr$94);
	J$ = ((integer)0);
	label$28:;
	#define vr$95 ((integer)((-(I$ < *(integer*)((ubyte *)&OBJDATA$ + 4)))))
	#define vr$96 ((integer)((-(J$ < (integer)32))))
	#define vr$97 ((integer)(vr$95 & vr$96))
	if (vr$97 == (integer)0) goto label$29;
	{
		#define vr$98 ((ubyte*)((ubyte*)((ubyte *)*(ubyte**)(&OBJDATA$) + I$)))
		#define vr$99 ((integer)(*(ubyte*)((ubyte *)vr$98)))
		CH$ = (vr$99);
		if (CH$ != (integer)0) goto label$31;
		{
			goto label$29;
		};
		label$31:;
		label$30:;
		#define vr$100 ((ubyte)(CH$))
		#define vr$101 ((char*)((char*)((ubyte *)(char*)&SECTIONNAME$ + J$)))
		*(ubyte*)((ubyte *)vr$101) = (vr$100);
		#define vr$102 ((integer)(I$ + (integer)1))
		I$ = (vr$102);
		#define vr$103 ((integer)(J$ + (integer)1))
		J$ = (vr$103);
	};
	goto label$28;
	label$29:;
	#define vr$104 ((char*)((char*)((ubyte *)(char*)&SECTIONNAME$ + J$)))
	*(ubyte*)((ubyte *)vr$104) = ((ubyte)0);
	fb$result$ = ((char*)&SECTIONNAME$);
	label$25:;
	#define vr$105 ((char*)(fb$result$))
	return vr$105;
}

static void HLOADFBCTINFFROMELF32( void )
{
	ELF32_H* H$;
	ELF32_SH* SH$;
	ELF32_SH* NAMETB$;
	char* SECTIONNAME$;
	label$32:;
	*(ubyte**)(&FBCTINF$) = ((ubyte*)0);
	*(integer*)((ubyte *)&FBCTINF$ + 4) = ((integer)0);
	if (*(integer*)((ubyte *)&OBJDATA$ + 4) >= (integer)52) goto label$35;
	{
		goto label$33;
	};
	label$35:;
	label$34:;
	#define vr$106 ((void*)(*(ubyte**)(&OBJDATA$)))
	H$ = (vr$106);
	{
		integer I$;
		I$ = ((integer)0);
		label$39:;
		{
			#define vr$107 ((ELF32_H*)((ELF32_H*)((ubyte *)H$ + I$)))
			#define vr$108 ((uinteger)(*(ubyte*)((ubyte *)vr$107)))
			#define vr$109 ((uinteger)(*(ubyte*)((ubyte *)ELF32MAGIC$ + I$)))
			if (vr$108 == vr$109) goto label$41;
			{
				goto label$33;
			};
			label$41:;
			label$40:;
		};
		label$37:;
		#define vr$110 ((integer)(I$ + (integer)1))
		I$ = (vr$110);
		label$36:;
		if (I$ <= (integer)15) goto label$39;
		label$38:;
	};
	#define vr$111 ((ushort*)(H$))
	#define vr$112 ((integer)(*(ushort*)((ubyte *)vr$111 + 40)))
	if (vr$112 == (integer)52) goto label$43;
	{
		goto label$33;
	};
	label$43:;
	label$42:;
	#define vr$113 ((ushort*)(H$))
	#define vr$114 ((integer)(*(ushort*)((ubyte *)vr$113 + 16)))
	if (vr$114 == (integer)1) goto label$45;
	{
		goto label$33;
	};
	label$45:;
	label$44:;
	#define vr$115 ((ushort*)(H$))
	#define vr$116 ((integer)(*(ushort*)((ubyte *)vr$115 + 18)))
	if (vr$116 == (integer)3) goto label$47;
	{
		goto label$33;
	};
	label$47:;
	label$46:;
	#define vr$117 ((ushort*)(H$))
	#define vr$118 ((integer)(*(ushort*)((ubyte *)vr$117 + 46)))
	if (vr$118 == (integer)40) goto label$49;
	{
		goto label$33;
	};
	label$49:;
	label$48:;
	#define vr$119 ((ushort*)(H$))
	#define vr$120 ((ulongint)(*(ushort*)((ubyte *)vr$119 + 48)))
	#define vr$121 ((ulongint)(vr$120 * (ulongint)40ull))
	#define vr$122 ((ulongint)(*(integer*)((ubyte *)&OBJDATA$ + 4)))
	if (vr$121 <= vr$122) goto label$51;
	{
		goto label$33;
	};
	label$51:;
	label$50:;
	#define vr$123 ((ushort*)(H$))
	#define vr$124 ((integer)(*(ushort*)((ubyte *)vr$123 + 50)))
	#define vr$125 ((integer)((-(vr$124 < (integer)0))))
	#define vr$126 ((ushort*)(H$))
	#define vr$127 ((ushort*)(H$))
	#define vr$128 ((integer)((-(*(ushort*)((ubyte *)vr$126 + 50) >= *(ushort*)((ubyte *)vr$127 + 48)))))
	#define vr$129 ((integer)(vr$125 | vr$128))
	if (vr$129 == (integer)0) goto label$53;
	{
		goto label$33;
	};
	label$53:;
	label$52:;
	#define vr$130 ((ulong*)(H$))
	#define vr$131 ((ulongint)(*(ulong*)((ubyte *)vr$130 + 32)))
	#define vr$132 ((ushort*)(H$))
	#define vr$133 ((integer)(*(ushort*)((ubyte *)vr$132 + 48)))
	#define vr$134 ((integer)(vr$133 * (integer)40))
	#define vr$135 ((ulongint)(vr$134))
	#define vr$136 ((ulongint)(vr$131 + vr$135))
	#define vr$137 ((ulongint)(*(integer*)((ubyte *)&OBJDATA$ + 4)))
	if (vr$136 <= vr$137) goto label$55;
	{
		goto label$33;
	};
	label$55:;
	label$54:;
	#define vr$138 ((ushort*)(H$))
	#define vr$139 ((integer)(*(ushort*)((ubyte *)vr$138 + 50)))
	ELF32_SH* vr$140 = (ELF32_SH*)(HCHECKELF32_SH( H$, vr$139 ));
	NAMETB$ = (vr$140);
	if (NAMETB$ != (integer)0) goto label$57;
	{
		goto label$33;
	};
	label$57:;
	label$56:;
	{
		integer I$;
		integer TMP$20$;
		I$ = ((integer)1);
		#define vr$141 ((ushort*)(H$))
		#define vr$142 ((integer)(*(ushort*)((ubyte *)vr$141 + 48)))
		#define vr$143 ((integer)(vr$142 + (integer)-1))
		TMP$20$ = (vr$143);
		goto label$58;
		label$61:;
		{
			#define vr$144 ((ulong*)(NAMETB$))
			char* vr$145 = (char*)(HGETELF32SECTIONNAME( H$, I$, *(ulong*)((ubyte *)vr$144 + 16) ));
			SECTIONNAME$ = (vr$145);
			if (SECTIONNAME$ == (char*)0) goto label$63;
			{
				integer vr$146 = (integer)(fb_StrCompare( SECTIONNAME$, (integer)0, (char*)&FBCTINFNAME$, (integer)9 ));
				if (vr$146 != (integer)0) goto label$65;
				{
					ELF32_SH* vr$147 = (ELF32_SH*)(HCHECKELF32_SH( H$, I$ ));
					SH$ = (vr$147);
					if (SH$ == (ELF32_SH*)0) goto label$67;
					{
						#define vr$148 ((ulong*)(SH$))
						#define vr$149 ((integer)(*(ulong*)((ubyte *)vr$148 + 16)))
						#define vr$150 ((ubyte*)((ubyte*)((ubyte *)*(ubyte**)(&OBJDATA$) + vr$149)))
						*(ubyte**)(&FBCTINF$) = (vr$150);
						#define vr$151 ((ulong*)(SH$))
						#define vr$152 ((integer)(*(ulong*)((ubyte *)vr$151 + 20)))
						*(integer*)((ubyte *)&FBCTINF$ + 4) = (vr$152);
						goto label$60;
					};
					label$67:;
					label$66:;
				};
				label$65:;
				label$64:;
			};
			label$63:;
			label$62:;
		};
		label$59:;
		#define vr$153 ((integer)(I$ + (integer)1))
		I$ = (vr$153);
		label$58:;
		if (I$ <= TMP$20$) goto label$61;
		label$60:;
	};
	label$33:;
}

static void HLOADFBCTINFFROMCOFF( void )
{
	COFF_H* H$;
	COFF_SH* SH$;
	COFF_SH* SHBASE$;
	label$68:;
	*(ubyte**)(&FBCTINF$) = ((ubyte*)0);
	*(integer*)((ubyte *)&FBCTINF$ + 4) = ((integer)0);
	if (*(integer*)((ubyte *)&OBJDATA$ + 4) >= (integer)20) goto label$71;
	{
		goto label$69;
	};
	label$71:;
	label$70:;
	#define vr$154 ((void*)(*(ubyte**)(&OBJDATA$)))
	H$ = (vr$154);
	#define vr$155 ((ushort*)(H$))
	#define vr$156 ((integer)(*(ushort*)((ubyte *)vr$155)))
	if (vr$156 == (integer)332) goto label$73;
	{
		goto label$69;
	};
	label$73:;
	label$72:;
	#define vr$157 ((ushort*)(H$))
	#define vr$158 ((integer)(*(ushort*)((ubyte *)vr$157 + 16)))
	if (vr$158 == (integer)0) goto label$75;
	{
		goto label$69;
	};
	label$75:;
	label$74:;
	#define vr$159 ((ushort*)(H$))
	#define vr$160 ((ulongint)(*(ushort*)((ubyte *)vr$159 + 2)))
	#define vr$161 ((ulongint)(vr$160 * (ulongint)40ull))
	#define vr$162 ((ulongint)(*(integer*)((ubyte *)&OBJDATA$ + 4)))
	if (vr$161 <= vr$162) goto label$77;
	{
		goto label$69;
	};
	label$77:;
	label$76:;
	#define vr$163 ((void*)(H$))
	#define vr$164 ((void*)((void*)((ubyte *)vr$163 + (integer)20)))
	SHBASE$ = (vr$164);
	{
		integer I$;
		integer TMP$21$;
		I$ = ((integer)0);
		#define vr$165 ((ushort*)(H$))
		#define vr$166 ((integer)(*(ushort*)((ubyte *)vr$165 + 2)))
		#define vr$167 ((integer)(vr$166 + (integer)-1))
		TMP$21$ = (vr$167);
		goto label$78;
		label$81:;
		{
			#define vr$168 ((integer)(I$ * (integer)40))
			#define vr$169 ((COFF_SH*)((COFF_SH*)((ubyte *)SHBASE$ + vr$168)))
			SH$ = (vr$169);
			{
				integer J$;
				J$ = ((integer)0);
				label$85:;
				{
					#define vr$170 ((COFF_SH*)((COFF_SH*)((ubyte *)SH$ + J$)))
					#define vr$171 ((uinteger)(*(ubyte*)((ubyte *)vr$170)))
					#define vr$172 ((char*)((char*)((ubyte *)(char*)&FBCTINFNAME$ + J$)))
					#define vr$173 ((uinteger)(*(ubyte*)((ubyte *)vr$172)))
					if (vr$171 == vr$173) goto label$87;
					{
						goto label$79;
					};
					label$87:;
					label$86:;
				};
				label$83:;
				#define vr$174 ((integer)(J$ + (integer)1))
				J$ = (vr$174);
				label$82:;
				if (J$ <= (integer)7) goto label$85;
				label$84:;
			};
			#define vr$175 ((ulong*)(SH$))
			#define vr$176 ((ulongint)(*(ulong*)((ubyte *)vr$175 + 20)))
			#define vr$177 ((ulong*)(SH$))
			#define vr$178 ((ulongint)(*(ulong*)((ubyte *)vr$177 + 16)))
			#define vr$179 ((ulongint)(vr$176 + vr$178))
			#define vr$180 ((ulongint)(*(integer*)((ubyte *)&OBJDATA$ + 4)))
			if (vr$179 <= vr$180) goto label$89;
			{
				goto label$69;
			};
			label$89:;
			label$88:;
			#define vr$181 ((ulong*)(SH$))
			#define vr$182 ((integer)(*(ulong*)((ubyte *)vr$181 + 20)))
			#define vr$183 ((ubyte*)((ubyte*)((ubyte *)*(ubyte**)(&OBJDATA$) + vr$182)))
			*(ubyte**)(&FBCTINF$) = (vr$183);
			#define vr$184 ((ulong*)(SH$))
			#define vr$185 ((integer)(*(ulong*)((ubyte *)vr$184 + 16)))
			*(integer*)((ubyte *)&FBCTINF$ + 4) = (vr$185);
			goto label$80;
		};
		label$79:;
		#define vr$186 ((integer)(I$ + (integer)1))
		I$ = (vr$186);
		label$78:;
		if (I$ <= TMP$21$) goto label$81;
		label$80:;
	};
	label$69:;
}

static char* HLOADARSTRING( ubyte* P$, integer LENGTH$ )
{
	char* fb$result$;
	static char S$[17];
	integer LAST$;
	integer I$;
	#define vr$187 ((char**)(&fb$result$))
	__builtin_memset( vr$187, 0, (integer)4 );
	label$90:;
	#define vr$188 ((integer)(LENGTH$ + (integer)-1))
	LAST$ = (vr$188);
	label$92:;
	if (LAST$ < (integer)0) goto label$93;
	{
		#define vr$189 ((ubyte*)((ubyte*)((ubyte *)P$ + LAST$)))
		#define vr$190 ((uinteger)(*(ubyte*)((ubyte *)vr$189)))
		if (vr$190 == (uinteger)32u) goto label$95;
		{
			goto label$93;
		};
		label$95:;
		label$94:;
		#define vr$191 ((integer)(LAST$ + (integer)-1))
		LAST$ = (vr$191);
	};
	goto label$92;
	label$93:;
	I$ = ((integer)0);
	label$96:;
	if (I$ > LAST$) goto label$97;
	{
		#define vr$192 ((ubyte*)((ubyte*)((ubyte *)P$ + I$)))
		#define vr$193 ((char*)((char*)((ubyte *)(char*)&S$ + I$)))
		*(ubyte*)((ubyte *)vr$193) = (*(ubyte*)((ubyte *)vr$192));
		#define vr$194 ((integer)(I$ + (integer)1))
		I$ = (vr$194);
	};
	goto label$96;
	label$97:;
	#define vr$195 ((char*)((char*)((ubyte *)(char*)&S$ + I$)))
	*(ubyte*)((ubyte *)vr$195) = ((ubyte)0);
	fb$result$ = ((char*)&S$);
	label$91:;
	#define vr$196 ((char*)(fb$result$))
	return vr$196;
}

static void HLOADOBJFROMAR( void )
{
	AR_H* H$;
	string FILENAME$;
	integer I$;
	integer FILESIZE$;
	label$98:;
	#define vr$197 ((string*)(&FILENAME$))
	__builtin_memset( vr$197, 0, (integer)12 );
	*(ubyte**)(&OBJDATA$) = ((ubyte*)0);
	*(integer*)((ubyte *)&OBJDATA$ + 4) = ((integer)0);
	if (*(integer*)((ubyte *)&ARDATA$ + 4) >= (integer)8) goto label$101;
	{
		#define vr$198 ((string*)(&FILENAME$))
		fb_StrDelete( vr$198 );
		goto label$99;
	};
	label$101:;
	label$100:;
	{
		I$ = ((integer)0);
		label$105:;
		{
			#define vr$199 ((ubyte*)((ubyte*)((ubyte *)*(ubyte**)(&ARDATA$) + I$)))
			#define vr$200 ((uinteger)(*(ubyte*)((ubyte *)vr$199)))
			#define vr$201 ((uinteger)(*(ubyte*)((ubyte *)ARMAGIC$ + I$)))
			if (vr$200 == vr$201) goto label$107;
			{
				#define vr$202 ((string*)(&FILENAME$))
				fb_StrDelete( vr$202 );
				goto label$99;
			};
			label$107:;
			label$106:;
		};
		label$103:;
		#define vr$203 ((integer)(I$ + (integer)1))
		I$ = (vr$203);
		label$102:;
		if (I$ <= (integer)7) goto label$105;
		label$104:;
	};
	I$ = ((integer)8);
	label$108:;
	{
		#define vr$204 ((integer)(I$ + (integer)60))
		if (vr$204 <= *(integer*)((ubyte *)&ARDATA$ + 4)) goto label$112;
		{
			#define vr$205 ((string*)(&FILENAME$))
			fb_StrDelete( vr$205 );
			goto label$99;
		};
		label$112:;
		label$111:;
		#define vr$206 ((void*)(*(ubyte**)(&ARDATA$)))
		#define vr$207 ((void*)((void*)((ubyte *)vr$206 + I$)))
		H$ = (vr$207);
		#define vr$208 ((ubyte*)(H$))
		#define vr$209 ((ubyte*)(&*(ubyte*)((ubyte *)vr$208)))
		char* vr$210 = (char*)(HLOADARSTRING( vr$209, (integer)16 ));
		#define vr$211 ((string*)(&FILENAME$))
		fb_StrAssign( vr$211, (integer)-1, vr$210, (integer)0, (integer)0 );
		#define vr$212 ((ubyte*)(H$))
		#define vr$213 ((ubyte*)(&*(ubyte*)((ubyte *)vr$212 + 48)))
		char* vr$214 = (char*)(HLOADARSTRING( vr$213, (integer)10 ));
		string* vr$215 = (string*)(fb_StrAllocTempDescZ( vr$214 ));
		double vr$216 = (double)(fb_VAL( vr$215 ));
		integer vr$217 = (integer)(fb_dtosi( vr$216 ));
		FILESIZE$ = (vr$217);
		if (FILESIZE$ >= (integer)0) goto label$114;
		{
			FILESIZE$ = ((integer)0);
		};
		goto label$113;
		label$114:;
		#define vr$218 ((integer)((-(FILESIZE$ > *(integer*)((ubyte *)&ARDATA$ + 4)))))
		#define vr$219 ((integer)(*(integer*)((ubyte *)&ARDATA$ + 4) - I$))
		#define vr$220 ((integer)((-(FILESIZE$ > vr$219))))
		#define vr$221 ((integer)(vr$218 | vr$220))
		if (vr$221 == (integer)0) goto label$115;
		{
			#define vr$222 ((integer)(*(integer*)((ubyte *)&ARDATA$ + 4) - I$))
			FILESIZE$ = (vr$222);
		};
		label$115:;
		label$113:;
		#define vr$223 ((integer)(I$ + (integer)60))
		I$ = (vr$223);
		{
			string TMP$33$;
			#define vr$224 ((string*)(&FILENAME$))
			#define vr$225 ((string*)(&TMP$33$))
			__builtin_memset( vr$225, 0, (integer)12 );
			#define vr$226 ((string*)(&TMP$33$))
			fb_StrAssign( vr$226, (integer)-1, vr$224, (integer)-1, (integer)0 );
			#define vr$227 ((string*)(&TMP$33$))
			integer vr$228 = (integer)(fb_StrCompare( vr$227, (integer)-1, (char*)"__fb_ct.inf", (integer)12 ));
			if (vr$228 == (integer)0) goto label$118;
			label$119:;
			#define vr$229 ((string*)(&TMP$33$))
			integer vr$230 = (integer)(fb_StrCompare( vr$229, (integer)-1, (char*)"__fb_ct.inf/", (integer)13 ));
			if (vr$230 != (integer)0) goto label$117;
			label$118:;
			{
				if (FILESIZE$ <= (integer)0) goto label$121;
				{
					#define vr$231 ((void*)(*(ubyte**)(&ARDATA$)))
					#define vr$232 ((void*)((void*)((ubyte *)vr$231 + I$)))
					*(ubyte**)(&OBJDATA$) = (vr$232);
					*(integer*)((ubyte *)&OBJDATA$ + 4) = (FILESIZE$);
				};
				label$121:;
				label$120:;
				#define vr$233 ((string*)(&TMP$33$))
				fb_StrDelete( vr$233 );
				goto label$109;
			};
			goto label$116;
			label$117:;
			#define vr$234 ((string*)(&TMP$33$))
			integer vr$235 = (integer)(fb_StrCompare( vr$234, (integer)-1, (char*)"/", (integer)2 ));
			if (vr$235 == (integer)0) goto label$123;
			label$124:;
			#define vr$236 ((string*)(&TMP$33$))
			integer vr$237 = (integer)(fb_StrCompare( vr$236, (integer)-1, (char*)"//", (integer)3 ));
			if (vr$237 == (integer)0) goto label$123;
			label$125:;
			#define vr$238 ((string*)(&TMP$33$))
			integer vr$239 = (integer)(fb_StrCompare( vr$238, (integer)-1, (char*)"__.SYMDEF", (integer)10 ));
			if (vr$239 != (integer)0) goto label$122;
			label$123:;
			{
			};
			goto label$116;
			label$122:;
			{
				#define vr$240 ((string*)(&TMP$33$))
				fb_StrDelete( vr$240 );
				goto label$109;
			};
			label$126:;
			label$116:;
			#define vr$241 ((string*)(&TMP$33$))
			fb_StrDelete( vr$241 );
		};
		#define vr$242 ((integer)(I$ + FILESIZE$))
		I$ = (vr$242);
		#define vr$243 ((integer)(I$ & (integer)1))
		#define vr$244 ((integer)(I$ + vr$243))
		I$ = (vr$244);
	};
	label$110:;
	goto label$108;
	label$109:;
	#define vr$245 ((string*)(&FILENAME$))
	fb_StrDelete( vr$245 );
	label$99:;
}

static void HLOADFILE( string* FILENAME$, DATABUFFER* BUF$ )
{
	integer F$;
	integer SIZE$;
	ubyte* P$;
	label$127:;
	#define vr$246 ((ubyte**)(BUF$))
	*(ubyte**)((ubyte *)vr$246) = ((ubyte*)0);
	#define vr$247 ((integer*)(BUF$))
	*(integer*)((ubyte *)vr$247 + 4) = ((integer)0);
	integer vr$248 = (integer)(fb_FileFree(  ));
	F$ = (vr$248);
	integer vr$249 = (integer)(fb_FileOpen( (string*)(FILENAME$), (integer)0, (integer)1, (integer)0, F$, (integer)0 ));
	if (vr$249 == (integer)0) goto label$130;
	{
		goto label$128;
	};
	label$130:;
	label$129:;
	longint vr$250 = (longint)(fb_FileSize( F$ ));
	#define vr$251 ((integer)(vr$250))
	SIZE$ = (vr$251);
	if (SIZE$ <= (integer)0) goto label$132;
	{
		void* vr$252 = (void*)(malloc( SIZE$ ));
		P$ = (vr$252);
		#define vr$253 ((integer*)(&SIZE$))
		integer vr$254 = (integer)(fb_FileGetIOB( F$, (integer)0, P$, SIZE$, vr$253 ));
		if (vr$254 == (integer)0) goto label$134;
		{
			goto label$128;
		};
		label$134:;
		label$133:;
		#define vr$255 ((ubyte**)(BUF$))
		*(ubyte**)((ubyte *)vr$255) = (P$);
		#define vr$256 ((integer*)(BUF$))
		*(integer*)((ubyte *)vr$256 + 4) = (SIZE$);
	};
	label$132:;
	label$131:;
	fb_FileClose( F$ );
	label$128:;
}

static void HLOADFBCTINFFROMOBJ( void )
{
	label$135:;
	{
		uinteger TMP$37$;
		integer vr$257 = (integer)(FBGETOPTION( (FB_COMPOPT)3 ));
		#define vr$258 ((uinteger)(vr$257))
		TMP$37$ = (vr$258);
		goto label$138;
		label$139:;
		{
			HLOADFBCTINFFROMCOFF(  );
		};
		goto label$137;
		label$140:;
		{
			HLOADFBCTINFFROMELF32(  );
		};
		goto label$137;
		label$138:;
		if (TMP$37$ > (uinteger)8u) goto label$137;
		static const void * LABEL$141$[] = {
			&&label$139,
			&&label$139,
			&&label$140,
			&&label$139,
			&&label$139,
			&&label$140,
			&&label$140,
			&&label$140,
			&&label$140,
		(void *)0 };
		#define vr$259 ((uinteger)(TMP$37$ << (uinteger)2u))
		goto **(void**)((ubyte *)LABEL$141$ + vr$259);
		label$137:;
	};
	if (*(integer*)((ubyte *)&FBCTINF$ + 4) != (integer)0) goto label$143;
	{
		goto label$136;
	};
	label$143:;
	label$142:;
	#define vr$260 ((ubyte*)(*(ubyte**)(&FBCTINF$)))
	#define vr$261 ((uinteger)(*(ubyte*)((ubyte *)vr$260)))
	if (vr$261 != (integer)16) goto label$145;
	{
		*(integer*)((ubyte *)&PARSER$ + 16) = ((integer)-1);
		*(integer*)(&PARSER$) = ((integer)1);
	};
	goto label$144;
	label$145:;
	{
		*(integer*)((ubyte *)&PARSER$ + 16) = ((integer)0);
	};
	label$144:;
	label$136:;
}

static void HRESETBUFFERS( void )
{
	label$146:;
	*(ubyte**)(&ARDATA$) = ((ubyte*)0);
	*(integer*)((ubyte *)&ARDATA$ + 4) = ((integer)0);
	*(ubyte**)(&OBJDATA$) = ((ubyte*)0);
	*(integer*)((ubyte *)&OBJDATA$ + 4) = ((integer)0);
	*(ubyte**)(&FBCTINF$) = ((ubyte*)0);
	*(integer*)((ubyte *)&FBCTINF$ + 4) = ((integer)0);
	label$147:;
}

static void OBJINFOINIT( string* FILENAME$ )
{
	label$148:;
	HRESETBUFFERS(  );
	*(integer*)(&PARSER$) = ((integer)0);
	fb_StrAssign( (OBJINFOPARSERCTX*)((ubyte *)&PARSER$ + 4), (integer)-1, (string*)(FILENAME$), (integer)-1, (integer)0 );
	*(integer*)((ubyte *)&PARSER$ + 16) = ((integer)0);
	*(integer*)((ubyte *)&PARSER$ + 20) = ((integer)-1);
	label$149:;
}

static char* HGETNEXTSTRING( void )
{
	char* fb$result$;
	integer BEGIN$;
	#define vr$262 ((char**)(&fb$result$))
	__builtin_memset( vr$262, 0, (integer)4 );
	label$168:;
	fb$result$ = ((char*)"");
	BEGIN$ = (*(integer*)(&PARSER$));
	label$170:;
	if (*(integer*)(&PARSER$) >= *(integer*)((ubyte *)&FBCTINF$ + 4)) goto label$171;
	{
		#define vr$263 ((integer)(*(integer*)(&PARSER$) + (integer)1))
		*(integer*)(&PARSER$) = (vr$263);
		#define vr$264 ((ubyte*)((ubyte*)((ubyte *)*(ubyte**)(&FBCTINF$) + *(integer*)(&PARSER$))))
		#define vr$265 ((uinteger)(*(ubyte*)((ubyte *)vr$264 + -1)))
		if (vr$265 != (integer)0) goto label$173;
		{
			#define vr$266 ((ubyte*)((ubyte*)((ubyte *)*(ubyte**)(&FBCTINF$) + BEGIN$)))
			fb$result$ = (vr$266);
			goto label$169;
		};
		label$173:;
		label$172:;
	};
	goto label$170;
	label$171:;
	label$169:;
	#define vr$267 ((char*)(fb$result$))
	return vr$267;
}

__attribute__(( constructor )) static void _GLOBAL__I( void )
{
	label$222:;
	_ZN16OBJINFOPARSERCTXC1Ev( (OBJINFOPARSERCTX*)&PARSER$ );
	label$223:;
}

__attribute__(( destructor )) static void _GLOBAL__D( void )
{
	label$225:;
	_ZN16OBJINFOPARSERCTXD1Ev( (OBJINFOPARSERCTX*)&PARSER$ );
	label$226:;
}
// Total compilation time: 0.02376199956052005 seconds. 
