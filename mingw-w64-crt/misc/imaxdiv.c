/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
/*
    This source code was extracted from the Q8 package created and
    placed in the PUBLIC DOMAIN by Doug Gwyn <gwyn@arl.mil>
    last edit:	1999/11/05	gwyn@arl.mil


	last edit:	1999/11/05	gwyn@arl.mil

	Implements subclause 7.8.2 of ISO/IEC 9899:1999 (E).

*/

#include	<inttypes.h>
#include	<stdlib.h>

imaxdiv_t
__cdecl
imaxdiv(intmax_t numer, intmax_t denom)
{
  imaxdiv_t	result;
  result.quot = numer / denom;
  result.rem = numer % denom;
  return result;
}
imaxdiv_t (__cdecl *__MINGW_IMP_SYMBOL(imaxdiv))(intmax_t, intmax_t) = imaxdiv;

/*
 * avoid gcc 8+ warning:
 * 'lldiv' alias between functions of incompatible types 'lldiv_t(long long int,  long long int)' {aka 'struct <anonymous>(long long int,  long long int)'} and 'imaxdiv_t(intmax_t,  intmax_t)' {aka 'struct <anonymous>(long long int,  long long int)'}
 */
#if defined(__GNUC__) && __GNUC__ >= 8
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wattribute-alias"
#endif
lldiv_t __attribute__ ((alias ("imaxdiv")))
__cdecl
lldiv (long long, long long); 
extern lldiv_t __attribute__ ((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(imaxdiv)))))
(__cdecl *__MINGW_IMP_SYMBOL(lldiv))(long long, long long);
#if defined(__GNUC__) && __GNUC__ >= 8
#pragma GCC diagnostic pop
#endif
