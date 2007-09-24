#include <time.h>

time_t __cdecl mktime(struct tm *_Tm)
{
#ifdef _USE_32BIT_TIME_T
  return _mktime32(_Tm);
#else
  return _mktime64(_Tm);
#endif
}