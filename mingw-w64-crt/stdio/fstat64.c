/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sys/stat.h>
#include <stdlib.h>
#include "__mingw_fix_stat.h"

int __cdecl fstat64(int fd, struct stat64 *stat)
{
  return __MINGW_FIXED_FSTAT(_fstat64, fd, (struct _stat64 *)stat);
}
int (__cdecl *__MINGW_IMP_SYMBOL(fstat64))(int, struct stat64 *) = fstat64;
