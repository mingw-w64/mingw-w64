/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <math.h>

double
round (double x)
{
  /* Add +/- 0.5 then then round towards zero.  */
  return trunc ( x + (x >= 0.0 ?  0.5 : -0.5));
}
