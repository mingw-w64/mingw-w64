/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sys/stat.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include "__mingw_fix_stat.h"

/* For pre-msvcr110 builds, we cannot use _fstat64i32() as it does
 * not signal EOVERFLOW when file size does not fit into the st_size field,
 * as it is required by POSIX fstat().
 * This file is used only for pre-msvcr110 builds.
 */
int __cdecl fstat64i32(int fd, struct _stat64i32 *stat);
int __cdecl fstat64i32(int fd, struct _stat64i32 *stat)
{
  struct _stat64 st;
  int ret = __MINGW_FIXED_FSTAT(_fstat64, fd, &st);
  if (ret != 0)
    return ret;
  if (st.st_size > INT32_MAX) {
    errno = EOVERFLOW;
    return -1;
  }
  stat->st_dev=st.st_dev;
  stat->st_ino=st.st_ino;
  stat->st_mode=st.st_mode;
  stat->st_nlink=st.st_nlink;
  stat->st_uid=st.st_uid;
  stat->st_gid=st.st_gid;
  stat->st_rdev=st.st_rdev;
  stat->st_size=(_off_t) st.st_size;
  stat->st_atime=st.st_atime;
  stat->st_mtime=st.st_mtime;
  stat->st_ctime=st.st_ctime;
  return 0;
}
int (__cdecl *__MINGW_IMP_SYMBOL(fstat64i32))(int, struct _stat64i32 *) = fstat64i32;

/* On 64-bit systems stat() is ABI-compatible with stat64i32() */
#ifdef _WIN64
#undef stat
struct stat;
int __attribute__ ((alias ("fstat64i32"))) __cdecl fstat(int fd, struct stat *stat);
extern int __attribute__ ((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(fstat64i32))))) (__cdecl *__MINGW_IMP_SYMBOL(fstat))(int fd, struct stat *stat);
#endif
