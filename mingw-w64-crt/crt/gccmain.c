/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <windows.h>
#include <stdlib.h>
#include <setjmp.h>

typedef void (*func_ptr) (void);
#define STATIC static

STATIC func_ptr __MINGW_CTOR_LIST__[1]
  __attribute__ ((__used__, section(".ctors"), aligned(sizeof(func_ptr))))
  = { (func_ptr) (-1) };

STATIC func_ptr __MINGW_DTOR_LIST__[1]
  __attribute__((section(".dtors"), aligned(sizeof(func_ptr))))
  = { (func_ptr) (-1) };

void __do_global_dtors (void);
void __do_global_ctors (void);
void __main (void);

void
__do_global_dtors (void)
{
  static func_ptr *p = __MINGW_DTOR_LIST__ + 1;

  while (*p)
    {
      (*(p)) ();
      p++;
    }
}

void
__do_global_ctors (void)
{
  unsigned long nptrs = (unsigned long) (ptrdiff_t) __MINGW_CTOR_LIST__[0];
  unsigned long i;

  if (nptrs == (unsigned long) -1)
    {
      for (nptrs = 0; __MINGW_CTOR_LIST__[nptrs + 1] != 0; nptrs++);
    }

  for (i = nptrs; i >= 1; i--)
    {
      __MINGW_CTOR_LIST__[i] ();
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
