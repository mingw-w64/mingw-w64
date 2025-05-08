/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sys/stat.h>
#include <stdlib.h>
#include "__mingw_fix_stat.h"

int __cdecl stat64(const char *_Filename, struct stat64 *_Stat)
{
  char *_path = __mingw_fix_stat_path(_Filename);
  if (_path == NULL && _Filename != NULL)
    return -1;
  int ret = _stat64(_path, (struct _stat64 *)_Stat);
  if (_path != _Filename)
    free(_path);
  return ret;
}
int (__cdecl *__MINGW_IMP_SYMBOL(stat64))(const char *, struct stat64 *) = stat64;
