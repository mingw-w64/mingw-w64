#include <intrin.h>

__int64 _InterlockedExchangeAdd64(__int64 volatile *Addend, __int64 Value)
{
  __int64 ret;
  __asm__ __volatile__ ("lock\n\t"
           "xaddq %0,(%1)"
           : "=r" (ret)
           : "r" (Addend), "0" (Value)
           : "memory");
  return ret;
}

__int64 InterlockedExchangeAdd64(__int64 volatile *, __int64) __attribute__((alias("_InterlockedExchangeAdd64")));

