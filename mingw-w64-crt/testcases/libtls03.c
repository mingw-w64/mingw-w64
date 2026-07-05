/* This is simple DLL library which uses CRT dtor TLS callback */

#include <corecrt_startup.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

static int *process_or_thread_detach_var = NULL;

__attribute__((dllexport))
void set_process_or_thread_detach_var(int *var)
{
  process_or_thread_detach_var = var;
}

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static void __cdecl oneshot_dtor_tls_callback(void)
{
  if (process_or_thread_detach_var)
    (*process_or_thread_detach_var)++;
}

/* Register oneshot_dtor_tls_callback as oneshot CRT dtor TLS callback */
extern int __cdecl __tlregdtor(_PVFV func);
__attribute__((dllexport))
int register_thread_detach_for_current_thread(void)
{
  return __tlregdtor(&oneshot_dtor_tls_callback);
}
