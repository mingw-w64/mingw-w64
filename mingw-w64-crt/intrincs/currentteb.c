#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

#ifdef _WIN64
 struct _TEB *NtCurrentTeb(VOID)
 {
   return (struct _TEB *)__readgsqword(FIELD_OFFSET(NT_TIB,Self));
 }
#else
 struct _TEB *NtCurrentTeb(void)
 {
   struct _TEB *ret;
   __asm__ volatile ("movl	%%fs:0x18,%0"
     : "=r" (ret));
   return ret;
 }
#endif

