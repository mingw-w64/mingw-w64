/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sys/stat.h>
#include <stdlib.h>
#include "__mingw_fix_stat.h"

int __cdecl stat64i32(const char *_Filename, struct _stat64i32 *_Stat);
int __cdecl stat64i32(const char *_Filename, struct _stat64i32 *_Stat)
{
  char *_path = __mingw_fix_stat_path(_Filename);
  if (_path == NULL && _Filename != NULL)
    return -1;
  int ret = _stat64i32(_path, _Stat);
  return __mingw_fix_stat_finish(ret, _Filename, _path, _Stat->st_mode);
}
int (__cdecl *__MINGW_IMP_SYMBOL(stat64i32))(const char *, struct _stat64i32 *) = stat64i32;

/* On 64-bit systems is stat() function ABI compatible with stat64i32() function */
#ifdef _WIN64
#undef stat
struct stat;
int __attribute__ ((alias ("stat64i32"))) __cdecl stat(const char *name, struct stat *stat);
extern int __attribute__ ((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(stat64i32))))) (__cdecl *__MINGW_IMP_SYMBOL(stat))(const char *name, struct stat *stat);
#endif
