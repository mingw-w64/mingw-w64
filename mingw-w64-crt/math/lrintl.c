/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <math.h>

long lrintl (long double x) 
{
  long retval = 0l;
  __asm__ __volatile__							      \
    ("fistpl %0"  : "=m" (retval) : "t" (x) : "st");				      \
  return retval;
}

