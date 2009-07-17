#include <stdio.h>
#include <setjmp.h>
#include <signal.h>

jmp_buf buf;

void catchSigSegV( int sig )
{
 longjmp(buf, 1);
}

int *ptr = 0;

int main(void)
{
 volatile int v;
 signal(SIGSEGV, catchSigSegV);
 if (!setjmp(buf))
 {
  puts("Ready to catch");
  v = *ptr;
  puts("Bad");
 }
  else puts("Ok");
 return 0;
}
