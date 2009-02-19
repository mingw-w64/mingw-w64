/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
extern double __cdecl ldexp(double _X,int _Y);
float ldexpf (float x, int expn)
  {return (float) ldexp (x, expn);}
