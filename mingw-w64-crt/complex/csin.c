/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
/*
   Contributed by Danny Smith
   2003-10-20
*/

#include <math.h>
#include <complex.h>

/* csin (x + I * y) = sin (x) * cosh (y)
    + I * (cos (x) * sinh (y)) */ 

double complex csin (double complex Z)
{
  double complex Res;
  __real__ Res = sin (__real__ Z) * cosh ( __imag__ Z);
  __imag__ Res = cos (__real__ Z) * sinh ( __imag__ Z);
  return Res;
}

