#define _CTYPE_DISABLE_MACROS
#include <ctype.h>

int __cdecl _isblank_l(int _C, _locale_t _Locale)
{
  return (_isctype_l(_C, _BLANK, _Locale) || _C == '\t');
}
int (__cdecl *__MINGW_IMP_SYMBOL(_isblank_l))(int, _locale_t) = _isblank_l;
