#include <intrin.h>

/* for __x86_64 only */
unsigned long __readgsdword(unsigned long Offset)
{
   unsigned long ret;
   __asm__ volatile ("movl	%%gs:%1,%0"
     : "=r" (ret) ,"=m" ((*(volatile long *) (unsigned __int64) Offset)));
   return ret;
}

