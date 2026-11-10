/*
   Copyright (c) 2011-2016, 2026 mingw-w64 project

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
*/

#if defined(__arm__) || defined(__aarch64__)
/* We use setjmp/longjmp through asynchronous function calls via
 * SetThreadContext below. This makes unwinding from longjmp not
 * work reliably; therefore use a version of setjmp/longjmp that doesn't
 * rely on SEH. */
#define __USE_MINGW_SETJMP_NON_SEH
#endif

#define WINPTHREAD_THREAD_DECL WINPTHREAD_API

#include "misc.h"

#include <signal.h> /* NSIG, SIGINT */
#include <stdio.h> /* fprintf, size_t, snprintf, stderr */
#include <stdlib.h> /* calloc, free, malloc, realloc */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

static _pthread_v *__pthread_self_lite (void);

void (**_pthread_key_dest)(void *) = NULL;

static volatile long _pthread_cancelling;
static int _pthread_concur;

/* FIXME Will default to zero as needed */
static pthread_once_t _pthread_tls_once;
static DWORD _pthread_tls = 0xffffffff;

static pthread_rwlock_t _pthread_key_lock = PTHREAD_RWLOCK_INITIALIZER;
static unsigned long _pthread_key_max=0L;
static unsigned long _pthread_key_sch=0L;

static _pthread_v *pthr_root = NULL, *pthr_last = NULL;
static pthread_mutex_t mtx_pthr_locked = PTHREAD_RECURSIVE_MUTEX_INITIALIZER;

static __pthread_idlist *idList = NULL;
static size_t idListCnt = 0;
static size_t idListMax = 0;
static pthread_t idListNextId = 0;

#if defined(__SEH__) && (!defined(__clang__) || __clang_major__ >= 7)
#define SEH_INLINE_ASM
#ifdef __arm__
#define ASM_EXCEPT "%%except"
#else
#define ASM_EXCEPT "@except"
#endif
#endif

#if !defined(_MSC_VER) && (defined(__i386__) || defined(SEH_INLINE_ASM))
static EXCEPTION_DISPOSITION __cdecl
SetThreadName_SEH (EXCEPTION_RECORD *ExceptionRecord, PVOID EstablisherFrame, CONTEXT *ContextRecord, PVOID DispatcherContext)
{
  /* Do not be confused with VEH handlers and CRT except filters which returns LONG value with UPPER_CASE constants.
   * SEH handlers like this one return value from EXCEPTION_DISPOSITION enum which has CamelCase constants.
   * UPPER_CASE EXCEPTION_CONTINUE_SEARCH and CamelCase ExceptionContinueSearch are different constants.
   */
  if (!(ExceptionRecord->ExceptionFlags & EXCEPTION_UNWINDING) &&
      !(ExceptionRecord->ExceptionFlags & EXCEPTION_NONCONTINUABLE) &&
      ExceptionRecord->ExceptionCode == EXCEPTION_SET_THREAD_NAME)
    return ExceptionContinueExecution;

  return ExceptionContinueSearch;
}
#endif

typedef struct _THREADNAME_INFO
{
  DWORD  dwType;	/* must be 0x1000 */
  LPCSTR szName;	/* pointer to name (in user addr space) */
  DWORD  dwThreadID;	/* thread ID (-1=caller thread) */
  DWORD  dwFlags;	/* reserved for future use, must be zero */
} THREADNAME_INFO;

#if !defined(_MSC_VER) && !defined(__i386__) && defined(SEH_INLINE_ASM)
WINPTHREADS_ATTRIBUTE((noinline)) /* required for asm .seh_handler directive */
#endif
static void
SetThreadName (DWORD dwThreadID, LPCSTR szThreadName)
{
   THREADNAME_INFO info;
   DWORD infosize;

   info.dwType = 0x1000;
   info.szName = szThreadName;
   info.dwThreadID = dwThreadID;
   info.dwFlags = 0;

   infosize = sizeof (info) / sizeof (ULONG_PTR);

   /* Exception has to be processed otherwise it will crash the process. */

#if defined(_MSC_VER)
   /* msvc supports __try / __except syntax, so use it */
   __try
     {
       RaiseException (EXCEPTION_SET_THREAD_NAME, 0, infosize, (ULONG_PTR *)&info);
     }
   __except (EXCEPTION_EXECUTE_HANDLER)
     {
     }
#else
   /* gcc does not support __try / __except syntax, so manually register SEH handler */
#if defined(__i386__)
   /* On 32-bit x86 is SEH handler registered and unregistered at runtime */
   EXCEPTION_REGISTRATION_RECORD exception_record = {
     .Next = (EXCEPTION_REGISTRATION_RECORD *) __readfsdword (0), /* current SEH handler */
     .Handler = (PEXCEPTION_ROUTINE)(void*) SetThreadName_SEH,
   };
   __writefsdword (0, (DWORD) &exception_record); /* register our SEH handler */
   RaiseException (EXCEPTION_SET_THREAD_NAME, 0, infosize, (ULONG_PTR *) &info);
   __writefsdword (0, (DWORD) exception_record.Next); /* unregister our SEH handler */
#elif defined(SEH_INLINE_ASM)
   /* On other platforms SEH handlers are registered at compile time.
      Assembler directive .seh_handler statically register SEH handler for
      the whole current function. It does not matter at which line is this
      directive called. It always applies for the whole function, so also
      for code before the directive itself. As this function does not do
      anything else, we can register our SEH handler for the whole function.
      This function has to be marked as noinline to ensure that the SEH
      handler would not be registered for a caller.
    */
   asm volatile (".seh_handler %c0, " ASM_EXCEPT :: "i" (SetThreadName_SEH));
   RaiseException (EXCEPTION_SET_THREAD_NAME, 0, infosize, (ULONG_PTR *) &info);
#else
   /* Other compilers / platforms do not provide SEH support */
#endif
#endif
}

/* Search the list idList for an element with identifier ID.  If
   found, its associated _pthread_v pointer is returned, otherwise
   NULL.
   NOTE: This method is not locked.  */
static struct _pthread_v *
__pthread_get_pointer (pthread_t id)
{
  size_t l, r, p;
  if (!idListCnt)
    return NULL;
  if (idListCnt == 1)
    return (idList[0].id == id ? idList[0].ptr : NULL);
  l = 0; r = idListCnt - 1;
  while (l <= r)
  {
    p = (l + r) >> 1;
    if (idList[p].id == id)
      return idList[p].ptr;
    else if (idList[p].id > id)
      {
	if (p == l)
	  return NULL;
	r = p - 1;
      }
    else
      {
	l = p + 1;
      }
  }

  return NULL;
}

static void
__pth_remove_use_for_key (pthread_key_t key)
{
  int i;

  pthread_mutex_lock (&mtx_pthr_locked);
  for (i = 0; i < idListCnt; i++)
    {
      if (idList[i].ptr != NULL
          && idList[i].ptr->keyval != NULL
          && key < idList[i].ptr->keymax)
        {
	  idList[i].ptr->keyval[key] = NULL;
	  idList[i].ptr->keyval_set[key] = 0;
	}
    }
  pthread_mutex_unlock (&mtx_pthr_locked);
}

/* Search the list idList for an element with identifier ID.  If
   found, its associated _pthread_v pointer is returned, otherwise
   NULL.
   NOTE: This method uses lock mtx_pthr_locked.  */
struct _pthread_v *
__pth_gpointer_locked (pthread_t id)
{
  struct _pthread_v *ret;
  if (!id)
    return NULL;
  pthread_mutex_lock (&mtx_pthr_locked);
  ret =  __pthread_get_pointer (id);
  pthread_mutex_unlock (&mtx_pthr_locked);
  return ret;
}

/* Registers in the list idList an element with _pthread_v pointer
   and creates and unique identifier ID.  If successful created the
   ID of this element is returned, otherwise on failure zero ID gets
   returned.
   NOTE: This method is not locked.  */
static pthread_t
__pthread_register_pointer (struct _pthread_v *ptr)
{
  __pthread_idlist *e;
  size_t i;

  if (!ptr)
    return 0;
  /* Check if a resize of list is necessary.  */
  if (idListCnt >= idListMax)
    {
      if (!idListCnt)
        {
	  e = (__pthread_idlist *) malloc (sizeof (__pthread_idlist) * 16);
	  if (!e)
	    return 0;
	  idListMax = 16;
	  idList = e;
	}
      else
        {
	  e = (__pthread_idlist *) realloc (idList, sizeof (__pthread_idlist) * (idListMax + 16));
	  if (!e)
	    return 0;
	  idListMax += 16;
	  idList = e;
	}
    }
  do
    {
      ++idListNextId;
      /* If two MSB are set we reset to id 1.  We need to check here bits
         to avoid gcc's no-overflow issue on increment.  Additionally we
         need to handle different size of pthread_t on 32-bit/64-bit.  */
      if ((idListNextId & ( ((pthread_t) 1) << ((sizeof (pthread_t) * 8) - 2))) != 0)
        idListNextId = 1;
    }
  while (idListNextId == 0 || __pthread_get_pointer (idListNextId));
  /* We assume insert at end of list.  */
  i = idListCnt;
  if (i != 0)
    {
      /* Find position we can actual insert sorted.  */
      while (i > 0 && idList[i - 1].id > idListNextId)
        --i;
      if (i != idListCnt)
	memmove (&idList[i + 1], &idList[i], sizeof (__pthread_idlist) * (idListCnt - i));
    }
  idList[i].id = idListNextId;
  idList[i].ptr = ptr;
  ++idListCnt;
  return idListNextId;
}

/* Deregisters in the list idList an element with identifier ID and
   returns its _pthread_v pointer on success.  Otherwise NULL is returned.
   NOTE: This method is not locked.  */
static struct _pthread_v *
__pthread_deregister_pointer (pthread_t id)
{
  size_t l, r, p;
  if (!idListCnt)
    return NULL;
  l = 0; r = idListCnt - 1;
  while (l <= r)
  {
    p = (l + r) >> 1;
    if (idList[p].id == id)
      {
	struct _pthread_v *ret = idList[p].ptr;
	p++;
	if (p < idListCnt)
	  memmove (&idList[p - 1], &idList[p], sizeof (__pthread_idlist) * (idListCnt - p));
	--idListCnt;
	/* Is this last element in list then free list.  */
	if (idListCnt == 0)
	{
	  free (idList);
	  idListCnt = idListMax = 0;
	}
	return ret;
      }
    else if (idList[p].id > id)
      {
	if (p == l)
	  return NULL;
	r = p - 1;
      }
    else
      {
	l = p + 1;
      }
  }
  return NULL;
}

/* Save a _pthread_v element for reuse in pool.  */
static void
push_pthread_mem (_pthread_v *sv)
{
  if (!sv || sv->next != NULL)
    return;
  pthread_mutex_lock (&mtx_pthr_locked);
  if (sv->x != 0)
    __pthread_deregister_pointer (sv->x);
  if (sv->keyval)
    free (sv->keyval);
  if (sv->keyval_set)
    free (sv->keyval_set);
  if (sv->thread_name)
    free (sv->thread_name);
  memset (sv, 0, sizeof(struct _pthread_v));
  if (pthr_last == NULL)
    pthr_root = pthr_last = sv;
  else
  {
    pthr_last->next = sv;
    pthr_last = sv;
  }
  pthread_mutex_unlock (&mtx_pthr_locked);
}

/* Get a _pthread_v element from pool, or allocate it.
   Note the unique identifier is created for the element here, too.  */
static _pthread_v *
pop_pthread_mem (void)
{
  _pthread_v *r = NULL;

  pthread_mutex_lock (&mtx_pthr_locked);
  if ((r = pthr_root) == NULL)
    {
      if ((r = (_pthread_v *)calloc (1,sizeof(struct _pthread_v))) != NULL)
	{
	  r->x = __pthread_register_pointer (r);
	  if (r->x == 0)
	    {
	      free (r);
	      r = NULL;
	    }
	}
      pthread_mutex_unlock (&mtx_pthr_locked);
      return r;
    }
  r->x = __pthread_register_pointer (r);
  if (r->x == 0)
    r = NULL;
  else
    {
      if((pthr_root = r->next) == NULL)
	pthr_last = NULL;

      r->next = NULL;
    }
  pthread_mutex_unlock (&mtx_pthr_locked);
  return r;
}

/* Free memory consumed in _pthread_v pointer pool.  */
static void
free_pthread_mem (void)
{
#if 0
  _pthread_v *t;

  pthread_mutex_lock (&mtx_pthr_locked);
  t = pthr_root;
  while (t != NULL)
  {
    _pthread_v *sv = t;
    t = t->next;
    if (sv->x != 0 && sv->ended == 0 && sv->valid != DEAD_THREAD)
      {
	pthread_mutex_unlock (&mtx_pthr_locked);
	pthread_cancel (t->x);
	Sleep (0);
	pthread_mutex_lock (&mtx_pthr_locked);
	t = pthr_root;
	continue;
      }
    else if (sv->x != 0 && sv->valid != DEAD_THREAD)
      {
	pthread_mutex_unlock (&mtx_pthr_locked);
	Sleep (0);
	pthread_mutex_lock (&mtx_pthr_locked);
	continue;
      }
    if (sv->x != 0)
      __pthread_deregister_pointer (sv->x);
    sv->x = 0;
    free (sv);
    pthr_root = t;
  }
  pthread_mutex_unlock (&mtx_pthr_locked);
#endif
  return;
}

static void
replace_spin_keys (pthread_spinlock_t *old, pthread_spinlock_t new)
{
  if (old == NULL)
    return;

  if (EPERM == pthread_spin_destroy (old))
    {
#define THREADERR "Error cleaning up spin_keys for thread %lu.\n"
      char threaderr[sizeof(THREADERR) + 8] = { 0 };
      snprintf(threaderr, sizeof(threaderr), THREADERR, GetCurrentThreadId());
#undef THREADERR
      OutputDebugStringA (threaderr);
      abort ();
    }

  *old = new;
}

/* Hook for TLS-based deregistration/registration of thread.  */
static void WINAPI
__dyn_tls_pthread (HANDLE hDllHandle, DWORD dwReason, LPVOID lpreserved)
{
  _pthread_v *t = NULL;
  pthread_spinlock_t new_spin_keys = PTHREAD_SPINLOCK_INITIALIZER;

  if (dwReason == DLL_PROCESS_DETACH)
    {
      free_pthread_mem ();
    }
  else if (dwReason == DLL_PROCESS_ATTACH)
    {
    }
  else if (dwReason == DLL_THREAD_DETACH)
    {
      if (_pthread_tls != 0xffffffff)
	t = (_pthread_v *)TlsGetValue(_pthread_tls);
      if (t && t->thread_noposix != 0)
	{
	  _pthread_cleanup_dest (t->x);
	  if (t->h != NULL)
	    {
	      CloseHandle (t->h);
	      if (t->evStart)
		CloseHandle (t->evStart);
	      t->evStart = NULL;
	      t->h = NULL;
	    }
	  pthread_mutex_destroy (&t->p_clock);
	  replace_spin_keys (&t->spin_keys, new_spin_keys);
	  push_pthread_mem (t);
	  t = NULL;
	  TlsSetValue (_pthread_tls, t);
	}
      else if (t && t->ended == 0)
	{
	  if (t->evStart)
	    CloseHandle(t->evStart);
	  t->evStart = NULL;
	  t->ended = 1;
	  _pthread_cleanup_dest (t->x);
	  if ((t->p_state & PTHREAD_CREATE_DETACHED) == PTHREAD_CREATE_DETACHED)
	    {
	      t->valid = DEAD_THREAD;
	      if (t->h != NULL)
		CloseHandle (t->h);
	      t->h = NULL;
	      pthread_mutex_destroy(&t->p_clock);
	      replace_spin_keys (&t->spin_keys, new_spin_keys);
	      push_pthread_mem (t);
	      t = NULL;
	      TlsSetValue (_pthread_tls, t);
	      return;
	    }
	  pthread_mutex_destroy(&t->p_clock);
	  replace_spin_keys (&t->spin_keys, new_spin_keys);
	}
      else if (t)
	{
	  if (t->evStart)
	    CloseHandle (t->evStart);
	  t->evStart = NULL;
	  pthread_mutex_destroy (&t->p_clock);
	  replace_spin_keys (&t->spin_keys, new_spin_keys);
	}
    }
}

#ifdef DLL_EXPORT

/* For DLL builds register TLS hook via DllMain(). Entrypoint DllMain()
 * works on all Windows versions (Win32s, Win9x, WinNT) for all cases.
 *
 * Callbacks defined via PIMAGE_TLS_CALLBACK are not called on Win9x
 * systems, and also they are not called on pre-Vista systems when
 * DLL library is loaded at runtime by LoadLibrary() call.
 */

BOOL WINAPI
DllMain (HANDLE hDllHandle, DWORD dwReason, LPVOID lpReserved)
{
  __dyn_tls_pthread (hDllHandle, dwReason, lpReserved);
  return TRUE;
}

#else

/* TLS-runtime section variable.  */

/* Force a reference to _tls_used to make the linker create the TLS
 * directory if it's not already there.  (e.g. if __declspec(thread)
 * is not used).
 * Force a reference to __xl_f to prevent whole program optimization
 * from discarding the variable. */
#if defined(__GNUC__)
/* Pointer to _tls_used has to be passed into volatile context inside
 * some function which is not optimized out to make TLS code working
 * with GNU LD --gc-sections switch, due to bug:
 * https://sourceware.org/pipermail/binutils/2026-July/150496.html
 */
extern const IMAGE_TLS_DIRECTORY _tls_used;
static __attribute__((destructor)) void _include_tls_used(void) { asm volatile ("" :: "r" (&_tls_used)); }
#elif defined(_MSC_VER)
/* On x86, symbols are prefixed with an underscore. */
# if defined(_M_IX86)
#   pragma comment(linker, "/include:__tls_used")
#   pragma comment(linker, "/include:___xl_f")
# else
#   pragma comment(linker, "/include:_tls_used")
#   pragma comment(linker, "/include:__xl_f")
# endif

/* .CRT$XLA to .CRT$XLZ is an array of PIMAGE_TLS_CALLBACK
 * pointers. Pick an arbitrary location for our callback.
 *
 * See VC\...\crt\src\vcruntime\tlssup.cpp for reference. */

# pragma section(".CRT$XLF", long, read)
#endif

#if defined(__GNUC__)
static __attribute__((used))
#endif
WINPTHREADS_ATTRIBUTE((WINPTHREADS_SECTION(".CRT$XLF")))
const PIMAGE_TLS_CALLBACK __xl_f = __dyn_tls_pthread;

#endif

/* Internal collect-once structure.  */
typedef struct collect_once_t {
  pthread_once_t *o;
  pthread_mutex_t m;
  int count;
  struct collect_once_t *next;
} collect_once_t;

static collect_once_t *once_obj = NULL;

static pthread_spinlock_t once_global = PTHREAD_SPINLOCK_INITIALIZER;

static collect_once_t *
enterOnceObject (pthread_once_t *o)
{
  collect_once_t *c, *p = NULL;
  pthread_spin_lock (&once_global);
  c = once_obj;
  while (c != NULL && c->o != o)
    {
      c = (p = c)->next;
    }
  if (!c)
    {
      c = (collect_once_t *) calloc(1,sizeof(collect_once_t));
      c->o = o;
      c->count = 1;
      if (!p)
        once_obj = c;
      else
        p->next = c;
      pthread_mutex_init(&c->m, NULL);
    }
  else
    c->count += 1;
  pthread_spin_unlock (&once_global);
  return c;
}

static void
leaveOnceObject (collect_once_t *c)
{
  collect_once_t *h, *p = NULL;
  if (!c)
    return;
  pthread_spin_lock (&once_global);
  h = once_obj;
  while (h != NULL && c != h)
    h = (p = h)->next;

  if (h)
    {
      c->count -= 1;
      if (c->count == 0)
	{
	  pthread_mutex_destroy(&c->m);
	  if (!p)
	    once_obj = c->next;
	  else
	    p->next = c->next;
	  free (c);
	}
    }
  else
    fprintf(stderr, "%p not found?!?!\n", (void *) c);
  pthread_spin_unlock (&once_global);
}

static void
_pthread_once_cleanup (void *o)
{
  collect_once_t *co = (collect_once_t *) o;
  pthread_mutex_unlock (&co->m);
  leaveOnceObject (co);
}

static int
_pthread_once_raw (pthread_once_t *o, void (*func)(void))
{
  collect_once_t *co;
  long state = *o;

  if (!o || !func)
    return EINVAL;

  if (state == 1)
    return 0;
  co = enterOnceObject(o);
  pthread_mutex_lock(&co->m);
  if (*o == 0)
    {
      func();
      *o = 1;
    }
  else if (*o != 1)
    fprintf (stderr," once %p is %ld\n", (void *) o, (long) *o);
  pthread_mutex_unlock(&co->m);
  leaveOnceObject(co);

  /* Done */
  return 0;
}

/* Unimplemented.  */
void *
pthread_timechange_handler_np(void *dummy)
{
  return NULL;
}

int
pthread_once (pthread_once_t *o, void (*func)(void))
{
  collect_once_t *co;
  long state = *o;

  if (!o || !func)
    return EINVAL;

  if (state == 1)
    return 0;
  co = enterOnceObject(o);
  pthread_mutex_lock(&co->m);
  if (*o == 0)
    {
      pthread_cleanup_push(_pthread_once_cleanup, co);
      func();
      pthread_cleanup_pop(0);
      *o = 1;
    }
  else if (*o != 1)
    fprintf (stderr," once %p is %ld\n", (void *) o, (long) *o);
  pthread_mutex_unlock(&co->m);
  leaveOnceObject(co);

  return 0;
}

int
pthread_key_create (pthread_key_t *key, void (* dest)(void *))
{
	unsigned int i;
	long nmax;
	void (**d)(void *);

	if (!key)
		return EINVAL;

	pthread_rwlock_wrlock (&_pthread_key_lock);

	for (i = _pthread_key_sch; i < _pthread_key_max; i++)
	{
		if (!_pthread_key_dest[i])
		{
			*key = i;
			if (dest)
				_pthread_key_dest[i] = dest;
			else
				_pthread_key_dest[i] = (void(*)(void *))1;
			pthread_rwlock_unlock (&_pthread_key_lock);
			return 0;
		}
	}

	for (i = 0; i < _pthread_key_sch; i++)
	{
		if (!_pthread_key_dest[i])
		{
			*key = i;
			if (dest)
				_pthread_key_dest[i] = dest;
			else
				_pthread_key_dest[i] = (void(*)(void *))1;
			pthread_rwlock_unlock (&_pthread_key_lock);

			return 0;
		}
	}

	if (_pthread_key_max == PTHREAD_KEYS_MAX)
	{
		pthread_rwlock_unlock(&_pthread_key_lock);
		return ENOMEM;
	}

	nmax = _pthread_key_max * 2;
	if (nmax == 0)
		nmax = _pthread_key_max + 1;
	if (nmax > PTHREAD_KEYS_MAX)
		nmax = PTHREAD_KEYS_MAX;

	/* No spare room anywhere */
	d = (void (__cdecl **)(void *))realloc(_pthread_key_dest, nmax * sizeof(*d));
	if (!d)
	{
		pthread_rwlock_unlock (&_pthread_key_lock);
		return ENOMEM;
	}

	/* Clear new region */
	memset ((void *) &d[_pthread_key_max], 0, (nmax-_pthread_key_max)*sizeof(void *));

	/* Use new region */
	_pthread_key_dest = d;
	_pthread_key_sch = _pthread_key_max + 1;
	*key = _pthread_key_max;
	_pthread_key_max = nmax;

	if (dest)
		_pthread_key_dest[*key] = dest;
	else
		_pthread_key_dest[*key] = (void(*)(void *))1;

	pthread_rwlock_unlock (&_pthread_key_lock);
	return 0;
}

int
pthread_key_delete (pthread_key_t key)
{
  if (key >= _pthread_key_max || !_pthread_key_dest)
    return EINVAL;

  pthread_rwlock_wrlock (&_pthread_key_lock);

  _pthread_key_dest[key] = NULL;

  /* Start next search from our location */
  if (_pthread_key_sch > key)
    _pthread_key_sch = key;
  /* So now we need to walk the complete list of threads
     and remove key's reference for it.  */
  __pth_remove_use_for_key (key);

  pthread_rwlock_unlock (&_pthread_key_lock);
  return 0;
}

void *
pthread_getspecific (pthread_key_t key)
{
  DWORD lasterr = GetLastError ();
  void *r;
  _pthread_v *t = __pthread_self_lite ();
  pthread_spin_lock (&t->spin_keys);
  r = (key >= t->keymax || t->keyval_set[key] == 0 ? NULL : t->keyval[key]);
  pthread_spin_unlock (&t->spin_keys);
  SetLastError (lasterr);
  return r;
}

int
pthread_setspecific (pthread_key_t key, const void *value)
{
  DWORD lasterr = GetLastError ();
  _pthread_v *t = __pthread_self_lite ();

  pthread_spin_lock (&t->spin_keys);

  if (key >= t->keymax)
    {
      int keymax = (key + 1);
      void **kv;
      unsigned char *kv_set;

      kv = (void **) realloc (t->keyval, keymax * sizeof (void *));

      if (!kv)
        {
	  pthread_spin_unlock (&t->spin_keys);
	  return ENOMEM;
	}
      kv_set = (unsigned char *) realloc (t->keyval_set, keymax);
      if (!kv_set)
        {
	  pthread_spin_unlock (&t->spin_keys);
	  return ENOMEM;
	}

      /* Clear new region */
      memset (&kv[t->keymax], 0, (keymax - t->keymax)*sizeof(void *));
      memset (&kv_set[t->keymax], 0, (keymax - t->keymax));

      t->keyval = kv;
      t->keyval_set = kv_set;
      t->keymax = keymax;
    }

  t->keyval[key] = (void *) value;
  t->keyval_set[key] = 1;
  pthread_spin_unlock (&t->spin_keys);
  SetLastError (lasterr);

  return 0;
}

int
pthread_equal (pthread_t t1, pthread_t t2)
{
  return (t1 == t2);
}

void
pthread_tls_init (void)
{
  _pthread_tls = TlsAlloc();

  /* Cannot continue if out of indexes */
  if (_pthread_tls == TLS_OUT_OF_INDEXES)
    abort();
}

void
_pthread_cleanup_dest (pthread_t t)
{
	_pthread_v *tv;
	unsigned int j;
	int i;

	if (!t)
		return;
	tv = __pth_gpointer_locked (t);
	if (!tv)
		return;

	for (j = 0; j < PTHREAD_DESTRUCTOR_ITERATIONS; j++)
	{
		int flag = 0;

		pthread_spin_lock (&tv->spin_keys);
		for (i = tv->keymax - 1; i >= 0; i--)
		{
			void *val = tv->keyval[i];

			if (tv->keyval_set[i])
			{
				pthread_rwlock_rdlock (&_pthread_key_lock);
				if ((uintptr_t) _pthread_key_dest[i] > 1)
				{
					/* Call destructor */
					tv->keyval[i] = NULL;
					tv->keyval_set[i] = 0;
					pthread_spin_unlock (&tv->spin_keys);
					_pthread_key_dest[i](val);
					pthread_spin_lock (&tv->spin_keys);
					flag = 1;
				}
				else
				{
					tv->keyval[i] = NULL;
					tv->keyval_set[i] = 0;
				}
				pthread_rwlock_unlock(&_pthread_key_lock);
			}
		}
		pthread_spin_unlock (&tv->spin_keys);
		/* Nothing to do? */
		if (!flag)
			return;
	}
}

static _pthread_v *
__pthread_self_lite (void)
{
  _pthread_v *t;
  pthread_spinlock_t new_spin_keys = PTHREAD_SPINLOCK_INITIALIZER;

  _pthread_once_raw (&_pthread_tls_once, pthread_tls_init);

  t = (_pthread_v *) TlsGetValue (_pthread_tls);
  if (t)
    return t;
  /* Main thread? */
  t = (struct _pthread_v *) pop_pthread_mem ();

  /* If cannot initialize main thread, then the only thing we can do is return null pthread_t */
  if (!t)
    return 0;

  t->p_state = PTHREAD_DEFAULT_ATTR /*| PTHREAD_CREATE_DETACHED*/;
  t->tid = GetCurrentThreadId();
  t->evStart = CreateEvent (NULL, 1, 0, NULL);
  t->p_clock = PTHREAD_MUTEX_INITIALIZER;
  replace_spin_keys (&t->spin_keys, new_spin_keys);
  t->sched_pol = SCHED_OTHER;
  t->h = NULL; //GetCurrentThread();
  if (!DuplicateHandle(GetCurrentProcess(), GetCurrentThread(), GetCurrentProcess(), &t->h, 0, FALSE, DUPLICATE_SAME_ACCESS))
    abort ();
  t->sched.sched_priority = GetThreadPriority(t->h);
  t->ended = 0;
  t->thread_noposix = 1;

  /* Save for later */
  if (!TlsSetValue(_pthread_tls, t))
    abort ();
  return t;
}

pthread_t
pthread_self (void)
{
  _pthread_v *t = __pthread_self_lite ();

  if (!t)
    return 0;
  return t->x;
}

/* Internal helper for getting event handle of thread T.  */
void *
pthread_getevent (void)
{
  _pthread_v *t = __pthread_self_lite ();
  return (!t ? NULL : t->evStart);
}

/* Internal helper for getting thread handle of thread T.  */
void *
pthread_gethandle (pthread_t t)
{
  struct _pthread_v *tv = __pth_gpointer_locked (t);
  return (!tv ? NULL : tv->h);
}

/* Internal helper for getting pointer of clean of current thread.  */
struct _pthread_cleanup **
pthread_getclean (void)
{
  struct _pthread_v *t = __pthread_self_lite ();
  if (!t) return NULL;
  return &t->clean;
}

int
pthread_get_concurrency (int *val)
{
  *val = _pthread_concur;
  return 0;
}

int
pthread_set_concurrency (int val)
{
  _pthread_concur = val;
  return 0;
}

void
pthread_exit (void *res)
{
  _pthread_v *t = NULL;
  unsigned rslt = (unsigned) ((intptr_t) res);
  struct _pthread_v *id = __pthread_self_lite ();

  id->ret_arg = res;

  _pthread_cleanup_dest (id->x);
  if (id->thread_noposix == 0)
    longjmp(id->jb, 1);

  /* Make sure we free ourselves if we are detached */
  if ((t = (_pthread_v *)TlsGetValue(_pthread_tls)) != NULL)
    {
      if (!t->h)
	{
	  t->valid = DEAD_THREAD;
	  if (t->evStart)
	    CloseHandle (t->evStart);
	  t->evStart = NULL;
	  rslt = (unsigned) (size_t) t->ret_arg;
	  push_pthread_mem(t);
	  t = NULL;
	  TlsSetValue (_pthread_tls, t);
	}
      else
	{
	  rslt = (unsigned) (size_t) t->ret_arg;
	  t->ended = 1;
	  if (t->evStart)
	    CloseHandle (t->evStart);
	  t->evStart = NULL;
	  if ((t->p_state & PTHREAD_CREATE_DETACHED) == PTHREAD_CREATE_DETACHED)
	    {
	      t->valid = DEAD_THREAD;
	      CloseHandle (t->h);
	      t->h = NULL;
	      push_pthread_mem(t);
	      t = NULL;
	      TlsSetValue(_pthread_tls, t);
	    }
	}
    }
  /* Time to die */
  _endthreadex(rslt);
}

void
_pthread_invoke_cancel (void)
{
  _pthread_cleanup *pcup;
  struct _pthread_v *se = __pthread_self_lite ();
  se->in_cancel = 1;
  _pthread_setnobreak (1);
  InterlockedDecrement(&_pthread_cancelling);

  /* Call cancel queue */
  for (pcup = se->clean; pcup; pcup = pcup->next)
    {
      pcup->func((pthread_once_t *)pcup->arg);
    }

  _pthread_setnobreak (0);
  pthread_exit(PTHREAD_CANCELED);
}

int
__pthread_shallcancel (void)
{
  struct _pthread_v *t;
  if (!_pthread_cancelling)
    return 0;
  t = __pthread_self_lite ();
  if (t == NULL)
    return 0;
  if (t->nobreak <= 0 && t->cancelled && (t->p_state & PTHREAD_CANCEL_ENABLE))
    return 1;
  return 0;
}

void
_pthread_setnobreak (int v)
{
  struct _pthread_v *t = __pthread_self_lite ();
  if (t == NULL)
    return;
  if (v > 0)
    InterlockedIncrement ((long*)&t->nobreak);
  else
    InterlockedDecrement((long*)&t->nobreak);
}

void
pthread_testcancel (void)
{
  struct _pthread_v *self = __pthread_self_lite ();

  if (!self || self->in_cancel)
    return;
  if (!_pthread_cancelling)
    return;
  pthread_mutex_lock (&self->p_clock);

  if (self->cancelled && (self->p_state & PTHREAD_CANCEL_ENABLE) && self->nobreak <= 0)
    {
      self->in_cancel = 1;
      self->p_state &= ~PTHREAD_CANCEL_ENABLE;
      if (self->evStart)
	ResetEvent (self->evStart);
      pthread_mutex_unlock (&self->p_clock);
      _pthread_invoke_cancel ();
    }
  pthread_mutex_unlock (&self->p_clock);
}

int
pthread_cancel (pthread_t t)
{
  struct _pthread_v *tv = __pth_gpointer_locked (t);

  if (!tv || !winpthreads_validate_handle(tv->h))
    return ESRCH;
  /*if (tv->ended) return ESRCH;*/
  pthread_mutex_lock(&tv->p_clock);
  if (pthread_equal(pthread_self(), t))
    {
      if(tv->cancelled)
	{
	  pthread_mutex_unlock(&tv->p_clock);
	  return (tv->in_cancel ? ESRCH : 0);
	}
      tv->cancelled = 1;
      InterlockedIncrement(&_pthread_cancelling);
      if(tv->evStart) SetEvent(tv->evStart);
      if ((tv->p_state & PTHREAD_CANCEL_ASYNCHRONOUS) != 0 && (tv->p_state & PTHREAD_CANCEL_ENABLE) != 0)
	{
	  tv->p_state &= ~PTHREAD_CANCEL_ENABLE;
	  tv->in_cancel = 1;
	  pthread_mutex_unlock(&tv->p_clock);
	  _pthread_invoke_cancel();
	}
      else
	pthread_mutex_unlock(&tv->p_clock);
      return 0;
    }

  if ((tv->p_state & PTHREAD_CANCEL_ASYNCHRONOUS) != 0 && (tv->p_state & PTHREAD_CANCEL_ENABLE) != 0)
    {
      /* Dangerous asynchronous cancelling */
      CONTEXT ctxt;

      if(tv->in_cancel)
	{
	  pthread_mutex_unlock(&tv->p_clock);
	  return (tv->in_cancel ? ESRCH : 0);
	}
      /* Already done? */
      if(tv->cancelled || tv->in_cancel)
	{
	  /* ??? pthread_mutex_unlock (&tv->p_clock); */
	  return ESRCH;
	}

      ctxt.ContextFlags = CONTEXT_CONTROL;

      SuspendThread (tv->h);
      if (winpthreads_wait (tv->h, 0, CLOCK_MONOTONIC, WINPTHREADS_WAIT_TIMEOUT_ZERO, NULL) == wait_timeout_expired)
	{
	  GetThreadContext(tv->h, &ctxt);
#ifdef _M_X64
	  ctxt.Rip = (uintptr_t) _pthread_invoke_cancel;
#elif defined(_M_IX86)
	  ctxt.Eip = (uintptr_t) _pthread_invoke_cancel;
#elif defined(_M_ARM) || defined(_M_ARM64)
	  ctxt.Pc = (uintptr_t) _pthread_invoke_cancel;
#else
#error Unsupported architecture
#endif
	  SetThreadContext (tv->h, &ctxt);

	  /* Also try deferred Cancelling */
	  tv->cancelled = 1;
	  tv->p_state &= ~PTHREAD_CANCEL_ENABLE;
	  tv->in_cancel = 1;

	  /* Notify everyone to look */
	  InterlockedIncrement (&_pthread_cancelling);
	  if (tv->evStart)
	    SetEvent (tv->evStart);
	  pthread_mutex_unlock (&tv->p_clock);

	  ResumeThread (tv->h);
	}
    }
  else
    {
      if (tv->cancelled == 0)
	{
	  /* Safe deferred Cancelling */
	  tv->cancelled = 1;

	  /* Notify everyone to look */
	  InterlockedIncrement (&_pthread_cancelling);
	  if (tv->evStart)
	    SetEvent (tv->evStart);
	}
      else
	{
	  pthread_mutex_unlock (&tv->p_clock);
	  return (tv->in_cancel ? ESRCH : 0);
	}
    }
  pthread_mutex_unlock (&tv->p_clock);
  return 0;
}

/* half-stubbed version as we don't really well support signals */
int
pthread_kill (pthread_t t, int sig)
{
  struct _pthread_v *tv;

  pthread_mutex_lock (&mtx_pthr_locked);
  tv = __pthread_get_pointer (t);
  if (!tv || t != tv->x || tv->in_cancel || tv->ended || tv->h == NULL
      || tv->h == INVALID_HANDLE_VALUE)
  {
    pthread_mutex_unlock (&mtx_pthr_locked);
    return ESRCH;
  }
  pthread_mutex_unlock (&mtx_pthr_locked);
  if (!sig)
    return 0;
  if (sig < SIGINT || sig > NSIG)
    return EINVAL;
  return pthread_cancel(t);
}

unsigned
_pthread_get_state (const pthread_attr_t *attr, unsigned flag)
{
  return (attr->p_state & flag);
}

int
_pthread_set_state (pthread_attr_t *attr, unsigned flag, unsigned val)
{
  if (~flag & val)
    return EINVAL;
  attr->p_state &= ~flag;
  attr->p_state |= val;

  return 0;
}

int
pthread_attr_init (pthread_attr_t *attr)
{
  memset (attr, 0, sizeof (pthread_attr_t));
  attr->p_state = PTHREAD_DEFAULT_ATTR;
  attr->stack = NULL;
  attr->s_size = 0;
  return 0;
}

int
pthread_attr_destroy (pthread_attr_t *attr)
{
  /* No need to do anything */
  memset (attr, 0, sizeof(pthread_attr_t));
  return 0;
}

int
pthread_attr_setdetachstate (pthread_attr_t *a, int flag)
{
  return _pthread_set_state(a, PTHREAD_CREATE_DETACHED, flag);
}

int
pthread_attr_getdetachstate (const pthread_attr_t *a, int *flag)
{
  *flag = _pthread_get_state(a, PTHREAD_CREATE_DETACHED);
  return 0;
}

int
pthread_attr_setinheritsched (pthread_attr_t *a, int flag)
{
  if (!a || (flag != PTHREAD_INHERIT_SCHED && flag != PTHREAD_EXPLICIT_SCHED))
    return EINVAL;
  return _pthread_set_state(a, PTHREAD_INHERIT_SCHED, flag);
}

int
pthread_attr_getinheritsched (const pthread_attr_t *a, int *flag)
{
  *flag = _pthread_get_state(a, PTHREAD_INHERIT_SCHED);
  return 0;
}

int
pthread_attr_setscope (pthread_attr_t *a, int flag)
{
  return _pthread_set_state(a, PTHREAD_SCOPE_SYSTEM, flag);
}

int
pthread_attr_getscope (const pthread_attr_t *a, int *flag)
{
  *flag = _pthread_get_state(a, PTHREAD_SCOPE_SYSTEM);
  return 0;
}

int
pthread_attr_getstack (const pthread_attr_t *attr, void **stack, size_t *size)
{
  *stack = (char *) attr->stack - attr->s_size;
  *size = attr->s_size;
  return 0;
}

int
pthread_attr_setstack (pthread_attr_t *attr, void *stack, size_t size)
{
  attr->s_size = size;
  attr->stack = (char *) stack + size;
  return 0;
}

int
pthread_attr_getstackaddr (const pthread_attr_t *attr, void **stack)
{
  *stack = attr->stack;
  return 0;
}

int
pthread_attr_setstackaddr (pthread_attr_t *attr, void *stack)
{
  attr->stack = stack;
  return 0;
}

int
pthread_attr_getstacksize (const pthread_attr_t *attr, size_t *size)
{
  *size = attr->s_size;
  return 0;
}

int
pthread_attr_setstacksize (pthread_attr_t *attr, size_t size)
{
  attr->s_size = size;
  return 0;
}

static void
test_cancel_locked (pthread_t t)
{
  struct _pthread_v *tv = __pth_gpointer_locked (t);

  if (!tv || tv->in_cancel || tv->ended != 0 || (tv->p_state & PTHREAD_CANCEL_ENABLE) == 0)
    return;
  if ((tv->p_state & PTHREAD_CANCEL_ASYNCHRONOUS) == 0)
    return;
  if (winpthreads_wait (tv->evStart, 0, CLOCK_MONOTONIC, WINPTHREADS_WAIT_TIMEOUT_ZERO, NULL) != wait_succeeded)
    return;
  pthread_mutex_unlock (&tv->p_clock);
  _pthread_invoke_cancel();
}

int
pthread_setcancelstate (int state, int *oldstate)
{
  _pthread_v *t = __pthread_self_lite ();

  if (!t || (state & PTHREAD_CANCEL_ENABLE) != state)
    return EINVAL;

  pthread_mutex_lock (&t->p_clock);
  if (oldstate)
    *oldstate = t->p_state & PTHREAD_CANCEL_ENABLE;
  t->p_state &= ~PTHREAD_CANCEL_ENABLE;
  t->p_state |= state;
  test_cancel_locked (t->x);
  pthread_mutex_unlock (&t->p_clock);

  return 0;
}

int
pthread_setcanceltype (int type, int *oldtype)
{
  _pthread_v *t = __pthread_self_lite ();

  if (!t || (type & PTHREAD_CANCEL_ASYNCHRONOUS) != type)
    return EINVAL;

  pthread_mutex_lock (&t->p_clock);
  if (oldtype)
    *oldtype = t->p_state & PTHREAD_CANCEL_ASYNCHRONOUS;
  t->p_state &= ~PTHREAD_CANCEL_ASYNCHRONOUS;
  t->p_state |= type;
  test_cancel_locked (t->x);
  pthread_mutex_unlock (&t->p_clock);

  return 0;
}

#if defined(__i386__)
/* Align ESP on 16-byte boundaries. */
__attribute__((force_align_arg_pointer))
#endif
unsigned __stdcall
pthread_create_wrapper (void *args)
{
  unsigned rslt = 0;
  struct _pthread_v *tv = (struct _pthread_v *)args;

  /* POSIX requires the floating-point environment to be inherited from the
     creating thread.  Windows starts every thread with its own defaults
     (x87 precision set to 53 bits, which breaks long double), and a TLS
     callback cannot change that on x64 because the initial context is
     loaded after the callbacks run, so set it here.  */
  fesetenv (&tv->fenv);

  pthread_mutex_lock (&mtx_pthr_locked);
  pthread_mutex_lock (&tv->p_clock);
  _pthread_once_raw(&_pthread_tls_once, pthread_tls_init);
  TlsSetValue(_pthread_tls, tv);
  tv->tid = GetCurrentThreadId();
  pthread_mutex_unlock (&tv->p_clock);


  if (!setjmp(tv->jb))
    {
      intptr_t trslt = (intptr_t) 128;
      pthread_mutex_unlock (&mtx_pthr_locked);
      /* Call function and save return value */
      if (tv->func)
        trslt = (intptr_t) tv->func(tv->ret_arg);
      pthread_mutex_lock (&mtx_pthr_locked);
      tv->ret_arg = (void*) trslt;
      /* Clean up destructors */
      _pthread_cleanup_dest(tv->x);
    }
  else
    pthread_mutex_lock (&mtx_pthr_locked);

  pthread_mutex_lock (&tv->p_clock);
  rslt = (unsigned) (size_t) tv->ret_arg;
  /* Make sure we free ourselves if we are detached */
  if (tv->evStart)
    CloseHandle (tv->evStart);
  tv->evStart = NULL;
  if (!tv->h)
    {
      tv->valid = DEAD_THREAD;
      pthread_mutex_unlock (&tv->p_clock);
      pthread_mutex_destroy (&tv->p_clock);
      push_pthread_mem (tv);
      tv = NULL;
      TlsSetValue (_pthread_tls, tv);
    }
  else
    {
      pthread_mutex_unlock (&tv->p_clock);
      pthread_mutex_destroy (&tv->p_clock);
      /* Reinitialise p_clock, since there may be attempts at
         destroying it again in __dyn_tls_thread later on. */
      tv->p_clock = PTHREAD_MUTEX_INITIALIZER;
      tv->ended = 1;
      /* GH #328 experiment: once ended, tv belongs to whoever joins or detaches
         us, and may be recycled for a new thread before our DLL_THREAD_DETACH
         runs -- so that callback must not find it through our TLS slot. */
      TlsSetValue (_pthread_tls, NULL);
    }
  while (pthread_mutex_unlock (&mtx_pthr_locked) == 0)
   Sleep (0);
  _endthreadex (rslt);
  return rslt;
}

int
pthread_create (pthread_t *th, const pthread_attr_t *attr, void *(* func)(void *), void *arg)
{
  HANDLE thrd = NULL;
  int redo = 0;
  struct _pthread_v *tv;
  unsigned int ssize = 0;
  pthread_spinlock_t new_spin_keys = PTHREAD_SPINLOCK_INITIALIZER;
  unsigned thrAddr; /* Dummy variable to pass a valid location to _beginthreadex (Win98). */

  if (attr && attr->s_size > UINT_MAX)
    return EINVAL;

  if ((tv = pop_pthread_mem ()) == NULL)
    return EAGAIN;

  if (th)
    *th = tv->x;

  /* Save data in pthread_t */
  tv->ended = 0;
  tv->ret_arg = arg;
  tv->func = func;
  tv->p_state = PTHREAD_DEFAULT_ATTR;
  tv->h = INVALID_HANDLE_VALUE;
  /* We retry it here a few times, as events are a limited resource ... */
  do
    {
      tv->evStart = CreateEvent (NULL, 1, 0, NULL);
      if (tv->evStart != NULL)
	break;
      Sleep ((!redo ? 0 : 20));
    }
  while (++redo <= 4);

  tv->p_clock = PTHREAD_MUTEX_INITIALIZER;
  replace_spin_keys (&tv->spin_keys, new_spin_keys);
  tv->valid = LIFE_THREAD;
  tv->sched.sched_priority = THREAD_PRIORITY_NORMAL;
  tv->sched_pol = SCHED_OTHER;
  if (tv->evStart == NULL)
    {
      if (th)
       memset (th, 0, sizeof (pthread_t));
      push_pthread_mem (tv);
      return EAGAIN;
    }

  if (attr)
    {
      int inh = 0;
      tv->p_state = attr->p_state;
      ssize = (unsigned int)attr->s_size;
      pthread_attr_getinheritsched (attr, &inh);
      if (inh)
	{
	  tv->sched.sched_priority = __pthread_self_lite ()->sched.sched_priority;
	}
      else
	tv->sched.sched_priority = attr->param.sched_priority;
    }

  fegetenv (&tv->fenv);

  /* Make sure tv->h has value of INVALID_HANDLE_VALUE */
  _ReadWriteBarrier();

  thrd = (HANDLE) _beginthreadex(NULL, ssize, pthread_create_wrapper, tv, 0x4/*CREATE_SUSPEND*/, &thrAddr);
  if (thrd == INVALID_HANDLE_VALUE)
    thrd = 0;
  /* Failed */
  if (!thrd)
    {
      if (tv->evStart)
	CloseHandle (tv->evStart);
      pthread_mutex_destroy (&tv->p_clock);
      replace_spin_keys (&tv->spin_keys, new_spin_keys);
      tv->evStart = NULL;
      tv->h = 0;
      if (th)
        memset (th, 0, sizeof (pthread_t));
      push_pthread_mem (tv);
      return EAGAIN;
    }
  {
    int pr = tv->sched.sched_priority;
    if (pr <= THREAD_PRIORITY_IDLE) {
	pr = THREAD_PRIORITY_IDLE;
    } else if (pr <= THREAD_PRIORITY_LOWEST) {
	pr = THREAD_PRIORITY_LOWEST;
    } else if (pr >= THREAD_PRIORITY_TIME_CRITICAL) {
	pr = THREAD_PRIORITY_TIME_CRITICAL;
    } else if (pr >= THREAD_PRIORITY_HIGHEST) {
	pr = THREAD_PRIORITY_HIGHEST;
    }
    SetThreadPriority (thrd, pr);
  }
  ResetEvent (tv->evStart);
  if ((tv->p_state & PTHREAD_CREATE_DETACHED) != 0)
    {
      tv->h = 0;
      ResumeThread (thrd);
      CloseHandle (thrd);
    }
  else
    {
      tv->h = thrd;
      ResumeThread (thrd);
    }
  Sleep (0);
  return 0;
}

int
pthread_join (pthread_t t, void **res)
{
  struct _pthread_v *tv = __pth_gpointer_locked (t);
  pthread_spinlock_t new_spin_keys = PTHREAD_SPINLOCK_INITIALIZER;

  if (!tv || !winpthreads_validate_handle(tv->h))
    return ESRCH;
  if ((tv->p_state & PTHREAD_CREATE_DETACHED) != 0)
    return EINVAL;
  if (pthread_equal(pthread_self(), t))
    return EDEADLK;

  /* pthread_testcancel (); */
  if (tv->ended == 0 || (tv->h != NULL && tv->h != INVALID_HANDLE_VALUE))
    winpthreads_wait (tv->h, 0, CLOCK_MONOTONIC, WINPTHREADS_WAIT_TIMEOUT_INDEFINITE, NULL);
  CloseHandle (tv->h);
  if (tv->evStart)
    CloseHandle (tv->evStart);
  tv->evStart = NULL;
  /* Obtain return value */
  if (res)
    *res = tv->ret_arg;
  pthread_mutex_destroy (&tv->p_clock);
  replace_spin_keys (&tv->spin_keys, new_spin_keys);
  push_pthread_mem (tv);

  return 0;
}

int
_pthread_tryjoin (pthread_t t, void **res)
{
  struct _pthread_v *tv;
  pthread_spinlock_t new_spin_keys = PTHREAD_SPINLOCK_INITIALIZER;

  pthread_mutex_lock (&mtx_pthr_locked);
  tv = __pthread_get_pointer (t);

  if (!tv || !winpthreads_validate_handle(tv->h))
    {
      pthread_mutex_unlock (&mtx_pthr_locked);
      return ESRCH;
    }

  if ((tv->p_state & PTHREAD_CREATE_DETACHED) != 0)
    {
      pthread_mutex_unlock (&mtx_pthr_locked);
      return EINVAL;
    }
  if (pthread_equal(pthread_self(), t))
    {
      pthread_mutex_unlock (&mtx_pthr_locked);
      return EDEADLK;
    }
  if(tv->ended == 0 && winpthreads_wait(tv->h, 0, CLOCK_MONOTONIC, WINPTHREADS_WAIT_TIMEOUT_ZERO, NULL) != wait_succeeded)
    {
      if (tv->ended == 0)
        {
	      pthread_mutex_unlock (&mtx_pthr_locked);
	      /* pthread_testcancel (); */
	      return EBUSY;
	    }
    }
  CloseHandle (tv->h);
  if (tv->evStart)
    CloseHandle (tv->evStart);
  tv->evStart = NULL;

  /* Obtain return value */
  if (res)
    *res = tv->ret_arg;
  pthread_mutex_destroy (&tv->p_clock);
  replace_spin_keys (&tv->spin_keys, new_spin_keys);

  push_pthread_mem (tv);

  pthread_mutex_unlock (&mtx_pthr_locked);
  /* pthread_testcancel (); */
  return 0;
}

int
pthread_detach (pthread_t t)
{
  int r = 0;
  struct _pthread_v *tv = __pth_gpointer_locked (t);
  HANDLE dw;
  pthread_spinlock_t new_spin_keys = PTHREAD_SPINLOCK_INITIALIZER;

  pthread_mutex_lock (&mtx_pthr_locked);
  if (!tv || !winpthreads_validate_handle(tv->h))
    {
      pthread_mutex_unlock (&mtx_pthr_locked);
      return ESRCH;
    }
  if ((tv->p_state & PTHREAD_CREATE_DETACHED) != 0)
    {
      pthread_mutex_unlock (&mtx_pthr_locked);
      return EINVAL;
    }
  /* if (tv->ended) r = ESRCH; */
  dw = tv->h;
  tv->h = 0;
  tv->p_state |= PTHREAD_CREATE_DETACHED;
  _ReadWriteBarrier();
  if (dw)
    {
      CloseHandle (dw);
      if (tv->ended)
	{
	  if (tv->evStart)
	    CloseHandle (tv->evStart);
	  tv->evStart = NULL;
	  pthread_mutex_destroy (&tv->p_clock);
	  replace_spin_keys (&tv->spin_keys, new_spin_keys);
	  push_pthread_mem (tv);
	}
    }
  pthread_mutex_unlock (&mtx_pthr_locked);

  return r;
}

static int dummy_concurrency_level = 0;

int
pthread_getconcurrency (void)
{
  return dummy_concurrency_level;
}

int
pthread_setconcurrency (int new_level)
{
  dummy_concurrency_level = new_level;
  return 0;
}

int
pthread_setname_np (pthread_t thread, const char *name)
{
  struct _pthread_v *tv;
  char *stored_name;

  if (name == NULL)
    return EINVAL;

  tv = __pth_gpointer_locked (thread);
  if (!tv || thread != tv->x || tv->in_cancel || tv->ended || tv->h == NULL
      || tv->h == INVALID_HANDLE_VALUE)
    return ESRCH;

  stored_name = strdup (name);
  if (stored_name == NULL)
    return ENOMEM;

  if (tv->thread_name != NULL)
    free (tv->thread_name);

  tv->thread_name = stored_name;
  SetThreadName (tv->tid, name);
  winpthreads_set_thread_description_ansi (tv->h, name);

  return 0;
}

int
pthread_getname_np (pthread_t thread, char *name, size_t len)
{
  struct _pthread_v *tv;
  size_t thread_name_len;

  if (name == NULL)
    return EINVAL;

  tv = __pth_gpointer_locked (thread);
  if (!tv || thread != tv->x || tv->in_cancel || tv->ended || tv->h == NULL
      || tv->h == INVALID_HANDLE_VALUE)
    return ESRCH;

  if (len < 1)
    return ERANGE;

  if (tv->thread_name == NULL)
    {
      name[0] = '\0';
      return 0;
    }

  thread_name_len = strlen (tv->thread_name);
  if (thread_name_len >= len)
    return ERANGE;

  memcpy (name, tv->thread_name, thread_name_len + 1);
  return 0;
}

/*******************************************************************************
 * Private Functions.
 */

/**
 * This is the maximum amount of handles `winpthreads_wait` can wait on
 * internally; note that `winpthreads_wait` only accepts a single handle to
 * wait on, however, it may wait on additional handles internally.
 *
 * This value must be less than or equal to `MAXIMUM_WAIT_OBJECTS`.
 */
#define WINPTHREADS_MAXIMUM_WAIT_OBJECTS 2

/**
 * Types of handles `winpthreads_wait` can wait on internally.
 */
typedef enum {
  /**
   * The handle passed to `winpthreads_wait`.
   */
  wait_object_handle,
  /**
   * Internal event handle used to wait for thread cancellation notification.
   */
  wait_object_cancellation_notification,
} winpthreads_wait_object_id;

/**
 * Reasons why `winpthreads_wait` can be interrupted.
 */
typedef enum {
  /**
   * No interruption has occurred.
   */
  wait_interrupt_none,
  /**
   * The calling thread received cancellation notification.
   */
  wait_interrupt_cancellation_notification,
} winpthreads_wait_interrupts;

/**
 * Structure used by `winpthreads_wait`.
 */
typedef struct {
  /**
   * Result of the wait operation.
   */
  winpthreads_wait_status Status;
  /**
   * If `Status` is `wait_interrupted`, this is a `winpthreads_wait_interrupts`
   * value describing why wait was interrupted.
   */
  winpthreads_wait_interrupts Interrupt;
  /**
   * Wait timeout, in milliseconds.
   */
  unsigned Timeout;
  /**
   * Number of objects in `Handle` and `HandleId`.
   */
  unsigned Count;
  /**
   * Handles to wait on.
   */
  void *Handle[WINPTHREADS_MAXIMUM_WAIT_OBJECTS];
  /**
   * Each `HandleId[N]` contains a `winpthreads_wait_object_id` value
   * corresponding to `Handle[N]`.
   *
   * There must be no more than one handle of each type.
   */
  winpthreads_wait_object_id HandleId[WINPTHREADS_MAXIMUM_WAIT_OBJECTS];
} winpthreads_wait_state;

/**
 * Add handle `object` with type `objectId` to `waitState`.
 */
static void WinpthreadsWaitStateAdd (winpthreads_wait_state *waitState, void *object, winpthreads_wait_object_id objectId) {
  waitState->Handle[waitState->Count]   = object;
  waitState->HandleId[waitState->Count] = objectId;
  waitState->Count                     += 1;
}

/**
 * Remove handle with type `objectId` from `waitState`.
 */
static void WinpthreadsWaitStateRemove (winpthreads_wait_state *waitState, winpthreads_wait_object_id objectId) {
  for (unsigned i = 0; i < waitState->Count; ++i) {
    if (waitState->HandleId[i] == objectId) {
      for (i += 1; i < waitState->Count; ++i) {
        waitState->Handle[i - 1]   = waitState->Handle[i];
        waitState->HandleId[i - 1] = waitState->HandleId[i];
      }

      waitState->Count -= 1;
      return;
    }
  }
}

/**
 * Common wait logic for `winpthreads_wait`.
 */
static void WinpthreadsWait (winpthreads_wait_state *waitState) {
  /**
   * Simply sleep if there are no handles to wait on.
   */
  if (waitState->Count == 0) {
    Sleep (waitState->Timeout);
    waitState->Status = wait_timeout_expired;
    return;
  }

  /**
   * Old documentation for `WaitForMultipleObjects[Ex]` says:
   *
   * Windows Me/98/95:
   *   No handle may be a duplicate of another handle created using
   *   DuplicateHandle.
   *
   * This may be interpreted as "you cannot pass a handle returned by
   * `DuplicateHandle` to `WaitForMultipleObjects[Ex]` functions".
   *
   * This is not the case and the actual behavior is:
   *
   * On Windows NT 3.1 and Win9x, you cannot pass both original and duplicated
   * handle to some object in the same call to `WaitForMultipleObjects[Ex]`;
   * such call will fail with `ERROR_INVALID_PARAMETER `.
   *
   * You cannot pass the same handle, original or duplicated, in the same call
   * to `WaitForMultipleObjects[Ex]` multiple times on all Windows versions.
   */
  unsigned waitResult = WaitForMultipleObjects (waitState->Count, waitState->Handle, FALSE, waitState->Timeout);

  if (waitResult == WAIT_TIMEOUT) {
    waitState->Status = wait_timeout_expired;
    return;
  }

  winpthreads_wait_status waitStatus = wait_failed;
  unsigned index;

  /**
   * A handle from `waitState.Handle` became signaled.
   */
  if (waitResult >= WAIT_OBJECT_0 && waitResult < WAIT_OBJECT_0 + waitState->Count) {
    waitStatus = wait_succeeded;
    index      = waitResult - WAIT_OBJECT_0;
  }

  /**
   * A handle from `waitState.Handle` was a mutex whose owner terminated
   * without releasing it; the calling thread owns the mutex now.
   */
  if (waitResult >= WAIT_ABANDONED_0 && waitResult < WAIT_ABANDONED_0 + waitState->Count) {
    waitStatus = wait_abandoned_mutex;
    index      = waitResult - WAIT_ABANDONED_0;
  }

  /**
   * Figure out which handle from `waitState.Handle` was signaled.
   */
  if (waitStatus == wait_succeeded || waitStatus == wait_abandoned_mutex) {
    switch (waitState->HandleId[index]) {
      /**
       * The handle passed to `winpthreads_wait` became signaled.
       */
      case wait_object_handle:
        waitState->Status = waitStatus;
        break;
      /**
       * The calling thread received cancellation notification.
       */
      case wait_object_cancellation_notification:
        waitState->Status    = wait_interrupted;
        waitState->Interrupt = wait_interrupt_cancellation_notification;
        break;
      default:
        UNREACHABLE ();
    }
  } else {
    waitState->Status = waitStatus;
  }
}

/**
 * Handle interrupted wait.
 *
 * If `waitState` and `flags` indicate that the caller must be notified about
 * interrupted wait, this function returns non-zero; otherwise, it returns zero.
 */
static int WinpthreadsWaitInterrupt (winpthreads_wait_state *waitState, int flags) {
  switch (waitState->Interrupt) {
    /**
     * The calling thread received cancellation notification.
     *
     * Call `__pthread_shallcancel` to determine whether we should proceed
     * with cancellation. If not, stop waiting on the associated event handle;
     * only the calling thread can modify its cancelability state.
     */
    case wait_interrupt_cancellation_notification:
      if (__pthread_shallcancel ()) {
        return 1;
      }

      WinpthreadsWaitStateRemove (waitState, wait_object_cancellation_notification);
      break;
    default:
      UNREACHABLE ();
  }

  return 0;
  UNREFERENCED_PARAMETER (flags);
}

WINPTHREADS_ATTRIBUTE ((noinline))
winpthreads_wait_status winpthreads_wait (void *handle, int flags, clockid_t clock, const struct _timespec64 *timeout, struct _timespec64 *remain) {
  /**
   * Keep track of wait state.
   */
  winpthreads_wait_state waitState = {
    .Status    = wait_failed,
    .Interrupt = wait_interrupt_none,
    .Timeout   = 0,
    .Count     = 0,
  };

  /**
   * Wait for `handle` to become signaled.
   */
  if (handle != NULL) {
    WinpthreadsWaitStateAdd (&waitState, handle, wait_object_handle);
  }

  /**
   * Wait for cancellation notification.
   */
  if (flags & WINPTHREADS_WAIT_CANCELLATION_NOTIFICATION) {
    HANDLE event = pthread_getevent ();

    if (event != NULL) {
      WinpthreadsWaitStateAdd (&waitState, event, wait_object_cancellation_notification);
    }
  }

  /**
   * Handle common cases with zero and `INFINITE` timeouts.
   */
  if (timeout == WINPTHREADS_WAIT_TIMEOUT_ZERO || timeout == WINPTHREADS_WAIT_TIMEOUT_INDEFINITE) {
    if (timeout == WINPTHREADS_WAIT_TIMEOUT_INDEFINITE) {
      waitState.Timeout = INFINITE;
    }

    do {
      WinpthreadsWait (&waitState);
    } while (waitState.Status == wait_interrupted && !WinpthreadsWaitInterrupt (&waitState, flags));

    return waitState.Status;
  }

  /**
   * By default, resolution of the "wait" timer used by `WaitFor*` and `Sleep*`
   * functions roughly matches that of `GetTickCount*` functions;
   * the latter are used to implement the monotonic (`CLOCK_MONOTONIC`) clock
   * if the proformance counter is not supported.
   *
   * The resolution of the wait timer can be changed by calling
   * `timeBeginPeriod` function from winmm.dll. On recent Windows versions,
   * it allows to set resolution of the wait timer up to 1ms.
   *
   * When `timeout` specifies absolute time, we don't have to do anything
   * special; the wait time outs when `clock` reaches `timeout`.
   *
   * When `timeout` is relative, we must ensure that wait does not time out
   * before `timeout` has really elapsed. In particular, this applies to cases
   * when resolution of the `clock` is >=1ms.
   *
   * Since the time is incremented at intervals equal to the `clock` resolution,
   * the elapsed wait time may appear to be equal to or greater than `timeout`,
   * while in reality it was less. This happens because after entering the wait,
   * only part of the first interval elapses before the time is incremented.
   */

  /**
   * Calculate the wait time from `timeout`.
   */
  struct _timespec64 clockResolution;
  struct _timespec64 waitStartTime;
  struct _timespec64 waitEndTime;
  struct _timespec64 waitUntil;
  struct _timespec64 waitFor;

  /**
   * Always use monotonic (`CLOCK_MONOTONIC`) clock when `timeout` is relative.
   * This is the only reliable way to measure elapsed wait time; using realtime
   * (`CLOCK_REALTIME`) clock is unreliable since system time can be changed
   * while we waiting, leading to incorrect results.
   */
  if ((flags & WINPTHREADS_WAIT_TIMEOUT_ABSTIME) == 0) {
    clock = CLOCK_MONOTONIC;
  }

  winpthreads_time (clock, &waitStartTime, &clockResolution);

  if ((flags & WINPTHREADS_WAIT_TIMEOUT_ABSTIME)) {
    winpthreads_timespec_round (timeout, &clockResolution, &waitUntil);
    winpthreads_timespec_sub (&waitUntil, &waitStartTime, &waitFor);
  } else {
    winpthreads_timespec_round (timeout, &clockResolution, &waitFor);

    /**
     * When resolution of the monotonic clock is >= 1ms, we increase total
     * wait time by the resolution of monotonic clock; in other words,
     * we increment `waitFor` by an additional `clockResolution`.
     *
     * This allows us to ensure that the wait does not time out before
     * `timeout` has really expired.
     */
    if (clockResolution.tv_nsec >= 1000000 || unlikely (clockResolution.tv_sec > 0)) {
      struct _timespec64 ts = waitFor;
      winpthreads_timespec_add (&ts, &clockResolution, &waitFor);
    }

    winpthreads_timespec_add (&waitStartTime, &waitFor, &waitUntil);
  }

  do {
    /**
     * This is `waitFor` converted to milliseconds.
     *
     * However, if `waitFor` is greater than `clockResolution`,
     * then this value is effectively `waitFor - clockResolution`.
     *
     * This only makes practical difference if `clockResolution` is >= 1ms;
     * that is, when clock used to measure elapsed wait time has the same
     * resolution as the system clock or the system timer.
     *
     * There is a decent chance that this value will be sufficient to bring
     * `clock` to `waitUntil`, saving `clockResolution` of total wait time.
     */
    waitState.Timeout = winpthreads_wait_time_from_timespec (&waitFor, &clockResolution);

    WinpthreadsWait (&waitState);

    switch (waitState.Status) {
      case wait_succeeded:
      case wait_abandoned_mutex:
      case wait_failed:
        return waitState.Status;
      case wait_timeout_expired:
      case wait_interrupted:
        break;
    }

    winpthreads_time (clock, &waitEndTime, NULL);

    /**
     * Check whether we should notify the caller about interrupted wait.
     */
    if (waitState.Status == wait_interrupted && WinpthreadsWaitInterrupt (&waitState, flags)) {
      break;
    }

    /**
     * Check if `timeout` has expired.
     */
    if (winpthreads_timespec_diff (&waitEndTime, &waitUntil) >= 0) {
      waitState.Status = wait_timeout_expired;
      break;
    }

    winpthreads_timespec_sub (&waitUntil, &waitEndTime, &waitFor);
  } while (1);

  /**
   * If wait was interrupted, calculate remaining wait time.
   */
  if (waitState.Status == wait_interrupted && remain != NULL) {
    winpthreads_timespec_sub (&waitUntil, &waitEndTime, remain);
  }

  return waitState.Status;
}

/*******************************************************************************
 * Public Functions.
 */

int pthread_delay64_np (const struct _timespec64 *interval) {
  /**
   * Function `pthread_delay_np` is a cancellation point.
   */
  pthread_testcancel ();

  /**
   * Check whether `interval` is valid.
   */
  if (interval->tv_sec < 0 || interval->tv_nsec < 0 || interval->tv_nsec >= 1000000000) {
    return EINVAL;
  }

  winpthreads_wait_status wait_status = winpthreads_wait (
    NULL, WINPTHREADS_WAIT_CANCELLATION_NOTIFICATION,
    CLOCK_MONOTONIC, interval, NULL
  );

  if (wait_status == wait_interrupted) {
    pthread_testcancel ();
    return EINTR;
  }

  return 0;
}

int pthread_delay32_np (const struct _timespec32 *interval) {
  struct _timespec64 ts64 = {
    .tv_sec  = interval->tv_sec,
    .tv_nsec = interval->tv_nsec
  };
  return pthread_delay64_np (&ts64);
}
