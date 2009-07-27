#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
#include <windows.h>

 PVOID GetCurrentFiber(VOID)
 {
   return(PVOID)__readgsqword(FIELD_OFFSET(NT_TIB,FiberData));
 }

