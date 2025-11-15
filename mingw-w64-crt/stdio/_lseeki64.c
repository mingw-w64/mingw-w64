/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <io.h>
#include <errno.h>
#include <limits.h>
#include <windows.h>

/* Define 64-bit _lseeki64() function via 32-bit CRT _lseek() function and 64-bit WinAPI SetFilePointer() function */
__int64 __cdecl _lseeki64(int fd, __int64 offset, int whence)
{
  const BOOL offset_overflowed = offset < LONG_MIN || offset > LONG_MAX;

  if (!offset_overflowed)
  {
    /* _lseek() takes only 32-bit offset value but can seek to file position
     * which does not fit into 32-bit integer via SEEK_CUR / SEEK_END.
     * Just the return value of new offset is truncated to 32 bits.
     * _lseek() does not signal truncation, so check here just for offset
     * overflow for SEEK_SET. For all other cases call SetFilePointer()
     * to retrieve new 64-bit file offset. */
    errno = 0;
    long ret = _lseek(fd, offset, whence);
    if (whence == SEEK_SET || (ret == -1 && errno))
      return ret;
  }

  HANDLE handle = (HANDLE)_get_osfhandle(fd);
  if (handle == INVALID_HANDLE_VALUE)
  {
    errno = EBADF;
    return -1;
  }

  /* If offset did not overflow then _lseek() was called and it already
   * set new file position, so just read that new file position.
   * If offset overflowed then _lseek() was not called at all,
   * so move in the file and set new position.
   * Note that FILE_* method and SEEK_* whence constants are same. */
  _Static_assert(FILE_BEGIN == SEEK_SET, "FILE_BEGIN == SEEK_SET");
  _Static_assert(FILE_CURRENT == SEEK_CUR, "FILE_CURRENT == SEEK_CUR");
  _Static_assert(FILE_END == SEEK_END, "FILE_END == SEEK_END");
  LARGE_INTEGER li = { .QuadPart = offset_overflowed ? offset : 0 };
  DWORD method = offset_overflowed ? whence : FILE_CURRENT;
  li.LowPart = SetFilePointer(handle, li.LowPart, &li.HighPart, method);
  if (li.LowPart == INVALID_SET_FILE_POINTER && GetLastError() != NO_ERROR)
  {
    errno = EINVAL;
    return -1;
  }

  /* At this stage, the file position was already changed by SetFilePointer().
   * For any file position change it is needed to clear EOF flag on fd, because
   * otherwise _read() would not work. The easiest way to clear EOF flag is to
   * call _lseek() function which at success path clears the EOF flag. If the
   * offset did not overflow then the _lseek() was already called. So when offset
   * overflowed call it with 0/SEEK_CUR which does nothing and clears EOF flag. */
  if (offset_overflowed)
  {
    (void)_lseek(fd, 0, SEEK_CUR);
  }

  return li.QuadPart;
}
__int64 (__cdecl *__MINGW_IMP_SYMBOL(_lseeki64))(int, __int64, int) = _lseeki64;

__int64 __attribute__ ((alias ("_lseeki64"))) __cdecl lseek64(int, __int64, int);
extern __int64 (__cdecl * __attribute__((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(_lseeki64))))) __MINGW_IMP_SYMBOL(lseek64))(int, __int64, int);
