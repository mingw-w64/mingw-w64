#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main (int argc, char **argv)
{
  printf ("%zd %p\n", (intptr_t) argc, argv[0]);
  fprintf (stdout, "%zd %p %" PRIuPTR "\n", (intptr_t) argc, argv[0], (intptr_t) argv[0]);

#include <_mingw_print_push.h>
  printf ("%Id %p\n", (intptr_t) argc, argv[0]);
  fprintf (stdout, "%Id %p %" PRIuPTR "\n", (intptr_t) argc, argv[0], (intptr_t) argv[0]);
#include <_mingw_print_pop.h>
  return 0;
}

