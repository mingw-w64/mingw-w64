/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sys/stat.h>
#include "crtdll_stat.h"

/* Define _fstat32() function via crtdll.dll _fstat() function */
_CRTIMP int __cdecl __crtdll_fstat(int fd, struct __crtdll_stat *crtdll_stat);
int __cdecl _fstat32(int fd, struct _stat32 *stat)
{
  struct __crtdll_stat crtdll_stat;
  int ret = __crtdll_fstat(fd, &crtdll_stat);
  if (ret == 0)
    copy_stat_members(stat, &crtdll_stat);
  return ret;
}
int (__cdecl *__MINGW_IMP_SYMBOL(_fstat32))(int fd, struct _stat32 *stat) = _fstat32;

#undef _fstat
int __attribute__ ((alias ("_fstat32"))) __cdecl _fstat(int fd, struct _stat32 *stat);
extern int __attribute__ ((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(_fstat32))))) (__cdecl *__MINGW_IMP_SYMBOL(_fstat))(int fd, struct _stat32 *stat);

#undef fstat
struct stat;
int __attribute__ ((alias ("_fstat32"))) __cdecl fstat(int fd, struct stat *stat);
extern int __attribute__ ((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(_fstat32))))) (__cdecl *__MINGW_IMP_SYMBOL(fstat))(int fd, struct stat *stat);
