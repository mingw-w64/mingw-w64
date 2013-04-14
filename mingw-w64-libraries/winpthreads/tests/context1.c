#define _WIN32_WINNT 0x400

#include "test.h"

static int washere = 0;

static void * func(void * arg)
{
  washere = 1;

  Sleep(1000);

  return 0; 
}

static void
anotherEnding ()
{
  /*
   * Switched context
   */
  washere++;

  pthread_exit(0);
}

int
main()
{
  pthread_t t;
  HANDLE hThread;

  assert(pthread_create(&t, NULL, func, NULL) == 0);

  hThread = pthread_gethandle (t);

  Sleep(500);

  SuspendThread(hThread);

  if (WaitForSingleObject(hThread, 0) == WAIT_TIMEOUT) 
    {
      /*
       * Ok, thread did not exit before we got to it.
       */
      CONTEXT context;

      context.ContextFlags = CONTEXT_CONTROL;

      GetThreadContext(hThread, &context);
#ifdef _M_X64
	  context.Rip = (uintptr_t) anotherEnding;
#else
	  context.Eip = (uintptr_t) anotherEnding;
#endif

      SetThreadContext(hThread, &context);
      ResumeThread(hThread);
    }
  else
    {
      printf("Exited early\n");
      fflush(stdout);
    }

  Sleep(1000);

  assert(washere == 2);

  return 0;
}

