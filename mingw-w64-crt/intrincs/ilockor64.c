#include <intrin.h>

__int64 _InterlockedOr64(__int64 volatile *Destination, __int64 Value)
{
  __asm__ __volatile__("lock ; orq %0,%1"
    : : "r"(Value),"m"(*Destination) : "memory");
  return *Destination;
}

