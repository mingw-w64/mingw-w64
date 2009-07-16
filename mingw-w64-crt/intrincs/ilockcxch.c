#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

#undef InterlockedCompareExchange
LONG InterlockedCompareExchange(LONG volatile *Destination,LONG ExChange,LONG Comperand)
{
  LONG prev;
  __asm__ __volatile__("lock ; cmpxchgl %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
  return prev;
}

