#include <cstdio>
#include <cstdlib>
#include <math.h>

// mingw-w64 headers
#include "libtest.h"

class f {
public:
  f(float a) { x = a; }
  bool is_finite () const {
    return isfinite (x);
  }
protected:
  float x;
};

int main(int argc, char **argv)
{
  mingw_test_init ();

  f m((float) argc);

  if (!m.is_finite ())
    abort ();

  return 0;
}
