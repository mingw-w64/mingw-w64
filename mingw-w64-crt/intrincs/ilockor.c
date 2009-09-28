#include <intrin.h>

long _InterlockedOr(long volatile *Destination, long Value)
{
  __asm__ __volatile__("lock ; orl %0,%1"
    : : "r"(Value),"m"(*Destination) : "memory");
  return *Destination;
}

long InterlockedOr(long volatile *, long) __attribute__((alias("_InterlockedOr")));

