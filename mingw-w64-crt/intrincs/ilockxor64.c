#include <intrin.h>

__int64 _InterlockedXor64(__int64 volatile *Destination, __int64 Value)
{
  __asm__ __volatile__("lock ; xorq %0,%1"
    : : "r"(Value),"m"(*Destination) : "memory");
  return *Destination;
}

__int64 InterlockedXor64(__int64 volatile *, __int64) __attribute__((alias("_InterlockedXor64")));

