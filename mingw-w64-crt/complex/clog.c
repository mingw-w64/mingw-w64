/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/*
   clog.c
   Contributed by Danny Smith
   2003-10-20
*/

/* clog (x + I * y) = log (hypot (x, y)) + I * atan2 (y, x) */

#include <math.h>
#include <complex.h>

double complex clog (double complex Z)
{
  double complex Res;
  __real__ Res = log (_hypot (__real__ Z,  __imag__ Z));
  __imag__ Res = carg (Z);
  return Res;
}

