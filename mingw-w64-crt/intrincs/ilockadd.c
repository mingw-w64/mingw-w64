#include <intrin.h>

__LONG32 _InterlockedAdd(__LONG32 volatile *, __LONG32);			/* not in intrin.h */
__LONG32 _InterlockedAdd(__LONG32 volatile *Addend, __LONG32 Value)
{
/* return InterlockedExchangeAdd(Addend,Value) + Value; */
#if defined(__x86_64__) || defined(_AMD64_) || defined(__i386__) || defined(_X86_)
  __LONG32 ret;
  __asm__ __volatile__ ("lock\n\t"
           "xaddl %0,(%1)"
           : "=r" (ret)
           : "r" (Addend), "0" (Value)
           : "memory");
  return ret + Value;
#else
  return __sync_fetch_and_add(Addend, Value) + Value;
#endif
}

#ifdef _WIN64
__LONG32 InterlockedAdd(__LONG32 volatile *, __LONG32) __attribute__((alias("_InterlockedAdd")));
#else
__LONG32 __stdcall InterlockedAdd(__LONG32 volatile *Addend, __LONG32 Value);
__LONG32 __stdcall InterlockedAdd(__LONG32 volatile *Addend, __LONG32 Value)
{
  return _InterlockedAdd(Addend, Value);
}
#endif

