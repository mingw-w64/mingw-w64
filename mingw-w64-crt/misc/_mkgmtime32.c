#ifndef __NO_INLINE__
#define __NO_INLINE__
#endif
#include <time.h>

extern __time32_t (__cdecl *__MINGW_IMP_SYMBOL(_mkgmtime))(struct tm *);

__time32_t __cdecl _mkgmtime32(struct tm *_Tm)
{
  return (*__MINGW_IMP_SYMBOL(_mkgmtime))(_Tm);
}
