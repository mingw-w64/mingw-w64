#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
#include <windows.h>

 PVOID GetFiberData(VOID)
 {
#ifdef _WIN64
   return *(PVOID *)GetCurrentFiber();
#else
  void *ret;
  __asm__ volatile ("movl     %%fs:0x10,%0\n"
      "movl   (%0),%0"
      : "=r" (ret));
  return ret;
#endif
 }

