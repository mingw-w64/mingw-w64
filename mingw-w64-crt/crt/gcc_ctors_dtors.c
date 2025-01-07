/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

typedef void (*func_ptr) (void);
extern func_ptr __CTOR_LIST__[];
extern func_ptr __DTOR_LIST__[];

void __cdecl __mingw_do_global_dtors (void);
void __cdecl __mingw_do_global_ctors (void);

void __cdecl
__mingw_do_global_dtors (void)
{
  /* static initialization ensures that repeated calls
   * to __mingw_do_global_dtors() will not invoke dtors
   * functions more times
   */
  static func_ptr *p = __DTOR_LIST__ + 1;

  while (*p)
    {
      (*(p)) ();
      p++;
    }
}

void __cdecl
__mingw_do_global_ctors (void)
{
  static int called = 0;
  unsigned long nptrs = (unsigned long) (__UINTPTR_TYPE__) __CTOR_LIST__[0];
  unsigned long i;

  if (called)
    return;

  if (nptrs == (unsigned long) -1)
    {
      for (nptrs = 0; __CTOR_LIST__[nptrs + 1] != 0; nptrs++);
    }

  for (i = nptrs; i >= 1; i--)
    {
      __CTOR_LIST__[i] ();
    }

  called = 1;
}
