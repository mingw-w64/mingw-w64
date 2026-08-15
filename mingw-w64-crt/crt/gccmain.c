/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

int __cdecl atexit (void (__cdecl *)(void));
typedef void (*func_ptr) (void);
extern func_ptr __CTOR_LIST__[];
extern func_ptr __DTOR_LIST__[];

/* WARNING: All these functions must be in one translation unit.
 * Otherwise linker can throw error "multiple definitions of __do_global_dtors"
 * when linking with static libgcc library which also provides these symbols.
 */
void __do_global_dtors (void);
void __do_global_ctors (void);
void __main (void);

/* __do_global_dtors is gcc ABI function which has to be exported.
 * It executes all gcc dtors from __DTOR_LIST__ list under guard
 * which prevents duplicate execution.
 *
 * Same implementation of this __do_global_dtors function is provided also by
 * the static libgcc library. They are interchangeable and EXE application can
 * link to any of them.
 *
 * To prevent duplicate execution of __DTOR_LIST__ in EXE application,
 * only this function with __do_global_dtors name should execute functions
 * in the __DTOR_LIST__ list.
 *
 * WARNING: Do not change ABI, name or behavior of this function.
 */
void
__do_global_dtors (void)
{
  /* static initialization and incrementation before invocation of dtor
   * ensures that repeated calls to __do_global_dtors() will not invoke
   * any dtor function more times
   */
  static func_ptr *p = __DTOR_LIST__ + 1;

  while (*p)
    {
      p++;
      (*(p-1)) ();
    }
}

/* __do_global_ctors is gcc ABI function which has to be exported.
 * It executes all gcc ctors from __CTOR_LIST__ list and schedules execution
 * of __do_global_dtors via atexit(). If it is called multiple times then gcc
 * ctors are executed multiple times but gcc dtors are executed only once.
 * This is because __do_global_dtors contains guard which prevents executing
 * dtors multiple times, even if registration of __do_global_dtors is done
 * multiple times.
 *
 * Same implementation of this __do_global_ctors function is provided also by
 * the static libgcc library. They are interchangeable and EXE application can
 * link to any of them.
 *
 * WARNING: Do not change ABI, name or behavior of this function.
 */
void
__do_global_ctors (void)
{
  __SIZE_TYPE__ nptrs = (__SIZE_TYPE__) __CTOR_LIST__[0];
  __SIZE_TYPE__ i;

  if (nptrs == (__SIZE_TYPE__) -1)
    {
      for (nptrs = 0; __CTOR_LIST__[nptrs + 1] != 0; nptrs++);
    }

  for (i = nptrs; i >= 1; i--)
    {
      __CTOR_LIST__[i] ();
    }

  atexit (__do_global_dtors);
}

/* __main is gcc ABI function which has to be exported.
 * It calls __do_global_ctors function under the guard.
 *
 * Same implementation of this __main function is provided also by
 * the static libgcc library. They are interchangeable and EXE application can
 * link to any of them.
 *
 * WARNING: Do not change ABI, name or behavior of this function.
 */
__attribute__((used)) /* required for gcc -flto -Ofast */
void
__main (void)
{
  /* gcc during compilation of function named main() (but not wmain() or
   * DllMain()) inserts at the beginning of the execution a call to the
   * function __main(). gcc expects that the function __main() will execute
   * all global C++ constructors which are emitted by gcc itself and will
   * schedule calls for global C++ destructors.
   *
   * mingw-w64 runtime executes all gcc's global C++ constructors in mingw-w64
   * startup code (in crtdll.c and crtexe.c) before executing function main(),
   * wmain() or DllMain().
   *
   * So the function __main() should expects that constructors were already
   * called and must prevent multiple execution of them.
   *
   * Also application or DLL library can be build with the custom entry point
   * which does not call mingw-w64 startup code but calls this __main() function
   * manually and therefore this __main() function has to execute all global
   * C++ constructors and has to schedule calls for global C++ destructors.
   *
   * gcc ABI function __do_global_ctors() do that: execute all global C++
   * constructors and has to schedule calls for global C++ destructors.
   * But it does not contain guard to prevent duplicate execution. On the other
   * hand, gcc ABI function __main() can be called multiple times and will not
   * call constructors or destructor multiple times. So call __do_global_ctors()
   * under own guard.
   */
  static int initialized = 0;
  if (!initialized)
    {
      initialized = 1;
      __do_global_ctors ();
    }
}
