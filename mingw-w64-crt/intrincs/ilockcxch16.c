#include <intrin.h>

short _InterlockedCompareExchange16(short volatile *Destination, short ExChange, short Comperand)
{
  short prev;
  __asm__ __volatile__("lock ; cmpxchgw %w1,%2"
    :"=a"(prev)
    :"q"(ExChange), "m"(*Destination), "0"(Comperand)
    : "memory");
  return prev;
}

short InterlockedCompareExchange16(short volatile *, short, short) __attribute__((alias("_InterlockedCompareExchange16")));

