/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <math.h>
int
__isnanf (float _x)
{
  unsigned short _sw;
  __asm__ __volatile__ ("fxam;"
	   "fstsw %%ax": "=a" (_sw) : "t" (_x) );
  return (_sw & (FP_NAN | FP_NORMAL | FP_INFINITE | FP_ZERO | FP_SUBNORMAL))
    == FP_NAN;
}

int __attribute__ ((alias ("__isnanf"))) isnanf (float);
