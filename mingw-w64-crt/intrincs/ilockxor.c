#include <intrin.h>

__LONG32 _InterlockedXor(__LONG32 volatile *Destination, __LONG32 Value)
{
  __asm__ __volatile__("lock ; xorl %0,%1"
    : : "r"(Value),"m"(*Destination) : "memory");
  return *Destination;
}

__LONG32 InterlockedXor(__LONG32 volatile *, __LONG32) __attribute__((alias("_InterlockedXor")));

