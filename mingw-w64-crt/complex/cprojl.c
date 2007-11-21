/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/*
   cprojl.c
   Contributed by Danny Smith
   2005-01-04
*/

#include <math.h>
#include <complex.h>

/* Return the value of the projection onto the Riemann sphere.*/

long double complex cprojl (long double complex Z)
{
  complex long double Res = Z;
  if (isinf (__real__ Z) || isinf (__imag__ Z))
    {
      __real__ Res = HUGE_VALL;
      __imag__ Res = copysignl (0.0L, __imag__ Z);
    }
  return Res;
}

