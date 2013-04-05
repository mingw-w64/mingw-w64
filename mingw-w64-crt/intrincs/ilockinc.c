#include <intrin.h>

__LONG32 _InterlockedIncrement(__LONG32 volatile *Addend)
{
  __LONG32 ret = 1;
  __asm__ __volatile__ ("lock\n\t"
	       "xaddl %0,%1"
	       : "+r" (ret), "+m" (*Addend)
	       : : "memory");
  return ret + 1;
}

#ifdef _WIN64
__LONG32 InterlockedIncrement(__LONG32 volatile *) __attribute__((alias("_InterlockedIncrement")));
#else
__LONG32 __stdcall InterlockedIncrement(__LONG32 volatile *Addend);
__LONG32 __stdcall InterlockedIncrement(__LONG32 volatile *Addend)
{
  return _InterlockedIncrement (Addend);
}
#endif

