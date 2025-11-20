#include <stdio.h>
#include <setjmp.h>
#include <signal.h>

jmp_buf buf;

void __attribute__((noreturn)) catchSigSegV( int sig )
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
 (void)v;
 return 0;
}
