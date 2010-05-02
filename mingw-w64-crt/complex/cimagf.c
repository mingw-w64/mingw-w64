/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <complex.h>
float __attribute__ ((const)) cimagf (float complex _Z)
{
  return __imag__ _Z;
}

