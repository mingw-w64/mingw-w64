#include <intrin.h>
#include <psdk_inc/intrin-mac.h>

#ifdef _WIN64
__buildlogicali(_InterlockedOr64, __int64, or)
#else
__int64 __stdcall InterlockedCompareExchange64(__int64 volatile *Destination,
  __int64 Exchange, __int64 Comperand);
__int64 _InterlockedOr64 (__int64 volatile *Destination,__int64 Value);
__int64 _InterlockedOr64 (__int64 volatile *Destination,__int64 Value)
{
  __int64 Old;
  do {
    Old = *Destination;
  } while(InterlockedCompareExchange64(Destination,Old | Value,Old)!=Old);
  return Old;
}
#endif

#ifdef _WIN64
__int64 InterlockedOr64(__int64 volatile *, __int64) __attribute__((alias("_InterlockedOr64")));
#else
__int64 __stdcall InterlockedOr64(__int64 volatile *Destination, __int64 Value);
__int64 __stdcall InterlockedOr64(__int64 volatile *Destination, __int64 Value)
{
  return _InterlockedOr64(Destination, Value);
}
#endif

