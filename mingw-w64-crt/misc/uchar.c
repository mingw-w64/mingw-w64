/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
/* ISO C1x Unicode utilities
 * Based on ISO/IEC SC22/WG14 9899 TR 19769 (SC22 N1326)
 *
 *  THIS SOFTWARE IS NOT COPYRIGHTED
 *
 *  This source code is offered for use in the public domain. You may
 *  use, modify or distribute it freely.
 *
 *  This code is distributed in the hope that it will be useful but
 *  WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 *  DISCLAIMED. This includes but is not limited to warranties of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *  Date: 2011-09-27
 */

#include <errno.h>
#include <uchar.h>

size_t mbrtoc16 (char16_t *__restrict__ pc16,
		 const char *__restrict__ s,
		 size_t n,
		 mbstate_t *__restrict__ state)
{
/* wchar_t should compatible to char16_t on Windows */
    return mbrtowc((wchar_t *)pc16, s, n, state);
}

size_t c16rtomb (char *__restrict__ s,
		 char16_t c16,
		 mbstate_t *__restrict__ state)
{
/* wchar_t should compatible to char16_t on Windows */
    return wcrtomb(s, c16, state);
}

size_t mbrtoc32 (char32_t *__restrict__ pc32,
		 const char *__restrict__ s,
		 size_t n,
		 mbstate_t *__restrict__ __UNUSED_PARAM(ps))
{
    if (*s == 0)
    {
	*pc32 = 0;
	return 0;
    }

    /* ASCII character - high bit unset */
    if ((*s & 0x80) == 0)
    {
	*pc32 = *s;
	return 1;
    }

    /* Multibyte chars */
    if ((*s & 0xE0) == 0xC0) /* 110xxxxx needs 2 bytes */
    {
	if (n < 2)
	    return (size_t)-2;

	*pc32 = ((s[0] & 31) << 6) | (s[1] & 63);
	return 2;
    }
    else if ((*s & 0xf0) == 0xE0) /* 1110xxxx needs 3 bytes */
    {
	if (n < 3)
	    return (size_t)-2;

	*pc32 = ((s[0] & 15) << 12) | ((s[1] & 63) << 6) | (s[2] & 63);
	return 3;
    }
    else if ((*s & 0xF8) == 0xF0) /* 11110xxx needs 4 bytes */
    {
	if (n < 4)
	    return (size_t)-2;

	*pc32 = ((s[0] & 7) << 18) | ((s[1] & 63) << 12) | ((s[2] & 63) << 6) | (s[4] & 63);
	return 4;
    }

    errno = EILSEQ;
    return (size_t)-1;
}

size_t c32rtomb (char *__restrict__ s,
		 char32_t c32,
		 mbstate_t *__restrict__ __UNUSED_PARAM(ps))
{
    if (c32 <= 0x7F) /* 7 bits needs 1 byte */
    {
	*s = (char)c32 & 0x7F;
	return 1;
    }
    else if (c32 <= 0x7FF) /* 11 bits needs 2 bytes */
    {
	s[1] = 0x80 | (char)(c32 & 0x3F);
	s[0] = 0xC0 | (char)(c32 >> 6);
	return 2;
    }
    else if (c32 <= 0xFFFF) /* 16 bits needs 3 bytes */
    {
	s[2] = 0x80 | (char)(c32 & 0x3F);
	s[1] = 0x80 | (char)((c32 >> 6) & 0x3F);
	s[0] = 0xE0 | (char)(c32 >> 12);
	return 3;
    }
    else if (c32 <= 0x1FFFFF) /* 21 bits needs 4 bytes */
    {
	s[3] = 0x80 | (char)(c32 & 0x3F);
	s[2] = 0x80 | (char)((c32 >> 6) & 0x3F);
	s[1] = 0x80 | (char)((c32 >> 12) & 0x3F);
	s[0] = 0xF0 | (char)(c32 >> 18);
	return 4;
    }

    errno = EILSEQ;
    return (size_t)-1;
}

