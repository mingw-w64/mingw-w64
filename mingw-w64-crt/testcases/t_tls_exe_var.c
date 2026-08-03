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

#include "../include/thread_local.h"

static int *get_thread_local_int(void)
{
  /* PE TLS variables in main EXE file are working on all Windows versions, so this function must not return NULL */
  return __MINGW_ALLOC_THREAD_LOCAL_OR_NULL(int, = 42);
}

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static DWORD WINAPI thread_main(LPVOID user_data)
{
  printf("Assert PE TLS variable for second thread\n");

  /* Check main thread local value */
  int *main_thread_local_int = user_data;
  assert(*main_thread_local_int == 10);
  *main_thread_local_int = 11;

  /* Check for default thread local value for current (second) thread */
  int *second_thread_local_int = get_thread_local_int();
  assert(second_thread_local_int != NULL);
  assert(*second_thread_local_int == 42);

  /* Changing second thread local value must not change main thread local value */
  *second_thread_local_int = 47;
  assert(*main_thread_local_int == 11);

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

  if (nt_headers->OptionalHeader.NumberOfRvaAndSizes <= IMAGE_DIRECTORY_ENTRY_TLS ||
      nt_headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].Size == 0 ||
      nt_headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].VirtualAddress == 0) {
    printf("Error: Missing PE TLS section\n");
    return 1;
  } else {
    printf("PE TLS section is present\n");
  }

  printf("Assert PE TLS variable for main thread\n");
  int *main_thread_local_int = get_thread_local_int();
  assert(main_thread_local_int != NULL);
  assert(*main_thread_local_int == 42);

  /* Change main thread local value, it must not affect values if other threads or default value */
  *main_thread_local_int = 10;

  printf("Creating new thread\n");
  HANDLE thread = CreateThread(NULL, 0, thread_main, main_thread_local_int, 0, &(DWORD){0} /*out: ThreadId*/);
  if (!thread) {
    if (GetLastError() != ERROR_CALL_NOT_IMPLEMENTED) {
      printf("Error: failed: %lu\n", GetLastError());
      return 1;
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
      return 1;
    }
  }

  printf("PASSED\n");
  return 0;
}
