/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

int __cdecl atexit (void (__cdecl *)(void));
void __cdecl __mingw_do_global_dtors (void);
void __cdecl __mingw_do_global_ctors (void);
void __main (void);

__attribute__((used)) /* required for gcc -flto -Ofast */
void
__main (void)
{
  /* gcc during compilation of function named main() (but not wmain() or
   * DllMain()) inserts at the beginning of the execution a call to the
   * function __main(). gcc expects that the function __main() will execute
   * all global C++ constructors which are emitted by gcc itself.
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
   * Both functions __mingw_do_global_ctors() and __mingw_do_global_dtors()
   * contain guards to prevent duplicate execution, so we can call them
   * here without any checks unconditionally.
   */
  __mingw_do_global_ctors ();
  atexit (__mingw_do_global_dtors);
}
