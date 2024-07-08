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

#include <windows.h>
#include <stdio.h>
#include "pthread.h"
#include "thread.h"
#include "misc.h"

typedef struct {
	int policy;
	struct sched_param param;
} my_pthread_attr_t;

int sched_get_priority_min(int pol) {
	if (pol < SCHED_MIN || pol > SCHED_MAX) {
		errno = EINVAL;
		return -1;
	}
	return THREAD_PRIORITY_IDLE;
}

int sched_get_priority_max(int pol) {
	if (pol < SCHED_MIN || pol > SCHED_MAX) {
		errno = EINVAL;
		return -1;
	}
	return THREAD_PRIORITY_TIME_CRITICAL;
}

int pthread_attr_setschedparam(pthread_attr_t* attr, const struct sched_param* p) {
	if (!attr || !p) {
		return EINVAL;
	}
	memcpy(&attr->param, p, sizeof(*p));
	return 0;
}

int pthread_attr_getschedparam(const pthread_attr_t* attr, struct sched_param* p) {
	if (!attr || !p) {
		return EINVAL;
	}
	memcpy(p, &attr->param, sizeof(*p));
	return 0;
}

int pthread_attr_setschedpolicy(pthread_attr_t* attr, int pol) {
	if (!attr || pol < SCHED_MIN || pol > SCHED_MAX) {
		return EINVAL;
	}
	((my_pthread_attr_t*)attr)->policy = pol;
	return 0;
}

int pthread_attr_getschedpolicy(const pthread_attr_t* attr, int* pol) {
	if (!attr || !pol) {
		return EINVAL;
	}
	*pol = ((my_pthread_attr_t*)attr)->policy;
	return 0;
}

static int pthread_check(pthread_t t) {
	struct _pthread_v* pv;
	if (!t) {
		return ESRCH;
	}
	pv = __pth_gpointer_locked(t);
	if (pv->ended == 0) {
		return 0;
	}
	CHECK_OBJECT(pv, ESRCH);
	return 0;
}

int pthread_getschedparam(pthread_t t, int* pol, struct sched_param* p) {
	int r;
	//if (!t)
	//  t = pthread_self();
	if ((r = pthread_check(t)) != 0) {
		return r;
	}
	if (!p || !pol) {
		return EINVAL;
	}
	*pol = __pth_gpointer_locked(t)->sched_pol;
	p->sched_priority = __pth_gpointer_locked(t)->sched.sched_priority;
	return 0;
}

static int convert_posix_to_windows_priority(int posix_priority) {
	if (posix_priority <= 0) {
		return THREAD_PRIORITY_IDLE;
	}
	else if (posix_priority <= 10) {
		return THREAD_PRIORITY_LOWEST + posix_priority;
	}
	else if (posix_priority <= 20) {
		return THREAD_PRIORITY_BELOW_NORMAL + (posix_priority - 10);
	}
	else if (posix_priority <= 30) {
		return THREAD_PRIORITY_NORMAL + (posix_priority - 20);
	}
	else if (posix_priority <= 40) {
		return THREAD_PRIORITY_ABOVE_NORMAL + (posix_priority - 30);
	}
	else if (posix_priority <= 50) {
		return THREAD_PRIORITY_HIGHEST + (posix_priority - 40);
	}
	else {
		return THREAD_PRIORITY_TIME_CRITICAL;
	}
}

int pthread_setschedparam(pthread_t t, int pol, const struct sched_param* p) {
	struct _pthread_v* pv;
	int r, pr = 0;
	if ((r = pthread_check(t)) != 0) {
		return r;
	}
	if (pol < SCHED_MIN || pol > SCHED_MAX || !p) {
		return EINVAL;
	}
	if (pol != SCHED_OTHER && pol != SCHED_FIFO && pol != SCHED_RR) {
		return ENOTSUP;
	}
	pr = p->sched_priority;
	if (pr < sched_get_priority_min(pol) || pr > sched_get_priority_max(pol)) {
		return EINVAL;
	}
	pv = __pth_gpointer_locked(t);
	pv->sched_pol = pol;
	pv->sched.sched_priority = p->sched_priority;
	int win_priority;
	if (pol == SCHED_OTHER) {
		win_priority = THREAD_PRIORITY_NORMAL;
	}
	else if (pol == SCHED_FIFO || pol == SCHED_RR) {
		win_priority = convert_posix_to_windows_priority(pr);
	}
	if (!SetThreadPriority(pv->h, win_priority)) {
		errno = EINVAL;
		return -1;
	}
	return 0;
}

int sched_getscheduler(pid_t pid) {
	if (pid != 0) {
		HANDLE h = NULL;
		int selfPid = (int)GetCurrentProcessId();
		if (pid != (pid_t)selfPid && (h = OpenProcess(PROCESS_QUERY_INFORMATION, 0, (DWORD)pid)) == NULL) {
			errno = (GetLastError() == (0xFF & ERROR_ACCESS_DENIED)) ? EPERM : ESRCH;
			return -1;
		}
		if (h) {
			CloseHandle(h);
		}
	}
	return SCHED_OTHER;
}

int sched_setscheduler(pid_t pid, int pol, const struct sched_param* param) {
	if (!param) {
		errno = EINVAL;
		return -1;
	}
	if (pid != 0) {
		HANDLE h = NULL;
		int selfPid = (int)GetCurrentProcessId();
		if (pid != (pid_t)selfPid && (h = OpenProcess(PROCESS_SET_INFORMATION, 0, (DWORD)pid)) == NULL) {
			errno = (GetLastError() == (0xFF & ERROR_ACCESS_DENIED)) ? EPERM : ESRCH;
			return -1;
		}
		if (h) {
			CloseHandle(h);
		}
	}
	if (pol != SCHED_OTHER) {
		errno = ENOSYS;
		return -1;
	}
	return SCHED_OTHER;
}

int sched_yield(void) {
	Sleep(0);
	return 0;
}
