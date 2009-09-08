#include <intrin.h>

/* for x86 only */
unsigned char __readfsbyte(unsigned long Offset)
{
   unsigned char ret;
   __asm__ volatile ("movb	%%fs:%1,%0"
     : "=r" (ret) ,"=m" ((*(volatile long *) Offset)));
   return ret;
}

