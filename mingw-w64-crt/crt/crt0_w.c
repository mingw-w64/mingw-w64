/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

/* We need to trick here header, as it prototypes WinMain by itself.  */
#define WinMain dummyWinMain
#include <windows.h>
#undef WinMain

extern void __main(void);

/* Do the UNICODE prototyping of WinMain.  */
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPWSTR lpCmdLine,int nShowCmd);

extern HINSTANCE __mingw_winmain_hInstance;
extern LPWSTR __mingw_winmain_lpCmdLine;
extern DWORD __mingw_winmain_nShowCmd;

/*ARGSUSED*/
int wmain (int flags, wchar_t **cmdline, wchar_t **inst)
{
  return (int) WinMain (__mingw_winmain_hInstance, NULL,
			__mingw_winmain_lpCmdLine, __mingw_winmain_nShowCmd);
}
