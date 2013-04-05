#include <intrin.h>

__LONG32 _InterlockedAnd(__LONG32 volatile *Destination, __LONG32 Value)
{
  __asm__ __volatile__("lock ; andl %0,%1"
    : :"r"(Value),"m"(*Destination)
    : "memory");
  return *Destination;
}

__LONG32 InterlockedAnd(__LONG32 volatile *, __LONG32) __attribute__((alias("_InterlockedAnd")));

