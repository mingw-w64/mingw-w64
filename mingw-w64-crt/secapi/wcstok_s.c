/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <errno.h>
#include <wchar.h>

wchar_t *__cdecl wcstok_s(wchar_t *_Str, const wchar_t *_Delim, wchar_t **_Context)
{
  /* wcstok_s() differs from wcstok() just in:
   * - validation of _Context and _Delim arguments
   * - setting errno for invalid arguments
   * - calling exception handler for invalid arguments
   */
  if (!_Context || !_Delim || (!_Str && !*_Context)) {
    errno = EINVAL;
    _invalid_parameter_noinfo();
    return NULL;
  }
  return wcstok(_Str, _Delim, _Context);
}
wchar_t *(__cdecl *__MINGW_IMP_SYMBOL(wcstok_s))(wchar_t *, const wchar_t *, wchar_t **) = wcstok_s;
