#define __CRT__NO_INLINE
#include <time.h>

/* FIXME: Relying on _USE_32BIT_TIME_T, which is a user-macro,
during CRT compilation is plainly broken.  Need an appropriate
implementation to provide users the ability of compiling the
CRT only with 32-bit time_t behavior. */

time_t __cdecl mktime(struct tm *_Tm)
{
#ifdef _USE_32BIT_TIME_T
  return _mktime32(_Tm);
#else
  return _mktime64(_Tm);
#endif
}