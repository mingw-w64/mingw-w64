#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
#include <windows.h>

SHORT InterlockedCompareExchange16(SHORT volatile *Destination,SHORT ExChange,SHORT Comperand)
{
  SHORT prev;
  __asm__ __volatile__("lock ; cmpxchgw %w1,%2"
    :"=a"(prev)
    :"q"(ExChange), "m"(*Destination), "0"(Comperand)
    : "memory");
  return prev;
}

