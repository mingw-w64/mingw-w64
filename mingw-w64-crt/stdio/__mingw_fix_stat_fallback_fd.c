/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sys/stat.h>
#include <string.h>
#include <wchar.h>
#include <errno.h>
#include <fcntl.h>
#include <windows.h>
#include "__mingw_fix_stat.h"

#ifdef MINGW_FIX_STAT_IS_WIDE
int __mingw_fix_wstat_fallback_fd(int ret, const wchar_t *filename, unsigned short mode)
#else
int __mingw_fix_stat_fallback_fd(int ret, const char *filename, unsigned short mode)
#endif
{
  int fd = -1;

  /*
   * CRT _stat does not handle paths with ? and * characters and returns ENOENT.
   * This prevents _stat from working on paths like \\?\C:\foo.txt.
   * CRT _stat incorrectly sets S_IFREG for pipe and char devices.
   * For these cases open specified filename and return its fd which will be passed to CRT fstat() by caller.
   */
  if ((ret < 0 && errno == ENOENT && __MINGW_STR_PBRK((filename), "?*")) || (ret == 0 && S_ISREG(mode))) {
    HANDLE handle = __MINGW_CREATE_FILE((filename), FILE_READ_ATTRIBUTES, FILE_SHARE_VALID_FLAGS, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
    if (handle != NULL && handle != INVALID_HANDLE_VALUE) {
      /* Open filename and return fd if CRT _stat failed or if the file is not regular disk file. */
      if (ret < 0 || GetFileType(handle) != FILE_TYPE_DISK) {
        int saved_errno = errno;
        fd = _open_osfhandle((intptr_t)handle, O_RDONLY);
        errno = saved_errno;
      }
      if (fd < 0)
        CloseHandle(handle);
    }
  }

  return fd;
}
