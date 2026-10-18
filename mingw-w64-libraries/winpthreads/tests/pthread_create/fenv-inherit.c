/*
   Copyright (c) 2026 mingw-w64 project

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
*/

#define _GNU_SOURCE /* for feenableexcept, fedisableexcept and fegetexcept */
#include <fenv.h>
#include <string.h>

#include "test.h"

/**
 * Test Summary:
 *
 * POSIX requires a thread created by `pthread_create` to inherit the
 * floating-point environment of the creating thread. Windows starts every
 * thread with its own defaults, so check that the rounding mode, enabled
 * exceptions and raised exception flags reach the new thread, and on x86
 * also the x87 precision control and the MXCSR flush-to-zero and
 * denormals-are-zero bits.
 */

#if defined(__i386__) || (defined(__x86_64__) && !defined(__arm64ec__))
#define TEST_X86 1

#if defined(__i386__) && !defined(__SSE__)
int __mingw_has_sse (void);
#define has_sse() __mingw_has_sse ()
#else
#define has_sse() 1
#endif

static unsigned short get_x87_cw (void) {
  unsigned short cw;
  __asm__ __volatile__ ("fnstcw %0" : "=m" (cw));
  return cw;
}

static void set_x87_cw (unsigned short cw) {
  __asm__ __volatile__ ("fldcw %0" : : "m" (cw));
}

static unsigned int get_mxcsr (void) {
  unsigned int mxcsr;
  __asm__ __volatile__ ("stmxcsr %0" : "=m" (mxcsr));
  return mxcsr;
}

static void set_mxcsr (unsigned int mxcsr) {
  __asm__ __volatile__ ("ldmxcsr %0" : : "m" (mxcsr));
}
#endif

typedef struct {
  int round;
  int enabled;
  int raised;
#ifdef TEST_X86
  unsigned short x87_cw;
  unsigned int mxcsr;
#endif
} fp_state;

static void get_state (fp_state *s) {
  s->round = fegetround ();
  s->enabled = fegetexcept ();
  s->raised = fetestexcept (FE_ALL_EXCEPT);
#ifdef TEST_X86
  s->x87_cw = get_x87_cw ();
  s->mxcsr = has_sse () ? get_mxcsr () : 0;
#endif
}

static void *child (void *arg) {
  get_state ((fp_state *) arg);
  return NULL;
}

static void *parent (void *arg) {
  pthread_t t;
  assert (pthread_create (&t, NULL, child, arg) == 0);
  assert (pthread_join (t, NULL) == 0);
  return NULL;
}

/* Check that a thread started from the current state, and a thread started by
   that thread, both see the current state. */
static void check_inherited (void) {
  fp_state expected, got;
  pthread_t t;

  get_state (&expected);

  memset (&got, 0xff, sizeof (got));
  assert (pthread_create (&t, NULL, child, &got) == 0);
  assert (pthread_join (t, NULL) == 0);
  assert (got.round == expected.round);
  assert (got.enabled == expected.enabled);
  assert (got.raised == expected.raised);
#ifdef TEST_X86
  assert (got.x87_cw == expected.x87_cw);
  assert (got.mxcsr == expected.mxcsr);
#endif

  memset (&got, 0xff, sizeof (got));
  assert (pthread_create (&t, NULL, parent, &got) == 0);
  assert (pthread_join (t, NULL) == 0);
  assert (got.round == expected.round);
  assert (got.enabled == expected.enabled);
  assert (got.raised == expected.raised);
#ifdef TEST_X86
  assert (got.x87_cw == expected.x87_cw);
  assert (got.mxcsr == expected.mxcsr);
#endif
}

int main (void) {
  fenv_t saved;
  static const int rounding[] = { FE_TONEAREST, FE_UPWARD, FE_DOWNWARD, FE_TOWARDZERO };
  size_t i;

  assert (fegetenv (&saved) == 0);

  /**
   * The default environment.
   */
  check_inherited ();

  /**
   * Each rounding mode.
   */
  for (i = 0; i < sizeof (rounding) / sizeof (rounding[0]); i++) {
    assert (fesetround (rounding[i]) == 0);
    check_inherited ();
  }
  assert (fesetround (FE_TONEAREST) == 0);

  /**
   * An enabled (unmasked) exception. No floating-point operations are done
   * while it is enabled.
   */
  assert (feenableexcept (FE_DIVBYZERO) != -1);
  check_inherited ();
  assert (fedisableexcept (FE_DIVBYZERO) != -1);

  /**
   * Raised exception flags.
   */
  assert (feraiseexcept (FE_INEXACT | FE_OVERFLOW) == 0);
  check_inherited ();
  assert (feclearexcept (FE_ALL_EXCEPT) == 0);

#ifdef TEST_X86
  /**
   * x87 precision control: 24-bit and 53-bit.
   */
  set_x87_cw ((get_x87_cw () & ~0x0300) | 0x0000);
  check_inherited ();
  set_x87_cw ((get_x87_cw () & ~0x0300) | 0x0200);
  check_inherited ();
  set_x87_cw ((get_x87_cw () & ~0x0300) | 0x0300);

  /**
   * MXCSR flush-to-zero and denormals-are-zero.
   */
  if (has_sse ()) {
    set_mxcsr (get_mxcsr () | 0x8040);
    check_inherited ();
    set_mxcsr (get_mxcsr () & ~0x8040);
  }
#endif

  assert (fesetenv (&saved) == 0);

  return 0;
}
