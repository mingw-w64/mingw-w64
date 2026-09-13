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

extern int __cdecl __tlregdtor(void (__cdecl*func)(void));

/* Tentative symbol __mingw_register_thread_local_exe_atexit_callback_ptr is
 * mingw-w64 internal symbol only for EXE applications. It is non-NULL if the
 * EXE application is using __tlregdtor.
 */
void (__cdecl *const __mingw_register_thread_local_exe_atexit_callback_ptr)(void) __attribute__((common)); /* tentative */

static int thread_dtor_counter = 0;
static int process_dtor_counter = 0;

static void __cdecl thread_dtor_callback(void)
{
  thread_dtor_counter++;
}

static void __cdecl process_dtor_callback(void)
{
  if (process_dtor_counter != 0) {
    printf("Error after main: dtor TLS callback on main process thread was called more times\n");
    /* exit, _exit, or ExitProcess calls TLS callbacks, so use TerminateProcess() which is not calling them */
    TerminateProcess(GetCurrentProcess(), 1);
  }
  process_dtor_counter++;
}

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static DWORD WINAPI thread_main(LPVOID user_data __attribute__((unused)))
{
  /* Register thread_dtor_callback as oneshot dtor TLS callback */
  if (__tlregdtor(&thread_dtor_callback) != 0) {
    printf("Error: __tlregdtor() on second thread failed\n");
    return 1;
  }
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

  if (!__mingw_register_thread_local_exe_atexit_callback_ptr) {
    printf("Error: __mingw_register_thread_local_exe_atexit_callback_ptr is NULL\n");
    ret = 1;
  }

  if (_osplatform == VER_PLATFORM_WIN32_WINDOWS) {
    printf("PE TLS callbacks are not supported on Win9x\n");
    if (ret)
      return ret;
    return 77;
  }

  /* Register process_dtor_callback as oneshot dtor TLS callback */
  if (__tlregdtor(&process_dtor_callback) != 0) {
    printf("Error: __tlregdtor() on main process thread failed\n");
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

    if (thread_dtor_counter != 1) {
      printf("Error: dtor TLS callback on second thread was not called\n");
      ret = 1;
    } else {
      printf("dtor TLS callback on second thread was called\n");
    }
  }

  if (process_dtor_counter != 0) {
    printf("Error: dtor TLS callback on main process thread was called before exiting process\n");
    ret = 1;
  }

  if (ret) printf("FAILED\n"); else printf("PASSED\n");
  return ret;
}
