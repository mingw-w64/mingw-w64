/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _INC_THREADS
#define _INC_THREADS

#include <_mingw.h>
#include <time.h> /* required per C11 7.26.1 1 */
#include <stdint.h> /* needed for uintptr_t and uint32_t */

#if (!defined(__STDC_VERSION__) || __STDC_VERSION__ <= 201710L || !__MINGW_GNUC_PREREQ(13, 0)) && !defined(__cplusplus)
#define thread_local _Thread_local
#endif

_CRT_BEGIN_C_HEADER

/* mtx */

enum {
  mtx_plain = 0,
  mtx_recursive = 1,
  mtx_timed = 2,
};

typedef struct {
  uintptr_t _Type;
  void *_Ptr;
  void *_Cv;
  uint32_t _Owner;
  uint32_t _Cnt;
} mtx_t;

void __cdecl mtx_destroy(mtx_t *_Mtx);
int __cdecl mtx_init(mtx_t *_Mtx, int _Type);
int __cdecl mtx_lock(mtx_t *_Mtx);
int __cdecl _mtx_timedlock32(mtx_t *_Mtx, const struct _timespec32 *_Ts);
int __cdecl _mtx_timedlock64(mtx_t *_Mtx, const struct _timespec64 *_Ts);
int __cdecl mtx_trylock(mtx_t *_Mtx);
int __cdecl mtx_unlock(mtx_t *_Mtx);

/* cnd */

typedef struct {
  void *_Ptr;
} cnd_t;

int __cdecl cnd_broadcast(cnd_t *_Cond);
void __cdecl cnd_destroy(cnd_t *_Cond);
int __cdecl cnd_init(cnd_t *_Cond);
int __cdecl cnd_signal(cnd_t *_Cond);
int __cdecl _cnd_timedwait32(cnd_t *_Cond, mtx_t *_Mtx, const struct _timespec32 *_Ts);
int __cdecl _cnd_timedwait64(cnd_t *_Cond, mtx_t *_Mtx, const struct _timespec64 *_Ts);
int __cdecl cnd_wait(cnd_t *_Cond, mtx_t *_Mtx);

/* thrd */

typedef struct {
  void *_Handle;
  uint32_t _Tid;
} thrd_t;

enum {
  thrd_success = 0,
  thrd_nomem = 1,
  thrd_timedout = 2,
  thrd_busy = 3,
  thrd_error = 4,
};

typedef int(__cdecl*thrd_start_t)(void *);

int __cdecl thrd_create(thrd_t *_Thr, thrd_start_t _Func, void *_Arg);
thrd_t __cdecl thrd_current(void);
int __cdecl thrd_detach(thrd_t _Thr);
int __cdecl thrd_equal(thrd_t _Thr0, thrd_t _Thr1);
void __cdecl __MINGW_ATTRIB_NORETURN thrd_exit(int _Res);
int __cdecl thrd_join(thrd_t _Thr, int *_Res);
int __cdecl _thrd_sleep32(const struct _timespec32 *_Duration, struct _timespec32 *_Remaining);
int __cdecl _thrd_sleep64(const struct _timespec64 *_Duration, struct _timespec64 *_Remaining);
void __cdecl thrd_yield(void);

/* tss */

#define TSS_DTOR_ITERATIONS 1

typedef struct {
  uint32_t _Idx;
} tss_t;

typedef void (__cdecl*tss_dtor_t)(void*);

int __cdecl tss_create(tss_t *_Key, tss_dtor_t _Dtor);
void __cdecl tss_delete(tss_t _Key);
void *__cdecl tss_get(tss_t _Key);
int __cdecl tss_set(tss_t _Key, void *_Val);

/* once */

#define ONCE_FLAG_INIT { NULL }

typedef struct {
  void *_Opaque;
} once_flag;

void __cdecl call_once(once_flag *_Flag, void(__cdecl*_Func)(void));

/*
 * To prevent ABI issues, the mingw-w64 runtime should not call these
 * functions. Instead it should call the fixed-size variants.
 */
#ifndef _CRTBLD
#ifdef _USE_32BIT_TIME_T
int __cdecl mtx_timedlock(mtx_t *_Mtx, const struct timespec *_Ts) __MINGW_ASM_CALL(_mtx_timedlock32);
int __cdecl cnd_timedwait(cnd_t *_Cond, mtx_t *_Mtx, const struct timespec *_Ts) __MINGW_ASM_CALL(_cnd_timedwait32);
int __cdecl thrd_sleep(const struct timespec *_Duration, struct timespec *_Remaining) __MINGW_ASM_CALL(_thrd_sleep32);
#else
int __cdecl mtx_timedlock(mtx_t *_Mtx, const struct timespec *_Ts) __MINGW_ASM_CALL(_mtx_timedlock64);
int __cdecl cnd_timedwait(cnd_t *_Cond, mtx_t *_Mtx, const struct timespec *_Ts) __MINGW_ASM_CALL(_cnd_timedwait64);
int __cdecl thrd_sleep(const struct timespec *_Duration, struct timespec *_Remaining) __MINGW_ASM_CALL(_thrd_sleep64);
#endif
#endif

_CRT_END_C_HEADER

#endif
