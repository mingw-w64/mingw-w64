#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
#include <windows.h>

/* for x86 only */
 WORD __readfsword(DWORD Offset);

 WORD __readfsword(DWORD Offset)
 {
   WORD ret;
   __asm__ volatile ("movw	%%fs:%1,%0"
     : "=r" (ret) ,"=m" ((*(volatile long *) Offset)));
   return ret;
 }

