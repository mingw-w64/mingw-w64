#include	<wchar.h>


#if 0
wchar_t *
wmemcpy(s1, s2, n)
	register wchar_t * __restrict__		s1;
	register const wchar_t * __restrict__	s2;
	register size_t					n;
	{
	wchar_t						*orig_s1 = s1;

	if ( s1 == NULL || s2 == NULL || n == 0 )
		return orig_s1;		/* robust */

	for ( ; n > 0; --n )
		*s1++ = *s2++;

	return orig_s1;
	}

#endif
