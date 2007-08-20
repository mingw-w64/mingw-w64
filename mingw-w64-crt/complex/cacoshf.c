/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/*
   cacoshf.c
   Contributed by Danny Smith
   2004-12-24
*/

#include <math.h>
#include <complex.h>

#if 0
/* cacoshf (z) = I * cacos (z)  */
float complex cacosh (float complex Z)
{
  float complex Tmp;
  float complex Res;

  Tmp = cacosf (Z);
  __real__ Res = -__imag__ Tmp;
  __imag__ Res = __real__ Tmp;
  return Res;
}

#else

/* cacosh (z) = I * cacos (z) = I * (pi/2 - casin (z))  */

float complex cacoshf (float complex Z)
{
  float complex Tmp;
  float complex Res;

  Tmp = casinf (Z);
  __real__ Res = __imag__ Tmp;
  __imag__ Res =  M_PI_2 - __real__ Tmp;
  return Res;
}
#endif
