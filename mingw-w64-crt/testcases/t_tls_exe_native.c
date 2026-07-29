#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

/* mingw-w64 headers */
#include "libtest.h"

static int process_attach = 0;
static int thread_attach = 0;
static int process_detach = 0;
static int thread_detach = 0;

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
    process_detach++;
  } else if (reason == DLL_THREAD_DETACH) {
    thread_detach++;
  }
}

/* Register pe_tls_callback as PE TLS callback with the highest priority (=B) */
static __attribute__((section(".CRT$XLB"), used)) const PIMAGE_TLS_CALLBACK register_pe_tls_callback = pe_tls_callback;

/* Force tlssup.c (_tls_used symbol for .tls linker section) to be linked */
extern const IMAGE_TLS_DIRECTORY _tls_used;
static __attribute__((destructor)) void _include_tls_used(void) { asm volatile ("" :: "r" (&_tls_used)); }

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

  /* Asserts that PE image is valid for parsing DataDirectory[] */
  extern IMAGE_DOS_HEADER __ImageBase;
  assert(__ImageBase.e_magic == IMAGE_DOS_SIGNATURE);
  IMAGE_NT_HEADERS *nt_headers = (IMAGE_NT_HEADERS *)((BYTE *)&__ImageBase + __ImageBase.e_lfanew);
  assert(nt_headers->Signature == IMAGE_NT_SIGNATURE);
  assert(nt_headers->FileHeader.SizeOfOptionalHeader >= offsetof(IMAGE_OPTIONAL_HEADER, DataDirectory));
  assert(nt_headers->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR_MAGIC);
  assert(nt_headers->FileHeader.SizeOfOptionalHeader >= offsetof(IMAGE_OPTIONAL_HEADER, DataDirectory[nt_headers->OptionalHeader.NumberOfRvaAndSizes]));

  int ret = 0;

  if (nt_headers->OptionalHeader.NumberOfRvaAndSizes <= IMAGE_DIRECTORY_ENTRY_TLS ||
      nt_headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].Size == 0 ||
      nt_headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].VirtualAddress == 0) {
    printf("Error: Missing PE TLS section\n");
    ret = 1;
  } else {
    printf("PE TLS section is present\n");
  }

  if (_osplatform == VER_PLATFORM_WIN32_WINDOWS) {
    printf("PE TLS callbacks are not supported on Win9x\n");
    if (ret)
      return ret;
    return 77;
  }

  if (process_attach != 1) {
    printf("Error: PE TLS callback for DLL_PROCESS_ATTACH was not called\n");
    ret = 1;
  } else {
    printf("PE TLS callback for DLL_PROCESS_ATTACH was called\n");
  }

  if (thread_attach != 0) {
    printf("Error: PE TLS callback for DLL_THREAD_ATTACH was called without spawning thread\n");
    ret = 1;
  }

  if (thread_detach != 0) {
    printf("Error: PE TLS callback for DLL_THREAD_DETACH was called without spawning thread\n");
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

    if (thread_attach != 1) {
      printf("Error: PE TLS callback for DLL_THREAD_ATTACH was not called\n");
      ret = 1;
    } else {
      printf("PE TLS callback for DLL_THREAD_ATTACH was called\n");
    }

    if (thread_detach != 1) {
      printf("Error: PE TLS callback for DLL_THREAD_DETACH was not called\n");
      ret = 1;
    } else {
      printf("PE TLS callback for DLL_THREAD_DETACH was called\n");
    }
  }

  if (ret) printf("FAILED\n"); else printf("PASSED\n");
  return ret;
}
