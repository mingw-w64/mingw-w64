#include <intrin.h>

#ifdef _WIN64
__int64 _InterlockedAnd64(__int64 volatile *Destination, __int64 Value)
{
  __asm__ __volatile__("lock ; andq %0,%1"
    : : "r"(Value),"m"(*Destination) : "memory");
  return *Destination;
}
#else
__int64 __stdcall InterlockedCompareExchange64(__int64 volatile *Destination,
  __int64 Exchange, __int64 Comperand);
__int64 _InterlockedAnd64 (__int64 volatile *Destination,__int64 Value);
__int64 _InterlockedAnd64 (__int64 volatile *Destination,__int64 Value)
{
  __int64 Old;
  do {
    Old = *Destination;
  } while(InterlockedCompareExchange64(Destination,Old & Value,Old)!=Old);
  return Old;
}
#endif

#ifdef _WIN64
__int64 InterlockedAnd64(__int64 volatile *, __int64) __attribute__((alias("_InterlockedAnd64")));
#else
__int64 __stdcall InterlockedAnd64(__int64 volatile *Destination, __int64 Value);
__int64 __stdcall InterlockedAnd64(__int64 volatile *Destination, __int64 Value)
{
  return _InterlockedAnd64(Destination, Value);
}
#endif
