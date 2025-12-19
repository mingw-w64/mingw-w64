/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sys/stat.h>
#include <stdlib.h>
#include "__mingw_fix_stat.h"

int __cdecl fstat32(int fd, struct _stat32 *stat);
int __cdecl fstat32(int fd, struct _stat32 *stat)
{
  return __MINGW_FIXED_FSTAT(_fstat32, fd, stat);
}
int (__cdecl *__MINGW_IMP_SYMBOL(fstat32))(int, struct _stat32 *) = fstat32;

/* On 32-bit systems fstat() is ABI-compatible with fstat32() */
#ifndef _WIN64
#undef stat
struct stat;
int __attribute__ ((alias ("fstat32"))) __cdecl fstat(int fd, struct stat *stat);
extern int __attribute__ ((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(fstat32))))) (__cdecl *__MINGW_IMP_SYMBOL(fstat))(int fd, struct stat *stat);
#endif
