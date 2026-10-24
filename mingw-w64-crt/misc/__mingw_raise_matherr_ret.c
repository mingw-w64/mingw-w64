/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <math.h>

int (__cdecl *__mingw_usermatherr)(struct _exception *) __attribute__((common)); /* tentative */

int __cdecl __mingw_raise_matherr_ret (int typ, const char *name, double a1, double a2, double *rslt)
{
  struct _exception ex;
  if (!__mingw_usermatherr)
    return 0;
  ex.type = typ;
  ex.name = (char*)name;
  ex.arg1 = a1;
  ex.arg2 = a2;
  ex.retval = *rslt;
  int ret = (*__mingw_usermatherr)(&ex);
  *rslt = ex.retval;
  return ret;
}
