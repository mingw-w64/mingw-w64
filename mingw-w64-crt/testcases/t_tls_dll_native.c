#include <stdio.h>
#include <stdlib.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

/* mingw-w64 headers */
#include "libtest.h"

__attribute__((dllimport)) extern int libtlsnat_process_attach;
__attribute__((dllimport)) extern int libtlsnat_thread_attach;
__attribute__((dllimport)) extern int libtlsnat_process_detach;
__attribute__((dllimport)) extern int libtlsnat_thread_detach;

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static DWORD WINAPI thread_main(LPVOID user_data __attribute__((unused)))
{
  return 0;
}

int main(void)
{
  mingw_test_init();

  int ret = 0;

  if (_osplatform == VER_PLATFORM_WIN32_WINDOWS) {
    printf("PE TLS callbacks are not supported on Win9x\n");
    return 77;
  }

  if (libtlsnat_process_attach != 1) {
    printf("Error: PE TLS callback in libtlsnat.dll for DLL_PROCESS_ATTACH was not called\n");
    ret = 1;
  } else {
    printf("PE TLS callback in libtlsnat.dll for DLL_PROCESS_ATTACH was called\n");
  }

  if (libtlsnat_thread_attach != 0) {
    printf("Error: PE TLS callback in libtlsnat.dll for DLL_THREAD_ATTACH was called without spawning thread\n");
    ret = 1;
  }

  if (libtlsnat_thread_detach != 0) {
    printf("Error: PE TLS callback in libtlsnat.dll for DLL_THREAD_DETACH was called without spawning thread\n");
    ret = 1;
  }

  printf("Creating new thread\n");
  HANDLE thread = CreateThread(NULL, 0, thread_main, NULL, 0, &(DWORD){0} /*out: ThreadId*/);
  if (!thread) {
    if (GetLastError() != ERROR_CALL_NOT_IMPLEMENTED) {
      printf("Error: failed: %lu\n", GetLastError());
      ret = 1;
    } else {
      printf("Skipped: not supported\n");
    }
  } else {
    DWORD tret;
    WaitForSingleObject(thread, INFINITE);
    GetExitCodeThread(thread, &tret);
    CloseHandle(thread);
    if (tret) {
      printf("Error: thread failed\n");
      ret = 1;
    }

    if (libtlsnat_thread_attach != 1) {
      printf("Error: PE TLS callback in libtlsnat.dll for DLL_THREAD_ATTACH was not called\n");
      ret = 1;
    } else {
      printf("PE TLS callback in libtlsnat.dll for DLL_THREAD_ATTACH was called\n");
    }

    if (libtlsnat_thread_detach != 1) {
      printf("Error: PE TLS callback in libtlsnat.dll for DLL_THREAD_DETACH was not called\n");
      ret = 1;
    } else {
      printf("PE TLS callback in libtlsnat.dll for DLL_THREAD_DETACH was called\n");
    }
  }

  if (libtlsnat_process_detach != 0) {
    printf("Error: PE TLS callback in libtlsnat.dll for DLL_PROCESS_DETACH was called before exiting process\n");
    ret = 1;
  }

  if (ret) printf("FAILED\n"); else printf("PASSED\n");
  return ret;
}
