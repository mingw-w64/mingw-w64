#include <process.h>
#include <pthread.h>
#include <stdio.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define STATUS_USER_DEFINED     (1U << 29)
#define GCC_MAGIC               (('G' << 16) | ('C' << 8) | 'C')
#define GCC_EXCEPTION(TYPE)     (STATUS_USER_DEFINED | ((TYPE) << 24) | GCC_MAGIC)

#define STATUS_GCC_THROW        GCC_EXCEPTION(0)
#define STATUS_GCC_UNWIND       GCC_EXCEPTION(1)
#define STATUS_GCC_FORCED       GCC_EXCEPTION(2)

static int test(void)
{
  /* Test SEH GCC C++ ABI that raising GCC C++ SEH exceptions do not crash whole process */

  RaiseException(STATUS_GCC_THROW, 0, 0, NULL);
  /* should return back without crashing application */

  RaiseException(STATUS_GCC_FORCED, 0, 0, NULL);
  /* should return back without crashing application */

  UnhandledExceptionFilter(&(EXCEPTION_POINTERS){ &(EXCEPTION_RECORD){ .ExceptionCode = STATUS_GCC_THROW }, NULL });
  /* should return back without crashing application */

  UnhandledExceptionFilter(&(EXCEPTION_POINTERS){ &(EXCEPTION_RECORD){ .ExceptionCode = STATUS_GCC_FORCED }, NULL });
  /* should return back without crashing application */

  return 0;
}

static void *test_from_pthread_create(void *arg __attribute__((unused)))
{
  return (void *)(intptr_t)test();
}

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static DWORD WINAPI test_from_createthread(LPVOID arg __attribute__((unused)))
{
  return test();
}

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static unsigned __stdcall test_from_beginthreadex(void *arg __attribute__((unused)))
{
  return test();
}

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static void __attribute__((noreturn)) __cdecl test_from_beginthread(void *arg __attribute__((unused)))
{
  /* Do not return from _beginthread's startaddress and do not call _endthread()
   * as they invalidate the thread handle returned by _beginthread().
   * The thread handle is used by _beginthread()'s caller which will close it.
   * So the only safe option is to exit this tread via WinAPI ExitThread() function.
   */
  ExitThread(test());
}

int main()
{
  int ret = 0;
  pthread_t pthread;
  HANDLE wthread;

  {
    int tret = test();
    if (tret)
    {
      puts("test in main thread failed");
      ret = 1;
    }
    else
      puts("test in main thread passed");
  }

  /* FIXME: Disable pthread test because mingw-w64-crt/testcases build system does not provide pthread support yet */
#if 0
  if (pthread_create(&pthread, NULL, test_from_pthread_create, NULL) != 0)
  {
    puts("\nfailed to spawn thread via pthread_create()");
    ret = 1;
  }
  else
  {
    void *tret;
    if (pthread_join(pthread, &tret) != 0 || tret)
    {
      puts("test in thread spawned by pthread_create() failed");
      ret = 1;
    }
    else
      puts("test in thread spawned by pthread_create() passed");
  }
#else
  (void)pthread;
#endif

  wthread = CreateThread(NULL, 0, test_from_createthread, NULL, 0, &(DWORD){0} /*out: ThreadId*/);
  if (wthread == NULL)
  {
    puts("failed to spawn thread via CreateThread()");
    ret = 1;
  }
  else
  {
    DWORD tret;
    WaitForSingleObject(wthread, INFINITE);
    GetExitCodeThread(wthread, &tret);
    CloseHandle(wthread);
    if (tret)
    {
      puts("test in thread spawned by CreateThread() failed");
      ret = 1;
    }
    else
      puts("test in thread spawned by CreateThread() passed");
  }

  wthread = (HANDLE)_beginthreadex(NULL, 0, test_from_beginthreadex, NULL, 0, &(unsigned){0} /*out: ThreadId*/);
  if (wthread == NULL)
  {
    puts("failed to spawn thread via _beginthreadex()");
    ret = 1;
  }
  else
  {
    DWORD tret;
    WaitForSingleObject(wthread, INFINITE);
    GetExitCodeThread(wthread, &tret);
    CloseHandle(wthread);
    if (tret)
    {
      puts("test in thread spawned by _beginthreadex() failed");
      ret = 1;
    }
    else
      puts("test in thread spawned by _beginthreadex() passed");
  }

  wthread = (HANDLE)_beginthread(test_from_beginthread, 0, NULL);
  if (wthread == INVALID_HANDLE_VALUE)
  {
    puts("failed to spawn thread via _beginthread()");
    ret = 1;
  }
  else
  {
    DWORD tret;
    WaitForSingleObject(wthread, INFINITE);
    GetExitCodeThread(wthread, &tret);
    CloseHandle(wthread);
    if (tret)
    {
      puts("test in thread spawned by _beginthread() failed");
      ret = 1;
    }
    else
      puts("test in thread spawned by _beginthread() passed");
  }

  return ret;
}
