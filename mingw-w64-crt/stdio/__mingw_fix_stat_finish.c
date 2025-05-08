/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include "__mingw_fix_stat.h"

int __mingw_fix_stat_finish(int ret, const void *orig_path, void *used_path,
                            unsigned short mode)
{
  /*
   * If the original pathname and used pathname differ, it means that
   * __mingw_fix_stat_path or __mingw_fix_wstat_path had to allocate
   * a temporary buffer and remove a trailing directory separator.
   * In this case the temporary allocation has to be freed, and the
   * stat function succeeds only if the pathname was a directory.
   */
  if (orig_path != used_path) {
    /* Save errno because we call free. */
    int saved_errno = errno;
    free(used_path);

    if (ret == 0 && !S_ISDIR(mode)) {
      ret = -1;
      saved_errno = ENOTDIR;
    }

    errno = saved_errno;
  }

  return ret;
}
