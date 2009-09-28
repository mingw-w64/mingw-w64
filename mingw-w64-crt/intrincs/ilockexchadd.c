#include <intrin.h>

long _InterlockedExchangeAdd(long volatile *Addend, long Value)
{
  long ret;
  __asm__ __volatile__ ("lock\n\t"
           "xaddl %0,(%1)"
           : "=r" (ret)
           : "r" (Addend), "0" (Value)
           : "memory");
  return ret;
}

long InterlockedExchangeAdd(long volatile *, long) __attribute__((alias("_InterlockedExchangeAdd")));

