/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define __CRT__NO_INLINE
#include <stddef.h>
#include <string.h> /* for memcmp prototype */

int __cdecl memcmp(const void *_S1, const void *_S2, size_t _N)
{
    const unsigned char *s1 = _S1, *s2 = _S2;

    if (_N == 0 || s1 == s2)
	return 0;	/* even for NULL pointers */

    if ((s1 != NULL) != (s2 != NULL))
	return s2 == NULL ? 1 : -1;	/* robust */

    for ( ; 0 < _N; ++s1, ++s2, --_N)
	if (*s1 != *s2)
	    return (*s1 < *s2 ? -1 : +1);

    return 0;
}

