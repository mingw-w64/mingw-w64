#include <stdio.h>
#include <setjmp.h>
#include <signal.h>
#include <assert.h>
#include <limits.h>

static jmp_buf buf;

static void __attribute__((noreturn)) catch_sigfpe(int signum)
{
  printf("SIGFPE exception caught\n");
  assert(signum == SIGFPE);
  longjmp(buf, 1);
}

int main(void)
{
#if defined(__arm__) || defined(__aarch64__) || defined(__arm64ec__)
  puts("Division overflow is ignored on ARM");
  return 77;
#else
  signal(SIGFPE, catch_sigfpe);
  if (!setjmp(buf))
  {
    puts("execute: INT_MIN/-1");
    volatile int a = INT_MIN;
    volatile int b = -1;
    volatile int c = a / b;
    (void)c;
    puts("FAILED, program continued");
    return 1;
  }
  puts("PASSED, program recovered");
  return 0;
#endif
}
