#include <time.h>
#include <memory.h>

double __cdecl difftime(time_t _Time1,time_t _Time2)
{
#ifdef _USE_32BIT_TIME_T
  return _difftime32(_Time1,_Time2);
#else
  return _difftime64(_Time1,_Time2);
#endif
}

