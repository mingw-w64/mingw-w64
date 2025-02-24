#define _CTYPE_DISABLE_MACROS
#include <ctype.h>

int __cdecl isblank (int _C)
{
  return (_isctype(_C, _BLANK) || _C == '\t');
}
int (__cdecl *__MINGW_IMP_SYMBOL(isblank))(int) = isblank;
