/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/*
   ccosf.c
   Contributed by Danny Smith
   2003-12-24
*/

#include <math.h>
#include <complex.h>

/* ccos (x + I * y) = cos (x) * cosh (y)
    + I * (sin (x) * sinh (y)) */ 


float complex ccosf (float complex Z)
{
  float complex Res;
  __real__ Res = cosf (__real__ Z) * coshf ( __imag__ Z);
  __imag__ Res = -sinf (__real__ Z) * sinhf ( __imag__ Z);
  return Res;
}
