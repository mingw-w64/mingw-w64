#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
#include <windows.h>

SHORT InterlockedIncrement16(SHORT volatile *Addend);

SHORT InterlockedIncrement16(SHORT volatile *Addend)
{
  SHORT ret = 1;
  __asm__ __volatile__ ("lock\n\t"
	       "xaddw %0,%1"
	       : "+r" (ret), "+m" (*Addend)
	       : : "memory");
  return ret + 1;
}
