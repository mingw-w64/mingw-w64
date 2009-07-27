#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
#include <windows.h>

/* for __x86_64 only */

 DWORD64 __readgsqword(DWORD Offset)
 {
   void *ret;
   __asm__ volatile ("movq	%%gs:%1,%0"
     : "=r" (ret) ,"=m" ((*(volatile long *) (DWORD64) Offset)));
   return (DWORD64) ret;
 }

