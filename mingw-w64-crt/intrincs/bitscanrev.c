#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
#include <windows.h>

BOOLEAN _BitScanReverse(DWORD *Index,DWORD Mask);

BOOLEAN _BitScanReverse(DWORD *Index,DWORD Mask)
{
  __asm__ __volatile__("bsrl %1,%0" : "=r" (Mask),"=m" ((*(volatile long *)Index)));
  return (Mask != 0);
}

