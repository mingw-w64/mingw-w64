#define __CRT__NO_INLINE
#include <time.h>

/* FIXME: Relying on _USE_32BIT_TIME_T, which is a user-macro,
during CRT compilation is plainly broken.  Need an appropriate
implementation to provide users the ability of compiling the
CRT only with 32-bit time_t behavior. */

struct tm *__cdecl localtime(const time_t *_Time)
{
#ifdef _USE_32BIT_TIME_T
  return _localtime32(_Time);
#else
  return _localtime64(_Time);
#endif
}
