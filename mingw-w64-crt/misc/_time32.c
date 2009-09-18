#define __NO_INLINE__
#include <time.h>

extern __time32_t (__cdecl *__MINGW_IMP_SYMBOL(time))(__time32_t *);

__time32_t __cdecl _time32(__time32_t *_Time)
{
  return (*__MINGW_IMP_SYMBOL(time))(_Time);
}

