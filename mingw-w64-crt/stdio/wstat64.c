/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sys/stat.h>
#include <stdlib.h>

wchar_t *__mingw_fix_wstat_path(const wchar_t *_path);

int __cdecl wstat64(const wchar_t *_Filename, struct _stat64 *_Stat);
int __cdecl wstat64(const wchar_t *_Filename, struct _stat64 *_Stat)
{
  wchar_t *_path = __mingw_fix_wstat_path(_Filename);
  int ret = _wstat64(_path, _Stat);
  if (_path != _Filename)
    free(_path);
  return ret;
}
int (__cdecl *__MINGW_IMP_SYMBOL(wstat64))(const wchar_t *, struct _stat64 *) = wstat64;
