#include <stdio.h>
#include <stdlib.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

/* mingw-w64 headers */
#include "libtest.h"

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static void WINAPI pe_tls_callback(HANDLE handle __attribute__((unused)), DWORD reason, LPVOID reserved __attribute__((unused)))
{
  if (reason == DLL_PROCESS_DETACH) {
    printf("SUCCESS: PE TLS callback for DLL_PROCESS_DETACH was called\n");
    /* exit, _exit, or ExitProcess calls TLS callbacks, so use TerminateProcess() which is not calling them */
    TerminateProcess(GetCurrentProcess(), 0);
  }
}

/* Register pe_tls_callback as PE TLS callback with the highest priority (=B) */
static __attribute__((section(".CRT$XLB"), used)) const PIMAGE_TLS_CALLBACK register_pe_tls_callback = pe_tls_callback;

/* Force tlssup.c (_tls_used symbol for .tls linker section) to be linked */
extern const IMAGE_TLS_DIRECTORY _tls_used;
static __attribute__((destructor)) void _include_tls_used(void) { asm volatile ("" :: "r" (&_tls_used)); }

int main(void)
{
  mingw_test_init();

  if (_osplatform == VER_PLATFORM_WIN32_WINDOWS) {
    printf("PE TLS callbacks are not supported on Win9x\n");
    return 77;
  }

  printf("Checking if the PE TLS callback for DLL_PROCESS_DETACH would be called...\n");
  return 1; /* TLS callback changes return code to 0 */
}
