/* This is simple DLL library which uses cxa dtor TLS callback */

#include <stdio.h>

static int *process_detach_var = NULL;

__attribute__((dllexport))
void set_process_detach_var(int *var)
{
  process_detach_var = var;
}

static void __thiscall cxa_dtor_tls_callback(void *obj)
{
  if (obj != (void*)42) {
    printf("cxa dtor callback called with wrong obj\n");
    return;
  }
  if (process_detach_var)
    (*process_detach_var)++;
}

/* Register cxa_dtor_tls_callback as cxa dtor TLS callback */
extern int __cxa_atexit(void (__thiscall *dtor)(void *obj), void *obj, void *dso);
__attribute__((constructor))
static void register_cxa_dtor_tls_callback(void)
{
  if (__cxa_atexit(&cxa_dtor_tls_callback, (void*)42, NULL) != 0)
    printf("__cxa_atexit() failed\n");
}
