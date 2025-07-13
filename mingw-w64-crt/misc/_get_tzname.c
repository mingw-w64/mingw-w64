/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <time.h>
#include <errno.h>
#include <string.h>

errno_t __cdecl _get_tzname(size_t *length, char *buffer, size_t size, int index)
{
  const char *tzname_ptr;

  if ((!buffer && size != 0) || (buffer && size == 0))
  {
    errno = EINVAL;
    return EINVAL;
  }

  if (buffer)
    buffer[0] = '\0';

  if (!length || (index != 0 && index != 1))
  {
    errno = EINVAL;
    return EINVAL;
  }

  tzname_ptr = _tzname[index];

  *length = strlen(tzname_ptr) + 1;

  if (buffer)
  {
    if (*length > size)
      return ERANGE;
    memcpy(buffer, tzname_ptr, *length);
  }

  return 0;
}
errno_t (__cdecl *__MINGW_IMP_SYMBOL(_get_tzname))(size_t *, char *, size_t, int) = _get_tzname;
