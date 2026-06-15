#include <stdio.h>
#include <stdlib.h>

// mingw-w64 headers
#include "libtest.h"

void foo (int d)
{
  throw (d);
}

int main()
{
  mingw_test_init ();

  try {
    foo (10);
    fwprintf (stderr, L"Failed to throw an exception?\n");
    _exit (EXIT_FAILURE);
  } catch (int ex) {
    if (ex != 10) {
      fwprintf (stderr, L"ex=%d\n", ex);
      _exit (EXIT_FAILURE);
    }
  }

  return 0;
}
