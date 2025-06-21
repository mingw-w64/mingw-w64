/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <io.h>
#include <errno.h>
#include <limits.h>

/* Define 64-bit _lseeki64() function via 32-bit _lseek() function */
__int64 __cdecl _lseeki64(int fd, __int64 offset, int whence)
{
  if (offset < LONG_MIN || offset > LONG_MAX)
  {
    errno = EOVERFLOW;
    return -1;
  }

  return _lseek(fd, offset, whence);
}
__int64 (__cdecl *__MINGW_IMP_SYMBOL(_lseeki64))(int, __int64, int) = _lseeki64;

__int64 __attribute__ ((alias ("_lseeki64"))) __cdecl lseek64(int, __int64, int);
extern __int64 (__cdecl * __attribute__((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(_lseeki64))))) __MINGW_IMP_SYMBOL(lseek64))(int, __int64, int);
