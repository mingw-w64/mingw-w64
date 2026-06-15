#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

/* mingw-w64 headers */
#include "libtest.h"

#ifndef __MSVCRT_VERSION__
#define __MSVCRT_VERSION__ 0x0000
#endif

#if defined(_UCRT) || __MSVCRT_VERSION__ >= 0x0E00
#define CRT_FILENAME "ucrtbase.dll"
#elif __MSVCRT_VERSION__ >= 0x0C00
#define CRT_FILENAME "msvcr120.dll"
#elif __MSVCRT_VERSION__ >= 0x0B00
#define CRT_FILENAME "msvcr110.dll"
#elif __MSVCRT_VERSION__ >= 0x0A00
#define CRT_FILENAME "msvcr100.dll"
#elif __MSVCRT_VERSION__ >= 0x0900
#define CRT_FILENAME "msvcr90.dll"
#elif __MSVCRT_VERSION__ >= 0x0800
#define CRT_FILENAME "msvcr80.dll"
#elif __MSVCRT_VERSION__ >= 0x0710
#define CRT_FILENAME "msvcr71.dll"
#elif __MSVCRT_VERSION__ >= 0x0700
#define CRT_FILENAME "msvcr70.dll"
#elif __MSVCRT_VERSION__ >= 0x0410
#define CRT_FILENAME "msvcrt.dll"
#elif __MSVCRT_VERSION__ >= 0x0400
#define CRT_FILENAME "msvcrt40.dll"
#elif __MSVCRT_VERSION__ >= 0x0200
#define CRT_FILENAME "msvcrt20.dll"
#elif __MSVCRT_VERSION__ >= 0x0100
#define CRT_FILENAME "msvcrt10.dll"
#else
#define CRT_FILENAME "crtdll.dll"
#endif

/* All CRT functions have __cdecl calling convention */
typedef double (__cdecl *my_pow)(double, double);

/* The `pow` implementation to test */
static my_pow fpow = pow;

/* Set `fpow` to CRT's `pow` */
static void set_pow_crt(void)
{
  my_pow ptr_pow = NULL;
  HMODULE hMod = GetModuleHandleA (CRT_FILENAME);

  if (hMod != NULL) {
    ptr_pow = (my_pow) (UINT_PTR) GetProcAddress (hMod, "pow");
  }

  fpow = ptr_pow;
}

/* `pow` implementation using `exp` and `log` */
static __attribute__((noinline)) double __cdecl pow_by_log_exp (double x, double y)
{
  /* pow(x, n) = exp(n * log(x)) */
  if (x < 0.0)
  {
    long v = (long) y;
    x = exp(y * log (-x));
    if ((double) v == y && (v&1) != 0)
    {
      x = -x;
    }
    return x;
  }
  return exp(y * log(x));
}

static __attribute__((noinline)) void test(int cnt)
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
  int e;

  mingw_test_init ();

  e = (argc > 1 ? atoi(argv[1]) : 20000000);

  /**
   * Test `pow` function in libmingwex.
   */
  printf ("Current implementation in libmingwex: ");
  test (e);
  printf ("pow(-1.0, 2) = %g\n", (*fpow)(-1.0, 2.0));
  printf ("pow(-1.0, 2.2) = %g\n", (*fpow)(-1.0, 2.2));
  printf ("pow(2.0, -1) = %g\n", (*fpow)(2.0,-1.0));

  /**
   * Test `pow` function in CRT.
   */
  set_pow_crt ();
  if (fpow != NULL) {
    printf ("Implementation in "CRT_FILENAME": ");
    test (e);
    printf ("pow(-1.0, 2) = %g\n", (*fpow)(-1.0, 2.0));
    printf ("pow(-1.0, 2.2) = %g\n", (*fpow)(-1.0, 2.2));
    printf ("pow(2.0, -1) = %g\n", (*fpow)(2.0,-1.0));
  }

  /**
   * Test `pow` implementation using `exp` and `log`.
   */
  fpow = pow_by_log_exp;
  printf ("Implementation by exp and log: ");
  test (e);
  printf ("pow(-1.0, 2) = %g\n", (*fpow)(-1.0, 2.0));
  printf ("pow(-1.0, 2.2) = %g\n", (*fpow)(-1.0, 2.2));
  printf ("pow(2.0, -1) = %g\n", (*fpow)(2.0,-1.0));

  return 0;
}
