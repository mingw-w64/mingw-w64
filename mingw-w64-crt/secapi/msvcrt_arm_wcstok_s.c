/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <errno.h>
#include <wchar.h>

_CRTIMP wchar_t *__cdecl __msvcrt_wcstok_s(wchar_t *_Str, const wchar_t *_Delim, wchar_t **_Context);

wchar_t *__cdecl wcstok_s(wchar_t *_Str, const wchar_t *_Delim, wchar_t **_Context)
{
  /* msvcrt.dll's wcstok_s() does not call mingw-w64's _invalid_parameter()
   * replacement which fixes the broken msvcrt.dll's _invalid_parameter().
   * So call mingw-w64's _invalid_parameter() manually on EINVAL.
   */
  wchar_t *ret;
  int old_errno = errno;
  errno = 0;
  ret = __msvcrt_wcstok_s(_Str, _Delim, _Context);
  if (errno == EINVAL) {
    _invalid_parameter_noinfo();
    return NULL;
  }
  errno = old_errno;
  return ret;
}
wchar_t *(__cdecl *__MINGW_IMP_SYMBOL(wcstok_s))(wchar_t *, const wchar_t *, wchar_t **) = wcstok_s;
