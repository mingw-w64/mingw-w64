/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdlib.h>
#include <corecrt_startup.h>

static _onexit_table_t atexit_table;

int __cdecl atexit(_PVFV func)
{
  /* Do not use msvcrt's atexit() or UCRT's _crt_atexit() function as it
   * cannot be called from DLL library which may be unloaded at runtime. */
  return _register_onexit_function(&atexit_table, (_onexit_t)func);
}

static int __cdecl __mingw_dll_atexit_table_func(int execute)
{
  if (execute)
    return _execute_onexit_table(&atexit_table);
  else
    return _initialize_onexit_table(&atexit_table);
}

int (__cdecl *const __mingw_dll_atexit_table_func_ptr)(int) = __mingw_dll_atexit_table_func;
