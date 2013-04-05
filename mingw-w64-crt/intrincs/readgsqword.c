#include <intrin.h>

/* for __x86_64 only */
unsigned __int64 __readgsqword(unsigned __LONG32 Offset)
{
   void *ret;
   __asm__ volatile ("movq	%%gs:%1,%0"
     : "=r" (ret) ,"=m" ((*(volatile __LONG32 *) (unsigned __int64) Offset)));
   return (unsigned __int64) ret;
}

