/*
   Copyright (c) 2011-2016  mingw-w64 project

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

/*
 * Posix Condition Variables for Microsoft Windows.
 * 22-9-2010 Partly based on the ACE framework implementation.
 */

#define WINPTHREAD_COND_DECL WINPTHREAD_API

#include "misc.h"

#include <stdlib.h> /* calloc, free */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

int __pthread_shallcancel (void); /* in thread.c */

static int do_sema_b_wait (HANDLE sema, int flags, const struct _timespec64 *timeout, pthread_mutex_t *mutex, LONG *val);
static int do_sema_b_release (HANDLE sema, LONG count, pthread_mutex_t *mutex, LONG *val);
static void cleanup_wait(void *arg);

typedef struct sCondWaitHelper {
    cond_t *c;
    pthread_mutex_t *external_mutex;
    int *r;
} sCondWaitHelper;

/**
 * Note that this function is also used in sem.c.
 */
int do_sema_b_wait_intern (HANDLE sema, int flags, const struct _timespec64 *timeout);

static pthread_spinlock_t cond_locked = PTHREAD_SPINLOCK_INITIALIZER;

static int
cond_static_init (pthread_cond_t *c)
{
  int r = 0;

  pthread_spin_lock (&cond_locked);
  if (c == NULL)
    r = EINVAL;
  else if (*c == PTHREAD_COND_INITIALIZER)
    r = pthread_cond_init (c, NULL);
  else
    /* We assume someone was faster ... */
    r = 0;
  pthread_spin_unlock (&cond_locked);
  return r;
}

int
pthread_condattr_destroy (pthread_condattr_t *a)
{
  if (!a)
    return EINVAL;
   *a = 0;
   return 0;
}

int
pthread_condattr_init (pthread_condattr_t *a)
{
  if (!a)
    return EINVAL;
  *a = 0;
  return 0;
}

int
pthread_condattr_getpshared (const pthread_condattr_t *a, int *s)
{
  if (!a || !s)
    return EINVAL;
  *s = *a;
  return 0;
}

int
pthread_condattr_getclock (const pthread_condattr_t *a, clockid_t *clock_id)
{
  if (!a || !clock_id)
    return EINVAL;
  *clock_id = 0;
  return 0;
}

int
pthread_condattr_setclock(pthread_condattr_t *a, clockid_t clock_id)
{
  if (!a || clock_id != 0)
    return EINVAL;
  return 0;
}

int
pthread_condattr_setpshared (pthread_condattr_t *a, int s)
{
  if (!a || (s != PTHREAD_PROCESS_SHARED && s != PTHREAD_PROCESS_PRIVATE))
    return EINVAL;
  if (s == PTHREAD_PROCESS_SHARED)
    {
       *a = PTHREAD_PROCESS_PRIVATE;
       return ENOSYS;
    }
  *a = s;
  return 0;
}

int
pthread_cond_init (pthread_cond_t *c, const pthread_condattr_t *a)
{
  cond_t *_c;
  int r = 0;

  if (!c)
    return EINVAL;
  if (a && *a == PTHREAD_PROCESS_SHARED)
    return ENOSYS;

  if ((_c = calloc(1, sizeof(*_c))) == NULL)
    return ENOMEM;

  _c->valid  = DEAD_COND;
  _c->busy = 0;
  _c->waiters_count_ = 0;
  _c->waiters_count_gone_ = 0;
  _c->waiters_count_unblock_ = 0;

  _c->sema_q = CreateSemaphore (NULL,       /* no security */
      0,          /* initially 0 */
      0x7fffffff, /* max count */
      NULL);      /* unnamed  */

  if (_c->sema_q == NULL) {
    r = EAGAIN;
    goto fail_sema_q;
  }

  _c->sema_b =  CreateSemaphore (NULL,       /* no security */
      0,          /* initially 0 */
      0x7fffffff, /* max count */
      NULL);

  if (_c->sema_b == NULL) {
    r = EAGAIN;
    goto fail_sema_b;
  }

  r = pthread_mutex_init (&_c->waiters_count_lock_, NULL);

  if (r != 0) {
    goto fail_waiters_count_lock;
  }

  r = pthread_mutex_init (&_c->waiters_q_lock_, NULL);

  if (r != 0) {
    goto fail_waiters_q_lock;
  }

  r = pthread_mutex_init (&_c->waiters_b_lock_, NULL);

  if (r != 0) {
    goto fail_waiters_b_lock;
  }

  _c->value_q = 0;
  _c->value_b = 1;
  _c->valid = LIFE_COND;
  *c = (pthread_cond_t)_c;

  return r;

fail_waiters_b_lock:
  pthread_mutex_destroy (&_c->waiters_q_lock_);
fail_waiters_q_lock:
  pthread_mutex_destroy (&_c->waiters_count_lock_);
fail_waiters_count_lock:
  CloseHandle (_c->sema_b);
fail_sema_b:
  CloseHandle (_c->sema_q);
fail_sema_q:
  free (_c);
  *c = (pthread_cond_t)NULL;

  return r;
}

int
pthread_cond_destroy (pthread_cond_t *c)
{
  cond_t *_c;
  int r;
  if (!c || !*c)
    return EINVAL;
  if (*c == PTHREAD_COND_INITIALIZER)
    {
      pthread_spin_lock (&cond_locked);
      if (*c == PTHREAD_COND_INITIALIZER)
      {
	*c = (pthread_cond_t)NULL;
	r = 0;
      }
      else
	r = EBUSY;
      pthread_spin_unlock (&cond_locked);
      return r;
    }
  _c = (cond_t *) *c;
  r = do_sema_b_wait (_c->sema_b, WINPTHREADS_WAIT_CANCELLATION_NOTIFICATION, WINPTHREADS_WAIT_TIMEOUT_INDEFINITE, &_c->waiters_b_lock_, &_c->value_b);
  if (r != 0)
    return r;
  if (0 != pthread_mutex_trylock (&_c->waiters_count_lock_))
    {
       do_sema_b_release (_c->sema_b, 1,&_c->waiters_b_lock_,&_c->value_b);
       return EBUSY;
    }
  if (_c->waiters_count_ > _c->waiters_count_gone_)
    {
      r = do_sema_b_release (_c->sema_b, 1,&_c->waiters_b_lock_,&_c->value_b);
      if (!r) r = EBUSY;
      pthread_mutex_unlock (&_c->waiters_count_lock_);
      return r;
    }
  *c = (pthread_cond_t)NULL;
  do_sema_b_release (_c->sema_b, 1,&_c->waiters_b_lock_,&_c->value_b);

  if (!CloseHandle (_c->sema_q) && !r)
    r = EINVAL;
  if (!CloseHandle (_c->sema_b) && !r)
    r = EINVAL;
  pthread_mutex_unlock (&_c->waiters_count_lock_);
  pthread_mutex_destroy (&_c->waiters_count_lock_);
  pthread_mutex_destroy (&_c->waiters_b_lock_);
  pthread_mutex_destroy (&_c->waiters_q_lock_);
  _c->valid  = DEAD_COND;
  free(_c);
  return 0;
}

int
pthread_cond_signal (pthread_cond_t *c)
{
  cond_t *_c;
  int r;

  if (!c || !*c)
    return EINVAL;
  _c = (cond_t *)*c;
  if (_c == (cond_t *)PTHREAD_COND_INITIALIZER)
    return 0;
  else if (_c->valid != (unsigned int)LIFE_COND)
    return EINVAL;

  pthread_mutex_lock (&_c->waiters_count_lock_);
  /* If there aren't any waiters, then this is a no-op.   */
  if (_c->waiters_count_unblock_ != 0)
    {
      if (_c->waiters_count_ == 0)
      {
	pthread_mutex_unlock (&_c->waiters_count_lock_);
	/* pthread_testcancel(); */
	return 0;
      }
      _c->waiters_count_ -= 1;
      _c->waiters_count_unblock_ += 1;
    }
  else if (_c->waiters_count_ > _c->waiters_count_gone_)
    {
      r = do_sema_b_wait (_c->sema_b, 0, WINPTHREADS_WAIT_TIMEOUT_INDEFINITE, &_c->waiters_b_lock_, &_c->value_b);
      if (r != 0)
      {
	pthread_mutex_unlock (&_c->waiters_count_lock_);
	/* pthread_testcancel(); */
	return r;
      }
      if (_c->waiters_count_gone_ != 0)
      {
	_c->waiters_count_ -= _c->waiters_count_gone_;
	_c->waiters_count_gone_ = 0;
      }
      _c->waiters_count_ -= 1;
      _c->waiters_count_unblock_ = 1;
    }
  else
    {
      pthread_mutex_unlock (&_c->waiters_count_lock_);
      /* pthread_testcancel(); */
      return 0;
    }
  pthread_mutex_unlock (&_c->waiters_count_lock_);
  r = do_sema_b_release(_c->sema_q, 1,&_c->waiters_q_lock_,&_c->value_q);
  /* pthread_testcancel(); */
  return r;
}

int
pthread_cond_broadcast (pthread_cond_t *c)
{
  cond_t *_c;
  int r;
  int relCnt = 0;

  if (!c || !*c)
    return EINVAL;
  _c = (cond_t *)*c;
  if (_c == (cond_t*)PTHREAD_COND_INITIALIZER)
    return 0;
  else if (_c->valid != (unsigned int)LIFE_COND)
    return EINVAL;

  pthread_mutex_lock (&_c->waiters_count_lock_);
  /* If there aren't any waiters, then this is a no-op.   */
  if (_c->waiters_count_unblock_ != 0)
    {
      if (_c->waiters_count_ == 0)
      {
	pthread_mutex_unlock (&_c->waiters_count_lock_);
	/* pthread_testcancel(); */
	return 0;
      }
      relCnt = _c->waiters_count_;
      _c->waiters_count_ = 0;
      _c->waiters_count_unblock_ += relCnt;
    }
  else if (_c->waiters_count_ > _c->waiters_count_gone_)
    {
      r = do_sema_b_wait (_c->sema_b, 0, WINPTHREADS_WAIT_TIMEOUT_INDEFINITE, &_c->waiters_b_lock_, &_c->value_b);
      if (r != 0)
      {
	pthread_mutex_unlock (&_c->waiters_count_lock_);
	/* pthread_testcancel(); */
	return r;
      }
      if (_c->waiters_count_gone_ != 0)
      {
	_c->waiters_count_ -= _c->waiters_count_gone_;
	_c->waiters_count_gone_ = 0;
      }
      relCnt = _c->waiters_count_;
      _c->waiters_count_ = 0;
      _c->waiters_count_unblock_ = relCnt;
    }
  else
    {
      pthread_mutex_unlock (&_c->waiters_count_lock_);
      /* pthread_testcancel(); */
      return 0;
    }
  pthread_mutex_unlock (&_c->waiters_count_lock_);
  r = do_sema_b_release(_c->sema_q, relCnt,&_c->waiters_q_lock_,&_c->value_q);
  /* pthread_testcancel(); */
  return r;
}

int
pthread_cond_wait (pthread_cond_t *c, pthread_mutex_t *external_mutex)
{
  sCondWaitHelper ch;
  cond_t *_c;
  int r;

  /* pthread_testcancel(); */

  if (!c || *c == (pthread_cond_t)NULL)
    return EINVAL;
  _c = (cond_t *)*c;
  if (*c == PTHREAD_COND_INITIALIZER)
  {
    r = cond_static_init(c);
    if (r != 0 && r != EBUSY)
      return r;
    _c = (cond_t *) *c;
  } else if (_c->valid != (unsigned int)LIFE_COND)
    return EINVAL;

tryagain:
  r = do_sema_b_wait (_c->sema_b, WINPTHREADS_WAIT_CANCELLATION_NOTIFICATION, WINPTHREADS_WAIT_TIMEOUT_INDEFINITE, &_c->waiters_b_lock_, &_c->value_b);
  if (r != 0)
    return r;

  if (0 != pthread_mutex_trylock (&_c->waiters_count_lock_))
  {
    r = do_sema_b_release (_c->sema_b, 1,&_c->waiters_b_lock_,&_c->value_b);
    if (r != 0)
      return r;
    sched_yield();
    goto tryagain;
  }

  _c->waiters_count_++;
  pthread_mutex_unlock (&_c->waiters_count_lock_);
  r = do_sema_b_release (_c->sema_b, 1,&_c->waiters_b_lock_,&_c->value_b);
  if (r != 0)
    return r;

  ch.c = _c;
  ch.r = &r;
  ch.external_mutex = external_mutex;

  pthread_cleanup_push(cleanup_wait, (void *) &ch);
  r = pthread_mutex_unlock(external_mutex);
  if (!r)
    r = do_sema_b_wait (_c->sema_q, WINPTHREADS_WAIT_CANCELLATION_NOTIFICATION, WINPTHREADS_WAIT_TIMEOUT_INDEFINITE, &_c->waiters_q_lock_, &_c->value_q);

  pthread_cleanup_pop(1);
  return r;
}

static int
pthread_cond_timedwait_impl (pthread_cond_t *c, pthread_mutex_t *external_mutex, const struct _timespec64 *t, int rel)
{
  sCondWaitHelper ch;
  int r;
  cond_t *_c;

  /* pthread_testcancel(); */

  if (!c || !*c)
    return EINVAL;
  _c = (cond_t *)*c;
  if (_c == (cond_t *)PTHREAD_COND_INITIALIZER)
  {
    r = cond_static_init(c);
    if (r && r != EBUSY)
      return r;
    _c = (cond_t *) *c;
  } else if ((_c)->valid != (unsigned int)LIFE_COND)
    return EINVAL;

  /**
   * `pthread_cond_timedwait` is a cancellation point.
   */
  int waitFlags = WINPTHREADS_WAIT_CANCELLATION_NOTIFICATION;

  if (rel == 0) {
    waitFlags |= WINPTHREADS_WAIT_TIMEOUT_ABSTIME;
  }

tryagain:
  r = do_sema_b_wait (_c->sema_b, waitFlags, WINPTHREADS_WAIT_TIMEOUT_INDEFINITE, &_c->waiters_b_lock_, &_c->value_b);
  if (r != 0)
    return r;

  if (0 != pthread_mutex_trylock (&_c->waiters_count_lock_))
  {
    r = do_sema_b_release (_c->sema_b, 1,&_c->waiters_b_lock_,&_c->value_b);
    if (r != 0)
      return r;
    sched_yield();
    goto tryagain;
  }

  _c->waiters_count_++;
  pthread_mutex_unlock (&_c->waiters_count_lock_);
  r = do_sema_b_release (_c->sema_b, 1,&_c->waiters_b_lock_,&_c->value_b);
  if (r != 0)
    return r;

  ch.c = _c;
  ch.r = &r;
  ch.external_mutex = external_mutex;
  {
    pthread_cleanup_push(cleanup_wait, (void *) &ch);

    r = pthread_mutex_unlock(external_mutex);
    if (!r)
      r = do_sema_b_wait (_c->sema_q, waitFlags, t, &_c->waiters_q_lock_, &_c->value_q);
    pthread_cleanup_pop(1);
  }
  return r;
}

int
pthread_cond_timedwait64(pthread_cond_t *c, pthread_mutex_t *m, const struct _timespec64 *t)
{
  return pthread_cond_timedwait_impl(c, m, t, 0);
}

int
pthread_cond_timedwait32(pthread_cond_t *c, pthread_mutex_t *m, const struct _timespec32 *t)
{
  struct _timespec64 t64 = {.tv_sec = t->tv_sec, .tv_nsec = t->tv_nsec};
  return pthread_cond_timedwait_impl(c, m, &t64, 0);
}

int
pthread_cond_timedwait64_relative_np(pthread_cond_t *c, pthread_mutex_t *m, const struct _timespec64 *t)
{
  return pthread_cond_timedwait_impl(c, m, t, 1);
}

int
pthread_cond_timedwait32_relative_np(pthread_cond_t *c, pthread_mutex_t *m, const struct _timespec32 *t)
{
  struct _timespec64 t64 = {.tv_sec = t->tv_sec, .tv_nsec = t->tv_nsec};
  return pthread_cond_timedwait_impl(c, m, &t64, 1);
}

static void
cleanup_wait (void *arg)
{
  int n, r;
  sCondWaitHelper *ch = (sCondWaitHelper *) arg;
  cond_t *_c;

  _c = ch->c;
  pthread_mutex_lock (&_c->waiters_count_lock_);
  n = _c->waiters_count_unblock_;
  if (n != 0)
    _c->waiters_count_unblock_ -= 1;
  else if ((INT_MAX/2) - 1 == _c->waiters_count_gone_)
  {
    _c->waiters_count_gone_ += 1;
    r = do_sema_b_wait (_c->sema_b, 0, WINPTHREADS_WAIT_TIMEOUT_INDEFINITE, &_c->waiters_b_lock_, &_c->value_b);
    if (r != 0)
    {
      pthread_mutex_unlock (&_c->waiters_count_lock_);
      ch->r[0] = r;
      return;
    }
    _c->waiters_count_ -= _c->waiters_count_gone_;
    r = do_sema_b_release (_c->sema_b, 1,&_c->waiters_b_lock_,&_c->value_b);
    if (r != 0)
    {
      pthread_mutex_unlock (&_c->waiters_count_lock_);
      ch->r[0] = r;
      return;
    }
    _c->waiters_count_gone_ = 0;
  }
  else
    _c->waiters_count_gone_ += 1;
  pthread_mutex_unlock (&_c->waiters_count_lock_);

  if (n == 1)
  {
    r = do_sema_b_release (_c->sema_b, 1,&_c->waiters_b_lock_,&_c->value_b);
    if (r != 0)
    {
      ch->r[0] = r;
      return;
    }
  }
  r = pthread_mutex_lock(ch->external_mutex);
  if (r != 0)
    ch->r[0] = r;
}

static int
do_sema_b_wait (HANDLE sema, int flags, const struct _timespec64 *timeout, pthread_mutex_t *mutex, LONG *val)
{
  int r;
  LONG v;
  pthread_mutex_lock (mutex);
  InterlockedDecrement(val);
  v = val[0];
  pthread_mutex_unlock (mutex);
  if (v >= 0)
    return 0;
  r = do_sema_b_wait_intern (sema, flags, timeout);
  pthread_mutex_lock (mutex);
  if (r != 0)
    InterlockedIncrement(val);
  pthread_mutex_unlock (mutex);
  return r;
}

int
do_sema_b_wait_intern (HANDLE sema, int flags, const struct _timespec64 *timeout)
{
  int error_code;

  do {
    switch (winpthreads_wait (sema, flags, CLOCK_REALTIME, timeout, NULL)) {
      case wait_succeeded:
        error_code = 0;
        break;
      /**
       * The calling thread received cancellation notification.
       */
      case wait_interrupted:
        pthread_testcancel ();
        error_code = EINTR;
        break;
      case wait_timeout_expired:
        error_code = ETIMEDOUT;
        break;
      case wait_failed:
        error_code = EINVAL;
        break;
      case wait_abandoned_mutex:
        UNREACHABLE ();
    }
  } while (error_code == EINTR);

  if (error_code != 0 && (flags & WINPTHREADS_WAIT_CANCELLATION_NOTIFICATION)) {
    pthread_testcancel ();
  }

  return error_code;
}

static int
do_sema_b_release(HANDLE sema, LONG count, pthread_mutex_t *mutex, LONG *val)
{
  int wc;
  pthread_mutex_lock (mutex);
  if (((long long) val[0] + (long long) count) > (long long) 0x7fffffffLL)
  {
    pthread_mutex_unlock (mutex);
    return ERANGE;
  }
  wc = -val[0];
  InterlockedExchangeAdd(val, count);
  if (wc <= 0 || ReleaseSemaphore(sema, (wc < count ? wc : count), NULL))
  {
    pthread_mutex_unlock (mutex);
    return 0;
  }
  InterlockedExchangeAdd(val, -count);
  pthread_mutex_unlock (mutex);
  return EINVAL;
}
