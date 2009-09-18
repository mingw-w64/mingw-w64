#ifndef __NO_INLINE__
#define __NO_INLINE__
#endif
#include <time.h>

extern struct tm * (__cdecl *__MINGW_IMP_SYMBOL(gmtime))(const __time32_t *);

struct tm *__cdecl _gmtime32(const __time32_t *_Time)
{
  return (*__MINGW_IMP_SYMBOL(gmtime))(_Time);
}
