#include <windows.h>
#include <math.h>
#include <stdio.h>

typedef double (*my_pow)(double, double);

static my_pow fpow = pow;

static void set_pow_msvcrt(void)
{
  HMODULE hMod = LoadLibrary ("msvcrt.dll");
  fpow = (my_pow) GetProcAddress (hMod, "pow");
}

static void test(int cnt)
{
  double x, y, z;
  unsigned int tiS = GetTickCount();
  x = 1.0;
  y = 1.0;
  z = 0.0;
  while (cnt > 0)
  {
   x += 0.01;
   y -= 0.01;
   z += (*fpow)(x, y);
   --cnt;
  }
  printf ("Rslt: %g, %u ms\n", z, GetTickCount () - tiS);
}

int main (int argc, char **argv)
{
  int e = (argc > 1 ? atoi(argv[1]) : 20000000);
  test (e);
  set_pow_msvcrt ();
  test (e);
  return 0;
}

