
SUBDIRS = . tests

AM_CFLAGS =
ACLOCAL_AMFLAGS = -I m4

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
  src/barrier.c   src/barrier.h \
  src/clock.c                   \
  src/cond.c      src/cond.h    \
  src/misc.c      src/misc.h    \
  src/mutex.c                   \
  src/nanosleep.c               \
  src/rwlock.c    src/rwlock.h  \
  src/sem.c       src/sem.h     \
  src/spinlock.c                \
  src/sched.c                   \
  src/thread.c    src/thread.h  \
  src/wpth_ver.h                \
  src/version.rc

libwinpthread_la_CPPFLAGS = -I$(srcdir)/include -DIN_WINPTHREAD
libwinpthread_la_LDFLAGS = -no-undefined -version-info 1:0:0

if MSVC
AM_CFLAGS += -W3
libwinpthread_la_CPPFLAGS += -D_CRT_NONSTDC_NO_WARNINGS -D_CRT_DECLARE_NONSTDC_NAMES -D_CRT_SECURE_NO_WARNINGS
else
AM_CFLAGS += -Wall
libwinpthread_la_CPPFLAGS += -D__USE_MINGW_ANSI_STDIO=0
libwinpthread_la_LDFLAGS += -L$(builddir)/fakelib -Wc,-no-pthread
EXTRA_libwinpthread_la_DEPENDENCIES = fakelib/libgcc.a  fakelib/libgcc_eh.a  fakelib/libgcc_s.a

# Break circular dep on bootstrap
noinst_LIBRARIES = fakelib/libgcc.a  fakelib/libgcc_eh.a  fakelib/libgcc_s.a
fakelib_libgcc_a_SOURCES = src/libgcc/dll_dependency.S src/libgcc/dll_math.c
fakelib_libgcc_s_a_SOURCES =
fakelib_libgcc_eh_a_SOURCES =
endif

# Extra files to add into archive with `make dist`
EXTRA_DIST = \
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
