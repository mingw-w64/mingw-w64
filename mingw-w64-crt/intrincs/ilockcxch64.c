#include <intrin.h>

__int64 _InterlockedCompareExchange64(__int64 volatile *Destination, __int64 ExChange, __int64 Comperand)
{
  __int64 prev;
  __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
  return prev;
}

__int64 InterlockedCompareExchange64(__int64 volatile *, __int64, __int64) __attribute__((alias("_InterlockedCompareExchange64")));

