#include <intrin.h>

/* for x86 only */
unsigned short __readfsword(unsigned long Offset)
{
   unsigned short ret;
   __asm__ volatile ("movw	%%fs:%1,%0"
     : "=r" (ret) ,"=m" ((*(volatile long *) Offset)));
   return ret;
}

