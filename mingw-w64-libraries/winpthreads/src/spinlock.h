/*
   Copyright (c) 2011 mingw-w64 project

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

#ifndef WIN_PTHREADS_SPINLOCK_H
#define WIN_PTHREADS_SPINLOCK_H

#define CHECK_SPINLOCK(l)  { \
    if (!(l) || !*l \
        || ( ((spin_t *)(*l))->valid != (unsigned int)LIFE_SPINLOCK ) ) \
        return EINVAL; }

#define CHECK_DEADLK_SL(l)
#define SET_OWNER_SL(l)	
#define SET_OWNER_SLIF(l,r)	
#define UNSET_OWNER_SL(l)

#define INIT_SPINLOCK(s)  { int r; \
    if (PTHREAD_SPINLOCK_INITIALIZER == *s) { if ((r = spinlock_static_init(s))) return r; }}

typedef struct spin_t spin_t;
struct spin_t
{
  volatile DWORD owner;
  volatile DWORD cur;
  unsigned int valid;
  volatile LONG l;
};

#define LIFE_SPINLOCK 0xFEEDBAB1
#define DEAD_SPINLOCK 0xB00FDEAD

typedef union _vol_spinlock _vol_spinlock;
union _vol_spinlock {
    LONG *l;
    volatile LONG *lv;
};

int _spin_lite_trylock (spin_t *l);
int _spin_lite_unlock (spin_t *l);
int _spin_lite_lock (spin_t *l);

#endif
