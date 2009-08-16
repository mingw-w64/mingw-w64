#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
#include <windows.h>

/* for x86 only */

 VOID __writefsbyte(DWORD Offset,BYTE Data)
 {
    __asm__ volatile ("movb	%0,%%fs:%1"
      : "=r" (Data) ,"=m" ((*(volatile long *) Offset)));
 }

