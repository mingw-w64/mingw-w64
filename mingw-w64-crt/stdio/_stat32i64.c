/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sys/stat.h>
#include <stdint.h>
#include <errno.h>

/* When the file time does not fit into the st_Xtime field:
 *           crtdll-msvcr71   msvcr80+
 * st_Xtime       -1             -1
 * errno       no change       EINVAL
 * returns         0              0
 *
 * This file is used for 32-bit pre-msvcrt40 builds and 64-bit msvcrt.dll builds.
 * So for 32-bit use the pre-msvcrt40 behavior - fills -1 without errno change.
 * And for 64-bit use the msvcr80+ behavior - fills -1 with setting errno to EINVAL.
 */
int __cdecl _stat32i64(const char *_Name,struct _stat32i64 *_Stat)
{
  struct _stat64 st;
  int ret=_stat64(_Name,&st);
  if (ret != 0)
    return ret;
  _Stat->st_dev=st.st_dev;
  _Stat->st_ino=st.st_ino;
  _Stat->st_mode=st.st_mode;
  _Stat->st_nlink=st.st_nlink;
  _Stat->st_uid=st.st_uid;
  _Stat->st_gid=st.st_gid;
  _Stat->st_rdev=st.st_rdev;
  _Stat->st_size=st.st_size;
  _Stat->st_atime=((st.st_atime < 0 || st.st_atime > INT32_MAX) ? -1 : st.st_atime);
  _Stat->st_mtime=((st.st_mtime < 0 || st.st_mtime > INT32_MAX) ? -1 : st.st_mtime);
  _Stat->st_ctime=((st.st_ctime < 0 || st.st_ctime > INT32_MAX) ? -1 : st.st_ctime);
#ifdef _WIN64
  if (_Stat->st_atime == -1 || _Stat->st_mtime == -1 || _Stat->st_ctime == -1)
    errno = EINVAL;
#endif
  return 0;
}
int (__cdecl *__MINGW_IMP_SYMBOL(_stat32i64))(const char *, struct _stat32i64 *) = _stat32i64;

#ifndef _WIN64
#undef _stati64
int __attribute__ ((alias ("_stat32i64"))) __cdecl _stati64(const char *, struct _stat32i64 *);
extern int __attribute__ ((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(_stat32i64))))) (__cdecl *__MINGW_IMP_SYMBOL(_stati64))(const char *, struct _stat32i64 *);
#endif
