/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <stdlib.h>
#include <errno.h>

errno_t __cdecl _get_wpgmptr(wchar_t **value)
{
  if (!value)
  {
    errno = EINVAL;
    return EINVAL;
  }

  *value = _wpgmptr;
  return 0;
}
errno_t (__cdecl *__MINGW_IMP_SYMBOL(_get_wpgmptr))(wchar_t **) = _get_wpgmptr;
