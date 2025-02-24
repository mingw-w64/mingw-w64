#define _CRT_WCTYPE_NOINLINE
#include <ctype.h>

int __cdecl _iswblank_l(wint_t _C, _locale_t _Locale)
{
  return (_iswctype_l(_C, _BLANK, _Locale) || _C == '\t');
}
int (__cdecl *__MINGW_IMP_SYMBOL(_iswblank_l))(wint_t, _locale_t) = _iswblank_l;
