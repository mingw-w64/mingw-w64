#include <intrin.h>

__int64 _InterlockedAdd64(__int64 volatile *Addend, __int64 Value);			/* not in intrin.h */
__int64 _InterlockedAdd64(__int64 volatile *Addend, __int64 Value)
{
/* return InterlockedExchangeAdd64(Addend,Value) + Value; */
  __int64 ret;
  __asm__ __volatile__ ("lock\n\t"
           "xaddq %0,(%1)"
           : "=r" (ret)
           : "r" (Addend), "0" (Value)
           : "memory");
  return ret + Value;
}

__int64 InterlockedAdd64(__int64 volatile *Addend, __int64 Value) __attribute__((alias("_InterlockedAdd64")));

