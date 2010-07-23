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

static __attribute__((noinline)) double pow_by_log_exp (double x, double y)
{
  /* pow(x, n) = exp(n * log(x)) */
  return exp(y * log(x));
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
  printf ("Current implementation in libmingwex: ");
  test (e);
  set_pow_msvcrt ();
  printf ("Implementation in msvcrt.dll: ");
  test (e);
  fpow = pow_by_log_exp;
  printf ("Implementation by exp and log: ");
  test (e);
  return 0;
}

