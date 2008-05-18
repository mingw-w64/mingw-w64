/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <math.h>
#include <limits.h>
#include <errno.h>

long
lround (double x)
{
  double c, tmp;
  c = nextafter (0.5, -1.);
  /* Add +/- 0.5 then then round towards zero. */
  tmp = trunc (x + (x >= 0.0 ? c : -c));
  if (!isfinite (tmp)
      || tmp > (double)LONG_MAX
      || tmp < (double)LONG_MIN)
    {
	  errno = ERANGE;
	  /* Undefined behaviour, so we could return anything. */
	  /* return tmp > 0.0 ? LONG_LONG_MAX : LONG_LONG_MIN; */
	}
  return (long)tmp;
}
