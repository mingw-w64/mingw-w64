/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <io.h>

/* Define 64-bit fgetpos() function via 32-bit fgetpos32() function */
_CRTIMP int __cdecl fgetpos32(FILE *__restrict__ _File, long *__restrict__ _Pos);
int __cdecl fgetpos(FILE *__restrict__ _File, fpos_t *__restrict__ _Pos)
{
  __int64 raw_off64;
  long pos32;
  int ret;
  int fd;
  int old_errno;

  old_errno = errno;

  /* Function fgetpos32() on success returns 0 and sets pos32 to [30:0] bits of
   * 64-bit position offset. If the [31] bit of 64-bit position offset is set
   * then fgetpos32() returns -1, sets pos32 to -1 and do not change errno.
   * Non-zero value in [63:32] bits of 64-bit position offset does not trigger
   * any error condition. In other error cases fgetpos32() returns -1,
   * sets pos32 to -1 and errno to error value. */

  errno = 0;
  ret = fgetpos32(_File, &pos32);
  if (ret != 0 || pos32 < 0)
  {
    if (errno == 0) /* This detects overflow when [31] bit is set. */
      errno = EOVERFLOW;
    *_Pos = pos32;
    return ret;
  }

  /* Now try to detect overflow when [63:32] bits of offset are set.
   * Do it by comparing the raw fd-based 64-bit offset returned by
   * _lseeki64() that is not further than the half of the maximal
   * possible 31-bit position offset returned by fgetpos32().
   * Because FILE* stream use read/write buffers and translation modes,
   * the FILE* stream position and raw fd position can be different
   * and raw fd position be used directly for FILE* stream position.
   */
  fd = fileno(_File);
  if (fd >= 0)
  {
    raw_off64 = _lseeki64(fd, 0, SEEK_CUR);
    if (raw_off64 > LONG_MAX && raw_off64 - pos32 > LONG_MAX/2)
    {
      errno = EOVERFLOW;
      *_Pos = -1;
      return -1;
    }
  }

  errno = old_errno;

  *_Pos = pos32;
  return 0;
}
int (__cdecl *__MINGW_IMP_SYMBOL(fgetpos))(FILE *__restrict__ _File, fpos_t *__restrict__ _Pos) = fgetpos;

int __attribute__ ((alias ("fgetpos"))) __cdecl fgetpos64 (FILE *__restrict__ _File, fpos_t *__restrict__ _Pos);
extern int (__cdecl * __attribute__((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(fgetpos))))) __MINGW_IMP_SYMBOL(fgetpos64))(FILE *__restrict__ _File, fpos_t *__restrict__ _Pos);
