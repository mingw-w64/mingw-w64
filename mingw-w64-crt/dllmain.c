#include <oscalls.h>
#define _DECL_DLLMAIN
#include <process.h>

BOOL WINAPI DllMain(HANDLE hDllHandle, DWORD dwReason, LPVOID lpreserved)
{
#if defined (CRTDLL)
  if (dwReason == DLL_PROCESS_ATTACH && !_pRawDllMain)
    DisableThreadLibraryCalls (hDllHandle);
#endif
  return TRUE;
}
