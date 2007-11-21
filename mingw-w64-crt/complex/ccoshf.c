/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/*
   ccoshf.c
   Contributed by Danny Smith
   2004-12-24
*/

#include <math.h>
#include <complex.h>

/* ccosh (x + I * y) = cosh (x) * cos (y)
    + I * (sinh (x) * sin (y)) */ 

float complex ccoshf (float complex Z)
{
  float complex Res;
  __real__ Res = coshf (__real__ Z) * cosf (__imag__ Z);
  __imag__ Res = sinhf (__real__ Z) * sinf (__imag__ Z);
  return Res;
}
