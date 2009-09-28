#include <intrin.h>

long _InterlockedCompareExchange(long volatile *Destination, long ExChange, long Comperand)
{
  long prev;
  __asm__ __volatile__("lock ; cmpxchgl %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
  return prev;
}

long InterlockedCompareExchange(long volatile *, long, long) __attribute__((alias("_InterlockedCompareExchange")));

