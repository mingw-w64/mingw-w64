#include	<wchar.h>

#if 0
wchar_t *wmemchr(s, c, n)
	register const wchar_t	*s;
	register wchar_t		c;
	register size_t			n;
	{
	if ( s != NULL )
		for ( ; n > 0; ++s, --n )
			if ( *s == c )
				return (wchar_t *)s;

	return NULL;
	}

#endif
