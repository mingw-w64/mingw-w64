/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdio.h>
#include <errno.h>
#include <limits.h>

/* Define 64-bit fsetpos() function via 32-bit fsetpos32() function */
_CRTIMP int __cdecl fsetpos32(FILE *__restrict__ _File, long *__restrict__ _Pos);
int __cdecl fsetpos(FILE *__restrict__ _File, const fpos_t *__restrict__ _Pos)
{
  long pos32;

  if (*_Pos > LONG_MAX)
  {
    errno = EOVERFLOW;
    return -1;
  }

  pos32 = *_Pos;
  return fsetpos32(_File, &pos32);
}
int (__cdecl *__MINGW_IMP_SYMBOL(fsetpos))(FILE *__restrict__ _File, const fpos_t *__restrict__ _Pos) = fsetpos;

int __attribute__ ((alias ("fsetpos"))) __cdecl fsetpos64 (FILE *__restrict__ _File, const fpos_t *__restrict__ _Pos);
extern int (__cdecl * __attribute__((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(fsetpos))))) __MINGW_IMP_SYMBOL(fsetpos64))(FILE *__restrict__ _File, const fpos_t *__restrict__ _Pos);
