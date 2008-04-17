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
AM_CFLAGS=-pipe $(vistasupport)
AM_DLLTOOLFLAGS=-k --as=$(AS) --output-lib $@
DTDEF=$(DLLTOOL) $(AM_DLLTOOLFLAGS) --def
DTLIB=$(DTDEF) $(top_srcdir)/`echo $@ | sed '{s|/lib|/|;s|\.a|.def|}'`
crt64srcdir=$(top_srcdir)/crt64
crt32srcdir=$(top_srcdir)/crt32


BUILT_SOURCES = _libm_dummy.c
_libm_dummy.c:
	echo "static int __mingw_libm_dummy;" > _libm_dummy.c


if LIB32
#########
# Compiling 32-bit runtime
#

crt32dir=$(prefix)/$(host)/lib32
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

lib32_LIBRARIES += lib32/libkernel32.a
lib32_libkernel32_a_SOURCES = libsrc/kernel32.c
lib32_libkernel32_a_AR = $(DTLIB); $(AR) $(ARFLAGS)
lib32_libkernel32_a_CPPFLAGS = -m32

lib32_LIBRARIES += lib32/libshell32.a
lib32_libshell32_a_SOURCES = libsrc/shell32.c
lib32_libshell32_a_AR = $(DTLIB); $(AR) $(ARFLAGS)
lib32_libshell32_a_CPPFLAGS = -m32

lib32_LIBRARIES += lib32/libdinput.a
lib32_libdinput_a_SOURCES = libsrc/dinput_kbd.c \
  libsrc/dinput_joy.c   libsrc/dinput_joy2.c \
  libsrc/dinput_mouse.c libsrc/dinput_mouse2.c
lib32_libdinput_a_AR = $(DTLIB); $(AR) $(ARFLAGS)

lib32_LIBRARIES += lib32/libdinput8.a
lib32_libdinput8_a_SOURCES = libsrc/dinput_private.h \
  libsrc/dinput_joy.c   libsrc/dinput_joy2.c \
  libsrc/dinput_mouse.c libsrc/dinput_mouse2.c \
  libsrc/dinput_kbd.c
lib32_libdinput8_a_AR = $(DTLIB); $(AR) $(ARFLAGS)

lib32_LIBRARIES += lib32/libdmoguids.a
lib32_libdmoguids_a_SOURCES = libsrc/dmoguids.c

lib32_LIBRARIES += lib32/libdxerr8.a
lib32_libdxerr8_a_SOURCES = libsrc/dxerr8.c libsrc/dxerr8w.c

lib32_LIBRARIES += lib32/libdxerr9.a
lib32_libdxerr9_a_SOURCES = libsrc/dxerr9.c libsrc/dxerr9w.c

lib32_LIBRARIES += lib32/libdxguid.a
lib32_libdxguid_a_SOURCES = libsrc/dxguid.c

lib32_LIBRARIES += lib32/libksuser.a
lib32_libksuser_a_SOURCES = libsrc/ksuser.c
lib32_libksuser_a_AR = $(DTLIB); $(AR) $(ARFLAGS)

lib32_LIBRARIES += lib32/liblargeint.a
lib32_liblargeint_a_SOURCES = libsrc/largeint.c

lib32_LIBRARIES += lib32/libscrnsave.a
lib32_libscrnsave_a_SOURCES = libsrc/scrnsave.c

lib32_LIBRARIES += lib32/libscrnsavw.a
lib32_libscrnsavw_a_SOURCES = libsrc/scrnsave.c
lib32_libscrnsavw_a_CFLAGS = -DUNICODE

lib32_LIBRARIES += lib32/libstrmiids.a
lib32_libstrmiids_a_SOURCES = libsrc/strmiids.c

lib32_LIBRARIES += lib32/libuuid.a
lib32_libuuid_a_SOURCES = libsrc/uuid.c libsrc/devguid.c \
    libsrc/ativscp-uuid.c libsrc/cguid-uuid.c    libsrc/comcat-uuid.c \
    libsrc/docobj-uuid.c  libsrc/exdisp-uuid.c   libsrc/extras-uuid.c libsrc/hlguids-uuid.c  libsrc/hlink-uuid.c   libsrc/mlang-uuid.c \
    libsrc/mshtml-uuid.c  libsrc/msxml-uuid.c    libsrc/oaidl-uuid.c  libsrc/objidl-uuid.c   libsrc/objsafe-uuid.c libsrc/ocidl-uuid.c \
    libsrc/oleacc-uuid.c  libsrc/olectlid-uuid.c libsrc/oleidl-uuid.c libsrc/servprov-uuid.c libsrc/unknwn-uuid.c  libsrc/urlmon-uuid.c

lib32_LIBRARIES += lib32/libws2_32.a
lib32_libws2_32_a_SOURCES = libsrc/ws2_32.c
lib32_libws2_32_a_AR = $(DTLIB); $(AR) $(ARFLAGS)


#These defs have no accompanying sources.  Look into using the rule below to run the dlltool command
#for all libraries, including those with sources.
lib32_SCRIPTS = \
  lib32/aclui.def     lib32/advapi32.def  lib32/apcups.def    lib32/avicap32.def  lib32/avifil32.def \
  lib32/cap.def       lib32/cfgmgr32.def  lib32/comctl32.def  lib32/comdlg32.def  lib32/crypt32.def  \
  lib32/ctl3d32.def   lib32/d3d8.def      lib32/d3d9.def      lib32/d3dim.def     lib32/d3drm.def    \
  lib32/d3dx8d.def    lib32/d3dx9d.def    lib32/d3dxof.def    lib32/ddraw.def     lib32/dhcpcsvc.def \
                                          lib32/dlcapi.def    lib32/dnsapi.def    lib32/dplayx.def   \
  lib32/dpnaddr.def   lib32/dpnet.def     lib32/dpnlobby.def  lib32/dpvoice.def   lib32/dsetup.def   \
  lib32/dsound.def    lib32/dxapi.def     lib32/faultrep.def  lib32/gdi32.def     lib32/glaux.def    \
  lib32/glu32.def     lib32/glut32.def    lib32/glut.def      lib32/hal.def       lib32/hid.def      \
  lib32/hidparse.def  lib32/icmui.def     lib32/igmpagnt.def  lib32/imagehlp.def  lib32/imm32.def    \
  lib32/iphlpapi.def                      lib32/ksproxy.def                       lib32/lz32.def     \
  lib32/mapi32.def    lib32/mcd.def       lib32/mfcuia32.def  lib32/mgmtapi.def   lib32/mprapi.def   \
  lib32/mpr.def       lib32/mqrt.def      lib32/msacm32.def   lib32/mscms.def     lib32/msdmo.def    \
  lib32/msimg32.def   lib32/msvcp60.def   lib32/msvfw32.def   lib32/mswsock.def   lib32/nddeapi.def  \
  lib32/ndis.def      lib32/netapi32.def  lib32/newdev.def    lib32/ntdll.def     lib32/ntoskrnl.def \
  lib32/odbc32.def    lib32/odbccp32.def  lib32/ole32.def     lib32/oleacc.def    lib32/oleaut32.def \
  lib32/olecli32.def  lib32/oledlg.def    lib32/olepro32.def  lib32/olesvr32.def  lib32/opengl32.def \
  lib32/penwin32.def  lib32/pkpd32.def    lib32/powrprof.def  lib32/psapi.def     lib32/quartz.def   \
  lib32/rapi.def      lib32/rasapi32.def  lib32/rasdlg.def    lib32/rpcdce4.def   lib32/rpcns4.def   \
  lib32/rpcrt4.def    lib32/rtm.def       lib32/rtutils.def   lib32/scsiport.def  lib32/secur32.def  \
  lib32/setupapi.def                      lib32/shfolder.def  lib32/shlwapi.def   lib32/snmpapi.def  \
  lib32/svrapi.def    lib32/tapi32.def    lib32/tdi.def       lib32/th32.def      lib32/thunk32.def  \
  lib32/url.def       lib32/usbcamd2.def  lib32/usbcamd.def   lib32/user32.def    lib32/userenv.def  \
  lib32/usp10.def     lib32/uxtheme.def   lib32/vdmdbg.def    lib32/version.def   lib32/videoprt.def \
  lib32/win32k.def    lib32/win32spl.def  lib32/wininet.def   lib32/winmm.def     lib32/winspool.def \
  lib32/winstrm.def   lib32/wldap32.def   lib32/wow32.def                         lib32/wsnmp32.def  \
  lib32/wsock32.def   lib32/wst.def       lib32/wtsapi32.def

lib32/lib%.a:
	$(DTDEF) $(top_srcdir)/lib32/$*.def


endif
# End 32-bit runtime
# ##########



if LIB64
#########################################################################
# Compiling 64-bit runtime
# #######################################################################

crt64dir=$(prefix)/$(host)/lib
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

lib64_LIBRARIES += lib64/libkernel32.a
lib64_libkernel32_a_SOURCES = libsrc/kernel32.c
lib64_libkernel32_a_AR = $(DTLIB); $(AR) $(ARFLAGS)

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
  crt64/dirent.c     crt64/ftruncate.c  crt64/getopt.c    crt64/wdirent.c  \
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
  math/expm1f.c        math/ldexpf.c       math/powi.c         \
  \
  misc/mb_wc_common.h \
  misc/alarm.c            misc/fesetenv.c         misc/io_intrin.c             misc/wcrtomb.c        \
  misc/btowc.c            misc/fesetexceptflag.c  misc/mingw-aligned-malloc.c  misc/wcstoimax.c      \
  misc/ctime.c            misc/fesetround.c       misc/mingw-fseek.c           misc/wcstold.c        \
  misc/difftime32.c       misc/fetestexcept.c     misc/_mkgmtime.c             misc/wcstoumax.c      \
  misc/difftime64.c       misc/feupdateenv.c      misc/mktime.c                misc/wctob.c          \
  misc/difftime.c         misc/fwide.c            misc/seterrno.c              misc/wctrans.c        \
  misc/execv.c            misc/getlogin.c         misc/sleep.c                 misc/wctype.c         \
  misc/execve.c           misc/gettimeofday.c     misc/spawnv.c                misc/wininterlocked.c \
  misc/execvp.c           misc/gmtime.c           misc/spawnve.c               misc/wmemchr.c        \
  misc/execvpe.c          misc/imaxabs.c          misc/spawnvp.c               misc/wmemcmp.c        \
  misc/feclearexcept.c    misc/imaxdiv.c          misc/spawnvpe.c              misc/wmemcpy.c        \
  misc/fegetenv.c         misc/isblank.c          misc/strtoimax.c             misc/wmemmove.c       \
  misc/fegetexceptflag.c  misc/iswblank.c         misc/wmemset.c               misc/mingw_getsp.S    \
  misc/fegetround.c       misc/localtime.c        misc/strtoumax.c \
  misc/feholdexcept.c     misc/mbrtowc.c          misc/time.c      \
  misc/feraiseexcept.c    misc/mbsinit.c          misc/wassert.c   \
  \
  stdio/atoll.c            stdio/ftello64.c      stdio/strtof.c     stdio/vsnwprintf.c \
  stdio/_Exit.c            stdio/_fwstat64i32.c  stdio/ulltoa.c     stdio/vsscanf.c    \
  stdio/_findfirst64i32.c  stdio/lltoa.c         stdio/ulltow.c     stdio/vswscanf.c   \
  stdio/_findnext64i32.c   stdio/lltow.c         stdio/vfscanf.c    stdio/vwscanf.c    \
  stdio/fopen64.c          stdio/lseek64.c       stdio/vfwscanf.c   stdio/wcstof.c     \
  stdio/fseeko64.c         stdio/snprintf.c      stdio/vscanf.c     stdio/wtoll.c      \
  stdio/_fstat64i32.c      stdio/snwprintf.c     stdio/vsnprintf.c  


lib64_SCRIPTS = \
  lib64/6to4svc.a    lib64/aaaamon.a    lib64/acgen64.a      lib64/acledit.a    lib64/aclui.a         \
  lib64/activeds.a   lib64/actxprxy.a   lib64/admparse.a     lib64/admwprox.a   lib64/adptif.a        \
  lib64/adrot.a      lib64/adsiis.a     lib64/adsiisex.a     lib64/adsldpc.a    lib64/adsldp.a        \
  lib64/adsmsext.a   lib64/adsnt.a      lib64/advapi32.a     lib64/advpack.a    lib64/aelupsvc.a      \
  lib64/agentanm.a   lib64/agentctl.a   lib64/agentdp2.a     lib64/agentdpv.a   lib64/agentmpx.a      \
  lib64/agentpsh.a   lib64/agentsr.a    lib64/agrmco64.a     lib64/agtintl.a    lib64/akscoinst.a     \
  lib64/alrsvc.a     lib64/amstream.a   lib64/apcups.a       lib64/apphelp.a    lib64/appmgmts.a      \
  lib64/appmgr.a     lib64/aqadmin.a    lib64/aqueue.a       lib64/asp.a        lib64/aspperf.a       \
  lib64/asycfilt.a   lib64/atkctrs.a    lib64/atl.a          lib64/atmlib.a     lib64/atmpvcno.a      \
  lib64/atrace.a     lib64/audiosrv.a   lib64/authz.a        lib64/autodisc.a   lib64/avicap32.a      \
  lib64/avifil32.a   lib64/azroles.a    lib64/azroleui.a     lib64/basesrv.a    lib64/batmeter.a      \
  lib64/batt.a       lib64/bidispl.a    lib64/bitsprx2.a     lib64/bitsprx3.a   lib64/bnts.a          \
  lib64/bootvid.a    lib64/browscap.a   lib64/browser.a      lib64/browseui.a   lib64/brpinfo.a       \
  lib64/bthci.a      lib64/bthserv.a    lib64/btpanui.a      lib64/cabinet.a    lib64/cabview.a       \
  lib64/camocx.a     lib64/cards.a      lib64/catsrv.a       lib64/catsrvps.a   lib64/catsrvut.a      \
  lib64/ccfgnt.a     lib64/cdfview.a    lib64/cdm.a          lib64/cdosys.a     lib64/certcli.a       \
  lib64/certmgr.a    lib64/certobj.a    lib64/cfgbkend.a     lib64/cfgmgr32.a   lib64/c_g18030.a      \
  lib64/chsbrkr.a    lib64/chtbrkr.a    lib64/chtskdic.a     lib64/chtskf.a     lib64/ciadmin.a       \
  lib64/cic.a        lib64/cimwin32.a   lib64/CINTIME.a      lib64/ciodm.a      lib64/c_is2022.a      \
  lib64/c_iscii.a    lib64/clbcatex.a   lib64/clbcatq.a      lib64/clb.a        lib64/cliconfg.a      \
  lib64/clusapi.a    lib64/cmcfg32.a    lib64/CmdEvTgProv.a  lib64/cmdial32.a   lib64/cmpbk32.a       \
  lib64/cmprops.a    lib64/cmsetacl.a   lib64/cmutil.a       lib64/cnbjmon.a    lib64/cnetcfg.a       \
  lib64/cnvfat.a     lib64/coadmin.a    lib64/colbact.a      lib64/comaddin.a   lib64/comadmin.a      \
  lib64/comcat.a     lib64/comctl32.a   lib64/comdlg32.a     lib64/compatui.a   lib64/compstui.a      \
  lib64/comrepl.a    lib64/comres.a     lib64/comsetup.a     lib64/comsnap.a    lib64/comsvcs.a       \
  lib64/comuid.a     lib64/confmsp.a    lib64/console.a      lib64/controt.a    lib64/corpol.a        \
  lib64/credui.a     lib64/crypt32.a    lib64/cryptdlg.a     lib64/cryptdll.a   lib64/cryptext.a      \
  lib64/cryptnet.a   lib64/cryptsvc.a   lib64/cryptui.a      lib64/cscdll.a     lib64/cscui.a         \
  lib64/csrsrv.a     lib64/d3d8thk.a    lib64/d3d9.a         lib64/d3dxof.a     lib64/danim.a         \
  lib64/dataclen.a   lib64/datime.a     lib64/davclnt.a      lib64/davcprox.a   lib64/dbgeng.a        \
  lib64/dbghelp.a    lib64/dbnetlib.a   lib64/dbnmpntw.a     lib64/dciman32.a   lib64/ddraw.a         \
  lib64/ddrawex.a    lib64/deskadp.a    lib64/deskmon.a      lib64/deskperf.a   lib64/devenum.a       \
  lib64/devmgr.a     lib64/dfrgifps.a   lib64/dfrgsnap.a     lib64/dfrgui.a     lib64/dfsshlex.a      \
  lib64/dgnet.a      lib64/dhcpcsvc.a   lib64/dhcpmon.a      lib64/dhcpsapi.a   lib64/diactfrm.a      \
  lib64/digest.a     lib64/dimap.a      lib64/dimsntfy.a     lib64/dimsroam.a   lib64/directdb.a      \
  lib64/diskcopy.a   lib64/dispex.a     lib64/dmconfig.a     lib64/dmdlgs.a     lib64/dmdskmgr.a      \
  lib64/dmintf.a     lib64/dmivcitf.a   lib64/dmocx.a        lib64/dmserver.a   lib64/dmutil.a        \
  lib64/dmvdsitf.a   lib64/dnsapi.a     lib64/dnsrslvr.a     lib64/docprop2.a   lib64/docprop.a       \
  lib64/dpnaddr.a    lib64/dpnet.a      lib64/dpnhpast.a     lib64/dpnhupnp.a   lib64/dpnlobby.a      \
  lib64/dpvacm.a     lib64/dpvoice.a    lib64/dpvvox.a       lib64/drprov.a     lib64/ds32gt.a        \
  lib64/dsauth.a     lib64/dsdmo.a      lib64/dsdmoprp.a     lib64/dskquota.a   lib64/dskquoui.a      \
  lib64/dsound3d.a   lib64/dsound.a     lib64/dsprop.a       lib64/dsprov.a     lib64/dsquery.a       \
  lib64/dssec.a      lib64/dssenh.a     lib64/dsuiext.a      lib64/duser.a      lib64/dxdiagn.a       \
  lib64/dxtmsft.a    lib64/dxtrans.a    lib64/efsadu.a       lib64/els.a        lib64/encapi.a        \
  lib64/ersvc.a      lib64/es.a         lib64/esent.a        lib64/esentprf.a   lib64/esscli.a        \
  lib64/eventcls.a   lib64/eventlog.a   lib64/evntagnt.a     lib64/evntrprv.a   lib64/evtgprov.a      \
  lib64/exstrace.a   lib64/extmgr.a     lib64/f3ahvoas.a     lib64/fastprox.a   lib64/faultrep.a      \
  lib64/fcachdll.a   lib64/fde.a        lib64/fdeploy.a      lib64/feclient.a   lib64/filemgmt.a      \
  lib64/fldrclnr.a   lib64/fltlib.a     lib64/fmifs.a        lib64/fontext.a    lib64/fontsub.a       \
  lib64/framedyn.a   lib64/fsusd.a      lib64/ftpctrs2.a     lib64/ftpmib.a     lib64/ftpsvc2.a       \
  lib64/fwcfg.a      lib64/fxsapi.a     lib64/fxscfgwz.a     lib64/fxscom.a     lib64/fxscomex.a      \
  lib64/fxsdrv.a     lib64/fxsmon.a     lib64/fxsocm.a       lib64/fxsperf.a    lib64/fxsroute.a      \
  lib64/fxsst.a      lib64/fxst30.a     lib64/fxstiff.a      lib64/fxsui.a      lib64/fxswzrd.a       \
  lib64/gcdef.a      lib64/gdi32.a      lib64/getuname.a     lib64/glmf32.a     lib64/glu32.a         \
  lib64/gpedit.a     lib64/gpkcsp.a     lib64/gptext.a       lib64/guitrn.a     lib64/gzip.a          \
  lib64/h323msp.a    lib64/hal.a        lib64/hbaapi.a       lib64/hgfs.a       lib64/hhsetup.a       \
  lib64/hid.a        lib64/hlink.a      lib64/hmmapi.a       lib64/hnetcfg.a    lib64/hnetmon.a       \
  lib64/hnetwiz.a    lib64/hostmib.a    lib64/hotplug.a      lib64/hticons.a    lib64/htrn_jis.a      \
  lib64/httpapi.a    lib64/httpext.a    lib64/httpmib.a      lib64/httpodbc.a   lib64/htui.a          \
  lib64/hypertrm.a   lib64/iasacct.a    lib64/iasads.a       lib64/iashlpr.a    lib64/iasnap.a        \
  lib64/iaspolcy.a   lib64/iasrad.a     lib64/iassam.a       lib64/iassdo.a     lib64/iassvcs.a       \
  lib64/icaapi.a     lib64/icfgnt5.a    lib64/icm32.a        lib64/icmp.a       lib64/icmui.a         \
  lib64/icwconn.a    lib64/icwdial.a    lib64/icwdl.a        lib64/icwhelp.a    lib64/icwphbk.a       \
  lib64/icwutil.a    lib64/idq.a        lib64/ieakeng.a      lib64/ieaksie.a    lib64/iedkcs32.a      \
  lib64/ieencode.a   lib64/iepeers.a    lib64/iernonce.a     lib64/iesetup.a    lib64/ifmon.a         \
  lib64/ifsutil.a    lib64/igmpagnt.a   lib64/iisadmin.a     lib64/iiscfg.a     lib64/iisclex4.a      \
  lib64/iis.a        lib64/iisext.a     lib64/iislog.a       lib64/iismap.a     lib64/iisrstap.a      \
  lib64/iisrtl.a     lib64/iissuba.a    lib64/iisui.a        lib64/iisuiobj.a   lib64/iisutil.a       \
  lib64/iisw3adm.a   lib64/iiswmi.a     lib64/imagehlp.a     lib64/imekrcic.a   lib64/imepadsm.a      \
  lib64/imeshare.a   lib64/imgutil.a    lib64/imjp81k.a      lib64/imjpcic.a    lib64/imjpcus.a       \
  lib64/imjpdct.a    lib64/imjputyc.a   lib64/imlang.a       lib64/imm32.a      lib64/imsinsnt.a      \
  lib64/imskdic.a    lib64/imskf.a      lib64/inetcfg.a      lib64/inetcomm.a   lib64/inetmgr.a       \
  lib64/inetmib1.a   lib64/inetpp.a     lib64/inetppui.a     lib64/infoadmn.a   lib64/infocomm.a      \
  lib64/infoctrs.a   lib64/infosoft.a   lib64/initpki.a      lib64/input.a      lib64/inseng.a        \
  lib64/iphlpapi.a   lib64/ipmontr.a    lib64/ipnathlp.a     lib64/ippromon.a   lib64/iprip.a         \
  lib64/iprop.a      lib64/iprtprio.a   lib64/iprtrmgr.a     lib64/ipsecsnp.a   lib64/ipsecsvc.a      \
  lib64/ipsmsnap.a   lib64/ipv6mon.a    lib64/ipxsap.a       lib64/irclass.a    lib64/isapips.a       \
  lib64/isatq.a      lib64/iscomlog.a   lib64/isign32.a      lib64/itircl.a     lib64/itss.a          \
  lib64/ixsso.a      lib64/iyuv_32.a    lib64/jet500.a       lib64/jscript.a    lib64/jsproxy.a       \
  lib64/kbd101a.a    lib64/kbd101b.a    lib64/kbd101c.a      lib64/kbd101.a     lib64/kbd103.a        \
  lib64/kbd106.a     lib64/kbd106n.a    lib64/kbda1.a        lib64/kbda2.a      lib64/kbda3.a         \
  lib64/kbdal.a      lib64/kbdarme.a    lib64/kbdarmw.a      lib64/kbdax2.a     lib64/kbdaze.a        \
  lib64/kbdazel.a    lib64/kbdbe.a      lib64/kbdbene.a      lib64/kbdblr.a     lib64/kbdbr.a         \
  lib64/kbdbu.a      lib64/kbdca.a      lib64/kbdcan.a       lib64/kbdcr.a      lib64/kbdcz1.a        \
  lib64/kbdcz2.a     lib64/kbdcz.a      lib64/kbdda.a        lib64/kbddiv1.a    lib64/kbddiv2.a       \
  lib64/kbddv.a      lib64/kbdes.a      lib64/kbdest.a       lib64/kbdfa.a      lib64/kbdfc.a         \
  lib64/kbdfi.a      lib64/kbdfo.a      lib64/kbdfr.a        lib64/kbdgae.a     lib64/kbdgeo.a        \
  lib64/kbdgkl.a     lib64/kbdgr1.a     lib64/kbdgr.a        lib64/kbdhe220.a   lib64/kbdhe319.a      \
  lib64/kbdheb.a     lib64/kbdhe.a      lib64/kbdhela2.a     lib64/kbdhela3.a   lib64/kbdhept.a       \
  lib64/kbdhu1.a     lib64/kbdhu.a      lib64/kbdibm02.a     lib64/kbdic.a      lib64/kbdindev.a      \
  lib64/kbdinguj.a   lib64/kbdinhin.a   lib64/kbdinkan.a     lib64/kbdinmar.a   lib64/kbdinpun.a      \
  lib64/kbdintam.a   lib64/kbdintel.a   lib64/kbdir.a        lib64/kbdit142.a   lib64/kbdit.a         \
  lib64/kbdjpn.a     lib64/kbdkaz.a     lib64/kbdkor.a       lib64/kbdkyr.a     lib64/kbdla.a         \
  lib64/kbdlk41a.a   lib64/kbdlk41j.a   lib64/kbdlt1.a       lib64/kbdlt.a      lib64/kbdlv1.a        \
  lib64/kbdlv.a      lib64/kbdmac.a     lib64/kbdmon.a       lib64/kbdnec95.a   lib64/kbdnecat.a      \
  lib64/kbdnec.a     lib64/kbdnecnt.a   lib64/kbdne.a        lib64/kbdno.a      lib64/kbdpl1.a        \
  lib64/kbdpl.a      lib64/kbdpo.a      lib64/kbdro.a        lib64/kbdru1.a     lib64/kbdru.a         \
  lib64/kbdsf.a      lib64/kbdsg.a      lib64/kbdsl1.a       lib64/kbdsl.a      lib64/kbdsp.a         \
  lib64/kbdsw.a      lib64/kbdsyr1.a    lib64/kbdsyr2.a      lib64/kbdtat.a     lib64/kbdth0.a        \
  lib64/kbdth1.a     lib64/kbdth2.a     lib64/kbdth3.a       lib64/kbdtuf.a     lib64/kbdtuq.a        \
  lib64/kbduk.a      lib64/kbdur.a      lib64/kbdurdu.a      lib64/kbdusa.a     lib64/kbdus.a         \
  lib64/kbdusl.a     lib64/kbdusr.a     lib64/kbdusx.a       lib64/kbduzb.a     lib64/kbdvntc.a       \
  lib64/kbdycc.a     lib64/kbdycl.a     lib64/kd1394.a       lib64/kdcom.a      lib64/kerberos.a      \
  lib64/keymgr.a     lib64/korwbrkr.a   lib64/krnlprov.a     lib64/langwrbk.a   lib64/licdll.a        \
  lib64/licmgr10.a   lib64/licwmi.a     lib64/linkinfo.a     lib64/lmhsvc.a     lib64/lmmib2.a        \
  lib64/lmrt.a       lib64/loadperf.a   lib64/localsec.a     lib64/localspl.a   lib64/localui.a       \
  lib64/log.a        lib64/loghours.a   lib64/logscrpt.a     lib64/lonsint.a    lib64/lpdsvc.a        \
  lib64/lpk.a        lib64/lprhelp.a    lib64/lprmon.a       lib64/lprmonui.a   lib64/lsasrv.a        \
  lib64/lz32.a       lib64/mag_hook.a   lib64/mailmsg.a      lib64/mapi32.a     lib64/mapistub.a      \
  lib64/mcastmib.a   lib64/mcd32.a      lib64/mcdsrv32.a     lib64/mchgrcoi.a   lib64/mciavi32.a      \
  lib64/mcicda.a     lib64/mciole32.a   lib64/mciqtz32.a     lib64/mciseq.a     lib64/mciwave.a       \
  lib64/mdhcp.a      lib64/mdminst.a    lib64/metadata.a     lib64/mf3216.a     lib64/mfc42.a         \
  lib64/mfc42u.a     lib64/mfcsubs.a    lib64/mgmtapi.a      lib64/midimap.a    lib64/migism.a        \
  lib64/miglibnt.a   lib64/mimefilt.a   lib64/mlang.a        lib64/mll_hp.a     lib64/mll_mtf.a       \
  lib64/mll_qic.a    lib64/mmcbase.a    lib64/mmcndmgr.a     lib64/mmcshext.a   lib64/mmfutil.a       \
  lib64/mmutilse.a   lib64/mobsync.a    lib64/modemui.a      lib64/mofd.a       lib64/mprapi.a        \
  lib64/mprddm.a     lib64/mpr.a        lib64/mprdim.a       lib64/mprmsg.a     lib64/mprui.a         \
  lib64/mqad.a       lib64/mqcertui.a   lib64/mqdscli.a      lib64/mqgentr.a    lib64/mqise.a         \
  lib64/mqlogmgr.a   lib64/mqoa.a       lib64/mqperf.a       lib64/mqqm.a       lib64/mqrt.a          \
  lib64/mqrtdep.a    lib64/mqsec.a      lib64/mqsnap.a       lib64/mqtrig.a     lib64/mqupgrd.a       \
  lib64/mqutil.a     lib64/msaatext.a   lib64/msacm32.a      lib64/msadce.a     lib64/msadcf.a        \
  lib64/msadco.a     lib64/msadcs.a     lib64/msadds.a       lib64/msado15.a    lib64/msadomd.a       \
  lib64/msador15.a   lib64/msadox.a     lib64/msadrh15.a     lib64/msafd.a      lib64/msasn1.a        \
  lib64/mscandui.a   lib64/mscat32.a    lib64/mscms.a        lib64/msctf.a      lib64/msctfp.a        \
  lib64/msdadiag.a   lib64/msdaosp.a    lib64/msdaprst.a     lib64/msdaps.a     lib64/msdarem.a       \
  lib64/msdart.a     lib64/msdatl3.a    lib64/msdfmap.a      lib64/msdmo.a      lib64/msdtclog.a      \
  lib64/msdtcprx.a   lib64/msdtcstp.a   lib64/msdtctm.a      lib64/msdtcuiu.a   lib64/msftedit.a      \
  lib64/msgina.a     lib64/msgr3en.a    lib64/msgrocm.a      lib64/msgsvc.a     lib64/mshtml.a        \
  lib64/mshtmled.a   lib64/msi.a        lib64/msident.a      lib64/msieftp.a    lib64/msihnd.a        \
  lib64/msimg32.a    lib64/msimtf.a     lib64/msinfo.a       lib64/msiprov.a    lib64/msir3jp.a       \
  lib64/msisip.a     lib64/mslbui.a     lib64/msls31.a       lib64/mslwvtts.a   lib64/msmqocm.a       \
  lib64/msobcomm.a   lib64/msobdl.a     lib64/msobmain.a     lib64/msobshel.a   lib64/msobweb.a       \
  lib64/msoeacct.a   lib64/msoe.a       lib64/msoert2.a      lib64/mspatcha.a   lib64/mspmsnsv.a      \
  lib64/msports.a    lib64/msrating.a   lib64/msrle32.a      lib64/mssign32.a   lib64/mssip32.a       \
  lib64/mstask.a     lib64/mstime.a     lib64/mstlsapi.a     lib64/mstscax.a    lib64/msutb.a         \
  lib64/msv1_0.a     lib64/msvcirt.a    lib64/msvcp60.a      lib64/msvfw32.a    lib64/msvidc32.a      \
  lib64/msvidctl.a   lib64/msw3prt.a    lib64/mswsock.a      lib64/msxactps.a   lib64/msxml3.a        \
  lib64/msxs64.a     lib64/msyuv.a      lib64/mtxclu.a       lib64/mtxdm.a      lib64/mtxex.a         \
  lib64/mtxoci.a     lib64/mycomput.a   lib64/mydocs.a       lib64/narrhook.a   lib64/ncobjapi.a      \
  lib64/ncprov.a     lib64/ncxpnt.a     lib64/nddeapi.a      lib64/nddenb32.a   lib64/ndisnpp.a       \
  lib64/netapi32.a   lib64/netcfgx.a    lib64/netid.a        lib64/netlogon.a   lib64/netman.a        \
  lib64/netoc.a      lib64/netplwiz.a   lib64/netrap.a       lib64/netshell.a   lib64/netui0.a        \
  lib64/netui1.a     lib64/netui2.a     lib64/newdev.a       lib64/nextlink.a   lib64/nlhtml.a        \
  lib64/nntpadm.a    lib64/nntpapi.a    lib64/nntpsnap.a     lib64/npptools.a   lib64/nshipsec.a      \
  lib64/ntdll.a      lib64/ntdsapi.a    lib64/ntdsbcli.a     lib64/ntevt.a      lib64/ntfsdrv.a       \
  lib64/ntlanman.a   lib64/ntlanui2.a   lib64/ntlanui.a      lib64/ntlsapi.a    lib64/ntmarta.a       \
  lib64/ntmsapi.a    lib64/ntmsdba.a    lib64/ntmsevt.a      lib64/ntmsmgr.a    lib64/ntmssvc.a       \
  lib64/ntoc.a       lib64/ntprint.a    lib64/ntshrui.a      lib64/ntvdm64.a    lib64/nwprovau.a      \
  lib64/oakley.a     lib64/objsel.a     lib64/occache.a      lib64/ocgen.a      lib64/ocmanage.a      \
  lib64/ocmsn.a      lib64/odbc32.a     lib64/odbc32gt.a     lib64/odbcbcp.a    lib64/odbcconf.a      \
  lib64/odbccp32.a   lib64/odbccr32.a   lib64/odbccu32.a     lib64/odbctrac.a   lib64/oeimport.a      \
  lib64/oemiglib.a   lib64/offfilt.a    lib64/ole32.a        lib64/oleacc.a     lib64/oleaut32.a      \
  lib64/olecli32.a   lib64/olecnv32.a   lib64/oledb32.a      lib64/oledb32r.a   lib64/oledlg.a        \
  lib64/oleprn.a     lib64/olesvr32.a   lib64/opengl32.a     lib64/osuninst.a   lib64/ovprintmondll.a \
  lib64/padrs404.a   lib64/padrs411.a   lib64/padrs412.a     lib64/padrs804.a   lib64/panmap.a        \
  lib64/pautoenr.a   lib64/pchshell.a   lib64/pchsvc.a       lib64/pdh.a        lib64/perfctrs.a      \
  lib64/perfdisk.a   lib64/perfnet.a    lib64/perfos.a       lib64/perfproc.a   lib64/perfts.a        \
  lib64/photowiz.a   lib64/pid.a        lib64/pidgen.a       lib64/pintlcsa.a   lib64/pintlcsd.a      \
  lib64/pjlmon.a     lib64/pngfilt.a    lib64/policman.a     lib64/polstore.a   lib64/powrprof.a      \
  lib64/printui.a    lib64/profmap.a    lib64/provthrd.a     lib64/PS5UI.a      lib64/psapi.a         \
  lib64/psbase.a     lib64/pschdprf.a   lib64/PSCRIPT5.a     lib64/psnppagn.a   lib64/pstorec.a       \
  lib64/pstorsvc.a   lib64/qasf.a       lib64/qcap.a         lib64/qdvd.a       lib64/qdv.a           \
  lib64/qedit.a      lib64/qmgr.a       lib64/qmgrprxy.a     lib64/qosname.a    lib64/quartz.a        \
  lib64/query.a      lib64/racpldlg.a   lib64/rasadhlp.a     lib64/rasapi32.a   lib64/rasauto.a       \
  lib64/raschap.a    lib64/rasctrs.a    lib64/rasdlg.a       lib64/rasman.a     lib64/rasmans.a       \
  lib64/rasmontr.a   lib64/rasmxs.a     lib64/rasppp.a       lib64/rasrad.a     lib64/rassapi.a       \
  lib64/rasser.a     lib64/rastapi.a    lib64/rastls.a       lib64/rcbdyctl.a   lib64/rdchost.a       \
  lib64/rdpcfgex.a   lib64/rdpsnd.a     lib64/rdpwsx.a       lib64/regapi.a     lib64/regsvc.a        \
  lib64/regwizc.a    lib64/remotepg.a   lib64/rend.a         lib64/repdrvfs.a   lib64/resutils.a      \
  lib64/riched20.a   lib64/rnr20.a      lib64/routetab.a     lib64/rpcns4.a     lib64/rpcnsh.a        \
  lib64/rpcref.a     lib64/rpcrt4.a     lib64/rpcss.a        lib64/rsaenh.a     lib64/rsfsaps.a       \
  lib64/rshx32.a     lib64/rsmps.a      lib64/rtm.a          lib64/rtutils.a    lib64/rwnh.a          \
  lib64/safrcdlg.a   lib64/safrdm.a     lib64/safrslv.a      lib64/samlib.a     lib64/samsrv.a        \
  lib64/sapi.a       lib64/scarddlg.a   lib64/sccbase.a      lib64/sccsccp.a    lib64/scecli.a        \
  lib64/scesrv.a     lib64/schannel.a   lib64/schedsvc.a     lib64/sclgntfy.a   lib64/scredir.a       \
  lib64/script.a     lib64/scripto.a    lib64/scriptpw.a     lib64/scrobj.a     lib64/scrptutl.a      \
  lib64/scrrun.a     lib64/sdhcinst.a   lib64/sdpblb.a       lib64/seclogon.a   lib64/secur32.a       \
  lib64/security.a   lib64/sendcmsg.a   lib64/sendmail.a     lib64/sensapi.a    lib64/senscfg.a       \
  lib64/sens.a       lib64/seo.a        lib64/seos.a         lib64/serialui.a   lib64/servdeps.a      \
  lib64/serwvdrv.a   lib64/setupapi.a   lib64/setupqry.a     lib64/sfc.a        lib64/sfcfiles.a      \
  lib64/sfc_os.a     lib64/sfmapi.a     lib64/shdocvw.a      lib64/shfolder.a   lib64/shgina.a        \
  lib64/shimeng.a    lib64/shimgvw.a    lib64/shlwapi.a      lib64/shmedia.a    lib64/shscrap.a       \
  lib64/shsvcs.a     lib64/sigtab.a     lib64/simptcp.a      lib64/sisbkup.a    lib64/skdll.a         \
  lib64/slayerxp.a   lib64/slbcsp.a     lib64/slbiop.a       lib64/smlogcfg.a   lib64/smtpadm.a       \
  lib64/smtpapi.a    lib64/smtpcons.a   lib64/smtpctrs.a     lib64/smtpsnap.a   lib64/smtpsvc.a       \
  lib64/sniffpol.a   lib64/snmpapi.a    lib64/snmpcl.a       lib64/snmpincl.a   lib64/snmpmib.a       \
  lib64/snmpsmir.a   lib64/snmpsnap.a   lib64/snmpstup.a     lib64/snmpthrd.a   lib64/snprfdll.a      \
  lib64/softkbd.a    lib64/softkey.a    lib64/softpub.a      lib64/spcommon.a   lib64/spoolss.a       \
  lib64/sptip.a      lib64/spttseng.a   lib64/sqlsrv32.a     lib64/sqlxmlx.a    lib64/srchctls.a      \
  lib64/srchui.a     lib64/srclient.a   lib64/srrstr.a       lib64/srsvc.a      lib64/srvsvc.a        \
  lib64/ssdpapi.a    lib64/ssdpsrv.a    lib64/ssinc.a        lib64/sstub.a      lib64/staxmem.a       \
  lib64/stclient.a   lib64/stdprov.a    lib64/sti_ci.a       lib64/sti.a        lib64/stobject.a      \
  lib64/storprop.a   lib64/streamci.a   lib64/strmfilt.a     lib64/svcext.a     lib64/svcpack.a       \
  lib64/swprv.a      lib64/sxs.a        lib64/synceng.a      lib64/syncui.a     lib64/sysinv.a        \
  lib64/sysmod.a     lib64/syssetup.a   lib64/t2embed.a      lib64/tapi32.a     lib64/tapi3.a         \
  lib64/tapiperf.a   lib64/tapisrv.a    lib64/tcpmib.a       lib64/tcpmon.a     lib64/tcpmonui.a      \
  lib64/termmgr.a    lib64/termsrv.a    lib64/thawbrkr.a     lib64/themeui.a    lib64/tlntsvrp.a      \
  lib64/traffic.a    lib64/trialoc.a    lib64/trkwks.a       lib64/tsappcmp.a   lib64/tsbyuv.a        \
  lib64/tscfgwmi.a   lib64/tsd32.a      lib64/tshoot.a       lib64/tsoc.a       lib64/twext.a         \
  lib64/txflog.a     lib64/udhisapi.a   lib64/ufat.a         lib64/uihelper.a   lib64/ulib.a          \
  lib64/umandlg.a    lib64/umdmxfrm.a   lib64/umpnpmgr.a     lib64/UNIDRV.a     lib64/UNIDRVUI.a      \
  lib64/uniime.a     lib64/unimdmat.a   lib64/uniplat.a      lib64/untfs.a      lib64/upnp.a          \
  lib64/upnphost.a   lib64/upnpui.a     lib64/ureg.a         lib64/urlauth.a    lib64/url.a           \
  lib64/urlmon.a     lib64/usbmon.a     lib64/user32.a       lib64/userenv.a    lib64/usp10.a         \
  lib64/utildll.a    lib64/uxtheme.a    lib64/vbscript.a     lib64/vdsbas.a     lib64/vdsdyndr.a      \
  lib64/vds_ps.a     lib64/vdsutil.a    lib64/vdswmi.a       lib64/verifier.a   lib64/version.a       \
  lib64/vgx.a        lib64/viewprov.a   lib64/vmx_mode.a     lib64/vssapi.a     lib64/vss_ps.a        \
  lib64/vsswmi.a     lib64/w32time.a    lib64/w32topl.a      lib64/w3cache.a    lib64/w3comlog.a      \
  lib64/w3core.a     lib64/w3ctrlps.a   lib64/w3ctrs.a       lib64/w3dt.a       lib64/w3ext.a         \
  lib64/w3isapi.a    lib64/w3ssl.a      lib64/w3tp.a         lib64/waaaamon.a   lib64/wab32.a         \
  lib64/wabfind.a    lib64/wabimp.a     lib64/wAcLayers.a    lib64/wacledit.a   lib64/wAcLua.a        \
  lib64/waclui.a     lib64/wAcSpecfc.a  lib64/wactiveds.a    lib64/wactxprxy.a  lib64/wacwow64.a      \
  lib64/wAcXtrnal.a  lib64/wadmparse.a  lib64/wadmwprx.a     lib64/wadptif.a    lib64/wADROT.a        \
  lib64/wadsiis.a    lib64/wadsldpc.a   lib64/wadsldp.a      lib64/wadsmsext.a  lib64/wadsnt.a        \
  lib64/wadvapi32.a  lib64/wadvpack.a   lib64/waelupsvc.a    lib64/wagentanm.a  lib64/wagentctl.a     \
  lib64/wagentdp2.a  lib64/wagentdpv.a  lib64/wagentmpx.a    lib64/wagentpsh.a  lib64/wagentsr.a      \
  lib64/wagtintl.a   lib64/wair300pp.a  lib64/wam.a          lib64/wamps.a      lib64/wamreg.a        \
  lib64/wamregps.a   lib64/wamstream.a  lib64/wapcups.a      lib64/wapphelp.a   lib64/wappmgmts.a     \
  lib64/wappmgr.a    lib64/wasp.a       lib64/waspperf.a     lib64/wasycfilt.a  lib64/watkctrs.a      \
  lib64/watl.a       lib64/watmlib.a    lib64/watmpvcno.a    lib64/waudiodev.a  lib64/waudiosrv.a     \
  lib64/wauthz.a     lib64/wautodisc.a  lib64/wavemsp.a      lib64/wavicap32.a  lib64/wavifil32.a     \
  lib64/wavmcoxp.a   lib64/wazroles.a   lib64/wazroleui.a    lib64/wbatmeter.a  lib64/wbatt.a         \
  lib64/wbckg.a      lib64/wbckgres.a   lib64/wbemcntl.a     lib64/wbemcomn.a   lib64/wbemcons.a      \
  lib64/wbemcore.a   lib64/wbemdisp.a   lib64/wbemess.a      lib64/wbemperf.a   lib64/wbemprox.a      \
  lib64/wbemsvc.a    lib64/wbemupgd.a   lib64/wbidispl.a     lib64/wbitsprx2.a  lib64/wbitsprx3.a     \
  lib64/wblackbox.a  lib64/wbrowscap.a  lib64/wbrowser.a     lib64/wbrowseui.a  lib64/wbrowsewm.a     \
  lib64/wcabinet.a   lib64/wcabview.a   lib64/wcamocx.a      lib64/wcards.a     lib64/wcatsrv.a       \
  lib64/wcatsrvps.a  lib64/wcatsrvut.a  lib64/wccfgnt.a      lib64/wcdfview.a   lib64/wcdosys.a       \
  lib64/wcertcli.a   lib64/wcertmgr.a   lib64/wcertobj.a     lib64/wc_eucdb.a   lib64/wcewmdm.a       \
  lib64/wcfgmgr32.a  lib64/wc_g18030.a  lib64/wchkr.a        lib64/wchsbrkr.a   lib64/wchtbrkr.a      \
  lib64/wCHTSKDIC.a  lib64/wCHTSKF.a    lib64/wciadmin.a     lib64/wcic.a       lib64/wCINTIME.a      \
  lib64/wciodm.a     lib64/wc_is2022.a  lib64/wc_iscii.a     lib64/wclbcatex.a  lib64/wclbcatq.a      \
  lib64/wclb.a       lib64/wclusapi.a   lib64/wcmcfg32.a     lib64/wcmdial32.a  lib64/wCmnclim.a      \
  lib64/wcmpbk32.a   lib64/wcmsetACL.a  lib64/wcmutil.a      lib64/wcnbjmon.a   lib64/wcnetcfg.a      \
  lib64/wcnvfat.a    lib64/wcolbact.a   lib64/wcomaddin.a    lib64/wcomadmin.a  lib64/wcomcat.a       \
  lib64/wcomctl32.a  lib64/wcomdlg32.a  lib64/wcompatUI.a    lib64/wcompstui.a  lib64/wcomres.a       \
  lib64/wcomsnap.a   lib64/wcomsvcs.a   lib64/wcomuid.a      lib64/wconfmsp.a   lib64/wconsole.a      \
  lib64/wContRot.a   lib64/wcorpol.a    lib64/wcredui.a      lib64/wcrtdll.a    lib64/wcrypt32.a      \
  lib64/wcryptdlg.a  lib64/wcryptdll.a  lib64/wcryptext.a    lib64/wcryptnet.a  lib64/wcryptsvc.a     \
  lib64/wcryptui.a   lib64/wcsapi3t1.a  lib64/wcscdll.a      lib64/wcscui.a     lib64/wc_snadb.a      \
  lib64/wcsseqchk.a  lib64/wctl3d32.a   lib64/wcustsat.a     lib64/wcyycoins.a  lib64/wcyyports.a     \
  lib64/wcyzcoins.a  lib64/wcyzports.a  lib64/wd3d8.a        lib64/wd3d8thk.a   lib64/wd3d9.a         \
  lib64/wd3dim700.a  lib64/wd3dim.a     lib64/wd3dpmesh.a    lib64/wd3dramp.a   lib64/wd3drm.a        \
  lib64/wd3dxof.a    lib64/wdanim.a     lib64/wdao360.a      lib64/wdataclen.a  lib64/wdatime.a       \
  lib64/wdavclnt.a   lib64/wdavcprox.a  lib64/wdbgeng.a      lib64/wdbghelp.a   lib64/wdbnetlib.a     \
  lib64/wdciman32.a  lib64/wddraw.a     lib64/wddrawex.a     lib64/wdeskadp.a   lib64/wdeskmon.a      \
  lib64/wdeskperf.a  lib64/wdevenum.a   lib64/wdfsshlex.a    lib64/wdgconfig.a  lib64/wdgnet.a        \
  lib64/wdgsetup.a   lib64/wdhcpcsvc.a  lib64/wdhcpmon.a     lib64/wdhcpsapi.a  lib64/wdiactfrm.a     \
  lib64/wdigest.a    lib64/wdigiinf.a   lib64/wdigirlpt.a    lib64/wdimap.a     lib64/wdimsntfy.a     \
  lib64/wdimsroam.a  lib64/wdinput8.a   lib64/wdinput.a      lib64/wdirectdb.a  lib64/wdiskcopy.a     \
  lib64/wdispex.a    lib64/wdisrvci.a   lib64/wdmaud.a       lib64/wdmband.a    lib64/wdmcompos.a     \
  lib64/wdmime.a     lib64/wdmloader.a  lib64/wdmocx.a       lib64/wdmscript.a  lib64/wdmstyle.a      \
  lib64/wdmsynth.a   lib64/wdmusic.a    lib64/wdnsapi.a      lib64/wdnsrslvr.a  lib64/wdocprop2.a     \
  lib64/wdocprop.a   lib64/wdplay.a     lib64/wdplayx.a      lib64/wdpmodemx.a  lib64/wdpnaddr.a      \
  lib64/wdpnet.a     lib64/wdpnhpast.a  lib64/wdpnhupnp.a    lib64/wdpnlobby.a  lib64/wdpvacm.a       \
  lib64/wdpvoice.a   lib64/wdpvvox.a    lib64/wdpwsockx.a    lib64/wdrmclien.a  lib64/wdrmstor.a      \
  lib64/wdrmv2clt.a  lib64/wdrprov.a    lib64/wds32gt.a      lib64/wdsauth.a    lib64/wdsdmo.a        \
  lib64/wdsdmoprp.a  lib64/wdskquota.a  lib64/wdskquoui.a    lib64/wdsound3d.a  lib64/wdsound.a       \
  lib64/wdsprop.a    lib64/wdsquery.a   lib64/wdssec.a       lib64/wdssenh.a    lib64/wdsuiext.a      \
  lib64/wdswave.a    lib64/wduser.a     lib64/wdx7vb.a       lib64/wdx8vb.a     lib64/wdxdiagn.a      \
  lib64/wdxmasf.a    lib64/wdxtmsft.a   lib64/wdxtrans.a     lib64/webcheck.a   lib64/webclnt.a       \
  lib64/webhits.a    lib64/webvw.a      lib64/wedb500.a      lib64/wefsadu.a    lib64/wels.a          \
  lib64/wencapi.a    lib64/wencdec.a    lib64/wes.a          lib64/wesent97.a   lib64/wesent.a        \
  lib64/wesentprf.a  lib64/wesscli.a    lib64/wevntrprv.a    lib64/wevtgprov.a  lib64/wexpsrv.a       \
  lib64/wexstrace.a  lib64/wextmgr.a    lib64/wf3ahvoas.a    lib64/wfastprox.a  lib64/wfaultrep.a     \
  lib64/wfde.a       lib64/wfdeploy.a   lib64/wfeclient.a    lib64/wfilemgmt.a  lib64/wfldrclnr.a     \
  lib64/wfltlib.a    lib64/wfmifs.a     lib64/wfontext.a     lib64/wfontsub.a   lib64/wframedyn.a     \
  lib64/wfsusd.a     lib64/wftlx041e.a  lib64/wftpctrs2.a    lib64/wftsrch.a    lib64/wfwcfg.a        \
  lib64/wfxsapi.a    lib64/wfxscom.a    lib64/wfxscomex.a    lib64/wfxsext32.a  lib64/wfxsperf.a      \
  lib64/wfxsxp32.a   lib64/wgcdef.a     lib64/wgdi32.a       lib64/wgetuname.a  lib64/wglmf32.a       \
  lib64/wglu32.a     lib64/wgpedit.a    lib64/wgpkcsp.a      lib64/wgptext.a    lib64/wguitrna.a      \
  lib64/wguitrn.a    lib64/wgzip.a      lib64/wh323msp.a     lib64/whbaapi.a    lib64/whccoin.a       \
  lib64/whhsetup.a   lib64/whid.a       lib64/whidserv.a     lib64/whlink.a     lib64/wHMMAPI.a       \
  lib64/whnetcfg.a   lib64/whnetmon.a   lib64/whrtz.a        lib64/whsf_inst.a  lib64/whttpapi.a      \
  lib64/whttpext.a   lib64/whttpmib.a   lib64/whttpodbc.a    lib64/whtui.a      lib64/wiadefui.a      \
  lib64/wiadss.a     lib64/wiarpc.a     lib64/wiasacct.a     lib64/wiasads.a    lib64/wiascr.a        \
  lib64/wiaservc.a   lib64/wiashext.a   lib64/wiashlpr.a     lib64/wiasnap.a    lib64/wiaspolcy.a     \
  lib64/wiasrad.a    lib64/wiasrecst.a  lib64/wiassam.a      lib64/wiassdo.a    lib64/wiassvcs.a      \
  lib64/wiavideo.a   lib64/wiavusd.a    lib64/wicfgnt5.a     lib64/wicm32.a     lib64/wicmp.a         \
  lib64/wicmui.a     lib64/wiconf32.a   lib64/wicwconn.a     lib64/wicwdial.a   lib64/wicwdl.a        \
  lib64/wicwhelp.a   lib64/wicwphbk.a   lib64/wicwutil.a     lib64/widq.a       lib64/wieakeng.a      \
  lib64/wieaksie.a   lib64/wiedkcs32.a  lib64/wieencode.a    lib64/wiepeers.a   lib64/wiernonce.a     \
  lib64/wiesetup.a   lib64/wifmon.a     lib64/wifsutil.a     lib64/wigmpagnt.a  lib64/wiisext.a       \
  lib64/wiislog.a    lib64/wiismap.a    lib64/wiispwchg.a    lib64/wiisrstap.a  lib64/wiisrtl.a       \
  lib64/wiisui.a     lib64/wiisuiobj.a  lib64/wiisutil.a     lib64/wiisw3adm.a  lib64/wimagehlp.a     \
  lib64/wimekrcic.a  lib64/wimepadsm.a  lib64/wimeshare.a    lib64/wimgutil.a   lib64/wimjp81k.a      \
  lib64/wimjpcic.a   lib64/wimjpcus.a   lib64/wimjpdct.a     lib64/wimjputyc.a  lib64/wimlang.a       \
  lib64/wimm32.a     lib64/wimskdic.a   lib64/wimskf.a       lib64/win32spl.a   lib64/winetcfg.a      \
  lib64/winetcomm.a  lib64/winetmgr.a   lib64/winetmib1.a    lib64/winetpp.a    lib64/winetppui.a     \
  lib64/winfax.a     lib64/winfoadmn.a  lib64/winfoctrs.a    lib64/winfosoft.a  lib64/wininet.a       \
  lib64/winipsec.a   lib64/winitpki.a   lib64/winmm.a        lib64/winntbbu.a   lib64/winput.a        \
  lib64/winrnr.a     lib64/winscard.a   lib64/winseng.a      lib64/winspool.a   lib64/winsrv.a        \
  lib64/winsta.a     lib64/wintrust.a   lib64/wiphlpapi.a    lib64/wipmontr.a   lib64/wipnathlp.a     \
  lib64/wippromon.a  lib64/wiprip.a     lib64/wiprop.a       lib64/wiprtprio.a  lib64/wiprtrmgr.a     \
  lib64/wipsecsnp.a  lib64/wipsecsvc.a  lib64/wipsmsnap.a    lib64/wipv6mon.a   lib64/wipxsap.a       \
  lib64/wir41_qc.a   lib64/wir41_qcx.a  lib64/wir50_32.a     lib64/wir50_qc.a   lib64/wir50_qcx.a     \
  lib64/wisapips.a   lib64/wiscomlog.a  lib64/wisign32.a     lib64/witircl.a    lib64/witss.a         \
  lib64/wixsso.a     lib64/wiyuv_32.a   lib64/wjet500.a      lib64/wjobexec.a   lib64/wjscript.a      \
  lib64/wjsproxy.a   lib64/wkbd101a.a   lib64/wkbd101b.a     lib64/wkbd101c.a   lib64/wkbd101.a       \
  lib64/wkbd103.a    lib64/wkbd106.a    lib64/wkbd106n.a     lib64/wkbda1.a     lib64/wkbda2.a        \
  lib64/wkbda3.a     lib64/wKBDAL.a     lib64/wkbdarme.a     lib64/wkbdarmw.a   lib64/wkbdax2.a       \
  lib64/wkbdaze.a    lib64/wkbdazel.a   lib64/wkbdbe.a       lib64/wkbdbene.a   lib64/wkbdblr.a       \
  lib64/wkbdbr.a     lib64/wkbdbu.a     lib64/wkbdca.a       lib64/wkbdcan.a    lib64/wkbdcr.a        \
  lib64/wkbdcz1.a    lib64/wkbdcz2.a    lib64/wkbdcz.a       lib64/wkbdda.a     lib64/wkbddiv1.a      \
  lib64/wkbddiv2.a   lib64/wkbddv.a     lib64/wkbdes.a       lib64/wkbdest.a    lib64/wkbdfa.a        \
  lib64/wkbdfc.a     lib64/wkbdfi.a     lib64/wkbdfo.a       lib64/wkbdfr.a     lib64/wkbdgae.a       \
  lib64/wkbdgeo.a    lib64/wkbdgkl.a    lib64/wkbdgr1.a      lib64/wkbdgr.a     lib64/wkbdhe220.a     \
  lib64/wkbdhe319.a  lib64/wkbdheb.a    lib64/wkbdhe.a       lib64/wkbdhela2.a  lib64/wkbdhela3.a     \
  lib64/wkbdhept.a   lib64/wkbdhu1.a    lib64/wkbdhu.a       lib64/wkbdibm02.a  lib64/wkbdic.a        \
  lib64/wkbdindev.a  lib64/wkbdinguj.a  lib64/wkbdinhin.a    lib64/wkbdinkan.a  lib64/wkbdinmar.a     \
  lib64/wkbdinpun.a  lib64/wkbdintam.a  lib64/wkbdintel.a    lib64/wkbdir.a     lib64/wkbdit142.a     \
  lib64/wkbdit.a     lib64/wkbdjpn.a    lib64/wkbdkaz.a      lib64/wkbdkor.a    lib64/wkbdkyr.a       \
  lib64/wkbdla.a     lib64/wkbdlk41a.a  lib64/wkbdlk41j.a    lib64/wkbdlt1.a    lib64/wkbdlt.a        \
  lib64/wkbdlv1.a    lib64/wkbdlv.a     lib64/wkbdmac.a      lib64/wkbdmon.a    lib64/wkbdnec95.a     \
  lib64/wkbdnecAT.a  lib64/wkbdnec.a    lib64/wkbdnecNT.a    lib64/wkbdne.a     lib64/wkbdno.a        \
  lib64/wkbdpl1.a    lib64/wkbdpl.a     lib64/wkbdpo.a       lib64/wkbdro.a     lib64/wkbdru1.a       \
  lib64/wkbdru.a     lib64/wkbdsf.a     lib64/wkbdsg.a       lib64/wkbdsl1.a    lib64/wkbdsl.a        \
  lib64/wkbdsp.a     lib64/wkbdsw.a     lib64/wkbdsyr1.a     lib64/wkbdsyr2.a   lib64/wkbdtat.a       \
  lib64/wkbdth0.a    lib64/wkbdth1.a    lib64/wkbdth2.a      lib64/wkbdth3.a    lib64/wkbdtuf.a       \
  lib64/wkbdtuq.a    lib64/wkbduk.a     lib64/wkbdur.a       lib64/wkbdurdu.a   lib64/wkbdusa.a       \
  lib64/wkbdus.a     lib64/wkbdusl.a    lib64/wkbdusr.a      lib64/wkbdusx.a    lib64/wkbduzb.a       \
  lib64/wkbdvntc.a   lib64/wkbdycc.a    lib64/wkbdycl.a      lib64/wkerberos.a  lib64/wkernel32.a     \
  lib64/wkeymgr.a    lib64/wkorwbrkr.a  lib64/wkssvc.a       lib64/wksuser.a    lib64/wlangwrbk.a     \
  lib64/wlanmon.a    lib64/wlaprxy.a    lib64/wldap32.a      lib64/wlicmgr10.a  lib64/wlinkinfo.a     \
  lib64/wlmhsvc.a    lib64/wlmmib2.a    lib64/wlmrt.a        lib64/wlnotify.a   lib64/wloadperf.a     \
  lib64/wlocalsec.a  lib64/wlocalui.a   lib64/wlog.a         lib64/wloghours.a  lib64/wlogscrpt.a     \
  lib64/wlonsint.a   lib64/wlpdsvc.a    lib64/wlpk.a         lib64/wlprhelp.a   lib64/wlprmon.a       \
  lib64/wlprmonui.a  lib64/wlsnp.a      lib64/wlstore.a      lib64/wlz32.a      lib64/wmag_hook.a     \
  lib64/wmcastmib.a  lib64/wmcd32.a     lib64/wmchgrcoi.a    lib64/wmciavi32.a  lib64/wmcicda.a       \
  lib64/wmciole32.a  lib64/wmciqtz32.a  lib64/wmciseq.a      lib64/wmciwave.a   lib64/wmdhcp.a        \
  lib64/wmdminst.a   lib64/wmf3216.a    lib64/wmfc40.a       lib64/wmfc40u.a    lib64/wmfc42.a        \
  lib64/wmfc42u.a    lib64/wmfcsubs.a   lib64/wmgmtapi.a     lib64/wmi2xml.a    lib64/wmiaprpl.a      \
  lib64/wmicookr.a   lib64/wmidcprv.a   lib64/wmi.a          lib64/wmidimap.a   lib64/wmigisma.a      \
  lib64/wmigism.a    lib64/wmiglibnt.a  lib64/wmimefilt.a    lib64/wmipcima.a   lib64/wmipdskq.a      \
  lib64/wmipicmp.a   lib64/wmipiprt.a   lib64/wmipjobj.a     lib64/wmiprop.a    lib64/wmiprov.a       \
  lib64/wmiprvsd.a   lib64/wmipsess.a   lib64/wmiscmgr.a     lib64/wmisvc.a     lib64/wmitimep.a      \
  lib64/wmiutils.a   lib64/wmlang.a     lib64/wmll_hp.a      lib64/wmll_mtf.a   lib64/wmll_qic.a      \
  lib64/wmmcbase.a   lib64/wmmcndmgr.a  lib64/wmmcshext.a    lib64/wmmfutil.a   lib64/wmmutilse.a     \
  lib64/wmobsync.a   lib64/wmodemui.a   lib64/wmofd.a        lib64/wmp43dmod.a  lib64/wmp4sdmod.a     \
  lib64/wmpg4dmod.a  lib64/wmprapi.a    lib64/wmprddm.a      lib64/wmpr.a       lib64/wmprdim.a       \
  lib64/wmprmsg.a    lib64/wmprui.a     lib64/wmpshell.a     lib64/wmpvis.a     lib64/wmqad.a         \
  lib64/wmqdscli.a   lib64/wmqoa.a      lib64/wmqperf.a      lib64/wmqrt.a      lib64/wmqsec.a        \
  lib64/wmqutil.a    lib64/wmsaatext.a  lib64/wmsacm32.a     lib64/wmsadce.a    lib64/wmsadcf.a       \
  lib64/wmsadco.a    lib64/wmsadcs.a    lib64/wmsadds.a      lib64/wmsado15.a   lib64/wmsadomd.a      \
  lib64/wmsador15.a  lib64/wmsadox.a    lib64/wmsadrh15.a    lib64/wmsafd.a     lib64/wmsapsspc.a     \
  lib64/wmsasn1.a    lib64/wmscandui.a  lib64/wmscat32.a     lib64/wmscms.a     lib64/wmscpxl32.a     \
  lib64/wMSCTF.a     lib64/wMSCTFP.a    lib64/wmsdadc.a      lib64/wmsdadiag.a  lib64/wmsdaenum.a     \
  lib64/wmsdaer.a    lib64/wmsdaora.a   lib64/wmsdaosp.a     lib64/wmsdaprst.a  lib64/wmsdaps.a       \
  lib64/wmsdarem.a   lib64/wmsdart.a    lib64/wmsdasc.a      lib64/wmsdasql.a   lib64/wmsdatl3.a      \
  lib64/wmsdatt.a    lib64/wmsdaurl.a   lib64/wmsdfmap.a     lib64/wmsdmo.a     lib64/wmsdtcprx.a     \
  lib64/wmsdtcuiu.a  lib64/wmsexch40.a  lib64/wmsexcl40.a    lib64/wmsftedit.a  lib64/wmsgina.a       \
  lib64/wmsgr3en.a   lib64/wmshtml.a    lib64/wmshtmled.a    lib64/wmsi.a       lib64/wmsident.a      \
  lib64/wmsieftp.a   lib64/wmsihnd.a    lib64/wmsimg32.a     lib64/wMSIMTF.a    lib64/wmsir3jp.a      \
  lib64/wmsisip.a    lib64/wmsjet40.a   lib64/wmsjetol1.a    lib64/wmsjint40.a  lib64/wmsjro.a        \
  lib64/wmsjter40.a  lib64/wmsjtes40.a  lib64/wmslbui.a      lib64/wmsls31.a    lib64/wmsltus40.a     \
  lib64/wmslwvtts.a  lib64/wmsnetobj.a  lib64/wmsnsspc.a     lib64/wmsoeacct.a  lib64/wmsoe.a         \
  lib64/wmsoert2.a   lib64/wmsorcl32.a  lib64/wmspatcha.a    lib64/wmspbde40.a  lib64/wmspmsnsv.a     \
  lib64/wmspmsp.a    lib64/wmsports.a   lib64/wmsr2c.a       lib64/wmsrating.a  lib64/wmsrd2x40.a     \
  lib64/wmsrd3x40.a  lib64/wmsrle32.a   lib64/wmssap.a       lib64/wmsscp.a     lib64/wmssign32.a     \
  lib64/wmssip32.a   lib64/wmstask.a    lib64/wmstext40.a    lib64/wmstime.a    lib64/wmstlsapi.a     \
  lib64/wmstscax.a   lib64/wmsutb.a     lib64/wmsv1_0.a      lib64/wmsvcirt.a   lib64/wmsvcp50.a      \
  lib64/wmsvcp60.a   lib64/wmsvcrt20.a  lib64/wmsvcrt40.a    lib64/wmsvcrt.a    lib64/wmsvfw32.a      \
  lib64/wmsvidc32.a  lib64/wmsvidctl.a  lib64/wmsw3prt.a     lib64/wmswebdvd.a  lib64/wmswmdm.a       \
  lib64/wmswsock.a   lib64/wmsxactps.a  lib64/wmsxbde40.a    lib64/wmsxml2.a    lib64/wmsxml3.a       \
  lib64/wmsxml.a     lib64/wmsyuv.a     lib64/wmtxclu.a      lib64/wmtxdm.a     lib64/wmtxex.a        \
  lib64/wmtxlegih.a  lib64/wmtxoci.a    lib64/wmxicfg.a      lib64/wmxport.a    lib64/wmycomput.a     \
  lib64/wmydocs.a    lib64/wnarrhook.a  lib64/wncobjapi.a    lib64/wnddeapi.a   lib64/wnddenb32.a     \
  lib64/wnetapi32.a  lib64/wnetcfgx.a   lib64/wnetid.a       lib64/wnetlogon.a  lib64/wnetman.a       \
  lib64/wnetplwiz.a  lib64/wnetrap.a    lib64/wnetshell.a    lib64/wnetui0.a    lib64/wnetui1.a       \
  lib64/wnetui2.a    lib64/wnewdev.a    lib64/wNEXTLINK.a    lib64/wnlhtml.a    lib64/wnntpadm.a      \
  lib64/wnntpapi.a   lib64/wnntpsnap.a  lib64/wnpdsplay.a    lib64/wnpptools.a  lib64/wnshipsec.a     \
  lib64/wntdll.a     lib64/wntdsapi.a   lib64/wntdsbcli.a    lib64/wntlanman.a  lib64/wntlanui2.a     \
  lib64/wntlanui.a   lib64/wntlsapi.a   lib64/wntmarta.a     lib64/wntmsapi.a   lib64/wntprint.a      \
  lib64/wntshrui.a   lib64/wntvdm64.a   lib64/woakley.a      lib64/wobjsel.a    lib64/woccache.a      \
  lib64/wocmanage.a  lib64/wodbc32.a    lib64/wodbc32gt.a    lib64/wodbcconf.a  lib64/wodbccp32.a     \
  lib64/wodbccr32.a  lib64/wodbccu32.a  lib64/wodbcji32.a    lib64/wodbcjt32.a  lib64/wodbctrac.a     \
  lib64/woddbse32.a  lib64/wodexl32.a   lib64/wodfox32.a     lib64/wodpdx32.a   lib64/wodtext32.a     \
  lib64/woeimport.a  lib64/woemiglib.a  lib64/wofffilt.a     lib64/wole32.a     lib64/woleacc.a       \
  lib64/woleaut32.a  lib64/wolecli32.a  lib64/wolecnv32.a    lib64/woledb32.a   lib64/woledb32r.a     \
  lib64/woledlg.a    lib64/woleprn.a    lib64/wolepro32.a    lib64/wolesvr32.a  lib64/wolethk32.a     \
  lib64/wopengl32.a  lib64/wosuninst.a  lib64/wow64cpu.a     lib64/wow64.a      lib64/wow64mib.a      \
  lib64/wow64win.a   lib64/wPADRS404.a  lib64/wpadrs411.a    lib64/wpadrs412.a  lib64/wpadrs804.a     \
  lib64/wpanmap.a    lib64/wpautoenr.a  lib64/wpd_ci.a       lib64/wpdh.a       lib64/wperfctrs.a     \
  lib64/wperfdisk.a  lib64/wperfnet.a   lib64/wperfos.a      lib64/wperfproc.a  lib64/wperfts.a       \
  lib64/wphotowiz.a  lib64/wpid.a       lib64/wpidgen.a      lib64/wPINTLCSA.a  lib64/wPINTLCSD.a     \
  lib64/wpjlmon.a    lib64/wpngfilt.a   lib64/wpolstore.a    lib64/wpowrprof.a  lib64/wprintui.a      \
  lib64/wprofmap.a   lib64/wprovthrd.a  lib64/wpsapi.a       lib64/wpsbase.a    lib64/wpschdprf.a     \
  lib64/wpsnppagn.a  lib64/wpstorec.a   lib64/wpstorsvc.a    lib64/wqasf.a      lib64/wqcap.a         \
  lib64/wqdvd.a      lib64/wqdv.a       lib64/wqedit.a       lib64/wqmgrprxy.a  lib64/wqosname.a      \
  lib64/wquartz.a    lib64/wquery.a     lib64/wrasadhlp.a    lib64/wrasapi32.a  lib64/wrasauto.a      \
  lib64/wraschap.a   lib64/wrasctrs.a   lib64/wrasdlg.a      lib64/wrasman.a    lib64/wrasmans.a      \
  lib64/wrasmontr.a  lib64/wrasmxs.a    lib64/wrasppp.a      lib64/wrasrad.a    lib64/wrassapi.a      \
  lib64/wrasser.a    lib64/wrastapi.a   lib64/wrastls.a      lib64/wrdpsnd.a    lib64/wregapi.a       \
  lib64/wregsvc.a    lib64/wregwizc.a   lib64/wrend.a        lib64/wresutils.a  lib64/wriched20.a     \
  lib64/wrnr20.a     lib64/wroutetab.a  lib64/wrpcns4.a      lib64/wrpcnsh.a    lib64/wrpcref.a       \
  lib64/wrpcrt4.a    lib64/wrsaenh.a    lib64/wrshx32.a      lib64/wrtm.a       lib64/wrtutils.a      \
  lib64/wrvse.a      lib64/wrwnh.a      lib64/ws2help.a      lib64/wsamlib.a    lib64/wsapi.a         \
  lib64/wsbe.a       lib64/wsbeio.a     lib64/wscarddlg.a    lib64/wsccbase.a   lib64/wsccsccp.a      \
  lib64/wscecli.a    lib64/wschannel.a  lib64/wschedsvc.a    lib64/wsclgntfy.a  lib64/wscredir.a      \
  lib64/wscripta.a   lib64/wscript.a    lib64/wscripto.a     lib64/wscriptpw.a  lib64/wscrobj.a       \
  lib64/wscrptutl.a  lib64/wscrrun.a    lib64/wscsvc.a       lib64/wsdpblb.a    lib64/wsecedit.a      \
  lib64/wseclogon.a  lib64/wsecur32.a   lib64/wsecurity.a    lib64/wsendcmsg.a  lib64/wsendmail.a     \
  lib64/wsensapi.a   lib64/wsenscfg.a   lib64/wsens.a        lib64/wseo.a       lib64/wserialui.a     \
  lib64/wservdeps.a  lib64/wserwvdrv.a  lib64/wsetupapi.a    lib64/wsfc.a       lib64/wsfcfiles.a     \
  lib64/wsfc_os.a    lib64/wsfmapi.a    lib64/wshatm.a       lib64/wshbth.a     lib64/wshcon.a        \
  lib64/wwdmaud.a    lib64/wwinspool.a  lib64/zoneoc.a 

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

