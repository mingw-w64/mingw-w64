/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sys/stat.h>
#include <stdlib.h>
#include "__mingw_fix_stat.h"

int __cdecl fstat32(int fd, struct _stat32 *stat);
int __cdecl stat32(const char *_Filename, struct _stat32 *_Stat);
int __cdecl stat32(const char *_Filename, struct _stat32 *_Stat)
{
  return __MINGW_FIXED_STAT(fstat32, _stat32, _Filename, _Stat);
}
int (__cdecl *__MINGW_IMP_SYMBOL(stat32))(const char *, struct _stat32 *) = stat32;

/* On 32-bit systems stat() is ABI-compatible with stat32() */
#ifndef _WIN64
#undef stat
struct stat;
int __attribute__ ((alias ("stat32"))) __cdecl stat(const char *name, struct stat *stat);
extern int __attribute__ ((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(stat32))))) (__cdecl *__MINGW_IMP_SYMBOL(stat))(const char *name, struct stat *stat);
#endif
