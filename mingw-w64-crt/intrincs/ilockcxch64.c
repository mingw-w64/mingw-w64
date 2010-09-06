#include <intrin.h>

#ifdef _WIN64
__int64 _InterlockedCompareExchange64(__int64 volatile *Destination, __int64 ExChange, __int64 Comperand)
{
  __int64 prev;
  __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
  return prev;
}
#else
__int64 _InterlockedCompareExchange64(volatile __int64 *Destination, __int64 Exchange, __int64 Comperand);

__int64 _InterlockedCompareExchange64(volatile __int64 *Destination, __int64 Exchange, __int64 Comperand)
{
  __int64 retval = Comperand;
  __asm__ __volatile__
  (
    "lock; cmpxchg8b %[Destination]" :
    [retval] "+A" (retval) :
    [Destination] "m" (*Destination),
    "b" ((unsigned long)((Exchange >>  0) & 0xFFFFFFFF)),
    "c" ((unsigned long)((Exchange >> 32) & 0xFFFFFFFF)) :
    "memory"
  );

  return retval;
}
#endif

#ifdef _WIN64
__int64 InterlockedCompareExchange64(__int64 volatile *, __int64, __int64) __attribute__((alias("_InterlockedCompareExchange64")));
#else
__int64 __stdcall InterlockedCompareExchange64(__int64 volatile *Destination,
   __int64 ExChange, __int64 Comperand);
__int64 __stdcall InterlockedCompareExchange64(__int64 volatile *Destination,
   __int64 ExChange, __int64 Comperand)
{
  return _InterlockedCompareExchange64 (Destination, ExChange, Comperand);
}
#endif

