#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
#include <windows.h>

/* for __x86_64 only */

 DWORD __readgsdword(DWORD Offset)
 {
   DWORD ret;
   __asm__ volatile ("movl	%%gs:%1,%0"
     : "=r" (ret) ,"=m" ((*(volatile long *) (DWORD64) Offset)));
   return ret;
 }

