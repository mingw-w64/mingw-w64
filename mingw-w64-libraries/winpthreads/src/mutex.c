/*
   Copyright (c) 2011, 2014 mingw-w64 project

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

#include <windows.h>
#include <winternl.h>
#include <stdio.h>
#include <malloc.h>
#include "pthread.h"
#include "ref.h"
#include "mutex.h"
#include "misc.h"

extern int do_sema_b_wait_intern (HANDLE sema, int nointerrupt, DWORD timeout);
static WINPTHREADS_ATTRIBUTE((noinline)) int mutex_static_init(pthread_mutex_t *m);
static WINPTHREADS_ATTRIBUTE((noinline)) int _mutex_trylock(pthread_mutex_t *m);

static pthread_spinlock_t mutex_global = PTHREAD_SPINLOCK_INITIALIZER;
static pthread_spinlock_t mutex_global_static = PTHREAD_SPINLOCK_INITIALIZER;

static WINPTHREADS_ATTRIBUTE((noinline)) int
mutex_unref (pthread_mutex_t *m, int r)
{
  mutex_t *m_ = (mutex_t *)*m;
  pthread_spin_lock (&mutex_global);
#ifdef WINPTHREAD_DBG
  assert((m_->valid == LIFE_MUTEX) && (m_->busy > 0));
#endif
  if (m_->valid == LIFE_MUTEX && m_->busy > 0)
    m_->busy -= 1;
  pthread_spin_unlock (&mutex_global);
  return r;
}

/* Set the mutex to busy in a thread-safe way */
/* A busy mutex can't be destroyed */
static WINPTHREADS_ATTRIBUTE((noinline)) int
mutex_ref (pthread_mutex_t *m)
{
  int r = 0;

  pthread_spin_lock (&mutex_global);

  if (!m || !*m)
  {
    pthread_spin_unlock (&mutex_global);
    return EINVAL;
  }

  if (STATIC_INITIALIZER(*m))
  {
    pthread_spin_unlock (&mutex_global);
    r = mutex_static_init (m);
    pthread_spin_lock (&mutex_global);

    if (r != 0 && r != EBUSY)
    {
      pthread_spin_unlock (&mutex_global);
      return r;
    }
  }
  
  r = 0;
  
  if (!m || !*m || ((mutex_t *)*m)->valid != LIFE_MUTEX) 
    r = EINVAL;
  else
    ((mutex_t *)*m)->busy += 1;

  pthread_spin_unlock (&mutex_global);

  return r;
}

/* An unlock can simply fail with EPERM instead of auto-init (can't be owned) */
static WINPTHREADS_ATTRIBUTE((noinline)) int
mutex_ref_unlock (pthread_mutex_t *m)
{
  int r = 0;
  mutex_t *m_ = (mutex_t *)*m;

  pthread_spin_lock (&mutex_global);

  if (!m || !*m || ((mutex_t *)*m)->valid != LIFE_MUTEX) 
    r = EINVAL;
  else if (STATIC_INITIALIZER(*m) || !COND_LOCKED(m_))
    r = EPERM;
  else
    ((mutex_t *)*m)->busy ++;

  pthread_spin_unlock (&mutex_global);

  return r;
}

/* doesn't lock the mutex but set it to invalid in a thread-safe way */
/* A busy mutex can't be destroyed -> EBUSY */
static WINPTHREADS_ATTRIBUTE((noinline)) int
mutex_ref_destroy (pthread_mutex_t *m, pthread_mutex_t *mDestroy)
{
  pthread_mutex_t mx;
  mutex_t *m_;
  int r = 0;

  if (!m || !*m)
    return EINVAL;

  *mDestroy = NULL;
  /* also considered as busy, any concurrent access prevents destruction: */
  mx = *m;
  r = pthread_mutex_trylock (&mx);
  if (r)
    return r;

  pthread_spin_lock (&mutex_global);

  if (!*m)
    r = EINVAL;
  else
  {
    m_ = (mutex_t *)*m;
    if (STATIC_INITIALIZER(*m))
      *m = NULL;
    else  if (m_->valid != LIFE_MUTEX)
      r = EINVAL;
    else if (m_->busy)
      r = 0xbeef;
    else
    {
      *mDestroy = *m;
      *m = NULL;
    }
  }

  if (r)
    {
      pthread_spin_unlock (&mutex_global);
      pthread_mutex_unlock (&mx);
    }
  return r;
}

static WINPTHREADS_ATTRIBUTE((noinline)) int
mutex_ref_init (pthread_mutex_t *m)
{
    int r = 0;

    pthread_spin_lock (&mutex_global);
    
    if (!m)  r = EINVAL;

    if (r) 
      pthread_spin_unlock (&mutex_global);
    return r;
}

#ifdef WINPTHREAD_DBG
static int print_state = 1;

void mutex_print_set (int state)
{
    print_state = state;
}

void mutex_print (volatile pthread_mutex_t *m, char *txt)
{
  if (!print_state) 
    return;
  mutex_t *m_ = (mutex_t *)*m;
  if (m_ == NULL) {
    printf("M%p %d %s\n",*m,(int)GetCurrentThreadId(),txt);
  } else {
    printf("M%p %d V=%0X B=%d t=%d o=%d C=%d R=%d H=%p %s\n",
            *m, 
            (int)GetCurrentThreadId(), 
            (int)m_->valid, 
            (int)m_->busy,
            m_->type,
            (int)GET_OWNER(m_),(int)(m_->count),(int)GET_RCNT(m_),GET_HANDLE(m_),txt);
  }
}
#endif

static WINPTHREADS_ATTRIBUTE((noinline)) int
mutex_static_init (pthread_mutex_t *m)
{
  static pthread_mutexattr_t mxattr_recursive = PTHREAD_MUTEX_RECURSIVE;
  static pthread_mutexattr_t mxattr_errorcheck = PTHREAD_MUTEX_ERRORCHECK;

  int r;

  pthread_spin_lock (&mutex_global_static);
  if (!STATIC_INITIALIZER(*m))
      /* Assume someone crept in between: */
      r = 0;
  else
  {
    if (*m == PTHREAD_MUTEX_INITIALIZER)
      r = pthread_mutex_init (m, NULL);
    else if (*m == PTHREAD_RECURSIVE_MUTEX_INITIALIZER)
      r = pthread_mutex_init (m, &mxattr_recursive);
    else if (*m == PTHREAD_ERRORCHECK_MUTEX_INITIALIZER)
      r = pthread_mutex_init (m, &mxattr_errorcheck);
    else if (*m == NULL)
      r = EINVAL;
    else
      r = pthread_mutex_init (m, NULL);
  }
  
  pthread_spin_unlock (&mutex_global_static);
  return r;
}

static int pthread_mutex_lock_intern(pthread_mutex_t *m, DWORD timeout);

int
pthread_mutex_lock (pthread_mutex_t *m)
{
  return pthread_mutex_lock_intern (m, INFINITE);
}

static int
pthread_mutex_lock_intern (pthread_mutex_t *m, DWORD timeout)
{
  mutex_t *_m;
  int r;
  HANDLE h;

  r = mutex_ref (m);
  if (r)
    return r;

  _m = (mutex_t *) *m;
  if (_m->type != PTHREAD_MUTEX_NORMAL)
  {
    if (COND_LOCKED(_m))
    {
      if (COND_OWNER(_m))
      {
	    if (_m->type == PTHREAD_MUTEX_RECURSIVE)
	    {
	      InterlockedIncrement(&_m->count);
	      return mutex_unref(m,0);
	    }

	    return mutex_unref(m, EDEADLK);
      }
    }
  }
  
  h = _m->h;
  mutex_unref (m, 0);

  r = do_sema_b_wait_intern (h, 1, timeout);

  if (r != 0)
    return r;

  r = mutex_ref (m);
  if (r)
    return r;

  _m->count = 1;
  SET_OWNER(_m);

  return mutex_unref (m, r);
}

int pthread_mutex_timedlock(pthread_mutex_t *m, const struct timespec *ts)
{
  unsigned long long t, ct;
  int r;
  mutex_t *_m;

  if (!ts) 
    return pthread_mutex_lock(m);
    
  r = mutex_ref(m);
  if (r) 
    return r;

  /* Try to lock it without waiting */
  r = _mutex_trylock (m);
  if (r != EBUSY) 
    return mutex_unref(m,r);
    
  _m = (mutex_t *)*m;
  if (_m->type != PTHREAD_MUTEX_NORMAL && COND_LOCKED(_m) && COND_OWNER(_m))
    return mutex_unref(m,EDEADLK);
  
  ct = _pthread_time_in_ms();
  t = _pthread_time_in_ms_from_timespec(ts);
  mutex_unref(m,r);
  r = pthread_mutex_lock_intern(m, (ct > t ? 0 : (t - ct)));
  return  r;
}

int pthread_mutex_unlock(pthread_mutex_t *m)
{    
  mutex_t *_m;
  int r = mutex_ref_unlock(m);
  
  if(r) {
    return r;
  }

  _m = (mutex_t *)*m;

  if (_m->type == PTHREAD_MUTEX_NORMAL)
  {
    if (!COND_LOCKED(_m))
      {
		  return mutex_unref(m, EPERM);
      }
  }
  else if (!COND_LOCKED(_m) || !COND_OWNER(_m)) {
    return mutex_unref(m,EPERM);
  }
  
  if (_m->type == PTHREAD_MUTEX_RECURSIVE)
  {
    if(InterlockedDecrement(&_m->count)) {
	  return mutex_unref(m,0);
	}
  }
  UNSET_OWNER(_m);

  if (_m->h != NULL && !ReleaseSemaphore(_m->h, 1, NULL)) {
  	SET_OWNER(_m);
    /* restore our own bookkeeping */
    return mutex_unref(m,EPERM);
  }

  return mutex_unref(m,0);
}

static WINPTHREADS_ATTRIBUTE((noinline)) int
_mutex_trylock(pthread_mutex_t *m)
{
  int r = 0;
  mutex_t *_m = (mutex_t *)*m;
  
  if (_m->type != PTHREAD_MUTEX_NORMAL)
  {
    if (COND_LOCKED(_m))
    {
      if (_m->type == PTHREAD_MUTEX_RECURSIVE && COND_OWNER(_m))
	  {
	    InterlockedIncrement(&_m->count);
	    return 0;
	  }
	
	  return EBUSY;
    }
  } else if (COND_LOCKED(_m))
    return EBUSY;
    
  r = do_sema_b_wait_intern (_m->h, 1, 0);
  
  if (r == ETIMEDOUT) 
    r = EBUSY;
  else if (!r)
  {
    _m->count = 1;
    SET_OWNER(_m);
  }
  
  return r;
}

int pthread_mutex_trylock(pthread_mutex_t *m)
{
  int r = mutex_ref(m);
  if(r) 
    return r;

  return mutex_unref(m,_mutex_trylock(m));
}

int
pthread_mutex_init (pthread_mutex_t *m, const pthread_mutexattr_t *a)
{
  mutex_t *_m;

  int r = mutex_ref_init (m);
  if (r) 
    return r;

  if (!(_m = (pthread_mutex_t)calloc(1,sizeof(*_m))))
    {
      pthread_spin_unlock (&mutex_global);
      return ENOMEM;
    }

  _m->type = PTHREAD_MUTEX_DEFAULT;
  _m->count = 0;
  _m->busy = 0;

  if (a)
  {
    int share = PTHREAD_PROCESS_PRIVATE;
    r = pthread_mutexattr_gettype (a, &_m->type);
    if (!r)
      r = pthread_mutexattr_getpshared(a, &share);
    
    if (!r && share == PTHREAD_PROCESS_SHARED)
      r = ENOSYS;
  }
  
  if (!r)
  {
    if ((_m->h = CreateSemaphore(NULL, 1, 0x7fffffff, NULL)) == NULL)
    {
      switch (GetLastError()) {
        case ERROR_ACCESS_DENIED:
          r = EPERM;
            break;
        default: /* We assume this, to keep it simple: */
            r = ENOMEM;
      }
    }
  } 
  
  if (r)
  {
    _m->valid = DEAD_MUTEX;
    free(_m);
    *m = NULL;
    pthread_spin_unlock (&mutex_global);
    return r;
  }

  _m->valid = LIFE_MUTEX;
  *m = _m;
  pthread_spin_unlock (&mutex_global);

  return 0;
}

int pthread_mutex_destroy (pthread_mutex_t *m)
{
  mutex_t *_m;
  pthread_mutex_t mDestroy;
  int r;
  
  while ((r = mutex_ref_destroy (m, &mDestroy)) == 0xbeef)
    Sleep (0);
  if (r)
    return r;

  if (!mDestroy)
  {
    pthread_spin_unlock (&mutex_global);
    return 0; /* destroyed a (still) static initialized mutex */
  }

  /* now the mutex is invalid, and no one can touch it */
  _m = (mutex_t *)mDestroy;

  CloseHandle (_m->h);
  _m->valid = DEAD_MUTEX;
  _m->type  = 0;
  _m->count = 0;
  _m->busy = 0;
  free (mDestroy);
  *m = NULL;
  pthread_spin_unlock (&mutex_global);

  return 0;
}

int pthread_mutexattr_init(pthread_mutexattr_t *a)
{
  *a = PTHREAD_MUTEX_NORMAL | (PTHREAD_PROCESS_PRIVATE << 3);
  return 0;
}

int pthread_mutexattr_destroy(pthread_mutexattr_t *a)
{
  if (!a)
    return EINVAL;

  return 0;
}

int pthread_mutexattr_gettype(const pthread_mutexattr_t *a, int *type)
{
  if (!a || !type)
    return EINVAL;
	
  *type = *a & 3;
  
  return 0;
}

int pthread_mutexattr_settype(pthread_mutexattr_t *a, int type)
{
    if (!a || (type != PTHREAD_MUTEX_NORMAL && type != PTHREAD_MUTEX_RECURSIVE && type != PTHREAD_MUTEX_ERRORCHECK))
      return EINVAL;
    *a &= ~3;
    *a |= type;

    return 0;
}

int pthread_mutexattr_getpshared(const pthread_mutexattr_t *a, int *type)
{
    if (!a || !type)
      return EINVAL;
    *type = (*a & 4 ? PTHREAD_PROCESS_SHARED : PTHREAD_PROCESS_PRIVATE);

    return 0;
}

int pthread_mutexattr_setpshared(pthread_mutexattr_t * a, int type)
{
    int r = 0;
    if (!a || (type != PTHREAD_PROCESS_SHARED
	&& type != PTHREAD_PROCESS_PRIVATE))
      return EINVAL;
    if (type == PTHREAD_PROCESS_SHARED)
    {
      type = PTHREAD_PROCESS_PRIVATE;
      r = ENOSYS;
    }
    type = (type == PTHREAD_PROCESS_SHARED ? 4 : 0);

    *a &= ~4;
    *a |= type;

    return r;
}

int pthread_mutexattr_getprotocol(const pthread_mutexattr_t *a, int *type)
{
    *type = *a & (8 + 16);

    return 0;
}

int pthread_mutexattr_setprotocol(pthread_mutexattr_t *a, int type)
{
    if ((type & (8 + 16)) != 8 + 16) return EINVAL;

    *a &= ~(8 + 16);
    *a |= type;

    return 0;
}

int pthread_mutexattr_getprioceiling(const pthread_mutexattr_t *a, int * prio)
{
    *prio = *a / PTHREAD_PRIO_MULT;
    return 0;
}

int pthread_mutexattr_setprioceiling(pthread_mutexattr_t *a, int prio)
{
    *a &= (PTHREAD_PRIO_MULT - 1);
    *a += prio * PTHREAD_PRIO_MULT;

    return 0;
}
