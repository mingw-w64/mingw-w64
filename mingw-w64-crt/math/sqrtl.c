/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <math.h>
#include <errno.h>

extern long double  __QNANL;

long double
sqrtl (long double x)
{
  if (x < 0.0L )
    {
      errno = EDOM;
      return __QNANL;
    }
  else
    {
      long double res;
      asm ("fsqrt" : "=t" (res) : "0" (x));
      return res;
    }
}
