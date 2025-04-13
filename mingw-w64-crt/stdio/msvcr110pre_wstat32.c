/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sys/stat.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

wchar_t *__mingw_fix_wstat_path(const wchar_t *_path);

/* For pre-msvcr110 builds, we cannot use _wstat32() function as it does
 * not signal EOVERFLOW when file size does not fit into the st_size field,
 * as it is required by POSIX stat() function.
 * This file is used only for pre-msvcr110 builds.
 */
int __cdecl wstat32(const wchar_t *_Filename, struct _stat32 *_Stat);
int __cdecl wstat32(const wchar_t *_Filename, struct _stat32 *_Stat)
{
  struct _stat32i64 st;
  wchar_t *_path = __mingw_fix_wstat_path(_Filename);
  int ret = _wstat32i64(_path, &st);
  if (_path != _Filename)
    free(_path);
  if (ret != 0)
    return ret;
  if (st.st_size > UINT32_MAX) {
    errno = EOVERFLOW;
    return -1;
  }
  _Stat->st_dev=st.st_dev;
  _Stat->st_ino=st.st_ino;
  _Stat->st_mode=st.st_mode;
  _Stat->st_nlink=st.st_nlink;
  _Stat->st_uid=st.st_uid;
  _Stat->st_gid=st.st_gid;
  _Stat->st_rdev=st.st_rdev;
  _Stat->st_size=(_off_t) st.st_size;
  _Stat->st_atime=st.st_atime;
  _Stat->st_mtime=st.st_mtime;
  _Stat->st_ctime=st.st_ctime;
  return 0;
}
int (__cdecl *__MINGW_IMP_SYMBOL(wstat32))(const wchar_t *, struct _stat32 *) = wstat32;

/* On 32-bit systems is wstat() function ABI compatible with wstat32() function */
#ifndef _WIN64
#undef stat
#undef wstat
struct stat;
int __attribute__ ((alias ("wstat32"))) __cdecl wstat(const wchar_t *name, struct stat *stat);
extern int __attribute__ ((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(wstat32))))) (__cdecl *__MINGW_IMP_SYMBOL(wstat))(const wchar_t *name, struct stat *stat);
#endif
