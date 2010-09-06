#define __CRT__NO_INLINE
#include <string.h>

size_t __cdecl strnlen (const char *_Str, size_t _MaxCount)
{
  size_t siz = strlen (_Str);
  return (siz <= _MaxCount) ? siz : _MaxCount;
}

