# INCLUDES = -I$(top_srcdir) -I$(includedir)
# Done: lib_LIBRARIES = libm.a libmingw32.a libmoldname.a libmingwex.a libcrtdll.a libmsvcrt.a libmsvcr80.a
# Done: Turn _libm_dummy.c into a BUILT_SOURCES thing
# TODO: 32-bit runtime compatibility
# Done: fix make dist
# TODO: Use $(RM) instead of rm?
# TODO: Use $(TAR) instead of tar?
# TODO: Find a better way to handle dxerr.c -- make it dxerr.h and add to sources list?
#

#Use AM_MAINTAINER_MODE in configure.ac to disable autoreconf

if WITHSYSROOT
  sysincludes=-I@TARGET_SYSTEM_ROOT@/mingw/include
  withsys=--with-sysroot=@TARGET_SYSTEM_ROOT@
else
  sysincludes=
  withsys=
endif

if VISTA
  vistasupport=-D__USE_MINGW_ACCESS
  enablevista=--enable-vista
else
  vistasupport=
  enablevista=
endif

AM_CPPFLAGS=-D_CRTBLD $(sysincludes)
AM_CFLAGS=-pipe $(vistasupport) -Wall -std=gnu99
AM_DLLTOOLFLAGS=-k --as=$(AS) --output-lib $@
DTDEF=$(DLLTOOL) $(AM_DLLTOOLFLAGS) --def
DTLIB=$(DTDEF) $(top_srcdir)/`echo $@ | $(SED) 's|/lib|/|;s|\.a|.def|'`
crt64srcdir=$(top_srcdir)/crt64
crt32srcdir=$(top_srcdir)/crt32

# can move this into libsrc/dummy_libm.c or similar
BUILT_SOURCES = _libm_dummy.c
_libm_dummy.c:
	echo "static int __mingw_libm_dummy;" > _libm_dummy.c

if LIB32
#########
# Compiling 32-bit runtime
#

crt32dir=$(prefix)/$(host)/lib
lib32dir=$(crt32dir)
include32=-I$(top_srcdir)/include32
COMPILE32=$(COMPILE) $(include32) -c $(crt32srcdir)/

# These source files aren't compiled in to any library yet.  I'm not sure how / where to do so.
# The source files that I did compile somewhere I just guessed at anyway.
#

temp= \
dxerr.c \
test.c

lib32_LIBRARIES = lib32/libm.a
nodist_lib32_libm_a_SOURCES = _libm_dummy.c
lib32_libm_a_CPPFLAGS = -m32

lib32_LIBRARIES += lib32/libmingwthrd.a
lib32_libmingwthrd_a_SOURCES = libsrc/dummy_mingwthrd.c
lib32_libmingwthrd_a_CPPFLAGS = -m32

lib32_LIBRARIES += lib32/libshell32.a
lib32_libshell32_a_SOURCES = libsrc/shell32.c
lib32_libshell32_a_AR = $(DTLIB); $(AR) $(ARFLAGS)
lib32_libshell32_a_CPPFLAGS = -m32

lib32_LIBRARIES += lib32/libdinput.a
lib32_libdinput_a_SOURCES = libsrc/dinput_kbd.c \
  libsrc/dinput_joy.c   libsrc/dinput_joy2.c \
  libsrc/dinput_mouse.c libsrc/dinput_mouse2.c
lib32_libdinput_a_AR = $(DTLIB); $(AR) $(ARFLAGS)
lib32_libdinput_a_CPPFLAGS = -m32

lib32_LIBRARIES += lib32/libdinput8.a
lib32_libdinput8_a_SOURCES = libsrc/dinput_private.h \
  libsrc/dinput_joy.c   libsrc/dinput_joy2.c \
  libsrc/dinput_mouse.c libsrc/dinput_mouse2.c \
  libsrc/dinput_kbd.c
lib32_libdinput8_a_AR = $(DTLIB); $(AR) $(ARFLAGS)
lib32_libdinput8_a_CPPFLAGS = -m32

lib32_LIBRARIES += lib32/libdmoguids.a
lib32_libdmoguids_a_SOURCES = libsrc/dmoguids.c
lib32_libdmoguids_a_CPPFLAGS = -m32

lib32_LIBRARIES += lib32/libdxerr8.a
lib32_libdxerr8_a_SOURCES = libsrc/dxerr8.c libsrc/dxerr8w.c
lib32_libdxerr8_a_CPPFLAGS = -m32

lib32_LIBRARIES += lib32/libdxerr9.a
lib32_libdxerr9_a_SOURCES = libsrc/dxerr9.c libsrc/dxerr9w.c
lib32_libdxerr9_a_CPPFLAGS = -m32

lib32_LIBRARIES += lib32/libdxguid.a
lib32_libdxguid_a_SOURCES = libsrc/dxguid.c
lib32_libdxguid_a_CPPFLAGS = -m32

lib32_LIBRARIES += lib32/libksuser.a
lib32_libksuser_a_SOURCES = libsrc/ksuser.c
lib32_libksuser_a_CPPFLAGS = -m32
lib32_libksuser_a_AR = $(DTLIB); $(AR) $(ARFLAGS)

lib32_LIBRARIES += lib32/liblargeint.a
lib32_liblargeint_a_SOURCES = libsrc/largeint.c
lib32_liblargeint_a_CPPFLAGS = -m32

lib32_LIBRARIES += lib32/libscrnsave.a
lib32_libscrnsave_a_SOURCES = libsrc/scrnsave.c
lib32_libscrnsave_a_CPPFLAGS = -m32

lib32_LIBRARIES += lib32/libscrnsavw.a
lib32_libscrnsavw_a_SOURCES = libsrc/scrnsave.c
lib32_libscrnsavw_a_CPPFLAGS = -m32
lib32_libscrnsavw_a_CFLAGS = -DUNICODE

lib32_LIBRARIES += lib32/libstrmiids.a
lib32_libstrmiids_a_SOURCES = libsrc/strmiids.c
lib32_libstrmiids_a_CPPFLAGS = -m32

lib32_LIBRARIES += lib32/libuuid.a
lib32_libuuid_a_SOURCES = libsrc/uuid.c libsrc/devguid.c \
    libsrc/ativscp-uuid.c libsrc/cguid-uuid.c    libsrc/comcat-uuid.c \
    libsrc/docobj-uuid.c  libsrc/exdisp-uuid.c   libsrc/extras-uuid.c libsrc/hlguids-uuid.c  libsrc/hlink-uuid.c   libsrc/mlang-uuid.c \
    libsrc/mshtml-uuid.c  libsrc/msxml-uuid.c    libsrc/oaidl-uuid.c  libsrc/objidl-uuid.c   libsrc/objsafe-uuid.c libsrc/ocidl-uuid.c \
    libsrc/oleacc-uuid.c  libsrc/olectlid-uuid.c libsrc/oleidl-uuid.c libsrc/servprov-uuid.c libsrc/unknwn-uuid.c  libsrc/urlmon-uuid.c
lib32_libuuid_a_CPPFLAGS = -m32

lib32_LIBRARIES += lib32/libws2_32.a
lib32_libws2_32_a_SOURCES = libsrc/ws2_32.c
lib32_libws2_32_a_CPPFLAGS = -m32
lib32_libws2_32_a_AR = $(DTLIB); $(AR) $(ARFLAGS)


#These defs have no accompanying sources.  Look into using the rule below to run the dlltool command
#for all libraries, including those with sources.
lib32_SCRIPTS = \
  lib32/libaclui.a     lib32/libadvapi32.a  lib32/libapcups.a    lib32/libavicap32.a  lib32/libavifil32.a \
  lib32/libcap.a       lib32/libcfgmgr32.a  lib32/libcomctl32.a  lib32/libcomdlg32.a  lib32/libcrypt32.a  \
  lib32/libctl3d32.a   lib32/libd3d8.a      lib32/libd3d9.a      lib32/libd3dim.a     lib32/libd3drm.a    \
  lib32/libd3dx8d.a    lib32/libd3dx9d.a    lib32/libd3dxof.a    lib32/libddraw.a     lib32/libdhcpcsvc.a \
  lib32/libdlcapi.a    lib32/libdnsapi.a    lib32/libdplayx.a    \
  lib32/libdpnaddr.a   lib32/libdpnet.a     lib32/libdpnlobby.a  lib32/libdpvoice.a   lib32/libdsetup.a   \
  lib32/libdsound.a    lib32/libdxapi.a     lib32/libfaultrep.a  lib32/libgdi32.a     lib32/libglaux.a    \
  lib32/libglu32.a     lib32/libglut32.a    lib32/libglut.a      lib32/libhal.a       lib32/libhid.a      \
  lib32/libhidparse.a  lib32/libicmui.a     lib32/libigmpagnt.a  lib32/libimagehlp.a  lib32/libimm32.a    \
  lib32/libiphlpapi.a  lib32/libkernel32.a  lib32/libksproxy.a                        lib32/liblz32.a     \
  lib32/libmapi32.a    lib32/libmcd.a       lib32/libmfcuia32.a  lib32/libmgmtapi.a   lib32/libmprapi.a   \
  lib32/libmpr.a       lib32/libmqrt.a      lib32/libmsacm32.a   lib32/libmscms.a     lib32/libmsdmo.a    \
  lib32/libmsimg32.a   lib32/libmsvcp60.a   lib32/libmsvfw32.a   lib32/libmswsock.a   lib32/libnddeapi.a  \
  lib32/libndis.a      lib32/libnetapi32.a  lib32/libnewdev.a    lib32/libntdll.a     lib32/libntoskrnl.a \
  lib32/libodbc32.a    lib32/libodbccp32.a  lib32/libole32.a     lib32/liboleacc.a    lib32/liboleaut32.a \
  lib32/libolecli32.a  lib32/liboledlg.a    lib32/libolepro32.a  lib32/libolesvr32.a  lib32/libopengl32.a \
  lib32/libpenwin32.a  lib32/libpkpd32.a    lib32/libpowrprof.a  lib32/libpsapi.a     lib32/libquartz.a   \
  lib32/librapi.a      lib32/librasapi32.a  lib32/librasdlg.a    lib32/librpcdce4.a   lib32/librpcns4.a   \
  lib32/librpcrt4.a    lib32/librtm.a       lib32/librtutils.a   lib32/libscsiport.a  lib32/libsecur32.a  \
  lib32/libsetupapi.a                       lib32/libshfolder.a  lib32/libshlwapi.a   lib32/libsnmpapi.a  \
  lib32/libsvrapi.a    lib32/libtapi32.a    lib32/libtdi.a       lib32/libth32.a      lib32/libthunk32.a  \
  lib32/liburl.a       lib32/libusbcamd2.a  lib32/libusbcamd.a   lib32/libuser32.a    lib32/libuserenv.a  \
  lib32/libusp10.a     lib32/libuxtheme.a   lib32/libvdmdbg.a    lib32/libversion.a   lib32/libvideoprt.a \
  lib32/libwin32k.a    lib32/libwin32spl.a  lib32/libwininet.a   lib32/libwinmm.a     lib32/libwinspool.a \
  lib32/libwinstrm.a   lib32/libwldap32.a   lib32/libwow32.a     lib32/libwsnmp32.a   \
  lib32/libwsock32.a   lib32/libwst.a       lib32/libwtsapi32.a

lib32/lib%.a:
	$(DTDEF) $(top_srcdir)/lib32/$*.def


endif
# End 32-bit runtime
# ##########



if LIB64
#########################################################################
# Compiling 64-bit runtime
# #######################################################################

crt64dir=$(prefix)/$(host)/lib64
lib64dir=$(crt64dir)
include64=-I$(top_srcdir)/include64
COMPILE64=$(COMPILE) $(include64) -D_SYSCRT=1 -DCRTDLL=1 -c $(crt64srcdir)/

crt64_SCRIPTS = \
  crt64/libcrtdll.a crt64/libmsvcrt.a crt64/libmsvcr80.a \
  crt64/crt1.o crt64/crt2.o crt64/dllcrt1.o crt64/dllcrt2.o \
  crt64/CRT_fp8.o crt64/CRT_fp10.o crt64/txtmode.o crt64/binmode.o crt64/crtbegin.o crt64/crtend.o \
  crt64/gcrt0.o crt64/gcrt1.o crt64/gcrt2.o
crt64/crt1.o:
	$(COMPILE64)crtexe.c -o $@ -D__CRTDLL__ -U__MSVCRT__
crt64/crt2.o:
	$(COMPILE64)crtexe.c -o $@ -D__MSVCRT__ -U__CRTDLL__
crt64/dllcrt1.o:
	$(COMPILE64)crtdll.c -o $@ -D__CRTDLL__ -U__MSVCRT__
crt64/dllcrt2.o:
	$(COMPILE64)crtdll.c -o $@ -D__MSVCRT__ -U__CRTDLL__

crt64/lib%.a: crt64/%.def
	$(DTDEF) $(crt64srcdir)/$*.def --dllname lib64/$*.dll

crt64/gcrt0.o: profile/gcrt0.c
	$(COMPILE) -c $? -o $@ 
crt64/gcrt1.o: profile/gcrt0.c
	$(COMPILE) -c $? -o $@ -U__MSVCRT__
crt64/gcrt2.o: profile/gcrt0.c
	$(COMPILE) -c $? -o $@ -D__MSVCRT__



lib64_LIBRARIES = lib64/libm.a
nodist_lib64_libm_a_SOURCES = _libm_dummy.c

lib64_LIBRARIES += lib64/libmingwthrd.a
lib64_libmingwthrd_a_SOURCES = libsrc/dummy_mingwthrd.c

lib64_LIBRARIES += lib64/libshell32.a
lib64_libshell32_a_SOURCES = libsrc/shell32.c
lib64_libshell32_a_AR = $(DTLIB); $(AR) $(ARFLAGS)

lib64_LIBRARIES += lib64/libdinput.a
lib64_libdinput_a_SOURCES = libsrc/dinput_private.h \
  libsrc/dinput_joy.c   libsrc/dinput_joy2.c        \
  libsrc/dinput_mouse.c libsrc/dinput_mouse2.c      \
  libsrc/dinput_kbd.c
lib64_libdinput_a_AR = $(DTLIB); $(AR) $(ARFLAGS)

lib64_LIBRARIES += lib64/libdinput8.a
lib64_libdinput8_a_SOURCES = libsrc/dinput_private.h \
  libsrc/dinput_joy.c   libsrc/dinput_joy2.c         \
  libsrc/dinput_mouse.c libsrc/dinput_mouse2.c       \
  libsrc/dinput_kbd.c
lib64_libdinput8_a_AR = $(DTLIB); $(AR) $(ARFLAGS)

lib64_LIBRARIES += lib64/libdmoguids.a
lib64_libdmoguids_a_SOURCES = libsrc/dmoguids.c

lib64_LIBRARIES += lib64/libdxerr8.a
lib64_libdxerr8_a_SOURCES = libsrc/dxerr8.c libsrc/dxerr8w.c

lib64_LIBRARIES += lib64/libdxerr9.a
lib64_libdxerr9_a_SOURCES = libsrc/dxerr9.c libsrc/dxerr9w.c

lib64_LIBRARIES += lib64/libdxguid.a
lib64_libdxguid_a_SOURCES = libsrc/dxguid.c

lib64_LIBRARIES += lib64/libgmon.a
lib64_libgmon_a_SOURCES = profile/mcount.c \
  profile/profil.h profile/profil.c        \
  profile/gmon.h   profile/gmon.c

lib64_LIBRARIES += lib64/libksuser.a
lib64_libksuser_a_SOURCES = libsrc/ksuser.c
lib64_libksuser_a_AR = $(DTLIB); $(AR) $(ARFLAGS)

lib64_LIBRARIES += lib64/liblargeint.a
lib64_liblargeint_a_SOURCES = libsrc/largeint.c

lib64_LIBRARIES += lib64/libscrnsave.a
lib64_libscrnsave_a_SOURCES = libsrc/scrnsave.c

lib64_LIBRARIES += lib64/libscrnsavw.a
lib64_libscrnsavw_a_SOURCES = libsrc/scrnsave.c
lib64_libscrnsavw_a_CFLAGS = -DUNICODE

lib64_LIBRARIES += lib64/libuuid.a
lib64_libuuid_a_SOURCES = libsrc/uuid.c libsrc/devguid.c \
  libsrc/ativscp-uuid.c libsrc/cguid-uuid.c    libsrc/comcat-uuid.c \
  libsrc/docobj-uuid.c  libsrc/exdisp-uuid.c   libsrc/extras-uuid.c libsrc/hlguids-uuid.c  libsrc/hlink-uuid.c   libsrc/mlang-uuid.c \
  libsrc/mshtml-uuid.c  libsrc/msxml-uuid.c    libsrc/oaidl-uuid.c  libsrc/objidl-uuid.c   libsrc/objsafe-uuid.c libsrc/ocidl-uuid.c \
  libsrc/oleacc-uuid.c  libsrc/olectlid-uuid.c libsrc/oleidl-uuid.c libsrc/servprov-uuid.c libsrc/unknwn-uuid.c  libsrc/urlmon-uuid.c

lib64_LIBRARIES += lib64/libmingw32.a
lib64_libmingw32_a_CPPFLAGS=-D_SYSCRT=1 -DCRTDLL=1 $(include64) $(AM_CPPFLAGS)
lib64_libmingw32_a_SOURCES = crt64/crt0_c.c crt64/crt0_w.c crt64/CRT_fp10.c \
  crt64/atonexit.c crt64/charmax.c    crt64/cinitexe.c crt64/dll_argv.c      crt64/dllargv.c  crt64/dllentry.c crt64/dllmain.c      \
  crt64/gccmain.c  crt64/gs_support.c crt64/merr.c     crt64/mingw_helpers.c crt64/natstart.c crt64/_newmode.c crt64/pseudo-reloc.c \
  crt64/pseudo-reloc-list.c crt64/pesect.c crt64/tlssup.c crt64/wildcard.c   crt64/xtxtmode.c crt64/xncommod.c crt64/xthdloc.c

lib64_LIBRARIES += lib64/libmoldname.a
lib64_libmoldname_a_CPPFLAGS=$(include64) $(AM_CPPFLAGS)
lib64_libmoldname_a_SOURCES = \
  crt64/isascii.c crt64/iscsym.c crt64/iscsymf.c crt64/toascii.c crt64/strcasecmp.c crt64/strncasecmp.c crt64/wcscmpi.c
lib64_libmoldname_a_AR = $(DTDEF) $(crt64srcdir)/moldname-msvcrt.def -U --dllname msvcrt.dll; $(AR) $(ARFLAGS)
  
lib64_LIBRARIES += lib64/libstrmiids.a
lib64_libstrmiids_a_SOURCES = libsrc/strmiids.c

lib64_LIBRARIES += lib64/libws2_32.a
lib64_libws2_32_a_SOURCES = libsrc/ws2_32.c
lib64_libws2_32_a_AR = $(DTLIB); $(AR) $(ARFLAGS)

lib64_LIBRARIES += lib64/libmingwex.a
lib64_libmingwex_a_CPPFLAGS=$(include64) $(AM_CPPFLAGS)
lib64_libmingwex_a_SOURCES = \
  \
  complex/cabs.c     complex/casinhl.c  complex/cexpl.c   complex/csin.c   \
  complex/cabsf.c    complex/casinl.c   complex/cimag.c   complex/csinf.c  \
  complex/cabsl.c    complex/catan.c    complex/cimagf.c  complex/csinh.c  \
  complex/cacos.c    complex/catanf.c   complex/cimagl.c  complex/csinhf.c \
  complex/cacosf.c   complex/catanh.c   complex/clog.c    complex/csinhl.c \
  complex/cacosh.c   complex/catanhf.c  complex/clogf.c   complex/csinl.c  \
  complex/cacoshf.c  complex/catanhl.c  complex/clogl.c   complex/csqrt.c  \
  complex/cacoshl.c  complex/catanl.c   complex/cpow.c    complex/csqrtf.c \
  complex/cacosl.c   complex/ccos.c     complex/cpowf.c   complex/csqrtl.c \
  complex/carg.c     complex/ccosf.c    complex/cpowl.c   complex/ctan.c   \
  complex/cargf.c    complex/ccosh.c    complex/cproj.c   complex/ctanf.c  \
  complex/cargl.c    complex/ccoshf.c   complex/cprojf.c  complex/ctanh.c  \
  complex/casin.c    complex/ccoshl.c   complex/cprojl.c  complex/ctanhf.c \
  complex/casinf.c   complex/ccosl.c    complex/creal.c   complex/ctanhl.c \
  complex/casinh.c   complex/cexp.c     complex/crealf.c  complex/ctanl.c  \
  complex/casinhf.c  complex/cexpf.c    complex/creall.c  \
  \
  gdtoa/arithchk.c   gdtoa/dmisc.c      gdtoa/dtoa.c      gdtoa/gd_arith.h \
  gdtoa/g_dfmt.c     gdtoa/gd_qnan.h    gdtoa/gdtoa.c     gdtoa/gdtoa.h    \
  gdtoa/gdtoaimp.h   gdtoa/gethex.c     gdtoa/g_ffmt.c    gdtoa/g__fmt.c   \
  gdtoa/gmisc.c      gdtoa/g_xfmt.c     gdtoa/hd_init.c   gdtoa/hexnan.c   \
  gdtoa/mingw_snprintf.c                gdtoa/misc.c      gdtoa/qnan.c     \
  gdtoa/smisc.c      gdtoa/strtodg.c    gdtoa/strtodnrp.c gdtoa/strtof.c   \
  gdtoa/strtopx.c    gdtoa/sum.c        gdtoa/ulp.c       \
  \
  math/cephes_emath.h  math/cephes_mconf.h math/fastmath.h     math/fp_consts.h  \
  math/acosf.c         math/expm1l.c       math/ldexpl.c       math/powif.c      \
  math/acosh.c         math/fabs.c         math/lgamma.c       math/powil.c      \
  math/acoshf.c        math/fabsf.c        math/lgammaf.c      math/powl.c       \
  math/acoshl.c        math/fabsl.c        math/lgammal.c      math/remainderf.S \
  math/acosl.c         math/fastmath.h     math/llrint.c       math/remainderl.S \
  math/asinf.c         math/fdim.c         math/llrintf.c      math/remainder.S  \
  math/asinh.c         math/fdimf.c        math/llrintl.c      math/remquof.S    \
  math/asinhf.c        math/fdiml.c        math/llround.c      math/remquol.S    \
  math/asinhl.c        math/floorf.c       math/llroundf.c     math/remquo.S     \
  math/asinl.c         math/floorl.S       math/llroundl.c     math/rint.c       \
  math/atan2f.c        math/fmaf.S         math/log10f.c       math/rintf.c      \
  math/atan2l.c        math/fmal.c         math/log10l.S       math/rintl.c      \
  math/atanf.c         math/fma.S          math/log1pf.S       math/round.c      \
  math/atanh.c         math/fmax.c         math/log1pl.S       math/roundf.c     \
  math/atanhf.c        math/fmaxf.c        math/log1p.S        math/roundl.c     \
  math/atanhl.c        math/fmaxl.c        math/log2f.S        math/scalbnf.S    \
  math/atanl.c         math/fmin.c         math/log2l.S        math/scalbnl.S    \
  math/cbrt.c          math/fminf.c        math/log2.S         math/scalbn.S     \
  math/cbrtf.c         math/fminl.c        math/logb.c         math/s_erf.c      \
  math/cbrtl.c         math/fmodf.c        math/logbf.c        math/sf_erf.c     \
  math/ceilf.c         math/fmodl.c        math/logbl.c        math/signbit.c    \
  math/ceill.S         math/fpclassify.c   math/logf.c         math/signbitf.c   \
  math/cephes_emath.c  math/fpclassifyf.c  math/logl.S         math/signbitl.c   \
  math/cephes_emath.h  math/fpclassifyl.c  math/lrint.c        math/sinf.c       \
  math/cephes_mconf.h  math/fp_consts.c    math/lrintf.c       math/sinhf.c      \
  math/copysign.c      math/fp_constsf.c   math/lrintl.c       math/sinhl.c      \
  math/copysignf.c     math/fp_consts.h    math/lround.c       math/sinl.S       \
  math/copysignl.S     math/fp_constsl.c   math/lroundf.c      math/sqrtf.c      \
  math/cosf.c          math/frexpf.c       math/lroundl.c      math/sqrtl.c      \
  math/coshf.c         math/frexpl.S       math/modff.c        math/tanf.c       \
  math/coshl.c         math/fucom.c        math/modfl.c        math/tanhf.c      \
  math/cosl.S          math/hypotf.c       math/nearbyintf.S   math/tanhl.c      \
  math/erfl.c          math/hypotl.c       math/nearbyintl.S   math/tanl.S       \
  math/exp2f.S         math/ilogbf.S       math/nearbyint.S    math/tgamma.c     \
  math/exp2l.S         math/ilogbl.S       math/nextafterf.c   math/tgammaf.c    \
  math/exp2.S          math/ilogb.S        math/nextafterl.c   math/tgammal.c    \
  math/expf.c          math/isnan.c        math/nexttoward.c   math/trunc.c      \
  math/expl.c          math/isnanf.c       math/nexttowardf.c  math/truncf.c     \
  math/expm1.c         math/isnanl.c       math/powf.c         math/truncl.c     \
  math/expm1f.c        math/ldexpf.c       math/powi.c         math/pow.c        \
  \
  misc/mb_wc_common.h \
  misc/alarm.c            misc/fesetenv.c         misc/mbsinit.c               misc/wcstold.c        \
  misc/btowc.c            misc/fesetexceptflag.c  misc/mingw-aligned-malloc.c  misc/wcstoumax.c      \
  misc/ctime.c            misc/fesetround.c       misc/mingw-fseek.c           misc/wctob.c          \
  misc/delayimp.c         misc/fetestexcept.c     misc/_mkgmtime.c             misc/wctrans.c        \
  misc/difftime32.c       misc/feupdateenv.c      misc/mktime.c                misc/wctype.c         \
  misc/difftime64.c       misc/ftruncate.c        misc/seterrno.c              misc/wdirent.c        \
  misc/difftime.c         misc/fwide.c            misc/sleep.c                 misc/winbs_uint64.c   \
  misc/dirent.c           misc/getlogin.c         misc/spawnv.c                misc/winbs_ulong.c    \
  misc/execv.c            misc/getopt.c           misc/spawnve.c               misc/winbs_ushort.c   \
  misc/execve.c           misc/gettimeofday.c     misc/spawnvp.c               misc/wininterlocked.c \
  misc/execvp.c           misc/gmtime.c           misc/spawnvpe.c              misc/wmemchr.c        \
  misc/execvpe.c          misc/imaxabs.c          misc/strtoimax.c             misc/wmemcmp.c        \
  misc/feclearexcept.c    misc/imaxdiv.c          misc/strtold.c               misc/wmemcpy.c        \
  misc/fegetenv.c         misc/io_intrin.c        misc/strtoumax.c             misc/wmemmove.c       \
  misc/fegetexceptflag.c  misc/isblank.c          misc/time.c                  misc/wmemset.c        \
  misc/fegetround.c       misc/iswblank.c         misc/wassert.c               \
  misc/feholdexcept.c     misc/localtime.c        misc/wcrtomb.c               \
  misc/feraiseexcept.c    misc/mbrtowc.c          misc/wcstoimax.c             \
  misc/mingw_getsp.S \
  \
  stdio/atoll.c            stdio/ftello64.c      stdio/strtof.c     stdio/vsnwprintf.c \
  stdio/_Exit.c            stdio/_fwstat64i32.c  stdio/ulltoa.c     stdio/vsscanf.c    \
  stdio/_findfirst64i32.c  stdio/lltoa.c         stdio/ulltow.c     stdio/vswscanf.c   \
  stdio/_findnext64i32.c   stdio/lltow.c         stdio/vfscanf.c    stdio/vwscanf.c    \
  stdio/fopen64.c          stdio/lseek64.c       stdio/vfwscanf.c   stdio/wcstof.c     \
  stdio/fseeko64.c         stdio/snprintf.c      stdio/vscanf.c     stdio/wtoll.c      \
  stdio/_fstat64i32.c      stdio/snwprintf.c     stdio/vsnprintf.c  


lib64_SCRIPTS = \
  lib64/lib6to4svc.a    lib64/libaaaamon.a    lib64/libacgen64.a      lib64/libacledit.a    lib64/libaclui.a         \
  lib64/libactiveds.a   lib64/libactxprxy.a   lib64/libadmparse.a     lib64/libadmwprox.a   lib64/libadptif.a        \
  lib64/libadrot.a      lib64/libadsiis.a     lib64/libadsiisex.a     lib64/libadsldpc.a    lib64/libadsldp.a        \
  lib64/libadsmsext.a   lib64/libadsnt.a      lib64/libadvapi32.a     lib64/libadvpack.a    lib64/libaelupsvc.a      \
  lib64/libagentanm.a   lib64/libagentctl.a   lib64/libagentdp2.a     lib64/libagentdpv.a   lib64/libagentmpx.a      \
  lib64/libagentpsh.a   lib64/libagentsr.a    lib64/libagrmco64.a     lib64/libagtintl.a    lib64/libakscoinst.a     \
  lib64/libalrsvc.a     lib64/libamstream.a   lib64/libapcups.a       lib64/libapphelp.a    lib64/libappmgmts.a      \
  lib64/libappmgr.a     lib64/libaqadmin.a    lib64/libaqueue.a       lib64/libasp.a        lib64/libaspperf.a       \
  lib64/libasycfilt.a   lib64/libatkctrs.a    lib64/libatl.a          lib64/libatmlib.a     lib64/libatmpvcno.a      \
  lib64/libatrace.a     lib64/libaudiosrv.a   lib64/libauthz.a        lib64/libautodisc.a   lib64/libavicap32.a      \
  lib64/libavifil32.a   lib64/libazroles.a    lib64/libazroleui.a     lib64/libbasesrv.a    lib64/libbatmeter.a      \
  lib64/libbatt.a       lib64/libbidispl.a    lib64/libbitsprx2.a     lib64/libbitsprx3.a   lib64/libbnts.a          \
  lib64/libbootvid.a    lib64/libbrowscap.a   lib64/libbrowser.a      lib64/libbrowseui.a   lib64/libbrpinfo.a       \
  lib64/libbthci.a      lib64/libbthserv.a    lib64/libbtpanui.a      lib64/libcabinet.a    lib64/libcabview.a       \
  lib64/libcamocx.a     lib64/libcards.a      lib64/libcatsrv.a       lib64/libcatsrvps.a   lib64/libcatsrvut.a      \
  lib64/libccfgnt.a     lib64/libcdfview.a    lib64/libcdm.a          lib64/libcdosys.a     lib64/libcertcli.a       \
  lib64/libcertmgr.a    lib64/libcertobj.a    lib64/libcfgbkend.a     lib64/libcfgmgr32.a   lib64/libc_g18030.a      \
  lib64/libchsbrkr.a    lib64/libchtbrkr.a    lib64/libchtskdic.a     lib64/libchtskf.a     lib64/libciadmin.a       \
  lib64/libcic.a        lib64/libcimwin32.a   lib64/libCINTIME.a      lib64/libciodm.a      lib64/libc_is2022.a      \
  lib64/libc_iscii.a    lib64/libclbcatex.a   lib64/libclbcatq.a      lib64/libclb.a        lib64/libcliconfg.a      \
  lib64/libclusapi.a    lib64/libcmcfg32.a    lib64/libCmdEvTgProv.a  lib64/libcmdial32.a   lib64/libcmpbk32.a       \
  lib64/libcmprops.a    lib64/libcmsetacl.a   lib64/libcmutil.a       lib64/libcnbjmon.a    lib64/libcnetcfg.a       \
  lib64/libcnvfat.a     lib64/libcoadmin.a    lib64/libcolbact.a      lib64/libcomaddin.a   lib64/libcomadmin.a      \
  lib64/libcomcat.a     lib64/libcomctl32.a   lib64/libcomdlg32.a     lib64/libcompatui.a   lib64/libcompstui.a      \
  lib64/libcomrepl.a    lib64/libcomres.a     lib64/libcomsetup.a     lib64/libcomsnap.a    lib64/libcomsvcs.a       \
  lib64/libcomuid.a     lib64/libconfmsp.a    lib64/libconsole.a      lib64/libcontrot.a    lib64/libcorpol.a        \
  lib64/libcredui.a     lib64/libcrypt32.a    lib64/libcryptdlg.a     lib64/libcryptdll.a   lib64/libcryptext.a      \
  lib64/libcryptnet.a   lib64/libcryptsvc.a   lib64/libcryptui.a      lib64/libcscdll.a     lib64/libcscui.a         \
  lib64/libcsrsrv.a     lib64/libd3d8thk.a    lib64/libd3d9.a         lib64/libd3dxof.a     lib64/libdanim.a         \
  lib64/libdataclen.a   lib64/libdatime.a     lib64/libdavclnt.a      lib64/libdavcprox.a   lib64/libdbgeng.a        \
  lib64/libdbghelp.a    lib64/libdbnetlib.a   lib64/libdbnmpntw.a     lib64/libdciman32.a   lib64/libddraw.a         \
  lib64/libddrawex.a    lib64/libdeskadp.a    lib64/libdeskmon.a      lib64/libdeskperf.a   lib64/libdevenum.a       \
  lib64/libdevmgr.a     lib64/libdfrgifps.a   lib64/libdfrgsnap.a     lib64/libdfrgui.a     lib64/libdfsshlex.a      \
  lib64/libdgnet.a      lib64/libdhcpcsvc.a   lib64/libdhcpmon.a      lib64/libdhcpsapi.a   lib64/libdiactfrm.a      \
  lib64/libdigest.a     lib64/libdimap.a      lib64/libdimsntfy.a     lib64/libdimsroam.a   lib64/libdirectdb.a      \
  lib64/libdiskcopy.a   lib64/libdispex.a     lib64/libdmconfig.a     lib64/libdmdlgs.a     lib64/libdmdskmgr.a      \
  lib64/libdmintf.a     lib64/libdmivcitf.a   lib64/libdmocx.a        lib64/libdmserver.a   lib64/libdmutil.a        \
  lib64/libdmvdsitf.a   lib64/libdnsapi.a     lib64/libdnsrslvr.a     lib64/libdocprop2.a   lib64/libdocprop.a       \
  lib64/libdpnaddr.a    lib64/libdpnet.a      lib64/libdpnhpast.a     lib64/libdpnhupnp.a   lib64/libdpnlobby.a      \
  lib64/libdpvacm.a     lib64/libdpvoice.a    lib64/libdpvvox.a       lib64/libdrprov.a     lib64/libds32gt.a        \
  lib64/libdsauth.a     lib64/libdsdmo.a      lib64/libdsdmoprp.a     lib64/libdskquota.a   lib64/libdskquoui.a      \
  lib64/libdsound3d.a   lib64/libdsound.a     lib64/libdsprop.a       lib64/libdsprov.a     lib64/libdsquery.a       \
  lib64/libdssec.a      lib64/libdssenh.a     lib64/libdsuiext.a      lib64/libduser.a      lib64/libdxdiagn.a       \
  lib64/libdxtmsft.a    lib64/libdxtrans.a    lib64/libefsadu.a       lib64/libels.a        lib64/libencapi.a        \
  lib64/libersvc.a      lib64/libes.a         lib64/libesent.a        lib64/libesentprf.a   lib64/libesscli.a        \
  lib64/libeventcls.a   lib64/libeventlog.a   lib64/libevntagnt.a     lib64/libevntrprv.a   lib64/libevtgprov.a      \
  lib64/libexstrace.a   lib64/libextmgr.a     lib64/libf3ahvoas.a     lib64/libfastprox.a   lib64/libfaultrep.a      \
  lib64/libfcachdll.a   lib64/libfde.a        lib64/libfdeploy.a      lib64/libfeclient.a   lib64/libfilemgmt.a      \
  lib64/libfldrclnr.a   lib64/libfltlib.a     lib64/libfmifs.a        lib64/libfontext.a    lib64/libfontsub.a       \
  lib64/libframedyn.a   lib64/libfsusd.a      lib64/libftpctrs2.a     lib64/libftpmib.a     lib64/libftpsvc2.a       \
  lib64/libfwcfg.a      lib64/libfxsapi.a     lib64/libfxscfgwz.a     lib64/libfxscom.a     lib64/libfxscomex.a      \
  lib64/libfxsdrv.a     lib64/libfxsmon.a     lib64/libfxsocm.a       lib64/libfxsperf.a    lib64/libfxsroute.a      \
  lib64/libfxsst.a      lib64/libfxst30.a     lib64/libfxstiff.a      lib64/libfxsui.a      lib64/libfxswzrd.a       \
  lib64/libgcdef.a      lib64/libgdi32.a      lib64/libgetuname.a     lib64/libglmf32.a     lib64/libglu32.a         \
  lib64/libgpedit.a     lib64/libgpkcsp.a     lib64/libgptext.a       lib64/libguitrn.a     lib64/libgzip.a          \
  lib64/libh323msp.a    lib64/libhal.a        lib64/libhbaapi.a       lib64/libhgfs.a       lib64/libhhsetup.a       \
  lib64/libhid.a        lib64/libhlink.a      lib64/libhmmapi.a       lib64/libhnetcfg.a    lib64/libhnetmon.a       \
  lib64/libhnetwiz.a    lib64/libhostmib.a    lib64/libhotplug.a      lib64/libhticons.a    lib64/libhtrn_jis.a      \
  lib64/libhttpapi.a    lib64/libhttpext.a    lib64/libhttpmib.a      lib64/libhttpodbc.a   lib64/libhtui.a          \
  lib64/libhypertrm.a   lib64/libiasacct.a    lib64/libiasads.a       lib64/libiashlpr.a    lib64/libiasnap.a        \
  lib64/libiaspolcy.a   lib64/libiasrad.a     lib64/libiassam.a       lib64/libiassdo.a     lib64/libiassvcs.a       \
  lib64/libicaapi.a     lib64/libicfgnt5.a    lib64/libicm32.a        lib64/libicmp.a       lib64/libicmui.a         \
  lib64/libicwconn.a    lib64/libicwdial.a    lib64/libicwdl.a        lib64/libicwhelp.a    lib64/libicwphbk.a       \
  lib64/libicwutil.a    lib64/libidq.a        lib64/libieakeng.a      lib64/libieaksie.a    lib64/libiedkcs32.a      \
  lib64/libieencode.a   lib64/libiepeers.a    lib64/libiernonce.a     lib64/libiesetup.a    lib64/libifmon.a         \
  lib64/libifsutil.a    lib64/libigmpagnt.a   lib64/libiisadmin.a     lib64/libiiscfg.a     lib64/libiisclex4.a      \
  lib64/libiis.a        lib64/libiisext.a     lib64/libiislog.a       lib64/libiismap.a     lib64/libiisrstap.a      \
  lib64/libiisrtl.a     lib64/libiissuba.a    lib64/libiisui.a        lib64/libiisuiobj.a   lib64/libiisutil.a       \
  lib64/libiisw3adm.a   lib64/libiiswmi.a     lib64/libimagehlp.a     lib64/libimekrcic.a   lib64/libimepadsm.a      \
  lib64/libimeshare.a   lib64/libimgutil.a    lib64/libimjp81k.a      lib64/libimjpcic.a    lib64/libimjpcus.a       \
  lib64/libimjpdct.a    lib64/libimjputyc.a   lib64/libimlang.a       lib64/libimm32.a      lib64/libimsinsnt.a      \
  lib64/libimskdic.a    lib64/libimskf.a      lib64/libinetcfg.a      lib64/libinetcomm.a   lib64/libinetmgr.a       \
  lib64/libinetmib1.a   lib64/libinetpp.a     lib64/libinetppui.a     lib64/libinfoadmn.a   lib64/libinfocomm.a      \
  lib64/libinfoctrs.a   lib64/libinfosoft.a   lib64/libinitpki.a      lib64/libinput.a      lib64/libinseng.a        \
  lib64/libiphlpapi.a   lib64/libipmontr.a    lib64/libipnathlp.a     lib64/libippromon.a   lib64/libiprip.a         \
  lib64/libiprop.a      lib64/libiprtprio.a   lib64/libiprtrmgr.a     lib64/libipsecsnp.a   lib64/libipsecsvc.a      \
  lib64/libipsmsnap.a   lib64/libipv6mon.a    lib64/libipxsap.a       lib64/libirclass.a    lib64/libisapips.a       \
  lib64/libisatq.a      lib64/libiscomlog.a   lib64/libisign32.a      lib64/libitircl.a     lib64/libitss.a          \
  lib64/libixsso.a      lib64/libiyuv_32.a    lib64/libjet500.a       lib64/libjscript.a    lib64/libjsproxy.a       \
  lib64/libkbd101a.a    lib64/libkbd101b.a    lib64/libkbd101c.a      lib64/libkbd101.a     lib64/libkbd103.a        \
  lib64/libkbd106.a     lib64/libkbd106n.a    lib64/libkbda1.a        lib64/libkbda2.a      lib64/libkbda3.a         \
  lib64/libkbdal.a      lib64/libkbdarme.a    lib64/libkbdarmw.a      lib64/libkbdax2.a     lib64/libkbdaze.a        \
  lib64/libkbdazel.a    lib64/libkbdbe.a      lib64/libkbdbene.a      lib64/libkbdblr.a     lib64/libkbdbr.a         \
  lib64/libkbdbu.a      lib64/libkbdca.a      lib64/libkbdcan.a       lib64/libkbdcr.a      lib64/libkbdcz1.a        \
  lib64/libkbdcz2.a     lib64/libkbdcz.a      lib64/libkbdda.a        lib64/libkbddiv1.a    lib64/libkbddiv2.a       \
  lib64/libkbddv.a      lib64/libkbdes.a      lib64/libkbdest.a       lib64/libkbdfa.a      lib64/libkbdfc.a         \
  lib64/libkbdfi.a      lib64/libkbdfo.a      lib64/libkbdfr.a        lib64/libkbdgae.a     lib64/libkbdgeo.a        \
  lib64/libkbdgkl.a     lib64/libkbdgr1.a     lib64/libkbdgr.a        lib64/libkbdhe220.a   lib64/libkbdhe319.a      \
  lib64/libkbdheb.a     lib64/libkbdhe.a      lib64/libkbdhela2.a     lib64/libkbdhela3.a   lib64/libkbdhept.a       \
  lib64/libkbdhu1.a     lib64/libkbdhu.a      lib64/libkbdibm02.a     lib64/libkbdic.a      lib64/libkbdindev.a      \
  lib64/libkbdinguj.a   lib64/libkbdinhin.a   lib64/libkbdinkan.a     lib64/libkbdinmar.a   lib64/libkbdinpun.a      \
  lib64/libkbdintam.a   lib64/libkbdintel.a   lib64/libkbdir.a        lib64/libkbdit142.a   lib64/libkbdit.a         \
  lib64/libkbdjpn.a     lib64/libkbdkaz.a     lib64/libkbdkor.a       lib64/libkbdkyr.a     lib64/libkbdla.a         \
  lib64/libkbdlk41a.a   lib64/libkbdlk41j.a   lib64/libkbdlt1.a       lib64/libkbdlt.a      lib64/libkbdlv1.a        \
  lib64/libkbdlv.a      lib64/libkbdmac.a     lib64/libkbdmon.a       lib64/libkbdnec95.a   lib64/libkbdnecat.a      \
  lib64/libkbdnec.a     lib64/libkbdnecnt.a   lib64/libkbdne.a        lib64/libkbdno.a      lib64/libkbdpl1.a        \
  lib64/libkbdpl.a      lib64/libkbdpo.a      lib64/libkbdro.a        lib64/libkbdru1.a     lib64/libkbdru.a         \
  lib64/libkbdsf.a      lib64/libkbdsg.a      lib64/libkbdsl1.a       lib64/libkbdsl.a      lib64/libkbdsp.a         \
  lib64/libkbdsw.a      lib64/libkbdsyr1.a    lib64/libkbdsyr2.a      lib64/libkbdtat.a     lib64/libkbdth0.a        \
  lib64/libkbdth1.a     lib64/libkbdth2.a     lib64/libkbdth3.a       lib64/libkbdtuf.a     lib64/libkbdtuq.a        \
  lib64/libkbduk.a      lib64/libkbdur.a      lib64/libkbdurdu.a      lib64/libkbdusa.a     lib64/libkbdus.a         \
  lib64/libkbdusl.a     lib64/libkbdusr.a     lib64/libkbdusx.a       lib64/libkbduzb.a     lib64/libkbdvntc.a       \
  lib64/libkbdycc.a     lib64/libkbdycl.a     lib64/libkd1394.a       lib64/libkdcom.a      lib64/libkerberos.a      \
  lib64/libkeymgr.a     lib64/libkorwbrkr.a   lib64/libkrnlprov.a     lib64/liblangwrbk.a   lib64/liblicdll.a        \
  lib64/liblicmgr10.a   lib64/liblicwmi.a     lib64/liblinkinfo.a     lib64/liblmhsvc.a     lib64/liblmmib2.a        \
  lib64/liblmrt.a       lib64/libloadperf.a   lib64/liblocalsec.a     lib64/liblocalspl.a   lib64/liblocalui.a       \
  lib64/liblog.a        lib64/libloghours.a   lib64/liblogscrpt.a     lib64/liblonsint.a    lib64/liblpdsvc.a        \
  lib64/liblpk.a        lib64/liblprhelp.a    lib64/liblprmon.a       lib64/liblprmonui.a   lib64/liblsasrv.a        \
  lib64/liblz32.a       lib64/libmag_hook.a   lib64/libmailmsg.a      lib64/libmapi32.a     lib64/libmapistub.a      \
  lib64/libmcastmib.a   lib64/libmcd32.a      lib64/libmcdsrv32.a     lib64/libmchgrcoi.a   lib64/libmciavi32.a      \
  lib64/libmcicda.a     lib64/libmciole32.a   lib64/libmciqtz32.a     lib64/libmciseq.a     lib64/libmciwave.a       \
  lib64/libmdhcp.a      lib64/libmdminst.a    lib64/libmetadata.a     lib64/libmf3216.a     lib64/libmfc42.a         \
  lib64/libmfc42u.a     lib64/libmfcsubs.a    lib64/libmgmtapi.a      lib64/libmidimap.a    lib64/libmigism.a        \
  lib64/libmiglibnt.a   lib64/libmimefilt.a   lib64/libmlang.a        lib64/libmll_hp.a     lib64/libmll_mtf.a       \
  lib64/libmll_qic.a    lib64/libmmcbase.a    lib64/libmmcndmgr.a     lib64/libmmcshext.a   lib64/libmmfutil.a       \
  lib64/libmmutilse.a   lib64/libmobsync.a    lib64/libmodemui.a      lib64/libmofd.a       lib64/libmprapi.a        \
  lib64/libmprddm.a     lib64/libmpr.a        lib64/libmprdim.a       lib64/libmprmsg.a     lib64/libmprui.a         \
  lib64/libmqad.a       lib64/libmqcertui.a   lib64/libmqdscli.a      lib64/libmqgentr.a    lib64/libmqise.a         \
  lib64/libmqlogmgr.a   lib64/libmqoa.a       lib64/libmqperf.a       lib64/libmqqm.a       lib64/libmqrt.a          \
  lib64/libmqrtdep.a    lib64/libmqsec.a      lib64/libmqsnap.a       lib64/libmqtrig.a     lib64/libmqupgrd.a       \
  lib64/libmqutil.a     lib64/libmsaatext.a   lib64/libmsacm32.a      lib64/libmsadce.a     lib64/libmsadcf.a        \
  lib64/libmsadco.a     lib64/libmsadcs.a     lib64/libmsadds.a       lib64/libmsado15.a    lib64/libmsadomd.a       \
  lib64/libmsador15.a   lib64/libmsadox.a     lib64/libmsadrh15.a     lib64/libmsafd.a      lib64/libmsasn1.a        \
  lib64/libmscandui.a   lib64/libmscat32.a    lib64/libmscms.a        lib64/libmsctf.a      lib64/libmsctfp.a        \
  lib64/libmsdadiag.a   lib64/libmsdaosp.a    lib64/libmsdaprst.a     lib64/libmsdaps.a     lib64/libmsdarem.a       \
  lib64/libmsdart.a     lib64/libmsdatl3.a    lib64/libmsdfmap.a      lib64/libmsdmo.a      lib64/libmsdtclog.a      \
  lib64/libmsdtcprx.a   lib64/libmsdtcstp.a   lib64/libmsdtctm.a      lib64/libmsdtcuiu.a   lib64/libmsftedit.a      \
  lib64/libmsgina.a     lib64/libmsgr3en.a    lib64/libmsgrocm.a      lib64/libmsgsvc.a     lib64/libmshtml.a        \
  lib64/libmshtmled.a   lib64/libmsi.a        lib64/libmsident.a      lib64/libmsieftp.a    lib64/libmsihnd.a        \
  lib64/libmsimg32.a    lib64/libmsimtf.a     lib64/libmsinfo.a       lib64/libmsiprov.a    lib64/libmsir3jp.a       \
  lib64/libmsisip.a     lib64/libmslbui.a     lib64/libmsls31.a       lib64/libmslwvtts.a   lib64/libmsmqocm.a       \
  lib64/libmsobcomm.a   lib64/libmsobdl.a     lib64/libmsobmain.a     lib64/libmsobshel.a   lib64/libmsobweb.a       \
  lib64/libmsoeacct.a   lib64/libmsoe.a       lib64/libmsoert2.a      lib64/libmspatcha.a   lib64/libmspmsnsv.a      \
  lib64/libmsports.a    lib64/libmsrating.a   lib64/libmsrle32.a      lib64/libmssign32.a   lib64/libmssip32.a       \
  lib64/libmstask.a     lib64/libmstime.a     lib64/libmstlsapi.a     lib64/libmstscax.a    lib64/libmsutb.a         \
  lib64/libmsv1_0.a     lib64/libmsvcirt.a    lib64/libmsvcp60.a      lib64/libmsvfw32.a    lib64/libmsvidc32.a      \
  lib64/libmsvidctl.a   lib64/libmsw3prt.a    lib64/libmswsock.a      lib64/libmsxactps.a   lib64/libmsxml3.a        \
  lib64/libmsxs64.a     lib64/libmsyuv.a      lib64/libmtxclu.a       lib64/libmtxdm.a      lib64/libmtxex.a         \
  lib64/libmtxoci.a     lib64/libmycomput.a   lib64/libmydocs.a       lib64/libnarrhook.a   lib64/libncobjapi.a      \
  lib64/libncprov.a     lib64/libncxpnt.a     lib64/libnddeapi.a      lib64/libnddenb32.a   lib64/libndisnpp.a       \
  lib64/libnetapi32.a   lib64/libnetcfgx.a    lib64/libnetid.a        lib64/libnetlogon.a   lib64/libnetman.a        \
  lib64/libnetoc.a      lib64/libnetplwiz.a   lib64/libnetrap.a       lib64/libnetshell.a   lib64/libnetui0.a        \
  lib64/libnetui1.a     lib64/libnetui2.a     lib64/libnewdev.a       lib64/libnextlink.a   lib64/libnlhtml.a        \
  lib64/libnntpadm.a    lib64/libnntpapi.a    lib64/libnntpsnap.a     lib64/libnpptools.a   lib64/libnshipsec.a      \
  lib64/libntdll.a      lib64/libntdsapi.a    lib64/libntdsbcli.a     lib64/libntevt.a      lib64/libntfsdrv.a       \
  lib64/libntlanman.a   lib64/libntlanui2.a   lib64/libntlanui.a      lib64/libntlsapi.a    lib64/libntmarta.a       \
  lib64/libntmsapi.a    lib64/libntmsdba.a    lib64/libntmsevt.a      lib64/libntmsmgr.a    lib64/libntmssvc.a       \
  lib64/libntoc.a       lib64/libntprint.a    lib64/libntshrui.a      lib64/libntvdm64.a    lib64/libnwprovau.a      \
  lib64/liboakley.a     lib64/libobjsel.a     lib64/liboccache.a      lib64/libocgen.a      lib64/libocmanage.a      \
  lib64/libocmsn.a      lib64/libodbc32.a     lib64/libodbc32gt.a     lib64/libodbcbcp.a    lib64/libodbcconf.a      \
  lib64/libodbccp32.a   lib64/libodbccr32.a   lib64/libodbccu32.a     lib64/libodbctrac.a   lib64/liboeimport.a      \
  lib64/liboemiglib.a   lib64/libofffilt.a    lib64/libole32.a        lib64/liboleacc.a     lib64/liboleaut32.a      \
  lib64/libolecli32.a   lib64/libolecnv32.a   lib64/liboledb32.a      lib64/liboledb32r.a   lib64/liboledlg.a        \
  lib64/liboleprn.a     lib64/libolesvr32.a   lib64/libopengl32.a     lib64/libosuninst.a   lib64/libovprintmondll.a \
  lib64/libpadrs404.a   lib64/libpadrs411.a   lib64/libpadrs412.a     lib64/libpadrs804.a   lib64/libpanmap.a        \
  lib64/libpautoenr.a   lib64/libpchshell.a   lib64/libpchsvc.a       lib64/libpdh.a        lib64/libperfctrs.a      \
  lib64/libperfdisk.a   lib64/libperfnet.a    lib64/libperfos.a       lib64/libperfproc.a   lib64/libperfts.a        \
  lib64/libphotowiz.a   lib64/libpid.a        lib64/libpidgen.a       lib64/libpintlcsa.a   lib64/libpintlcsd.a      \
  lib64/libpjlmon.a     lib64/libpngfilt.a    lib64/libpolicman.a     lib64/libpolstore.a   lib64/libpowrprof.a      \
  lib64/libprintui.a    lib64/libprofmap.a    lib64/libprovthrd.a     lib64/libPS5UI.a      lib64/libpsapi.a         \
  lib64/libpsbase.a     lib64/libpschdprf.a   lib64/libPSCRIPT5.a     lib64/libpsnppagn.a   lib64/libpstorec.a       \
  lib64/libpstorsvc.a   lib64/libqasf.a       lib64/libqcap.a         lib64/libqdvd.a       lib64/libqdv.a           \
  lib64/libqedit.a      lib64/libqmgr.a       lib64/libqmgrprxy.a     lib64/libqosname.a    lib64/libquartz.a        \
  lib64/libquery.a      lib64/libracpldlg.a   lib64/librasadhlp.a     lib64/librasapi32.a   lib64/librasauto.a       \
  lib64/libraschap.a    lib64/librasctrs.a    lib64/librasdlg.a       lib64/librasman.a     lib64/librasmans.a       \
  lib64/librasmontr.a   lib64/librasmxs.a     lib64/librasppp.a       lib64/librasrad.a     lib64/librassapi.a       \
  lib64/librasser.a     lib64/librastapi.a    lib64/librastls.a       lib64/librcbdyctl.a   lib64/librdchost.a       \
  lib64/librdpcfgex.a   lib64/librdpsnd.a     lib64/librdpwsx.a       lib64/libregapi.a     lib64/libregsvc.a        \
  lib64/libregwizc.a    lib64/libremotepg.a   lib64/librend.a         lib64/librepdrvfs.a   lib64/libresutils.a      \
  lib64/libriched20.a   lib64/librnr20.a      lib64/libroutetab.a     lib64/librpcns4.a     lib64/librpcnsh.a        \
  lib64/librpcref.a     lib64/librpcrt4.a     lib64/librpcss.a        lib64/librsaenh.a     lib64/librsfsaps.a       \
  lib64/librshx32.a     lib64/librsmps.a      lib64/librtm.a          lib64/librtutils.a    lib64/librwnh.a          \
  lib64/libsafrcdlg.a   lib64/libsafrdm.a     lib64/libsafrslv.a      lib64/libsamlib.a     lib64/libsamsrv.a        \
  lib64/libsapi.a       lib64/libscarddlg.a   lib64/libsccbase.a      lib64/libsccsccp.a    lib64/libscecli.a        \
  lib64/libscesrv.a     lib64/libschannel.a   lib64/libschedsvc.a     lib64/libsclgntfy.a   lib64/libscredir.a       \
  lib64/libscript.a     lib64/libscripto.a    lib64/libscriptpw.a     lib64/libscrobj.a     lib64/libscrptutl.a      \
  lib64/libscrrun.a     lib64/libsdhcinst.a   lib64/libsdpblb.a       lib64/libseclogon.a   lib64/libsecur32.a       \
  lib64/libsecurity.a   lib64/libsendcmsg.a   lib64/libsendmail.a     lib64/libsensapi.a    lib64/libsenscfg.a       \
  lib64/libsens.a       lib64/libseo.a        lib64/libseos.a         lib64/libserialui.a   lib64/libservdeps.a      \
  lib64/libserwvdrv.a   lib64/libsetupapi.a   lib64/libsetupqry.a     lib64/libsfc.a        lib64/libsfcfiles.a      \
  lib64/libsfc_os.a     lib64/libsfmapi.a     lib64/libshdocvw.a      lib64/libshfolder.a   lib64/libshgina.a        \
  lib64/libshimeng.a    lib64/libshimgvw.a    lib64/libshlwapi.a      lib64/libshmedia.a    lib64/libshscrap.a       \
  lib64/libshsvcs.a     lib64/libsigtab.a     lib64/libsimptcp.a      lib64/libsisbkup.a    lib64/libskdll.a         \
  lib64/libslayerxp.a   lib64/libslbcsp.a     lib64/libslbiop.a       lib64/libsmlogcfg.a   lib64/libsmtpadm.a       \
  lib64/libsmtpapi.a    lib64/libsmtpcons.a   lib64/libsmtpctrs.a     lib64/libsmtpsnap.a   lib64/libsmtpsvc.a       \
  lib64/libsniffpol.a   lib64/libsnmpapi.a    lib64/libsnmpcl.a       lib64/libsnmpincl.a   lib64/libsnmpmib.a       \
  lib64/libsnmpsmir.a   lib64/libsnmpsnap.a   lib64/libsnmpstup.a     lib64/libsnmpthrd.a   lib64/libsnprfdll.a      \
  lib64/libsoftkbd.a    lib64/libsoftkey.a    lib64/libsoftpub.a      lib64/libspcommon.a   lib64/libspoolss.a       \
  lib64/libsptip.a      lib64/libspttseng.a   lib64/libsqlsrv32.a     lib64/libsqlxmlx.a    lib64/libsrchctls.a      \
  lib64/libsrchui.a     lib64/libsrclient.a   lib64/libsrrstr.a       lib64/libsrsvc.a      lib64/libsrvsvc.a        \
  lib64/libssdpapi.a    lib64/libssdpsrv.a    lib64/libssinc.a        lib64/libsstub.a      lib64/libstaxmem.a       \
  lib64/libstclient.a   lib64/libstdprov.a    lib64/libsti_ci.a       lib64/libsti.a        lib64/libstobject.a      \
  lib64/libstorprop.a   lib64/libstreamci.a   lib64/libstrmfilt.a     lib64/libsvcext.a     lib64/libsvcpack.a       \
  lib64/libswprv.a      lib64/libsxs.a        lib64/libsynceng.a      lib64/libsyncui.a     lib64/libsysinv.a        \
  lib64/libsysmod.a     lib64/libsyssetup.a   lib64/libt2embed.a      lib64/libtapi32.a     lib64/libtapi3.a         \
  lib64/libtapiperf.a   lib64/libtapisrv.a    lib64/libtcpmib.a       lib64/libtcpmon.a     lib64/libtcpmonui.a      \
  lib64/libtermmgr.a    lib64/libtermsrv.a    lib64/libthawbrkr.a     lib64/libthemeui.a    lib64/libtlntsvrp.a      \
  lib64/libtraffic.a    lib64/libtrialoc.a    lib64/libtrkwks.a       lib64/libtsappcmp.a   lib64/libtsbyuv.a        \
  lib64/libtscfgwmi.a   lib64/libtsd32.a      lib64/libtshoot.a       lib64/libtsoc.a       lib64/libtwext.a         \
  lib64/libtxflog.a     lib64/libudhisapi.a   lib64/libufat.a         lib64/libuihelper.a   lib64/libulib.a          \
  lib64/libumandlg.a    lib64/libumdmxfrm.a   lib64/libumpnpmgr.a     lib64/libUNIDRV.a     lib64/libUNIDRVUI.a      \
  lib64/libuniime.a     lib64/libunimdmat.a   lib64/libuniplat.a      lib64/libuntfs.a      lib64/libupnp.a          \
  lib64/libupnphost.a   lib64/libupnpui.a     lib64/libureg.a         lib64/liburlauth.a    lib64/liburl.a           \
  lib64/liburlmon.a     lib64/libusbmon.a     lib64/libuser32.a       lib64/libuserenv.a    lib64/libusp10.a         \
  lib64/libutildll.a    lib64/libuxtheme.a    lib64/libvbscript.a     lib64/libvdsbas.a     lib64/libvdsdyndr.a      \
  lib64/libvds_ps.a     lib64/libvdsutil.a    lib64/libvdswmi.a       lib64/libverifier.a   lib64/libversion.a       \
  lib64/libvgx.a        lib64/libviewprov.a   lib64/libvmx_mode.a     lib64/libvssapi.a     lib64/libvss_ps.a        \
  lib64/libvsswmi.a     lib64/libw32time.a    lib64/libw32topl.a      lib64/libw3cache.a    lib64/libw3comlog.a      \
  lib64/libw3core.a     lib64/libw3ctrlps.a   lib64/libw3ctrs.a       lib64/libw3dt.a       lib64/libw3ext.a         \
  lib64/libw3isapi.a    lib64/libw3ssl.a      lib64/libw3tp.a         lib64/libwaaaamon.a   lib64/libwab32.a         \
  lib64/libwabfind.a    lib64/libwabimp.a     lib64/libwAcLayers.a    lib64/libwacledit.a   lib64/libwAcLua.a        \
  lib64/libwaclui.a     lib64/libwAcSpecfc.a  lib64/libwactiveds.a    lib64/libwactxprxy.a  lib64/libwacwow64.a      \
  lib64/libwAcXtrnal.a  lib64/libwadmparse.a  lib64/libwadmwprx.a     lib64/libwadptif.a    lib64/libwADROT.a        \
  lib64/libwadsiis.a    lib64/libwadsldpc.a   lib64/libwadsldp.a      lib64/libwadsmsext.a  lib64/libwadsnt.a        \
  lib64/libwadvapi32.a  lib64/libwadvpack.a   lib64/libwaelupsvc.a    lib64/libwagentanm.a  lib64/libwagentctl.a     \
  lib64/libwagentdp2.a  lib64/libwagentdpv.a  lib64/libwagentmpx.a    lib64/libwagentpsh.a  lib64/libwagentsr.a      \
  lib64/libwagtintl.a   lib64/libwair300pp.a  lib64/libwam.a          lib64/libwamps.a      lib64/libwamreg.a        \
  lib64/libwamregps.a   lib64/libwamstream.a  lib64/libwapcups.a      lib64/libwapphelp.a   lib64/libwappmgmts.a     \
  lib64/libwappmgr.a    lib64/libwasp.a       lib64/libwaspperf.a     lib64/libwasycfilt.a  lib64/libwatkctrs.a      \
  lib64/libwatl.a       lib64/libwatmlib.a    lib64/libwatmpvcno.a    lib64/libwaudiodev.a  lib64/libwaudiosrv.a     \
  lib64/libwauthz.a     lib64/libwautodisc.a  lib64/libwavemsp.a      lib64/libwavicap32.a  lib64/libwavifil32.a     \
  lib64/libwavmcoxp.a   lib64/libwazroles.a   lib64/libwazroleui.a    lib64/libwbatmeter.a  lib64/libwbatt.a         \
  lib64/libwbckg.a      lib64/libwbckgres.a   lib64/libwbemcntl.a     lib64/libwbemcomn.a   lib64/libwbemcons.a      \
  lib64/libwbemcore.a   lib64/libwbemdisp.a   lib64/libwbemess.a      lib64/libwbemperf.a   lib64/libwbemprox.a      \
  lib64/libwbemsvc.a    lib64/libwbemupgd.a   lib64/libwbidispl.a     lib64/libwbitsprx2.a  lib64/libwbitsprx3.a     \
  lib64/libwblackbox.a  lib64/libwbrowscap.a  lib64/libwbrowser.a     lib64/libwbrowseui.a  lib64/libwbrowsewm.a     \
  lib64/libwcabinet.a   lib64/libwcabview.a   lib64/libwcamocx.a      lib64/libwcards.a     lib64/libwcatsrv.a       \
  lib64/libwcatsrvps.a  lib64/libwcatsrvut.a  lib64/libwccfgnt.a      lib64/libwcdfview.a   lib64/libwcdosys.a       \
  lib64/libwcertcli.a   lib64/libwcertmgr.a   lib64/libwcertobj.a     lib64/libwc_eucdb.a   lib64/libwcewmdm.a       \
  lib64/libwcfgmgr32.a  lib64/libwc_g18030.a  lib64/libwchkr.a        lib64/libwchsbrkr.a   lib64/libwchtbrkr.a      \
  lib64/libwCHTSKDIC.a  lib64/libwCHTSKF.a    lib64/libwciadmin.a     lib64/libwcic.a       lib64/libwCINTIME.a      \
  lib64/libwciodm.a     lib64/libwc_is2022.a  lib64/libwc_iscii.a     lib64/libwclbcatex.a  lib64/libwclbcatq.a      \
  lib64/libwclb.a       lib64/libwclusapi.a   lib64/libwcmcfg32.a     lib64/libwcmdial32.a  lib64/libwCmnclim.a      \
  lib64/libwcmpbk32.a   lib64/libwcmsetACL.a  lib64/libwcmutil.a      lib64/libwcnbjmon.a   lib64/libwcnetcfg.a      \
  lib64/libwcnvfat.a    lib64/libwcolbact.a   lib64/libwcomaddin.a    lib64/libwcomadmin.a  lib64/libwcomcat.a       \
  lib64/libwcomctl32.a  lib64/libwcomdlg32.a  lib64/libwcompatUI.a    lib64/libwcompstui.a  lib64/libwcomres.a       \
  lib64/libwcomsnap.a   lib64/libwcomsvcs.a   lib64/libwcomuid.a      lib64/libwconfmsp.a   lib64/libwconsole.a      \
  lib64/libwContRot.a   lib64/libwcorpol.a    lib64/libwcredui.a      lib64/libwcrtdll.a    lib64/libwcrypt32.a      \
  lib64/libwcryptdlg.a  lib64/libwcryptdll.a  lib64/libwcryptext.a    lib64/libwcryptnet.a  lib64/libwcryptsvc.a     \
  lib64/libwcryptui.a   lib64/libwcsapi3t1.a  lib64/libwcscdll.a      lib64/libwcscui.a     lib64/libwc_snadb.a      \
  lib64/libwcsseqchk.a  lib64/libwctl3d32.a   lib64/libwcustsat.a     lib64/libwcyycoins.a  lib64/libwcyyports.a     \
  lib64/libwcyzcoins.a  lib64/libwcyzports.a  lib64/libwd3d8.a        lib64/libwd3d8thk.a   lib64/libwd3d9.a         \
  lib64/libwd3dim700.a  lib64/libwd3dim.a     lib64/libwd3dpmesh.a    lib64/libwd3dramp.a   lib64/libwd3drm.a        \
  lib64/libwd3dxof.a    lib64/libwdanim.a     lib64/libwdao360.a      lib64/libwdataclen.a  lib64/libwdatime.a       \
  lib64/libwdavclnt.a   lib64/libwdavcprox.a  lib64/libwdbgeng.a      lib64/libwdbghelp.a   lib64/libwdbnetlib.a     \
  lib64/libwdciman32.a  lib64/libwddraw.a     lib64/libwddrawex.a     lib64/libwdeskadp.a   lib64/libwdeskmon.a      \
  lib64/libwdeskperf.a  lib64/libwdevenum.a   lib64/libwdfsshlex.a    lib64/libwdgconfig.a  lib64/libwdgnet.a        \
  lib64/libwdgsetup.a   lib64/libwdhcpcsvc.a  lib64/libwdhcpmon.a     lib64/libwdhcpsapi.a  lib64/libwdiactfrm.a     \
  lib64/libwdigest.a    lib64/libwdigiinf.a   lib64/libwdigirlpt.a    lib64/libwdimap.a     lib64/libwdimsntfy.a     \
  lib64/libwdimsroam.a  lib64/libwdinput8.a   lib64/libwdinput.a      lib64/libwdirectdb.a  lib64/libwdiskcopy.a     \
  lib64/libwdispex.a    lib64/libwdisrvci.a   lib64/libwdmaud.a       lib64/libwdmband.a    lib64/libwdmcompos.a     \
  lib64/libwdmime.a     lib64/libwdmloader.a  lib64/libwdmocx.a       lib64/libwdmscript.a  lib64/libwdmstyle.a      \
  lib64/libwdmsynth.a   lib64/libwdmusic.a    lib64/libwdnsapi.a      lib64/libwdnsrslvr.a  lib64/libwdocprop2.a     \
  lib64/libwdocprop.a   lib64/libwdplay.a     lib64/libwdplayx.a      lib64/libwdpmodemx.a  lib64/libwdpnaddr.a      \
  lib64/libwdpnet.a     lib64/libwdpnhpast.a  lib64/libwdpnhupnp.a    lib64/libwdpnlobby.a  lib64/libwdpvacm.a       \
  lib64/libwdpvoice.a   lib64/libwdpvvox.a    lib64/libwdpwsockx.a    lib64/libwdrmclien.a  lib64/libwdrmstor.a      \
  lib64/libwdrmv2clt.a  lib64/libwdrprov.a    lib64/libwds32gt.a      lib64/libwdsauth.a    lib64/libwdsdmo.a        \
  lib64/libwdsdmoprp.a  lib64/libwdskquota.a  lib64/libwdskquoui.a    lib64/libwdsound3d.a  lib64/libwdsound.a       \
  lib64/libwdsprop.a    lib64/libwdsquery.a   lib64/libwdssec.a       lib64/libwdssenh.a    lib64/libwdsuiext.a      \
  lib64/libwdswave.a    lib64/libwduser.a     lib64/libwdx7vb.a       lib64/libwdx8vb.a     lib64/libwdxdiagn.a      \
  lib64/libwdxmasf.a    lib64/libwdxtmsft.a   lib64/libwdxtrans.a     lib64/libwebcheck.a   lib64/libwebclnt.a       \
  lib64/libwebhits.a    lib64/libwebvw.a      lib64/libwedb500.a      lib64/libwefsadu.a    lib64/libwels.a          \
  lib64/libwencapi.a    lib64/libwencdec.a    lib64/libwes.a          lib64/libwesent97.a   lib64/libwesent.a        \
  lib64/libwesentprf.a  lib64/libwesscli.a    lib64/libwevntrprv.a    lib64/libwevtgprov.a  lib64/libwexpsrv.a       \
  lib64/libwexstrace.a  lib64/libwextmgr.a    lib64/libwf3ahvoas.a    lib64/libwfastprox.a  lib64/libwfaultrep.a     \
  lib64/libwfde.a       lib64/libwfdeploy.a   lib64/libwfeclient.a    lib64/libwfilemgmt.a  lib64/libwfldrclnr.a     \
  lib64/libwfltlib.a    lib64/libwfmifs.a     lib64/libwfontext.a     lib64/libwfontsub.a   lib64/libwframedyn.a     \
  lib64/libwfsusd.a     lib64/libwftlx041e.a  lib64/libwftpctrs2.a    lib64/libwftsrch.a    lib64/libwfwcfg.a        \
  lib64/libwfxsapi.a    lib64/libwfxscom.a    lib64/libwfxscomex.a    lib64/libwfxsext32.a  lib64/libwfxsperf.a      \
  lib64/libwfxsxp32.a   lib64/libwgcdef.a     lib64/libwgdi32.a       lib64/libwgetuname.a  lib64/libwglmf32.a       \
  lib64/libwglu32.a     lib64/libwgpedit.a    lib64/libwgpkcsp.a      lib64/libwgptext.a    lib64/libwguitrna.a      \
  lib64/libwguitrn.a    lib64/libwgzip.a      lib64/libwh323msp.a     lib64/libwhbaapi.a    lib64/libwhccoin.a       \
  lib64/libwhhsetup.a   lib64/libwhid.a       lib64/libwhidserv.a     lib64/libwhlink.a     lib64/libwHMMAPI.a       \
  lib64/libwhnetcfg.a   lib64/libwhnetmon.a   lib64/libwhrtz.a        lib64/libwhsf_inst.a  lib64/libwhttpapi.a      \
  lib64/libwhttpext.a   lib64/libwhttpmib.a   lib64/libwhttpodbc.a    lib64/libwhtui.a      lib64/libwiadefui.a      \
  lib64/libwiadss.a     lib64/libwiarpc.a     lib64/libwiasacct.a     lib64/libwiasads.a    lib64/libwiascr.a        \
  lib64/libwiaservc.a   lib64/libwiashext.a   lib64/libwiashlpr.a     lib64/libwiasnap.a    lib64/libwiaspolcy.a     \
  lib64/libwiasrad.a    lib64/libwiasrecst.a  lib64/libwiassam.a      lib64/libwiassdo.a    lib64/libwiassvcs.a      \
  lib64/libwiavideo.a   lib64/libwiavusd.a    lib64/libwicfgnt5.a     lib64/libwicm32.a     lib64/libwicmp.a         \
  lib64/libwicmui.a     lib64/libwiconf32.a   lib64/libwicwconn.a     lib64/libwicwdial.a   lib64/libwicwdl.a        \
  lib64/libwicwhelp.a   lib64/libwicwphbk.a   lib64/libwicwutil.a     lib64/libwidq.a       lib64/libwieakeng.a      \
  lib64/libwieaksie.a   lib64/libwiedkcs32.a  lib64/libwieencode.a    lib64/libwiepeers.a   lib64/libwiernonce.a     \
  lib64/libwiesetup.a   lib64/libwifmon.a     lib64/libwifsutil.a     lib64/libwigmpagnt.a  lib64/libwiisext.a       \
  lib64/libwiislog.a    lib64/libwiismap.a    lib64/libwiispwchg.a    lib64/libwiisrstap.a  lib64/libwiisrtl.a       \
  lib64/libwiisui.a     lib64/libwiisuiobj.a  lib64/libwiisutil.a     lib64/libwiisw3adm.a  lib64/libwimagehlp.a     \
  lib64/libwimekrcic.a  lib64/libwimepadsm.a  lib64/libwimeshare.a    lib64/libwimgutil.a   lib64/libwimjp81k.a      \
  lib64/libwimjpcic.a   lib64/libwimjpcus.a   lib64/libwimjpdct.a     lib64/libwimjputyc.a  lib64/libwimlang.a       \
  lib64/libwimm32.a     lib64/libwimskdic.a   lib64/libwimskf.a       lib64/libwin32spl.a   lib64/libwinetcfg.a      \
  lib64/libwinetcomm.a  lib64/libwinetmgr.a   lib64/libwinetmib1.a    lib64/libwinetpp.a    lib64/libwinetppui.a     \
  lib64/libwinfax.a     lib64/libwinfoadmn.a  lib64/libwinfoctrs.a    lib64/libwinfosoft.a  lib64/libwininet.a       \
  lib64/libwinipsec.a   lib64/libwinitpki.a   lib64/libwinmm.a        lib64/libwinntbbu.a   lib64/libwinput.a        \
  lib64/libwinrnr.a     lib64/libwinscard.a   lib64/libwinseng.a      lib64/libwinspool.a   lib64/libwinsrv.a        \
  lib64/libwinsta.a     lib64/libwintrust.a   lib64/libwiphlpapi.a    lib64/libwipmontr.a   lib64/libwipnathlp.a     \
  lib64/libwippromon.a  lib64/libwiprip.a     lib64/libwiprop.a       lib64/libwiprtprio.a  lib64/libwiprtrmgr.a     \
  lib64/libwipsecsnp.a  lib64/libwipsecsvc.a  lib64/libwipsmsnap.a    lib64/libwipv6mon.a   lib64/libwipxsap.a       \
  lib64/libwir41_qc.a   lib64/libwir41_qcx.a  lib64/libwir50_32.a     lib64/libwir50_qc.a   lib64/libwir50_qcx.a     \
  lib64/libwisapips.a   lib64/libwiscomlog.a  lib64/libwisign32.a     lib64/libwitircl.a    lib64/libwitss.a         \
  lib64/libwixsso.a     lib64/libwiyuv_32.a   lib64/libwjet500.a      lib64/libwjobexec.a   lib64/libwjscript.a      \
  lib64/libwjsproxy.a   lib64/libwkbd101a.a   lib64/libwkbd101b.a     lib64/libwkbd101c.a   lib64/libwkbd101.a       \
  lib64/libwkbd103.a    lib64/libwkbd106.a    lib64/libwkbd106n.a     lib64/libwkbda1.a     lib64/libwkbda2.a        \
  lib64/libwkbda3.a     lib64/libwKBDAL.a     lib64/libwkbdarme.a     lib64/libwkbdarmw.a   lib64/libwkbdax2.a       \
  lib64/libwkbdaze.a    lib64/libwkbdazel.a   lib64/libwkbdbe.a       lib64/libwkbdbene.a   lib64/libwkbdblr.a       \
  lib64/libwkbdbr.a     lib64/libwkbdbu.a     lib64/libwkbdca.a       lib64/libwkbdcan.a    lib64/libwkbdcr.a        \
  lib64/libwkbdcz1.a    lib64/libwkbdcz2.a    lib64/libwkbdcz.a       lib64/libwkbdda.a     lib64/libwkbddiv1.a      \
  lib64/libwkbddiv2.a   lib64/libwkbddv.a     lib64/libwkbdes.a       lib64/libwkbdest.a    lib64/libwkbdfa.a        \
  lib64/libwkbdfc.a     lib64/libwkbdfi.a     lib64/libwkbdfo.a       lib64/libwkbdfr.a     lib64/libwkbdgae.a       \
  lib64/libwkbdgeo.a    lib64/libwkbdgkl.a    lib64/libwkbdgr1.a      lib64/libwkbdgr.a     lib64/libwkbdhe220.a     \
  lib64/libwkbdhe319.a  lib64/libwkbdheb.a    lib64/libwkbdhe.a       lib64/libwkbdhela2.a  lib64/libwkbdhela3.a     \
  lib64/libwkbdhept.a   lib64/libwkbdhu1.a    lib64/libwkbdhu.a       lib64/libwkbdibm02.a  lib64/libwkbdic.a        \
  lib64/libwkbdindev.a  lib64/libwkbdinguj.a  lib64/libwkbdinhin.a    lib64/libwkbdinkan.a  lib64/libwkbdinmar.a     \
  lib64/libwkbdinpun.a  lib64/libwkbdintam.a  lib64/libwkbdintel.a    lib64/libwkbdir.a     lib64/libwkbdit142.a     \
  lib64/libwkbdit.a     lib64/libwkbdjpn.a    lib64/libwkbdkaz.a      lib64/libwkbdkor.a    lib64/libwkbdkyr.a       \
  lib64/libwkbdla.a     lib64/libwkbdlk41a.a  lib64/libwkbdlk41j.a    lib64/libwkbdlt1.a    lib64/libwkbdlt.a        \
  lib64/libwkbdlv1.a    lib64/libwkbdlv.a     lib64/libwkbdmac.a      lib64/libwkbdmon.a    lib64/libwkbdnec95.a     \
  lib64/libwkbdnecAT.a  lib64/libwkbdnec.a    lib64/libwkbdnecNT.a    lib64/libwkbdne.a     lib64/libwkbdno.a        \
  lib64/libwkbdpl1.a    lib64/libwkbdpl.a     lib64/libwkbdpo.a       lib64/libwkbdro.a     lib64/libwkbdru1.a       \
  lib64/libwkbdru.a     lib64/libwkbdsf.a     lib64/libwkbdsg.a       lib64/libwkbdsl1.a    lib64/libwkbdsl.a        \
  lib64/libwkbdsp.a     lib64/libwkbdsw.a     lib64/libwkbdsyr1.a     lib64/libwkbdsyr2.a   lib64/libwkbdtat.a       \
  lib64/libwkbdth0.a    lib64/libwkbdth1.a    lib64/libwkbdth2.a      lib64/libwkbdth3.a    lib64/libwkbdtuf.a       \
  lib64/libwkbdtuq.a    lib64/libwkbduk.a     lib64/libwkbdur.a       lib64/libwkbdurdu.a   lib64/libwkbdusa.a       \
  lib64/libwkbdus.a     lib64/libwkbdusl.a    lib64/libwkbdusr.a      lib64/libwkbdusx.a    lib64/libwkbduzb.a       \
  lib64/libwkbdvntc.a   lib64/libwkbdycc.a    lib64/libwkbdycl.a      lib64/libwkerberos.a  lib64/libwkernel32.a     \
  lib64/libwkeymgr.a    lib64/libwkorwbrkr.a  lib64/libwkssvc.a       lib64/libwksuser.a    lib64/libwlangwrbk.a     \
  lib64/libwlanmon.a    lib64/libwlaprxy.a    lib64/libwldap32.a      lib64/libwlicmgr10.a  lib64/libwlinkinfo.a     \
  lib64/libwlmhsvc.a    lib64/libwlmmib2.a    lib64/libwlmrt.a        lib64/libwlnotify.a   lib64/libwloadperf.a     \
  lib64/libwlocalsec.a  lib64/libwlocalui.a   lib64/libwlog.a         lib64/libwloghours.a  lib64/libwlogscrpt.a     \
  lib64/libwlonsint.a   lib64/libwlpdsvc.a    lib64/libwlpk.a         lib64/libwlprhelp.a   lib64/libwlprmon.a       \
  lib64/libwlprmonui.a  lib64/libwlsnp.a      lib64/libwlstore.a      lib64/libwlz32.a      lib64/libwmag_hook.a     \
  lib64/libwmcastmib.a  lib64/libwmcd32.a     lib64/libwmchgrcoi.a    lib64/libwmciavi32.a  lib64/libwmcicda.a       \
  lib64/libwmciole32.a  lib64/libwmciqtz32.a  lib64/libwmciseq.a      lib64/libwmciwave.a   lib64/libwmdhcp.a        \
  lib64/libwmdminst.a   lib64/libwmf3216.a    lib64/libwmfc40.a       lib64/libwmfc40u.a    lib64/libwmfc42.a        \
  lib64/libwmfc42u.a    lib64/libwmfcsubs.a   lib64/libwmgmtapi.a     lib64/libwmi2xml.a    lib64/libwmiaprpl.a      \
  lib64/libwmicookr.a   lib64/libwmidcprv.a   lib64/libwmi.a          lib64/libwmidimap.a   lib64/libwmigisma.a      \
  lib64/libwmigism.a    lib64/libwmiglibnt.a  lib64/libwmimefilt.a    lib64/libwmipcima.a   lib64/libwmipdskq.a      \
  lib64/libwmipicmp.a   lib64/libwmipiprt.a   lib64/libwmipjobj.a     lib64/libwmiprop.a    lib64/libwmiprov.a       \
  lib64/libwmiprvsd.a   lib64/libwmipsess.a   lib64/libwmiscmgr.a     lib64/libwmisvc.a     lib64/libwmitimep.a      \
  lib64/libwmiutils.a   lib64/libwmlang.a     lib64/libwmll_hp.a      lib64/libwmll_mtf.a   lib64/libwmll_qic.a      \
  lib64/libwmmcbase.a   lib64/libwmmcndmgr.a  lib64/libwmmcshext.a    lib64/libwmmfutil.a   lib64/libwmmutilse.a     \
  lib64/libwmobsync.a   lib64/libwmodemui.a   lib64/libwmofd.a        lib64/libwmp43dmod.a  lib64/libwmp4sdmod.a     \
  lib64/libwmpg4dmod.a  lib64/libwmprapi.a    lib64/libwmprddm.a      lib64/libwmpr.a       lib64/libwmprdim.a       \
  lib64/libwmprmsg.a    lib64/libwmprui.a     lib64/libwmpshell.a     lib64/libwmpvis.a     lib64/libwmqad.a         \
  lib64/libwmqdscli.a   lib64/libwmqoa.a      lib64/libwmqperf.a      lib64/libwmqrt.a      lib64/libwmqsec.a        \
  lib64/libwmqutil.a    lib64/libwmsaatext.a  lib64/libwmsacm32.a     lib64/libwmsadce.a    lib64/libwmsadcf.a       \
  lib64/libwmsadco.a    lib64/libwmsadcs.a    lib64/libwmsadds.a      lib64/libwmsado15.a   lib64/libwmsadomd.a      \
  lib64/libwmsador15.a  lib64/libwmsadox.a    lib64/libwmsadrh15.a    lib64/libwmsafd.a     lib64/libwmsapsspc.a     \
  lib64/libwmsasn1.a    lib64/libwmscandui.a  lib64/libwmscat32.a     lib64/libwmscms.a     lib64/libwmscpxl32.a     \
  lib64/libwMSCTF.a     lib64/libwMSCTFP.a    lib64/libwmsdadc.a      lib64/libwmsdadiag.a  lib64/libwmsdaenum.a     \
  lib64/libwmsdaer.a    lib64/libwmsdaora.a   lib64/libwmsdaosp.a     lib64/libwmsdaprst.a  lib64/libwmsdaps.a       \
  lib64/libwmsdarem.a   lib64/libwmsdart.a    lib64/libwmsdasc.a      lib64/libwmsdasql.a   lib64/libwmsdatl3.a      \
  lib64/libwmsdatt.a    lib64/libwmsdaurl.a   lib64/libwmsdfmap.a     lib64/libwmsdmo.a     lib64/libwmsdtcprx.a     \
  lib64/libwmsdtcuiu.a  lib64/libwmsexch40.a  lib64/libwmsexcl40.a    lib64/libwmsftedit.a  lib64/libwmsgina.a       \
  lib64/libwmsgr3en.a   lib64/libwmshtml.a    lib64/libwmshtmled.a    lib64/libwmsi.a       lib64/libwmsident.a      \
  lib64/libwmsieftp.a   lib64/libwmsihnd.a    lib64/libwmsimg32.a     lib64/libwMSIMTF.a    lib64/libwmsir3jp.a      \
  lib64/libwmsisip.a    lib64/libwmsjet40.a   lib64/libwmsjetol1.a    lib64/libwmsjint40.a  lib64/libwmsjro.a        \
  lib64/libwmsjter40.a  lib64/libwmsjtes40.a  lib64/libwmslbui.a      lib64/libwmsls31.a    lib64/libwmsltus40.a     \
  lib64/libwmslwvtts.a  lib64/libwmsnetobj.a  lib64/libwmsnsspc.a     lib64/libwmsoeacct.a  lib64/libwmsoe.a         \
  lib64/libwmsoert2.a   lib64/libwmsorcl32.a  lib64/libwmspatcha.a    lib64/libwmspbde40.a  lib64/libwmspmsnsv.a     \
  lib64/libwmspmsp.a    lib64/libwmsports.a   lib64/libwmsr2c.a       lib64/libwmsrating.a  lib64/libwmsrd2x40.a     \
  lib64/libwmsrd3x40.a  lib64/libwmsrle32.a   lib64/libwmssap.a       lib64/libwmsscp.a     lib64/libwmssign32.a     \
  lib64/libwmssip32.a   lib64/libwmstask.a    lib64/libwmstext40.a    lib64/libwmstime.a    lib64/libwmstlsapi.a     \
  lib64/libwmstscax.a   lib64/libwmsutb.a     lib64/libwmsv1_0.a      lib64/libwmsvcirt.a   lib64/libwmsvcp50.a      \
  lib64/libwmsvcp60.a   lib64/libwmsvcrt20.a  lib64/libwmsvcrt40.a    lib64/libwmsvcrt.a    lib64/libwmsvfw32.a      \
  lib64/libwmsvidc32.a  lib64/libwmsvidctl.a  lib64/libwmsw3prt.a     lib64/libwmswebdvd.a  lib64/libwmswmdm.a       \
  lib64/libwmswsock.a   lib64/libwmsxactps.a  lib64/libwmsxbde40.a    lib64/libwmsxml2.a    lib64/libwmsxml3.a       \
  lib64/libwmsxml.a     lib64/libwmsyuv.a     lib64/libwmtxclu.a      lib64/libwmtxdm.a     lib64/libwmtxex.a        \
  lib64/libwmtxlegih.a  lib64/libwmtxoci.a    lib64/libwmxicfg.a      lib64/libwmxport.a    lib64/libwmycomput.a     \
  lib64/libwmydocs.a    lib64/libwnarrhook.a  lib64/libwncobjapi.a    lib64/libwnddeapi.a   lib64/libwnddenb32.a     \
  lib64/libwnetapi32.a  lib64/libwnetcfgx.a   lib64/libwnetid.a       lib64/libwnetlogon.a  lib64/libwnetman.a       \
  lib64/libwnetplwiz.a  lib64/libwnetrap.a    lib64/libwnetshell.a    lib64/libwnetui0.a    lib64/libwnetui1.a       \
  lib64/libwnetui2.a    lib64/libwnewdev.a    lib64/libwNEXTLINK.a    lib64/libwnlhtml.a    lib64/libwnntpadm.a      \
  lib64/libwnntpapi.a   lib64/libwnntpsnap.a  lib64/libwnpdsplay.a    lib64/libwnpptools.a  lib64/libwnshipsec.a     \
  lib64/libwntdll.a     lib64/libwntdsapi.a   lib64/libwntdsbcli.a    lib64/libwntlanman.a  lib64/libwntlanui2.a     \
  lib64/libwntlanui.a   lib64/libwntlsapi.a   lib64/libwntmarta.a     lib64/libwntmsapi.a   lib64/libwntprint.a      \
  lib64/libwntshrui.a   lib64/libwntvdm64.a   lib64/libwoakley.a      lib64/libwobjsel.a    lib64/libwoccache.a      \
  lib64/libwocmanage.a  lib64/libwodbc32.a    lib64/libwodbc32gt.a    lib64/libwodbcconf.a  lib64/libwodbccp32.a     \
  lib64/libwodbccr32.a  lib64/libwodbccu32.a  lib64/libwodbcji32.a    lib64/libwodbcjt32.a  lib64/libwodbctrac.a     \
  lib64/libwoddbse32.a  lib64/libwodexl32.a   lib64/libwodfox32.a     lib64/libwodpdx32.a   lib64/libwodtext32.a     \
  lib64/libwoeimport.a  lib64/libwoemiglib.a  lib64/libwofffilt.a     lib64/libwole32.a     lib64/libwoleacc.a       \
  lib64/libwoleaut32.a  lib64/libwolecli32.a  lib64/libwolecnv32.a    lib64/libwoledb32.a   lib64/libwoledb32r.a     \
  lib64/libwoledlg.a    lib64/libwoleprn.a    lib64/libwolepro32.a    lib64/libwolesvr32.a  lib64/libwolethk32.a     \
  lib64/libwopengl32.a  lib64/libwosuninst.a  lib64/libwow64cpu.a     lib64/libwow64.a      lib64/libwow64mib.a      \
  lib64/libwow64win.a   lib64/libwPADRS404.a  lib64/libwpadrs411.a    lib64/libwpadrs412.a  lib64/libwpadrs804.a     \
  lib64/libwpanmap.a    lib64/libwpautoenr.a  lib64/libwpd_ci.a       lib64/libwpdh.a       lib64/libwperfctrs.a     \
  lib64/libwperfdisk.a  lib64/libwperfnet.a   lib64/libwperfos.a      lib64/libwperfproc.a  lib64/libwperfts.a       \
  lib64/libwphotowiz.a  lib64/libwpid.a       lib64/libwpidgen.a      lib64/libwPINTLCSA.a  lib64/libwPINTLCSD.a     \
  lib64/libwpjlmon.a    lib64/libwpngfilt.a   lib64/libwpolstore.a    lib64/libwpowrprof.a  lib64/libwprintui.a      \
  lib64/libwprofmap.a   lib64/libwprovthrd.a  lib64/libwpsapi.a       lib64/libwpsbase.a    lib64/libwpschdprf.a     \
  lib64/libwpsnppagn.a  lib64/libwpstorec.a   lib64/libwpstorsvc.a    lib64/libwqasf.a      lib64/libwqcap.a         \
  lib64/libwqdvd.a      lib64/libwqdv.a       lib64/libwqedit.a       lib64/libwqmgrprxy.a  lib64/libwqosname.a      \
  lib64/libwquartz.a    lib64/libwquery.a     lib64/libwrasadhlp.a    lib64/libwrasapi32.a  lib64/libwrasauto.a      \
  lib64/libwraschap.a   lib64/libwrasctrs.a   lib64/libwrasdlg.a      lib64/libwrasman.a    lib64/libwrasmans.a      \
  lib64/libwrasmontr.a  lib64/libwrasmxs.a    lib64/libwrasppp.a      lib64/libwrasrad.a    lib64/libwrassapi.a      \
  lib64/libwrasser.a    lib64/libwrastapi.a   lib64/libwrastls.a      lib64/libwrdpsnd.a    lib64/libwregapi.a       \
  lib64/libwregsvc.a    lib64/libwregwizc.a   lib64/libwrend.a        lib64/libwresutils.a  lib64/libwriched20.a     \
  lib64/libwrnr20.a     lib64/libwroutetab.a  lib64/libwrpcns4.a      lib64/libwrpcnsh.a    lib64/libwrpcref.a       \
  lib64/libwrpcrt4.a    lib64/libwrsaenh.a    lib64/libwrshx32.a      lib64/libwrtm.a       lib64/libwrtutils.a      \
  lib64/libwrvse.a      lib64/libwrwnh.a      lib64/libws2help.a      lib64/libwsamlib.a    lib64/libwsapi.a         \
  lib64/libwsbe.a       lib64/libwsbeio.a     lib64/libwscarddlg.a    lib64/libwsccbase.a   lib64/libwsccsccp.a      \
  lib64/libwscecli.a    lib64/libwschannel.a  lib64/libwschedsvc.a    lib64/libwsclgntfy.a  lib64/libwscredir.a      \
  lib64/libwscripta.a   lib64/libwscript.a    lib64/libwscripto.a     lib64/libwscriptpw.a  lib64/libwscrobj.a       \
  lib64/libwscrptutl.a  lib64/libwscrrun.a    lib64/libwscsvc.a       lib64/libwsdpblb.a    lib64/libwsecedit.a      \
  lib64/libwseclogon.a  lib64/libwsecur32.a   lib64/libwsecurity.a    lib64/libwsendcmsg.a  lib64/libwsendmail.a     \
  lib64/libwsensapi.a   lib64/libwsenscfg.a   lib64/libwsens.a        lib64/libwseo.a       lib64/libwserialui.a     \
  lib64/libwservdeps.a  lib64/libwserwvdrv.a  lib64/libwsetupapi.a    lib64/libwsfc.a       lib64/libwsfcfiles.a     \
  lib64/libwsfc_os.a    lib64/libwsfmapi.a    lib64/libwshatm.a       lib64/libwshbth.a     lib64/libwshcon.a        \
  lib64/libwwdmaud.a    lib64/libwwinspool.a  lib64/libzoneoc.a       \
  \
  lib64/libkernel32.a   lib64/libdwmapi.a     lib64/libuxtheme.a

lib64/lib%.a:
	$(DTDEF) $(top_srcdir)/lib64/$*.def

endif
# End 64-bit runtime
##########

# Installation options
#

noinst_HEADERS = libsrc/dxerr.c \
 include64/internal.h include64/oscalls.h include64/sect_attribs.h


# Cleaning options
#

CLEANFILES = $(BUILT_SOURCES) $(crt64_SCRIPTS) $(lib64_SCRIPTS) $(crt32_SCRIPTS) $(lib32_SCRIPTS)

# Distribution options
#

EXTRA_DIST = DISCLAIMER
EXTRA_DIST += $(top_srcdir)/lib64/*.def $(top_srcdir)/lib32/*.def \
  $(crt64srcdir)/*.def \
  $(crt64srcdir)/crtexe.c \
  $(crt64srcdir)/crtdll.c \
  $(crt64srcdir)/CRT_fp8.c \
  $(crt64srcdir)/CRT_fp10.c \
  $(crt64srcdir)/txtmode.c \
  $(crt64srcdir)/binmode.c \
  $(crt64srcdir)/crtbegin.c \
  $(crt64srcdir)/crtend.c \
  profile/gcrt0.c \
  profile/COPYING profile/CYGWIN_LICENSE

DISTCHECK_CONFIGURE_FLAGS = --host=x86_64-pc-mingw32 --enable-lib32 $(withsys) $(enablevista)

dist-hook:
	rm -rf `find $(top_distdir) -name ".svn"`


