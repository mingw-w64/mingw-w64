/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <math.h>
#include <limits.h>
#include <errno.h>

long long
llroundf (float x)
{
  float c, tmp;
  c = nextafterf (0.5F, -1.0F);
  /* Add +/- 0.5 then then round towards zero. */
  tmp = truncf (x + (x >= 0.0F ? c : -c));
  if (!isfinite (tmp)
	  || tmp > (float)LONG_LONG_MAX
	  || tmp < (float)LONG_LONG_MIN)
	{
	  errno = ERANGE;
	  /* Undefined behaviour, so we could return anything. */
	  /* return tmp > 0.0 ? LONG_LONG_MAX : LONG_LONG_MIN; */
	}
  return (long long)tmp;
}  
