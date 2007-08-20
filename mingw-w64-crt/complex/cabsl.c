/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <math.h>
#include <complex.h>

long double cabsl (long double complex Z)
{
  return  hypotl ( __real__ Z,  __imag__ Z);
}
