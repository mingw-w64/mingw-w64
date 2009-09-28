#define __NO_CTYPE_LINES
#include <ctype.h>

int _cdecl isblank (int _C)
{
  return (_isctype(_C, _BLANK) || _C == '\t');
}
