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
 * Main thread M statically initializes spin lock S and creates two threads
 * A and B.
 *
 * Threads A and B both try to lock S and unlock S. Since S is statically
 * initialized, `pthread_spin_lock` must perform actual initialization.
 * Only one thread must complete initialization and both A and B must use
 * the same spinlock object to perform synchronization.
 *
 * After both A and B terminate, M verifies that A and B used the same spinlock
 * object, and then destroys it.
 */

static struct timespec ThreadAEntryTime;
static struct timespec ThreadBEntryTime;

static void *ThreadA(void *arg)
{
  pthread_spinlock_t lock;

  assert(pthread_spin_lock((pthread_spinlock_t *) arg) == 0);
  assert (clock_gettime (CLOCK_REALTIME, &ThreadAEntryTime) == 0);
  lock = *(pthread_spinlock_t *) arg;
  assert(pthread_spin_unlock((pthread_spinlock_t *) arg) == 0);

  return (void *) lock;
}

static void *ThreadB(void *arg)
{
  pthread_spinlock_t lock;

  assert(pthread_spin_lock((pthread_spinlock_t *) arg) == 0);
  assert (clock_gettime (CLOCK_REALTIME, &ThreadBEntryTime) == 0);
  lock = *(pthread_spinlock_t *) arg;
  assert(pthread_spin_unlock((pthread_spinlock_t *) arg) == 0);

  return (void *) lock;
}

int main(void)
{
  pthread_spinlock_t lock = PTHREAD_SPINLOCK_INITIALIZER;

  pthread_t threadA;
  pthread_spinlock_t threadALock;

  pthread_t threadB;
  pthread_spinlock_t threadBLock;

  assert(pthread_create(&threadA, NULL, ThreadA, &lock) == 0);
  assert(pthread_create(&threadB, NULL, ThreadB, &lock) == 0);

  assert(pthread_join(threadA, (void **) &threadALock) == 0);
  assert(pthread_join(threadB, (void **) &threadBLock) == 0);

  wprintf(L"Thread A lock entry time: %.0f.%ld\n", (double) ThreadAEntryTime.tv_sec, ThreadAEntryTime.tv_nsec);
  wprintf(L"Thread B lock entry time: %.0f.%ld\n", (double) ThreadBEntryTime.tv_sec, ThreadBEntryTime.tv_nsec);

  assert(threadALock == threadBLock);
  assert(pthread_spin_destroy(&lock) == 0);

  return 0;
}
