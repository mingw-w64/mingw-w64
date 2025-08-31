/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <wchar.h>

wchar_t *__cdecl wcstok(wchar_t *restrict _Str, const wchar_t *restrict _Delim, wchar_t **restrict _Context)
{
  /* wcstok_s() differs from wcstok() just in:
   * - validation of _Context and _Delim arguments
   * - setting errno for invalid arguments
   * - calling exception handler for invalid arguments
   */
  if (!_Str && !*_Context)
    return NULL; /* do not set errno and do not call exception handler for invalid _Str / _Context */
  return wcstok_s(_Str, _Delim, _Context);
}
wchar_t *(__cdecl *__MINGW_IMP_SYMBOL(wcstok))(wchar_t *restrict, const wchar_t *restrict, wchar_t **restrict) = wcstok;
