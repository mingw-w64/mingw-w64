/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef __MINGW_THREAD_LOCAL_H
#define __MINGW_THREAD_LOCAL_H

#include <windows.h>

/* Macro __MINGW_ALLOC_THREAD_LOCAL allocates Windows native thread local
 * storage for variable of specified type with initial value at compile time
 * and returns pointer to that allocated thread local variable at runtime.
 * If the specified type is array then the returned value is also of the
 * array type, specifically "type[]" (and not the "type(*)[]").
 * Its functionality is exactly ABI same as the MSVC __declspec(thread) keyword,
 * just it returns pointer to that variable (not variable itself) and it does
 * not require any thread local storage support from compiler.
 *
 * Note that Windows native thread local storage support is not available for
 * DLL libraries which were loaded at runtime by one of the LoadLibrary call
 * on systems prior Windows Vista. MSVC __declspec(thread) keyword and also
 * __MINGW_ALLOC_THREAD_LOCAL() macro for that case tries to dereference memory
 * which could belongs to other module which cause memory corruption or crash.
 *
 * To avoid these issues, there are two additional macros:
 * __MINGW_ALLOC_THREAD_LOCAL_OR_NULL and __MINGW_ALLOC_THREAD_LOCAL_OR_STATIC
 * If the thread local storage was not allocated by the system then the first
 * one returns NULL pointer, and second one returns pointer to static storage
 * allocated at the compile time (which is shared by all threads). So the
 * second one macro is useful for functions which should be thread-safe when
 * possible with fallback to non-thread-safe on pre-Vista systems.
 *
 * MinGW-w64 CRT runtime code sets _tls_index to -1 at compile time and Windows
 * system PE loader changes it at runtime to the correct TLS index/slot value,
 * which would not be -1. Value 0 is valid index/slot used by EXE binaries and
 * in some cases also by DLL libraries (if no other DLL library and also main
 * EXE does not use TLS). Note that we cannot use TLS callbacks for this check
 * because on some systems (e.g. on all Win9x) TLS callbacks are never called.
 *
 * Examples:
 *   int *tls0 = __MINGW_ALLOC_THREAD_LOCAL(int);
 *   int *tls1 = __MINGW_ALLOC_THREAD_LOCAL(int, = 10);
 *   int *tls2 = __MINGW_ALLOC_THREAD_LOCAL(int[4]);
 *   int *tls3 = __MINGW_ALLOC_THREAD_LOCAL(int[4], = {1,2,3,4});
 *   int *tls4 = __MINGW_ALLOC_THREAD_LOCAL(int[], = {1,2,3,4});
 */
#define ___MINGW_DEREF_IF_ARRAY(var, expr) \
  __builtin_choose_expr( \
    __builtin_classify_type(var) == 5 && !__builtin_types_compatible_p( \
      __typeof__(&*__builtin_choose_expr(__builtin_classify_type(var) == 5, (var), NULL)), \
      __typeof__(var) \
    ), \
    *(expr), \
    (expr) \
  )
#define ___MINGW_ALLOC_THREAD_LOCAL_HELPER(fallback, type, ...) ({ \
  extern char *_tls_start; \
  extern unsigned long _tls_index; \
  __attribute__((__section__(".tls$"))) static __typeof__(type) __mingw_tls_var __VA_ARGS__; \
  ___MINGW_DEREF_IF_ARRAY(__mingw_tls_var, \
    ((__builtin_constant_p(fallback) && (fallback) == (__typeof__(type) *)-1) || _tls_index != (unsigned long)-1) ? \
    (__typeof__(type) *)(((char ***)NtCurrentTeb())[11][_tls_index] + ((char *)&__mingw_tls_var - (char *)&_tls_start)) : \
    (fallback) \
  ); \
})
#define __MINGW_ALLOC_THREAD_LOCAL(type, ...) ___MINGW_ALLOC_THREAD_LOCAL_HELPER((__typeof__(type) *)-1, type, ##__VA_ARGS__)
#define __MINGW_ALLOC_THREAD_LOCAL_OR_NULL(type, ...) ___MINGW_ALLOC_THREAD_LOCAL_HELPER((__typeof__(type) *)NULL, type, ##__VA_ARGS__)
#define __MINGW_ALLOC_THREAD_LOCAL_OR_STATIC(type, ...) ___MINGW_ALLOC_THREAD_LOCAL_HELPER(&__mingw_tls_var, type, ##__VA_ARGS__)

#endif
