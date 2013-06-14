#include <intrin.h>

#ifdef _WIN32
__LONG32 __stdcall InterlockedCompareExchange(__LONG32 volatile *Destination, __LONG32 ExChange, __LONG32 Comperand);

__LONG32 __stdcall InterlockedCompareExchange(__LONG32 volatile *Destination, __LONG32 ExChange, __LONG32 Comperand)
{
  __LONG32 prev;
  __asm__ __volatile__("lock ; cmpxchgl %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
  return prev;
}
#endif
