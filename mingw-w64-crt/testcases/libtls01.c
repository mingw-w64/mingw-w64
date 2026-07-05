/* This is simple DLL library which uses PE TLS callback */

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

static int process_attach = 0;
static int thread_attach = 0;
static int *process_detach_var = NULL;
static int *thread_detach_var = NULL;

__attribute__((dllexport))
int get_process_attach(void)
{
  return process_attach;
}

__attribute__((dllexport))
int get_thread_attach(void)
{
  return thread_attach;
}

__attribute__((dllexport))
void set_process_detach_var(int *var)
{
  process_detach_var = var;
}

__attribute__((dllexport))
void set_thread_detach_var(int *var)
{
  thread_detach_var = var;
}

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static void WINAPI pe_tls_callback(HANDLE handle __attribute__((unused)), DWORD reason, LPVOID reserved __attribute__((unused)))
{
  if (reason == DLL_PROCESS_ATTACH) {
    process_attach++;
  } else if (reason == DLL_THREAD_ATTACH) {
    thread_attach++;
  } else if (reason == DLL_PROCESS_DETACH) {
    if (process_detach_var)
      (*process_detach_var)++;
  } else if (reason == DLL_THREAD_DETACH) {
    if (thread_detach_var)
      (*thread_detach_var)++;
  }
}

/* Register pe_tls_callback as PE TLS callback with the highest priority (=B) */
static __attribute__((section(".CRT$XLB"), used)) PIMAGE_TLS_CALLBACK register_pe_tls_callback = pe_tls_callback;

/* Force tlssup.c (_tls_used symbol for .tls linker section) to be linked */
extern const IMAGE_TLS_DIRECTORY _tls_used;
static __attribute__((used)) const IMAGE_TLS_DIRECTORY *const _include_tls_used = &_tls_used;
