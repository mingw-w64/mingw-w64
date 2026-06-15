#include <limits.h>
#include <process.h>
#include <stdio.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

/* This test is run as XFAIL, so it has to return non-zero on success (as the crash is expected) and zero on error */
#define FAILURE 0

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static unsigned __stdcall test(void *arg __attribute__((unused)))
{
  puts("execute: INT_MIN / -1");
  volatile int a = INT_MIN;
  volatile int b = -1;
  volatile int c = a / b;
  printf("result: FAILED, program continued, result is: %d\n", c);
  return FAILURE;
}

int main(void)
{
#if defined(__arm__) || defined(__aarch64__) || defined(__arm64ec__)
  puts("Division overflow is ignored on ARM");
  return 77;
#endif
  SetErrorMode(SetErrorMode(0) | SEM_NOGPFAULTERRORBOX);
#ifdef RUN_TEST_IN_THREAD
  HANDLE thread = (HANDLE)_beginthreadex(NULL, 0, test, NULL, 0, &(unsigned){0} /*out: ThreadId*/);
  if (!thread)
  {
    puts("failed to spawn thread");
    return FAILURE;
  }
  DWORD ret;
  WaitForSingleObject(thread, INFINITE);
  GetExitCodeThread(thread, &ret);
  CloseHandle(thread);
  return ret;
#else
  return test(NULL);
#endif
}
