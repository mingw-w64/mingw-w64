/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sys/stat.h>
#include <stdlib.h>
#include "__mingw_fix_stat.h"

int __cdecl wstat32i64(const wchar_t *_Filename, struct _stat32i64 *_Stat);
int __cdecl wstat32i64(const wchar_t *_Filename, struct _stat32i64 *_Stat)
{
  return __MINGW_FIXED_STAT(_wstat32i64, _Filename, _Stat);
}
int (__cdecl *__MINGW_IMP_SYMBOL(wstat32i64))(const wchar_t *, struct _stat32i64 *) = wstat32i64;
