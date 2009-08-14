#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
#include <windows.h>

LONG InterlockedIncrement(LONG volatile *Addend)
{
  LONG ret, value = 1;
  __asm__ ("lock\n\t"
	       "xaddl %0,(%1)"
	       : "=r" (ret)
	       : "r" (Addend), "0" (value)
	       : "memory");
  return ret + 1;
}
