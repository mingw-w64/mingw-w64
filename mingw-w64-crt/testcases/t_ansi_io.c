#define __USE_MINGW_ANSI_STDIO 1
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

/* mingw-w64 headers */
#include "libtest.h"

int main (int argc, char **argv)
{
  mingw_test_init ();

  printf ("%zd %p\n", (intptr_t) argc, argv[0]);
  fprintf (stdout, "%zd %p %" PRIuPTR "\n", (intptr_t) argc, argv[0], (intptr_t) argv[0]);

  printf ("%Id %p\n", (intptr_t) argc, argv[0]);
  fprintf (stdout, "%Id %p %" PRIuPTR "\n", (intptr_t) argc, argv[0], (intptr_t) argv[0]);

  return 0;
}
