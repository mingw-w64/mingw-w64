#include <intrin.h>

__LONG32 _InterlockedDecrement(__LONG32 volatile *Addend)
{
  __LONG32 ret = -1;
  __asm__ __volatile__ ("lock\n\t"
	       "xaddl %0,%1"
	       : "+r" (ret), "+m" (*Addend)
	       : : "memory");
  return ret - 1;
}

#ifdef _WIN64
__LONG32 InterlockedDecrement(__LONG32 volatile *) __attribute__((alias("_InterlockedDecrement")));
#else
__LONG32 __stdcall InterlockedDecrement(__LONG32 volatile *Addend);
__LONG32 __stdcall InterlockedDecrement(__LONG32 volatile *Addend)
{
  return _InterlockedDecrement(Addend);
}
#endif

