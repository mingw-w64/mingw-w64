/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <math.h>
#include <limits.h>
#include <errno.h>

long long
llroundl (long double x)
{
  long double c, tmp;
  c = nextafterl (0.5, -1.);
  /* Add +/- 0.5 then then round towards zero. */
  tmp = truncl (x + (x >= 0.0 ? c : -c));
  if (!isfinite (tmp)
	  || tmp > (long double)LONG_LONG_MAX
	  || tmp < (long double)LONG_LONG_MIN)
	{
	  errno = ERANGE;
	  /* Undefined behaviour, so we could return anything. */
	  /* return tmp > 0.0 ? LONG_LONG_MAX : LONG_LONG_MIN; */
	}
  return (long long)tmp;
}
