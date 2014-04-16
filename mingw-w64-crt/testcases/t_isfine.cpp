#include <cstdio>
#include <cstdlib>
#include <math.h>

class f {
public:
  f(float a) { x = a; }
  bool is_finite () const {
    return isfinite (x);
  }
protected:
  float x;
};

int main(int argc,char **argv)
{
  f m((float) argc);
  if (!m.is_finite ())
   abort ();
  return 0;
}
