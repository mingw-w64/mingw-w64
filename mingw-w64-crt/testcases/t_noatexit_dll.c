#include <stdio.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

/* mingw-w64 headers */
#include "libtest.h"

/* This test verifies that DLL library libnoatexit.dll which is not using atexit callbacks, does not have unwanted/unexpected atexit implementation. */
int main(void)
{
  mingw_test_init();

  /* gcc's crtbegin.o (libgcc/config/i386/cygming-crtbegin.c) injects atexit call into every output binary.
   * So skip this test for all gcc builds (and exclude clang builds for which this test is passing). */
#if defined(__GNUC__) && !defined(__clang__)
  printf("test skipped for gcc builds\n");
  return 77;
#endif

  HMODULE lib = LoadLibraryA("libnoatexit.dll");
  if (!lib) {
    DWORD error = GetLastError();
    printf("test failed\n");
    printf("Cannot load DLL library libnoatexit.dll: %lu\n", error);
    return 1;
  }

  int (*is_atexit_included)(void) = (int(*)(void))(void(*)(void))GetProcAddress(lib, "is_atexit_included");
  if (!is_atexit_included) {
    DWORD error = GetLastError();
    printf("test failed\n");
    printf("Cannot resolve is_atexit_included symbol from DLL library libnoatexit.dll: %lu\n", error);
    return 1;
  }

  if (is_atexit_included()) {
    printf("test failed\n");
    printf("DLL library libnoatexit.dll contains static linked mingw-w64 atexit implementation\n");
    return 1;
  } else {
    printf("test passed\n");
    printf("DLL library libnoatexit.dll does not contain static linked mingw-w64 atexit implementation\n");
    return 0;
  }
}
