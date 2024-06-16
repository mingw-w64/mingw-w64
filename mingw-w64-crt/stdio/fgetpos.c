/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdio.h>

/* Define 64-bit fgetpos() function via 32-bit fgetpos32() function */
_CRTIMP int __cdecl fgetpos32(FILE *__restrict__ _File, long *__restrict__ _Pos);
int __cdecl fgetpos(FILE *__restrict__ _File, fpos_t *__restrict__ _Pos)
{
  long pos32;
  int ret;

  ret = fgetpos32(_File, &pos32);
  *_Pos = pos32;
  return ret;
}
int (__cdecl *__MINGW_IMP_SYMBOL(fgetpos))(FILE *__restrict__ _File, fpos_t *__restrict__ _Pos) = fgetpos;

int __attribute__ ((alias ("fgetpos"))) __cdecl fgetpos64 (FILE *__restrict__ _File, fpos_t *__restrict__ _Pos);
extern int (__cdecl * __attribute__((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(fgetpos))))) __MINGW_IMP_SYMBOL(fgetpos64))(FILE *__restrict__ _File, fpos_t *__restrict__ _Pos);
