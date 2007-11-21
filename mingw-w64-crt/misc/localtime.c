#include <time.h>

struct tm *__cdecl localtime(const time_t *_Time)
{
#ifdef _USE_32BIT_TIME_T
  return _localtime32(_Time);
#else
  return _localtime64(_Time);
#endif
}
