#ifndef __NO_INLINE__
#define __NO_INLINE__
#endif
#include <time.h>

extern char * (__cdecl * __MINGW_IMP_SYMBOL(ctime))(const __time32_t *);

char *__cdecl _ctime32(const __time32_t *_Time)
{
  return (*__MINGW_IMP_SYMBOL(ctime))(_Time);
}

