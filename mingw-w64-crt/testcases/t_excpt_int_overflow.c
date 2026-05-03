#include <stdio.h>
#include <limits.h>
#include <windows.h>

int main(void)
{
#if defined(__arm__) || defined(__aarch64__) || defined(__arm64ec__)
  puts("Division overflow is ignored on ARM");
  return 77;
#else
  SetErrorMode(SetErrorMode(0) | SEM_NOGPFAULTERRORBOX);
  puts("execute: INT_MIN / -1");
  volatile int a = INT_MIN;
  volatile int b = -1;
  volatile int c = a / b;
  (void)c;
  puts("result: FAILED, program continued");
  return 0;
#endif
}
