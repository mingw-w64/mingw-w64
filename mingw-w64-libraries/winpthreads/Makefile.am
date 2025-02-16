
SUBDIRS = . tests

AM_CFLAGS = -Wall -DWIN32_LEAN_AND_MEAN
ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libwinpthread.la

include_HEADERS = include/pthread.h include/sched.h include/semaphore.h include/pthread_unistd.h include/pthread_time.h include/pthread_compat.h include/pthread_signal.h
libwinpthread_la_CPPFLAGS = -I$(srcdir)/include -DIN_WINPTHREAD -DWINPTHREAD_DBG=1
libwinpthread_la_LDFLAGS = -no-undefined -version-info 1:0:0
libwinpthread_la_SOURCES = \
  src/barrier.h  src/cond.h  src/misc.h  src/mutex.h  src/rwlock.h  src/spinlock.h  src/thread.h  src/ref.h  src/sem.h  src/wpth_ver.h \
  src/barrier.c  src/cond.c  src/misc.c  src/mutex.c  src/rwlock.c  src/spinlock.c  src/thread.c  src/ref.c  src/sem.c  src/sched.c \
  src/winpthread_internal.h  src/clock.c src/nanosleep.c src/version.rc

if MSVC
AM_CFLAGS += -nologo
libwinpthread_la_CPPFLAGS += -D_CRT_NONSTDC_NO_WARNINGS
else
libwinpthread_la_CPPFLAGS += -D__USE_MINGW_ANSI_STDIO=0
libwinpthread_la_LDFLAGS += -L$(builddir)/fakelib -Wc,-no-pthread
EXTRA_libwinpthread_la_DEPENDENCIES = fakelib/libgcc.a  fakelib/libgcc_eh.a  fakelib/libgcc_s.a

# Break circular dep on bootstrap
noinst_LIBRARIES = fakelib/libgcc.a  fakelib/libgcc_eh.a  fakelib/libgcc_s.a
fakelib_libgcc_a_SOURCES = src/libgcc/dll_dependency.S src/libgcc/dll_math.c
fakelib_libgcc_s_a_SOURCES =
fakelib_libgcc_eh_a_SOURCES =
endif

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
