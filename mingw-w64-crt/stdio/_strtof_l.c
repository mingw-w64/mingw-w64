/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <stdlib.h>
#include <float.h>
#include <errno.h>
#include <math.h>
#include <locale.h>

float _strtof_l( const char *nptr, char **endptr, _locale_t _Locale)
{
  const double ret = _strtod_l(nptr, endptr, _Locale);
  if (isfinite(ret)) {
    /* Check for cases that aren't out of range for doubles, but that are
     * for floats. */
    if (ret > FLT_MAX)
      errno = ERANGE;
    else if (ret < -FLT_MAX)
      errno = ERANGE;
    else if (ret > 0 && ret < FLT_MIN)
      errno = ERANGE;
    else if (ret < 0 && ret > -FLT_MIN)
      errno = ERANGE;
  }
  return ret;
}
