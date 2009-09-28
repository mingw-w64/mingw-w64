/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/*
   clogf.c
   Contributed by Danny Smith
   2004-12-24
*/

/* clog (x + I * y) = log (hypot (x, y)) + I * atan2 (y, x) */

#include <math.h>
#include <complex.h>

float complex clogf (float complex Z)
{
  float complex Res;
  __real__ Res = logf (_hypot (__real__ Z,  __imag__ Z));
  __imag__ Res = cargf (Z);
  return Res;
}

