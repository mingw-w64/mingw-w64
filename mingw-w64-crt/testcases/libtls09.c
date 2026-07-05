/* This is simple DLL library which uses mingw cxa thread dtor TLS callback */

#include <stdio.h>

static int *process_or_thread_detach_var = NULL;

__attribute__((dllexport))
void set_process_or_thread_detach_var(int *var)
{
  process_or_thread_detach_var = var;
}

static void __thiscall oneshot_mingw_cxa_thread_dtor_tls_callback(void *obj)
{
  if (obj != (void*)42) {
    printf("mingw cxa thread dtor callback called with wrong obj\n");
    return;
  }
  if (process_or_thread_detach_var)
    (*process_or_thread_detach_var)++;
}

/* Register oneshot_mingw_cxa_thread_dtor_tls_callback as oneshot mingw cxa thread dtor TLS callback */
extern int __mingw_cxa_thread_atexit(void (__thiscall *dtor)(void *obj), void *obj, void *dso);
__attribute__((dllexport))
int register_thread_detach_for_current_thread(void)
{
  return __mingw_cxa_thread_atexit(&oneshot_mingw_cxa_thread_dtor_tls_callback, (void*)42, NULL);
}
