# start config section

SHELL = /bin/bash

srcdir = ../lib
VPATH = ../lib

SUBDIRS := 
subdirs := 

host_alias = i686-pc-cygwin
build_alias = i686-pc-cygwin
target_alias = x86_64-pc-mingw32
# prefix = /vol/m
prefix = /usr/local
includedir:=${prefix}/${target_alias}/include
EXEEXT =.exe

program_transform_name = s,x,x,
exec_prefix = ${prefix}
libdir:=${exec_prefix}/lib
bindir = ${exec_prefix}/bin
datadir = ${prefix}/share
infodir = ${prefix}/info
inst_includedir:=$(includedir)
inst_libdir:=$(libdir)

INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_PROGRAM = ${INSTALL}
mkinstalldirs = mkdir -p

CC = $(prefix)/bin/x86_64-pc-mingw32-gcc$(EXEEXT)
CC_FOR_TARGET = $(CC)

DLLTOOL = $(prefix)/bin/x86_64-pc-mingw32-dlltool$(EXEEXT)
DLLTOOL_FLAGS = --as=$(AS) -k
AS = $(prefix)/bin/x86_64-pc-mingw32-as$(EXEEXT)
AS_FOR_TARGET = $(AS_FOR_TARGET)
WINDRES = $(prefix)/bin/x86_64-pc-mingw32-windres$(EXEEXT)

# Depending on if we build as part of winsup or mingw we need to
# add additional include paths in order to get the correct headers
# from the C library.
BUILDENV = 

#ifeq ($(BUILDENV), mingw)
EXTRA_INCLUDES = -I$(prefix)/x86_64-pc-mingw32/include
# -I$(srcdir)/../../mingw/include
#endif

INCLUDES = $(EXTRA_INCLUDES)

CFLAGS = -O2 -g
ALL_CFLAGS = $(CFLAGS) $(INCLUDES)

RANLIB = $(prefix)/bin/x86_64-pc-mingw32-ranlib$(EXEEXT)
AR = $(prefix)/bin/x86_64-pc-mingw32-ar$(EXEEXT)
LD = $(prefix)/bin/x86_64-pc-mingw32-ld$(EXEEXT)

FLAGS_TO_PASS = \
	AS="$(AS)" \
	CC="$(CC)" \
	CPPFLAGS="$(CPPFLAGS)" \
	CFLAGS="$(CFLAGS)" \
	CXXFLAGS="$(CXXFLAGS)" \
	AR="$(AR)" \
	RANLIB="$(RANLIB)" \
	LD="$(LD)" \
	DLLTOOL="$(DLLTOOL)" \
	TAR="$(TAR)" \
	TARFLAGS="$(TARFLAGS)" \
	TARFILEEXT="$(TARFILEEXT)" \
	WINDRES="$(WINDRES)"

# end config section

# headers

# libraries

DEF_FILES = $(notdir $(wildcard $(srcdir)/*.def))
IMPLIBS = $(addprefix lib,$(subst .def,.a,$(DEF_FILES)))
EXTRA_LIBS=libuuid.a libscrnsave.a libscrnsavw.a liblargeint.a
LIBS = $(IMPLIBS) $(EXTRA_LIBS)
UUID_OBJS = uuid.o mshtml-uuid.o
EXTRA_OBJS = shell32.o scrnsave.o scrnsavw.o largeint.o \
	$(UUID_OBJS) kernel32.o
UUID_SOURCES = uuid.c mshtml-uuid.c
SOURCES = scrnsave.c shell32.c  largeint.c $(UUID_SOURCES)\
res.rc test.c kernel32.c

DISTFILES = $(DEF_FILES) $(SOURCES)

.NOTPARALLEL:

# targets
all: $(EXTRA_OBJS) $(LIBS)

%-subdirs:
	for i in $(SUBDIRS); do \
	  $(MAKE) $(FLAGS_TO_PASS) -C $$i $*; \
	done

ddk:
	$(MAKE) $(FLAGS_TO_PASS) -C $@

directx:
	$(MAKE) $(FLAGS_TO_PASS) -C $@

TEST_OPTIONS = $(ALL_CFLAGS) -DWINVER=0x0666  \
	-Wall -pedantic -Wsystem-headers -c $(srcdir)/test.c -o test.o
.PHONY: test ddk directx
test:
	@echo "Testing w32api..."
	@for lang in c c++ objective-c ; do \
		echo "$$lang..."; \
		$(CC) -x$$lang $(TEST_OPTIONS) ; \
		echo "$$lang UNICODE..."; \
		$(CC) -x$$lang -DUNICODE $(TEST_OPTIONS) ; \
	done
	@echo "windres..."
	@$(WINDRES) --include-dir $(INCDIR) -i $(srcdir)/res.rc -o test.o
	@echo "windres UNICODE..."
	@$(WINDRES) --define UNICODE --include-dir $(INCDIR) -i $(srcdir)/res.rc -o test.o
	@rm -f test.o

scrnsavw.o: scrnsave.c
	$(CC) -c $(ALL_CFLAGS) -DUNICODE -o $@ $<

# make rules

.SUFFIXES: .c .o .def .a

.c.o:
	$(CC) -c $(ALL_CFLAGS) -o $@ $<

libuuid.a : $(UUID_OBJS)
	$(AR) rc $@ $(UUID_OBJS)
	$(RANLIB) $@

# libvfw32.a contains import stubs for 3 dll's.  Using an MRI script
# seems to be the simplest way to combine them into one archive.
# NB: With older dlltool, the object file members will not have unique
# names.
libvfw32.a : vfw32.mri libmsvfw32.a libavifil32.a libavicap32.a
	rm -f $@
	$(AR) -M < ${word 1,$^}
	$(RANLIB) $@

lib%.a : %.def %.o
	$(DLLTOOL) $(DLLTOOL_FLAGS) --output-lib $@ --def $(srcdir)/$*.def
	$(AR) r $@ $*.o
	$(RANLIB) $@

lib%.a: %.def
	$(DLLTOOL) $(DLLTOOL_FLAGS) --output-lib $@ --def $<

lib%.a: %.o
	$(AR) rc $@ $*.o
	$(RANLIB) $@

dist:
	mkdir $(distdir)/include
	chmod 755 $(distdir)/include
	mkdir $(distdir)/lib
	chmod 755 $(distdir)/lib
	@for i in $(DISTFILES); do \
		cp -p $(srcdir)/$$i $(distdir)/lib/$$i ; \
	done
	for i in $(SUBDIRS); do \
		(cd $$i; $(MAKE) distdir=../$(distdir) dist); \
	done

# clean

mostlyclean:
	rm -f *~ *.o *.s

clean:
	rm -f *.o *.a *.s *~

distclean: clean
	rm -f config.cache config.status config.log Makefile

maintainer-clean: distclean

