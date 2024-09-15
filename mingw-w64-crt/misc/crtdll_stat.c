/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sys/stat.h>
#include "crtdll_stat.h"

/* Define _stat32() function via crtdll.dll _stat() function */
_CRTIMP int __cdecl __crtdll_stat(const char *name, struct __crtdll_stat *crtdll_stat);
int __cdecl _stat32(const char *name, struct _stat32 *stat)
{
  struct __crtdll_stat crtdll_stat;
  int ret = __crtdll_stat(name, &crtdll_stat);
  if (ret == 0)
    copy_stat_members(stat, &crtdll_stat);
  return ret;
}
int (__cdecl *__MINGW_IMP_SYMBOL(_stat32))(const char *name, struct _stat32 *stat) = _stat32;

#undef _stat
int __attribute__ ((alias ("_stat32"))) __cdecl _stat(const char *name, struct _stat32 *stat);
extern int __attribute__ ((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(_stat32))))) (__cdecl *__MINGW_IMP_SYMBOL(_stat))(const char *name, struct _stat32 *stat);

/*
 * Function stat() (without leading underline) is provided by mingw-w64
 * emulation due to trailing stash issue, so alias is not defined here.
 * Emulation calls _stat32() function, which resolve to the correct one.
 */
