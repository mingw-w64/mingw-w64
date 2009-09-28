#ifndef __NO_INLINE__
#define __NO_INLINE__
#endif
#include <time.h>

extern __time32_t (__cdecl *__MINGW_IMP_SYMBOL(mktime))(struct tm *);

__time32_t __cdecl _mktime32(struct tm *_Tm)
{
  return (*__MINGW_IMP_SYMBOL(mktime))(_Tm);
}

