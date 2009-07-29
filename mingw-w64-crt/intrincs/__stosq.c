#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
#include <windows.h>
#ifdef _WIN64
VOID __stosq(PDWORD64 Dest,DWORD64 Data,SIZE_T Count)
{
  __asm__ __volatile__
  (
    "rep; stosq" :
    [Dest] "=D" (Dest), [Count] "=c" (Count) :
    "[Dest]" (Dest), "a" (Data), "[Count]" (Count)
  );
}

#endif

