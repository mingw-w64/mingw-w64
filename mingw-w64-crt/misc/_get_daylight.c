/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <time.h>
#include <errno.h>

errno_t __cdecl _get_daylight(int *value)
{
  if (!value)
  {
    errno = EINVAL;
    return EINVAL;
  }

  *value = _daylight;
  return 0;
}
errno_t (__cdecl *__MINGW_IMP_SYMBOL(_get_daylight))(int *) = _get_daylight;
