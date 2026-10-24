/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <math.h>

void __cdecl __mingw_raise_matherr (int typ, const char *name, double a1, double a2, double rslt)
{
  (void)__mingw_raise_matherr_ret (typ, name, a1, a2, &rslt);
}
