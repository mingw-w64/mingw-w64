/* This is simple DLL library which uses mingw cxa dtor TLS callback */

#include <stdio.h>

static int *process_detach_var = NULL;

__attribute__((dllexport))
void set_process_detach_var(int *var)
{
  process_detach_var = var;
}

static void __thiscall mingw_cxa_dtor_tls_callback(void *obj)
{
  if (obj != (void*)42) {
    printf("mingw cxa dtor callback called with wrong obj\n");
    return;
  }
  if (process_detach_var)
    (*process_detach_var)++;
}

/* Register mingw_cxa_dtor_tls_callback as mingw cxa dtor TLS callback */
extern int __mingw_cxa_atexit(void (__thiscall *dtor)(void *obj), void *obj, void *dso);
__attribute__((constructor))
static void register_mingw_cxa_dtor_tls_callback(void)
{
  if (__mingw_cxa_atexit(&mingw_cxa_dtor_tls_callback, (void*)42, NULL) != 0)
    printf("__mingw_cxa_atexit() failed\n");
}
