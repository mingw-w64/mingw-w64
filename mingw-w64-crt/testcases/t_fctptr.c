#include <assert.h>
#include <stdlib.h>

/* mingw-w64 headers */
#include "libtest.h"

void (__cdecl *exit_ptr)(int) = exit;

int main()
{
  mingw_test_init ();
  assert (exit_ptr != NULL);
  exit_ptr (EXIT_SUCCESS);
  _exit (EXIT_FAILURE);
}
