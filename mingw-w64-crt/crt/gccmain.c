/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <windows.h>
#include <stdlib.h>
#include <setjmp.h>

typedef void (*func_ptr) (void);
extern func_ptr __CTOR_LIST__[];
extern func_ptr __DTOR_LIST__[];

void __do_global_dtors (void);
void __do_global_ctors (void);
void __main (void);

void
__do_global_dtors (void)
{
  static func_ptr *p = __DTOR_LIST__ + 1;

  while (*p)
    {
      /* If the linker provided its own __DTOR_LIST__ in addition to the
       * one we provide, we'd end up with the first pointer here being
       * a (func_ptr)-1 sentinel. */
      if (*p != (func_ptr) -1)
        (*(p)) ();
      p++;
    }
}

extern func_ptr __CTOR_END__[];
extern func_ptr __DTOR_END__[];

void __do_global_ctors (void)
{
  static func_ptr *p = __CTOR_END__ - 1;
  /* If the linker provided its own __CTOR_LIST__ in addition to the one
   * we provide, we'd actually stop at __CTOR_LIST__+1, but that's no problem
   * for this function. */
  while (*p != (func_ptr) -1) {
    /* In case there's an extra null pointer at the end before __CTOR_END__,
     * check the pointer value before calling it. */
    if (*p)
      (*(p))();
    p--;
  }
  atexit (__do_global_dtors);
}

static int initialized = 0;

void
__main (void)
{
  if (!initialized)
    {
      initialized = 1;
      __do_global_ctors ();
    }
}
