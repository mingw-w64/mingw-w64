#define _GNU_SOURCE /* for feenableexcept and fegetexcept */
#include <fenv.h>
#include <stdio.h>

/* mingw-w64 headers */
#include "libtest.h"

#if defined(__i386__) || (defined(__x86_64__) && !defined(__arm64ec__))
#define TEST_X86 1

#if defined(__i386__) && !defined(__SSE__)
int __mingw_has_sse(void);
#define has_sse() __mingw_has_sse()
#else
#define has_sse() 1
#endif

static unsigned short get_x87_cw(void)
{
  unsigned short cw;
  __asm__ __volatile__ ("fnstcw %0" : "=m" (cw));
  return cw;
}

static void set_x87_cw(unsigned short cw)
{
  __asm__ __volatile__ ("fldcw %0" : : "m" (cw));
}

static unsigned int get_mxcsr(void)
{
  unsigned int mxcsr;
  __asm__ __volatile__ ("stmxcsr %0" : "=m" (mxcsr));
  return mxcsr;
}

static void set_mxcsr(unsigned int mxcsr)
{
  __asm__ __volatile__ ("ldmxcsr %0" : : "m" (mxcsr));
}
#endif

static int failed;

#define CHECK(cond) do { \
    if (!(cond)) { \
      failed = 1; \
      printf("%s:%d: check failed: %s\n", __FILE__, __LINE__, #cond); \
    } \
  } while (0)

/* Move every part of the environment away from its default. */
static void change_environment(void)
{
  CHECK(fesetround(FE_TOWARDZERO) == 0);
  CHECK(feenableexcept(FE_DIVBYZERO | FE_INVALID) != -1);
  CHECK(feraiseexcept(FE_INEXACT) == 0);
#ifdef TEST_X86
  /* 24-bit x87 precision. */
  set_x87_cw(get_x87_cw() & ~0x0300);
  /* SSE flush-to-zero, denormals-are-zero and a raised overflow flag. */
  if (has_sse())
    set_mxcsr(get_mxcsr() | 0x8040 | 0x0008);
#endif
}

/* Check that the environment is the one set at program startup. */
static void check_default_environment(void)
{
  CHECK(fegetround() == FE_TONEAREST);
  CHECK(fegetexcept() == 0);
  CHECK(fetestexcept(FE_ALL_EXCEPT) == 0);
#ifdef TEST_X86
  CHECK(get_x87_cw() == 0x037f);
  if (has_sse())
    CHECK(get_mxcsr() == 0x1f80);
#endif
}

int main()
{
  mingw_test_init();

  /* fesetenv(FE_DFL_ENV) restores the startup environment of both the x87
     and the SSE unit. */
  change_environment();
  CHECK(fesetenv(FE_DFL_ENV) == 0);
  check_default_environment();

#ifdef TEST_X86
  /* An environment with every exception unmasked, 64-bit precision and round
     to nearest encodes as { 0, 0 }.  Saving and restoring it must not reset
     it to FE_DFL_ENV.  The results are read before checking them so that no
     floating-point operation runs while exceptions are unmasked. */
  {
    fenv_t env;
    unsigned short cw = (get_x87_cw() & ~0x0f3f) | 0x0300;
    unsigned short got_cw;
    unsigned int got_mxcsr = 0;
    int ret1, ret2, ret3;

    set_x87_cw(cw);
    if (has_sse())
      set_mxcsr(0);
    ret1 = fegetenv(&env);
    ret2 = fesetenv(FE_DFL_ENV);
    ret3 = fesetenv(&env);
    got_cw = get_x87_cw();
    if (has_sse())
      got_mxcsr = get_mxcsr();
    fesetenv(FE_DFL_ENV);

    CHECK(ret1 == 0 && ret2 == 0 && ret3 == 0);
    CHECK(got_cw == cw);
    CHECK(got_mxcsr == 0);
  }

  /* A copy of *FE_DFL_ENV selects the startup environment too. */
  {
    fenv_t env = *FE_DFL_ENV;

    change_environment();
    CHECK(fesetenv(&env) == 0);
    check_default_environment();
  }
#endif

  return failed;
}
