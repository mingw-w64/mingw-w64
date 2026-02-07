#define _CTYPE_DISABLE_MACROS
#include <ctype.h>

/**
 * Calls to `_isctype ('\t', _BLANK)` return inconsistent results
 * depending on CRT and active locale.
 *
 * In all CRTs it returns zero in "C" locale and non-zero otherwise.
 */

int __cdecl isblank (int _C)
{
  return (_isctype(_C, _BLANK) || _C == '\t');
}
int (__cdecl *__MINGW_IMP_SYMBOL(isblank))(int) = isblank;
