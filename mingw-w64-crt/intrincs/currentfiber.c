#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
#include <windows.h>

 PVOID GetCurrentFiber(VOID)
 {
#ifdef _WIN64
   return(PVOID)__readgsqword(FIELD_OFFSET(NT_TIB,FiberData));
#else
    void *ret;
    __asm__ volatile ("movl     %%fs:0x10,%0"
        : "=r" (ret));
    return ret;
#endif
 }

