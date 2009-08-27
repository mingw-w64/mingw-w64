#define __USE_MINGW_ANSI_STDIO
#include <stdio.h>
#include <stdint.h>

int main (int argc, char **argv)
{
  printf ("%zd %p\n", (intptr_t) argc, argv[0]);
  fprintf (stdout, "%zd %p\n", (intptr_t) argc, argv[0]);

#include <_mingw_print_push.h>
  printf ("%Id %p\n", (intptr_t) argc, argv[0]);
  fprintf (stdout, "%Id %p\n", (intptr_t) argc, argv[0]);
#include <_mingw_print_pop.h>
  return 0;
}

