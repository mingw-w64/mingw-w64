#include <time.h>

char *__cdecl ctime(const time_t *_Time)
{
#ifdef _USE_32BIT_TIME_T
  return _ctime32(_Time);
#else
  return _ctime64(_Time);
#endif
}