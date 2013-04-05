#include <intrin.h>
__LONG32 _InterlockedExchangeAdd(__LONG32 volatile *Addend, __LONG32 Value);

__LONG32 _InterlockedExchangeAdd(__LONG32 volatile *Addend, __LONG32 Value)
{
  __LONG32 ret;
  __asm__ __volatile__ ("lock\n\t"
           "xaddl %0,(%1)"
           : "=r" (ret)
           : "r" (Addend), "0" (Value)
           : "memory");
  return ret;
}

#ifdef _WIN64
__LONG32 InterlockedExchangeAdd(__LONG32 volatile *, __LONG32) __attribute__((alias("_InterlockedExchangeAdd")));
#else
__LONG32 __stdcall InterlockedExchangeAdd(__LONG32 volatile *Addend, __LONG32 Value);
__LONG32 __stdcall InterlockedExchangeAdd(__LONG32 volatile *Addend, __LONG32 Value)
{
  return _InterlockedExchangeAdd(Addend, Value);
}
#endif

