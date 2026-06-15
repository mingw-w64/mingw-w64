#include <setjmp.h>
#include <signal.h>
#include <stdio.h>

jmp_buf buf;

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
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
 else
 {
  puts("Ok");
 }

 (void)v;
 return 0;
}
