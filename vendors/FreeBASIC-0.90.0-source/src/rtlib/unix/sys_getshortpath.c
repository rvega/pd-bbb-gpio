#include "../fb.h"

char *fb_hGetShortPath( char *src, char *dst, int maxlen )
{
	if( strchr( src, 32 ) == NULL ) {
		strcpy( dst, src );
	} else {
		int i = 0;
		char *old_dst = dst;

		while ((*src) && (i < maxlen - 1)) {
			if (*src == ' ') {
				*dst++ = '\\';
				i++;
			}
			if (i == maxlen - 1)
				break;
			*dst++ = *src++;
			i++;
		}
		dst = old_dst;
		dst[maxlen - 1] = '\0';
	}

	return dst;
}
