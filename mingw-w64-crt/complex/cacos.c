/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <math.h>
#include <complex.h>

/* cacos ( Z ) =  pi/2 - casin ( Z ) */

double complex cacos (double complex Z)
{
  double complex Res  = casin (Z);
  __real__ Res = M_PI_2 - __real__ Res;
  __imag__ Res = - __imag__ Res;
  return Res;
}
