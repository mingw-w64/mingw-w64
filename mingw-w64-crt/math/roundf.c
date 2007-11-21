/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <math.h>

float
roundf (float x)
{
  /* Add +/- 0.5 then then round towards zero.  */
  return truncf ( x + (x >= 0.0F ?  0.5F : -0.5F));
}
