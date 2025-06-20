/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sys/stat.h>
#include <stdlib.h>
#include "__mingw_fix_stat.h"

int __cdecl wstat64i32(const wchar_t *_Filename, struct _stat64i32 *_Stat);
int __cdecl wstat64i32(const wchar_t *_Filename, struct _stat64i32 *_Stat)
{
  wchar_t *_path = __mingw_fix_wstat_path(_Filename);
  if (_path == NULL && _Filename != NULL)
    return -1;
  int ret = _wstat64i32(_path, _Stat);
  return __mingw_fix_stat_finish(ret, _Filename, _path, _Stat->st_mode);
}
int (__cdecl *__MINGW_IMP_SYMBOL(wstat64i32))(const wchar_t *, struct _stat64i32 *) = wstat64i32;

/* On 64-bit systems is wstat() function ABI compatible with wstat64i32() function */
#ifdef _WIN64
#undef stat
#undef wstat
struct stat;
int __attribute__ ((alias ("wstat64i32"))) __cdecl wstat(const wchar_t *name, struct stat *stat);
extern int __attribute__ ((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(wstat64i32))))) (__cdecl *__MINGW_IMP_SYMBOL(wstat))(const wchar_t *name, struct stat *stat);
#endif
