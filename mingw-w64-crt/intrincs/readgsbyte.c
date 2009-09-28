#include <intrin.h>

/* for __x86_64 only */
unsigned char __readgsbyte(unsigned long Offset)
{
   unsigned char ret;
   __asm__ volatile ("movb	%%gs:%1,%0"
     : "=r" (ret) ,"=m" ((*(volatile long *) (unsigned __int64) Offset)));
   return ret;
}

