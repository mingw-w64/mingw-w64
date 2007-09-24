#include <time.h>

time_t __cdecl _mkgmtime(struct tm *_Tm)
{
#ifdef _USE_32BIT_TIME_T
  return _mkgmtime32(_Tm);
#else
  return _mkgmtime64(_Tm);
#endif
}
