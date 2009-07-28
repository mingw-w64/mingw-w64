/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#define __CRT__NO_INLINE
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

_CONST_RETURN wchar_t *__cdecl wmemchr(const wchar_t *_S,wchar_t _C,size_t _N)
{
	for ( ; 0 < _N; ++_S, --_N)
		if (*_S == _C)
			return (_CONST_RETURN wchar_t *)(_S);
	return NULL;
}

