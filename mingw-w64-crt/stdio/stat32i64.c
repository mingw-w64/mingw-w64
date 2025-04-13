/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sys/stat.h>
#include <stdlib.h>

char *__mingw_fix_stat_path(const char *_path);

int __cdecl stat32i64(const char *_Filename, struct _stat32i64 *_Stat);
int __cdecl stat32i64(const char *_Filename, struct _stat32i64 *_Stat)
{
  char *_path = __mingw_fix_stat_path(_Filename);
  int ret = _stat32i64(_path, _Stat);
  if (_path != _Filename)
    free(_path);
  return ret;
}
int (__cdecl *__MINGW_IMP_SYMBOL(stat32i64))(const char *, struct _stat32i64 *) = stat32i64;
