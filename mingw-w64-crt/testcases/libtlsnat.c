/* This is simple DLL library which uses PE TLS callback */

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

__attribute__((dllexport)) int libtlsnat_process_attach = 0;
__attribute__((dllexport)) int libtlsnat_thread_attach = 0;
__attribute__((dllexport)) int libtlsnat_process_detach = 0;
__attribute__((dllexport)) int libtlsnat_thread_detach = 0;

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static void WINAPI pe_tls_callback(HANDLE handle __attribute__((unused)), DWORD reason, LPVOID reserved __attribute__((unused)))
{
  if (reason == DLL_PROCESS_ATTACH) {
    libtlsnat_process_attach++;
  } else if (reason == DLL_THREAD_ATTACH) {
    libtlsnat_thread_attach++;
  } else if (reason == DLL_PROCESS_DETACH) {
    /* Check that DLL_PROCESS_DETACH is not called more than once */
    if (libtlsnat_process_detach != 0) {
      /* exit, _exit, or ExitProcess calls TLS callbacks, so use TerminateProcess() which is not calling them */
      TerminateProcess(GetCurrentProcess(), 1);
    }
    libtlsnat_process_detach++;
  } else if (reason == DLL_THREAD_DETACH) {
    libtlsnat_thread_detach++;
  }
}

/* Register pe_tls_callback as PE TLS callback with the highest priority (=B) */
static __attribute__((section(".CRT$XLB"), used)) const PIMAGE_TLS_CALLBACK register_pe_tls_callback = pe_tls_callback;

/* Force tlssup.c (_tls_used symbol for .tls linker section) to be linked */
extern const IMAGE_TLS_DIRECTORY _tls_used;
static __attribute__((destructor)) void _include_tls_used(void) { asm volatile ("" :: "r" (&_tls_used)); }
