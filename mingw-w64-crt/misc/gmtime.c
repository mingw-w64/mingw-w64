#include <time.h>

struct tm *__cdecl gmtime(const time_t *_Time)
{
#ifdef _USE_32BIT_TIME_T
  return _gmtime32(_Time);
#else
  return _gmtime64(_Time);
#endif
}
