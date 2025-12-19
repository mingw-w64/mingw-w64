/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sys/stat.h>
#include <windows.h>
#include "__mingw_fix_stat.h"

int __mingw_fix_fstat_finish(int ret, int fd, unsigned short *mode)
{
  /* msvcrt's _fstat fills S_IFREG for directories. Fix it to S_IFDIR. */
  BY_HANDLE_FILE_INFORMATION fi;
  if (ret == 0 && S_ISREG(*mode) && GetFileInformationByHandle((HANDLE)_get_osfhandle(fd), &fi) && (fi.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
    *mode = (*mode & ~S_IFMT) | S_IFDIR;
  return ret;
}
