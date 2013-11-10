/*
   Copyright (c) 2013 mingw-w64 project

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
#include <stdio.h>
#include <malloc.h>
#include "pthread.h"
#include "misc.h"

/* In theory, owner and locks are in CRITICAL_SECTION as well.
In practise, however, the implementation of CRITICAL_SECTION
should be regarded as opaque. That's why we replicate these
members. */
typedef struct spin_t {
   DWORD owner;
   DWORD locks;
   CRITICAL_SECTION section;
} spin_t;

static CRITICAL_SECTION global_lock;

__attribute__((constructor))
static void
global_spin_ctor (void)
{
  InitializeCriticalSection (&global_lock);
}

__attribute__((destructor))
static void
global_spin_dtor (void)
{
  DeleteCriticalSection (&global_lock);
}


static int
static_spin_init (pthread_spinlock_t* lock)
{
  if (PTHREAD_SPINLOCK_INITIALIZER == *lock)
    {
      EnterCriticalSection (&global_lock);
      if (PTHREAD_SPINLOCK_INITIALIZER == *lock)
        {
          int initrv = pthread_spin_init (lock, PTHREAD_PROCESS_PRIVATE);
          if (initrv < 0)
            {
              LeaveCriticalSection (&global_lock);
              return initrv;
            }
        }
      LeaveCriticalSection (&global_lock);
    }
  return 0;
}

int
pthread_spin_init (pthread_spinlock_t *lock, int pshared)
{
  spin_t *spin;

  if (!lock)
    return EINVAL; 

  if (pshared != PTHREAD_PROCESS_PRIVATE)
    return ENOTSUP;

  if (!(spin = (spin_t*) calloc (1, sizeof(*spin))))
    return ENOMEM;

  InitializeCriticalSection (&spin->section);
  *lock = spin;
  return 0;
}


int
pthread_spin_destroy (pthread_spinlock_t *lock)
{
  spin_t *spin;

  if (!lock || !*lock)
    return EINVAL;

  EnterCriticalSection (&global_lock);
  if (*lock == PTHREAD_SPINLOCK_INITIALIZER)
    {
      *lock = NULL;
      LeaveCriticalSection (&global_lock);
      return 0;
    }

  spin = (spin_t*)*lock;
  if (spin->owner && spin->owner != GetCurrentThreadId ())
    return EPERM;

  DeleteCriticalSection (&spin->section);
  free (spin);
  *lock = NULL;
  LeaveCriticalSection (&global_lock);
  return 0;
}

int
pthread_spin_lock (pthread_spinlock_t *lock)
{
  spin_t *spin;
  int rv = 0;

  if (!lock || !*lock)
    return EINVAL;

  rv = static_spin_init (lock);
  if (rv < 0)
    return rv;

  spin = (spin_t*)*lock;
  EnterCriticalSection (&spin->section);
  spin->owner = GetCurrentThreadId ();
  spin->locks++;
  return 0;
}
  
int
pthread_spin_trylock (pthread_spinlock_t *lock)
{
  spin_t *spin;
  int rv = 0;

  if (!lock || !*lock)
    return EINVAL;

  rv = static_spin_init (lock);
  if (rv < 0)
    return rv;

  spin = (spin_t*)*lock;
  if (!TryEnterCriticalSection (&spin->section))
    return EBUSY;

  spin->owner = GetCurrentThreadId ();
  spin->locks++;
  return 0;
}


int
pthread_spin_unlock (pthread_spinlock_t *lock)
{
  spin_t *spin;

  if (!lock || !*lock)
    return EINVAL;

  if (*lock == PTHREAD_SPINLOCK_INITIALIZER)
    return EPERM;

  spin = (spin_t*)*lock;
  if (spin->owner != GetCurrentThreadId ())
    return EPERM;

  if (!--spin->locks)
    spin->owner = 0;
  LeaveCriticalSection (&spin->section);
  return 0;
}
