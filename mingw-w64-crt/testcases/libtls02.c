/* This is simple DLL library which uses CRT dyn TLS callback */

#include <corecrt_startup.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

static int process_or_thread_attach = 0;

__attribute__((dllexport))
int get_process_or_thread_attach(void)
{
  return process_or_thread_attach;
}

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static void __cdecl dyn_tls_callback(void)
{
  process_or_thread_attach++;
}

/* Register dyn_tls_callback as CRT dyn TLS callback with the highest priority (=B) */
static __attribute__((section(".CRT$XDB"), used)) _PVFV register_dyn_tls_callback = &dyn_tls_callback;

/* Force tlsdyn.c (__dyn_tls_init symbol) to be linked */
extern void WINAPI __dyn_tls_init(HANDLE, DWORD, LPVOID);
static __attribute__((used)) void (WINAPI *const _include_dyn_tls_init)(HANDLE, DWORD, LPVOID) = &__dyn_tls_init;
