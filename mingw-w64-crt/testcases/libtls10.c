/* This is simple DLL library which uses mingwthr dtor TLS callback */

#include <stdio.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

static int *thread_detach_var = NULL;

__attribute__((dllexport))
void set_thread_detach_var(int *var)
{
  thread_detach_var = var;
}

static void mingwthr_dtor_tls_callback(void *value)
{
  if (value != (void*)42) {
    printf("w64mingwthr dtor callback called with wrong value\n");
    return;
  }
  if (thread_detach_var)
    (*thread_detach_var)++;
}

static DWORD tls_key = TLS_OUT_OF_INDEXES;

/* Register mingwthr_dtor_tls_callback as mingwthr dtor TLS callback */
extern int __mingwthr_key_dtor(DWORD key, void (*dtor)(void *value));
__attribute__((constructor))
static void register_mingwthr_dtor_tls_callback(void)
{
  tls_key = TlsAlloc();
  if (tls_key == TLS_OUT_OF_INDEXES) {
    printf("TlsAlloc() failed\n");
    return;
  }
  if (__mingwthr_key_dtor(tls_key, &mingwthr_dtor_tls_callback) != 0)
    printf("__mingwthr_key_dtor() failed\n");
}

__attribute__((destructor))
static void free_tls_key(void)
{
  TlsFree(tls_key);
  tls_key = TLS_OUT_OF_INDEXES;
}

BOOL WINAPI DllMain(HINSTANCE instance __attribute__((unused)), DWORD reason, LPVOID reserved __attribute__((unused)))
{
  if (reason == DLL_THREAD_ATTACH)
    TlsSetValue(tls_key, (void*)42);
  return TRUE;
}
