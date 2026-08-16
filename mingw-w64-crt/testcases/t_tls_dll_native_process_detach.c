#include <stdio.h>
#include <stdlib.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

/* mingw-w64 headers */
#include "libtest.h"

__attribute__((dllimport)) extern const int libtlsnatprocdet_library;

int main(void)
{
  mingw_test_init();

  if (_osplatform == VER_PLATFORM_WIN32_WINDOWS) {
    printf("PE TLS callbacks are not supported on Win9x\n");
    return 77;
  }

  /* Force linking libtlsnatprocdet.dll library */
  const volatile int *const volatile libtlsnatprocdet_library_ref = &libtlsnatprocdet_library;
  (void)libtlsnatprocdet_library_ref;

  printf("Checking if the PE TLS callback inside libtlsnatprocdet.dll for DLL_PROCESS_DETACH would be called...\n");
  return 1; /* TLS callback inside libtlsnatprocdet.dll changes return code to 0 */
}
