
SUBDIRS = . tests

ACLOCAL_AMFLAGS = -I m4

# Global compiler and linker flags are set in configure.ac
AM_CPPFLAGS = @CRT_DEFINES@
AM_CFLAGS   = @DEFAULT_WARNINGS@
AM_LDFLAGS  = @LINKER_SUBSYSTEM@

lib_LTLIBRARIES = libwinpthread.la

include_HEADERS =          \
  include/pthread.h        \
  include/pthread_compat.h \
  include/pthread_signal.h \
  include/pthread_time.h   \
  include/pthread_unistd.h \
  include/sched.h          \
  include/semaphore.h

libwinpthread_la_SOURCES =      \
  src/affinity.c                \
  src/barrier.c   src/barrier.h \
  src/cond.c      src/cond.h    \
  src/misc.c      src/misc.h    \
  src/mutex.c                   \
  src/rwlock.c    src/rwlock.h  \
  src/sem.c       src/sem.h     \
  src/spinlock.c                \
  src/sched.c                   \
  src/time.c      src/winpthreads-time.h  \
  src/thread.c    src/thread.h  \
  src/wpth_ver.h                \
  src/version.rc

libwinpthread_la_CPPFLAGS = $(AM_CPPFLAGS) -I$(srcdir)/include -DIN_WINPTHREAD
libwinpthread_la_CFLAGS   = $(AM_CFLAGS)
libwinpthread_la_LDFLAGS  = $(AM_LDFLAGS) -no-undefined -version-info 1:0:0

if !MSVC
libwinpthread_la_LDFLAGS += -L$(builddir)/fakelib -Wc,-no-pthread
EXTRA_libwinpthread_la_DEPENDENCIES = fakelib/libgcc.a  fakelib/libgcc_eh.a  fakelib/libgcc_s.a

# Break circular dep on bootstrap
noinst_LIBRARIES = fakelib/libgcc.a  fakelib/libgcc_eh.a  fakelib/libgcc_s.a
fakelib_libgcc_a_SOURCES = src/libgcc/dll_dependency.S src/libgcc/dll_math.c
fakelib_libgcc_s_a_SOURCES =
fakelib_libgcc_eh_a_SOURCES =
endif

# Extra files to add into archive with `make dist`
EXTRA_DIST =                   \
  tests/benchtests/benchtest.h \
  tests/ChangeLog.2010         \
  tests/test.h                 \
  build-aux/windres-rc

# Tell libtool how to use the resource compiler
.rc.lo:
	$(LIBTOOL) $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --tag=RC --mode=compile $(RC) $(RCFLAGS) -i $< -o $@

# Handle -lpthread alias when installing
install-exec-hook:
	. $(builddir)/libwinpthread.la; \
	if test -n "$${library_names}"; then \
		alias=$$(printf %s "$${library_names}" | $(SED) 's|winpthread|pthread|'); \
		$(INSTALL_DATA) $(DESTDIR)$(libdir)/$${library_names} $(DESTDIR)$(libdir)/$${alias}; \
	fi; \
	if test -n "$${old_library}"; then \
		alias=$$(printf %s "$${old_library}" | $(SED) 's|winpthread|pthread|'); \
		$(INSTALL_DATA) $(DESTDIR)$(libdir)/$${old_library} $(DESTDIR)$(libdir)/$${alias}; \
	fi

# Likewise when uninstalling
uninstall-hook:
	. $(builddir)/libwinpthread.la; \
	if test -n "$${library_names}"; then \
		alias=$$(printf %s "$${library_names}" | $(SED) 's|winpthread|pthread|'); \
		rm -f $(DESTDIR)$(libdir)/$${alias}; \
	fi; \
	if test -n "$${old_library}"; then \
		alias=$$(printf %s "$${old_library}" | $(SED) 's|winpthread|pthread|'); \
		rm -f $(DESTDIR)$(libdir)/$${alias}; \
	fi

DISTCHECK_CONFIGURE_FLAGS = --host=$(host_triplet)
