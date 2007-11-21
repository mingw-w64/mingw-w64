#include <string.h>
#undef wcscmpi

int
wcscmpi (const wchar_t * ws1,const wchar_t * ws2)
{
  return _wcsicmp (ws1,ws2);
}
