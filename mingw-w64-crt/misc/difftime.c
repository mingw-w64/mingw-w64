#define __CRT__NO_INLINE
#include <time.h>
#include <memory.h>

/* FIXME: Relying on _USE_32BIT_TIME_T, which is a user-macro,
during CRT compilation is plainly broken.  Need an appropriate
implementation to provide users the ability of compiling the
CRT only with 32-bit time_t behavior. */

double __cdecl difftime(time_t _Time1,time_t _Time2)
{
#ifdef _USE_32BIT_TIME_T
  return _difftime32(_Time1,_Time2);
#else
  return _difftime64(_Time1,_Time2);
#endif
}

