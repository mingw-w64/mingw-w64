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

static int process_or_thread_attach = 0;

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static void __cdecl dyn_tls_callback(void)
{
  process_or_thread_attach++;
}

/* Register dyn_tls_callback as CRT dyn TLS callback with the highest priority (=B) */
static __attribute__((section(".CRT$XDB"), used)) void (__cdecl *const register_dyn_tls_callback)(void) = &dyn_tls_callback;

/* Force tlsdyn.c (__dyn_tls_init symbol) to be linked */
extern void WINAPI __dyn_tls_init(HANDLE, DWORD, LPVOID);
static __attribute__((used)) void (WINAPI *const _include_dyn_tls_init)(HANDLE, DWORD, LPVOID) = &__dyn_tls_init;

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

  /* Prevent register_dyn_tls_callback to be garbage collected by the GNU LD --gc-sections switch.
   * Its pointer has to be stored into some volatile variable and then variable to be accessed.
   * This is needed for older GNU LD versions which do not KEEP ".CRT$XD*" sections.
   */
  static void (__cdecl *const *volatile const include_register_dyn_tls_callback)(void) = &register_dyn_tls_callback;
  (void)include_register_dyn_tls_callback;

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

  if (process_or_thread_attach != 1) {
    printf("Error: Dyn TLS callback for DLL_PROCESS_ATTACH was not called\n");
    ret = 1;
  } else {
    printf("Dyn TLS callback for DLL_PROCESS_ATTACH was called\n");
  }

  printf("Creating new thread\n");
  process_or_thread_attach = 0;
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

    if (process_or_thread_attach != 1) {
      printf("Error: Dyn TLS callback for DLL_THREAD_ATTACH was not called\n");
      ret = 1;
    } else {
      printf("Dyn TLS callback for DLL_THREAD_ATTACH was called\n");
    }
  }

  if (ret) printf("FAILED\n"); else printf("PASSED\n");
  return ret;
}
