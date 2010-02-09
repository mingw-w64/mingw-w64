/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <math.h>

long long llrint (double x) 
{
  long long retval = 0ll;
  __asm__ __volatile__							      \
    ("fistpll %0"  : "=m" (retval) : "t" (x) : "st");				      \
  return retval;
}

