#include <stdio.h>
#include <stdlib.h>
#include <io.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

/* mingw-w64 headers */
#include "libtest.h"

static int main_success = 0;
static HANDLE stdout_handle = NULL;

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static void WINAPI pe_tls_callback(HANDLE handle __attribute__((unused)), DWORD reason, LPVOID reserved __attribute__((unused)))
{
  if (reason == DLL_PROCESS_DETACH) {
    /* Do not call CRT functions, at this stage they can be already deinitialized */
    if (stdout_handle != NULL && stdout_handle != INVALID_HANDLE_VALUE) {
      static const char buffer[] = "SUCCESS: PE TLS callback for DLL_PROCESS_DETACH was called\r\n";
      WriteFile(stdout_handle, buffer, sizeof(buffer)-1, &(DWORD){0}, NULL);
    }
    /* exit, _exit, or ExitProcess calls TLS callbacks, so use TerminateProcess() which is not calling them */
    TerminateProcess(GetCurrentProcess(), main_success ? 0 : 1);
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
    /* exit, _exit, or ExitProcess calls TLS callbacks, so use TerminateProcess() which is not calling them */
    TerminateProcess(GetCurrentProcess(), 77);
  }

  printf("Checking if the PE TLS callback for DLL_PROCESS_DETACH would be called...\n");

  /* Store copy of the WinAPI stdout HANDLE as CRT stdio functions cannot be used in PE TLS callback during DLL_PROCESS_DETACH */
  DuplicateHandle(GetCurrentProcess(), (HANDLE)_get_osfhandle(STDOUT_FILENO), GetCurrentProcess(), &stdout_handle, 0, FALSE, DUPLICATE_SAME_ACCESS);

  main_success = 1;
  return 1; /* TLS callback changes return code to 0 */
}
