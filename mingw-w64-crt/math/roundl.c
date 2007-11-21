/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <math.h>

long double
roundl (long double x)
{
  /* Add +/- 0.5 then then round towards zero.  */
  return truncl ( x + (x >= 0.0L ?  0.5L : -0.5L));
}
