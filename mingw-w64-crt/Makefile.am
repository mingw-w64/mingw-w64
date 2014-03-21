# INCLUDES = -I$(top_srcdir) -I$(includedir)
# Done: lib_LIBRARIES = libm.a libmingw32.a libmoldname.a libmingwex.a libcrtdll.a libmsvcrt.a libmsvcr80.a
# Done: Turn _libm_dummy.c into a BUILT_SOURCES thing
# Done: 32-bit runtime compatibility
# Done: fix make dist
# TODO: Use $(TAR) instead of tar?
# TODO: Find a better way to handle dxerr.c -- make it dxerr.h and add to sources list?
#

#Use AM_MAINTAINER_MODE in configure.ac to disable autoreconf

#AUTOMAKE_OPTIONS = color-tests

if WITHSYSROOT
  sysincludes=-I@TARGET_SYSTEM_ROOT@/include
  withsys=--with-sysroot=@TARGET_SYSTEM_ROOT@
else
  sysincludes=
  withsys=
endif

AM_CPPFLAGS=-D_CRTBLD $(sysincludes)
AM_CFLAGS=-pipe -std=gnu99 -D_WIN32_WINNT=0x0f00 @ADD_C_CXX_WARNING_FLAGS@ @ADD_C_ONLY_WARNING_FLAGS@
AM_CXXFLAGS=@ADD_C_CXX_WARNING_FLAGS@ @ADD_CXX_ONLY_WARNING_FLAGS@
AM_DLLTOOLFLAGS=-k --as=$(AS) --output-lib $@
if DELAY_IMPORT_LIBS
  AM_DLLTOOLFLAGS += --output-delaylib $@.delayimp.a
endif
CPPFLAGS32=-m32
CPPFLAGS64=-m64
DLLTOOLFLAGS32=--as-flags=--32 -m i386
DLLTOOLFLAGS64=--as-flags=--64 -m i386:x86-64
DTDEF32=$(DLLTOOL) $(DLLTOOLFLAGS32) $(AM_DLLTOOLFLAGS) --input-def
DTDEF64=$(DLLTOOL) $(DLLTOOLFLAGS64) $(AM_DLLTOOLFLAGS) --input-def
DTLIB32=$(DTDEF32) $(top_srcdir)/`echo $@ | $(SED) 's|/lib|/|;s|\.a|.def|'`
DTLIB64=$(DTDEF64) $(top_srcdir)/`echo $@ | $(SED) 's|/lib|/|;s|\.a|.def|'`
LDFLAGS32=-m32 -L$(top_builddir)/lib32
LDFLAGS64=-m64 -L$(top_builddir)/lib64
extra_include=-I$(top_srcdir)/include
processed_defs=

# default directx import library names
xinput=xinput1_3
xapofx=xapofx1_5
x3daudio=x3daudio1_7
d3dx9=d3dx9_43
d3dx10=d3dx10_43
d3dx11=d3dx11_43
d3dcsxd=d3dcsxd_43
d3dcompiler=d3dcompiler_43

# can move this into libsrc/dummy_libm.c or similar
BUILT_SOURCES = _libm_dummy.c
_libm_dummy.c:
	echo "static int __attribute__((unused)) __mingw_libm_dummy;" > _libm_dummy.c

src_libm=_libm_dummy.c

lib32/DFP_src_%.dfp.obj: math/DFP/mpdecimal-2.3/%.c
	$(COMPILE) $(CPPFLAGS32) -std=gnu99 -frounding-math -fsignaling-nans -Wno-inline -DCONFIG_32 -DPPRO -DASM -Dmpdecimal_header=\"mpdecimal-i686.h\" -DUSE_LOCKING_CTOR -c $< -o $@

lib64/DFP_src_%.dfp.obj: math/DFP/mpdecimal-2.3/%.c
	$(COMPILE) $(CPPFLAGS64) -std=gnu99 -frounding-math -fsignaling-nans -Wno-inline -DCONFIG_64 -DASM -Dmpdecimal_header=\"mpdecimal-x86_64.h\" -DUSE_LOCKING_CTOR -c $< -o $@

if ENABLE_DFP
obj_dfpsrc32 = \
lib32/DFP_src_basearith.dfp.obj lib32/DFP_src_context.dfp.obj lib32/DFP_src_constants.dfp.obj lib32/DFP_src_convolute.dfp.obj lib32/DFP_src_crt.dfp.obj \
lib32/DFP_src_mpdecimal.dfp.obj lib32/DFP_src_mpsignal.dfp.obj lib32/DFP_src_difradix2.dfp.obj lib32/DFP_src_fnt.dfp.obj lib32/DFP_src_fourstep.dfp.obj \
lib32/DFP_src_io.dfp.obj lib32/DFP_src_memory.dfp.obj lib32/DFP_src_numbertheory.dfp.obj lib32/DFP_src_sixstep.dfp.obj lib32/DFP_src_transpose.dfp.obj

obj_dfpsrc64 = \
lib64/DFP_src_basearith.dfp.obj lib64/DFP_src_context.dfp.obj lib64/DFP_src_constants.dfp.obj lib64/DFP_src_convolute.dfp.obj lib64/DFP_src_crt.dfp.obj \
lib64/DFP_src_mpdecimal.dfp.obj lib64/DFP_src_mpsignal.dfp.obj lib64/DFP_src_difradix2.dfp.obj lib64/DFP_src_fnt.dfp.obj lib64/DFP_src_fourstep.dfp.obj \
lib64/DFP_src_io.dfp.obj lib64/DFP_src_memory.dfp.obj lib64/DFP_src_numbertheory.dfp.obj lib64/DFP_src_sixstep.dfp.obj lib64/DFP_src_transpose.dfp.obj

src_dfp_math = \
math/DFP/__fpclassifyd32.c math/DFP/__fpclassifyd64.c math/DFP/__fpclassifyd128.c \
math/DFP/__isnand32.c math/DFP/__isnand64.c math/DFP/__isnand128.c \
math/DFP/__signbitd32.c math/DFP/__signbitd64.c math/DFP/__signbitd128.c \
math/DFP/isinfd32.c math/DFP/isinfd64.c math/DFP/isinfd128.c

else
obj_dfpsrc32 =
obj_dfpsrc64 =
src_dfp_math =
endif

src_libshell32=libsrc/shell32.c
src_libdinput=libsrc/dinput_kbd.c libsrc/dinput_joy.c libsrc/dinput_joy2.c libsrc/dinput_mouse.c libsrc/dinput_mouse2.c
src_libdinput8=libsrc/dinput_private.h libsrc/dinput_joy.c libsrc/dinput_joy2.c libsrc/dinput_mouse.c libsrc/dinput_mouse2.c libsrc/dinput_kbd.c
src_libdmoguids=libsrc/dmoguids.c
src_libdxerr8=libsrc/dxerr8.c libsrc/dxerr8w.c
src_libdxerr9=libsrc/dxerr9.c libsrc/dxerr9w.c
src_libmfuuid=libsrc/mfuuid.c
src_libwbemuuid=libsrc/wbemuuid.c
src_libwmcodecdspuuid=libsrc/wmcodecdspuuid.c
src_libwindowscodecs=libsrc/windowscodecs.c
src_libdxguid=libsrc/dxguid.c
src_libksuser=libsrc/ksuser.c
src_libksguid=libsrc/ksuser.c
src_liblargeint=libsrc/largeint.c
src_libsensorsapi=libsrc/sensorsapi.c
src_libportabledeviceguids=libsrc/portabledeviceguids.c

src_libmingw32=include/oscalls.h include/internal.h include/sect_attribs.h \
  crt/atonexit.c      crt/crt0_c.c         crt/dll_argv.c  crt/gccmain.c     crt/natstart.c  crt/pseudo-reloc-list.c  crt/wildcard.c \
  crt/charmax.c       crt/crt0_w.c         crt/dllargv.c   crt/gs_support.c  crt/_newmode.c  crt/tlssup.c             crt/xncommod.c \
  crt/cinitexe.c      crt/crt0_w.c         crt/merr.c      crt/pesect.c      crt/udllargc.c  crt/xthdloc.c            crt/CRT_fp10.c \
  crt/mingw_custom.c  crt/mingw_helpers.c  \
  crt/pseudo-reloc.c  crt/udll_argv.c      \
  crt/xtxtmode.c      crt/crt_handler.c    \
  crt/tlsthrd.c       crt/tlsmthread.c     crt/tlsmcrt.c

src_libscrnsave=libsrc/scrnsave.c
src_libscrnsavw=libsrc/scrnsave.c
src_libstrmiids=libsrc/strmiids.c
src_libmingwthrd=libsrc/mingwthrd_mt.c

src_libgdiplus=libsrc/gdiplus.c

src_libuuid=\
  libsrc/ativscp-uuid.c   libsrc/atsmedia-uuid.c  libsrc/bth-uuid.c       libsrc/cguid-uuid.c     libsrc/comcat-uuid.c  \
  libsrc/devguid.c        libsrc/docobj-uuid.c    libsrc/dxva-uuid.c      libsrc/exdisp-uuid.c    libsrc/extras-uuid.c  \
  libsrc/fwp-uuid.c       libsrc/guid_nul.c       libsrc/hlguids-uuid.c   libsrc/hlink-uuid.c     libsrc/mlang-uuid.c   \
  libsrc/msctf-uuid.c     libsrc/mshtmhst-uuid.c  libsrc/mshtml-uuid.c    libsrc/msxml-uuid.c     libsrc/netcon-uuid.c  \
  libsrc/ntddkbd-uuid.c   libsrc/ntddmou-uuid.c   libsrc/ntddpar-uuid.c   libsrc/ntddscsi-uuid.c  libsrc/ntddser-uuid.c \
  libsrc/ntddstor-uuid.c  libsrc/ntddvdeo-uuid.c  libsrc/oaidl-uuid.c     libsrc/objidl-uuid.c    libsrc/objsafe-uuid.c \
  libsrc/ocidl-uuid.c     libsrc/oleacc-uuid.c    libsrc/olectlid-uuid.c  libsrc/oleidl-uuid.c    libsrc/power-uuid.c   \
  libsrc/powrprof-uuid.c  libsrc/urlmon-uuid.c    libsrc/usbcamdi-uuid.c  libsrc/usbiodef-uuid.c  libsrc/uuid.c         \
  libsrc/vds-uuid.c       libsrc/virtdisk-uuid.c  libsrc/wia-uuid.c

src_libws2_32=libsrc/ws2_32.c \
  \
  libsrc/ws2tcpip/in6_addr_equal.c           libsrc/ws2tcpip/in6addr_isany.c           libsrc/ws2tcpip/in6addr_isloopback.c       \
  libsrc/ws2tcpip/in6addr_setany.c           libsrc/ws2tcpip/in6addr_setloopback.c     libsrc/ws2tcpip/in6_is_addr_linklocal.c    \
  libsrc/ws2tcpip/in6_is_addr_loopback.c     libsrc/ws2tcpip/in6_is_addr_mc_global.c   libsrc/ws2tcpip/in6_is_addr_mc_linklocal.c \
  libsrc/ws2tcpip/in6_is_addr_mc_nodelocal.c libsrc/ws2tcpip/in6_is_addr_mc_orglocal.c libsrc/ws2tcpip/in6_is_addr_mc_sitelocal.c \
  libsrc/ws2tcpip/in6_is_addr_multicast.c    libsrc/ws2tcpip/in6_is_addr_sitelocal.c   libsrc/ws2tcpip/in6_is_addr_unspecified.c  \
  libsrc/ws2tcpip/in6_is_addr_v4compat.c     libsrc/ws2tcpip/in6_is_addr_v4mapped.c    libsrc/ws2tcpip/in6_set_addr_loopback.c    \
  libsrc/ws2tcpip/in6_set_addr_unspecified.c libsrc/ws2tcpip/gai_strerrorA.c           libsrc/ws2tcpip/gai_strerrorW.c            \
  \
  libsrc/wspiapi/WspiapiStrdup.c             libsrc/wspiapi/WspiapiParseV4Address.c    libsrc/wspiapi/WspiapiNewAddrInfo.c        \
  libsrc/wspiapi/WspiapiQueryDNS.c           libsrc/wspiapi/WspiapiLookupNode.c        libsrc/wspiapi/WspiapiClone.c              \
  libsrc/wspiapi/WspiapiLegacyFreeAddrInfo.c libsrc/wspiapi/WspiapiLegacyGetAddrInfo.c libsrc/wspiapi/WspiapiLegacyGetNameInfo.c  \
  libsrc/wspiapi/WspiapiLoad.c               libsrc/wspiapi/WspiapiGetAddrInfo.c       libsrc/wspiapi/WspiapiGetNameInfo.c        \
  libsrc/wspiapi/WspiapiFreeAddrInfo.c

src_msvcrt=\
  misc/invalid_parameter_handler.c \
  misc/output_format.c \
  secapi/_access_s.c \
  secapi/_cgets_s.c \
  secapi/_cgetws_s.c \
  secapi/_chsize_s.c \
  secapi/_cprintf_s.c \
  secapi/_cprintf_s_l.c \
  secapi/_ctime32_s.c \
  secapi/_ctime64_s.c \
  secapi/_cwprintf_s.c \
  secapi/_cwprintf_s_l.c \
  secapi/_gmtime32_s.c \
  secapi/_gmtime64_s.c \
  secapi/_localtime32_s.c \
  secapi/_localtime64_s.c \
  secapi/_mktemp_s.c \
  secapi/_strdate_s.c \
  secapi/_strtime_s.c \
  secapi/_umask_s.c \
  secapi/_vcprintf_s.c \
  secapi/_vcprintf_s_l.c \
  secapi/_vcwprintf_s.c \
  secapi/_vcwprintf_s_l.c \
  secapi/_waccess_s.c \
  secapi/_wasctime_s.c \
  secapi/_wctime32_s.c \
  secapi/_wctime64_s.c \
  secapi/_wstrtime_s.c \
  secapi/_wmktemp_s.c \
  secapi/_wstrdate_s.c \
  secapi/asctime_s.c \
  secapi/memcpy_s.c \
  secapi/rand_s.c \
  secapi/sprintf_s.c \
  secapi/vsprintf_s.c \
  secapi/wmemcpy_s.c

src_msvcrt32=\
  $(src_msvcrt) \
  misc/lc_locale_func.c

src_libmingwex=\
  crt/dllentry.c        crt/dllmain.c \
  \
  complex/cabs.c     complex/cabsf.c    complex/cabsl.c   complex/cacos.c    complex/cacosf.c   complex/cacosl.c \
  complex/carg.c     complex/cargf.c    complex/cargl.c   complex/casin.c    complex/casinf.c   complex/casinl.c \
  complex/catan.c    complex/catanf.c   complex/catanl.c  complex/ccos.c     complex/ccosf.c    complex/ccosl.c  \
  complex/cexp.c     complex/cexpf.c    complex/cexpl.c   complex/cimag.c    complex/cimagf.c   complex/cimagl.c \
  complex/clog.c     complex/clogf.c    complex/clogl.c   complex/conj.c     complex/conjf.c    complex/conjl.c  \
  complex/cpow.c     complex/cpowf.c    complex/cpowl.c   complex/cproj.c    complex/cprojf.c   complex/cprojl.c \
  complex/creal.c    complex/crealf.c   complex/creall.c  complex/csin.c     complex/csinf.c    complex/csinl.c  \
  complex/csqrt.c    complex/csqrtf.c   complex/csqrtl.c  complex/ctan.c     complex/ctanf.c    complex/ctanl.c  \
  complex/cabs.def.h    complex/cacos.def.h  complex/cacosh.def.h  complex/carg.def.h          complex/casin.def.h \
  complex/casinh.def.h  complex/catan.def.h  complex/catanh.def.h  complex/ccos.def.h          complex/ccosh.def.h \
  complex/cexp.def.h    complex/cimag.def.h  complex/clog.def.h    complex/complex_internal.h  complex/conj.def.h  \
  complex/cpow.def.h    complex/cproj.def.h  complex/creal.def.h   complex/csin.def.h          complex/csinh.def.h \
  complex/csqrt.def.h   complex/ctan.def.h   complex/ctanh.def.h   \
  \
  gdtoa/gd_arith.h  gdtoa/gd_qnan.h  gdtoa/gdtoa.h  gdtoa/gdtoaimp.h \
  gdtoa/arithchk.c  gdtoa/dmisc.c    gdtoa/dtoa.c   gdtoa/g_dfmt.c   gdtoa/gdtoa.c      gdtoa/gethex.c     \
  gdtoa/g_ffmt.c    gdtoa/g__fmt.c   gdtoa/gmisc.c  gdtoa/g_xfmt.c   gdtoa/hd_init.c    gdtoa/hexnan.c     \
  gdtoa/misc.c      gdtoa/qnan.c     gdtoa/smisc.c  gdtoa/strtodg.c  gdtoa/strtodnrp.c  gdtoa/strtof.c     \
  gdtoa/strtopx.c   gdtoa/sum.c      gdtoa/ulp.c    \
  \
  math/_chgsignl.S      math/ceil.S        math/ceilf.S          math/ceill.S         math/copysignl.S     math/cosl_internal.S \
  math/exp2.S           math/exp2f.S       math/exp2l.S          math/floor.S         math/floorf.S        math/floorl.S        \
  math/fma.S            math/fmaf.S        math/frexpl.S         math/ilogb.S         math/ilogbf.S        math/ilogbl.S        \
  math/internal_logl.S  math/log10l.S      math/log1p.S          math/log1pf.S        math/log1pl.S        math/log2.S          \
  math/log2f.S          math/log2l.S       math/nearbyint.S      math/nearbyintf.S    math/nearbyintl.S    math/remainder.S     \
  math/remainderf.S     math/remainderl.S  math/remquo.S         math/remquof.S       math/remquol.S       math/scalbn.S        \
  math/scalbnf.S        math/scalbnl.S     math/sinl_internal.S  math/tanl.S          math/trunc.S         math/truncf.S        \
  math/acosf.c          math/acosh.c       math/acoshf.c         math/acoshl.c        math/acosl.c         math/asinf.c         \
  math/asinh.c          math/asinhf.c      math/asinhl.c         math/asinl.c         math/atan2f.c        math/atan2l.c        \
  math/atanf.c          math/atanh.c       math/atanhf.c         math/atanhl.c        math/atanl.c         math/cbrt.c          \
  math/cbrtf.c          math/cbrtl.c       math/cephes_emath.c   math/copysign.c      math/copysignf.c     math/cos.c           \
  math/cosf.c           math/coshf.c       math/coshl.c          math/cosl.c          math/cossin.c        math/erfl.c          \
  math/exp.c            math/expf.c        math/expl.c           math/expm1.c         math/expm1f.c        math/expm1l.c        \
  math/fabs.c           math/fabsf.c       math/fabsl.c          math/fdim.c          math/fdimf.c         math/fdiml.c         \
  math/fmal.c           math/fmax.c        math/fmaxf.c          math/fmaxl.c         math/fmin.c          math/fminf.c         \
  math/fminl.c          math/fmod.c        math/fmodf.c          math/fmodl.c         math/fp_consts.c     math/fp_constsf.c    \
  math/fp_constsl.c     math/fpclassify.c  math/fpclassifyf.c    math/fpclassifyl.c   math/frexpf.c        math/fucom.c         \
  math/hypotf.c         math/hypotl.c      math/isnan.c          math/isnanf.c        math/isnanl.c        math/ldexp.c         \
  math/ldexpf.c         math/ldexpl.c      math/lgamma.c         math/lgammaf.c       math/lgammal.c       math/llrint.c        \
  math/signgam.c \
  math/llrintf.c        math/llrintl.c     math/llround.c        math/llroundf.c      math/llroundl.c      math/log.c           \
  math/log10f.c         math/logb.c        math/logbf.c          math/logbl.c         math/logf.c          math/logl.c          \
  math/lrint.c          math/lrintf.c      math/lrintl.c         math/lround.c        math/lroundf.c       math/lroundl.c       \
  math/modf.c           math/modff.c       math/modfl.c          math/nextafterf.c    math/nextafterl.c    math/nexttoward.c    \
  math/nexttowardf.c    math/pow.c         math/powf.c           math/powi.c          math/powif.c         math/powil.c         \
  math/powl.c           math/rint.c        math/rintf.c          math/rintl.c         math/round.c         math/roundf.c        \
  math/roundl.c         math/s_erf.c       math/sf_erf.c         math/signbit.c       math/signbitf.c      math/signbitl.c      \
  math/sin.c            math/sinf.c        math/sinhf.c          math/sinhl.c         math/sinl.c          math/sqrt.c          \
  math/sqrtf.c          math/sqrtl.c       math/tanf.c           math/tanhf.c         math/tanhl.c         math/tgamma.c        \
  math/tgammaf.c        math/tgammal.c     math/truncl.c         \
  math/acosh.def.h      math/cos.def.h     math/exp.def.h        math/expm1.def.h     math/log.def.h       math/pow.def.h       \
  math/powi.def.h       math/sin.def.h     math/sqrt.def.h       \
  math/cephes_emath.h  math/cephes_mconf.h  math/fastmath.h  math/fp_consts.h  math/abs64.c \
  \
  misc/mb_wc_common.h \
  misc/mingw_getsp.S \
  misc/alarm.c           misc/basename.c            misc/btowc.c            misc/delay-f.c               misc/delay-n.c         \
  misc/delayimp.c        misc/difftime.c            misc/difftime32.c       misc/difftime64.c            misc/dirent.c          \
  misc/dirname.c         misc/execv.c               misc/execve.c           misc/execvp.c                misc/execvpe.c         \
  misc/feclearexcept.c   misc/fegetenv.c            misc/fegetexceptflag.c  misc/fegetround.c            misc/feholdexcept.c    \
  misc/feraiseexcept.c   misc/fesetenv.c            misc/fesetexceptflag.c  misc/fesetround.c            misc/fetestexcept.c    \
  misc/feupdateenv.c     misc/ftruncate.c           misc/fwide.c            misc/getlogin.c              misc/getopt.c          \
  misc/gettimeofday.c    misc/imaxabs.c             misc/imaxdiv.c          misc/isblank.c               misc/iswblank.c        \
  misc/mbrtowc.c         misc/mbsinit.c             misc/mempcpy.c          misc/mingw-aligned-malloc.c  misc/mingw-fseek.c     \
  misc/mingw_matherr.c   misc/mingw_mbwc_convert.c  misc/mingw_usleep.c     misc/mingw_wcstod.c          misc/mingw_wcstof.c    \
  misc/mingw_wcstold.c   misc/purecall.c            misc/seterrno.c         misc/sleep.c                 misc/spawnv.c          \
  misc/spawnve.c         misc/spawnvp.c             misc/spawnvpe.c         misc/strnlen.c               misc/strsafe.c         \
  misc/strtoimax.c       misc/strtold.c             misc/strtoumax.c        misc/tdelete.c               misc/tfind.c           \
  misc/tsearch.c         misc/twalk.c               misc/uchar_c16rtomb.c   misc/uchar_c32rtomb.c        misc/uchar_mbrtoc16.c  \
  misc/uchar_mbrtoc32.c  misc/wassert.c             misc/wcrtomb.c          misc/wcsnlen.c               misc/wcstof.c          \
  misc/wcstoimax.c       misc/wcstold.c             misc/wcstoumax.c        misc/wctob.c                 misc/wctrans.c         \
  misc/wctype.c          misc/wdirent.c             misc/winbs_uint64.c     misc/winbs_ulong.c           misc/winbs_ushort.c    \
  misc/wmemchr.c         misc/wmemcmp.c             misc/wmemcpy.c          misc/wmemmove.c              misc/wmempcpy.c        \
  misc/wmemset.c         \
  \
  stdio/mingw_pformat.h    \
  stdio/vfscanf2.S         stdio/vfwscanf2.S         stdio/vscanf2.S          stdio/vsscanf2.S          stdio/vswscanf2.S \
  stdio/vwscanf2.S         \
  stdio/_Exit.c            stdio/_findfirst64i32.c   stdio/_findnext64i32.c   stdio/_fstat.c \
  stdio/_fstat64i32.c      stdio/_ftime.c            stdio/_getc_nolock.c     stdio/_getwc_nolock.c     stdio/_putc_nolock.c    \
  stdio/_putwc_nolock.c    stdio/_stat.c             stdio/_stat64i32.c       stdio/_wfindfirst64i32.c  stdio/_wfindnext64i32.c \
  stdio/_wstat.c           stdio/_wstat64i32.c       stdio/asprintf.c         stdio/atoll.c             stdio/fgetpos64.c       \
  stdio/fopen64.c          stdio/fseeko32.c          stdio/fseeko64.c         stdio/fsetpos64.c         stdio/ftello.c          \
  stdio/ftello64.c         stdio/ftruncate64.c       stdio/lltoa.c            stdio/lltow.c             stdio/lseek64.c         \
  stdio/mingw_fprintf.c    stdio/mingw_fprintfw.c    stdio/mingw_fscanf.c     stdio/mingw_fwscanf.c     stdio/mingw_pformat.c   \
  stdio/mingw_pformatw.c   stdio/mingw_printf.c      stdio/mingw_printfw.c    stdio/mingw_scanf.c       stdio/mingw_snprintf.c  \
  stdio/mingw_snprintfw.c  stdio/mingw_sprintf.c     stdio/mingw_sprintfw.c   stdio/mingw_sscanf.c      stdio/mingw_swscanf.c   \
  stdio/mingw_vfprintf.c   stdio/mingw_vfprintfw.c   stdio/mingw_vfscanf.c    stdio/mingw_vprintf.c     stdio/mingw_vprintfw.c  \
  stdio/mingw_vsnprintf.c  stdio/mingw_vsnprintfw.c  stdio/mingw_vsprintf.c   stdio/mingw_vsprintfw.c   stdio/mingw_wscanf.c    \
  stdio/mingw_wvfscanf.c   stdio/snprintf.c          stdio/snwprintf.c        stdio/strtof.c            stdio/truncate.c        \
  stdio/ulltoa.c           stdio/ulltow.c            stdio/vasprintf.c        stdio/vfscanf.c           stdio/vfwscanf.c        \
  stdio/vscanf.c           stdio/vsnprintf.c         stdio/vsnprintf_s.c      stdio/vsnwprintf.c        stdio/vsscanf.c         \
  stdio/vswscanf.c         stdio/vwscanf.c           stdio/wtoll.c            stdio/mingw_asprintf.c    stdio/mingw_vasprintf.c

# These intrinsics are target independent:
src_intrincs= \
  intrincs/__movsb.c        intrincs/__movsd.c        intrincs/__movsw.c         intrincs/__stosb.c       intrincs/__stosd.c        \
  intrincs/__stosw.c        intrincs/_rotl64.c        intrincs/_rotr64.c         intrincs/bitscanfwd.c    intrincs/bitscanrev.c     \
  intrincs/bittest.c        intrincs/bittestc.c       intrincs/bittestci.c       intrincs/bittestr.c      intrincs/bittestri.c      \
  intrincs/bittests.c       intrincs/bittestsi.c      intrincs/cpuid.c           \
  intrincs/ilockadd.c       intrincs/ilockand.c        intrincs/ilockand64.c \
  intrincs/ilockcxch.c      \
  intrincs/ilockcxch16.c    intrincs/ilockcxch64.c    intrincs/ilockcxchptr.c    intrincs/ilockdec.c      intrincs/ilockdec16.c     \
  intrincs/ilockdec64.c     intrincs/ilockexch.c      intrincs/ilockexch64.c     intrincs/ilockexchadd.c  intrincs/ilockexchadd64.c \
  intrincs/ilockexchptr.c   intrincs/ilockinc.c       intrincs/ilockinc16.c      intrincs/ilockinc64.c    intrincs/ilockor.c        \
  intrincs/ilockor64.c      intrincs/ilockxor.c       intrincs/ilockxor64.c      intrincs/inbyte.c        intrincs/inbytestring.c   \
  intrincs/indword.c        intrincs/indwordstring.c  intrincs/inword.c          intrincs/inwordstring.c  intrincs/outbyte.c        \
  intrincs/outbytestring.c  intrincs/outdword.c       intrincs/outdwordstring.c  intrincs/outword.c       intrincs/outwordstring.c  \
  intrincs/rdtsc.c          intrincs/readcr0.c        intrincs/readcr2.c         intrincs/readcr3.c       intrincs/readcr4.c        \
  intrincs/readcr8.c        intrincs/readmsr.c        intrincs/writecr0.c        intrincs/writecr2.c      intrincs/writecr3.c       \
  intrincs/writecr4.c       intrincs/writecr8.c       intrincs/writemsr.c        intrincs/__int2c.c       intrincs/RtlSecureZeroMemory.c

# these only go into the 64 bit version:
src_intrincs64=\
  intrincs/bittest64.c    intrincs/bittestc64.c   intrincs/bittestr64.c   intrincs/bittestri64.c     \
  intrincs/bittests64.c   intrincs/bittestsi64.c  intrincs/bitscanfwd64.c intrincs/bitscanrev64.c    \
  intrincs/ilockadd64.c   intrincs/readgsbyte.c   intrincs/readgsword.c   intrincs/readgsdword.c     \
  intrincs/readgsqword.c  intrincs/writegsbyte.c  intrincs/writegsword.c  intrincs/writegsdword.c    \
  intrincs/writegsqword.c intrincs/mul128ex.c     intrincs/umul128ex.c    intrincs/_mul128.c         \
  intrincs/_umul128.c     intrincs/__movsq.c      intrincs/__stosq.c      intrincs/__shiftright128.c \
  intrincs/bittestci64.c  intrincs/__faststorefence.c    intrincs/__shiftleft128.c

# these only go into the 32 bit version:
src_intrincs32=\
  intrincs/readfsbyte.c   intrincs/readfsword.c   intrincs/readfsdword.c  \
  intrincs/writefsbyte.c  intrincs/writefsword.c  intrincs/writefsdword.c

winrtlibs=\
  winrt/libruntimeobject.a

if LIB32
#########
# Compiling 32-bit runtime
#

lib32dir=$(prefix)/@LIB32SUFFIXDIR@
crt32dir=$(lib32dir)
winrt32dir=$(lib32dir)
dx32dir=$(lib32dir)

winrt32_DATA = $(winrtlibs)

if !W32API
crt32_DATA = \
  lib32/crt1.o    lib32/crt2.o     lib32/crt1u.o   lib32/crt2u.o    lib32/dllcrt1.o    lib32/dllcrt2.o \
  lib32/CRT_fp8.o lib32/CRT_fp10.o lib32/txtmode.o lib32/binmode.o  lib32/crtbegin.o   lib32/crtend.o \
  lib32/gcrt0.o   lib32/gcrt1.o    lib32/gcrt2.o   lib32/CRT_glob.o lib32/CRT_noglob.o
else
crt32_DATA =
endif

COMPILE32=$(COMPILE) $(CPPFLAGS32) $(extra_include) -D_SYSCRT=1 -DCRTDLL=1
lib32/crt1.o: crt/crtexe.c
	$(COMPILE32) -c $< -o $@ -D__CRTDLL__ -U__MSVCRT__
lib32/crt2.o: crt/crtexe.c
	$(COMPILE32) -c $< -o $@ -U__CRTDLL__ -D__MSVCRT__
lib32/crt1u.o: crt/ucrtexe.c
	$(COMPILE32) -c $< -o $@ -D__CRTDLL__ -U__MSVCRT__
lib32/crt2u.o: crt/ucrtexe.c
	$(COMPILE32) -c $< -o $@ -U__CRTDLL__ -D__MSVCRT__
lib32/dllcrt1.o: crt/crtdll.c
	$(COMPILE32) -c $< -o $@ -D__CRTDLL__ -U__MSVCRT__
lib32/dllcrt2.o: crt/crtdll.c
	$(COMPILE32) -c $< -o $@ -U__CRTDLL__ -D__MSVCRT__

lib32/gcrt0.o: profile/gcrt0.c
	$(COMPILE) $(CPPFLAGS32) -c $< -o $@
lib32/gcrt1.o: profile/gcrt0.c
	$(COMPILE) $(CPPFLAGS32) -c $< -o $@ -U__MSVCRT__
lib32/gcrt2.o: profile/gcrt0.c
	$(COMPILE) $(CPPFLAGS32) -c $< -o $@ -D__MSVCRT__

lib32/%.o: crt/%.c
	$(COMPILE) $(CPPFLAGS32) -c $< -o $@

# These source files aren't compiled in to any library yet.  I'm not sure how / where to do so.
# The source files that I did compile somewhere I just guessed at anyway.
#

temp= \
dxerr.c \
test.c

lib32_LIBRARIES = lib32/libkernel32.a
lib32_libkernel32_a_SOURCES = $(src_intrincs) $(src_intrincs32)
lib32_libkernel32_a_AR = $(DTLIB32) && $(AR) $(ARFLAGS)
lib32_libkernel32_a_CPPFLAGS=$(CPPFLAGS32) $(extra_include) $(AM_CPPFLAGS)

if !W32API
lib32_LIBRARIES += lib32/libmsvcrt.a
lib32_libmsvcrt_a_SOURCES = $(src_msvcrt32) lib32/msvcrt.def.in
lib32_libmsvcrt_a_AR = $(DTDEF32) lib32/msvcrt.def && $(AR) $(ARFLAGS)
lib32_libmsvcrt_a_CPPFLAGS=$(CPPFLAGS32) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
EXTRA_lib32_libmsvcrt_a_DEPENDENCIES=lib32/msvcrt.def
endif

lib32_LIBRARIES += lib32/libshell32.a
lib32_libshell32_a_SOURCES = $(src_libshell32)
lib32_libshell32_a_AR = $(DTLIB32) && $(AR) $(ARFLAGS)
lib32_libshell32_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libdinput.a
lib32_libdinput_a_SOURCES = $(src_libdinput)
lib32_libdinput_a_AR = $(DTLIB32) && $(AR) $(ARFLAGS)
lib32_libdinput_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libdinput8.a
lib32_libdinput8_a_SOURCES = $(src_libdinput8)
lib32_libdinput8_a_AR = $(DTLIB32) && $(AR) $(ARFLAGS)
lib32_libdinput8_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libdmoguids.a
lib32_libdmoguids_a_SOURCES = $(src_libdmoguids)
lib32_libdmoguids_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libdxerr8.a
lib32_libdxerr8_a_SOURCES = $(src_libdxerr8)
lib32_libdxerr8_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libdxerr9.a
lib32_libdxerr9_a_SOURCES = $(src_libdxerr9)
lib32_libdxerr9_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libmfuuid.a
lib32_libmfuuid_a_SOURCES = $(src_libmfuuid)
lib32_libmfuuid_a_CPPFLAGS = $(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libwmcodecdspuuid.a
lib32_libwmcodecdspuuid_a_SOURCES = $(src_libwmcodecdspuuid)
lib32_libwmcodecdspuuid_a_CPPFLAGS = $(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libwindowscodecs.a
lib32_libwindowscodecs_a_SOURCES = $(src_libwindowscodecs)
lib32_libwindowscodecs_a_CPPFLAGS = $(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libwbemuuid.a
lib32_libwbemuuid_a_SOURCES = $(src_libwbemuuid)
lib32_libwbemuuid_a_CPPFLAGS = $(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libdxguid.a
lib32_libdxguid_a_SOURCES = $(src_libdxguid)
lib32_libdxguid_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libksuser.a
lib32_libksuser_a_SOURCES = $(src_libksuser)
lib32_libksuser_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)
lib32_libksuser_a_AR = $(DTLIB32) && $(AR) $(ARFLAGS)

lib32_LIBRARIES += lib32/libksguid.a
lib32_libksguid_a_SOURCES = $(src_libksguid)
lib32_libksguid_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libsensorsapi.a
lib32_libsensorsapi_a_SOURCES = $(src_libsensorsapi)
lib32_libsensorsapi_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libportabledeviceguids.a
lib32_libportabledeviceguids_a_SOURCES = $(src_libportabledeviceguids)
lib32_libportabledeviceguids_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libscrnsave.a
lib32_libscrnsave_a_SOURCES = $(src_libscrnsave)
lib32_libscrnsave_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libscrnsavw.a
lib32_libscrnsavw_a_SOURCES = $(src_libscrnsavw)
lib32_libscrnsavw_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)
lib32_libscrnsavw_a_CFLAGS = -DUNICODE

lib32_LIBRARIES += lib32/libstrmiids.a
lib32_libstrmiids_a_SOURCES = $(src_libstrmiids)
lib32_libstrmiids_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libuuid.a
lib32_libuuid_a_SOURCES = $(src_libuuid)
lib32_libuuid_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libgdiplus.a
lib32_libgdiplus_a_SOURCES = $(src_libgdiplus)
lib32_libgdiplus_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)
lib32_libgdiplus_a_AR = $(DTLIB32) && $(AR) $(ARFLAGS)

lib32_LIBRARIES += lib32/libws2_32.a
lib32_libws2_32_a_SOURCES = $(src_libws2_32)
lib32_libws2_32_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)
lib32_libws2_32_a_AR = $(DTLIB32) && $(AR) $(ARFLAGS)

if !W32API
lib32_LIBRARIES += lib32/libdelayimp.a
lib32_libdelayimp_a_SOURCES =

lib32_LIBRARIES += lib32/libm.a
nodist_lib32_libm_a_SOURCES = $(src_libm)
lib32_libm_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libgmon.a
lib32_libgmon_a_SOURCES = profile/mcount.c \
  profile/profil.h profile/profil.c        \
  profile/gmon.h   profile/gmon.c \
  profile/mcountFunc.S
lib32_libgmon_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/liblargeint.a
lib32_liblargeint_a_SOURCES = $(src_liblargeint)
lib32_liblargeint_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libmingw32.a
lib32_libmingw32_a_CPPFLAGS=$(CPPFLAGS32) -D_SYSCRT=1 -DCRTDLL=1 $(extra_include) $(AM_CPPFLAGS)
lib32_libmingw32_a_SOURCES = $(src_libmingw32)

lib32_LIBRARIES += lib32/libmingwex.a
lib32_libmingwex_a_CPPFLAGS=$(CPPFLAGS32) $(extra_include) $(AM_CPPFLAGS)
lib32_libmingwex_a_SOURCES = $(src_libmingwex) $(src_dfp_math)
lib32_libmingwex_a_LIBADD = $(obj_dfpsrc32)

lib32_LIBRARIES += lib32/libmoldname.a
lib32_libmoldname_a_CPPFLAGS=$(CPPFLAGS32) $(extra_include) $(AM_CPPFLAGS)
lib32_libmoldname_a_SOURCES = $(src_libm)

lib32_LIBRARIES += lib32/libmingwthrd.a
lib32_libmingwthrd_a_SOURCES = $(src_libmingwthrd)
lib32_libmingwthrd_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

processed_defs += lib32/msvcrt.def lib32/msvcr80.def lib32/msvcr90.def lib32/msvcr90d.def lib32/msvcr100.def lib32/msvcr110.def

endif

include lib32/Makefile.am

if !W32API
lib32_DATA += lib32/libglut.a lib32/libmsvcp60.a lib32/libmsvcr80.a lib32/libmsvcr90.a lib32/libmsvcr90d.a lib32/libmsvcr100.a lib32/libmsvcr110.a lib32/libcrtdll.a
endif

# combine these two rules with the ones for lib64
# Use two patterns, one for 32/64 in lib32/ and lib64/
lib32/libcrtdll.a lib32/libmsvcr80.a: lib32/lib%.a: lib32/%.def
	$(DTDEF32) $< --dllname $*.dll

lib32/lib%.a: lib32/%.def
	$(DTDEF32) $<

# libvfw32.a contains import stubs for 3 dll's.  Using an MRI script
# seems to be the simplest way to combine them into one archive.
# NB: With older dlltool, the object file members will not have unique
# names.
lib32/libvfw32.a: lib32/vfw32.mri lib32/libmsvfw32.a lib32/libavifil32.a lib32/libavicap32.a
	rm -f $@
	$(AR) -M < $<
	$(RANLIB) $@

dx32_DATA =
dx32_DATA += lib32/libxinput.a
dx32_DATA += lib32/libxapofx.a
dx32_DATA += lib32/libx3daudio.a
dx32_DATA += lib32/libd3dx9.a
dx32_DATA += lib32/libd3dx10.a
dx32_DATA += lib32/libd3dx11.a
dx32_DATA += lib32/libd3dcsxd.a
dx32_DATA += lib32/libd3dcompiler.a

lib32/libxinput.a: lib32/$(xinput).def
	$(DTDEF32) $<
lib32/libxapofx.a: lib32/$(xapofx).def
	$(DTDEF32) $<
lib32/libx3daudio.a: lib32/$(x3daudio).def
	$(DTDEF32) $<
lib32/libd3dx9.a: lib32/$(d3dx9).def
	$(DTDEF32) $<
lib32/libd3dx10.a: lib32/$(d3dx10).def
	$(DTDEF32) $<
lib32/libd3dx11.a: lib32/$(d3dx11).def
	$(DTDEF32) $<
lib32/libd3dcsxd.a: lib32/$(d3dcsxd).def
	$(DTDEF32) $<
lib32/libd3dcompiler.a: lib32/$(d3dcompiler).def
	$(DTDEF32) $<

endif
# End 32-bit runtime
# ##########



if LIB64
#########################################################################
# Compiling 64-bit runtime
# #######################################################################

lib64dir=$(prefix)/@LIB64SUFFIXDIR@
crt64dir=$(lib64dir)
winrt64dir=$(lib64dir)
dx64dir=$(lib64dir)

winrt64_DATA = $(winrtlibs)

if !W32API
crt64_DATA = \
  lib64/crt1.o    lib64/crt2.o     lib64/crt1u.o   lib64/crt2u.o   lib64/dllcrt1.o lib64/dllcrt2.o \
  lib64/CRT_fp8.o lib64/CRT_fp10.o lib64/txtmode.o lib64/binmode.o lib64/crtbegin.o lib64/crtend.o \
  lib64/gcrt0.o   lib64/gcrt1.o    lib64/gcrt2.o   lib64/CRT_glob.o lib64/CRT_noglob.o
else
crt64_DATA =
endif

COMPILE64=$(COMPILE) $(CPPFLAGS64) $(extra_include) -D_SYSCRT=1 -DCRTDLL=1
lib64/crt1.o: crt/crtexe.c
	$(COMPILE64) -c $< -o $@ -D__CRTDLL__ -U__MSVCRT__
lib64/crt2.o: crt/crtexe.c
	$(COMPILE64) -c $< -o $@ -U__CRTDLL__ -D__MSVCRT__
lib64/crt1u.o: crt/ucrtexe.c
	$(COMPILE64) -c $< -o $@ -D__CRTDLL__ -U__MSVCRT__
lib64/crt2u.o: crt/ucrtexe.c
	$(COMPILE64) -c $< -o $@ -U__CRTDLL__ -D__MSVCRT__
lib64/dllcrt1.o: crt/crtdll.c
	$(COMPILE64) -c $< -o $@ -D__CRTDLL__ -U__MSVCRT__
lib64/dllcrt2.o: crt/crtdll.c
	$(COMPILE64) -c $< -o $@ -U__CRTDLL__ -D__MSVCRT__

lib64/gcrt0.o: profile/gcrt0.c
	$(COMPILE) $(CPPFLAGS64) -c $< -o $@
lib64/gcrt1.o: profile/gcrt0.c
	$(COMPILE) $(CPPFLAGS64) -c $< -o $@ -U__MSVCRT__
lib64/gcrt2.o: profile/gcrt0.c
	$(COMPILE) $(CPPFLAGS64) -c $< -o $@ -D__MSVCRT__

lib64/%.o: crt/%.c
	$(COMPILE) $(CPPFLAGS64) -c $< -o $@

lib64_LIBRARIES = lib64/libkernel32.a
lib64_libkernel32_a_SOURCES = $(src_intrincs) $(src_intrincs64)
lib64_libkernel32_a_CPPFLAGS=$(CPPFLAGS64) $(extra_include) $(AM_CPPFLAGS)
lib64_libkernel32_a_AR = $(DTLIB64) && $(AR) $(ARFLAGS)

if !W32API
lib64_LIBRARIES += lib64/libmsvcrt.a
lib64_libmsvcrt_a_SOURCES = $(src_msvcrt) lib64/msvcrt.def.in
lib64_libmsvcrt_a_AR = $(DTDEF64) lib64/msvcrt.def && $(AR) $(ARFLAGS)
lib64_libmsvcrt_a_CPPFLAGS=$(CPPFLAGS64) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
EXTRA_lib64_libmsvcrt_a_DEPENDENCIES=lib64/msvcrt.def
endif

lib64_LIBRARIES += lib64/libshell32.a
lib64_libshell32_a_SOURCES = $(src_libshell32)
lib64_libshell32_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)
lib64_libshell32_a_AR = $(DTLIB64) && $(AR) $(ARFLAGS)

lib64_LIBRARIES += lib64/libdinput.a
lib64_libdinput_a_SOURCES = $(src_libdinput)
lib64_libdinput_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)
lib64_libdinput_a_AR = $(DTLIB64) && $(AR) $(ARFLAGS)

lib64_LIBRARIES += lib64/libdinput8.a
lib64_libdinput8_a_SOURCES = $(src_libdinput8)
lib64_libdinput8_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)
lib64_libdinput8_a_AR = $(DTLIB64) && $(AR) $(ARFLAGS)

lib64_LIBRARIES += lib64/libdmoguids.a
lib64_libdmoguids_a_SOURCES = $(src_libdmoguids)
lib64_libdmoguids_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libdxerr8.a
lib64_libdxerr8_a_SOURCES = $(src_libdxerr8)
lib64_libdxerr8_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libdxerr9.a
lib64_libdxerr9_a_SOURCES = $(src_libdxerr9)
lib64_libdxerr9_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libmfuuid.a
lib64_libmfuuid_a_SOURCES = $(src_libmfuuid)
lib64_libmfuuid_a_CPPFLAGS = $(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libwmcodecdspuuid.a
lib64_libwmcodecdspuuid_a_SOURCES = $(src_libwmcodecdspuuid)
lib64_libwmcodecdspuuid_a_CPPFLAGS = $(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libwindowscodecs.a
lib64_libwindowscodecs_a_SOURCES = $(src_libwindowscodecs)
lib64_libwindowscodecs_a_CPPFLAGS = $(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libwbemuuid.a
lib64_libwbemuuid_a_SOURCES = $(src_libwbemuuid)
lib64_libwbemuuid_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libdxguid.a
lib64_libdxguid_a_SOURCES = $(src_libdxguid)
lib64_libdxguid_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libsensorsapi.a
lib64_libsensorsapi_a_SOURCES = $(src_libsensorsapi)
lib64_libsensorsapi_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libportabledeviceguids.a
lib64_libportabledeviceguids_a_SOURCES = $(src_libportabledeviceguids)
lib64_libportabledeviceguids_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libksuser.a
lib64_libksuser_a_SOURCES = $(src_libksuser)
lib64_libksuser_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)
lib64_libksuser_a_AR = $(DTLIB64) && $(AR) $(ARFLAGS)

lib64_LIBRARIES += lib64/libksguid.a
lib64_libksguid_a_SOURCES = $(src_libksguid)
lib64_libksguid_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libscrnsave.a
lib64_libscrnsave_a_SOURCES = $(src_libscrnsave)
lib64_libscrnsave_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libscrnsavw.a
lib64_libscrnsavw_a_SOURCES = libsrc/scrnsave.c
lib64_libscrnsavw_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)
lib64_libscrnsavw_a_CFLAGS = -DUNICODE

lib64_LIBRARIES += lib64/libstrmiids.a
lib64_libstrmiids_a_SOURCES = $(src_libstrmiids)
lib64_libstrmiids_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libuuid.a
lib64_libuuid_a_SOURCES = $(src_libuuid)
lib64_libuuid_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libgdiplus.a
lib64_libgdiplus_a_SOURCES = $(src_libgdiplus)
lib64_libgdiplus_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)
lib64_libgdiplus_a_AR = $(DTLIB64) && $(AR) $(ARFLAGS)

lib64_LIBRARIES += lib64/libws2_32.a
lib64_libws2_32_a_SOURCES = $(src_libws2_32)
lib64_libws2_32_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)
lib64_libws2_32_a_AR = $(DTLIB64) && $(AR) $(ARFLAGS)

if !W32API
lib64_LIBRARIES += lib64/libdelayimp.a
lib64_libdelayimp_a_SOURCES =

lib64_LIBRARIES += lib64/libm.a
nodist_lib64_libm_a_SOURCES = $(src_libm)
lib64_libm_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libgmon.a
lib64_libgmon_a_SOURCES = profile/mcount.c \
  profile/profil.h profile/profil.c        \
  profile/gmon.h   profile/gmon.c \
  profile/mcountFunc.S
lib64_libgmon_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/liblargeint.a
lib64_liblargeint_a_SOURCES = $(src_liblargeint)
lib64_liblargeint_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libmingw32.a
lib64_libmingw32_a_CPPFLAGS=$(CPPFLAGS64) -D_SYSCRT=1 -DCRTDLL=1 $(extra_include) $(AM_CPPFLAGS)
lib64_libmingw32_a_SOURCES = $(src_libmingw32)

lib64_LIBRARIES += lib64/libmingwex.a
lib64_libmingwex_a_CPPFLAGS=$(CPPFLAGS64) $(extra_include) $(AM_CPPFLAGS)
lib64_libmingwex_a_SOURCES = $(src_libmingwex) $(src_dfp_math)
lib64_libmingwex_a_LIBADD = $(obj_dfpsrc64)

lib64_LIBRARIES += lib64/libmoldname.a
lib64_libmoldname_a_CPPFLAGS=$(CPPFLAGS64) $(extra_include) $(AM_CPPFLAGS)
lib64_libmoldname_a_SOURCES = $(src_libm)

lib64_LIBRARIES += lib64/libmingwthrd.a
lib64_libmingwthrd_a_SOURCES = $(src_libmingwthrd)
lib64_libmingwthrd_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

processed_defs += lib64/msvcrt.def lib64/msvcr80.def lib64/msvcr90.def lib64/msvcr90d.def lib64/msvcr100.def lib64/msvcr110.def

endif

lib64_DATA = \
  lib64/libwinusb.a     lib64/libavrt.a       \
  lib64/lib6to4svc.a    lib64/libaaaamon.a    lib64/libacledit.a      lib64/libaclui.a      \
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
  lib64/libchsbrkr.a    lib64/libchtbrkr.a    lib64/libchtskdic.a     lib64/libciadmin.a    \
  lib64/libcic.a        lib64/libcimwin32.a   lib64/libCINTIME.a      lib64/libciodm.a      lib64/libc_is2022.a      \
  lib64/libc_iscii.a    lib64/libclbcatex.a   lib64/libclbcatq.a      lib64/libclb.a        lib64/libcliconfg.a      \
  lib64/libclasspnp.a   lib64/libclusapi.a    lib64/libcmcfg32.a      lib64/libcmdial32.a   lib64/libcmpbk32.a       \
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
  lib64/libdevmgr.a     lib64/libdevobj.a     lib64/libdevrtl.a       \
  lib64/libdfrgifps.a   lib64/libdfrgsnap.a     lib64/libdfrgui.a     lib64/libdfsshlex.a      \
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
  lib64/libhid.a        lib64/libhidclass.a   lib64/libhidparse.a     lib64/libhlink.a      lib64/libhmmapi.a        \
  lib64/libhnetcfg.a    lib64/libhnetmon.a    lib64/libhnetwiz.a      lib64/libhostmib.a    lib64/libhotplug.a       \
  lib64/libhticons.a    lib64/libhtrn_jis.a   lib64/libhttpapi.a      lib64/libhttpext.a    lib64/libhttpmib.a       \
  lib64/libhttpodbc.a   lib64/libhtui.a       lib64/libhypertrm.a     lib64/libiasacct.a    lib64/libiasads.a        \
  lib64/libiashlpr.a    lib64/libiasnap.a     lib64/libiaspolcy.a     lib64/libiasrad.a     lib64/libiassam.a        \
  lib64/libiassdo.a     lib64/libiassvcs.a    lib64/libicaapi.a       lib64/libicfgnt5.a    lib64/libicm32.a         \
  lib64/libicmp.a       lib64/libicmui.a      lib64/libicwconn.a      lib64/libicwdial.a    lib64/libicwdl.a         \
  lib64/libicwhelp.a    lib64/libicwphbk.a    lib64/libicwutil.a      lib64/libidq.a        lib64/libieakeng.a       \
  lib64/libieaksie.a    lib64/libiedkcs32.a   lib64/libieencode.a     lib64/libiepeers.a    lib64/libiernonce.a      \
  lib64/libiesetup.a    lib64/libifmon.a      lib64/libifsutil.a      lib64/libigmpagnt.a   lib64/libiisadmin.a      \
  lib64/libiiscfg.a     lib64/libiisclex4.a   lib64/libiis.a          lib64/libiisext.a     lib64/libiislog.a        \
  lib64/libiismap.a     lib64/libiisrstap.a   lib64/libiisrtl.a       lib64/libiissuba.a    lib64/libiisui.a         \
  lib64/libiisuiobj.a   lib64/libiisutil.a    lib64/libiisw3adm.a     lib64/libiiswmi.a     lib64/libimagehlp.a      \
  lib64/libimekrcic.a   lib64/libimeshare.a   lib64/libimgutil.a      lib64/libimjp81k.a    lib64/libimjpcic.a       \
  lib64/libimjpcus.a    lib64/libimjpdct.a    lib64/libimjputyc.a     lib64/libimm32.a      lib64/libimsinsnt.a      \
  lib64/libimskdic.a    lib64/libinetcfg.a    lib64/libinetcomm.a     lib64/libinetmgr.a    lib64/libinetmib1.a      \
  lib64/libinetpp.a     lib64/libinetppui.a   lib64/libinfoadmn.a     lib64/libinfocomm.a   lib64/libinfoctrs.a      \
  lib64/libinfosoft.a   lib64/libinitpki.a    lib64/libinput.a        lib64/libinseng.a     \
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
  lib64/libmscandui.a   lib64/libmscat32.a    lib64/libmscms.a                              lib64/libmsctfp.a        \
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
  lib64/libmsv1_0.a     lib64/libmsvcirt.a    lib64/libmsvfw32.a      lib64/libmsvidc32.a      \
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
  lib64/libpanmap.a     \
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
  lib64/libsoftkbd.a    lib64/libsoftpub.a    lib64/libspcommon.a     lib64/libspoolss.a    \
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
  lib64/liburlmon.a     lib64/libusbmon.a     lib64/libusbcamd2.a     lib64/libusbd.a       lib64/libusbport.a       \
  lib64/libuser32.a     lib64/libuserenv.a    lib64/libusp10.a        lib64/libutildll.a    lib64/libuxtheme.a       \
  lib64/libvbscript.a   lib64/libvdsbas.a     lib64/libvdsdyndr.a     lib64/libvds_ps.a     lib64/libvdsutil.a       \
  lib64/libvdswmi.a     lib64/libverifier.a   lib64/libversion.a      lib64/libvgx.a        lib64/libviewprov.a      \
  lib64/libvmx_mode.a   lib64/libvssapi.a     lib64/libvss_ps.a       lib64/libvsswmi.a     lib64/libw32time.a       \
  lib64/libw32topl.a    lib64/libw3cache.a    lib64/libw3comlog.a     lib64/libw3core.a     lib64/libw3ctrlps.a      \
  lib64/libw3ctrs.a     lib64/libw3dt.a       lib64/libw3ext.a        lib64/libw3isapi.a    lib64/libw3ssl.a         \
  lib64/libw3tp.a       lib64/libwab32.a      lib64/libwabimp.a       lib64/libwamreg.a     lib64/libwamregps.a      \
  lib64/libwbemcore.a   lib64/libwbemupgd.a   lib64/libwdigest.a      lib64/libwdmaud.a     lib64/libwebcheck.a      \
  lib64/libwebclnt.a    lib64/libwebhits.a    lib64/libwiadss.a       lib64/libwiarpc.a     lib64/libwiaservc.a      \
  lib64/libwiashext.a   lib64/libwin32spl.a   lib64/libwinfax.a       lib64/libwininet.a    lib64/libwinipsec.a      \
  lib64/libwinmm.a      lib64/libwinrnr.a     lib64/libwinscard.a     lib64/libwinspool.a   lib64/libwinsrv.a        \
  lib64/libwinsta.a     lib64/libwintrust.a   lib64/libwkssvc.a       lib64/libwldap32.a    lib64/libwlnotify.a      \
  lib64/libwlstore.a    lib64/libwmi2xml.a    lib64/libwmiaprpl.a     lib64/libwmi.a        lib64/libwmilib.a        \
  lib64/libwmiprop.a    \
  lib64/libwmisvc.a     lib64/libwow64cpu.a   lib64/libwow64.a        lib64/libwow64mib.a   lib64/libwow64win.a      \
  lib64/libwpd_ci.a     lib64/libws2help.a    lib64/libwscsvc.a       lib64/libwshatm.a     lib64/libwshbth.a        \
  lib64/libwshcon.a     lib64/libwsock32.a    lib64/libzoneoc.a       lib64/libnormaliz.a   \
  \
  lib64/libclfsw32.a    \
  lib64/libdwmapi.a     lib64/libntoskrnl.a     lib64/libuxtheme.a    \
  lib64/libwtsapi32.a   \
  lib64/libbcrypt.a     lib64/libbthprops.a   lib64/libdhcpcsvc6.a   lib64/libdxva2.a       lib64/libeappcfg.a       \
  lib64/libeappgnui.a   lib64/libeapphost.a   lib64/libeappprxy.a    lib64/libevr.a         lib64/libiscsidsc.a      \
  lib64/libktmw32.a     lib64/libmf.a         lib64/libmfplat.a      lib64/libmsdrm.a       lib64/libncrypt.a        \
  lib64/libwecapi.a     lib64/libwevtapi.a    lib64/libwevtfwd.a     lib64/libqutil.a       lib64/libconnect.a       \
  lib64/libfwpuclnt.a   lib64/libndfapi.a     lib64/libp2p.a         lib64/libp2pcollab.a   lib64/libp2pgraph.a      \
  lib64/libwdstptc.a    lib64/libcscapi.a     lib64/librstrmgr.a     lib64/libqwave.a       lib64/libwsdapi.a        \
  lib64/libvfw32.a      \
  lib64/libks.a         lib64/librpcdiag.a    lib64/librpchttp.a     lib64/libresutil.a     lib64/libslwga.a         \
  lib64/libslc.a        lib64/libslcext.a     lib64/libvsstrace.a    lib64/libmsctfmonitor.a lib64/libtbs.a          \
  lib64/libtdh.a        lib64/libtxfw32.a     lib64/libwlanui.a      lib64/libwlanapi.a     lib64/libwlanutil.a      \
  lib64/libwer.a        lib64/libndis.a       lib64/libd2d1.a        lib64/libwdscsl.a      lib64/libpcwum.a         \
  lib64/libwdscore.a    lib64/libcryptsp.a    lib64/libwdsclient.a   lib64/libwdsupgcompl.a lib64/libwdsclientapi.a  \
  lib64/libwdsutil.a    lib64/libwdsimage.a      \
  \
  lib64/libcryptxml.a   lib64/libsspicli.a    \
  \
  lib64/libd3dcompiler_33.a lib64/libd3dcompiler_34.a lib64/libd3dcompiler_35.a \
  lib64/libd3dcompiler_36.a lib64/libd3dcompiler_37.a lib64/libd3dcompiler_38.a \
  lib64/libd3dcompiler_39.a lib64/libd3dcompiler_40.a lib64/libd3dcompiler_41.a \
  lib64/libd3dcompiler_42.a lib64/libd3dcompiler_43.a lib64/libd3dcsxd_43.a \
  lib64/libd3dx10_33.a      lib64/libd3dx10_34.a      lib64/libd3dx10_35.a \
  lib64/libd3dx10_36.a      lib64/libd3dx10_37.a      lib64/libd3dx10_38.a \
  lib64/libd3dx10_39.a      lib64/libd3dx10_40.a      lib64/libd3dx10_41.a \
  lib64/libd3dx10_42.a      lib64/libd3dx10_43.a      lib64/libd3dx11_42.a \
  lib64/libd3dx11_43.a      lib64/libd3dx9_24.a       lib64/libd3dx9_25.a \
  lib64/libd3dx9_26.a       lib64/libd3dx9_27.a       lib64/libd3dx9_28.a \
  lib64/libd3dx9_29.a       lib64/libd3dx9_30.a       lib64/libd3dx9_31.a \
  lib64/libd3dx9_32.a       lib64/libd3dx9_33.a       lib64/libd3dx9_34.a \
  lib64/libd3dx9_35.a       lib64/libd3dx9_36.a       lib64/libd3dx9_37.a \
  lib64/libd3dx9_38.a       lib64/libd3dx9_39.a       lib64/libd3dx9_40.a \
  lib64/libd3dx9_41.a       lib64/libd3dx9_42.a       lib64/libd3dx9_43.a \
  lib64/libdwrite.a         lib64/libdxgi.a           lib64/libx3daudio1_2.a \
  lib64/libx3daudio1_3.a    lib64/libx3daudio1_4.a    lib64/libx3daudio1_5.a \
  lib64/libx3daudio1_6.a    lib64/libx3daudio1_7.a    lib64/libx3daudiod1_7.a \
  lib64/libxapofx1_0.a      lib64/libxapofx1_1.a      lib64/libxapofx1_2.a \
  lib64/libxapofx1_3.a      lib64/libxapofx1_4.a      lib64/libxapofx1_5.a \
  lib64/libxapofxd1_5.a     lib64/libxinput1_1.a      lib64/libxinput1_2.a \
  lib64/libxinput1_3.a      lib64/libxinput1_4.a      lib64/libxinput9_1_0.a \
  lib64/libxaudio2_8.a      lib64/libd3dcompiler_46.a lib64/libd3dcsx_46.a \
  \
  lib64/libwinhttp.a \
  lib64/libapi-ms-win-core-winrt-string-l1-1-0.a \
  lib64/libapi-ms-win-core-winrt-l1-1-0.a

if !W32API
lib64_DATA += lib64/libmsvcp60.a lib64/libmsvcr80.a lib64/libmsvcr90.a lib64/libmsvcr100.a lib64/libmsvcr90d.a lib64/libmsvcr110.a lib64/libcrtdll.a
endif

lib64/libcrtdll.a lib64/libmsvcr80.a: lib64/lib%.a: lib64/%.def
	$(DTDEF64) $< --dllname $*.dll

lib64/lib%.a: lib64/%.def
	$(DTDEF64) $<

# libvfw32.a contains import stubs for 3 dll's.  Using an MRI script
# seems to be the simplest way to combine them into one archive.
# NB: With older dlltool, the object file members will not have unique
# names.
lib64/libvfw32.a: lib64/vfw32.mri lib64/libmsvfw32.a lib64/libavifil32.a lib64/libavicap32.a
	rm -f $@
	$(AR) -M < $<
	$(RANLIB) $@

dx64_DATA =
dx64_DATA += lib64/libxinput.a
dx64_DATA += lib64/libxapofx.a
dx64_DATA += lib64/libx3daudio.a
dx64_DATA += lib64/libd3dx9.a
dx64_DATA += lib64/libd3dx10.a
dx64_DATA += lib64/libd3dx11.a
dx64_DATA += lib64/libd3dcsxd.a
dx64_DATA += lib64/libd3dcompiler.a

lib64/libxinput.a: lib64/$(xinput).def
	$(DTDEF64) $<
lib64/libxapofx.a: lib64/$(xapofx).def
	$(DTDEF64) $<
lib64/libx3daudio.a: lib64/$(x3daudio).def
	$(DTDEF64) $<
lib64/libd3dx9.a: lib64/$(d3dx9).def
	$(DTDEF64) $<
lib64/libd3dx10.a: lib64/$(d3dx10).def
	$(DTDEF64) $<
lib64/libd3dx11.a: lib64/$(d3dx11).def
	$(DTDEF64) $<
lib64/libd3dcsxd.a: lib64/$(d3dcsxd).def
	$(DTDEF64) $<
lib64/libd3dcompiler.a: lib64/$(d3dcompiler).def
	$(DTDEF64) $<

endif
# End 64-bit runtime
##########

%.def: %.def.in
	$(CPP) -x c $< -Wp,-w -I$(top_srcdir)/def-include | $(SED) 's/^#/;/' >$@

# Don't compile these, but install as is:
#
libsrcdir=$(includedir)
dist_libsrc_DATA = \
  libsrc/agtctl_i.c   libsrc/agtsvr_i.c     libsrc/cdoex_i.c    libsrc/cdoexm_i.c     \
  libsrc/cdosys_i.c   libsrc/emostore_i.c   libsrc/iisext_i.c   libsrc/mtsadmin_i.c   \
  libsrc/mtxadmin_i.c libsrc/scardssp_i.c   libsrc/scardssp_p.c libsrc/tsuserex_i.c


# Installation options
#

noinst_HEADERS = libsrc/dxerr.c \
 include/internal.h include/oscalls.h include/sect_attribs.h


# Cleaning options
#

CLEANFILES = $(BUILT_SOURCES) $(crt64_DATA) $(lib64_DATA) $(crt32_DATA) $(lib32_DATA) $(processed_defs)

# Distribution options
#

EXTRA_DIST = $(srcdir)/ChangeLog.*
EXTRA_DIST += revstamp.h \
  $(top_srcdir)/lib32/*.def \
  $(top_srcdir)/lib64/*.def \
  $(top_srcdir)/lib32/*.mri \
  $(top_srcdir)/lib64/*.mri \
  $(top_srcdir)/lib32/*.def.in \
  $(top_srcdir)/lib64/*.def.in \
  $(top_srcdir)/def-include/*.def.in \
  $(top_srcdir)/$(winrtlibs) \
  crt/binmode.c \
  crt/crtbegin.c \
  crt/crtdll.c \
  crt/crtend.c \
  crt/crtexe.c \
  crt/CRT_fp8.c \
  crt/CRT_fp10.c \
  crt/CRT_glob.c \
  crt/CRT_noglob.c \
  crt/txtmode.c \
  crt/ucrtexe.c \
  profile/gcrt0.c \
  profile/COPYING \
  profile/CYGWIN_LICENSE

EXTRA_DIST += math/DFP/mpdecimal-2.3/.hg_archival.txt \
math/DFP/mpdecimal-2.3/basearith.c \
math/DFP/mpdecimal-2.3/basearith.h \
math/DFP/mpdecimal-2.3/bench.c \
math/DFP/mpdecimal-2.3/bits.h \
math/DFP/mpdecimal-2.3/cdecimal2.c \
math/DFP/mpdecimal-2.3/cdecimal3.c \
math/DFP/mpdecimal-2.3/CHANGELOG.txt \
math/DFP/mpdecimal-2.3/cmd/compare.c \
math/DFP/mpdecimal-2.3/cmd/div.c \
math/DFP/mpdecimal-2.3/cmd/divmod.c \
math/DFP/mpdecimal-2.3/cmd/multiply.c \
math/DFP/mpdecimal-2.3/cmd/pow.c \
math/DFP/mpdecimal-2.3/cmd/powmod.c \
math/DFP/mpdecimal-2.3/cmd/README.txt \
math/DFP/mpdecimal-2.3/cmd/shift.c \
math/DFP/mpdecimal-2.3/cmd/sqrt.c \
math/DFP/mpdecimal-2.3/config.h.in \
math/DFP/mpdecimal-2.3/configure \
math/DFP/mpdecimal-2.3/configure.in \
math/DFP/mpdecimal-2.3/constants.c \
math/DFP/mpdecimal-2.3/constants.h \
math/DFP/mpdecimal-2.3/context.c \
math/DFP/mpdecimal-2.3/convolute.c \
math/DFP/mpdecimal-2.3/convolute.h \
math/DFP/mpdecimal-2.3/crt.c \
math/DFP/mpdecimal-2.3/crt.h \
math/DFP/mpdecimal-2.3/difradix2.c \
math/DFP/mpdecimal-2.3/difradix2.h \
math/DFP/mpdecimal-2.3/doc/cdecimal/index.html \
math/DFP/mpdecimal-2.3/doc/index.html \
math/DFP/mpdecimal-2.3/doc/libmpdec/arithmetic.html \
math/DFP/mpdecimal-2.3/doc/libmpdec/assign-convert.html \
math/DFP/mpdecimal-2.3/doc/libmpdec/attributes.html \
math/DFP/mpdecimal-2.3/doc/libmpdec/context.html \
math/DFP/mpdecimal-2.3/doc/libmpdec/decimals.html \
math/DFP/mpdecimal-2.3/doc/libmpdec/functions.html \
math/DFP/mpdecimal-2.3/doc/libmpdec/index.html \
math/DFP/mpdecimal-2.3/doc/libmpdec/memory.html \
math/DFP/mpdecimal-2.3/doc/libmpdec/various.html \
math/DFP/mpdecimal-2.3/doc/LICENSE.txt \
math/DFP/mpdecimal-2.3/doc/objects.inv \
math/DFP/mpdecimal-2.3/doc/search.html \
math/DFP/mpdecimal-2.3/doc/searchindex.js \
math/DFP/mpdecimal-2.3/doc/_static/basic.css \
math/DFP/mpdecimal-2.3/doc/_static/default.css \
math/DFP/mpdecimal-2.3/doc/_static/doctools.js \
math/DFP/mpdecimal-2.3/doc/_static/file.png \
math/DFP/mpdecimal-2.3/doc/_static/jquery.js \
math/DFP/mpdecimal-2.3/doc/_static/minus.png \
math/DFP/mpdecimal-2.3/doc/_static/mpdecimal-doc.css \
math/DFP/mpdecimal-2.3/doc/_static/plus.png \
math/DFP/mpdecimal-2.3/doc/_static/pygments.css \
math/DFP/mpdecimal-2.3/doc/_static/searchtools.js \
math/DFP/mpdecimal-2.3/doc/_static/sidebar.js \
math/DFP/mpdecimal-2.3/doc/_static/underscore.js \
math/DFP/mpdecimal-2.3/docstrings.h \
math/DFP/mpdecimal-2.3/fnt.c \
math/DFP/mpdecimal-2.3/fnt.h \
math/DFP/mpdecimal-2.3/fourstep.c \
math/DFP/mpdecimal-2.3/fourstep.h \
math/DFP/mpdecimal-2.3/io.c \
math/DFP/mpdecimal-2.3/io.h \
math/DFP/mpdecimal-2.3/LIBINSTALL.txt \
math/DFP/mpdecimal-2.3/LICENSE.txt \
math/DFP/mpdecimal-2.3/literature/mpdecimal.lisp \
math/DFP/mpdecimal-2.3/literature/README.txt \
math/DFP/mpdecimal-2.3/literature/umodarith.lisp \
math/DFP/mpdecimal-2.3/Makefile.in \
math/DFP/mpdecimal-2.3/Makefile.vc \
math/DFP/mpdecimal-2.3/memory.c \
math/DFP/mpdecimal-2.3/memory.h \
math/DFP/mpdecimal-2.3/mpdecimal-i686.h \
math/DFP/mpdecimal-2.3/mpdecimal-x86_64.h \
math/DFP/mpdecimal-2.3/mpdecimal.c \
math/DFP/mpdecimal-2.3/mpdecimal.h.in \
math/DFP/mpdecimal-2.3/mpdecimal32vc.h \
math/DFP/mpdecimal-2.3/mpdecimal64vc.h \
math/DFP/mpdecimal-2.3/mpsignal.c \
math/DFP/mpdecimal-2.3/mptest.h \
math/DFP/mpdecimal-2.3/mptypes.h \
math/DFP/mpdecimal-2.3/numbertheory.c \
math/DFP/mpdecimal-2.3/numbertheory.h \
math/DFP/mpdecimal-2.3/PKG-INFO \
math/DFP/mpdecimal-2.3/PYINSTALL.txt \
math/DFP/mpdecimal-2.3/python/Bench.class \
math/DFP/mpdecimal-2.3/python/Bench.java \
math/DFP/mpdecimal-2.3/python/bench.py \
math/DFP/mpdecimal-2.3/python/BENCHMARK.txt \
math/DFP/mpdecimal-2.3/python/build_all_branches.bat \
math/DFP/mpdecimal-2.3/python/build_all_branches.sh \
math/DFP/mpdecimal-2.3/python/build_all_releases.sh \
math/DFP/mpdecimal-2.3/python/ctx-deccheck2.py \
math/DFP/mpdecimal-2.3/python/deccheck2.py \
math/DFP/mpdecimal-2.3/python/deccheck3.py \
math/DFP/mpdecimal-2.3/python/failapi2.diff \
math/DFP/mpdecimal-2.3/python/failapi3.diff \
math/DFP/mpdecimal-2.3/python/formathelper.py \
math/DFP/mpdecimal-2.3/python/genlocale.py \
math/DFP/mpdecimal-2.3/python/genrandformat.py \
math/DFP/mpdecimal-2.3/python/genrandlocale.py \
math/DFP/mpdecimal-2.3/python/gettests.bat \
math/DFP/mpdecimal-2.3/python/gettests.sh \
math/DFP/mpdecimal-2.3/python/get_all_branches.bat \
math/DFP/mpdecimal-2.3/python/get_all_branches.sh \
math/DFP/mpdecimal-2.3/python/get_all_releases.sh \
math/DFP/mpdecimal-2.3/python/randdec.py \
math/DFP/mpdecimal-2.3/python/randfloat.py \
math/DFP/mpdecimal-2.3/python/README.txt \
math/DFP/mpdecimal-2.3/python/runall-amd64.bat \
math/DFP/mpdecimal-2.3/python/runall-memorydebugger.sh \
math/DFP/mpdecimal-2.3/python/runall-refleak.bat \
math/DFP/mpdecimal-2.3/python/runall-releases.sh \
math/DFP/mpdecimal-2.3/python/runall-x86.bat \
math/DFP/mpdecimal-2.3/python/runall.sh \
math/DFP/mpdecimal-2.3/python/test_cdecimal2.5.py \
math/DFP/mpdecimal-2.3/python/test_cdecimal2.py \
math/DFP/mpdecimal-2.3/python/test_cdecimal3.py \
math/DFP/mpdecimal-2.3/python/valgrind.supp \
math/DFP/mpdecimal-2.3/README.txt \
math/DFP/mpdecimal-2.3/setup.py \
math/DFP/mpdecimal-2.3/sixstep.c \
math/DFP/mpdecimal-2.3/sixstep.h \
math/DFP/mpdecimal-2.3/tests/additional.decTest \
math/DFP/mpdecimal-2.3/tests/cov.c \
math/DFP/mpdecimal-2.3/tests/covreport.py \
math/DFP/mpdecimal-2.3/tests/deccheck.c \
math/DFP/mpdecimal-2.3/tests/dnloop-windows.patch \
math/DFP/mpdecimal-2.3/tests/dnloop.patch \
math/DFP/mpdecimal-2.3/tests/fntcov.c \
math/DFP/mpdecimal-2.3/tests/fullcov_header.patch \
math/DFP/mpdecimal-2.3/tests/getdn.bat \
math/DFP/mpdecimal-2.3/tests/getdn.sh \
math/DFP/mpdecimal-2.3/tests/gettests.bat \
math/DFP/mpdecimal-2.3/tests/gettests.sh \
math/DFP/mpdecimal-2.3/tests/karatsuba_fnt.c \
math/DFP/mpdecimal-2.3/tests/karatsuba_fnt2.c \
math/DFP/mpdecimal-2.3/tests/Makefile.in \
math/DFP/mpdecimal-2.3/tests/Makefile.vc \
math/DFP/mpdecimal-2.3/tests/malloc_fail.c \
math/DFP/mpdecimal-2.3/tests/malloc_fail.h \
math/DFP/mpdecimal-2.3/tests/mpd_mpz_add.c \
math/DFP/mpdecimal-2.3/tests/mpd_mpz_divmod.c \
math/DFP/mpdecimal-2.3/tests/mpd_mpz_mul.c \
math/DFP/mpdecimal-2.3/tests/mpd_mpz_sub.c \
math/DFP/mpdecimal-2.3/tests/official.decTest \
math/DFP/mpdecimal-2.3/tests/ppro_mulmod.c \
math/DFP/mpdecimal-2.3/tests/README.txt \
math/DFP/mpdecimal-2.3/tests/runallconfigs.bat \
math/DFP/mpdecimal-2.3/tests/runallconfigs.sh \
math/DFP/mpdecimal-2.3/tests/runalltests.bat \
math/DFP/mpdecimal-2.3/tests/runalltests.sh \
math/DFP/mpdecimal-2.3/tests/runshort.bat \
math/DFP/mpdecimal-2.3/tests/runshort.sh \
math/DFP/mpdecimal-2.3/tests/runtest.c \
math/DFP/mpdecimal-2.3/tests/testdata_dist/baseconv.decTest \
math/DFP/mpdecimal-2.3/tests/testdata_dist/binop_eq.decTest \
math/DFP/mpdecimal-2.3/tests/testdata_dist/cov.decTest \
math/DFP/mpdecimal-2.3/tests/testdata_dist/divmod.decTest \
math/DFP/mpdecimal-2.3/tests/testdata_dist/divmod_eq.decTest \
math/DFP/mpdecimal-2.3/tests/testdata_dist/extra.decTest \
math/DFP/mpdecimal-2.3/tests/testdata_dist/fma_eq.decTest \
math/DFP/mpdecimal-2.3/tests/testdata_dist/format.decTest \
math/DFP/mpdecimal-2.3/tests/testdata_dist/getint.decTest \
math/DFP/mpdecimal-2.3/tests/testdata_dist/invroot.decTest \
math/DFP/mpdecimal-2.3/tests/testdata_dist/largeint.decTest \
math/DFP/mpdecimal-2.3/tests/testdata_dist/powmod.decTest \
math/DFP/mpdecimal-2.3/tests/testdata_dist/powmod_eq.decTest \
math/DFP/mpdecimal-2.3/tests/testdata_dist/shiftlr.decTest \
math/DFP/mpdecimal-2.3/tests/testdata_dist/testruntest.decTest \
math/DFP/mpdecimal-2.3/tests/test_transpose.c \
math/DFP/mpdecimal-2.3/tools/release.sh \
math/DFP/mpdecimal-2.3/tools/replace.sh \
math/DFP/mpdecimal-2.3/tools/todos.sh \
math/DFP/mpdecimal-2.3/transpose.c \
math/DFP/mpdecimal-2.3/transpose.h \
math/DFP/mpdecimal-2.3/typearith.h \
math/DFP/mpdecimal-2.3/umodarith.h \
math/DFP/mpdecimal-2.3/vars.mk \
math/DFP/mpdecimal-2.3/vccompat.h \
math/DFP/mpdecimal-2.3/vcdiv64.asm \
math/DFP/mpdecimal-2.3/vcstdint.h

DISTCHECK_CONFIGURE_FLAGS = --host=$(host_triplet) $(withsys)

dist-hook:
	find $(top_distdir) -name ".svn" -delete

# Testsuite options
#

#old
#  testcases/tstwassert_win \
#  testcases/tstwinmain \
#  testcases/tstwassert \
#  testcases_tstwinmain_LDADD = -lgdi32

testcase_progs = \
  testcases/tstmainc \
  testcases/tstmaincpp \
  testcases/tstmain_sys_xxx \
  testcases/t_ansi_io \
  testcases/t_findfirst \
  testcases/t_float  \
  testcases/t_fstat \
  testcases/t_intrinc \
  testcases/t_imagebase \
  testcases/t_matherr \
  testcases/t_nullptrexception \
  testcases/t_readdir \
  testcases/t_setjmp \
  testcases/t_sigv \
  testcases/t_speed_powl \
  testcases/t_stat \
  testcases/t_stdint \
  testcases/t_time \
  testcases/t_tls1 \
  testcases/t_trycatch \
  testcases/t_stat_slash \
  testcases/t_wreaddir \
  testcases/t_fseeko64

testcases_tstmaincpp_SOURCES = testcases/tstmaincpp.cpp
testcases_t_trycatch_SOURCES = testcases/t_trycatch.cpp
testcases_t_intrinc_CFLAGS = -std=c99

if ENABLE_TESTS_UNICODE
  testcase_progs += testcases/t_municode testcases/t_tmain
  testcases_t_municode_CFLAGS = -municode
  testcases_t_tmain_CFLAGS = -municode -D_UNICODE
endif

# Do not specify TESTS = check_PROGRAMS, because some TESTS
# may not be check_PROGRAMS.
check_LIBRARIES =
check_PROGRAMS = $(testcase_progs)
TESTS = $(testcase_progs)
XFAIL_TESTS = \
  testcases/t_nullptrexception

# Include the complex math testcase fragment.
include testcases/complex/Makefile.am
