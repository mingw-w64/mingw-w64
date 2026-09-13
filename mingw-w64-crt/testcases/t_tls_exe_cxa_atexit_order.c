#include <stdio.h>
#include <stdlib.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

/* mingw-w64 headers */
#include "libtest.h"

extern int __mingw_cxa_atexit(void (__thiscall *dtor)(void *obj), void *obj, void *dso);

static int main_success = 0;

static void __cdecl atexit1_callback(void)
{
  printf("Error: atexit1 calllback was called before mingw_cxa_atexit callback\n");
  /* exit, _exit, or ExitProcess calls TLS callbacks, so use TerminateProcess() which is not calling them */
  TerminateProcess(GetCurrentProcess(), 1);
}

static void __cdecl atexit2_callback(void)
{
  printf("Error: atexit2 calllback was called before mingw_cxa_atexit callback\n");
  /* exit, _exit, or ExitProcess calls TLS callbacks, so use TerminateProcess() which is not calling them */
  TerminateProcess(GetCurrentProcess(), 1);
}

static void __thiscall mingw_cxa_atexit_callback(void *obj)
{
  if (obj != (void*)42) {
    printf("Error: mingw_cxa_atexit callback was called with wrong obj\n");
    main_success = 0;
  } else {
    printf("SUCCESS: mingw_cxa_atexit callback was called\n");
  }
  /* exit, _exit, or ExitProcess calls TLS callbacks, so use TerminateProcess() which is not calling them */
  TerminateProcess(GetCurrentProcess(), main_success ? 0 : 1);
}

int main(void)
{
  mingw_test_init();

  /* Register two atexit callbacks, one before __mingw_cxa_atexit() call and one after __mingw_cxa_atexit() call.
   * The mingw_cxa_atexit callback must be called before any atexit callback independently of the registration order. */

  if (atexit(atexit1_callback) != 0) {
    printf("Error: atexit() failed\n");
    /* exit, _exit, or ExitProcess calls TLS callbacks, so use TerminateProcess() which is not calling them */
    TerminateProcess(GetCurrentProcess(), 1);
  }

  if (__mingw_cxa_atexit(&mingw_cxa_atexit_callback, (void*)42, NULL) != 0) {
    printf("Error: __mingw_cxa_atexit() failed\n");
    /* exit, _exit, or ExitProcess calls TLS callbacks, so use TerminateProcess() which is not calling them */
    TerminateProcess(GetCurrentProcess(), 1);
  }

  if (atexit(atexit2_callback) != 0) {
    printf("Error: atexit() failed\n");
    /* exit, _exit, or ExitProcess calls TLS callbacks, so use TerminateProcess() which is not calling them */
    TerminateProcess(GetCurrentProcess(), 1);
  }

  printf("Checking if the mingw_cxa_atexit callback would be called before all atexit callbacks...\n");
  main_success = 1;
  return 1; /* mingw_cxa_atexit callback changes return code to 0 */
}
