#include <time.h>

time_t __cdecl time(time_t *_Time)
{
#ifdef _USE_32BIT_TIME_T
  return _time32(_Time);
#else
  return _time64(_Time);
#endif
}
