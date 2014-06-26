/* rtrimw$ ANY function */

#include "fb.h"


/*:::::*/
FBCALL FB_WCHAR *fb_WstrRTrimAny ( const FB_WCHAR *src, const FB_WCHAR *pattern )
{
    const FB_WCHAR *pachText;
	FB_WCHAR 	*dst;
	size_t 		len;

    if( src == NULL ) {
        return NULL;
    }

	len = fb_wstr_Len( src );
    {
        size_t len_pattern = fb_wstr_Len( pattern );
        pachText = src;
		while ( len != 0 )
        {
            size_t i;
            --len;
            for( i=0; i!=len_pattern; ++i ) {
                if( wcschr( pattern, pachText[len] )!=NULL ) {
                    break;
                }
            }
            if( i==len_pattern ) {
                ++len;
                break;
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

