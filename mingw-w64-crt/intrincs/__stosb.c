#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
#include <windows.h>

VOID __stosb(PBYTE Dest,BYTE Data,SIZE_T Count);

VOID __stosb(PBYTE Dest,BYTE Data,SIZE_T Count)
{
  __asm__ __volatile__
  (
    "rep; stosb" :
    [Dest] "=D" (Dest), [Count] "=c" (Count) :
    "[Dest]" (Dest), "a" (Data), "[Count]" (Count)
  );
}



