#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

BOOLEAN _BitScanReverse64(DWORD *Index,DWORD64 Mask)
{
  __asm__ __volatile__("bsrq %1,%0" : "=r" (Mask),"=m" ((*(volatile long long *)Index)));
  return (Mask != 0);
}

