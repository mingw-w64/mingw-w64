/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <process.h>
#include <windows.h>

__MINGW_ATTRIB_NORETURN
void __cdecl _endthreadex(unsigned retval)
{
  /* Do not call _endthread() as it automatically closes the thread handle.
   * Function _endthreadex() must not close the thread handle.
   * CRT DLL library always correctly release thread resources via its DLL entrypoint callback.
   * So calling just the WinAPI ExitThread() is enough, no memory leak is possible.
   */
  ExitThread(retval);
}
void (__cdecl *__MINGW_IMP_SYMBOL(_endthreadex))(unsigned) = _endthreadex;
