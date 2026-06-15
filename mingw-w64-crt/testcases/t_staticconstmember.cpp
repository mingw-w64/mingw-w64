#include <stdio.h>

// mingw-w64 headers
#include "libtest.h"

struct Foobar {
  static const double var;
};

const double Foobar::var = 1.0;

int main()
{
  mingw_test_init ();

  const char *ptr = (const char *) (&Foobar::var);

  for (int i = 0; i < 8; ++i) {
    if (i) {
      fprintf(stderr, ".");
    }

    fprintf(stderr, "%.2x", 0xFF & ptr[i]);
  }

  fprintf(stderr, " => %g : %g\n", Foobar::var, *((double*)ptr));

  return 0;
}
