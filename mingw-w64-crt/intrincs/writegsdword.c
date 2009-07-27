#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
#include <windows.h>

/* for __x86_64 only */

 VOID __writegsdword(DWORD Offset,DWORD Data)
 {
   __asm__ volatile ("movl	%0,%%gs:%1"
     : "=r" (Data) ,"=m" ((*(volatile long *) (DWORD64) Offset)));
 }

