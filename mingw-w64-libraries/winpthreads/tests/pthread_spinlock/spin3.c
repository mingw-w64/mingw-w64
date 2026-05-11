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
 * Main thread M create spinlock object S and locks it.
 *
 * Thread A attempts to unlock S; since S is owned by M,
 * `pthread_spin_unlock` must fail with `EPERM`.
 *
 * Thread M unlocks and destroys S.
 */

static void *thread(void *arg)
{
  assert(pthread_spin_unlock((pthread_spinlock_t *) arg) == EPERM);
  return arg;
}

int main(void)
{
  pthread_spinlock_t spin;
  pthread_t t;
  void *result;

  assert(pthread_spin_init(&spin, PTHREAD_PROCESS_PRIVATE) == 0);
  assert(pthread_spin_lock(&spin) == 0);
  assert(pthread_create(&t, NULL, thread, &spin) == 0);
  assert(pthread_join(t, &result) == 0);
  assert(result == &spin);
  assert(pthread_spin_unlock(&spin) == 0);
  assert(pthread_spin_destroy(&spin) == 0);

  return 0;
}
