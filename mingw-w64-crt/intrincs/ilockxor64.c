#include <intrin.h>
#include <psdk_inc/intrin-mac.h>

#ifdef _WIN64
__buildlogicali(_InterlockedXor64, __int64, xor)
#else
__int64 __stdcall InterlockedCompareExchange64(__int64 volatile *Destination,
  __int64 Exchange, __int64 Comperand);
__int64 _InterlockedXor64 (__int64 volatile *Destination,__int64 Value);
__int64 _InterlockedXor64 (__int64 volatile *Destination,__int64 Value)
{
    __int64 Old;
    do {
      Old = *Destination;
    } while(InterlockedCompareExchange64(Destination,Old ^ Value,Old)!=Old);

    return Old;
  }
#endif

#ifdef _WIN64
__int64 InterlockedXor64(__int64 volatile *, __int64) __attribute__((alias("_InterlockedXor64")));
#else
__int64 __stdcall InterlockedXor64(__int64 volatile *Destination, __int64 Value);
__int64 __stdcall InterlockedXor64(__int64 volatile *Destination, __int64 Value)
{
  return _InterlockedXor64(Destination, Value);
}
#endif
