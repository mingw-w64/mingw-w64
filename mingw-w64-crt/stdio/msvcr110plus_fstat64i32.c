/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sys/stat.h>
#include <stdlib.h>
#include "__mingw_fix_stat.h"

int __cdecl fstat64i32(int fd, struct _stat64i32 *stat);
int __cdecl fstat64i32(int fd, struct _stat64i32 *stat)
{
  return __MINGW_FIXED_FSTAT(_fstat64i32, fd, stat);
}
int (__cdecl *__MINGW_IMP_SYMBOL(fstat64i32))(int fd, struct _stat64i32 *) = fstat64i32;

/* On 64-bit systems fstat() is ABI-compatible with fstat64i32() */
#ifdef _WIN64
#undef stat
struct stat;
int __attribute__ ((alias ("fstat64i32"))) __cdecl fstat(int fd, struct stat *stat);
extern int __attribute__ ((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(fstat64i32))))) (__cdecl *__MINGW_IMP_SYMBOL(fstat))(int fd, struct stat *stat);
#endif
