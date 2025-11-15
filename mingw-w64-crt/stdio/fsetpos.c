/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <io.h>

/* Define 64-bit fsetpos() function via 32-bit fsetpos32() and 64-bit _lseeki64() functions */
_CRTIMP int __cdecl fsetpos32(FILE *__restrict__ _File, long *__restrict__ _Pos);
int __cdecl fsetpos(FILE *__restrict__ _File, const fpos_t *__restrict__ _Pos)
{
  if (*_Pos < LONG_MIN)
  {
    errno = EINVAL;
    return -1;
  }
  else if (*_Pos > LONG_MAX)
  {
    /* fflush() and fsetpos32() clear read and write buffers, so the followup
     * _lseeki64() call correctly change offset of the FILE* stream too. */
    if (fflush(_File) != 0)
      return -1;
    if (fsetpos32(_File, &(long){LONG_MAX}) != 0)
      return -1;
    if (_lseeki64(fileno(_File), *_Pos, SEEK_SET) == -1)
      return -1;
    return 0;
  }
  else
  {
    return fsetpos32(_File, &(long){*_Pos});
  }
}
int (__cdecl *__MINGW_IMP_SYMBOL(fsetpos))(FILE *__restrict__ _File, const fpos_t *__restrict__ _Pos) = fsetpos;

int __attribute__ ((alias ("fsetpos"))) __cdecl fsetpos64 (FILE *__restrict__ _File, const fpos_t *__restrict__ _Pos);
extern int (__cdecl * __attribute__((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(fsetpos))))) __MINGW_IMP_SYMBOL(fsetpos64))(FILE *__restrict__ _File, const fpos_t *__restrict__ _Pos);
