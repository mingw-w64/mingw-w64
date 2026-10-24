/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <math.h>

int (__cdecl *__mingw_usermatherr)(struct _exception *) = NULL;

#undef __setusermatherr

void __cdecl __mingw_setusermatherr (int (__cdecl *f)(struct _exception *))
{
  __mingw_usermatherr = f;
  __setusermatherr (f);
}
