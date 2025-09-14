AM_CPPFLAGS = -I. -I$(top_srcdir)/src -I$(top_srcdir)/include
AM_CFLAGS =
AM_LDFLAGS = -L$(top_builddir)

if !MSVC
AM_CFLAGS += -Wno-error=int-conversion -Wno-error=incompatible-pointer-types
AM_LDFLAGS += -L$(top_builddir)/fakelib
endif

LDADD = $(top_builddir)/libwinpthread.la

check_LIBRARIES = \
	libbenchlib.a

libbenchlib_a_SOURCES = \
	benchtests/benchlib.c

benchtests_benchtest1_LDADD = libbenchlib.a $(LDADD)
benchtests_benchtest2_LDADD = libbenchlib.a $(LDADD)
benchtests_benchtest3_LDADD = libbenchlib.a $(LDADD)
benchtests_benchtest4_LDADD = libbenchlib.a $(LDADD)
benchtests_benchtest5_LDADD = libbenchlib.a $(LDADD)

# TODO: fix pthread_cancel/cancel9
check_PROGRAMS =               \
	benchtests/benchtest1      \
	benchtests/benchtest2      \
	benchtests/benchtest3      \
	benchtests/benchtest4      \
	benchtests/benchtest5      \
	clock/t_clock_getres       \
	clock/t_clock_gettime      \
	clock/t_clock_nanosleep    \
	clock/t_clock_settime      \
	clock/t_nanosleep          \
	exceptions/exception1      \
	exceptions/exception2      \
	exceptions/exception3      \
	misc/loadfree              \
	misc/tryentercs            \
	misc/tryentercs2           \
	pthread_barrier/barrier1   \
	pthread_barrier/barrier2   \
	pthread_barrier/barrier3   \
	pthread_barrier/barrier4   \
	pthread_barrier/barrier5   \
	pthread_barrier/barrier6   \
	pthread_cancel/cancel1     \
	pthread_cancel/cancel2     \
	pthread_cancel/cancel3     \
	pthread_cancel/cancel4     \
	pthread_cancel/cancel5     \
	pthread_cancel/cancel6a    \
	pthread_cancel/cancel6d    \
	pthread_cancel/cancel7     \
	pthread_cancel/cancel8     \
	pthread_cleanup/cleanup0   \
	pthread_cleanup/cleanup1   \
	pthread_cleanup/cleanup2   \
	pthread_cleanup/cleanup3   \
	pthread_cond/condvar1      \
	pthread_cond/condvar1_1    \
	pthread_cond/condvar1_2    \
	pthread_cond/condvar2      \
	pthread_cond/condvar2_1    \
	pthread_cond/condvar3      \
	pthread_cond/condvar3_1    \
	pthread_cond/condvar3_2    \
	pthread_cond/condvar3_3    \
	pthread_cond/condvar4      \
	pthread_cond/condvar5      \
	pthread_cond/condvar6      \
	pthread_cond/condvar7      \
	pthread_cond/condvar8      \
	pthread_cond/condvar9      \
	pthread_create/create1     \
	pthread_create/create2     \
	pthread_create/create3     \
	pthread_exit/exit1         \
	pthread_exit/exit2         \
	pthread_exit/exit3         \
	pthread_exit/exit4         \
	pthread_exit/exit5         \
	pthread_join/join1         \
	pthread_join/join2         \
	pthread_join/join3         \
	pthread_misc/context1      \
	pthread_misc/count1        \
	pthread_misc/delay1        \
	pthread_misc/delay2        \
	pthread_misc/detach1       \
	pthread_misc/equal1        \
	pthread_misc/errno1        \
	pthread_misc/eyal1         \
	pthread_misc/inherit1      \
	pthread_misc/kill1         \
	pthread_misc/reuse1        \
	pthread_misc/reuse2        \
	pthread_misc/self1         \
	pthread_misc/self2         \
	pthread_misc/stress1       \
	pthread_misc/valid1        \
	pthread_misc/valid2        \
	pthread_mutex/mutex1       \
	pthread_mutex/mutex1e      \
	pthread_mutex/mutex1n      \
	pthread_mutex/mutex1r      \
	pthread_mutex/mutex2       \
	pthread_mutex/mutex2e      \
	pthread_mutex/mutex2r      \
	pthread_mutex/mutex3       \
	pthread_mutex/mutex3e      \
	pthread_mutex/mutex3r      \
	pthread_mutex/mutex4       \
	pthread_mutex/mutex5       \
	pthread_mutex/mutex6       \
	pthread_mutex/mutex6e      \
	pthread_mutex/mutex6es     \
	pthread_mutex/mutex6n      \
	pthread_mutex/mutex6r      \
	pthread_mutex/mutex6rs     \
	pthread_mutex/mutex6s      \
	pthread_mutex/mutex7       \
	pthread_mutex/mutex7e      \
	pthread_mutex/mutex7n      \
	pthread_mutex/mutex7r      \
	pthread_mutex/mutex8       \
	pthread_mutex/mutex8e      \
	pthread_mutex/mutex8n      \
	pthread_mutex/mutex8r      \
	pthread_once/once1         \
	pthread_once/once2         \
	pthread_once/once3         \
	pthread_once/once4         \
	pthread_rwlock/rwlock1     \
	pthread_rwlock/rwlock2     \
	pthread_rwlock/rwlock2_t   \
	pthread_rwlock/rwlock3     \
	pthread_rwlock/rwlock3_t   \
	pthread_rwlock/rwlock4     \
	pthread_rwlock/rwlock4_t   \
	pthread_rwlock/rwlock5     \
	pthread_rwlock/rwlock5_t   \
	pthread_rwlock/rwlock6     \
	pthread_rwlock/rwlock6_t   \
	pthread_rwlock/rwlock6_t2  \
	pthread_rwlock/rwlock7     \
	pthread_rwlock/rwlock8     \
	pthread_spinlock/spin1     \
	pthread_spinlock/spin2     \
	pthread_spinlock/spin3     \
	pthread_spinlock/spin4     \
	pthread_tls/tsd1           \
	pthread_tls/tsd2           \
	sched/priority1            \
	sched/priority2            \
	semaphore/semaphore1       \
	semaphore/semaphore2       \
	semaphore/semaphore3       \
	semaphore/semaphore4       \
	semaphore/semaphore4t      \
	semaphore/semaphore5

TESTS = $(check_PROGRAMS)

# TODO: investigate why these tests fail
XFAIL_TESTS =              \
	pthread_mutex/mutex4   \
	pthread_mutex/mutex6e  \
	pthread_mutex/mutex6es \
	pthread_mutex/mutex7   \
	pthread_mutex/mutex7e  \
	pthread_mutex/mutex7n  \
	pthread_spinlock/spin1 \
	pthread_spinlock/spin3
