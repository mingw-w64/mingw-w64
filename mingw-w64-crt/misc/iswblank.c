#define _WCTYPE_INLINE_DEFINED
#include <wctype.h>

int __cdecl iswblank (wint_t _C)
{
  return (iswctype(_C, _BLANK) || _C == '\t');
}
int (__cdecl *__MINGW_IMP_SYMBOL(iswblank))(wint_t) = iswblank;
