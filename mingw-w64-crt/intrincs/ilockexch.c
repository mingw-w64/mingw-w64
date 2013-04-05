#include <intrin.h>

__LONG32 _InterlockedExchange(__LONG32 volatile *Target, __LONG32 Value)
{
  __asm__ __volatile("lock ; xchgl %0,%1"
    : "=r"(Value)
    : "m"(*Target),"0"(Value)
    : "memory");
  return Value;
}

#ifdef _WIN64
__LONG32 InterlockedExchange(__LONG32 volatile *, __LONG32) __attribute__((alias("_InterlockedExchange")));
#else
__LONG32 __stdcall InterlockedExchange(__LONG32 volatile *Target, __LONG32 Value);
__LONG32 __stdcall InterlockedExchange(__LONG32 volatile *Target, __LONG32 Value)
{
  return _InterlockedExchange(Target,Value);
}
#endif

