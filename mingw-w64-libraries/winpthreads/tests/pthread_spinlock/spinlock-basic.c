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
 * Create spinlock object and test basic assumptions about lock ownership
 * and lifetime.
 */

int main(void)
{
  pthread_spinlock_t lock;

  assert(pthread_spin_init(&lock, PTHREAD_PROCESS_PRIVATE) == 0);
  assert(pthread_spin_lock(&lock) == 0);
  assert(pthread_spin_lock(&lock) == EDEADLK);
  assert(pthread_spin_trylock(&lock) == EBUSY);
  assert(pthread_spin_destroy(&lock) == EBUSY);
  assert(pthread_spin_unlock(&lock) == 0);
  assert(pthread_spin_destroy(&lock) == 0);
  assert(pthread_spin_lock(&lock) == EINVAL);

  return 0;
}
