#define _CTYPE_DISABLE_MACROS
#include <wctype.h>

int __cdecl iswblank (wint_t _C)
{
  /**
   * mingw-w64's `iswctype` is a wrapper around CRT's `iswctype` which
   * properly handles TAB character.
   */
  return iswctype (_C, _BLANK);
}
int (__cdecl *__MINGW_IMP_SYMBOL(iswblank))(wint_t) = iswblank;
