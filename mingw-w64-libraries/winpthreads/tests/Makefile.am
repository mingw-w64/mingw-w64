AM_CPPFLAGS = -I$(top_srcdir)/src -I$(top_srcdir)/include
AM_LDFLAGS = -L$(top_builddir)

if !MSVC
AM_LDFLAGS += -L$(top_builddir)/fakelib
endif

LDADD = $(top_builddir)/libwinpthread.la

#FIXME: The test "test.c" is inherently broken currently.
check_PROGRAMS = t_clock_getres  t_clock_gettime  t_clock_nanosleep  t_clock_settime  t_nanosleep  #test
TESTS = $(check_PROGRAMS)
