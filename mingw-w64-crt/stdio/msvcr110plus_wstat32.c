/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sys/stat.h>
#include <stdlib.h>
#include "__mingw_fix_stat.h"

int __cdecl fstat32(int fd, struct _stat32 *stat);
int __cdecl wstat32(const wchar_t *_Filename, struct _stat32 *_Stat);
int __cdecl wstat32(const wchar_t *_Filename, struct _stat32 *_Stat)
{
  return __MINGW_FIXED_STAT(fstat32, _wstat32, _Filename, _Stat);
}
int (__cdecl *__MINGW_IMP_SYMBOL(wstat32))(const wchar_t *, struct _stat32 *) = wstat32;

/* On 32-bit systems wstat() is ABI-compatible with wstat32() */
#ifndef _WIN64
#undef stat
#undef wstat
struct stat;
int __attribute__ ((alias ("wstat32"))) __cdecl wstat(const wchar_t *name, struct stat *stat);
extern int __attribute__ ((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(wstat32))))) (__cdecl *__MINGW_IMP_SYMBOL(wstat))(const wchar_t *name, struct stat *stat);
#endif
