#include <stdio.h>
#include <stdlib.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

/* mingw-w64 headers */
#include "libtest.h"

extern int __cdecl __tlregdtor(void (__cdecl*func)(void));

static int main_success = 0;

static void __cdecl atexit1_callback(void)
{
  printf("Error: atexit1 calllback was called before __tlregdtor callback\n");
  /* exit, _exit, or ExitProcess calls TLS callbacks, so use TerminateProcess() which is not calling them */
  TerminateProcess(GetCurrentProcess(), 1);
}

static void __cdecl atexit2_callback(void)
{
  printf("Error: atexit2 calllback was called before __tlregdtor callback\n");
  /* exit, _exit, or ExitProcess calls TLS callbacks, so use TerminateProcess() which is not calling them */
  TerminateProcess(GetCurrentProcess(), 1);
}

static void __cdecl dtor_callback(void)
{
  printf("SUCCESS: __tlregdtor callback was called\n");
  /* exit, _exit, or ExitProcess calls TLS callbacks, so use TerminateProcess() which is not calling them */
  TerminateProcess(GetCurrentProcess(), main_success ? 0 : 1);
}

int main(void)
{
  mingw_test_init();

  /* Register two atexit callbacks, one before __tlregdtor() call and one after __tlregdtor() call.
   * The __tlregdtor callback must be called before any atexit callback independently of the registration order. */

  if (atexit(atexit1_callback) != 0) {
    printf("Error: atexit() failed\n");
    /* exit, _exit, or ExitProcess calls TLS callbacks, so use TerminateProcess() which is not calling them */
    TerminateProcess(GetCurrentProcess(), 1);
  }

  if (__tlregdtor(&dtor_callback) != 0) {
    printf("Error: __tlregdtor() failed\n");
    /* exit, _exit, or ExitProcess calls TLS callbacks, so use TerminateProcess() which is not calling them */
    TerminateProcess(GetCurrentProcess(), 1);
  }

  if (atexit(atexit2_callback) != 0) {
    printf("Error: atexit() failed\n");
    /* exit, _exit, or ExitProcess calls TLS callbacks, so use TerminateProcess() which is not calling them */
    TerminateProcess(GetCurrentProcess(), 1);
  }

  printf("Checking if the __tlregdtor callback would be called before all atexit callbacks...\n");
  main_success = 1;
  return 1; /* __tlregdtor callback changes return code to 0 */
}
