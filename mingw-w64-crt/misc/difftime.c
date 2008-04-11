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

struct tm *__cdecl localtime_r(const time_t *_Time,struct tm *_Tm)
{
  struct tm *p = localtime(_Time);
  if (!p)
    return NULL;
  if (_Tm)
    {
      memcpy (_Tm, p, sizeof (struct tm));
      return _Tm;
    }
  else
    return p;
}
