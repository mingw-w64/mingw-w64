/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sys/stat.h>
#include <stdint.h>
#include <errno.h>

#ifndef _WIN64
#include <fcntl.h>
#include <windows.h>
int __cdecl fstat32(int fd, struct _stat32 *stat);
#endif

/* When the file time does not fit into the st_Xtime field:
 *           crtdll-msvcr71   msvcr80+
 * st_Xtime       -1             -1
 * errno       no change       EINVAL
 * returns         0              0
 *
 * When the file size does not fit into the st_size field:
 *           crtdll-msvcr90   msvcr100   msvcr110+
 * st_size      truncate         0           0
 * errno       no change     no change   EOVERFLOW
 * returns         0            -1          -1
 *
 * The stat function on 32-bit system os msvcrt.dll behaves
 * like the msvcr80/msvcr90, so use this behavior.
 */
int __cdecl _wstat32(const wchar_t *_Name,struct _stat32 *_Stat)
{
#ifdef _WIN64
  struct _stat64 st;
  int ret=_wstat64(_Name,&st);
  if (ret != 0)
    return ret;
  _Stat->st_dev=st.st_dev;
  _Stat->st_ino=st.st_ino;
  _Stat->st_mode=st.st_mode;
  _Stat->st_nlink=st.st_nlink;
  _Stat->st_uid=st.st_uid;
  _Stat->st_gid=st.st_gid;
  _Stat->st_rdev=st.st_rdev;
  _Stat->st_size=(_off_t) st.st_size; /* truncate 64-bit st_size to 32-bit */
  _Stat->st_atime=((st.st_atime < 0 || st.st_atime > INT32_MAX) ? -1 : st.st_atime);
  _Stat->st_mtime=((st.st_mtime < 0 || st.st_mtime > INT32_MAX) ? -1 : st.st_mtime);
  _Stat->st_ctime=((st.st_ctime < 0 || st.st_ctime > INT32_MAX) ? -1 : st.st_ctime);
  if (_Stat->st_atime == -1 || _Stat->st_mtime == -1 || _Stat->st_ctime == -1)
    errno = EINVAL;
  return 0;
#else
  /* mingw-w64 _wstat64() on 32-bit systems is implemented as wrapper around the _wstat32().
   * Therefore mingw-w64 _wstat32() implementation cannot call _wstat64().
   * This _wstat32() implementation uses mingw-w64 fstat32() with handle obtained from CreateFileW().
   * mingw-w64 fstat32() is a wrapper around the CRT _fstat32() and which fixes the S_IFMT to
   * S_IFDIR for directories. The CRT _fstat32() returns S_IFREG for directories.
   * _fstat32() requires only FILE_READ_ATTRIBUTES access and FILE_FLAG_BACKUP_SEMANTICS is
   * required for opening directory via CreateFileW().
   * Using just FILE_READ_ATTRIBUTES access allows to open also path which is was denied for
   * reading by another process. msvcrt.dll _wstat32() also allows to be called on such path.
   */
  int fd;
  int ret;
  int err;
  HANDLE handle;
  handle = CreateFileW(_Name, FILE_READ_ATTRIBUTES, FILE_SHARE_VALID_FLAGS, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
  if (handle == INVALID_HANDLE_VALUE) {
    switch (GetLastError()) {
    case ERROR_PATH_NOT_FOUND:
    case ERROR_FILE_NOT_FOUND:
      errno = ENOENT;
      break;
    case ERROR_ACCESS_DENIED:
    case ERROR_WRITE_PROTECT...ERROR_SHARING_BUFFER_EXCEEDED: /* gcc extension for case ranges: https://gcc.gnu.org/onlinedocs/gcc-3.0.4/gcc/Case-Ranges.html */
      errno = EACCES;
      break;
    case ERROR_NOT_ENOUGH_MEMORY:
      errno = ENOMEM;
      break;
    default:
      errno = EINVAL;
      break;
    }
    return -1;
  }
  fd = _open_osfhandle((intptr_t)handle, O_RDONLY);
  if (fd < 0) {
    CloseHandle(handle);
    return -1;
  }
  ret = fstat32(fd, _Stat);
  err = errno;
  close(fd);
  errno = err;
  return ret;
#endif
}
int (__cdecl *__MINGW_IMP_SYMBOL(_wstat32))(const wchar_t *, struct _stat32 *) = _wstat32;

/* On 32-bit systems is _wstat ABI using 32-bit time_t and 32-bit off_t */
#ifndef _WIN64
#undef _wstat
int __attribute__((alias("_wstat32"))) __cdecl _wstat(const wchar_t *_Name,struct _stat32 *_Stat);
extern int __attribute__((alias(__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(_wstat32))))) (__cdecl *__MINGW_IMP_SYMBOL(_wstat))(const wchar_t *, struct _stat32 *);
#endif
