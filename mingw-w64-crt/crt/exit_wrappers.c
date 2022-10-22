/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>
#ifdef __USING_MCFGTHREAD__
#include <mcfgthread/exit.h>
#include <mcfgthread/cxa.h>
#endif

/* `exit()`, C89  */
void exit(int status) __attribute__((__noreturn__));
extern void (*__MINGW_IMP_SYMBOL(exit))(int) __attribute__((__noreturn__));

void exit(int status)
{
#ifdef __USING_MCFGTHREAD__
  __MCF_exit(status);
#else
  (*__MINGW_IMP_SYMBOL(exit))(status);
#endif
}

/* `_exit()`, POSIX  */
void _exit(int status) __attribute__((__noreturn__));
extern void (*__MINGW_IMP_SYMBOL(_exit))(int) __attribute__((__noreturn__));

void _exit(int status)
{
#ifdef __USING_MCFGTHREAD__
  __MCF__Exit(status);
#else
  (*__MINGW_IMP_SYMBOL(_exit))(status);
#endif
}

#ifdef __USING_MCFGTHREAD__
/* `at_quick_exit()`, C99  */
typedef void (__cdecl *_PVFV)(void);
int at_quick_exit(_PVFV func);

typedef void* HANDLE;
extern HANDLE __dso_handle;

int at_quick_exit(_PVFV func)
{
  return __MCF_cxa_at_quick_exit ((__MCF_cxa_dtor_cdecl*)(intptr_t) func, NULL, &__dso_handle);
}
#endif  /* __USING_MCFGTHREAD__  */
