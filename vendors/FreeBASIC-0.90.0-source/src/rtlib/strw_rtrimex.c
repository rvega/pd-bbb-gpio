/* enhanced rtrimw$ function */

#include "fb.h"


/*:::::*/
FBCALL FB_WCHAR *fb_WstrRTrimEx ( const FB_WCHAR *src, const FB_WCHAR *pattern )
{
	FB_WCHAR 	*dst;
	int 		len;
	const FB_WCHAR *p = NULL;

    if( src == NULL ) {
        return NULL;
    }

	{
        size_t len_pattern = fb_wstr_Len( pattern );
		len = fb_wstr_Len( src );
		if( len >= len_pattern )
		{
            if( len_pattern==1 ) {
                p = fb_wstr_SkipCharRev( src,
                                         len,
                                         *pattern );
                len = (int)(p - src) + 1;

            } else if( len_pattern != 0 ) {
                size_t test_index = len - len_pattern;
                p = src;
                while (len >= len_pattern ) {
                    if( fb_wstr_Compare( p + test_index,
                                         pattern,
                                         len_pattern )!=0 )
                        break;
                    test_index -= len_pattern;
                }
                len = test_index + len_pattern;
            }
		}
    }

	if( len > 0 )
	{
		/* alloc temp string */
        dst = fb_wstr_AllocTemp( len );
		if( dst != NULL )
		{
			/* simple copy */
			fb_wstr_Copy( dst, src, len );
		}
		else
			dst = NULL;
    }
	else
		dst = NULL;

    return dst;
}

