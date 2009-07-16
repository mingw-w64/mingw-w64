#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

/* for __x86_64 only */

 VOID __writegsword(DWORD Offset,WORD Data)
 {
    __asm__ volatile ("movw	%0,%%gs:%1"
      : "=r" (Data) ,"=m" ((*(volatile long *) (DWORD64) Offset)));
 }

