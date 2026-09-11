/*
 *      Pthreads-win32 - POSIX Threads Library for Win32
 *      Copyright(C) 1998 John E. Bossom
 *      Copyright(C) 1999,2005 Pthreads-win32 contributors
 *      Copyright(C) 2026 mingw-w64 project
 *
 *      Contact Email: mingw-w64-public@lists.sourceforge.net
 *
 *      The current list of contributors is contained
 *      in the file CONTRIBUTORS included with the source
 *      code distribution. The list can also be seen at the
 *      following World Wide Web location:
 *      http://sources.redhat.com/pthreads-win32/contributors.html
 *
 *      This library is free software; you can redistribute it and/or
 *      modify it under the terms of the GNU Lesser General Public
 *      License as published by the Free Software Foundation; either
 *      version 2 of the License, or (at your option) any later version.
 *
 *      This library is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *      Lesser General Public License for more details.
 *
 *      You should have received a copy of the GNU Lesser General Public
 *      License along with this library in the file COPYING.LIB;
 *      if not, write to the Free Software Foundation, Inc.,
 *      59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */

#include "test.h"

/**
 * Test Summary:
 *
 * Main thread M creates (statically initialized) mutex L with type
 * `PTHREAD_MUTEX_RECURSIVE`.
 *
 * Thread A locks L.
 *
 * Thread A attempts to lock L again; the call to `pthread_mutex_lock` must
 * succeed.
 *
 * Thread A unlocks L.
 *
 * Thread A attempts to unlock L again; the call to `pthread_mutex_unlock` must
 * succeed.
 *
 * Thread M destroys L.
 */

static void *ThreadA(void *arg)
{
  pthread_mutex_t *mutex = arg;

  assert(pthread_mutex_lock(mutex) == 0);
  assert(pthread_mutex_lock(mutex) == 0);
  assert(pthread_mutex_unlock(mutex) == 0);
  assert(pthread_mutex_unlock(mutex) == 0);

  return arg;
}

int main(void)
{
  pthread_mutex_t mutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER;
  pthread_t thread;
  void *result;

  assert(pthread_create(&thread, NULL, ThreadA, &mutex) == 0);
  assert(pthread_join (thread, &result) == 0);
  assert(result == &mutex);
  assert(pthread_mutex_destroy(&mutex) == 0);

  return 0;
}
