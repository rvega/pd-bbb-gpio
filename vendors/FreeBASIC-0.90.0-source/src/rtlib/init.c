/* libfb initialization */

#include "fb.h"
#include <locale.h>

FB_RTLIB_CTX __fb_ctx /* not initialized */;
static int __fb_is_inicnt = 0;

/* called from fbrt0 */
void fb_hRtInit( void )
{
	/* already initialized? */
	++__fb_is_inicnt;
	if( __fb_is_inicnt != 1 )
		return;

	/* initialize context */
	memset( &__fb_ctx, 0, sizeof( FB_RTLIB_CTX ) );
    
	/* os-dep initialization */
	fb_hInit( );

#ifdef ENABLE_MT
	fb_TlsInit( );
#endif

	/**
	 * With the default "C" locale (which is just plain 7-bit ASCII),
	 * our mbstowcs() calls (from fb_wstr_ConvFromA()) fail to convert
	 * zstrings specific to the user's locale to Unicode wstrings.
	 *
	 * To fix this we must tell the CRT to use the user's locale setting,
	 * i.e. the locale given by LC_* or LANG environment variables.
	 *
	 * We should change the LC_CTYPE setting only, to affect the behaviour
	 * of the codepage <-> Unicode conversion functions, but not for
	 * example LC_NUMERIC, which would affect things like the decimal
	 * separator used by float <-> string conversion functions.
	 */
	setlocale( LC_CTYPE, "" );

}

/* called from fbrt0 */
void fb_hRtExit( void )
{
	--__fb_is_inicnt;
	if( __fb_is_inicnt != 0 )
		return;

	/* atexit() can't be used because if OPEN is called in a global ctor inside 
	   a shared-lib and any other file function is called in the respective global
	   dtor, it would be already reseted - the atexit() chain is called before the 
	   global dtors one*/
	fb_FileReset( );

	/* os-dep termination */
	fb_hEnd( 0 );

#ifdef ENABLE_MT
	fb_TlsExit( );
#endif

	/* If an error message was stored, print it now, after the console was
	   cleaned up. At least the DOS gfxlib clears the console on exit,
	   thus any error messages must be printed after that or they would
	   not be visible. */
	if( __fb_ctx.errmsg )
		fputs( __fb_ctx.errmsg, stderr );
}

/* called by FB program */
FBCALL void fb_Init( int argc, char **argv, int lang )
{
	__fb_ctx.argc = argc;
	__fb_ctx.argv = argv;
	__fb_ctx.lang = lang;
}

/* called by FB program */
FBCALL void fb_End( int errlevel )
{
	exit( errlevel );
}
