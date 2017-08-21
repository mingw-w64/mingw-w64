/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Winline"
#endif

#define __MSVCRT_VERSION__ 0x1400

#define vfprintf real_vfprintf
#define fprintf real_fprintf
#define fwprintf real_fwprintf
#define _snwprintf real__snwprintf
#define __getmainargs crtimp___getmainargs
#define __wgetmainargs crtimp___wgetmainargs
#define _amsg_exit crtimp__amsg_exit
#define _get_output_format crtimp__get_output_format
#define _wsetlocale crtimp__wsetlocale

#include <internal.h>
#include <sect_attribs.h>
#include <stdio.h>
#include <locale.h>

#undef vfprintf
#undef fprintf
#undef fwprintf
#undef _snwprintf
#undef __getmainargs
#undef __wgetmainargs
#undef _amsg_exit
#undef _get_output_format
#undef _wsetlocale

#undef __iob_func
#undef ___mb_cur_max_func


// Declarations of non-static functions implemented within this file (that aren't
// declared in any of the included headers, and that isn't mapped away with a define
// to get rid of the _CRTIMP in headers).
int __cdecl __getmainargs(int * _Argc, char *** _Argv, char ***_Env, int _DoWildCard, _startupinfo *_StartInfo);
int __cdecl __wgetmainargs(int * _Argc, wchar_t *** _Argv, wchar_t ***_Env, int _DoWildCard, _startupinfo *_StartInfo);
void __cdecl _amsg_exit(int ret);
unsigned int __cdecl _get_output_format(void);
wchar_t * __cdecl _wsetlocale(int _Category, const wchar_t *_Locale);

void __cdecl _lock(int _File);
void __cdecl _unlock(int _File);
_onexit_t __dllonexit(_onexit_t func, _PVFV** begin, _PVFV** end);

int fprintf(FILE* ptr, const char* fmt, ...);
int vfprintf(FILE* ptr, const char* fmt, va_list ap);
FILE *__cdecl __iob_func(void);
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
_CRTIMP int __cdecl ___mb_cur_max_func(void);

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
  real_fprintf(stderr, "runtime error %d\n", ret);
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

static int compat_inited;
static CRITICAL_SECTION exit_lock;
static size_t (*real_fwrite)(const void *restrict, size_t, size_t, FILE *restrict);
static char * (*real_setlocale)(int, const char*);
static wchar_t * (*real__wsetlocale)(int, const wchar_t*);
static int local__mb_cur_max;
int * __MINGW_IMP_SYMBOL(__mb_cur_max) = &local__mb_cur_max;

static void __cdecl free_locks(void)
{
  DeleteCriticalSection(&exit_lock);
}

static void __cdecl init_compat(void)
{
  HANDLE ucrt;
  if (compat_inited)
    return;

  ucrt = GetModuleHandle("ucrtbase.dll");
  real_fwrite = (size_t (*)(const void *restrict, size_t, size_t, FILE *restrict)) GetProcAddress(ucrt, "fwrite");
  real_setlocale = (char * (*)(int, const char*)) GetProcAddress(ucrt, "setlocale");
  real__wsetlocale = (wchar_t * (*)(int, const wchar_t*)) GetProcAddress(ucrt, "_wsetlocale");

  InitializeCriticalSection(&exit_lock);

  local__mb_cur_max = ___mb_cur_max_func();

  compat_inited = 1;
}

static void __cdecl init_compat_dtor(void)
{
  init_compat();
  // atexit requires parts for this is inited at .CRT$XIAA, but we might need
  // the compat init for fwrite (fprintf with a constant string) already in
  // _pei386_runtime_relocator which for DLLs is run before the constructors
  // in .CRT$XIAA.
  atexit(free_locks);
}

_CRTALLOC(".CRT$XID") _PVFV mingw_ucrtbase_compat_init = init_compat_dtor;


// Intercept any calls to setlocale, that could change the return value of
// ___mb_cur_max_func(), and update the __mb_cur_max variable accordingly.
// If stdlib.h and ctype.h were to be updated to actually call the real
// ___mb_cur_max_func() function (which exists in all(?) versions of msvcrt.dll)
// instead of reading the __mb_cur_max extern variable, we could avoid all this.
char * __cdecl setlocale(int _Category, const char *_Locale)
{
  char *ret;
  if (!compat_inited)
    init_compat();
  ret = real_setlocale(_Category, _Locale);
  local__mb_cur_max = ___mb_cur_max_func();
  return ret;
}

wchar_t * __cdecl _wsetlocale(int _Category, const wchar_t *_Locale)
{
  wchar_t *ret;
  if (!compat_inited)
    init_compat();
  ret = real__wsetlocale(_Category, _Locale);
  local__mb_cur_max = ___mb_cur_max_func();
  return ret;
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

// Dummy iob array for the cases in CRT startup objects and libmingwex that link
// directly to legacy-msvcrt style stdio - this is only meant to support use with
// stderr below.
// Since this array is an array of concrete FILE structs (not FILE pointers),
// we can't easily make this a proper alias for the real FILE objects within
// ucrtbase.dll (we'd need to sync the FILE struct content back and forth
// after each operation). Instead use this as a dummy, and check that FILE pointers
// are equal to &local_iob[2], indicating stderr.
static FILE local_iob[3];
FILE (* __MINGW_IMP_SYMBOL(_iob))[] = &local_iob;

FILE *__cdecl __iob_func(void)
{
  return local_iob;
}

// This is only supposed to handle the stray calls to
// fprintf(stderr,) within libmingwex and the CRT startup
// files.
int __cdecl vfprintf(FILE *ptr, const char *fmt, va_list ap)
{
  if (!compat_inited)
    init_compat();
  if (ptr != &local_iob[2])
    abort();
  return real_vfprintf(stderr, fmt, ap);
}

int __cdecl fprintf(FILE *ptr, const char *fmt, ...)
{
  va_list ap;
  int ret;
  if (!compat_inited)
    init_compat();
  if (ptr != &local_iob[2])
    abort();
  va_start(ap, fmt);
  ret = real_vfprintf(stderr, fmt, ap);
  va_end(ap);
  return ret;
}

// assert (in wassert.c) produces references to these two functions
int __cdecl fwprintf(FILE *ptr, const wchar_t *fmt, ...)
{
  va_list ap;
  int ret;
  if (!compat_inited)
    init_compat();
  if (ptr != &local_iob[2])
    abort();
  va_start(ap, fmt);
  ret = vfwprintf(stderr, fmt, ap);
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

// fprintf calls with a constant value can be rewritten to fwrite,
// but we need to catch any case of passing the compat dummy stderr
// before we call the real fwrite.
// Normally, init_compat is called via the CRTALLOC array, but if
// _pei386_runtime_relocator fails and tries to print to stderr,
// we can end up here before those constructors have been run.
size_t __cdecl fwrite(const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream)
{
  if (!compat_inited)
    init_compat();
  if (stream == &local_iob[2])
    stream = stderr;
  return real_fwrite(ptr, size, nitems, stream);
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
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
