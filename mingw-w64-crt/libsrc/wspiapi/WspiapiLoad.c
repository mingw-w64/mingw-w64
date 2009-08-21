#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <wspiapi.h>

FARPROC WINAPI
WspiapiLoad (WORD wFunction)
{
  HMODULE hLibrary = NULL;
  static WINBOOL bInitialized = FALSE;
  static WSPIAPI_FUNCTION rgtGlobal[] = WSPIAPI_FUNCTION_ARRAY;
  static const int iNumGlobal = (sizeof(rgtGlobal) / sizeof(WSPIAPI_FUNCTION));
  WSPIAPI_FUNCTION rgtLocal[] = WSPIAPI_FUNCTION_ARRAY;
  FARPROC fScratch = NULL;
  int i = 0;
  if (bInitialized)
    return (rgtGlobal[wFunction].pfAddress);
  for (;;) {
    CHAR SystemDir[MAX_PATH + 1];
    CHAR Path[MAX_PATH + 8];
    if (GetSystemDirectoryA(SystemDir,MAX_PATH) == 0)
      break;
    _WSPIAPI_STRCPY_S(Path, _WSPIAPI_COUNTOF(Path), SystemDir);
    _WSPIAPI_STRCAT_S(Path, _WSPIAPI_COUNTOF(Path), "\\ws2_32");
    hLibrary = LoadLibraryA(Path);
    if (hLibrary != NULL) {
      fScratch = GetProcAddress(hLibrary, "getaddrinfo");
      if (!fScratch) {
	FreeLibrary(hLibrary);
	hLibrary = NULL;
      }
    }
    if (hLibrary != NULL)
      break;
    _WSPIAPI_STRCPY_S(Path, _WSPIAPI_COUNTOF(Path), SystemDir);
    _WSPIAPI_STRCAT_S(Path, _WSPIAPI_COUNTOF(Path), "\\wship6");
    hLibrary = LoadLibraryA(Path);
    if (hLibrary != NULL) {
      fScratch = GetProcAddress(hLibrary, "getaddrinfo");
      if (!fScratch) {
	FreeLibrary(hLibrary);
	hLibrary = NULL;
      }
    }
    break;
  }
  if (hLibrary != NULL) {
    for (i = 0; i < iNumGlobal; i++) {
      rgtLocal[i].pfAddress = GetProcAddress(hLibrary, rgtLocal[i].pszName);
      if (!(rgtLocal[i].pfAddress)) {
	FreeLibrary(hLibrary);
	hLibrary = NULL;
	break;
      }
    }
    if (hLibrary != NULL) {
      for (i = 0; i < iNumGlobal; i++)
	rgtGlobal[i].pfAddress = rgtLocal[i].pfAddress;
    }
  }
  bInitialized = TRUE;
  return (rgtGlobal[wFunction].pfAddress);
}
