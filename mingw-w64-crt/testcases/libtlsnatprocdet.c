#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static void WINAPI pe_tls_callback(HANDLE handle __attribute__((unused)), DWORD reason, LPVOID reserved __attribute__((unused)))
{
  /* When process is exiting, change its exit code from 1 to 0 */
  if (reason == DLL_PROCESS_DETACH) {
    /* exit, _exit, or ExitProcess calls TLS callbacks, so use TerminateProcess() which is not calling them */
    TerminateProcess(GetCurrentProcess(), 0);
  }
}

/* Register pe_tls_callback as PE TLS callback with the highest priority (=B) */
static __attribute__((section(".CRT$XLB"), used)) const PIMAGE_TLS_CALLBACK register_pe_tls_callback = pe_tls_callback;

/* Force tlssup.c (_tls_used symbol for .tls linker section) to be linked */
extern const IMAGE_TLS_DIRECTORY _tls_used;
static __attribute__((destructor)) void _include_tls_used(void) { asm volatile ("" :: "r" (&_tls_used)); }

/* Export some symbol which is specific to this library, test file is importing it */
__attribute__((dllexport)) const int libtlsnatprocdet_library = 1;
