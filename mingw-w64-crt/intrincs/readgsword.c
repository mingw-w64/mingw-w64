#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

/* for __x86_64 only */

 WORD __readgsword(DWORD Offset)
 {
   WORD ret;
   __asm__ volatile ("movw	%%gs:%1,%0"
     : "=r" (ret) ,"=m" ((*(volatile long *) (DWORD64) Offset)));
   return ret;
 }

