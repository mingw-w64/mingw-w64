AM_CPPFLAGS = -I$(top_srcdir)/src -I$(top_srcdir)/include
AM_LDFLAGS = -L$(top_builddir)

if !MSVC
AM_LDFLAGS += -L$(top_builddir)/fakelib
endif

LDADD = $(top_builddir)/libwinpthread.la

check_PROGRAMS =            \
	clock/t_clock_getres    \
	clock/t_clock_gettime   \
	clock/t_clock_nanosleep \
	clock/t_clock_settime   \
	clock/t_nanosleep

TESTS = $(check_PROGRAMS)
