# This makefile requires GNU make.

PACKAGE = x86_64-mingw-runtime
VERSION = 3.9
CYGRELEASE = 1

VPATH = .:./math:./complex:./stdio:./misc:./termios
srcdir = .
objdir = .

host_alias = x86_64-pc-mingw32
build_alias = x86_64-pc-mingw32
target_alias = x86_64-pc-mingw32
# prefix = /vol/m
prefix = /usr/local
conf_prefix = $(prefix)
EXEEXT=.exe

program_transform_name = s,x,x,
exec_prefix = $(prefix)
bindir = $(exec_prefix)/bin
libdir = $(exec_prefix)/lib
tooldir:=$(exec_prefix)/$(target_alias)
datadir = $(prefix)/share
infodir = $(prefix)/info
includedir = $(prefix)/$(target_alias)/include
inst_bindir:=$(tooldir)/bin
inst_includedir:=$(tooldir)/include/mingw
inst_libdir:=$(tooldir)/lib/mingw
inst_docdir:=$(tooldir)/share/doc/mingw-runtime

# The Mingw headers are installed under a subdirectory of 
# $(tooldir)/include when configuring in Cygwin.
HEADER_SUBDIR = 

SHELL = /bin/sh

INSTALL = /usr/bin/install -c
INSTALL_DATA = $(INSTALL) -m 644
INSTALL_PROGRAM = $(INSTALL)
mkinstalldirs = $(SHELL) mkinstalldirs

CC := $(prefix)/bin/x86_64-pc-mingw32-gcc$(EXEEXT)
override CC := $(filter-out -L% -B%,$(shell echo $(CC) | sed -e 's%\(-isystem\|-iwithprefixbefore\)  *[^ ]*\( \|$$\)% %g'))
# FIXME: Which is it, CC or CC_FOR_TARGET?
CC_FOR_TARGET = $(CC)
AS_FOR_TARGET = $(AS)
CFLAGS = -g -O2 -I. -D_CRTBLD -D_SYSCRT=1 -DCRTDLL=1 -DWINHEAP=1
CXXFLAGS = $(CFLAGS)

# compiling with Cygwin?
MNO_CYGWIN = 
ifdef MNO_CYGWIN
   subdirforlib=/mingw
else
   libdir=
endif

# Needed for threading dll.

# Various libraries.
LIBM_A=libm.a

W32API_INCLUDE = 
INCLUDES+= -I.
ALL_CFLAGS = $(CFLAGS) $(W32API_INCLUDE) $(INCLUDES) $(MNO_CYGWIN)
ALL_CXXFLAGS = $(CXXFLAGS) $(W32API_INCLUDE) $(INCLUDES) -nostdinc++ $(MNO_CYGWIN)

AS = $(prefix)/bin/x86_64-pc-mingw32-as$(EXEEXT)
AR = $(prefix)/bin/x86_64-pc-mingw32-ar$(EXEEXT)
LD = $(prefix)/bin/x86_64-pc-mingw32-ld$(EXEEXT)
AR_FLAGS = rcv
RANLIB = $(prefix)/bin/x86_64-pc-mingw32-ranlib$(EXEEXT)
DLLTOOL = $(prefix)/bin/x86_64-pc-mingw32-dlltool$(EXEEXT)
DLLTOOLFLAGS = 
DLLTOOL_FOR_TARGET = $(DLLTOOL)
DLLTOOL_FLAGS = --as $(AS_FOR_TARGET)
DLLWRAP = $(prefix)/bin/x86_64-pc-mingw32-dlltool$(EXEEXT)
DLLWRAP_FOR_TARGET = $(DLLWRAP)
DLLWRAP_FLAGS = --dlltool $(DLLTOOL) --as $(AS) --driver-name $(CC)

TAR = tar
TARFLAGS = z
TARFILEEXT = .tar.gz

SUBDIRS := mklibs

FLAGS_TO_PASS:=\
	AS="$(AS)" \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS) $(CFLAGS_COMMON) $(CFLAGS_CONFIG)" \
	CXXFLAGS="$(CXXFLAGS) $(CFLAGS_COMMON) $(CFLAGS_CONFIG)" \
	EXE_LDFLAGS="$(EXE_LDFLAGS)" \
	AR="$(AR)" \
	RANLIB="$(RANLIB)" \
	LD="$(LD)" \
	DLLTOOL="$(DLLTOOL)" \
	exec_prefix="$(exec_prefix)" \
	bindir="$(bindir)" \
	libdir="$(libdir)" \
	tooldir="$(tooldir)" \
	datadir="$(datadir)" \
	infodir="$(infodir)" \
	includedir="$(includedir)" \
	inst_bindir="$(inst_bindir)" \
	inst_includedir="$(inst_includedir)" \
	inst_libdir="$(inst_libdir)" \
	inst_docdir="$(inst_docdir)" \
	prefix="$(prefix)" \
	target_alias="$(target_alias)" \
	TAR="$(TAR)" \
	TARFLAGS="$(TARFLAGS)" \
	TARFILEEXT="$(TARFILEEXT)"

CRT0S = crt1.o crt2.o dllcrt1.o dllcrt2.o \
	CRT_fp8.o CRT_fp10.o txtmode.o binmode.o crtbegin.o crtend.o
MINGW_OBJS = crt0_c.o crt0_w.o dll_argv.o  gccmain.o \
	     CRT_fp10.o \
	     pseudo-reloc.o pseudo-reloc-list.o pesect.o cinitexe.o \
	     natstart.o gs_support.o atonexit.o dllmain.o \
	     wildcard.o merr.o \
	     dllargv.o \
	     charmax.o xtxtmode.o \
	     tlssup.o xncommod.o _newmode.o \
	     xthdloc.o mingw_helpers.o

MATH_OBJS = \
	acosf.o acosl.o asinf.o asinl.o atan2f.o atan2l.o \
	atanf.o atanl.o cbrt.o cbrtf.o cbrtl.o ceilf.o ceill.o \
	cephes_emath.o \
	copysign.o copysignf.o copysignl.o cosf.o coshf.o coshl.o cosl.o \
	erfl.o exp2.o exp2f.o exp2l.o expf.o expl.o expm1.o expm1l.o expm1f.o \
	fabs.o fabsf.o fabsl.o \
	fdim.o fdimf.o fdiml.o floorf.o floorl.o fma.o fmaf.o fmal.o \
	fmax.o fmaxf.o fmaxl.o fmin.o fminf.o fminl.o fmodf.o \
	fmodl.o fp_consts.o fp_constsf.o fp_constsl.o \
	fpclassify.o fpclassifyf.o fpclassifyl.o \
	frexpf.o frexpl.o fucom.o hypotf.o hypotl.o ilogb.o ilogbf.o \
	ilogbl.o isnan.o isnanf.o isnanl.o ldexpf.o ldexpl.o \
	lgamma.o lgammaf.o lgammal.o llrint.o \
	llrintf.o llrintl.o llround.o llroundf.o llroundl.o \
	log10f.o log10l.o log1p.o log1pf.o log1pl.o log2.o log2f.o \
	log2l.o logb.o logbf.o logbl.o logf.o logl.o lrint.o lrintf.o \
	lrintl.o lround.o lroundf.o lroundl.o modff.o modfl.o \
	nearbyint.o nearbyintf.o nearbyintl.o \
	nextafterf.o nextafterl.o nexttowardf.o nexttoward.o \
	powf.o powi.o powif.o powil.o powl.o \
	remainder.o remainderf.o remainderl.o remquo.o \
	remquof.o remquol.o rint.o rintf.o rintl.o round.o roundf.o \
	roundl.o scalbn.o scalbnf.o scalbnl.o s_erf.o sf_erf.o \
	signbit.o signbitf.o signbitl.o sinf.o sinhf.o sinhl.o sinl.o \
	sqrtf.o sqrtl.o tanf.o tanhf.o tanhl.o tanl.o tgamma.o \
	tgammaf.o tgammal.o trunc.o truncf.o truncl.o \
	acosh.o acoshf.o acoshl.o asinh.o asinhf.o asinhl.o \
	atanh.o atanhf.o atanhl.o
FENV_OBJS = fesetround.o  fegetround.o \
	fegetenv.o fesetenv.o feupdateenv.o \
	feclearexcept.o feholdexcept.o fegetexceptflag.o \
	feraiseexcept.o fetestexcept.o fesetexceptflag.o

COMPLEX_OBJS = \
	cabs.o cabsf.o cabsl.o cacos.o cacosf.o cacosl.o cacosh.o \
	cacoshf.o cacoshl.o carg.o cargf.o cargl.o casin.o casinf.o \
	casinl.o casinh.o casinhf.o casinhl.o catan.o catanf.o catanl.o \
	catanh.o catanhf.o catanhl.o ccos.o ccosf.o ccosl.o ccosh.o \
	ccoshf.o ccoshl.o cexp.o cexpf.o cexpl.o cimag.o cimagf.o \
	cimagl.o clog.o clogf.o clogl.o cpow.o cpowf.o cpowl.o cproj.o \
	cprojf.o cprojl.o creal.o crealf.o creall.o csin.o csinf.o \
	csinl.o csinh.o csinhf.o csinhl.o csqrt.o csqrtf.o csqrtl.o \
	ctan.o ctanf.o ctanl.o ctanh.o ctanhf.o ctanhl.o

STDIO_OBJS = \
	fopen64.o fseeko64.o ftello64.o lseek64.o \
	snprintf.o  vsnprintf.o snwprintf.o vsnwprintf.o \
	vfscanf.o vfwscanf.o vscanf.o vsscanf.o vswscanf.o vwscanf.o

STDLIB_STUB_OBJS = \
	lltoa.o ulltoa.o \
	lltow.o ulltow.o \
	atoll.o wtoll.o \
	strtof.o wcstof.o \
	_Exit.o

FENV_OBJS = fesetround.o  fegetround.o \
	fegetenv.o fesetenv.o feupdateenv.o \
	feclearexcept.o feholdexcept.o fegetexceptflag.o \
	feraiseexcept.o fetestexcept.o fesetexceptflag.o

REPLACE_OBJS = \
	mingw-aligned-malloc.o mingw-fseek.o

Q8_OBJS = \
	fwide.o imaxabs.o imaxdiv.o mbsinit.o \
	strtoimax.o strtoumax.o wcstoimax.o wcstoumax.o \
	wmemchr.o wmemcmp.o wmemcpy.o wmemmove.o wmemset.o \
	wctrans.o wctype.o wcrtomb.o wctob.o mbrtowc.o btowc.o seterrno.o \
	sleep.o alarm.o getlogin.o gettimeofday.o wassert.o

STDLIB_OBJS = \
	strtold.o wcstold.o

MINGWEX_OBJS = dirent.o wdirent.o getopt.o ftruncate.o

MOLD_OBJS = isascii.o iscsym.o iscsymf.o toascii.o \
	strcasecmp.o strncasecmp.o wcscmpi.o

TERMIOS_OBJS = \
	cfmakeraw.o cfsetspeed.o speed.o tcdrain.o tcflow.o tcflush.o \
	tcgetattr.o tcgetpgrp.o tcgetsid.o tcsendbrk.o tcsetattr.o tcsetpgrp.o ioctl.o \
	ttyname.o

LIBS = libcrtdll.a \
       libmsvcrt.a \
       libmsvcr80.a \
       libmingw32.a \
       libmoldname.a \
       libmingwex.a \
       $(LIBM_A)

DLLS = 

SRCDIST_FILES = dll_argv.c ChangeLog \
README TODO config.guess config.sub configure configure.in \
crt1.c crtdll.def \
gccmain.c init.c install-sh jamfile mkinstalldirs \
natstart.c gs_support.c atonexit.c \
mthr.c mthr_init.c mthr_stub.c readme.txt \
isascii.c iscsym.c iscsymf.c toascii.c \
strcasecmp.c strncasecmp.c wcscmpi.c \
CRT_fp8.c CRT_fp10.c test_headers.c txtmode.c binmode.c pseudo-reloc.c \
pseudo-reloc-list.c atonexit.c dllmain.c \
wildcard.c merr.c \
dllargv.c charmax.c \
tlssup.c xtxtmode.c xncommod.c _newmode.c \
xthdloc.c crt0_c.c crt0_w.c mingw_helpers.c \
DISCLAIMER CONTRIBUTORS


all_dlls_host = all_dlls_host
install_dlls_host = install_dlls_host

all: $(CRT0S) $(LIBS) $(all_dlls_host)
	@$(MAKE) subdirs DO=$@ $(FLAGS_TO_PASS)

all_dlls_host: $(DLLS)

install_dlls_host:
	for i in $(DLLS); do \
		$(INSTALL_PROGRAM) $$i $(inst_bindir)/$$i ; \
	done

_libm_dummy.o:
	rm -f _libm_dummy.c
	echo "static int __mingw_libm_dummy;" > _libm_dummy.c
	$(CC) -c $(ALL_CFLAGS) _libm_dummy.c
	rm -f _libm_dummy.c

libm.a: _libm_dummy.o
	$(AR) rc $@ _libm_dummy.o
	$(RANLIB) $@

DLL_OFILES        = mthr.o mthr_init.o
DLL_CC_STUFF      = -B./ -mdll $(MNO_CYGWIN) -Wl,--image-base,0x6FBC0000 \
		    -Wl,--entry,_DllMainCRTStartup@24 \
                    $(DLL_OFILES) \
		    -Lmingwex

libmingw32.a: $(MINGW_OBJS)
	$(AR) rc $@ $(MINGW_OBJS)
	$(RANLIB) $@

msvcrt.def \
	$(CC) -DRUNTIME=$(basename $(notdir $@)) \
		-D__$(basename $(notdir $@))__=1 \
		-D__MSVCRT__ -C -E -P \
		-xc-header $? > $@

msvcr80.def \
	$(CC) -DRUNTIME=$(basename $(notdir $@)) \
		-D__$(basename $(notdir $@))__=1 \
		-D__MSVCRT__ -C -E -P \
		-xc-header $? > $@

libmoldname.a: moldname-msvcrt.def $(MOLD_OBJS)
	$(DLLTOOL) --as $(AS) -k -U	\
		--dllname msvcrt.dll	\
		--def moldname-msvcrt.def	\
		--output-lib $@
	$(AR) rc $@ $(MOLD_OBJS)
	$(RANLIB) $@

libmingwex.a: $(MINGWEX_OBJS) $(MATH_OBJS) $(COMPLEX_OBJS) $(STDIO_OBJS) $(STDLIB_STUB_OBJS) $(STDLIB_OBJS) $(FENV_OBJS) $(REPLACE_OBJS) $(Q8_OBJS)
	$(AR) rc $@ $(MINGWEX_OBJS) $(MATH_OBJS) $(COMPLEX_OBJS) $(STDIO_OBJS) $(STDLIB_STUB_OBJS) $(STDLIB_OBJS) $(FENV_OBJS) $(REPLACE_OBJS) $(Q8_OBJS)
	$(RANLIB) $@

# The special rules are necessary.
crt1.o:
	$(CC) -c -D__CRTDLL__ -U__MSVCRT__ $(ALL_CFLAGS) $< -o $@

crt2.o:
	$(CC) -c -D__MSVCRT__ -U__CRTDLL__ $(ALL_CFLAGS) $< -o $@

dllcrt1.o:
	$(CC) -c -D__CRTDLL__ -U__MSVCRT__ $(ALL_CFLAGS) $< -o $@

dllcrt2.o:
	$(CC) -c -D__MSVCRT__ -U__CRTDLL__ $(ALL_CFLAGS) $< -o $@

crtbegin.o:
	$(CC) -c $(ALL_CFLAGS) $< -o $@

crtend.o:
	$(CC) -c $(ALL_CFLAGS) $< -o $@

TEST_H_OPTIONS = $(ALL_CFLAGS) -Wall -W -Wsystem-headers -c \
	$(srcdir)/test_headers.c -o test_headers.o

.PHONY: test_headers
test_headers:
	@echo "Testing runtime headers..."
	@for lang in c c++ objective-c ; do \
		echo "$$lang ..."; \
		$(CC) -x$$lang  $(TEST_H_OPTIONS) ; \
		echo "$$lang -ansi"; \
		$(CC) -x$$lang -ansi $(TEST_H_OPTIONS) ; \
	done
# specify -std=xx only for C
	@for std in gnu89 gnu99 c89 c99 ; do \
		echo "std = $$std"; \
		$(CC) -std=$$std  $(TEST_H_OPTIONS) ; \
	done

	@rm -f test_headers.o

clean:
	-rm -f *.o *.a *~ core a.out
	@$(MAKE) subdirs DO=$@ $(FLAGS_TO_PASS)

distclean: clean
	@$(MAKE) subdirs DO=$@ $(FLAGS_TO_PASS)
	-rm -f config.cache config.status config.log 
distdir=$(PACKAGE)-$(VERSION)

  TARFLAGS = j
  TARFILEEXT = .tar.bz2

ifneq (,$(findstring mingw, $(target_alias)))
    dist_prefix =
else
    dist_prefix = $(conf_prefix)
endif

dist: srcdist bindist

srcdist:
	rm -rf $(distdir)
	mkdir $(distdir)
	chmod 755 $(distdir)
	for i in $(SRCDIST_FILES); do \
		cp -p $(srcdir)/$$i $(distdir)/$$i ; \
	done
	for i in $(SUBDIRS); do \
		(cd $$i; $(MAKE) distdir=../$(distdir) dist); \
	done
#FIXME this needs to be done with SUBDIRS and Makefiles.
	mkdir $(distdir)/include
	mkdir $(distdir)/include/sys
	cp $(srcdir)/include/*.h $(distdir)/include/
	cp $(srcdir)/include/sys/*.h $(distdir)/include/sys/
#end FIXME
	rm -f $(distdir)-src.tar.gz
	$(TAR) $(TARFLAGS)cf $(distdir)-src$(TARFILEEXT) $(distdir)


bindist:
	rm -rf $(distdir)
	mkdir $(distdir)
	chmod 755 $(distdir)
	$(MAKE) install prefix=$(shell pwd)/$(distdir)$(dist_prefix)
	rm -f $(distdir).tar.gz
	cd $(distdir); \
	$(TAR) $(TARFLAGS)cf ../$(distdir)$(TARFILEEXT) *

snapshot: 
	make dist SNAPDATE=$(shell date '+%Y%m%d')

info:

info-html:

install-info: info

install-dirs:
	$(mkinstalldirs) $(inst_bindir)
	$(mkinstalldirs) $(inst_includedir)
	$(mkinstalldirs) $(inst_libdir)
	$(mkinstalldirs) $(inst_docdir)

install: all install-dirs $(install_dlls_host)
	for i in $(LIBS); do \
		$(INSTALL_DATA) $$i $(inst_libdir)/$$i ; \
	done
	for i in $(CRT0S); do \
		$(INSTALL_DATA) $$i $(inst_libdir)/$$i ; \
	done
	for sub in . sys ; do \
		dstdir=$(inst_includedir)/$$sub ; \
		$(mkinstalldirs) $$dstdir ; \
		for i in $(srcdir)/include/$$sub/*.h ; do \
		  $(INSTALL_DATA) $$i $$dstdir/`basename $$i` ; \
		done ; \
	done
	@$(MAKE) subdirs DO=$@ $(FLAGS_TO_PASS)

subdirs: $(SUBDIRS)
	@true

# The . is here because SUBDIRS may be empty

. $(SUBDIRS): force
	@if [ -d ./$@ ]; then \
	  echo "Making $(DO) in $@..." ; \
	  if (rootme=`pwd`/ ; export rootme ; \
	    rootsrc=`cd $(srcdir); pwd`/ ; export rootsrc ; \
	    cd ./$@; \
	    $(MAKE) $(FLAGS_TO_PASS) $(DO)) ; then true ; \
	  else exit 1 ; fi ; \
	else true ; fi ; \

force:

#
# Dependancies
#
libcrtdll.a: crtdll.def
libmsvcrt.a: msvcrt.def
libmsvcr80.a: msvcr80.def
dll_argv.o: dll_argv.c
crtbegin.o: crtbegin.c
crtend.o: crtend.c
crt1.o: crtexe.c
crt2.o: crtexe.c
dllcrt1.o: crtdll.c
dllcrt2.o: crtdll.c
ctype_old.o: ctype_old.c
string_old.o: string_old.c
CRT_fp8.o: CRT_fp8.c
CRT_fp10.o: CRT_fp10.c


config.status: configure
	$(SHELL) config.status --recheck

.SUFFIXES: .y $(SUFFIXES) .cc .o .def .a

.c.o:
	$(CC) -c $(ALL_CFLAGS) $< -o $@


lib%.a: %.def
	$(DLLTOOL) --as=$(AS) -k --dllname $*.dll --output-lib lib$*.a --def $<

