#define __NO_INLINE__
#include <time.h>

extern struct tm * (__cdecl *__MINGW_IMP_SYMBOL(localtime))(const __time32_t *);

struct tm *__cdecl _localtime32(const __time32_t *_Time)
{
  return (*__MINGW_IMP_SYMBOL(localtime))(_Time);
}

