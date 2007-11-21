/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <math.h>
#include <errno.h>

long double ldexpl(long double x, int expn)
{
  long double res;
  if (!isfinite (x) || x == 0.0L)
    return x;

  __asm__ ("fscale"
  	    : "=t" (res)
	    : "0" (x), "u" ((long double) expn));

  if (!isfinite (res) || res == 0.0L)
    errno = ERANGE;

  return res;
}
