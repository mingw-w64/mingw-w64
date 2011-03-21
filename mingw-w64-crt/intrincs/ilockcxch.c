#include <intrin.h>

long _InterlockedCompareExchange(long volatile *Destination, long ExChange, long Comperand)
{
  long prev;
  __asm__ __volatile__("lock ; cmpxchgl %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
  return prev;
}

#ifdef _WIN64
long InterlockedCompareExchange(long volatile *, long, long) __attribute__((alias("_InterlockedCompareExchange")));
#else
long __stdcall InterlockedCompareExchange(long volatile *Destination, long ExChange, long Comperand);
long __stdcall InterlockedCompareExchange(long volatile *Destination, long ExChange, long Comperand)
{
  return _InterlockedCompareExchange(Destination, ExChange, Comperand);
}
#endif

