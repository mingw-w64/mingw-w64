/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Winline"
#endif

#undef __MSVCRT_VERSION__
#define __MSVCRT_VERSION__ 0x1400

#define fwprintf real_fwprintf
#define _snwprintf real__snwprintf
#define __getmainargs crtimp___getmainargs
#define __wgetmainargs crtimp___wgetmainargs
#define _amsg_exit crtimp__amsg_exit
#define _get_output_format crtimp__get_output_format

#include <internal.h>
#include <sect_attribs.h>
#include <stdio.h>
#include <time.h>

#undef fwprintf
#undef _snwprintf
#undef __getmainargs
#undef __wgetmainargs
#undef _amsg_exit
#undef _get_output_format



// Declarations of non-static functions implemented within this file (that aren't
// declared in any of the included headers, and that isn't mapped away with a define
// to get rid of the _CRTIMP in headers).
int __cdecl __getmainargs(int * _Argc, char *** _Argv, char ***_Env, int _DoWildCard, _startupinfo *_StartInfo);
int __cdecl __wgetmainargs(int * _Argc, wchar_t *** _Argv, wchar_t ***_Env, int _DoWildCard, _startupinfo *_StartInfo);
void __cdecl _amsg_exit(int ret);
unsigned int __cdecl _get_output_format(void);

void __cdecl _lock(int _File);
void __cdecl _unlock(int _File);
_onexit_t __dllonexit(_onexit_t func, _PVFV** begin, _PVFV** end);

int __cdecl fwprintf(FILE *ptr, const wchar_t *fmt, ...);
int __cdecl _snwprintf(wchar_t * restrict _Dest, size_t _Count, const wchar_t * restrict _Format, ...);

int __cdecl __ms_fwprintf(FILE *, const wchar_t *, ...);

// Declarations of functions from ucrtbase.dll that we use below
_CRTIMP int* __cdecl __p___argc(void);
_CRTIMP char*** __cdecl __p___argv(void);
_CRTIMP wchar_t*** __cdecl __p___wargv(void);
_CRTIMP char*** __cdecl __p__environ(void);
_CRTIMP wchar_t*** __cdecl __p__wenviron(void);
_CRTIMP char** __cdecl __p__acmdln(void);
_CRTIMP wchar_t** __cdecl __p__wcmdln(void);

_CRTIMP int __cdecl _crt_atexit(_onexit_t func);

_CRTIMP int __cdecl _initialize_narrow_environment(void);
_CRTIMP int __cdecl _initialize_wide_environment(void);
_CRTIMP int __cdecl _configure_narrow_argv(int mode);
_CRTIMP int __cdecl _configure_wide_argv(int mode);



// Wrappers with legacy msvcrt.dll style API, based on the new ucrtbase.dll functions.
int __cdecl __getmainargs(int * _Argc, char *** _Argv, char ***_Env, int _DoWildCard, _startupinfo *_StartInfo)
{
  _initialize_narrow_environment();
  _configure_narrow_argv(_DoWildCard ? 2 : 1);
  *_Argc = *__p___argc();
  *_Argv = *__p___argv();
  *_Env = *__p__environ();
  __set_app_type(_StartInfo->newmode);
  __MINGW_IMP_SYMBOL(_acmdln) = __p__acmdln();
  return 0;
}

int __cdecl __wgetmainargs(int * _Argc, wchar_t *** _Argv, wchar_t ***_Env, int _DoWildCard, _startupinfo *_StartInfo)
{
  _initialize_wide_environment();
  _configure_wide_argv(_DoWildCard ? 2 : 1);
  *_Argc = *__p___argc();
  *_Argv = *__p___wargv();
  *_Env = *__p__wenviron();
  __set_app_type(_StartInfo->newmode);
  __MINGW_IMP_SYMBOL(_wcmdln) = (char**) __p__wcmdln();
  return 0;
}

_onexit_t __cdecl _onexit(_onexit_t func)
{
  return _crt_atexit(func) == 0 ? func : NULL;
}

_onexit_t __cdecl (*__MINGW_IMP_SYMBOL(_onexit))(_onexit_t func) = _onexit;

_onexit_t __dllonexit(_onexit_t func, _PVFV** begin, _PVFV** end)
{
  int len = *end - *begin;
  _PVFV* ret = realloc(*begin, (len + 1) * sizeof(**begin));
  if (ret == NULL)
    return NULL;
  len++;
  *begin = ret;
  *end = *begin + len;
  (*begin)[len - 1] = (_PVFV) func;
  return func;
}

void __cdecl _amsg_exit(int ret) {
  fprintf(stderr, "runtime error %d\n", ret);
}

unsigned int __cdecl _get_output_format(void)
{
  return 0;
}

static char ** local__initenv;
static wchar_t ** local__winitenv;
static int local_fmode;
char *** __MINGW_IMP_SYMBOL(__initenv) = &local__initenv;
wchar_t *** __MINGW_IMP_SYMBOL(__winitenv) = &local__winitenv;
int * __MINGW_IMP_SYMBOL(_fmode) = &local_fmode;

char ** __MINGW_IMP_SYMBOL(_acmdln);
char ** __MINGW_IMP_SYMBOL(_wcmdln);



// The parts below are mostly ugly workarounds, necessary to appease code
// within libmingwex and CRT startup routines built for legacy msvcrt.dll
// to work properly with ucrtbase.dll.
#define _EXIT_LOCK1 8

static CRITICAL_SECTION exit_lock;

static void __cdecl free_locks(void)
{
  DeleteCriticalSection(&exit_lock);
}

static void __cdecl init_compat_dtor(void)
{
  InitializeCriticalSection(&exit_lock);

  atexit(free_locks);
}

static _CRTALLOC(".CRT$XID") __attribute__((__used__)) _PVFV mingw_ucrtbase_compat_init = init_compat_dtor;


// These are required to provide the unrepfixed data symbols "timezone"
// and "tzname"; we can't remap "timezone" via a define due to clashes
// with e.g. "struct timezone".
typedef void __cdecl (*_tzset_func)(void);
extern _tzset_func __MINGW_IMP_SYMBOL(_tzset);

static long local_timezone;
char** __MINGW_IMP_SYMBOL(tzname);
long * __MINGW_IMP_SYMBOL(timezone) = &local_timezone;

void __cdecl _tzset(void)
{
  __MINGW_IMP_SYMBOL(_tzset)();
  __MINGW_IMP_SYMBOL(tzname) = _tzname;
  local_timezone = _timezone;
}

void __cdecl tzset(void)
{
  _tzset();
}

// This is the only lock that will be used (from atonexit.c). The _lock_file and
// _unlock_file fallback wrappers in stdio/mingw_lock.c are only linked in libmsvcrt.a,
// not when targeting a known newer version.
void __cdecl _lock(int _File)
{
  if (_File == _EXIT_LOCK1)
    EnterCriticalSection(&exit_lock);
}

void __cdecl _unlock(int _File)
{
  if (_File == _EXIT_LOCK1)
    LeaveCriticalSection(&exit_lock);
}

// assert (in wassert.c) produces references to these two functions
int __cdecl fwprintf(FILE *ptr, const wchar_t *fmt, ...)
{
  va_list ap;
  int ret;
  va_start(ap, fmt);
  ret = vfwprintf(ptr, fmt, ap);
  va_end(ap);
  return ret;
}

int __cdecl _snwprintf(wchar_t * restrict _Dest, size_t _Count, const wchar_t * restrict _Format, ...)
{
  va_list ap;
  int ret;
  va_start(ap, _Format);
  ret = vsnwprintf(_Dest, _Count, _Format, ap);
  va_end(ap);
  return ret;
}

// This is called for wchar cases with __USE_MINGW_ANSI_STDIO enabled (where the
// char case just uses fputc). The FILE* is a valid file here, shouldn't be our
// dummy stderr.
int __cdecl __ms_fwprintf(FILE *file, const wchar_t *fmt, ...)
{
  va_list ap;
  int ret;
  va_start(ap, fmt);
  ret = __stdio_common_vfwprintf(UCRTBASE_PRINTF_LEGACY_WIDE_SPECIFIERS, file, fmt, NULL, ap);
  va_end(ap);
  return ret;
}

// Dummy/unused __imp_ wrappers, to make GNU ld not autoexport these symbols.
int __cdecl (*__MINGW_IMP_SYMBOL(__getmainargs))(int *, char ***, char ***, int, _startupinfo *) = __getmainargs;
int __cdecl (*__MINGW_IMP_SYMBOL(__wgetmainargs))(int *, wchar_t ***, wchar_t ***, int, _startupinfo *) = __wgetmainargs;
_onexit_t __cdecl (*__MINGW_IMP_SYMBOL(__dllonexit))(_onexit_t, _PVFV**, _PVFV**) = __dllonexit;
void __cdecl (*__MINGW_IMP_SYMBOL(_amsg_exit))(int) = _amsg_exit;
unsigned int __cdecl (*__MINGW_IMP_SYMBOL(_get_output_format))(void) = _get_output_format;
void __cdecl (*__MINGW_IMP_SYMBOL(tzset))(void) = tzset;
void __cdecl (*__MINGW_IMP_SYMBOL(_lock))(int) = _lock;
void __cdecl (*__MINGW_IMP_SYMBOL(_unlock))(int) = _unlock;
int __cdecl (*__MINGW_IMP_SYMBOL(fwprintf))(FILE *, const wchar_t *, ...) = fwprintf;
int __cdecl (*__MINGW_IMP_SYMBOL(_snwprintf))(wchar_t *restrict, size_t, const wchar_t *restrict, ...) = _snwprintf;
int __cdecl (*__MINGW_IMP_SYMBOL(__ms_fwprintf))(FILE *, const wchar_t *, ...) = __ms_fwprintf;
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
