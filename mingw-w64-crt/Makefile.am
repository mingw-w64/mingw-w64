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
  sysincludes="-I@TARGET_SYSTEM_ROOT@/include"
  withsys="--with-sysroot=@TARGET_SYSTEM_ROOT@"
else
  sysincludes=
  withsys=
endif

AM_CPPFLAGS=$(sysincludes)
AM_CFLAGS=-pipe -std=gnu99 -fno-builtin -D_CRTBLD -D_WIN32_WINNT=0x0f00 -D__MSVCRT_VERSION__=0x600 -D__USE_MINGW_ANSI_STDIO=0 @IMAGEBASE_CFLAGS@ @CFGUARD_CFLAGS@ @ADD_C_CXX_WARNING_FLAGS@ @ADD_C_ONLY_WARNING_FLAGS@
AM_CXXFLAGS=@ADD_C_CXX_WARNING_FLAGS@ @ADD_CXX_ONLY_WARNING_FLAGS@
AM_CCASFLAGS=@CFGUARD_CFLAGS@
CPPFLAGSARM32=-mfpu=vfpv3
CPPFLAGS32=-m32 -masm=att
CPPFLAGS64=-m64 -masm=att
AM_DLLTOOLFLAGS=-k --as=$(AS) --output-lib $@
DLLTOOLFLAGSARM32=-m arm
if ARM64EC
    DLLTOOLFLAGSARM64=-m arm64ec
else
    DLLTOOLFLAGSARM64=-m arm64
endif
DLLTOOLFLAGS32=--as-flags=--32 -m i386
DLLTOOLFLAGS64=--as-flags=--64 -m i386:x86-64
DTDEFARM32=$(DLLTOOL) $(DLLTOOLFLAGSARM32) $(AM_DLLTOOLFLAGS) --input-def
DTDEFARM64=$(DLLTOOL) $(DLLTOOLFLAGSARM64) $(AM_DLLTOOLFLAGS) --input-def
DTDEF32=$(DLLTOOL) $(DLLTOOLFLAGS32) $(AM_DLLTOOLFLAGS) --input-def
DTDEF64=$(DLLTOOL) $(DLLTOOLFLAGS64) $(AM_DLLTOOLFLAGS) --input-def
if DLLTOOL_HAS_TEMP_PREFIX
  AM_DLLTOOLFLAGS += --temp-prefix $(basename $@)
endif
if DELAY_IMPORT_LIBS
  AM_DLLTOOLFLAGS += --output-delaylib $@.delayimp.a
endif
DTLIBARM32=$(DTDEFARM32) $(top_srcdir)/`echo $@ | $(SED) 's|/lib|/|;s|\.a|.def|'`
DTLIBARM64=$(DTDEFARM64) $(top_srcdir)/`echo $@ | $(SED) 's|/lib|/|;s|\.a|.def|'`
DTLIB32=$(DTDEF32) $(top_srcdir)/`echo $@ | $(SED) 's|/lib|/|;s|\.a|.def|'`
DTLIB64=$(DTDEF64) $(top_srcdir)/`echo $@ | $(SED) 's|/lib|/|;s|\.a|.def|'`
LDFLAGSARM32= -L$(top_builddir)/libarm32
LDFLAGSARM64= -L$(top_builddir)/libarm64
LDFLAGS32=-m32 -L$(top_builddir)/lib32
LDFLAGS64=-m64 -L$(top_builddir)/lib64
extra_include=-I$(top_srcdir)/include
processed_defs=

noinst_LIBRARIES =

# default directx import library names
xinput=xinput1_3
xapofx=xapofx1_5
x3daudio=x3daudio1_7
d3dx9=d3dx9_43
d3dx10=d3dx10_43
d3dx11=d3dx11_43
d3dcsxd=d3dcsxd_43
d3dcompiler=d3dcompiler_47

# can move this into libsrc/dummy_libm.c or similar
BUILT_SOURCES = _libm_dummy.c
_libm_dummy.c:
	$(AM_V_GEN)echo "static int __attribute__((unused)) __mingw_libm_dummy;" > _libm_dummy.c

src_libm=_libm_dummy.c

if ENABLE_DFP
src_dfp_math = \
math/DFP/__fpclassifyd32.c math/DFP/__fpclassifyd64.c math/DFP/__fpclassifyd128.c \
math/DFP/__isnand32.c math/DFP/__isnand64.c math/DFP/__isnand128.c \
math/DFP/__signbitd32.c math/DFP/__signbitd64.c math/DFP/__signbitd128.c \
math/DFP/isinfd32.c math/DFP/isinfd64.c math/DFP/isinfd128.c

else
src_dfp_math =

endif

src_libbits=libsrc/bits.c
src_libshell32=libsrc/shell32.c
src_libdinput=libsrc/dinput_kbd.c libsrc/dinput_joy.c libsrc/dinput_joy2.c libsrc/dinput_mouse.c libsrc/dinput_mouse2.c
src_libdinput8=libsrc/dinput_private.h libsrc/dinput_joy.c libsrc/dinput_joy2.c libsrc/dinput_mouse.c libsrc/dinput_mouse2.c libsrc/dinput_kbd.c
src_libdmoguids=libsrc/dmoguids.c
src_libdxerr8=libsrc/dxerr8.c libsrc/dxerr8w.c
src_libdxerr9=libsrc/dxerr9.c libsrc/dxerr9w.c
src_libmfuuid=libsrc/mfuuid.c
src_libmsxml2=libsrc/msxml2.c
src_libmsxml6=libsrc/msxml6.c
src_libamstrmid=libsrc/amstrmid.c
src_libwbemuuid=libsrc/wbemuuid.c
src_libwmcodecdspuuid=libsrc/wmcodecdspuuid.c
src_libwindowscodecs=libsrc/windowscodecs.c
src_libdxguid=libsrc/dxguid.c
src_libksuser=libsrc/ksuser.c
src_libksguid=libsrc/ksuser.c
src_liblargeint=libsrc/largeint.c
src_liblocationapi=libsrc/locationapi.c
src_libsapi=libsrc/sapi.c
src_libsensorsapi=libsrc/sensorsapi.c
src_libportabledeviceguids=libsrc/portabledeviceguids.c
src_libtaskschd=libsrc/taskschd.c
src_libntoskrnl=libsrc/memcmp.c
src_libdloadhelper=libsrc/dloadhelper.c misc/delay-f.c

src_libmingw32=include/oscalls.h include/internal.h include/sect_attribs.h \
  crt/crtexewin.c     crt/dll_argv.c  crt/gccmain.c     crt/natstart.c  crt/pseudo-reloc-list.c  crt/wildcard.c \
  crt/charmax.c       crt/ucrtexewin.c crt/dllargv.c    crt/_newmode.c  crt/tlssup.c             crt/xncommod.c \
  crt/cinitexe.c      crt/merr.c      crt/pesect.c      crt/udllargc.c  crt/xthdloc.c \
  crt/mingw_custom.c  crt/mingw_helpers.c  \
  crt/pseudo-reloc.c  crt/udll_argv.c      \
  crt/usermatherr.c   \
  crt/xtxtmode.c      crt/crt_handler.c    \
  crt/tlsthrd.c       crt/tlsmthread.c     crt/tlsmcrt.c   \
  crt/cxa_atexit.c    crt/cxa_thread_atexit.c crt/tls_atexit.c

src_libscrnsave=libsrc/scrnsave.c
src_libscrnsavw=libsrc/scrnsave.c
src_libstrmiids=libsrc/strmiids.c
src_libmingwthrd=libsrc/mingwthrd_mt.c

src_libgdiplus=libsrc/gdiplus.c

src_adsiid=libsrc/activeds-uuid.c

src_libuuid=\
  libsrc/ativscp-uuid.c   libsrc/atsmedia-uuid.c    libsrc/bth-uuid.c         libsrc/cguid-uuid.c     libsrc/comcat-uuid.c   \
  libsrc/ctxtcall-uuid.c \
  libsrc/devguid.c        libsrc/docobj-uuid.c      libsrc/dxva-uuid.c        libsrc/exdisp-uuid.c    libsrc/extras-uuid.c   \
  libsrc/fwp-uuid.c       libsrc/guid_nul.c         libsrc/hlguids-uuid.c     libsrc/hlink-uuid.c     libsrc/mlang-uuid.c    \
  libsrc/msctf-uuid.c     libsrc/mshtmhst-uuid.c    libsrc/mshtml-uuid.c      libsrc/msxml-uuid.c     libsrc/netcfg-uuid.c   \
  libsrc/netcon-uuid.c    libsrc/ntddkbd-uuid.c     libsrc/ntddmou-uuid.c     libsrc/ntddpar-uuid.c   libsrc/ntddscsi-uuid.c \
  libsrc/ntddser-uuid.c   libsrc/ntddstor-uuid.c    libsrc/ntddvdeo-uuid.c    libsrc/oaidl-uuid.c     libsrc/objidl-uuid.c   \
  libsrc/objsafe-uuid.c   libsrc/ocidl-uuid.c       libsrc/oleacc-uuid.c      libsrc/olectlid-uuid.c  libsrc/oleidl-uuid.c   \
  libsrc/power-uuid.c     libsrc/powrprof-uuid.c    libsrc/uianimation-uuid.c libsrc/usbcamdi-uuid.c  libsrc/usbiodef-uuid.c \
  libsrc/uuid.c           libsrc/vds-uuid.c         libsrc/virtdisk-uuid.c    libsrc/vss-uuid.c       libsrc/wia-uuid.c \
  libsrc/windowscodecs.c

src_libwiaguid = libsrc/wia-uuid.c

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

# Files included in all libmsvcr*.a
src_msvcrt_common=\
  misc/_onexit.c \
  misc/mbsinit.c \
  misc/onexit_table.c \
  misc/register_tls_atexit.c \
  stdio/_getc_nolock.c \
  stdio/_getwc_nolock.c \
  stdio/_putc_nolock.c \
  stdio/_putwc_nolock.c \
  stdio/_strtof_l.c \
  stdio/_wcstof_l.c \
  stdio/acrt_iob_func.c \
  stdio/strtof.c \
  stdio/snprintf_alias.c \
  stdio/snwprintf_alias.c \
  stdio/swprintf.c \
  stdio/swprintf_alias.c \
  stdio/vsnprintf_alias.c \
  stdio/vsnwprintf_alias.c \
  stdio/vswprintf.c \
  stdio/vswprintf_alias.c \
  stdio/stat32i64.c \
  stdio/stat64.c \
  stdio/wstat32i64.c \
  stdio/wstat64.c \
  math/cbrt.c math/cbrtf.c \
  math/copysign.c math/copysignf.c \
  math/coshf.c \
  math/expf.c \
  math/fabs.c math/fabsf.c \
  math/fdim.c math/fdimf.c \
  math/fma.c math/fmaf.c \
  math/fmax.c math/fmaxf.c \
  math/fmin.c math/fminf.c \
  math/frexp.c \
  math/hypot.c \
  math/llrint.c math/llrintf.c \
  math/llround.c math/llroundf.c \
  math/log10f.c \
  math/logf.c \
  math/lrint.c math/lrintf.c \
  math/lround.c math/lroundf.c \
  math/modf.c math/modff.c \
  math/nextafterf.c math/nextafterl.c \
  math/nexttoward.c math/nexttowardf.c \
  math/powf.c \
  math/round.c math/roundf.c \
  math/s_erf.c math/sf_erf.c \
  math/sinhf.c \
  math/sqrt.c math/sqrtf.c \
  math/tanhf.c \
  math/tgamma.c math/tgammaf.c

# Arch specific files included in all libmsvcr*.a on x86
src_msvcrt_common_add_x86=\
  math/x86/acosh.c math/x86/acoshf.c \
  math/x86/asinh.c math/x86/asinhf.c \
  math/x86/atan2.c \
  math/x86/atanh.c math/x86/atanhf.c \
  math/x86/ceil.S \
  math/x86/cos.c \
  math/x86/cossin.c \
  math/x86/exp.c \
  math/x86/exp2.S math/x86/exp2f.S \
  math/x86/expm1.c math/x86/expm1f.c \
  math/x86/floor.S \
  math/x86/fmod.c \
  math/x86/ilogb.S math/x86/ilogbf.S \
  math/x86/log.c \
  math/x86/log1p.S math/x86/log1pf.S \
  math/x86/log2.S math/x86/log2f.S \
  math/x86/logb.c math/x86/logbf.c \
  math/x86/nearbyint.S math/x86/nearbyintf.S \
  math/x86/pow.c \
  math/x86/remainder.S math/x86/remainderf.S \
  math/x86/remquo.S math/x86/remquof.S \
  math/x86/rint.c math/x86/rintf.c \
  math/x86/sin.c \
  math/x86/trunc.S math/x86/truncf.S \
  \
  math/x86/acosf.c \
  math/x86/asinf.c \
  math/x86/atan2f.c \
  math/x86/atanf.c \
  math/x86/ceilf.S \
  math/x86/cosf.c \
  math/x86/floorf.S \
  math/x86/fmodf.c \
  math/x86/sinf.c \
  math/x86/tanf.c

# Arch specific files included in all libmsvcr*.a on x86_32
src_msvcrt_common_add_x86_32=\
  $(src_msvcrt_common_add_x86)

# Arch specific files included in all libmsvcr*.a on x86_64
src_msvcrt_common_add_x86_64=\
  $(src_msvcrt_common_add_x86)

# Arch specific files included in all libmsvcr*.a on arm
src_msvcrt_common_add_arm=\
  math/cbrtl.c \
  math/erfl.c \
  math/fdiml.c \
  math/fmal.c \
  math/fmaxl.c \
  math/fminl.c \
  math/llrintl.c \
  math/llroundl.c \
  math/lrintl.c \
  math/lroundl.c \
  math/rintl.c \
  math/roundl.c \
  math/tgammal.c \
  math/truncl.c

# Arch specific files included in all libmsvcr*.a on arm32
src_msvcrt_common_add_arm32=\
  $(src_msvcrt_common_add_arm)

# Arch specific files included in all libmsvcr*.a on arm64
src_msvcrt_common_add_arm64=\
  $(src_msvcrt_common_add_arm)

# Files included in all libmsvcr*.a on x86_32
src_msvcrt_common32=\
  $(src_msvcrt_common) \
  $(src_msvcrt_common_add_x86_32)

# Files included in all libmsvcr*.a on x86_64
src_msvcrt_common64=\
  $(src_msvcrt_common) \
  $(src_msvcrt_common_add_x86_64)

# Files included in all libmsvcr*.a on arm32
src_msvcrt_commonarm32=\
  $(src_msvcrt_common) \
  $(src_msvcrt_common_add_arm32)

# Files included in all libmsvcr*.a on arm64
src_msvcrt_commonarm64=\
  $(src_msvcrt_common) \
  $(src_msvcrt_common_add_arm64)

src_msvcrt_add_vscanf=\
  stdio/scanf2-argcount-char.c \
  stdio/scanf2-argcount-wchar.c \
  stdio/vfscanf.c \
  stdio/vfwscanf.c \
  stdio/vscanf.c \
  stdio/vsscanf.c \
  stdio/vswscanf.c \
  stdio/vwscanf.c

# Files included in libmsvcrt-os.a (for msvcrt.dll) on all archs
src_msvcrt=\
  $(src_msvcrt_add_vscanf) \
  misc/__iswcsym.c \
  misc/__iswcsymf.c \
  misc/__sys_errlist.c \
  misc/__sys_nerr.c \
  misc/_aligned_msize.c \
  misc/_aligned_offset_recalloc.c \
  misc/_aligned_recalloc.c \
  misc/_configthreadlocale.c \
  misc/_recalloc.c \
  misc/_set_purecall_handler.c \
  misc/imaxdiv.c \
  misc/invalid_parameter_handler.c \
  misc/isblank.c \
  misc/iswblank.c \
  misc/_isblank_l.c \
  misc/_iswblank_l.c \
  misc/wctrans.c \
  misc/wctype.c \
  secapi/_vscprintf_p.c \
  secapi/_vscwprintf_p.c \
  secapi/_vswprintf_p.c \
  secapi/wmemcpy_s.c \
  secapi/wmemmove_s.c \
  stdio/_ftelli64.c \
  stdio/mingw_lock.c \
  stdio/msvcr110pre_stat32.c \
  stdio/msvcr110pre_stat64i32.c \
  stdio/msvcr110pre_wstat32.c \
  stdio/msvcr110pre_wstat64i32.c

src_msvcrt_add_x86=\
  secapi/_access_s.c \
  secapi/_cgets_s.c \
  secapi/_cgetws_s.c \
  secapi/_chsize_s.c \
  secapi/_controlfp_s.c \
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
  secapi/_sopen_s.c \
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
  secapi/_wmktemp_s.c \
  secapi/_wstrdate_s.c \
  secapi/_wstrtime_s.c \
  secapi/asctime_s.c \
  secapi/memcpy_s.c \
  secapi/memmove_s.c \
  secapi/rand_s.c \
  secapi/sprintf_s.c \
  secapi/strerror_s.c \
  secapi/vsprintf_s.c \
  stdio/scanf.S

# Files included in libucrt*.a
src_ucrtbase=\
  misc/ucrt__getmainargs.c \
  misc/ucrt__wgetmainargs.c \
  misc/ucrt_amsg_exit.c \
  misc/ucrt_at_quick_exit.c \
  misc/ucrt_tzset.c \
  math/_huge.c \
  misc/__badioinfo.c \
  misc/__p___initenv.c \
  misc/__p___winitenv.c \
  misc/__p__osplatform_emul.c \
  misc/__p__osver_emul.c \
  misc/__initenv.c \
  misc/__winitenv.c \
  misc/_onexit.c \
  misc/output_format.c \
  misc/ucrt-access.c \
  stdio/ucrt___local_stdio_printf_options.c \
  stdio/ucrt___local_stdio_scanf_options.c \
  stdio/ucrt__scprintf.c \
  stdio/ucrt__scwprintf.c \
  stdio/ucrt__snprintf.c \
  stdio/ucrt__snscanf.c \
  stdio/ucrt__snwprintf.c \
  stdio/ucrt__swprintf.c \
  stdio/ucrt__vscprintf.c \
  stdio/ucrt__vscwprintf.c \
  stdio/ucrt__vsnprintf.c \
  stdio/ucrt__vsnwprintf.c \
  stdio/ucrt__vswprintf.c \
  stdio/ucrt_fprintf.c \
  stdio/ucrt_fscanf.c \
  stdio/ucrt_fwprintf.c \
  stdio/ucrt_fwscanf.c \
  stdio/ucrt_ms_fwprintf.c \
  stdio/ucrt_printf.c \
  stdio/ucrt_scanf.c \
  stdio/ucrt_snprintf.c \
  stdio/ucrt_snwprintf.c \
  stdio/ucrt_sprintf.c \
  stdio/ucrt_sscanf.c \
  stdio/ucrt_swprintf.c \
  stdio/ucrt_swscanf.c \
  stdio/ucrt_vfprintf.c \
  stdio/ucrt_vfscanf.c \
  stdio/ucrt_vfwprintf.c \
  stdio/ucrt_vfwscanf.c \
  stdio/ucrt_vprintf.c \
  stdio/ucrt_vscanf.c \
  stdio/ucrt_vsnprintf.c \
  stdio/ucrt_vsnwprintf.c \
  stdio/ucrt_vsprintf.c \
  stdio/ucrt_vswprintf.c \
  stdio/ucrt_vsscanf.c \
  stdio/ucrt_vswscanf.c \
  stdio/ucrt_vwprintf.c \
  stdio/ucrt_vwscanf.c \
  stdio/ucrt_wprintf.c \
  stdio/ucrt_wscanf.c \
  string/ucrt__wcstok.c

# Files included in libucrtapp.a
src_ucrtapp=\
  misc/__C_specific_handler.c \
  misc/longjmp.S \
  misc/setjmp.S \
  string/memchr.c \
  string/memcmp.c \
  string/memcpy.c \
  string/memmove.c \
  string/memrchr.c \
  string/strchr.c \
  string/strchrnul.c \
  string/strrchr.c \
  string/strstr.c \
  string/wcschr.c \
  string/wcsrchr.c \
  string/wcsstr.c

if ARM64EC
src_ucrtapp_arm64=\
  misc/arm64ec/longjmp.c \
  misc/arm64ec/setjmp.c
endif

# Files included in libucrt*.a on x86_32
src_ucrtbase32=\
  $(src_ucrtbase) \
  math/fabsf.c \
  math/nextafterl.c \
  math/nexttoward.c math/nexttowardf.c \
  math/coshf.c \
  math/expf.c \
  math/log10f.c \
  math/logf.c \
  math/modff.c \
  math/powf.c \
  math/sincos.c \
  math/sincosf.c \
  math/sinhf.c \
  math/sqrtf.c \
  math/tanhf.c \
  math/x86/acosf.c \
  math/x86/asinf.c \
  math/x86/atan2f.c \
  math/x86/atanf.c \
  math/x86/ceilf.S \
  math/x86/cosf.c \
  math/x86/floorf.S \
  math/x86/fmodf.c \
  math/x86/sinf.c \
  math/x86/tanf.c

# Files included in libucrt*.a on x86_64
src_ucrtbase64=\
  $(src_ucrtbase) \
  math/fabsf.c \
  math/nextafterl.c \
  math/nexttoward.c math/nexttowardf.c \
  math/sincos.c \
  math/sincosf.c

# Files included in libucrt*.a on arm32
src_ucrtbasearm32=\
  $(src_ucrtbase)

# Files included in libucrt*.a on arm64
src_ucrtbasearm64=\
  $(src_ucrtbase)

if ARM64EC
src_ucrtbasearm64+=math/fabsf.c
endif

# Files included in libmsvcrt-os.a (for msvcrt.dll) on x86_32
src_msvcrt32=\
  $(src_msvcrt) \
  $(src_msvcrt_add_x86) \
  misc/msvcrt__getmainargs.c \
  misc/msvcrt__wgetmainargs.c \
  math/i386__copysignf.c \
  misc/___mb_cur_max_func.c \
  misc/__p__osplatform.c \
  misc/__pctype_func.c \
  misc/__pwctype_func.c \
  misc/_aligned_free.c \
  misc/_aligned_malloc.c \
  misc/_aligned_offset_malloc.c \
  misc/_aligned_offset_realloc.c \
  misc/_aligned_realloc.c \
  misc/_create_locale.c \
  misc/_free_locale.c \
  misc/_get_current_locale.c \
  misc/_initterm_e.c \
  misc/_time64.c \
  misc/btowc.c \
  misc/imaxabs.c \
  misc/lc_locale_func.c \
  misc/mbrtowc.c \
  misc/output_format.c \
  misc/_get_errno.c \
  misc/_set_errno.c \
  misc/strnlen.c \
  misc/strtoimax.c \
  misc/strtoumax.c \
  misc/wassert.c \
  misc/wcrtomb.c \
  misc/wcsnlen.c \
  misc/wcstoimax.c \
  misc/wcstoumax.c \
  misc/wctob.c \
  stdio/_fseeki64.c \
  stdio/_fstat64.c \
  stdio/_fstat64i32.c \
  stdio/_scprintf.c \
  stdio/_scwprintf.c \
  stdio/_stat64.c \
  stdio/_stat64i32.c \
  stdio/_vscprintf.c \
  stdio/_vscwprintf.c \
  stdio/_wstat64.c \
  stdio/_wstat64i32.c \
  string/wcstok.c

# Files included in libmsvcrt-os.a (for msvcrt.dll) on x86_64
src_msvcrt64=\
  $(src_msvcrt) \
  $(src_msvcrt_add_x86) \
  misc/__daylight.c \
  misc/__dstbias.c \
  misc/__p___argc.c \
  misc/__p___argv.c \
  misc/__p___wargv.c \
  misc/__p___mb_cur_max.c \
  misc/__p___initenv.c \
  misc/__p___winitenv.c \
  misc/__p__acmdln.c \
  misc/__p__commode.c \
  misc/__p__environ.c \
  misc/__p__fmode.c \
  misc/__p__mbcasemap.c \
  misc/__p__mbctype.c \
  misc/__p__osplatform.c \
  misc/__p__osver.c \
  misc/__p__pctype.c \
  misc/__p__pgmptr.c \
  misc/__p__pwctype.c \
  misc/__p__wcmdln.c \
  misc/__p__wenviron.c \
  misc/__p__winmajor.c \
  misc/__p__winminor.c \
  misc/__p__winver.c \
  misc/__p__wpgmptr.c \
  misc/__timezone.c \
  misc/__tzname.c \
  misc/_create_locale.c \
  misc/_free_locale.c \
  misc/_get_current_locale.c \
  misc/_initterm_e.c \
  misc/btowc.c \
  misc/mbrtowc.c \
  misc/output_format.c \
  misc/_get_errno.c \
  misc/_set_errno.c \
  misc/strnlen.c \
  misc/wassert.c \
  misc/wcrtomb.c \
  misc/wcsnlen.c \
  misc/wctob.c \
  stdio/_fseeki64.c \
  string/wcstok.c

# Files included in libmsvcrt-os.a (for msvcrt.dll) on arm32
src_msvcrtarm32=\
  $(src_msvcrt) \
  misc/__p___argc.c \
  misc/__p___argv.c \
  misc/__p___wargv.c \
  misc/__p___mb_cur_max.c \
  misc/__p___initenv.c \
  misc/__p___winitenv.c \
  misc/__p__acmdln.c \
  misc/__p__commode.c \
  misc/__p__fmode.c \
  misc/__p__mbcasemap.c \
  misc/__p__mbctype.c \
  misc/__p__osplatform_emul.c \
  misc/__p__osver.c \
  misc/__p__pctype.c \
  misc/__p__pgmptr.c \
  misc/__p__pwctype.c \
  misc/__p__wcmdln.c \
  misc/__p__winmajor.c \
  misc/__p__winminor.c \
  misc/__p__winver.c \
  misc/__p__wpgmptr.c \
  misc/__timezone.c \
  misc/__tzname.c \
  misc/_getpid.c \
  misc/__initenv.c \
  misc/__winitenv.c \
  stdio/_fstat64i32.c \
  stdio/_setmaxstdio.c \
  stdio/_stat64i32.c \
  stdio/_wstat64i32.c \
  stdio/gets.c \
  stdio/scanf.S

if !ENABLE_SOFTMATH
src_msvcrtarm32+=\
  math/arm/nearbyint.S \
  math/arm/nearbyintf.S \
  math/arm/nearbyintl.S \
  math/arm/s_trunc.c \
  math/arm/s_truncf.c \
  math/arm-common/acosh.c \
  math/arm-common/acoshf.c \
  math/arm-common/acoshl.c \
  math/arm-common/asinh.c \
  math/arm-common/asinhf.c \
  math/arm-common/asinhl.c \
  math/arm-common/atanh.c \
  math/arm-common/atanhf.c \
  math/arm-common/atanhl.c \
  math/arm-common/exp2.c \
  math/arm-common/exp2f.c \
  math/arm-common/exp2l.c \
  math/arm-common/copysignl.c \
  math/arm-common/expm1.c \
  math/arm-common/expm1f.c \
  math/arm-common/expm1l.c \
  math/arm-common/ilogb.c \
  math/arm-common/ilogbf.c \
  math/arm-common/ilogbl.c \
  math/arm-common/log1p.c \
  math/arm-common/log1pf.c \
  math/arm-common/log1pl.c \
  math/arm-common/log2.c \
  math/arm-common/logb.c \
  math/arm-common/logbf.c \
  math/arm-common/logbl.c \
  math/arm-common/pow.c \
  math/arm-common/powf.c \
  math/arm-common/powl.c \
  math/arm-common/remainder.c \
  math/arm-common/remainderf.c \
  math/arm-common/remainderl.c \
  math/arm-common/remquol.c \
  math/arm-common/s_remquo.c \
  math/arm-common/s_remquof.c \
  math/arm-common/scalbn.c
endif

# Files included in libmsvcrt-os.a (for msvcrt.dll) on arm64
src_msvcrtarm64=\
  $(src_msvcrt) \
  math/arm-common/acosh.c \
  math/arm-common/acoshf.c \
  math/arm-common/acoshl.c \
  math/arm-common/asinh.c \
  math/arm-common/asinhf.c \
  math/arm-common/asinhl.c \
  math/arm-common/atanh.c \
  math/arm-common/atanhf.c \
  math/arm-common/atanhl.c \
  math/arm-common/copysignl.c \
  math/arm-common/exp2.c \
  math/arm-common/exp2f.c \
  math/arm-common/exp2l.c \
  math/arm-common/expm1.c \
  math/arm-common/expm1f.c \
  math/arm-common/expm1l.c \
  math/arm-common/ilogb.c \
  math/arm-common/ilogbf.c \
  math/arm-common/ilogbl.c \
  math/arm-common/log1p.c \
  math/arm-common/log1pf.c \
  math/arm-common/log1pl.c \
  math/arm-common/log2.c \
  math/arm-common/logb.c \
  math/arm-common/logbf.c \
  math/arm-common/logbl.c \
  math/arm-common/pow.c \
  math/arm-common/powf.c \
  math/arm-common/powl.c \
  math/arm-common/remainder.c \
  math/arm-common/remainderf.c \
  math/arm-common/remainderl.c \
  math/arm-common/remquol.c \
  math/arm-common/s_remquo.c \
  math/arm-common/s_remquof.c \
  math/arm-common/scalbn.c \
  math/arm64/nearbyint.c \
  math/arm64/nearbyintf.c \
  math/arm64/nearbyintl.c \
  math/arm64/trunc.c \
  math/arm64/truncf.c \
  misc/__p___argc.c \
  misc/__p___argv.c \
  misc/__p___wargv.c \
  misc/__p___mb_cur_max.c \
  misc/__p___initenv.c \
  misc/__p___winitenv.c \
  misc/__p__acmdln.c \
  misc/__p__commode.c \
  misc/__p__fmode.c \
  misc/__p__mbcasemap.c \
  misc/__p__mbctype.c \
  misc/__p__osplatform_emul.c \
  misc/__p__osver.c \
  misc/__p__pctype.c \
  misc/__p__pgmptr.c \
  misc/__p__pwctype.c \
  misc/__p__wcmdln.c \
  misc/__p__winmajor.c \
  misc/__p__winminor.c \
  misc/__p__winver.c \
  misc/__p__wpgmptr.c \
  misc/__timezone.c \
  misc/__tzname.c \
  misc/_getpid.c \
  misc/__initenv.c \
  misc/__winitenv.c \
  stdio/_setmaxstdio.c \
  stdio/gets.c

if ARM64EC
src_msvcrtarm64+=math/fabsf.c
src_msvcrtarm64_x64=libarm64/stdio/scanf.x86_64.o
else
src_msvcrtarm64+=stdio/scanf.S
endif

src_pre_msvcrt20=\
  misc/__daylight.c \
  misc/__initenv.c \
  misc/__p___argc.c \
  misc/__p___argv.c \
  misc/__p___initenv.c \
  misc/__p___mb_cur_max.c \
  misc/__p__acmdln.c \
  misc/__p__commode.c \
  misc/__p__environ.c \
  misc/__p__fmode.c \
  misc/__p__osver.c \
  misc/__p__pctype.c \
  misc/__p__pgmptr.c \
  misc/__p__pwctype.c \
  misc/__p__winmajor.c \
  misc/__p__winminor.c \
  misc/__p__winver.c \
  misc/__timezone.c \
  misc/__tzname.c \
  stdio/fgetws.c \
  stdio/fputws.c \
  stdio/iob_func.c

src_pre_msvcrt40=\
  misc/__dstbias.c \
  misc/__set_app_type.c \
  misc/_dstbias.c \
  misc/dummy__setusermatherr.c \
  stdio/_filelengthi64.c \
  stdio/_fstat32i64.c \
  stdio/_stat32i64.c \
  stdio/_wstat32i64.c \
  stdio/fgetpos.c \
  stdio/fsetpos.c

src_pre_msvcrt60=\
  misc/__badioinfo.c \
  misc/__p__osplatform_emul.c \
  stdio/atoll.c \
  stdio/mingw_dummy__lock.c

src_pre_msvcr70=\
  misc/___mb_cur_max_func.c \
  misc/__pctype_func.c \
  misc/__pwctype_func.c \
  misc/_aligned_free.c \
  misc/_aligned_malloc.c \
  misc/_aligned_offset_malloc.c \
  misc/_aligned_offset_realloc.c \
  misc/_aligned_realloc.c \
  misc/_time64.c \
  misc/lc_locale_func.c \
  misc/strtoimax.c \
  misc/strtoumax.c \
  misc/wcstoimax.c \
  misc/wcstoumax.c \
  stdio/_fstat64.c \
  stdio/_scprintf.c \
  stdio/_scwprintf.c \
  stdio/_stat64.c \
  stdio/_vscprintf.c \
  stdio/_vscwprintf.c \
  stdio/_wstat64.c

src_pre_msvcr71=\
  misc/_set_purecall_handler.c

src_pre_msvcr80=\
  misc/__iswcsym.c \
  misc/__iswcsymf.c \
  misc/__sys_errlist.c \
  misc/__sys_nerr.c \
  misc/_aligned_msize.c \
  misc/_aligned_offset_recalloc.c \
  misc/_aligned_recalloc.c \
  misc/_configthreadlocale.c \
  misc/_get_errno.c \
  misc/_initterm_e.c \
  misc/_recalloc.c \
  misc/_set_errno.c \
  misc/btowc.c \
  misc/imaxabs.c \
  misc/invalid_parameter_handler.c \
  misc/mbrtowc.c \
  misc/output_format.c \
  misc/strnlen.c \
  misc/wassert.c \
  misc/wcrtomb.c \
  misc/wcsnlen.c \
  misc/wctob.c \
  stdio/_fseeki64.c \
  stdio/_fstat64i32.c \
  stdio/_ftelli64.c \
  stdio/_stat64i32.c \
  stdio/_wstat64i32.c \
  stdio/mingw_lock.c \
  string/wcstok.c

src_pre_msvcr100=\
  misc/imaxdiv.c

src_pre_msvcr110=\
  stdio/msvcr110pre_stat32.c \
  stdio/msvcr110pre_stat64i32.c \
  stdio/msvcr110pre_wstat32.c \
  stdio/msvcr110pre_wstat64i32.c

src_pre_msvcr120=\
  $(src_msvcrt_add_vscanf) \
  math/i386__copysignf.c \
  misc/isblank.c \
  misc/iswblank.c \
  misc/wctrans.c \
  misc/wctype.c \
  stdio/scanf.S

src_pre_msvcr120_post_msvcr71=\
  misc/_isblank_l.c \
  misc/_iswblank_l.c

src_post_msvcr80=\
  misc/__p__osplatform_emul.c \
  misc/__p__osver_emul.c

src_post_msvcr100=\
  stdio/msvcr110plus_stat32.c \
  stdio/msvcr110plus_stat64i32.c \
  stdio/msvcr110plus_wstat32.c \
  stdio/msvcr110plus_wstat64i32.c

src_crtdll=\
  $(src_pre_msvcrt20) \
  $(src_pre_msvcrt40) \
  $(src_pre_msvcrt60) \
  $(src_pre_msvcr70) \
  $(src_pre_msvcr71) \
  $(src_pre_msvcr80) \
  $(src_pre_msvcr100) \
  $(src_pre_msvcr110) \
  $(src_pre_msvcr120) \
  misc/crtdll__getmainargs.c \
  misc/crtdll__ismbblead.c \
  misc/crtdll_fstat.c \
  misc/crtdll_stat.c \
  misc/__p__mbctype.c

src_msvcrt10=\
  $(src_pre_msvcrt20) \
  $(src_pre_msvcrt40) \
  $(src_pre_msvcrt60) \
  $(src_pre_msvcr70) \
  $(src_pre_msvcr71) \
  $(src_pre_msvcr80) \
  $(src_pre_msvcr100) \
  $(src_pre_msvcr110) \
  $(src_pre_msvcr120) \
  misc/crtdll__getmainargs.c \
  misc/msvcrt10__ismbblead.c

src_msvcrt20=\
  $(src_pre_msvcrt40) \
  $(src_pre_msvcrt60) \
  $(src_pre_msvcr70) \
  $(src_pre_msvcr71) \
  $(src_pre_msvcr80) \
  $(src_pre_msvcr100) \
  $(src_pre_msvcr110) \
  $(src_pre_msvcr120) \
  misc/msvcrt20__getmainargs.c \
  misc/msvcrt20__wgetmainargs.c

src_msvcrt40=\
  $(src_pre_msvcrt60) \
  $(src_pre_msvcr70) \
  $(src_pre_msvcr71) \
  $(src_pre_msvcr80) \
  $(src_pre_msvcr100) \
  $(src_pre_msvcr110) \
  $(src_pre_msvcr120) \
  misc/msvcrt__getmainargs.c \
  misc/msvcrt__wgetmainargs.c

src_msvcrtd=\
  $(src_pre_msvcr70) \
  $(src_pre_msvcr71) \
  $(src_pre_msvcr80) \
  $(src_pre_msvcr100) \
  $(src_pre_msvcr110) \
  $(src_pre_msvcr120) \
  misc/msvcrt__getmainargs.c \
  misc/msvcrt__wgetmainargs.c

src_msvcr70=\
  $(src_pre_msvcr71) \
  $(src_pre_msvcr80) \
  $(src_pre_msvcr100) \
  $(src_pre_msvcr110) \
  $(src_pre_msvcr120) \
  misc/__p__osplatform.c

src_msvcr71=\
  $(src_pre_msvcr80) \
  $(src_pre_msvcr100) \
  $(src_pre_msvcr110) \
  $(src_pre_msvcr120) \
  misc/__p__osplatform.c

src_msvcr80=\
  $(src_pre_msvcr100) \
  $(src_pre_msvcr110) \
  $(src_pre_msvcr120) \
  $(src_pre_msvcr120_post_msvcr71)

src_msvcr90=\
  $(src_pre_msvcr100) \
  $(src_pre_msvcr110) \
  $(src_pre_msvcr120) \
  $(src_pre_msvcr120_post_msvcr71) \
  $(src_post_msvcr80)

src_msvcr100=\
  $(src_pre_msvcr110) \
  $(src_pre_msvcr120) \
  $(src_pre_msvcr120_post_msvcr71) \
  $(src_post_msvcr80)

src_msvcr110=\
  $(src_pre_msvcr120) \
  $(src_pre_msvcr120_post_msvcr71) \
  $(src_post_msvcr80) \
  $(src_post_msvcr100)

src_msvcr120=\
  $(src_post_msvcr80) \
  $(src_post_msvcr100)

src_msvcr120_app=\
  $(src_post_msvcr80) \
  $(src_post_msvcr100) \
  misc/__p___initenv.c \
  misc/__p___winitenv.c \
  misc/__p__environ.c \
  misc/__p__wenviron.c \
  misc/__set_app_type.c \
  misc/_getpid.c

# These mingwex sources are target independent:
src_libmingwex=\
  crt/loadcfg.S \
  cfguard/mingw_cfguard_support.c \
  \
  misc/dllmain.c \
  \
  complex/_cabs.c    complex/cabs.c   complex/cabsf.c   complex/cabsl.c   complex/cacos.c   complex/cacosf.c   \
  complex/cacosl.c   complex/carg.c   complex/cargf.c   complex/cargl.c   complex/casin.c   complex/casinf.c   \
  complex/casinl.c   complex/catan.c  complex/catanf.c  complex/catanl.c  complex/ccos.c    complex/ccosf.c    \
  complex/ccosl.c    complex/cexp.c   complex/cexpf.c   complex/cexpl.c   complex/cimag.c   complex/cimagf.c   \
  complex/cimagl.c   complex/clog.c   complex/clogf.c   complex/clogl.c   complex/clog10.c  complex/clog10f.c  \
  complex/clog10l.c  complex/conj.c   complex/conjf.c   complex/conjl.c   complex/cpow.c    complex/cpowf.c    \
  complex/cpowl.c    complex/cproj.c  complex/cprojf.c  complex/cprojl.c  complex/creal.c   complex/crealf.c   \
  complex/creall.c   complex/csin.c   complex/csinf.c   complex/csinl.c   complex/csqrt.c   complex/csqrtf.c   \
  complex/csqrtl.c   complex/ctan.c   complex/ctanf.c   complex/ctanl.c   \
  complex/cabs.def.h    complex/cacos.def.h  complex/cacosh.def.h  complex/carg.def.h    complex/casin.def.h         \
  complex/casinh.def.h  complex/catan.def.h  complex/catanh.def.h  complex/ccos.def.h    complex/ccosh.def.h         \
  complex/cexp.def.h    complex/cimag.def.h  complex/clog.def.h    complex/clog10.def.h  complex/complex_internal.h  \
  complex/conj.def.h    complex/cpow.def.h   complex/cproj.def.h   complex/creal.def.h   complex/csin.def.h          \
  complex/csinh.def.h   complex/csqrt.def.h  complex/ctan.def.h    complex/ctanh.def.h   \
  \
  gdtoa/gd_arith.h  gdtoa/gd_qnan.h  gdtoa/gdtoa.h  gdtoa/gdtoaimp.h \
  gdtoa/arithchk.c  gdtoa/dmisc.c    gdtoa/dtoa.c   gdtoa/g_dfmt.c   gdtoa/gdtoa.c      gdtoa/gethex.c     \
  gdtoa/g_ffmt.c    gdtoa/g__fmt.c   gdtoa/gmisc.c  gdtoa/g_xfmt.c   gdtoa/hd_init.c    gdtoa/hexnan.c     \
  gdtoa/misc.c      gdtoa/qnan.c     gdtoa/smisc.c  gdtoa/strtodg.c  gdtoa/strtodnrp.c  gdtoa/strtof.c     \
  gdtoa/strtopx.c   gdtoa/sum.c      gdtoa/ulp.c    \
  \
  math/coshl.c       \
  math/fabsl.c          math/fp_consts.c   math/fp_constsf.c     \
  math/fp_constsl.c     math/fpclassify.c  math/fpclassifyf.c    math/fpclassifyl.c   math/frexpf.c        math/frexpl.c \
  math/hypotf.c         math/hypotl.c      math/isnan.c          math/isnanf.c        math/isnanl.c        \
  math/ldexpf.c         math/lgamma.c      math/lgammaf.c        math/lgammal.c       \
  math/modfl.c          \
  math/powi.c           math/powif.c       math/powil.c          \
  math/signbit.c        math/signbitf.c    math/signbitl.c       \
  math/signgam.c        \
  math/sinhl.c          math/sqrtl.c       math/tanhl.c          \
  math/powi.def.h       math/sqrt.def.h    \
  math/cephes_mconf.h   math/fp_consts.h   \
  \
  misc/mb_wc_common.h \
  misc/mingw_longjmp.S \
  misc/mingw_getsp.S \
  misc/alarm.c \
  misc/delay-f.c         misc/delay-n.c         \
  misc/delayimp.c        misc/dirent.c          \
  misc/dirname.c \
  misc/feclearexcept.c   misc/fegetenv.c            misc/fegetexceptflag.c  misc/fegetround.c            misc/feholdexcept.c    \
  misc/feraiseexcept.c   misc/fesetenv.c            misc/fesetexceptflag.c  misc/fesetround.c            misc/fetestexcept.c    \
  misc/mingw_controlfp.c \
  misc/mingw_setfp.c \
  misc/feupdateenv.c     misc/ftruncate.c           misc/fwide.c            misc/getlogin.c              misc/getopt.c          \
  misc/gettimeofday.c    misc/__mingw_has_sse.c      \
  misc/mempcpy.c         misc/mingw-aligned-malloc.c \
  misc/mingw_matherr.c   misc/mingw_mbwc_convert.c  misc/mingw_usleep.c     misc/mingw_wcstod.c          misc/mingw_wcstof.c    \
  misc/mingw_wcstold.c \
  misc/mkstemp.c         misc/sleep.c           \
  misc/strsafe.c \
  misc/tdelete.c         misc/tdestroy.c            misc/tfind.c           \
  misc/tsearch.c         misc/twalk.c           \
  misc/wcstof.c \
  misc/wcstold.c \
  misc/wdirent.c         misc/winbs_uint64.c        misc/winbs_ulong.c      misc/winbs_ushort.c    \
  misc/wmemchr.c         misc/wmemcmp.c             misc/wmemcpy.c          misc/wmemmove.c              misc/wmempcpy.c        \
  misc/wmemset.c         misc/mingw-access.c \
  misc/ftw32.c           misc/ftw32i64.c            misc/ftw64.c            misc/ftw64i32.c \
  \
  ssp/chk_fail.c         ssp/gets_chk.c             ssp/memcpy_chk.c        ssp/memmove_chk.c \
  ssp/mempcpy_chk.c \
  ssp/memset_chk.c       ssp/stack_chk_fail.c       ssp/stack_chk_guard.c   ssp/strcat_chk.c \
  ssp/stpcpy_chk.c       ssp/strcpy_chk.c           ssp/strncat_chk.c       ssp/strncpy_chk.c \
  \
  stdio/strtok_r.c \
  stdio/_Exit.c            stdio/_findfirst64i32.c   stdio/_findnext64i32.c   stdio/_wfindfirst64i32.c  stdio/_wfindnext64i32.c \
  stdio/asprintf.c \
  stdio/fopen64.c          stdio/fseeko32.c          stdio/fseeko64.c                                   stdio/ftello.c          \
  stdio/ftello64.c         stdio/ftruncate64.c       stdio/lltoa.c            stdio/lltow.c             stdio/lseek64.c         \
  stdio/__mingw_fix_stat_path.c stdio/__mingw_fix_wstat_path.c \
  \
  stdio/mingw_pformat.h    mingw_sformat.h           mingw_swformat.h \
  stdio/mingw_fprintf.c    stdio/mingw_fwprintf.c    stdio/mingw_fscanf.c     stdio/mingw_fwscanf.c     stdio/mingw_pformat.c   \
  stdio/mingw_wpformat.c   stdio/mingw_printf.c      stdio/mingw_wprintf.c    stdio/mingw_scanf.c       stdio/mingw_snprintf.c  \
  stdio/mingw_swprintf.c   stdio/mingw_snwprintf.c   stdio/mingw_sprintf.c    stdio/mingw_sscanf.c      stdio/mingw_swscanf.c   \
  stdio/mingw_vfprintf.c   stdio/mingw_vfwprintf.c   stdio/mingw_vfscanf.c    stdio/mingw_vprintf.c     stdio/mingw_vwprintf.c  \
  stdio/mingw_vsnprintf.c  stdio/mingw_vswprintf.c   stdio/mingw_vsnwprintf.c stdio/mingw_vsprintf.c    stdio/mingw_wscanf.c    \
  stdio/mingw_vfwscanf.c   stdio/mingw_vswscanf.c    stdio/mingw_vsscanf.c    stdio/mingw_sformat.c     stdio/mingw_swformat.c  \
  \
  stdio/snprintf.c         stdio/snwprintf.c         stdio/truncate.c        \
  stdio/ulltoa.c           stdio/ulltow.c            stdio/vasprintf.c \
  stdio/vsnprintf.c        stdio/vsnwprintf.c \
  stdio/wtoll.c            stdio/mingw_asprintf.c    stdio/mingw_vasprintf.c

# these go into both 32 and 64 bit x86 versions:
src_libmingwex_x86=\
  math/cbrtl.c              math/erfl.c               math/fdiml.c              math/fmal.c               math/fmaxl.c              \
  math/fminl.c              math/llrintl.c            math/llroundl.c           math/lrintl.c             math/lroundl.c            \
  math/rintl.c              math/roundl.c             math/tgammal.c            math/truncl.c             \
  math/x86/_chgsignl.S      math/x86/acosh.def.h      math/x86/acoshl.c         math/x86/acosl.c          \
  math/x86/asinhl.c         math/x86/asinl.c          math/x86/atan2l.c         \
  math/x86/atanhl.c         math/x86/atanl.c          \
  math/x86/ceill.S          math/x86/copysignl.S      \
  math/x86/cos.def.h        math/x86/cosl.c           math/x86/cosl_internal.S  \
  math/x86/cossinl.c        \
  math/x86/exp2l.S          math/x86/exp.def.h        math/x86/expl.c           math/x86/expm1.def.h      math/x86/expm1l.c         \
  math/x86/fastmath.h       math/x86/floorl.S         \
  math/x86/fmodl.c          math/x86/fucom.c          \
  math/x86/ilogbl.S         math/x86/internal_logl.S  \
  math/x86/ldexp.c          math/x86/ldexpl.c         \
  math/x86/log.def.h        math/x86/log10l.S         math/x86/log1pl.S         math/x86/log2l.S          \
  math/x86/logbl.c          math/x86/logl.c           math/x86/nearbyintl.S     math/x86/pow.def.h        math/x86/powl.c           \
  math/x86/remainderl.S     math/x86/remquol.S        \
  math/x86/scalbn.S         math/x86/scalbnf.S        math/x86/scalbnl.S        \
  math/x86/sin.def.h        \
  math/x86/sinl.c           math/x86/sinl_internal.S  math/x86/tanl.S


src_libmingwex32=$(src_libmingwex_x86)
src_libmingwex64=$(src_libmingwex_x86) \
  cfguard/guard_dispatch.S

# these only go into the ARM32 version:
src_libmingwexarm32=\
  math/sincos.c \
  math/sincosf.c \
  math/arm-common/sincosl.c \
  math/arm/s_rint.c         math/arm/s_rintf.c

if ENABLE_SOFTMATH
src_libmingwexarm32+=\
  math/softmath/e_fmod.c    math/softmath/e_fmodf.c   math/softmath/e_powf.c    math/softmath/e_pow.c \
  math/softmath/acosf.c     math/softmath/acosh.c     math/softmath/acosl.c     math/softmath/acoshf.c    math/softmath/acoshl.c    \
  math/softmath/asinf.c     math/softmath/asinh.c     math/softmath/asinl.c     math/softmath/asinhf.c    math/softmath/asinhl.c    \
  math/softmath/atan2f.c    math/softmath/atan2l.c    math/softmath/atanf.c     math/softmath/atanh.c     math/softmath/atanl.c     \
  math/softmath/atanhf.c    math/softmath/atanhl.c    math/softmath/cos.c       math/softmath/cosf.c      math/softmath/cosl.c      \
  math/softmath/exp.c       math/softmath/expl.c      math/softmath/exp2.c      math/softmath/exp2f.c     math/softmath/exp2l.c     \
  math/softmath/expm1.c     math/softmath/expm1f.c    math/softmath/expm1l.c    math/softmath/fmod.c      math/softmath/fmodf.c     \
  math/softmath/fmodl.c     math/softmath/frexpl.c    math/softmath/ilogb.c     math/softmath/ilogbf.c    math/softmath/ilogbl.c    \
  math/softmath/ldexp.c     math/softmath/ldexpl.c    math/softmath/log.c       math/softmath/log10l.c    math/softmath/log1p.c     \
  math/softmath/log1pf.c    math/softmath/log1pl.c    math/softmath/log2.c      math/softmath/log2f.c     math/softmath/log2l.c     \
  math/softmath/logb.c      math/softmath/logbf.c     math/softmath/logbl.c     math/softmath/logl.c      math/softmath/pow.c       \
  math/softmath/powl.c      \
  math/softmath/remainder.c math/softmath/remainderf.c math/softmath/remainderl.c \
  math/softmath/remquo.c    math/softmath/remquof.c   math/softmath/remquol.c   math/softmath/scalbn.c    math/softmath/scalbnf.c   \
  math/softmath/scalbnl.c   math/softmath/sin.c \
  math/softmath/sinf.c      math/softmath/sinl.c      math/softmath/tanf.c      math/softmath/tanl.c
else
src_libmingwexarm32+=\
  math/arm-common/ldexpl.c
endif

# these only go into the ARM64 version:
src_libmingwexarm64=\
  math/sincos.c \
  math/sincosf.c \
  math/arm-common/sincosl.c \
  math/arm64/rint.c         math/arm64/rintf.c \
  math/arm-common/ldexpl.c

if ARM64EC
src_libmingwexarm64+=crt/chpe.S
src_libmingwexarm64_x64=libarm64/cfguard/guard_dispatch.x86_64.o
endif

# These intrinsics are target independent:
src_intrincs= \
  intrincs/__movsb.c        intrincs/__movsd.c        intrincs/__movsw.c         intrincs/__stosb.c       intrincs/__stosd.c        \
  intrincs/__stosw.c        intrincs/_rotl64.c        intrincs/_rotr64.c         intrincs/bitscanfwd.c    intrincs/bitscanrev.c     \
  intrincs/bittest.c        intrincs/bittestc.c       intrincs/bittestci.c       intrincs/bittestr.c      intrincs/bittestri.c      \
  intrincs/bittests.c       intrincs/bittestsi.c      intrincs/cpuid.c           \
  intrincs/ilockadd.c       intrincs/ilockand.c        intrincs/ilockand64.c \
  intrincs/ilockcxch.c      intrincs/ilockcxch8.c     \
  intrincs/ilockcxch16.c    intrincs/ilockcxch64.c    intrincs/ilockcxchptr.c    intrincs/ilockdec.c      intrincs/ilockdec16.c     \
  intrincs/ilockdec64.c     intrincs/ilockexch.c      intrincs/ilockexch64.c     intrincs/ilockexchadd.c  intrincs/ilockexchadd64.c \
  intrincs/ilockexchptr.c   intrincs/ilockinc.c       intrincs/ilockinc16.c      intrincs/ilockinc64.c    intrincs/ilockor.c        \
  intrincs/ilockor64.c      intrincs/ilockxor.c       intrincs/ilockxor64.c      intrincs/inbyte.c        intrincs/inbytestring.c   \
  intrincs/indword.c        intrincs/indwordstring.c  intrincs/inword.c          intrincs/inwordstring.c  intrincs/outbyte.c        \
  intrincs/outbytestring.c  intrincs/outdword.c       intrincs/outdwordstring.c  intrincs/outword.c       intrincs/outwordstring.c  \
  intrincs/readcr0.c        intrincs/readcr2.c        intrincs/readcr3.c         intrincs/readcr4.c       \
  intrincs/readmsr.c        intrincs/writecr0.c        intrincs/writecr2.c      intrincs/writecr3.c       \
  intrincs/writecr4.c       intrincs/writemsr.c        intrincs/__int2c.c       intrincs/RtlSecureZeroMemory.c

# these only go into the 64 bit version:
src_intrincs64=\
  intrincs/bittest64.c    intrincs/bittestc64.c   intrincs/bittestr64.c   intrincs/bittestri64.c     \
  intrincs/bittests64.c   intrincs/bittestsi64.c  intrincs/bitscanfwd64.c intrincs/bitscanrev64.c    \
  intrincs/ilockadd64.c   intrincs/rdtsc.c        intrincs/readgsbyte.c   intrincs/readgsword.c      intrincs/readgsdword.c \
  intrincs/readgsqword.c  intrincs/writegsbyte.c  intrincs/writegsword.c  intrincs/writegsdword.c    \
  intrincs/writegsqword.c intrincs/mul128ex.c     intrincs/umul128ex.c    intrincs/_mul128.c         \
  intrincs/_umul128.c     intrincs/__movsq.c      intrincs/__stosq.c      intrincs/__shiftright128.c \
  intrincs/bittestci64.c  intrincs/__faststorefence.c    intrincs/__shiftleft128.c                   \
  intrincs/readcr8.c      intrincs/writecr8.c

# these only go into the 32 bit version:
src_intrincs32=\
  intrincs/rdtsc.c        intrincs/readfsbyte.c   intrincs/readfsword.c   intrincs/readfsdword.c  \
  intrincs/writefsbyte.c  intrincs/writefsword.c  intrincs/writefsdword.c

# these only go into the ARM32 version:
src_intrincsarm32=

# these only go into the ARM64 version:
src_intrincsarm64=

if LIB32
#########
# Compiling 32-bit runtime
#

lib32dir=$(prefix)/@LIBX8632SUFFIXDIR@
crt32dir=$(lib32dir)
winrt32dir=$(lib32dir)
dx32dir=$(lib32dir)

if !W32API
crt32_DATA = \
  lib32/crt1.o    lib32/crt2.o     lib32/crt1u.o   lib32/crt2u.o    lib32/dllcrt1.o    lib32/dllcrt2.o \
  lib32/CRT_fp8.o lib32/CRT_fp10.o lib32/txtmode.o lib32/binmode.o  lib32/crtbegin.o   lib32/crtend.o \
  lib32/gcrt0.o   lib32/gcrt1.o    lib32/gcrt2.o   lib32/CRT_glob.o lib32/CRT_noglob.o
else
crt32_DATA =
endif

COMPILE32=$(COMPILE) $(CPPFLAGS32) $(extra_include) -D_SYSCRT=1
lib32/crt1.o: crt/crtexe.c
	$(AM_V_CC)$(COMPILE32) -c $< -o $@
lib32/crt2.o: lib32/crt1.o
	$(AM_V_GEN)cp $< $@
lib32/crt1u.o: crt/ucrtexe.c
	$(AM_V_CC)$(COMPILE32) -c $< -o $@
lib32/crt2u.o: lib32/crt1u.o
	$(AM_V_GEN)cp $< $@
lib32/dllcrt1.o: crt/crtdll.c
	$(AM_V_CC)$(COMPILE32) -c $< -o $@
lib32/dllcrt2.o: lib32/dllcrt1.o
	$(AM_V_GEN)cp $< $@

lib32/gcrt0.o: profile/gcrt0.c
	$(AM_V_CC)$(COMPILE) $(CPPFLAGS32) -c $< -o $@
lib32/gcrt1.o: lib32/gcrt0.o
	$(AM_V_GEN)cp $< $@
lib32/gcrt2.o: lib32/gcrt0.o
	$(AM_V_GEN)cp $< $@

lib32/%.o: crt/%.c
	$(AM_V_CC)$(COMPILE) $(CPPFLAGS32) -c $< -o $@

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

lib32_DATA =
if !W32API
lib32_DATA += lib32/libmsvcrt.a
lib32/libmsvcrt.a: lib32/@MSVCRT_LIB@
	$(AM_V_GEN)cp $< $@

lib32_DATA += lib32/libmsvcrt-os.a
lib32/libmsvcrt-os.a: lib-common/msvcrt-os.mri lib32/libmsvcrt_def.a lib32/libmsvcrt_common.a lib32/libmsvcrt_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)
endif

lib32_LIBRARIES += lib32/libbits.a
lib32_libbits_a_SOURCES = $(src_libbits)
lib32_libbits_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

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

lib32_LIBRARIES += lib32/libmsxml2.a
lib32_libmsxml2_a_SOURCES = $(src_libmsxml2)
lib32_libmsxml2_a_CPPFLAGS = $(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libmsxml6.a
lib32_libmsxml6_a_SOURCES = $(src_libmsxml6)
lib32_libmsxml6_a_CPPFLAGS = $(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libmfuuid.a
lib32_libmfuuid_a_SOURCES = $(src_libmfuuid)
lib32_libmfuuid_a_CPPFLAGS = $(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libamstrmid.a
lib32_libamstrmid_a_SOURCES = $(src_libamstrmid)
lib32_libamstrmid_a_CPPFLAGS = $(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libwmcodecdspuuid.a
lib32_libwmcodecdspuuid_a_SOURCES = $(src_libwmcodecdspuuid)
lib32_libwmcodecdspuuid_a_CPPFLAGS = $(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libwindowscodecs.a
lib32_libwindowscodecs_a_SOURCES = $(src_libwindowscodecs)
lib32_libwindowscodecs_a_CPPFLAGS = $(CPPFLAGS32) $(sysincludes)
lib32_libwindowscodecs_a_AR = $(DTDEF32) $(top_srcdir)/lib32/windowscodecs.def && $(AR) $(ARFLAGS)

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

lib32_LIBRARIES += lib32/liblocationapi.a
lib32_liblocationapi_a_SOURCES = $(src_liblocationapi)
lib32_liblocationapi_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libsapi.a
lib32_libsapi_a_SOURCES = $(src_libsapi)
lib32_libsapi_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

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

lib32_LIBRARIES += lib32/libwiaguid.a
lib32_libwiaguid_a_SOURCES = $(src_libwiaguid)
lib32_libwiaguid_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libgdiplus.a
lib32_libgdiplus_a_SOURCES = $(src_libgdiplus)
lib32_libgdiplus_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)
lib32_libgdiplus_a_AR = $(DTLIB32) && $(AR) $(ARFLAGS)

lib32_LIBRARIES += lib32/libws2_32.a
lib32_libws2_32_a_SOURCES = $(src_libws2_32) lib-common/ws2_32.def.in
lib32_libws2_32_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)
lib32_libws2_32_a_AR = $(DTDEF32) lib32/ws2_32.def && $(AR) $(ARFLAGS)
EXTRA_lib32_libws2_32_a_DEPENDENCIES=lib32/ws2_32.def

lib32_LIBRARIES += lib32/libtaskschd.a
lib32_libtaskschd_a_SOURCES = $(src_libtaskschd)
lib32_libtaskschd_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libntoskrnl.a
lib32_libntoskrnl_a_SOURCES = $(src_libntoskrnl)
lib32_libntoskrnl_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)
lib32_libntoskrnl_a_AR = $(DTLIB32) && $(AR) $(ARFLAGS)

lib32_LIBRARIES += lib32/libadsiid.a
lib32_libadsiid_a_SOURCES = $(src_adsiid)
lib32_libadsiid_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

lib32_LIBRARIES += lib32/libdloadhelper.a
lib32_libdloadhelper_a_SOURCES = $(src_libdloadhelper)
lib32_libdloadhelper_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

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
lib32_libmingw32_a_CPPFLAGS=$(CPPFLAGS32) -D_SYSCRT=1 $(extra_include) $(AM_CPPFLAGS)
lib32_libmingw32_a_SOURCES = $(src_libmingw32) crt/CRT_fp10.c

lib32_LIBRARIES += lib32/libmingwex.a
lib32_libmingwex_a_CPPFLAGS=$(CPPFLAGS32) $(extra_include) $(AM_CPPFLAGS)
lib32_libmingwex_a_SOURCES = $(src_libmingwex) $(src_libmingwex32) $(src_dfp_math)

lib32_LIBRARIES += lib32/libmoldname.a
lib32_libmoldname_a_CPPFLAGS=$(CPPFLAGS32) $(extra_include) $(AM_CPPFLAGS)
lib32_libmoldname_a_SOURCES = $(src_libm)

lib32_LIBRARIES += lib32/libmingwthrd.a
lib32_libmingwthrd_a_SOURCES = $(src_libmingwthrd)
lib32_libmingwthrd_a_CPPFLAGS=$(CPPFLAGS32) $(sysincludes)

processed_defs += lib32/crtdll.def lib32/msvcrt10.def lib32/msvcrt20.def lib32/msvcrt40.def lib32/msvcr40d.def \
				  lib32/msvcrt.def lib32/msvcrtd.def lib32/msvcr70.def lib32/msvcr70d.def lib32/msvcr71.def lib32/msvcr71d.def \
				  lib32/msvcr80.def lib32/msvcr80d.def lib32/msvcr90.def lib32/msvcr90d.def lib32/msvcr100.def lib32/msvcr100d.def \
				  lib32/msvcr110.def lib32/msvcr110d.def lib32/msvcr120.def lib32/msvcr120d.def \
				  lib32/msvcr120_app.def lib32/msvcp120_app.def lib32/ucrtbase.def lib32/ucrtbased.def \
				  lib32/api-ms-win-crt-math-l1-1-0.def lib32/api-ms-win-crt-private-l1-1-0.def lib32/api-ms-win-crt-runtime-l1-1-0.def \
				  lib32/api-ms-win-crt-filesystem-l1-1-0.def lib32/api-ms-win-crt-time-l1-1-0.def \
				  lib32/vcruntime140.def lib32/vcruntime140d.def lib32/vcruntime140_app.def

endif

include lib32/Makefile.am

if !W32API
lib32_DATA += lib32/libglut.a lib32/libmsvcp60.a lib32/libmsvcp120_app.a

lib32_DATA += lib32/libcrtdll.a
lib32/libcrtdll.a: lib32/crtdll.mri lib32/libcrtdll_def.a lib32/libmsvcrt_common.a lib32/libcrtdll_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib32_DATA += lib32/libmsvcrt10.a
lib32/libmsvcrt10.a: lib32/msvcrt10.mri lib32/libmsvcrt10_def.a lib32/libmsvcrt_common.a lib32/libmsvcrt10_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib32_DATA += lib32/libmsvcrt20.a
lib32/libmsvcrt20.a: lib32/msvcrt20.mri lib32/libmsvcrt20_def.a lib32/libmsvcrt_common.a lib32/libmsvcrt20_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib32_DATA += lib32/libmsvcrt40.a
lib32/libmsvcrt40.a: lib32/msvcrt40.mri lib32/libmsvcrt40_def.a lib32/libmsvcrt_common.a lib32/libmsvcrt40_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib32_DATA += lib32/libmsvcr40d.a
lib32/libmsvcr40d.a: lib32/msvcr40d.mri lib32/libmsvcr40d_def.a lib32/libmsvcrt_common.a lib32/libmsvcrt40_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib32_DATA += lib32/libmsvcrtd.a
lib32/libmsvcrtd.a: lib32/msvcrtd.mri lib32/libmsvcrtd_def.a lib32/libmsvcrt_common.a lib32/libmsvcrtd_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib32_DATA += lib32/libmsvcr70.a
lib32/libmsvcr70.a: lib32/msvcr70.mri lib32/libmsvcr70_def.a lib32/libmsvcrt_common.a lib32/libmsvcr70_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib32_DATA += lib32/libmsvcr70d.a
lib32/libmsvcr70d.a: lib32/msvcr70d.mri lib32/libmsvcr70d_def.a lib32/libmsvcrt_common.a lib32/libmsvcr70_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib32_DATA += lib32/libmsvcr71.a
lib32/libmsvcr71.a: lib32/msvcr71.mri lib32/libmsvcr71_def.a lib32/libmsvcrt_common.a lib32/libmsvcr71_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib32_DATA += lib32/libmsvcr71d.a
lib32/libmsvcr71d.a: lib32/msvcr71d.mri lib32/libmsvcr71d_def.a lib32/libmsvcrt_common.a lib32/libmsvcr71_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib32_DATA += lib32/libmsvcr80.a
lib32/libmsvcr80.a: lib-common/msvcr80.mri lib32/libmsvcr80_def.a lib32/libmsvcrt_common.a lib32/libmsvcr80_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib32_DATA += lib32/libmsvcr80d.a
lib32/libmsvcr80d.a: lib-common/msvcr80d.mri lib32/libmsvcr80d_def.a lib32/libmsvcrt_common.a lib32/libmsvcr80_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib32_DATA += lib32/libmsvcr90.a
lib32/libmsvcr90.a: lib-common/msvcr90.mri lib32/libmsvcr90_def.a lib32/libmsvcrt_common.a lib32/libmsvcr90_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib32_DATA += lib32/libmsvcr90d.a
lib32/libmsvcr90d.a: lib-common/msvcr90d.mri lib32/libmsvcr90d_def.a lib32/libmsvcrt_common.a lib32/libmsvcr90_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib32_DATA += lib32/libmsvcr100.a
lib32/libmsvcr100.a: lib-common/msvcr100.mri lib32/libmsvcr100_def.a lib32/libmsvcrt_common.a lib32/libmsvcr100_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib32_DATA += lib32/libmsvcr100d.a
lib32/libmsvcr100d.a: lib-common/msvcr100d.mri lib32/libmsvcr100d_def.a lib32/libmsvcrt_common.a lib32/libmsvcr100_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib32_DATA += lib32/libmsvcr110.a
lib32/libmsvcr110.a: lib-common/msvcr110.mri lib32/libmsvcr110_def.a lib32/libmsvcrt_common.a lib32/libmsvcr110_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib32_DATA += lib32/libmsvcr110d.a
lib32/libmsvcr110d.a: lib-common/msvcr110d.mri lib32/libmsvcr110d_def.a lib32/libmsvcrt_common.a lib32/libmsvcr110_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib32_DATA += lib32/libmsvcr120.a
lib32/libmsvcr120.a: lib-common/msvcr120.mri lib32/libmsvcr120_def.a lib32/libmsvcrt_common.a lib32/libmsvcr120_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib32_DATA += lib32/libmsvcr120d.a
lib32/libmsvcr120d.a: lib-common/msvcr120d.mri lib32/libmsvcr120d_def.a lib32/libmsvcrt_common.a lib32/libmsvcr120_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib32_DATA += lib32/libmsvcr120_app.a
lib32/libmsvcr120_app.a: lib-common/msvcr120_app.mri lib32/libmsvcr120_app_def.a lib32/libmsvcrt_common.a lib32/libmsvcr120_extra.a lib32/libmsvcr120_app_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib32_DATA += lib32/libucrtbase.a
lib32/libucrtbase.a: lib-common/ucrtbase.mri lib32/libucrtbase_def.a lib32/libucrt_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib32_DATA += lib32/libucrtbased.a
lib32/libucrtbased.a: lib-common/ucrtbased.mri lib32/libucrtbased_def.a lib32/libucrt_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib32_DATA += lib32/libucrt.a lib32/libucrtapp.a
noinst_LIBRARIES += lib32/libcrtdll_extra.a lib32/libmsvcrt10_extra.a lib32/libmsvcrt20_extra.a lib32/libmsvcrt40_extra.a lib32/libmsvcrt_common.a lib32/libmsvcrt_extra.a lib32/libmsvcrtd_extra.a lib32/libmsvcr70_extra.a lib32/libmsvcr71_extra.a lib32/libmsvcr80_extra.a lib32/libmsvcr90_extra.a lib32/libmsvcr100_extra.a lib32/libmsvcr110_extra.a lib32/libmsvcr120_extra.a lib32/libmsvcr120_app_extra.a lib32/libucrt_extra.a lib32/libucrtapp_extra.a
lib32_libcrtdll_extra_a_SOURCES = $(src_crtdll)
lib32_libcrtdll_extra_a_CPPFLAGS = $(CPPFLAGS32) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib32_libmsvcrt10_extra_a_SOURCES = $(src_msvcrt10)
lib32_libmsvcrt10_extra_a_CPPFLAGS = $(CPPFLAGS32) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib32_libmsvcrt20_extra_a_SOURCES = $(src_msvcrt20)
lib32_libmsvcrt20_extra_a_CPPFLAGS = $(CPPFLAGS32) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib32_libmsvcrt40_extra_a_SOURCES = $(src_msvcrt40)
lib32_libmsvcrt40_extra_a_CPPFLAGS = $(CPPFLAGS32) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib32_libmsvcrt_common_a_SOURCES = $(src_msvcrt_common32)
lib32_libmsvcrt_common_a_CPPFLAGS=$(CPPFLAGS32) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib32_libmsvcrt_extra_a_SOURCES = $(src_msvcrt32)
lib32_libmsvcrt_extra_a_CPPFLAGS=$(CPPFLAGS32) -D__LIBMSVCRT__ -D__LIBMSVCRT_OS__ $(extra_include) $(sysincludes)
lib32_libmsvcrtd_extra_a_SOURCES = $(src_msvcrtd)
lib32_libmsvcrtd_extra_a_CPPFLAGS = $(CPPFLAGS32) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib32_libmsvcr70_extra_a_SOURCES = $(src_msvcr70)
lib32_libmsvcr70_extra_a_CPPFLAGS = $(CPPFLAGS32) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib32_libmsvcr71_extra_a_SOURCES = $(src_msvcr71)
lib32_libmsvcr71_extra_a_CPPFLAGS = $(CPPFLAGS32) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib32_libmsvcr80_extra_a_SOURCES = $(src_msvcr80)
lib32_libmsvcr80_extra_a_CPPFLAGS = $(CPPFLAGS32) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib32_libmsvcr90_extra_a_SOURCES = $(src_msvcr90)
lib32_libmsvcr90_extra_a_CPPFLAGS = $(CPPFLAGS32) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib32_libmsvcr100_extra_a_SOURCES = $(src_msvcr100)
lib32_libmsvcr100_extra_a_CPPFLAGS = $(CPPFLAGS32) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib32_libmsvcr110_extra_a_SOURCES = $(src_msvcr110)
lib32_libmsvcr110_extra_a_CPPFLAGS = $(CPPFLAGS32) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib32_libmsvcr120_extra_a_SOURCES = $(src_msvcr120)
lib32_libmsvcr120_extra_a_CPPFLAGS = $(CPPFLAGS32) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib32_libmsvcr120_app_extra_a_SOURCES = $(src_msvcr120_app)
lib32_libmsvcr120_app_extra_a_CPPFLAGS=$(CPPFLAGS32) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib32_libucrt_extra_a_SOURCES = $(src_ucrtbase32)
lib32_libucrt_extra_a_CPPFLAGS=$(CPPFLAGS32) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib32_libucrtapp_extra_a_SOURCES = $(src_ucrtapp)
lib32_libucrtapp_extra_a_CPPFLAGS=$(CPPFLAGS32) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)

lib32_DATA += lib32/libvcruntime140.a
lib32_DATA += lib32/libvcruntime140d.a
lib32_DATA += lib32/libvcruntime140_app.a
endif

lib32/lib%.a: lib32/%.def
	$(AM_V_GEN)$(DTDEF32) $<

lib32/lib%.a: lib-common/%.def
	$(AM_V_GEN)$(DTDEF32) $<

lib32/lib%_def.a: lib32/%.def
	$(AM_V_GEN)$(DTDEF32) $<

lib32/lib%_def.a: lib-common/%.def
	$(AM_V_GEN)$(DTDEF32) $<

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
	$(AM_V_GEN)$(DTDEF32) $<
lib32/libxapofx.a: lib32/$(xapofx).def
	$(AM_V_GEN)$(DTDEF32) $<
lib32/libx3daudio.a: lib32/$(x3daudio).def
	$(AM_V_GEN)$(DTDEF32) $<
lib32/libd3dx9.a: lib32/$(d3dx9).def
	$(AM_V_GEN)$(DTDEF32) $<
lib32/libd3dx10.a: lib32/$(d3dx10).def
	$(AM_V_GEN)$(DTDEF32) $<
lib32/libd3dx11.a: lib32/$(d3dx11).def
	$(AM_V_GEN)$(DTDEF32) $<
lib32/libd3dcsxd.a: lib32/$(d3dcsxd).def
	$(AM_V_GEN)$(DTDEF32) $<
lib32/libd3dcompiler.a: lib32/$(d3dcompiler).def
	$(AM_V_GEN)$(DTDEF32) $<

endif
# End 32-bit runtime
# ##########



if LIB64
#########################################################################
# Compiling 64-bit runtime
# #######################################################################

lib64dir=$(prefix)/@LIBX8664SUFFIXDIR@
crt64dir=$(lib64dir)
winrt64dir=$(lib64dir)
dx64dir=$(lib64dir)

if !W32API
crt64_DATA = \
  lib64/crt1.o    lib64/crt2.o     lib64/crt1u.o   lib64/crt2u.o   lib64/dllcrt1.o lib64/dllcrt2.o \
  lib64/CRT_fp8.o lib64/CRT_fp10.o lib64/txtmode.o lib64/binmode.o lib64/crtbegin.o lib64/crtend.o \
  lib64/gcrt0.o   lib64/gcrt1.o    lib64/gcrt2.o   lib64/CRT_glob.o lib64/CRT_noglob.o
else
crt64_DATA =
endif

COMPILE64=$(COMPILE) $(CPPFLAGS64) $(extra_include) -D_SYSCRT=1
lib64/crt1.o: crt/crtexe.c
	$(AM_V_CC)$(COMPILE64) -c $< -o $@
lib64/crt2.o: lib64/crt1.o
	$(AM_V_GEN)cp $< $@
lib64/crt1u.o: crt/ucrtexe.c
	$(AM_V_CC)$(COMPILE64) -c $< -o $@
lib64/crt2u.o: lib64/crt1u.o
	$(AM_V_GEN)cp $< $@
lib64/dllcrt1.o: crt/crtdll.c
	$(AM_V_CC)$(COMPILE64) -c $< -o $@
lib64/dllcrt2.o: lib64/dllcrt1.o
	$(AM_V_GEN)cp $< $@

lib64/gcrt0.o: profile/gcrt0.c
	$(AM_V_CC)$(COMPILE) $(CPPFLAGS64) -c $< -o $@
lib64/gcrt1.o: lib64/gcrt0.o
	$(AM_V_GEN)cp $< $@
lib64/gcrt2.o: lib64/gcrt0.o
	$(AM_V_GEN)cp $< $@

lib64/%.o: crt/%.c
	$(AM_V_CC)$(COMPILE) $(CPPFLAGS64) -c $< -o $@

lib64_LIBRARIES = lib64/libkernel32.a
lib64_libkernel32_a_SOURCES = $(src_intrincs) $(src_intrincs64) lib-common/kernel32.def.in
lib64_libkernel32_a_CPPFLAGS=$(CPPFLAGS64) $(extra_include) $(AM_CPPFLAGS)
lib64_libkernel32_a_AR = $(DTDEF64) lib64/kernel32.def && $(AR) $(ARFLAGS)
EXTRA_lib64_libkernel32_a_DEPENDENCIES=lib64/kernel32.def

lib64_DATA =
if !W32API
lib64_DATA += lib64/libmsvcrt.a
lib64/libmsvcrt.a: lib64/@MSVCRT_LIB@
	$(AM_V_GEN)cp $< $@

lib64_DATA += lib64/libmsvcrt-os.a
lib64/libmsvcrt-os.a: lib-common/msvcrt-os.mri lib64/libmsvcrt_def.a lib64/libmsvcrt_common.a lib64/libmsvcrt_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)
endif

lib64_LIBRARIES += lib64/libbits.a
lib64_libbits_a_SOURCES = $(src_libbits)
lib64_libbits_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libshell32.a
lib64_libshell32_a_SOURCES = $(src_libshell32)
lib64_libshell32_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)
lib64_libshell32_a_AR = $(DTDEF64) $(top_srcdir)/lib-common/shell32.def && $(AR) $(ARFLAGS)

lib64_LIBRARIES += lib64/libdinput.a
lib64_libdinput_a_SOURCES = $(src_libdinput)
lib64_libdinput_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)
lib64_libdinput_a_AR = $(DTDEF64) $(top_srcdir)/lib-common/dinput.def && $(AR) $(ARFLAGS)

lib64_LIBRARIES += lib64/libdinput8.a
lib64_libdinput8_a_SOURCES = $(src_libdinput8)
lib64_libdinput8_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)
lib64_libdinput8_a_AR = $(DTDEF64) $(top_srcdir)/lib-common/dinput8.def && $(AR) $(ARFLAGS)

lib64_LIBRARIES += lib64/libdmoguids.a
lib64_libdmoguids_a_SOURCES = $(src_libdmoguids)
lib64_libdmoguids_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libdxerr8.a
lib64_libdxerr8_a_SOURCES = $(src_libdxerr8)
lib64_libdxerr8_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libdxerr9.a
lib64_libdxerr9_a_SOURCES = $(src_libdxerr9)
lib64_libdxerr9_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libmsxml2.a
lib64_libmsxml2_a_SOURCES = $(src_libmsxml2)
lib64_libmsxml2_a_CPPFLAGS = $(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libmsxml6.a
lib64_libmsxml6_a_SOURCES = $(src_libmsxml6)
lib64_libmsxml6_a_CPPFLAGS = $(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libmfuuid.a
lib64_libmfuuid_a_SOURCES = $(src_libmfuuid)
lib64_libmfuuid_a_CPPFLAGS = $(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libamstrmid.a
lib64_libamstrmid_a_SOURCES = $(src_libamstrmid)
lib64_libamstrmid_a_CPPFLAGS = $(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libwmcodecdspuuid.a
lib64_libwmcodecdspuuid_a_SOURCES = $(src_libwmcodecdspuuid)
lib64_libwmcodecdspuuid_a_CPPFLAGS = $(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libwindowscodecs.a
lib64_libwindowscodecs_a_SOURCES = $(src_libwindowscodecs)
lib64_libwindowscodecs_a_CPPFLAGS = $(CPPFLAGS64) $(sysincludes)
lib64_libwindowscodecs_a_AR = $(DTDEF64) $(top_srcdir)/lib-common/windowscodecs.def && $(AR) $(ARFLAGS)

lib64_LIBRARIES += lib64/libwbemuuid.a
lib64_libwbemuuid_a_SOURCES = $(src_libwbemuuid)
lib64_libwbemuuid_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libdxguid.a
lib64_libdxguid_a_SOURCES = $(src_libdxguid)
lib64_libdxguid_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/liblocationapi.a
lib64_liblocationapi_a_SOURCES = $(src_liblocationapi)
lib64_liblocationapi_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libsapi.a
lib64_libsapi_a_SOURCES = $(src_libsapi)
lib64_libsapi_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libsensorsapi.a
lib64_libsensorsapi_a_SOURCES = $(src_libsensorsapi)
lib64_libsensorsapi_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libportabledeviceguids.a
lib64_libportabledeviceguids_a_SOURCES = $(src_libportabledeviceguids)
lib64_libportabledeviceguids_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libksuser.a
lib64_libksuser_a_SOURCES = $(src_libksuser)
lib64_libksuser_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)
lib64_libksuser_a_AR = $(DTDEF64) $(top_srcdir)/lib-common/ksuser.def && $(AR) $(ARFLAGS)

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

lib64_LIBRARIES += lib64/libwiaguid.a
lib64_libwiaguid_a_SOURCES = $(src_libwiaguid)
lib64_libwiaguid_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libgdiplus.a
lib64_libgdiplus_a_SOURCES = $(src_libgdiplus)
lib64_libgdiplus_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)
lib64_libgdiplus_a_AR = $(DTDEF64) $(top_srcdir)/lib-common/gdiplus.def && $(AR) $(ARFLAGS)

lib64_LIBRARIES += lib64/libws2_32.a
lib64_libws2_32_a_SOURCES = $(src_libws2_32) lib-common/ws2_32.def.in
lib64_libws2_32_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)
lib64_libws2_32_a_AR = $(DTDEF64) lib64/ws2_32.def && $(AR) $(ARFLAGS)
EXTRA_lib64_libws2_32_a_DEPENDENCIES=lib64/ws2_32.def

lib64_LIBRARIES += lib64/libtaskschd.a
lib64_libtaskschd_a_SOURCES = $(src_libtaskschd)
lib64_libtaskschd_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libadsiid.a
lib64_libadsiid_a_SOURCES = $(src_adsiid)
lib64_libadsiid_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libdloadhelper.a
lib64_libdloadhelper_a_SOURCES = $(src_libdloadhelper)
lib64_libdloadhelper_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

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
lib64_libmingw32_a_CPPFLAGS=$(CPPFLAGS64) -D_SYSCRT=1 $(extra_include) $(AM_CPPFLAGS)
lib64_libmingw32_a_SOURCES = $(src_libmingw32) crt/CRT_fp10.c

lib64_LIBRARIES += lib64/libmingwex.a
lib64_libmingwex_a_CPPFLAGS=$(CPPFLAGS64) $(extra_include) $(AM_CPPFLAGS)
lib64_libmingwex_a_SOURCES = $(src_libmingwex) $(src_libmingwex64) $(src_dfp_math)

lib64_LIBRARIES += lib64/libmoldname.a
lib64_libmoldname_a_CPPFLAGS=$(CPPFLAGS64) $(extra_include) $(AM_CPPFLAGS)
lib64_libmoldname_a_SOURCES = $(src_libm)

lib64_LIBRARIES += lib64/libmingwthrd.a
lib64_libmingwthrd_a_SOURCES = $(src_libmingwthrd)
lib64_libmingwthrd_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

processed_defs += lib64/msvcrt.def lib64/msvcr80.def lib64/msvcr80d.def lib64/msvcr90.def lib64/msvcr90d.def \
				  lib64/msvcr100.def lib64/msvcr100d.def lib64/msvcr110.def lib64/msvcr110d.def lib64/msvcr120.def lib64/msvcr120d.def \
				  lib64/msvcr120_app.def lib64/msvcp120_app.def lib64/ucrtbase.def lib64/ucrtbased.def \
				  lib64/advapi32.def lib64/clbcatq.def lib64/kernel32.def lib64/ole32.def \
				  lib64/oleaut32.def lib64/user32.def lib64/winhvplatform.def lib64/ws2_32.def \
				  lib64/api-ms-win-crt-math-l1-1-0.def lib64/api-ms-win-crt-private-l1-1-0.def lib64/api-ms-win-crt-runtime-l1-1-0.def \
				  lib64/api-ms-win-crt-filesystem-l1-1-0.def lib64/api-ms-win-crt-time-l1-1-0.def \
				  lib64/vcruntime140.def lib64/vcruntime140d.def lib64/vcruntime140_app.def

endif

include lib64/Makefile.am

if !W32API
lib64_DATA += lib64/libmsvcp60.a lib64/libmsvcp120_app.a

lib64_DATA += lib64/libmsvcr80.a
lib64/libmsvcr80.a: lib-common/msvcr80.mri lib64/libmsvcr80_def.a lib64/libmsvcrt_common.a lib64/libmsvcr80_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib64_DATA += lib64/libmsvcr80d.a
lib64/libmsvcr80d.a: lib-common/msvcr80d.mri lib64/libmsvcr80d_def.a lib64/libmsvcrt_common.a lib64/libmsvcr80_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib64_DATA += lib64/libmsvcr90.a
lib64/libmsvcr90.a: lib-common/msvcr90.mri lib64/libmsvcr90_def.a lib64/libmsvcrt_common.a lib64/libmsvcr90_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib64_DATA += lib64/libmsvcr90d.a
lib64/libmsvcr90d.a: lib-common/msvcr90d.mri lib64/libmsvcr90d_def.a lib64/libmsvcrt_common.a lib64/libmsvcr90_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib64_DATA += lib64/libmsvcr100.a
lib64/libmsvcr100.a: lib-common/msvcr100.mri lib64/libmsvcr100_def.a lib64/libmsvcrt_common.a lib64/libmsvcr100_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib64_DATA += lib64/libmsvcr100d.a
lib64/libmsvcr100d.a: lib-common/msvcr100d.mri lib64/libmsvcr100d_def.a lib64/libmsvcrt_common.a lib64/libmsvcr100_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib64_DATA += lib64/libmsvcr110.a
lib64/libmsvcr110.a: lib-common/msvcr110.mri lib64/libmsvcr110_def.a lib64/libmsvcrt_common.a lib64/libmsvcr110_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib64_DATA += lib64/libmsvcr110d.a
lib64/libmsvcr110d.a: lib-common/msvcr110d.mri lib64/libmsvcr110d_def.a lib64/libmsvcrt_common.a lib64/libmsvcr110_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib64_DATA += lib64/libmsvcr120.a
lib64/libmsvcr120.a: lib-common/msvcr120.mri lib64/libmsvcr120_def.a lib64/libmsvcrt_common.a lib64/libmsvcr120_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib64_DATA += lib64/libmsvcr120d.a
lib64/libmsvcr120d.a: lib-common/msvcr120d.mri lib64/libmsvcr120d_def.a lib64/libmsvcrt_common.a lib64/libmsvcr120_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib64_DATA += lib64/libmsvcr120_app.a
lib64/libmsvcr120_app.a: lib-common/msvcr120_app.mri lib64/libmsvcr120_app_def.a lib64/libmsvcrt_common.a lib64/libmsvcr120_extra.a lib64/libmsvcr120_app_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib64_DATA += lib64/libucrtbase.a
lib64/libucrtbase.a: lib-common/ucrtbase.mri lib64/libucrtbase_def.a lib64/libucrt_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib64_DATA += lib64/libucrtbased.a
lib64/libucrtbased.a: lib-common/ucrtbased.mri lib64/libucrtbased_def.a lib64/libucrt_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

lib64_DATA += lib64/libucrt.a lib64/libucrtapp.a
noinst_LIBRARIES += lib64/libmsvcrt_common.a lib64/libmsvcrt_extra.a lib64/libmsvcr80_extra.a lib64/libmsvcr90_extra.a lib64/libmsvcr100_extra.a lib64/libmsvcr110_extra.a lib64/libmsvcr120_extra.a lib64/libmsvcr120_app_extra.a lib64/libucrt_extra.a lib64/libucrtapp_extra.a
lib64_libmsvcrt_common_a_SOURCES = $(src_msvcrt_common64)
lib64_libmsvcrt_common_a_CPPFLAGS=$(CPPFLAGS64) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib64_libmsvcrt_extra_a_SOURCES = $(src_msvcrt64)
lib64_libmsvcrt_extra_a_CPPFLAGS=$(CPPFLAGS64) -D__LIBMSVCRT__ -D__LIBMSVCRT_OS__ $(extra_include) $(sysincludes)
lib64_libmsvcr80_extra_a_SOURCES = $(src_msvcr80)
lib64_libmsvcr80_extra_a_CPPFLAGS=$(CPPFLAGS64) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib64_libmsvcr90_extra_a_SOURCES = $(src_msvcr90)
lib64_libmsvcr90_extra_a_CPPFLAGS=$(CPPFLAGS64) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib64_libmsvcr100_extra_a_SOURCES = $(src_msvcr100)
lib64_libmsvcr100_extra_a_CPPFLAGS=$(CPPFLAGS64) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib64_libmsvcr110_extra_a_SOURCES = $(src_msvcr110)
lib64_libmsvcr110_extra_a_CPPFLAGS=$(CPPFLAGS64) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib64_libmsvcr120_extra_a_SOURCES = $(src_msvcr120)
lib64_libmsvcr120_extra_a_CPPFLAGS=$(CPPFLAGS64) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib64_libmsvcr120_app_extra_a_SOURCES = $(src_msvcr120_app)
lib64_libmsvcr120_app_extra_a_CPPFLAGS=$(CPPFLAGS64) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib64_libucrt_extra_a_SOURCES = $(src_ucrtbase64)
lib64_libucrt_extra_a_CPPFLAGS=$(CPPFLAGS64) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib64_libucrtapp_extra_a_SOURCES = $(src_ucrtapp)
lib64_libucrtapp_extra_a_CPPFLAGS=$(CPPFLAGS64) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)

lib64_DATA += lib64/libvcruntime140.a
lib64_DATA += lib64/libvcruntime140d.a
lib64_DATA += lib64/libvcruntime140_app.a
endif

lib64/lib%.a: lib64/%.def
	$(AM_V_GEN)$(DTDEF64) $<

lib64/lib%.a: lib-common/%.def
	$(AM_V_GEN)$(DTDEF64) $<

lib64/lib%_def.a: lib64/%.def
	$(AM_V_GEN)$(DTDEF64) $<

lib64/lib%_def.a: lib-common/%.def
	$(AM_V_GEN)$(DTDEF64) $<

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
	$(AM_V_GEN)$(DTDEF64) $<
lib64/libxapofx.a: lib64/$(xapofx).def
	$(AM_V_GEN)$(DTDEF64) $<
lib64/libx3daudio.a: lib64/$(x3daudio).def
	$(AM_V_GEN)$(DTDEF64) $<
lib64/libd3dx9.a: lib64/$(d3dx9).def
	$(AM_V_GEN)$(DTDEF64) $<
lib64/libd3dx10.a: lib64/$(d3dx10).def
	$(AM_V_GEN)$(DTDEF64) $<
lib64/libd3dx11.a: lib64/$(d3dx11).def
	$(AM_V_GEN)$(DTDEF64) $<
lib64/libd3dcsxd.a: lib64/$(d3dcsxd).def
	$(AM_V_GEN)$(DTDEF64) $<
lib64/libd3dcompiler.a: lib-common/$(d3dcompiler).def
	$(AM_V_GEN)$(DTDEF64) $<

endif
# End 64-bit runtime
##########



if LIBARM32
#########
# Compiling ARM 32-bit runtime
#

libarm32dir=$(prefix)/@LIBARM32SUFFIXDIR@
crt32dir=$(libarm32dir)
winrt32dir=$(libarm32dir)
dx32dir=$(libarm32dir)

if !W32API
crt32_DATA = \
  libarm32/crt1.o    libarm32/crt2.o     libarm32/crt1u.o   libarm32/crt2u.o    libarm32/dllcrt1.o    libarm32/dllcrt2.o \
  libarm32/CRT_fp8.o libarm32/txtmode.o  libarm32/binmode.o libarm32/crtbegin.o libarm32/crtend.o \
  libarm32/gcrt0.o   libarm32/gcrt1.o    libarm32/gcrt2.o   libarm32/CRT_glob.o libarm32/CRT_noglob.o
else
crt32_DATA =
endif

COMPILE32=$(COMPILE) $(CPPFLAGSARM32) $(extra_include) -D_SYSCRT=1
libarm32/crt1.o: crt/crtexe.c
	$(AM_V_CC)$(COMPILE32) -c $< -o $@
libarm32/crt2.o: libarm32/crt1.o
	$(AM_V_GEN)cp $< $@
libarm32/crt1u.o: crt/ucrtexe.c
	$(AM_V_CC)$(COMPILE32) -c $< -o $@
libarm32/crt2u.o: libarm32/crt1u.o
	$(AM_V_GEN)cp $< $@
libarm32/dllcrt1.o: crt/crtdll.c
	$(AM_V_CC)$(COMPILE32) -c $< -o $@
libarm32/dllcrt2.o: libarm32/dllcrt1.o
	$(AM_V_GEN)cp $< $@

libarm32/gcrt0.o: profile/gcrt0.c
	$(AM_V_CC)$(COMPILE) $(CPPFLAGSARM32) -c $< -o $@
libarm32/gcrt1.o: libarm32/gcrt0.o
	$(AM_V_GEN)cp $< $@
libarm32/gcrt2.o: libarm32/gcrt0.o
	$(AM_V_GEN)cp $< $@

libarm32/%.o: crt/%.c
	$(AM_V_CC)$(COMPILE) $(CPPFLAGSARM32) -c $< -o $@

# These source files aren't compiled in to any library yet.  I'm not sure how / where to do so.
# The source files that I did compile somewhere I just guessed at anyway.
#

temp= \
dxerr.c \
test.c

libarm32_LIBRARIES = libarm32/libkernel32.a
libarm32_libkernel32_a_SOURCES = $(src_intrincs) $(src_intrincsarm32) lib-common/kernel32.def.in
libarm32_libkernel32_a_AR = $(DTDEFARM32) libarm32/kernel32.def && $(AR) $(ARFLAGS)
libarm32_libkernel32_a_CPPFLAGS=$(CPPFLAGSARM32) $(extra_include) $(AM_CPPFLAGS)
EXTRA_libarm32_libkernel32_a_DEPENDENCIES=libarm32/kernel32.def

libarm32_DATA =
if !W32API
libarm32_DATA += libarm32/libmsvcrt.a
libarm32/libmsvcrt.a: libarm32/@MSVCRT_LIB@
	$(AM_V_GEN)cp $< $@

libarm32_DATA += libarm32/libmsvcrt-os.a
libarm32/libmsvcrt-os.a: lib-common/msvcrt-os.mri libarm32/libmsvcrt_def.a libarm32/libmsvcrt_common.a libarm32/libmsvcrt_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)
endif

libarm32_LIBRARIES += libarm32/libbits.a
libarm32_libbits_a_SOURCES = $(src_libbits)
libarm32_libbits_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/libshell32.a
libarm32_libshell32_a_SOURCES = $(src_libshell32)
libarm32_libshell32_a_AR = $(DTDEFARM32) $(top_srcdir)/lib-common/shell32.def && $(AR) $(ARFLAGS)
libarm32_libshell32_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/libdinput.a
libarm32_libdinput_a_SOURCES = $(src_libdinput)
libarm32_libdinput_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)
libarm32_libdinput_a_AR = $(DTDEFARM32) $(top_srcdir)/lib-common/dinput.def && $(AR) $(ARFLAGS)

libarm32_LIBRARIES += libarm32/libdinput8.a
libarm32_libdinput8_a_SOURCES = $(src_libdinput8)
libarm32_libdinput8_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)
libarm32_libdinput8_a_AR = $(DTDEFARM32) $(top_srcdir)/lib-common/dinput8.def && $(AR) $(ARFLAGS)

libarm32_LIBRARIES += libarm32/libdmoguids.a
libarm32_libdmoguids_a_SOURCES = $(src_libdmoguids)
libarm32_libdmoguids_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/libdxerr8.a
libarm32_libdxerr8_a_SOURCES = $(src_libdxerr8)
libarm32_libdxerr8_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/libdxerr9.a
libarm32_libdxerr9_a_SOURCES = $(src_libdxerr9)
libarm32_libdxerr9_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/libmsxml2.a
libarm32_libmsxml2_a_SOURCES = $(src_libmsxml2)
libarm32_libmsxml2_a_CPPFLAGS = $(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/libmsxml6.a
libarm32_libmsxml6_a_SOURCES = $(src_libmsxml6)
libarm32_libmsxml6_a_CPPFLAGS = $(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/libmfuuid.a
libarm32_libmfuuid_a_SOURCES = $(src_libmfuuid)
libarm32_libmfuuid_a_CPPFLAGS = $(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/libamstrmid.a
libarm32_libamstrmid_a_SOURCES = $(src_libamstrmid)
libarm32_libamstrmid_a_CPPFLAGS = $(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/libwmcodecdspuuid.a
libarm32_libwmcodecdspuuid_a_SOURCES = $(src_libwmcodecdspuuid)
libarm32_libwmcodecdspuuid_a_CPPFLAGS = $(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/libwindowscodecs.a
libarm32_libwindowscodecs_a_SOURCES = $(src_libwindowscodecs)
libarm32_libwindowscodecs_a_CPPFLAGS = $(CPPFLAGSARM32) $(sysincludes)
libarm32_libwindowscodecs_a_AR = $(DTDEFARM32) $(top_srcdir)/lib-common/windowscodecs.def && $(AR) $(ARFLAGS)

libarm32_LIBRARIES += libarm32/libwbemuuid.a
libarm32_libwbemuuid_a_SOURCES = $(src_libwbemuuid)
libarm32_libwbemuuid_a_CPPFLAGS = $(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/libdxguid.a
libarm32_libdxguid_a_SOURCES = $(src_libdxguid)
libarm32_libdxguid_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/libksuser.a
libarm32_libksuser_a_SOURCES = $(src_libksuser)
libarm32_libksuser_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)
libarm32_libksuser_a_AR = $(DTDEFARM32) $(top_srcdir)/lib-common/ksuser.def && $(AR) $(ARFLAGS)

libarm32_LIBRARIES += libarm32/libksguid.a
libarm32_libksguid_a_SOURCES = $(src_libksguid)
libarm32_libksguid_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/liblocationapi.a
libarm32_liblocationapi_a_SOURCES = $(src_liblocationapi)
libarm32_liblocationapi_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/libsensorsapi.a
libarm32_libsensorsapi_a_SOURCES = $(src_libsensorsapi)
libarm32_libsensorsapi_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/libsapi.a
libarm32_libsapi_a_SOURCES = $(src_libsapi)
libarm32_libsapi_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/libportabledeviceguids.a
libarm32_libportabledeviceguids_a_SOURCES = $(src_libportabledeviceguids)
libarm32_libportabledeviceguids_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/libscrnsave.a
libarm32_libscrnsave_a_SOURCES = $(src_libscrnsave)
libarm32_libscrnsave_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/libscrnsavw.a
libarm32_libscrnsavw_a_SOURCES = $(src_libscrnsavw)
libarm32_libscrnsavw_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)
libarm32_libscrnsavw_a_CFLAGS = -DUNICODE

libarm32_LIBRARIES += libarm32/libstrmiids.a
libarm32_libstrmiids_a_SOURCES = $(src_libstrmiids)
libarm32_libstrmiids_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/libuuid.a
libarm32_libuuid_a_SOURCES = $(src_libuuid)
libarm32_libuuid_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/libwiaguid.a
libarm32_libwiaguid_a_SOURCES = $(src_libwiaguid)
libarm32_libwiaguid_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/libgdiplus.a
libarm32_libgdiplus_a_SOURCES = $(src_libgdiplus)
libarm32_libgdiplus_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)
libarm32_libgdiplus_a_AR = $(DTDEFARM32) $(top_srcdir)/lib-common/gdiplus.def && $(AR) $(ARFLAGS)

libarm32_LIBRARIES += libarm32/libws2_32.a
libarm32_libws2_32_a_SOURCES = $(src_libws2_32) lib-common/libws2_32.def.in
libarm32_libws2_32_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)
libarm32_libws2_32_a_AR = $(DTDEFARM32) libarm32/ws2_32.def && $(AR) $(ARFLAGS)
EXTRA_libarm32_libws2_32_a_DEPENDENCIES=libarm32/ws2_32.def

libarm32_LIBRARIES += libarm32/libadsiid.a
libarm32_libadsiid_a_SOURCES = $(src_adsiid)
libarm32_libadsiid_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/libdloadhelper.a
libarm32_libdloadhelper_a_SOURCES = $(src_libdloadhelper)
libarm32_libdloadhelper_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)

if !W32API
libarm32_LIBRARIES += libarm32/libdelayimp.a
libarm32_libdelayimp_a_SOURCES =

libarm32_LIBRARIES += libarm32/libm.a
nodist_libarm32_libm_a_SOURCES = $(src_libm)
libarm32_libm_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)

#libarm32_LIBRARIES += libarm32/libgmon.a
#libarm32_libgmon_a_SOURCES = profile/mcount.c \
#  profile/profil.h profile/profil.c        \
#  profile/gmon.h   profile/gmon.c \
#  profile/mcountFunc.S
#libarm32_libgmon_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/liblargeint.a
libarm32_liblargeint_a_SOURCES = $(src_liblargeint)
libarm32_liblargeint_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)

libarm32_LIBRARIES += libarm32/libmingw32.a
libarm32_libmingw32_a_CPPFLAGS=$(CPPFLAGSARM32) -D_SYSCRT=1 $(extra_include) $(AM_CPPFLAGS)
libarm32_libmingw32_a_SOURCES = $(src_libmingw32)

libarm32_LIBRARIES += libarm32/libmingwex.a
libarm32_libmingwex_a_CPPFLAGS=$(CPPFLAGSARM32) $(extra_include) $(AM_CPPFLAGS)
libarm32_libmingwex_a_SOURCES = $(src_libmingwex) $(src_libmingwexarm32) $(src_dfp_math)

libarm32_LIBRARIES += libarm32/libmoldname.a
libarm32_libmoldname_a_CPPFLAGS=$(CPPFLAGSARM32) $(extra_include) $(AM_CPPFLAGS)
libarm32_libmoldname_a_SOURCES = $(src_libm)

libarm32_LIBRARIES += libarm32/libmingwthrd.a
libarm32_libmingwthrd_a_SOURCES = $(src_libmingwthrd)
libarm32_libmingwthrd_a_CPPFLAGS=$(CPPFLAGSARM32) $(sysincludes)

processed_defs += libarm32/msvcrt.def libarm32/msvcr110.def libarm32/msvcr110d.def libarm32/msvcr120.def libarm32/msvcr120d.def libarm32/msvcr120_app.def \
				  libarm32/ucrtbase.def libarm32/ucrtbased.def \
				  libarm32/advapi32.def libarm32/clbcatq.def libarm32/kernel32.def libarm32/ole32.def libarm32/oleaut32.def \
				  libarm32/user32.def libarm32/ws2_32.def \
				  libarm32/api-ms-win-crt-math-l1-1-0.def libarm32/api-ms-win-crt-private-l1-1-0.def libarm32/api-ms-win-crt-runtime-l1-1-0.def \
				  libarm32/api-ms-win-crt-filesystem-l1-1-0.def libarm32/api-ms-win-crt-time-l1-1-0.def \
				  libarm32/vcruntime140.def libarm32/vcruntime140d.def libarm32/vcruntime140_app.def

endif

include libarm32/Makefile.am

if !W32API
libarm32_DATA += libarm32/libmsvcp60.a

libarm32_DATA += libarm32/libmsvcr110.a
libarm32/libmsvcr110.a: lib-common/msvcr110.mri libarm32/libmsvcr110_def.a libarm32/libmsvcrt_common.a libarm32/libmsvcr110_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

libarm32_DATA += libarm32/libmsvcr110d.a
libarm32/libmsvcr110d.a: lib-common/msvcr110d.mri libarm32/libmsvcr110d_def.a libarm32/libmsvcrt_common.a libarm32/libmsvcr110_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

libarm32_DATA += libarm32/libmsvcr120.a
libarm32/libmsvcr120.a: lib-common/msvcr120.mri libarm32/libmsvcr120_def.a libarm32/libmsvcrt_common.a libarm32/libmsvcr120_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

libarm32_DATA += libarm32/libmsvcr120d.a
libarm32/libmsvcr120d.a: lib-common/msvcr120d.mri libarm32/libmsvcr120d_def.a libarm32/libmsvcrt_common.a libarm32/libmsvcr120_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

libarm32_DATA += libarm32/libmsvcr120_app.a
libarm32/libmsvcr120_app.a: lib-common/msvcr120_app.mri libarm32/libmsvcr120_app_def.a libarm32/libmsvcrt_common.a libarm32/libmsvcr120_app_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

libarm32_DATA += libarm32/libucrtbase.a
libarm32/libucrtbase.a: lib-common/ucrtbase.mri libarm32/libucrtbase_def.a libarm32/libucrt_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

libarm32_DATA += libarm32/libucrtbased.a
libarm32/libucrtbased.a: lib-common/ucrtbased.mri libarm32/libucrtbased_def.a libarm32/libucrt_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

libarm32_DATA += libarm32/libucrt.a libarm32/libucrtapp.a
noinst_LIBRARIES += libarm32/libmsvcrt_common.a libarm32/libmsvcrt_extra.a libarm32/libmsvcr110_extra.a libarm32/libmsvcr120_extra.a libarm32/libmsvcr120_app_extra.a libarm32/libucrt_extra.a libarm32/libucrtapp_extra.a
libarm32_libmsvcrt_common_a_SOURCES = $(src_msvcrt_commonarm32)
libarm32_libmsvcrt_common_a_CPPFLAGS=$(CPPFLAGSARM32) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
libarm32_libmsvcrt_extra_a_SOURCES = $(src_msvcrtarm32)
libarm32_libmsvcrt_extra_a_CPPFLAGS=$(CPPFLAGSARM32) -D__LIBMSVCRT__ -D__LIBMSVCRT_OS__ $(extra_include) $(sysincludes)
libarm32_libmsvcr110_extra_a_SOURCES = $(src_msvcr110)
libarm32_libmsvcr110_extra_a_CPPFLAGS=$(CPPFLAGSARM32) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
libarm32_libmsvcr120_extra_a_SOURCES = $(src_msvcr120)
libarm32_libmsvcr120_extra_a_CPPFLAGS=$(CPPFLAGSARM32) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
libarm32_libmsvcr120_app_extra_a_SOURCES = $(src_msvcr120_app)
libarm32_libmsvcr120_app_extra_a_CPPFLAGS=$(CPPFLAGSARM32) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
libarm32_libucrt_extra_a_SOURCES = $(src_ucrtbasearm32)
libarm32_libucrt_extra_a_CPPFLAGS=$(CPPFLAGSARM32) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
libarm32_libucrtapp_extra_a_SOURCES = $(src_ucrtapp)
libarm32_libucrtapp_extra_a_CPPFLAGS=$(CPPFLAGSARM32) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)

libarm32_DATA += libarm32/libvcruntime140.a
libarm32_DATA += libarm32/libvcruntime140d.a
libarm32_DATA += libarm32/libvcruntime140_app.a
endif

libarm32/lib%.a: libarm32/%.def
	$(AM_V_GEN)$(DTDEFARM32) $<

libarm32/lib%.a: lib-common/%.def
	$(AM_V_GEN)$(DTDEFARM32) $<

libarm32/lib%_def.a: libarm32/%.def
	$(AM_V_GEN)$(DTDEFARM32) $<

libarm32/lib%_def.a: lib-common/%.def
	$(AM_V_GEN)$(DTDEFARM32) $<

dx32_DATA =
dx32_DATA += libarm32/libxinput.a
dx32_DATA += libarm32/libd3dcompiler.a

libarm32/libxinput.a: lib-common/xinput1_4.def
	$(AM_V_GEN)$(DTDEFARM32) $<
libarm32/libd3dcompiler.a: lib-common/d3dcompiler_47.def
	$(AM_V_GEN)$(DTDEFARM32) $<

endif
# End ARM 32-bit runtime
# ##########

if LIBARM64
#########
# Compiling ARM 64-bit runtime
#

libarm64dir=$(prefix)/@LIBARM64SUFFIXDIR@
crt64dir=$(libarm64dir)
winrt64dir=$(libarm64dir)
dx64dir=$(libarm64dir)

if !W32API
crt64_DATA = \
  libarm64/crt1.o    libarm64/crt2.o     libarm64/crt1u.o   libarm64/crt2u.o    libarm64/dllcrt1.o    libarm64/dllcrt2.o \
  libarm64/CRT_fp8.o libarm64/txtmode.o  libarm64/binmode.o libarm64/crtbegin.o libarm64/crtend.o \
  libarm64/gcrt0.o   libarm64/gcrt1.o    libarm64/gcrt2.o   libarm64/CRT_glob.o libarm64/CRT_noglob.o
else
crt64_DATA =
endif

COMPILE64=$(COMPILE) $(CPPFLAGSARM64) $(extra_include) -D_SYSCRT=1
libarm64/crt1.o: crt/crtexe.c
	$(AM_V_CC)$(COMPILE64) -c $< -o $@
libarm64/crt2.o: libarm64/crt1.o
	$(AM_V_GEN)cp $< $@
libarm64/crt1u.o: crt/ucrtexe.c
	$(AM_V_CC)$(COMPILE64) -c $< -o $@
libarm64/crt2u.o: libarm64/crt1u.o
	$(AM_V_GEN)cp $< $@
libarm64/dllcrt1.o: crt/crtdll.c
	$(AM_V_CC)$(COMPILE64) -c $< -o $@
libarm64/dllcrt2.o: libarm64/dllcrt1.o
	$(AM_V_GEN)cp $< $@

libarm64/gcrt0.o: profile/gcrt0.c
	$(AM_V_CC)$(COMPILE) $(CPPFLAGSARM64) -c $< -o $@
libarm64/gcrt1.o: libarm64/gcrt0.o
	$(AM_V_GEN)cp $< $@
libarm64/gcrt2.o: libarm64/gcrt0.o
	$(AM_V_GEN)cp $< $@

libarm64/%.o: crt/%.c
	$(AM_V_CC)$(COMPILE) $(CPPFLAGSARM64) -c $< -o $@

libarm64/%.x86_64.o: %.S
	$(AM_V_CC)$(MKDIR_P) $(@D) && $(COMPILE) $(CPPFLAGSARM64) -target x86_64-windows-gnu -c $< -o $@

# These source files aren't compiled in to any library yet.  I'm not sure how / where to do so.
# The source files that I did compile somewhere I just guessed at anyway.
#

temp= \
dxerr.c \
test.c

libarm64_LIBRARIES = libarm64/libkernel32.a
libarm64_libkernel32_a_SOURCES = $(src_intrincs) $(src_intrincsarm64) lib-common/kernel32.def.in
libarm64_libkernel32_a_AR = $(DTDEFARM64) libarm64/kernel32.def && $(AR) $(ARFLAGS)
libarm64_libkernel32_a_CPPFLAGS=$(CPPFLAGSARM64) $(extra_include) $(AM_CPPFLAGS)
EXTRA_libarm64_libkernel32_a_DEPENDENCIES=libarm64/kernel32.def

libarm64_DATA =
if !W32API
libarm64_DATA += libarm64/libmsvcrt.a
libarm64/libmsvcrt.a: libarm64/@MSVCRT_LIB@
	$(AM_V_GEN)cp $< $@

libarm64_DATA += libarm64/libmsvcrt-os.a
libarm64/libmsvcrt-os.a: lib-common/msvcrt-os.mri libarm64/libmsvcrt_def.a libarm64/libmsvcrt_common.a libarm64/libmsvcrt_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)
endif

libarm64_LIBRARIES += libarm64/libbits.a
libarm64_libbits_a_SOURCES = $(src_libbits)
libarm64_libbits_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libshell32.a
libarm64_libshell32_a_SOURCES = $(src_libshell32)
libarm64_libshell32_a_AR = $(DTDEFARM64) $(top_srcdir)/lib-common/shell32.def && $(AR) $(ARFLAGS)
libarm64_libshell32_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libdinput.a
libarm64_libdinput_a_SOURCES = $(src_libdinput)
libarm64_libdinput_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)
libarm64_libdinput_a_AR = $(DTDEFARM64) $(top_srcdir)/lib-common/dinput.def && $(AR) $(ARFLAGS)

libarm64_LIBRARIES += libarm64/libdinput8.a
libarm64_libdinput8_a_SOURCES = $(src_libdinput8)
libarm64_libdinput8_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)
libarm64_libdinput8_a_AR = $(DTDEFARM64) $(top_srcdir)/lib-common/dinput8.def && $(AR) $(ARFLAGS)

libarm64_LIBRARIES += libarm64/libdmoguids.a
libarm64_libdmoguids_a_SOURCES = $(src_libdmoguids)
libarm64_libdmoguids_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libdxerr8.a
libarm64_libdxerr8_a_SOURCES = $(src_libdxerr8)
libarm64_libdxerr8_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libdxerr9.a
libarm64_libdxerr9_a_SOURCES = $(src_libdxerr9)
libarm64_libdxerr9_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libmsxml2.a
libarm64_libmsxml2_a_SOURCES = $(src_libmsxml2)
libarm64_libmsxml2_a_CPPFLAGS = $(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libmsxml6.a
libarm64_libmsxml6_a_SOURCES = $(src_libmsxml6)
libarm64_libmsxml6_a_CPPFLAGS = $(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libmfuuid.a
libarm64_libmfuuid_a_SOURCES = $(src_libmfuuid)
libarm64_libmfuuid_a_CPPFLAGS = $(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libamstrmid.a
libarm64_libamstrmid_a_SOURCES = $(src_libamstrmid)
libarm64_libamstrmid_a_CPPFLAGS = $(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libwmcodecdspuuid.a
libarm64_libwmcodecdspuuid_a_SOURCES = $(src_libwmcodecdspuuid)
libarm64_libwmcodecdspuuid_a_CPPFLAGS = $(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libwindowscodecs.a
libarm64_libwindowscodecs_a_SOURCES = $(src_libwindowscodecs)
libarm64_libwindowscodecs_a_CPPFLAGS = $(CPPFLAGSARM64) $(sysincludes)
libarm64_libwindowscodecs_a_AR = $(DTDEFARM64) $(top_srcdir)/lib-common/windowscodecs.def && $(AR) $(ARFLAGS)

libarm64_LIBRARIES += libarm64/libwbemuuid.a
libarm64_libwbemuuid_a_SOURCES = $(src_libwbemuuid)
libarm64_libwbemuuid_a_CPPFLAGS = $(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libdxguid.a
libarm64_libdxguid_a_SOURCES = $(src_libdxguid)
libarm64_libdxguid_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libksuser.a
libarm64_libksuser_a_SOURCES = $(src_libksuser)
libarm64_libksuser_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)
libarm64_libksuser_a_AR = $(DTDEFARM64) $(top_srcdir)/lib-common/ksuser.def && $(AR) $(ARFLAGS)

libarm64_LIBRARIES += libarm64/libksguid.a
libarm64_libksguid_a_SOURCES = $(src_libksguid)
libarm64_libksguid_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/liblocationapi.a
libarm64_liblocationapi_a_SOURCES = $(src_liblocationapi)
libarm64_liblocationapi_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libsensorsapi.a
libarm64_libsensorsapi_a_SOURCES = $(src_libsensorsapi)
libarm64_libsensorsapi_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libsapi.a
libarm64_libsapi_a_SOURCES = $(src_libsapi)
libarm64_libsapi_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libportabledeviceguids.a
libarm64_libportabledeviceguids_a_SOURCES = $(src_libportabledeviceguids)
libarm64_libportabledeviceguids_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libscrnsave.a
libarm64_libscrnsave_a_SOURCES = $(src_libscrnsave)
libarm64_libscrnsave_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libscrnsavw.a
libarm64_libscrnsavw_a_SOURCES = $(src_libscrnsavw)
libarm64_libscrnsavw_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)
libarm64_libscrnsavw_a_CFLAGS = -DUNICODE

libarm64_LIBRARIES += libarm64/libstrmiids.a
libarm64_libstrmiids_a_SOURCES = $(src_libstrmiids)
libarm64_libstrmiids_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libuuid.a
libarm64_libuuid_a_SOURCES = $(src_libuuid)
libarm64_libuuid_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libwiaguid.a
libarm64_libwiaguid_a_SOURCES = $(src_libwiaguid)
libarm64_libwiaguid_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libgdiplus.a
libarm64_libgdiplus_a_SOURCES = $(src_libgdiplus)
libarm64_libgdiplus_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)
libarm64_libgdiplus_a_AR = $(DTDEFARM64) $(top_srcdir)/lib-common/gdiplus.def && $(AR) $(ARFLAGS)

libarm64_LIBRARIES += libarm64/libws2_32.a
libarm64_libws2_32_a_SOURCES = $(src_libws2_32) lib-common/libws2_32.def.in
libarm64_libws2_32_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)
libarm64_libws2_32_a_AR = $(DTDEFARM64) libarm64/ws2_32.def && $(AR) $(ARFLAGS)
EXTRA_libarm64_libws2_32_a_DEPENDENCIES=libarm64/ws2_32.def

libarm64_LIBRARIES += libarm64/libadsiid.a
libarm64_libadsiid_a_SOURCES = $(src_adsiid)
libarm64_libadsiid_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libdloadhelper.a
libarm64_libdloadhelper_a_SOURCES = $(src_libdloadhelper)
libarm64_libdloadhelper_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

if !W32API
libarm64_LIBRARIES += libarm64/libdelayimp.a
libarm64_libdelayimp_a_SOURCES =

libarm64_LIBRARIES += libarm64/libm.a
nodist_libarm64_libm_a_SOURCES = $(src_libm)
libarm64_libm_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

#libarm64_LIBRARIES += libarm64/libgmon.a
#libarm64_libgmon_a_SOURCES = profile/mcount.c \
#  profile/profil.h profile/profil.c        \
#  profile/gmon.h   profile/gmon.c \
#  profile/mcountFunc.S
#libarm64_libgmon_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/liblargeint.a
libarm64_liblargeint_a_SOURCES = $(src_liblargeint)
libarm64_liblargeint_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libmingw32.a
libarm64_libmingw32_a_CPPFLAGS=$(CPPFLAGSARM64) -D_SYSCRT=1 $(extra_include) $(AM_CPPFLAGS)
libarm64_libmingw32_a_SOURCES = $(src_libmingw32)

libarm64_LIBRARIES += libarm64/libmingwex.a
libarm64_libmingwex_a_CPPFLAGS=$(CPPFLAGSARM64) $(extra_include) $(AM_CPPFLAGS)
libarm64_libmingwex_a_SOURCES = $(src_libmingwex) $(src_libmingwexarm64) $(src_dfp_math)
libarm64_libmingwex_a_LIBADD=$(src_libmingwexarm64_x64)

libarm64_LIBRARIES += libarm64/libmoldname.a
libarm64_libmoldname_a_CPPFLAGS=$(CPPFLAGSARM64) $(extra_include) $(AM_CPPFLAGS)
libarm64_libmoldname_a_SOURCES = $(src_libm)

libarm64_LIBRARIES += libarm64/libmingwthrd.a
libarm64_libmingwthrd_a_SOURCES = $(src_libmingwthrd)
libarm64_libmingwthrd_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

processed_defs += libarm64/msvcrt.def libarm64/ucrtbase.def libarm64/ucrtbased.def \
				  libarm64/advapi32.def libarm64/clbcatq.def libarm64/kernel32.def libarm64/ole32.def libarm64/oleaut32.def \
				  libarm64/user32.def libarm64/winhvplatform.def libarm64/ws2_32.def \
				  libarm64/api-ms-win-crt-math-l1-1-0.def libarm64/api-ms-win-crt-private-l1-1-0.def libarm64/api-ms-win-crt-runtime-l1-1-0.def \
				  libarm64/api-ms-win-crt-filesystem-l1-1-0.def libarm64/api-ms-win-crt-time-l1-1-0.def \
				  libarm64/vcruntime140.def libarm64/vcruntime140d.def libarm64/vcruntime140_app.def

endif

include libarm64/Makefile.am

if !W32API
libarm64_DATA += libarm64/libucrtbase.a
libarm64/libucrtbase.a: lib-common/ucrtbase.mri libarm64/libucrtbase_def.a libarm64/libucrt_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

libarm64_DATA += libarm64/libucrtbased.a
libarm64/libucrtbased.a: lib-common/ucrtbased.mri libarm64/libucrtbased_def.a libarm64/libucrt_extra.a
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)

libarm64_DATA += libarm64/libucrt.a libarm64/libucrtapp.a
noinst_LIBRARIES += libarm64/libmsvcrt_common.a libarm64/libmsvcrt_extra.a libarm64/libucrt_extra.a libarm64/libucrtapp_extra.a
libarm64_libmsvcrt_common_a_SOURCES = $(src_msvcrt_commonarm64)
libarm64_libmsvcrt_common_a_CPPFLAGS=$(CPPFLAGSARM64) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
libarm64_libmsvcrt_extra_a_SOURCES = $(src_msvcrtarm64)
libarm64_libmsvcrt_extra_a_CPPFLAGS=$(CPPFLAGSARM64) -D__LIBMSVCRT__ -D__LIBMSVCRT_OS__ $(extra_include) $(sysincludes)
libarm64_libmsvcrt_extra_a_LIBADD=$(src_msvcrtarm64_x64)
libarm64_libucrt_extra_a_SOURCES = $(src_ucrtbasearm64)
libarm64_libucrt_extra_a_CPPFLAGS=$(CPPFLAGSARM64) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
libarm64_libucrtapp_extra_a_SOURCES = $(src_ucrtapp) $(src_ucrtapp_arm64)
libarm64_libucrtapp_extra_a_CPPFLAGS=$(CPPFLAGSARM64) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)

libarm64_DATA += libarm64/libvcruntime140.a
libarm64_DATA += libarm64/libvcruntime140d.a
libarm64_DATA += libarm64/libvcruntime140_app.a
endif

libarm64/lib%.a: libarm64/%.def
	$(AM_V_GEN)$(DTDEFARM64) $<

libarm64/lib%.a: lib-common/%.def
	$(AM_V_GEN)$(DTDEFARM64) $<

libarm64/lib%_def.a: libarm64/%.def
	$(AM_V_GEN)$(DTDEFARM64) $<

libarm64/lib%_def.a: lib-common/%.def
	$(AM_V_GEN)$(DTDEFARM64) $<

dx64_DATA =
dx64_DATA += libarm64/libxinput.a
dx64_DATA += libarm64/libd3dcompiler.a

libarm64/libxinput.a: lib-common/xinput1_4.def
	$(AM_V_GEN)$(DTDEFARM64) $<
libarm64/libd3dcompiler.a: lib-common/d3dcompiler_47.def
	$(AM_V_GEN)$(DTDEFARM64) $<

endif
# End ARM 64-bit runtime
# ##########

%/libmincore.a: lib-common/mincore.mri \
		%/libapi-ms-win-core-com-l1-1-0.a \
		%/libapi-ms-win-core-com-l1-1-1.a \
		%/libapi-ms-win-core-com-l1-1-2.a \
		%/libapi-ms-win-core-com-l1-1-3.a \
		%/libapi-ms-win-core-com-midlproxystub-l1-1-0.a \
		%/libapi-ms-win-core-comm-l1-1-0.a \
		%/libapi-ms-win-core-comm-l1-1-1.a \
		%/libapi-ms-win-core-comm-l1-1-2.a \
		%/libapi-ms-win-core-console-l1-1-0.a \
		%/libapi-ms-win-core-console-l1-2-0.a \
		%/libapi-ms-win-core-console-l1-2-1.a \
		%/libapi-ms-win-core-console-l2-1-0.a \
		%/libapi-ms-win-core-console-l2-2-0.a \
		%/libapi-ms-win-core-console-l3-2-0.a \
		%/libapi-ms-win-core-datetime-l1-1-0.a \
		%/libapi-ms-win-core-datetime-l1-1-1.a \
		%/libapi-ms-win-core-datetime-l1-1-2.a \
		%/libapi-ms-win-core-debug-l1-1-0.a \
		%/libapi-ms-win-core-debug-l1-1-1.a \
		%/libapi-ms-win-core-debug-l1-1-2.a \
		%/libapi-ms-win-core-delayload-l1-1-0.a \
		%/libapi-ms-win-core-delayload-l1-1-1.a \
		%/libapi-ms-win-core-errorhandling-l1-1-0.a \
		%/libapi-ms-win-core-errorhandling-l1-1-1.a \
		%/libapi-ms-win-core-errorhandling-l1-1-2.a \
		%/libapi-ms-win-core-errorhandling-l1-1-3.a \
		%/libapi-ms-win-core-fibers-l1-1-0.a \
		%/libapi-ms-win-core-fibers-l1-1-1.a \
		%/libapi-ms-win-core-file-l1-1-0.a \
		%/libapi-ms-win-core-file-l1-2-0.a \
		%/libapi-ms-win-core-file-l1-2-1.a \
		%/libapi-ms-win-core-file-l1-2-2.a \
		%/libapi-ms-win-core-file-l1-2-3.a \
		%/libapi-ms-win-core-file-l2-1-0.a \
		%/libapi-ms-win-core-file-l2-1-1.a \
		%/libapi-ms-win-core-file-l2-1-2.a \
		%/libapi-ms-win-core-file-l2-1-3.a \
		%/libapi-ms-win-core-firmware-l1-1-0.a \
		%/libapi-ms-win-core-handle-l1-1-0.a \
		%/libapi-ms-win-core-heap-l1-1-0.a \
		%/libapi-ms-win-core-heap-l2-1-0.a \
		%/libapi-ms-win-core-interlocked-l1-1-0.a \
		%/libapi-ms-win-core-interlocked-l1-2-0.a \
		%/libapi-ms-win-core-io-l1-1-0.a \
		%/libapi-ms-win-core-io-l1-1-1.a \
		%/libapi-ms-win-core-job-l1-1-0.a \
		%/libapi-ms-win-core-libraryloader-l1-2-0.a \
		%/libapi-ms-win-core-libraryloader-l1-2-1.a \
		%/libapi-ms-win-core-libraryloader-l1-2-2.a \
		%/libapi-ms-win-core-libraryloader-l2-1-0.a \
		%/libapi-ms-win-core-localization-l1-2-1.a \
		%/libapi-ms-win-core-localization-l1-2-0.a \
		%/libapi-ms-win-core-localization-l1-2-2.a \
		%/libapi-ms-win-core-localization-l1-2-3.a \
		%/libapi-ms-win-core-localization-l1-2-4.a \
		%/libapi-ms-win-core-localization-l2-1-0.a \
		%/libapi-ms-win-core-memory-l1-1-0.a \
		%/libapi-ms-win-core-memory-l1-1-1.a \
		%/libapi-ms-win-core-memory-l1-1-2.a \
		%/libapi-ms-win-core-memory-l1-1-3.a \
		%/libapi-ms-win-core-memory-l1-1-4.a \
		%/libapi-ms-win-core-memory-l1-1-5.a \
		%/libapi-ms-win-core-memory-l1-1-6.a \
		%/libapi-ms-win-core-memory-l1-1-7.a \
		%/libapi-ms-win-core-namedpipe-l1-1-0.a \
		%/libapi-ms-win-core-namedpipe-l1-2-1.a \
		%/libapi-ms-win-core-namedpipe-l1-2-2.a \
		%/libapi-ms-win-core-namespace-l1-1-0.a \
		%/libapi-ms-win-core-path-l1-1-0.a \
		%/libapi-ms-win-core-processenvironment-l1-1-0.a \
		%/libapi-ms-win-core-processenvironment-l1-2-0.a \
		%/libapi-ms-win-core-processsnapshot-l1-1-0.a \
		%/libapi-ms-win-core-processthreads-l1-1-0.a \
		%/libapi-ms-win-core-processthreads-l1-1-1.a \
		%/libapi-ms-win-core-processthreads-l1-1-2.a \
		%/libapi-ms-win-core-processthreads-l1-1-3.a \
		%/libapi-ms-win-core-processthreads-l1-1-4.a \
		%/libapi-ms-win-core-processtopology-l1-1-0.a \
		%/libapi-ms-win-core-profile-l1-1-0.a \
		%/libapi-ms-win-core-psapi-l1-1-0.a \
		%/libapi-ms-win-core-quirks-l1-1-0.a \
		%/libapi-ms-win-core-quirks-l1-1-1.a \
		%/libapi-ms-win-core-realtime-l1-1-0.a \
		%/libapi-ms-win-core-realtime-l1-1-1.a \
		%/libapi-ms-win-core-realtime-l1-1-2.a \
		%/libapi-ms-win-core-registry-l1-1-0.a \
		%/libapi-ms-win-core-registry-l1-1-1.a \
		%/libapi-ms-win-core-registry-l1-1-2.a \
		%/libapi-ms-win-core-rtlsupport-l1-1-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-2-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-2-1.a \
		%/libapi-ms-win-core-shutdown-l1-1-0.a \
		%/libapi-ms-win-core-shutdown-l1-1-1.a \
		%/libapi-ms-win-core-sidebyside-ansi-l1-1-0.a \
		%/libapi-ms-win-core-sidebyside-l1-1-0.a \
		%/libapi-ms-win-core-state-helpers-l1-1-0.a \
		%/libapi-ms-win-core-string-l1-1-0.a \
		%/libapi-ms-win-core-string-l2-1-0.a \
		%/libapi-ms-win-core-string-l2-1-1.a \
		%/libapi-ms-win-core-synch-l1-1-0.a \
		%/libapi-ms-win-core-synch-l1-2-0.a \
		%/libapi-ms-win-core-synch-l1-2-1.a \
		%/libapi-ms-win-core-sysinfo-l1-1-0.a \
		%/libapi-ms-win-core-sysinfo-l1-2-0.a \
		%/libapi-ms-win-core-sysinfo-l1-2-1.a \
		%/libapi-ms-win-core-sysinfo-l1-2-2.a \
		%/libapi-ms-win-core-sysinfo-l1-2-3.a \
		%/libapi-ms-win-core-sysinfo-l1-2-4.a \
		%/libapi-ms-win-core-sysinfo-l1-2-5.a \
		%/libapi-ms-win-core-sysinfo-l1-2-6.a \
		%/libapi-ms-win-core-systemtopology-l1-1-0.a \
		%/libapi-ms-win-core-systemtopology-l1-1-1.a \
		%/libapi-ms-win-core-threadpool-l1-2-0.a \
		%/libapi-ms-win-core-timezone-l1-1-0.a \
		%/libapi-ms-win-core-timezone-l1-1-1.a \
		%/libapi-ms-win-core-util-l1-1-0.a \
		%/libapi-ms-win-core-util-l1-1-1.a \
		%/libapi-ms-win-core-version-l1-1-0.a \
		%/libapi-ms-win-core-version-l1-1-1.a \
		%/libapi-ms-win-core-winrt-error-l1-1-0.a \
		%/libapi-ms-win-core-winrt-error-l1-1-1.a \
		%/libapi-ms-win-core-winrt-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-1.a \
		%/libapi-ms-win-core-wow64-l1-1-0.a \
		%/libapi-ms-win-core-wow64-l1-1-1.a \
		%/libapi-ms-win-core-wow64-l1-1-2.a \
		%/libapi-ms-win-core-wow64-l1-1-3.a \
		%/libapi-ms-win-core-xstate-l1-1-0.a \
		%/libapi-ms-win-core-xstate-l1-1-1.a \
		%/libapi-ms-win-core-xstate-l1-1-2.a \
		%/libapi-ms-win-core-xstate-l1-1-3.a \
		%/libapi-ms-win-core-xstate-l2-1-0.a \
		%/libapi-ms-win-core-xstate-l2-1-1.a \
		%/libapi-ms-win-devices-config-l1-1-1.a \
		%/libapi-ms-win-devices-config-l1-1-2.a \
		%/libapi-ms-win-devices-swdevice-l1-1-0.a \
		%/libapi-ms-win-devices-swdevice-l1-1-1.a \
		%/libapi-ms-win-eventing-classicprovider-l1-1-0.a \
		%/libapi-ms-win-eventing-consumer-l1-1-0.a \
		%/libapi-ms-win-eventing-consumer-l1-1-1.a \
		%/libapi-ms-win-eventing-controller-l1-1-0.a \
		%/libapi-ms-win-eventing-provider-l1-1-0.a \
		%/libapi-ms-win-power-base-l1-1-0.a \
		%/libapi-ms-win-power-setting-l1-1-0.a \
		%/libapi-ms-win-power-setting-l1-1-1.a \
		%/libapi-ms-win-security-appcontainer-l1-1-0.a \
		%/libapi-ms-win-security-base-l1-1-0.a \
		%/libapi-ms-win-security-base-l1-2-0.a \
		%/libapi-ms-win-security-base-l1-2-1.a \
		%/libapi-ms-win-security-base-l1-2-2.a \
		%/libapi-ms-win-security-credentials-l1-1-0.a \
		%/libapi-ms-win-security-lsalookup-l2-1-0.a \
		%/libapi-ms-win-security-lsalookup-l2-1-1.a \
		%/libapi-ms-win-security-sddl-l1-1-0.a \
		%/libapi-ms-win-service-core-l1-1-0.a \
		%/libapi-ms-win-service-core-l1-1-1.a \
		%/libapi-ms-win-service-core-l1-1-2.a \
		%/libapi-ms-win-service-core-l1-1-3.a \
		%/libapi-ms-win-service-core-l1-1-4.a \
		%/libapi-ms-win-service-management-l1-1-0.a \
		%/libapi-ms-win-service-management-l2-1-0.a \
		%/libapi-ms-win-service-winsvc-l1-1-0.a \
		%/libauthz.a \
		%/libbcrypt.a \
		%/libcabinet.a \
		%/libcrypt32.a \
		%/libcryptbase.a \
		%/libcryptnet.a \
		%/libdnsapi.a \
		%/libdfscli.a \
		%/libdsparse.a \
		%/libdsrole.a \
		%/libiphlpapi.a \
		%/liblogoncli.a \
		%/libmpr.a \
		%/libmswsock.a \
		%/libncrypt.a \
		%/libnetutils.a \
		%/liboleaut32.a \
		%/librpcrt4.a \
		%/libsamcli.a \
		%/libschedcli.a \
		%/libsrvcli.a \
		%/libsspicli.a \
		%/libuserenv.a \
		%/libwinhttp.a \
		%/libwkscli.a \
		%/libwldap32.a \
		%/libwebsocket.a \
		%/libws2_32.a
	$(AM_V_at)rm -f $@
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(AM_V_at)$(RANLIB) $@

%/libmincore_downlevel.a: lib-common/mincore_downlevel.mri \
		%/libapi-ms-win-downlevel-advapi32-l1-1-0.a \
		%/libapi-ms-win-downlevel-advapi32-l2-1-0.a \
		%/libapi-ms-win-downlevel-normaliz-l1-1-0.a \
		%/libapi-ms-win-downlevel-ole32-l1-1-0.a \
		%/libapi-ms-win-downlevel-shell32-l1-1-0.a \
		%/libapi-ms-win-downlevel-shlwapi-l1-1-0.a \
		%/libapi-ms-win-downlevel-shlwapi-l2-1-0.a \
		%/libapi-ms-win-downlevel-user32-l1-1-0.a \
		%/libapi-ms-win-downlevel-version-l1-1-0.a
	$(AM_V_at)rm -f $@
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(AM_V_at)$(RANLIB) $@

%/libnanosrv.a: lib-common/nanosrv.mri \
		%/libapi-ms-win-net-isolation-l1-1-0.a \
		%/libapi-ms-win-net-isolation-l1-1-1.a \
		%/libclfsw32.a \
		%/libclusapi.a \
		%/libcryptxml.a \
		%/libdbgeng.a \
		%/libdbghelp.a \
		%/libdnsperf.a \
		%/libesent.a \
		%/libfaultrep.a \
		%/libfwpuclnt.a \
		%/libhbaapi.a \
		%/libhttpapi.a \
		%/libiscsidsc.a \
		%/libktmw32.a \
		%/libmprapi.a \
		%/libntdsapi.a \
		%/libpdh.a \
		%/libsnmpapi.a \
		%/libtbs.a \
		%/libvirtdisk.a \
		%/libvssapi.a \
		%/libwebservices.a \
		%/libwer.a \
		%/libwevtapi.a \
		%/libwintrust.a \
		%/libwsmsvc.a
	$(AM_V_at)rm -f $@
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(AM_V_at)$(RANLIB) $@

%/libonecore.a: lib-common/onecore.mri \
		%/libadvapi32_onecore.a \
		%/libapi-ms-win-core-backgroundtask-l1-1-0.a \
		%/libapi-ms-win-core-calendar-l1-1-0.a \
		%/libapi-ms-win-core-comm-l1-1-1.a \
		%/libapi-ms-win-core-comm-l1-1-2.a \
		%/libapi-ms-win-core-debug-minidump-l1-1-0.a \
		%/libapi-ms-win-core-enclave-l1-1-1.a \
		%/libapi-ms-win-core-errorhandling-l1-1-3.a \
		%/libapi-ms-win-core-featurestaging-l1-1-0.a \
		%/libapi-ms-win-core-featurestaging-l1-1-1.a \
		%/libapi-ms-win-core-handle-l1-1-0.a \
		%/libapi-ms-win-core-libraryloader-l2-1-0.a \
		%/libapi-ms-win-core-memory-l1-1-3.a \
		%/libapi-ms-win-core-memory-l1-1-4.a \
		%/libapi-ms-win-core-memory-l1-1-5.a \
		%/libapi-ms-win-core-memory-l1-1-6.a \
		%/libapi-ms-win-core-memory-l1-1-7.a \
		%/libapi-ms-win-core-path-l1-1-0.a \
		%/libapi-ms-win-core-quirks-l1-1-0.a \
		%/libapi-ms-win-core-quirks-l1-1-1.a \
		%/libapi-ms-win-core-realtime-l1-1-1.a \
		%/libapi-ms-win-core-realtime-l1-1-2.a \
		%/libapi-ms-win-core-rtlsupport-l1-1-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-2-0.a \
		%/libapi-ms-win-core-state-helpers-l1-1-0.a \
		%/libapi-ms-win-core-synch-l1-2-0.a \
		%/libapi-ms-win-core-sysinfo-l1-2-0.a \
		%/libapi-ms-win-core-sysinfo-l1-2-3.a \
		%/libapi-ms-win-core-sysinfo-l1-2-4.a \
		%/libapi-ms-win-core-util-l1-1-1.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-0.a \
		%/libapi-ms-win-core-winrt-error-l1-1-0.a \
		%/libapi-ms-win-core-winrt-error-l1-1-1.a \
		%/libapi-ms-win-core-winrt-l1-1-0.a \
		%/libapi-ms-win-core-winrt-registration-l1-1-0.a \
		%/libapi-ms-win-core-winrt-robuffer-l1-1-0.a \
		%/libapi-ms-win-core-winrt-roparameterizediid-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-1.a \
		%/libapi-ms-win-core-wow64-l1-1-1.a \
		%/libapi-ms-win-devices-config-l1-1-1.a \
		%/libapi-ms-win-devices-query-l1-1-0.a \
		%/libapi-ms-win-devices-query-l1-1-1.a \
		%/libapi-ms-win-devices-swdevice-l1-1-0.a \
		%/libapi-ms-win-devices-swdevice-l1-1-1.a \
		%/libapi-ms-win-gaming-deviceinformation-l1-1-0.a \
		%/libapi-ms-win-power-base-l1-1-0.a \
		%/libapi-ms-win-power-limitsmanagement-l1-1-0.a \
		%/libapi-ms-win-power-setting-l1-1-0.a \
		%/libapi-ms-win-power-setting-l1-1-1.a \
		%/libapi-ms-win-ro-typeresolution-l1-1-0.a \
		%/libapi-ms-win-ro-typeresolution-l1-1-1.a \
		%/libapi-ms-win-security-base-l1-2-2.a \
		%/libapi-ms-win-security-isolatedcontainer-l1-1-0.a \
		%/libapi-ms-win-security-isolatedcontainer-l1-1-1.a \
		%/libapi-ms-win-service-core-l1-1-3.a \
		%/libapi-ms-win-service-core-l1-1-4.a \
		%/libapi-ms-win-shcore-scaling-l1-1-0.a \
		%/libapi-ms-win-shcore-scaling-l1-1-1.a \
		%/libapi-ms-win-shcore-scaling-l1-1-2.a \
		%/libapi-ms-win-shcore-stream-winrt-l1-1-0.a \
		%/libauthz.a \
		%/libbcrypt.a \
		%/libcabinet.a \
		%/libcomctl32_onecore.a \
		%/libcomdlg32.a \
		%/libcrypt32.a \
		%/libcryptnet.a \
		%/libdfscli.a \
		%/libdhcpcsvc.a \
		%/libdhcpcsvc6.a \
		%/libdiagnosticdataquery.a \
		%/libdnsapi.a \
		%/libdsrole.a \
		%/libfltlib.a \
		%/libfontsub.a \
		%/libgdi32_onecore.a \
		%/libiphlpapi.a \
		%/libkernel32_onecore.a \
		%/liblogoncli.a \
		%/libmpr.a \
		%/libmswsock.a \
		%/libncrypt_onecore.a \
		%/libnetutils.a \
		%/libnormaliz_onecore.a \
		%/libntdll_onecore.a \
		%/libole32_onecore.a \
		%/liboleaut32.a \
		%/libpowrprof_onecore.a \
		%/libprofapi.a \
		%/libpsapi.a \
		%/librpcrt4.a \
		%/libsamcli.a \
		%/libschedcli.a \
		%/libsecur32_onecore.a \
		%/libsetupapi_onecore.a \
		%/libshell32_onecore.a \
		%/libshlwapi.a \
		%/libsrvcli.a \
		%/libsspicli.a \
		%/libtdh_onecore.a \
		%/libuser32_onecore.a \
		%/libuserenv.a \
		%/libversion.a \
		%/libwebsocket.a \
		%/libwinhttp_onecore.a \
		%/libwinmm_onecore.a \
		%/libwkscli.a \
		%/libwldap32.a \
		%/libwpprecorderum.a \
		%/libws2_32.a \
		%/libwtsapi32_onecore.a \
		%/libxmllite.a
	$(AM_V_at)rm -f $@
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(AM_V_at)$(RANLIB) $@

%/libonecore_apiset.a: lib-common/onecore_apiset.mri \
		%/libapi-ms-win-core-apiquery-l2-1-0.a \
		%/libapi-ms-win-core-atoms-l1-1-0.a \
		%/libapi-ms-win-core-backgroundtask-l1-1-0.a \
		%/libapi-ms-win-core-calendar-l1-1-0.a \
		%/libapi-ms-win-core-com-l1-1-0.a \
		%/libapi-ms-win-core-com-l1-1-1.a \
		%/libapi-ms-win-core-com-l1-1-2.a \
		%/libapi-ms-win-core-com-l1-1-3.a \
		%/libapi-ms-win-core-com-midlproxystub-l1-1-0.a \
		%/libapi-ms-win-core-comm-l1-1-0.a \
		%/libapi-ms-win-core-comm-l1-1-1.a \
		%/libapi-ms-win-core-comm-l1-1-2.a \
		%/libapi-ms-win-core-console-l1-1-0.a \
		%/libapi-ms-win-core-console-l1-2-0.a \
		%/libapi-ms-win-core-console-l1-2-1.a \
		%/libapi-ms-win-core-console-l2-1-0.a \
		%/libapi-ms-win-core-console-l2-2-0.a \
		%/libapi-ms-win-core-console-l3-2-0.a \
		%/libapi-ms-win-core-datetime-l1-1-0.a \
		%/libapi-ms-win-core-datetime-l1-1-1.a \
		%/libapi-ms-win-core-datetime-l1-1-2.a \
		%/libapi-ms-win-core-debug-l1-1-0.a \
		%/libapi-ms-win-core-debug-l1-1-1.a \
		%/libapi-ms-win-core-debug-l1-1-2.a \
		%/libapi-ms-win-core-debug-minidump-l1-1-0.a \
		%/libapi-ms-win-core-delayload-l1-1-0.a \
		%/libapi-ms-win-core-delayload-l1-1-1.a \
		%/libapi-ms-win-core-enclave-l1-1-0.a \
		%/libapi-ms-win-core-enclave-l1-1-1.a \
		%/libapi-ms-win-core-errorhandling-l1-1-0.a \
		%/libapi-ms-win-core-errorhandling-l1-1-1.a \
		%/libapi-ms-win-core-errorhandling-l1-1-2.a \
		%/libapi-ms-win-core-errorhandling-l1-1-3.a \
		%/libapi-ms-win-core-featurestaging-l1-1-0.a \
		%/libapi-ms-win-core-featurestaging-l1-1-1.a \
		%/libapi-ms-win-core-fibers-l1-1-0.a \
		%/libapi-ms-win-core-fibers-l1-1-1.a \
		%/libapi-ms-win-core-fibers-l2-1-0.a \
		%/libapi-ms-win-core-fibers-l2-1-1.a \
		%/libapi-ms-win-core-file-ansi-l1-1-0.a \
		%/libapi-ms-win-core-file-ansi-l2-1-0.a \
		%/libapi-ms-win-core-file-l1-1-0.a \
		%/libapi-ms-win-core-file-l1-2-0.a \
		%/libapi-ms-win-core-file-l1-2-1.a \
		%/libapi-ms-win-core-file-l1-2-2.a \
		%/libapi-ms-win-core-file-l1-2-3.a \
		%/libapi-ms-win-core-file-l2-1-0.a \
		%/libapi-ms-win-core-file-l2-1-1.a \
		%/libapi-ms-win-core-file-l2-1-2.a \
		%/libapi-ms-win-core-file-l2-1-3.a \
		%/libapi-ms-win-core-firmware-l1-1-0.a \
		%/libapi-ms-win-core-handle-l1-1-0.a \
		%/libapi-ms-win-core-heap-l1-1-0.a \
		%/libapi-ms-win-core-heap-l2-1-0.a \
		%/libapi-ms-win-core-heap-obsolete-l1-1-0.a \
		%/libapi-ms-win-core-interlocked-l1-1-0.a \
		%/libapi-ms-win-core-interlocked-l1-2-0.a \
		%/libapi-ms-win-core-io-l1-1-0.a \
		%/libapi-ms-win-core-io-l1-1-1.a \
		%/libapi-ms-win-core-job-l1-1-0.a \
		%/libapi-ms-win-core-job-l2-1-0.a \
		%/libapi-ms-win-core-job-l2-1-1.a \
		%/libapi-ms-win-core-kernel32-legacy-ansi-l1-1-0.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-0.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-1.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-2.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-3.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-4.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-5.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-6.a \
		%/libapi-ms-win-core-largeinteger-l1-1-0.a \
		%/libapi-ms-win-core-libraryloader-l1-2-0.a \
		%/libapi-ms-win-core-libraryloader-l1-2-1.a \
		%/libapi-ms-win-core-libraryloader-l1-2-2.a \
		%/libapi-ms-win-core-libraryloader-l2-1-0.a \
		%/libapi-ms-win-core-localization-ansi-l1-1-0.a \
		%/libapi-ms-win-core-localization-l1-2-0.a \
		%/libapi-ms-win-core-localization-l1-2-1.a \
		%/libapi-ms-win-core-localization-l1-2-2.a \
		%/libapi-ms-win-core-localization-l1-2-3.a \
		%/libapi-ms-win-core-localization-l1-2-4.a \
		%/libapi-ms-win-core-localization-l2-1-0.a \
		%/libapi-ms-win-core-localization-obsolete-l1-2-0.a \
		%/libapi-ms-win-core-memory-l1-1-0.a \
		%/libapi-ms-win-core-memory-l1-1-1.a \
		%/libapi-ms-win-core-memory-l1-1-2.a \
		%/libapi-ms-win-core-memory-l1-1-3.a \
		%/libapi-ms-win-core-memory-l1-1-4.a \
		%/libapi-ms-win-core-memory-l1-1-5.a \
		%/libapi-ms-win-core-memory-l1-1-6.a \
		%/libapi-ms-win-core-memory-l1-1-7.a \
		%/libapi-ms-win-core-namedpipe-ansi-l1-1-0.a \
		%/libapi-ms-win-core-namedpipe-ansi-l1-1-1.a \
		%/libapi-ms-win-core-namedpipe-l1-1-0.a \
		%/libapi-ms-win-core-namedpipe-l1-2-1.a \
		%/libapi-ms-win-core-namedpipe-l1-2-2.a \
		%/libapi-ms-win-core-namespace-ansi-l1-1-0.a \
		%/libapi-ms-win-core-namespace-l1-1-0.a \
		%/libapi-ms-win-core-normalization-l1-1-0.a \
		%/libapi-ms-win-core-path-l1-1-0.a \
		%/libapi-ms-win-core-perfcounters-l1-1-0.a \
		%/libapi-ms-win-core-privateprofile-l1-1-0.a \
		%/libapi-ms-win-core-privateprofile-l1-1-1.a \
		%/libapi-ms-win-core-processenvironment-ansi-l1-1-0.a \
		%/libapi-ms-win-core-processenvironment-l1-1-0.a \
		%/libapi-ms-win-core-processenvironment-l1-2-0.a \
		%/libapi-ms-win-core-processsnapshot-l1-1-0.a \
		%/libapi-ms-win-core-processthreads-l1-1-0.a \
		%/libapi-ms-win-core-processthreads-l1-1-1.a \
		%/libapi-ms-win-core-processthreads-l1-1-2.a \
		%/libapi-ms-win-core-processthreads-l1-1-3.a \
		%/libapi-ms-win-core-processthreads-l1-1-4.a \
		%/libapi-ms-win-core-processtopology-l1-1-0.a \
		%/libapi-ms-win-core-processtopology-obsolete-l1-1-0.a \
		%/libapi-ms-win-core-processtopology-obsolete-l1-1-1.a \
		%/libapi-ms-win-core-profile-l1-1-0.a \
		%/libapi-ms-win-core-psapi-ansi-l1-1-0.a \
		%/libapi-ms-win-core-psapi-l1-1-0.a \
		%/libapi-ms-win-core-quirks-l1-1-0.a \
		%/libapi-ms-win-core-quirks-l1-1-1.a \
		%/libapi-ms-win-core-realtime-l1-1-0.a \
		%/libapi-ms-win-core-realtime-l1-1-1.a \
		%/libapi-ms-win-core-realtime-l1-1-2.a \
		%/libapi-ms-win-core-registry-l1-1-0.a \
		%/libapi-ms-win-core-registry-l1-1-1.a \
		%/libapi-ms-win-core-registry-l1-1-2.a \
		%/libapi-ms-win-core-registry-l2-1-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-1-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-2-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-2-1.a \
		%/libapi-ms-win-core-shutdown-ansi-l1-1-0.a \
		%/libapi-ms-win-core-shutdown-l1-1-0.a \
		%/libapi-ms-win-core-shutdown-l1-1-1.a \
		%/libapi-ms-win-core-string-l1-1-0.a \
		%/libapi-ms-win-core-string-l2-1-0.a \
		%/libapi-ms-win-core-string-l2-1-1.a \
		%/libapi-ms-win-core-string-obsolete-l1-1-0.a \
		%/libapi-ms-win-core-string-obsolete-l1-1-1.a \
		%/libapi-ms-win-core-stringansi-l1-1-0.a \
		%/libapi-ms-win-core-synch-ansi-l1-1-0.a \
		%/libapi-ms-win-core-synch-l1-1-0.a \
		%/libapi-ms-win-core-synch-l1-2-0.a \
		%/libapi-ms-win-core-synch-l1-2-1.a \
		%/libapi-ms-win-core-sysinfo-l1-1-0.a \
		%/libapi-ms-win-core-sysinfo-l1-2-0.a \
		%/libapi-ms-win-core-sysinfo-l1-2-1.a \
		%/libapi-ms-win-core-sysinfo-l1-2-2.a \
		%/libapi-ms-win-core-sysinfo-l1-2-3.a \
		%/libapi-ms-win-core-sysinfo-l1-2-4.a \
		%/libapi-ms-win-core-sysinfo-l1-2-5.a \
		%/libapi-ms-win-core-sysinfo-l1-2-6.a \
		%/libapi-ms-win-core-systemtopology-l1-1-0.a \
		%/libapi-ms-win-core-systemtopology-l1-1-1.a \
		%/libapi-ms-win-core-threadpool-l1-2-0.a \
		%/libapi-ms-win-core-threadpool-legacy-l1-1-0.a \
		%/libapi-ms-win-core-timezone-l1-1-0.a \
		%/libapi-ms-win-core-timezone-l1-1-1.a \
		%/libapi-ms-win-core-toolhelp-l1-1-0.a \
		%/libapi-ms-win-core-toolhelp-l1-1-1.a \
		%/libapi-ms-win-core-url-l1-1-0.a \
		%/libapi-ms-win-core-util-l1-1-0.a \
		%/libapi-ms-win-core-util-l1-1-1.a \
		%/libapi-ms-win-core-version-l1-1-0.a \
		%/libapi-ms-win-core-version-l1-1-1.a \
		%/libapi-ms-win-core-versionansi-l1-1-0.a \
		%/libapi-ms-win-core-versionansi-l1-1-1.a \
		%/libapi-ms-win-core-windowsceip-l1-1-0.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-0.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-1.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-2.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-3.a \
		%/libapi-ms-win-core-winrt-error-l1-1-0.a \
		%/libapi-ms-win-core-winrt-error-l1-1-1.a \
		%/libapi-ms-win-core-winrt-l1-1-0.a \
		%/libapi-ms-win-core-winrt-registration-l1-1-0.a \
		%/libapi-ms-win-core-winrt-robuffer-l1-1-0.a \
		%/libapi-ms-win-core-winrt-roparameterizediid-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-1.a \
		%/libapi-ms-win-core-wow64-l1-1-0.a \
		%/libapi-ms-win-core-wow64-l1-1-1.a \
		%/libapi-ms-win-core-wow64-l1-1-2.a \
		%/libapi-ms-win-core-wow64-l1-1-3.a \
		%/libapi-ms-win-core-xstate-l2-1-0.a \
		%/libapi-ms-win-core-xstate-l2-1-1.a \
		%/libapi-ms-win-devices-config-l1-1-1.a \
		%/libapi-ms-win-devices-config-l1-1-2.a \
		%/libapi-ms-win-devices-query-l1-1-0.a \
		%/libapi-ms-win-devices-query-l1-1-1.a \
		%/libapi-ms-win-devices-swdevice-l1-1-0.a \
		%/libapi-ms-win-devices-swdevice-l1-1-1.a \
		%/libapi-ms-win-eventing-classicprovider-l1-1-0.a \
		%/libapi-ms-win-eventing-consumer-l1-1-0.a \
		%/libapi-ms-win-eventing-consumer-l1-1-1.a \
		%/libapi-ms-win-eventing-controller-l1-1-0.a \
		%/libapi-ms-win-eventing-legacy-l1-1-0.a \
		%/libapi-ms-win-eventing-obsolete-l1-1-0.a \
		%/libapi-ms-win-eventing-provider-l1-1-0.a \
		%/libapi-ms-win-eventing-tdh-l1-1-0.a \
		%/libapi-ms-win-eventing-tdh-l1-1-1.a \
		%/libapi-ms-win-gaming-deviceinformation-l1-1-0.a \
		%/libapi-ms-win-mm-time-l1-1-0.a \
		%/libapi-ms-win-oobe-notification-l1-1-0.a \
		%/libapi-ms-win-perf-legacy-l1-1-0.a \
		%/libapi-ms-win-power-base-l1-1-0.a \
		%/libapi-ms-win-power-limitsmanagement-l1-1-0.a \
		%/libapi-ms-win-power-setting-l1-1-0.a \
		%/libapi-ms-win-power-setting-l1-1-1.a \
		%/libapi-ms-win-ro-typeresolution-l1-1-0.a \
		%/libapi-ms-win-ro-typeresolution-l1-1-1.a \
		%/libapi-ms-win-security-appcontainer-l1-1-0.a \
		%/libapi-ms-win-security-base-ansi-l1-1-0.a \
		%/libapi-ms-win-security-base-l1-1-0.a \
		%/libapi-ms-win-security-base-l1-2-0.a \
		%/libapi-ms-win-security-base-l1-2-1.a \
		%/libapi-ms-win-security-base-l1-2-2.a \
		%/libapi-ms-win-security-cpwl-l1-1-0.a \
		%/libapi-ms-win-security-credentials-l1-1-0.a \
		%/libapi-ms-win-security-cryptoapi-l1-1-0.a \
		%/libapi-ms-win-security-isolatedcontainer-l1-1-0.a \
		%/libapi-ms-win-security-isolatedcontainer-l1-1-1.a \
		%/libapi-ms-win-security-lsalookup-ansi-l2-1-0.a \
		%/libapi-ms-win-security-lsalookup-l2-1-0.a \
		%/libapi-ms-win-security-lsalookup-l2-1-1.a \
		%/libapi-ms-win-security-lsapolicy-l1-1-0.a \
		%/libapi-ms-win-security-provider-ansi-l1-1-0.a \
		%/libapi-ms-win-security-provider-l1-1-0.a \
		%/libapi-ms-win-security-sddl-ansi-l1-1-0.a \
		%/libapi-ms-win-security-sddl-l1-1-0.a \
		%/libapi-ms-win-security-systemfunctions-l1-1-0.a \
		%/libapi-ms-win-service-core-ansi-l1-1-0.a \
		%/libapi-ms-win-service-core-ansi-l1-1-1.a \
		%/libapi-ms-win-service-core-l1-1-0.a \
		%/libapi-ms-win-service-core-l1-1-1.a \
		%/libapi-ms-win-service-core-l1-1-2.a \
		%/libapi-ms-win-service-core-l1-1-3.a \
		%/libapi-ms-win-service-core-l1-1-4.a \
		%/libapi-ms-win-service-management-l1-1-0.a \
		%/libapi-ms-win-service-management-l2-1-0.a \
		%/libapi-ms-win-service-winsvc-l1-1-0.a \
		%/libapi-ms-win-shcore-obsolete-l1-1-0.a \
		%/libapi-ms-win-shcore-path-l1-1-0.a \
		%/libapi-ms-win-shcore-registry-l1-1-0.a \
		%/libapi-ms-win-shcore-registry-l1-1-1.a \
		%/libapi-ms-win-shcore-scaling-l1-1-0.a \
		%/libapi-ms-win-shcore-scaling-l1-1-1.a \
		%/libapi-ms-win-shcore-scaling-l1-1-2.a \
		%/libapi-ms-win-shcore-stream-l1-1-0.a \
		%/libapi-ms-win-shcore-stream-winrt-l1-1-0.a \
		%/libapi-ms-win-shcore-sysinfo-l1-1-0.a \
		%/libapi-ms-win-shcore-unicodeansi-l1-1-0.a \
		%/libapi-ms-win-shell-shdirectory-l1-1-0.a \
		%/libauthz.a \
		%/libbcrypt.a \
		%/libcabinet.a \
		%/libcrypt32.a \
		%/libcryptbase.a \
		%/libcryptnet.a \
		%/libdfscli.a \
		%/libdhcpcsvc.a \
		%/libdnsapi.a \
		%/libdsrole.a \
		%/libfltlib.a \
		%/libiphlpapi.a \
		%/liblogoncli.a \
		%/libmpr.a \
		%/libmswsock.a \
		%/libncrypt.a \
		%/libnetutils.a \
		%/liboleaut32.a \
		%/libpowrprof.a \
		%/libprofapi.a \
		%/librpcrt4.a \
		%/libsamcli.a \
		%/libschedcli.a \
		%/libsrvcli.a \
		%/libsspicli.a \
		%/libuserenv.a \
		%/libwebsocket.a \
		%/libwinhttp.a \
		%/libwkscli.a \
		%/libwldap32.a \
		%/libwpprecorderum.a \
		%/libws2_32.a \
		%/libxmllite.a
	$(AM_V_at)rm -f $@
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(AM_V_at)$(RANLIB) $@

%/libonecoreuap_apiset.a: lib-common/onecoreuap_apiset.mri \
		%/libapi-ms-win-appmodel-runtime-l1-1-0.a \
		%/libapi-ms-win-appmodel-runtime-l1-1-1.a \
		%/libapi-ms-win-appmodel-runtime-l1-1-2.a \
		%/libapi-ms-win-appmodel-runtime-l1-1-3.a \
		%/libapi-ms-win-core-apiquery-l2-1-0.a \
		%/libapi-ms-win-core-atoms-l1-1-0.a \
		%/libapi-ms-win-core-backgroundtask-l1-1-0.a \
		%/libapi-ms-win-core-calendar-l1-1-0.a \
		%/libapi-ms-win-core-com-l1-1-0.a \
		%/libapi-ms-win-core-com-l1-1-1.a \
		%/libapi-ms-win-core-com-l1-1-2.a \
		%/libapi-ms-win-core-com-l1-1-3.a \
		%/libapi-ms-win-core-com-l2-1-1.a \
		%/libapi-ms-win-core-com-midlproxystub-l1-1-0.a \
		%/libapi-ms-win-core-comm-l1-1-0.a \
		%/libapi-ms-win-core-comm-l1-1-1.a \
		%/libapi-ms-win-core-comm-l1-1-2.a \
		%/libapi-ms-win-core-console-l1-1-0.a \
		%/libapi-ms-win-core-console-l1-2-0.a \
		%/libapi-ms-win-core-console-l1-2-1.a \
		%/libapi-ms-win-core-console-l2-1-0.a \
		%/libapi-ms-win-core-console-l2-2-0.a \
		%/libapi-ms-win-core-console-l3-2-0.a \
		%/libapi-ms-win-core-datetime-l1-1-0.a \
		%/libapi-ms-win-core-datetime-l1-1-1.a \
		%/libapi-ms-win-core-datetime-l1-1-2.a \
		%/libapi-ms-win-core-debug-l1-1-0.a \
		%/libapi-ms-win-core-debug-l1-1-1.a \
		%/libapi-ms-win-core-debug-l1-1-2.a \
		%/libapi-ms-win-core-debug-minidump-l1-1-0.a \
		%/libapi-ms-win-core-delayload-l1-1-0.a \
		%/libapi-ms-win-core-delayload-l1-1-1.a \
		%/libapi-ms-win-core-enclave-l1-1-0.a \
		%/libapi-ms-win-core-enclave-l1-1-1.a \
		%/libapi-ms-win-core-errorhandling-l1-1-0.a \
		%/libapi-ms-win-core-errorhandling-l1-1-1.a \
		%/libapi-ms-win-core-errorhandling-l1-1-2.a \
		%/libapi-ms-win-core-errorhandling-l1-1-3.a \
		%/libapi-ms-win-core-featurestaging-l1-1-0.a \
		%/libapi-ms-win-core-featurestaging-l1-1-1.a \
		%/libapi-ms-win-core-fibers-l1-1-0.a \
		%/libapi-ms-win-core-fibers-l1-1-1.a \
		%/libapi-ms-win-core-fibers-l2-1-0.a \
		%/libapi-ms-win-core-fibers-l2-1-1.a \
		%/libapi-ms-win-core-file-ansi-l1-1-0.a \
		%/libapi-ms-win-core-file-ansi-l2-1-0.a \
		%/libapi-ms-win-core-file-fromapp-l1-1-0.a \
		%/libapi-ms-win-core-file-l1-1-0.a \
		%/libapi-ms-win-core-file-l1-2-0.a \
		%/libapi-ms-win-core-file-l1-2-1.a \
		%/libapi-ms-win-core-file-l1-2-2.a \
		%/libapi-ms-win-core-file-l1-2-3.a \
		%/libapi-ms-win-core-file-l2-1-0.a \
		%/libapi-ms-win-core-file-l2-1-1.a \
		%/libapi-ms-win-core-file-l2-1-2.a \
		%/libapi-ms-win-core-file-l2-1-3.a \
		%/libapi-ms-win-core-firmware-l1-1-0.a \
		%/libapi-ms-win-core-handle-l1-1-0.a \
		%/libapi-ms-win-core-heap-l1-1-0.a \
		%/libapi-ms-win-core-heap-l2-1-0.a \
		%/libapi-ms-win-core-heap-obsolete-l1-1-0.a \
		%/libapi-ms-win-core-interlocked-l1-1-0.a \
		%/libapi-ms-win-core-interlocked-l1-2-0.a \
		%/libapi-ms-win-core-io-l1-1-0.a \
		%/libapi-ms-win-core-io-l1-1-1.a \
		%/libapi-ms-win-core-job-l1-1-0.a \
		%/libapi-ms-win-core-job-l2-1-0.a \
		%/libapi-ms-win-core-job-l2-1-1.a \
		%/libapi-ms-win-core-kernel32-legacy-ansi-l1-1-0.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-0.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-1.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-2.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-3.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-4.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-5.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-6.a \
		%/libapi-ms-win-core-largeinteger-l1-1-0.a \
		%/libapi-ms-win-core-libraryloader-l1-2-0.a \
		%/libapi-ms-win-core-libraryloader-l1-2-1.a \
		%/libapi-ms-win-core-libraryloader-l1-2-2.a \
		%/libapi-ms-win-core-libraryloader-l2-1-0.a \
		%/libapi-ms-win-core-localization-ansi-l1-1-0.a \
		%/libapi-ms-win-core-localization-l1-2-0.a \
		%/libapi-ms-win-core-localization-l1-2-1.a \
		%/libapi-ms-win-core-localization-l1-2-2.a \
		%/libapi-ms-win-core-localization-l1-2-3.a \
		%/libapi-ms-win-core-localization-l1-2-4.a \
		%/libapi-ms-win-core-localization-l2-1-0.a \
		%/libapi-ms-win-core-localization-obsolete-l1-2-0.a \
		%/libapi-ms-win-core-memory-l1-1-0.a \
		%/libapi-ms-win-core-memory-l1-1-1.a \
		%/libapi-ms-win-core-memory-l1-1-2.a \
		%/libapi-ms-win-core-memory-l1-1-3.a \
		%/libapi-ms-win-core-memory-l1-1-4.a \
		%/libapi-ms-win-core-memory-l1-1-5.a \
		%/libapi-ms-win-core-memory-l1-1-6.a \
		%/libapi-ms-win-core-memory-l1-1-7.a \
		%/libapi-ms-win-core-namedpipe-ansi-l1-1-0.a \
		%/libapi-ms-win-core-namedpipe-ansi-l1-1-1.a \
		%/libapi-ms-win-core-namedpipe-l1-1-0.a \
		%/libapi-ms-win-core-namedpipe-l1-2-1.a \
		%/libapi-ms-win-core-namedpipe-l1-2-2.a \
		%/libapi-ms-win-core-namespace-ansi-l1-1-0.a \
		%/libapi-ms-win-core-namespace-l1-1-0.a \
		%/libapi-ms-win-core-normalization-l1-1-0.a \
		%/libapi-ms-win-core-path-l1-1-0.a \
		%/libapi-ms-win-core-perfcounters-l1-1-0.a \
		%/libapi-ms-win-core-privateprofile-l1-1-0.a \
		%/libapi-ms-win-core-privateprofile-l1-1-1.a \
		%/libapi-ms-win-core-processenvironment-ansi-l1-1-0.a \
		%/libapi-ms-win-core-processenvironment-l1-1-0.a \
		%/libapi-ms-win-core-processenvironment-l1-2-0.a \
		%/libapi-ms-win-core-processsnapshot-l1-1-0.a \
		%/libapi-ms-win-core-processthreads-l1-1-0.a \
		%/libapi-ms-win-core-processthreads-l1-1-1.a \
		%/libapi-ms-win-core-processthreads-l1-1-2.a \
		%/libapi-ms-win-core-processthreads-l1-1-3.a \
		%/libapi-ms-win-core-processthreads-l1-1-4.a \
		%/libapi-ms-win-core-processtopology-l1-1-0.a \
		%/libapi-ms-win-core-processtopology-obsolete-l1-1-0.a \
		%/libapi-ms-win-core-processtopology-obsolete-l1-1-1.a \
		%/libapi-ms-win-core-profile-l1-1-0.a \
		%/libapi-ms-win-core-psapi-ansi-l1-1-0.a \
		%/libapi-ms-win-core-psapi-l1-1-0.a \
		%/libapi-ms-win-core-psm-appnotify-l1-1-0.a \
		%/libapi-ms-win-core-quirks-l1-1-0.a \
		%/libapi-ms-win-core-quirks-l1-1-1.a \
		%/libapi-ms-win-core-realtime-l1-1-0.a \
		%/libapi-ms-win-core-realtime-l1-1-1.a \
		%/libapi-ms-win-core-realtime-l1-1-2.a \
		%/libapi-ms-win-core-registry-l1-1-0.a \
		%/libapi-ms-win-core-registry-l1-1-1.a \
		%/libapi-ms-win-core-registry-l1-1-2.a \
		%/libapi-ms-win-core-registry-l2-1-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-1-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-2-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-2-1.a \
		%/libapi-ms-win-core-shutdown-ansi-l1-1-0.a \
		%/libapi-ms-win-core-shutdown-l1-1-0.a \
		%/libapi-ms-win-core-shutdown-l1-1-1.a \
		%/libapi-ms-win-core-slapi-l1-1-0.a \
		%/libapi-ms-win-core-string-l1-1-0.a \
		%/libapi-ms-win-core-string-l2-1-0.a \
		%/libapi-ms-win-core-string-l2-1-1.a \
		%/libapi-ms-win-core-string-obsolete-l1-1-0.a \
		%/libapi-ms-win-core-string-obsolete-l1-1-1.a \
		%/libapi-ms-win-core-stringansi-l1-1-0.a \
		%/libapi-ms-win-core-synch-ansi-l1-1-0.a \
		%/libapi-ms-win-core-synch-l1-1-0.a \
		%/libapi-ms-win-core-synch-l1-2-0.a \
		%/libapi-ms-win-core-synch-l1-2-1.a \
		%/libapi-ms-win-core-sysinfo-l1-1-0.a \
		%/libapi-ms-win-core-sysinfo-l1-2-0.a \
		%/libapi-ms-win-core-sysinfo-l1-2-1.a \
		%/libapi-ms-win-core-sysinfo-l1-2-2.a \
		%/libapi-ms-win-core-sysinfo-l1-2-3.a \
		%/libapi-ms-win-core-sysinfo-l1-2-4.a \
		%/libapi-ms-win-core-sysinfo-l1-2-5.a \
		%/libapi-ms-win-core-sysinfo-l1-2-6.a \
		%/libapi-ms-win-core-systemtopology-l1-1-0.a \
		%/libapi-ms-win-core-systemtopology-l1-1-1.a \
		%/libapi-ms-win-core-threadpool-l1-2-0.a \
		%/libapi-ms-win-core-threadpool-legacy-l1-1-0.a \
		%/libapi-ms-win-core-timezone-l1-1-0.a \
		%/libapi-ms-win-core-timezone-l1-1-1.a \
		%/libapi-ms-win-core-toolhelp-l1-1-0.a \
		%/libapi-ms-win-core-toolhelp-l1-1-1.a \
		%/libapi-ms-win-core-url-l1-1-0.a \
		%/libapi-ms-win-core-util-l1-1-0.a \
		%/libapi-ms-win-core-util-l1-1-1.a \
		%/libapi-ms-win-core-version-l1-1-0.a \
		%/libapi-ms-win-core-version-l1-1-1.a \
		%/libapi-ms-win-core-versionansi-l1-1-0.a \
		%/libapi-ms-win-core-versionansi-l1-1-1.a \
		%/libapi-ms-win-core-windowsceip-l1-1-0.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-0.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-1.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-2.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-3.a \
		%/libapi-ms-win-core-winrt-error-l1-1-0.a \
		%/libapi-ms-win-core-winrt-error-l1-1-1.a \
		%/libapi-ms-win-core-winrt-l1-1-0.a \
		%/libapi-ms-win-core-winrt-registration-l1-1-0.a \
		%/libapi-ms-win-core-winrt-robuffer-l1-1-0.a \
		%/libapi-ms-win-core-winrt-roparameterizediid-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-1.a \
		%/libapi-ms-win-core-wow64-l1-1-0.a \
		%/libapi-ms-win-core-wow64-l1-1-1.a \
		%/libapi-ms-win-core-wow64-l1-1-2.a \
		%/libapi-ms-win-core-wow64-l1-1-3.a \
		%/libapi-ms-win-core-xstate-l2-1-0.a \
		%/libapi-ms-win-core-xstate-l2-1-1.a \
		%/libapi-ms-win-devices-config-l1-1-1.a \
		%/libapi-ms-win-devices-config-l1-1-2.a \
		%/libapi-ms-win-devices-query-l1-1-0.a \
		%/libapi-ms-win-devices-query-l1-1-1.a \
		%/libapi-ms-win-devices-swdevice-l1-1-0.a \
		%/libapi-ms-win-devices-swdevice-l1-1-1.a \
		%/libapi-ms-win-eventing-classicprovider-l1-1-0.a \
		%/libapi-ms-win-eventing-consumer-l1-1-0.a \
		%/libapi-ms-win-eventing-consumer-l1-1-1.a \
		%/libapi-ms-win-eventing-controller-l1-1-0.a \
		%/libapi-ms-win-eventing-legacy-l1-1-0.a \
		%/libapi-ms-win-eventing-obsolete-l1-1-0.a \
		%/libapi-ms-win-eventing-provider-l1-1-0.a \
		%/libapi-ms-win-eventing-tdh-l1-1-0.a \
		%/libapi-ms-win-eventing-tdh-l1-1-1.a \
		%/libapi-ms-win-gaming-deviceinformation-l1-1-0.a \
		%/libapi-ms-win-gaming-expandedresources-l1-1-0.a \
		%/libapi-ms-win-gaming-tcui-l1-1-0.a \
		%/libapi-ms-win-gaming-tcui-l1-1-1.a \
		%/libapi-ms-win-gaming-tcui-l1-1-2.a \
		%/libapi-ms-win-gaming-tcui-l1-1-3.a \
		%/libapi-ms-win-gaming-tcui-l1-1-4.a \
		%/libapi-ms-win-mm-time-l1-1-0.a \
		%/libapi-ms-win-net-isolation-l1-1-0.a \
		%/libapi-ms-win-net-isolation-l1-1-1.a \
		%/libapi-ms-win-ntuser-sysparams-l1-1-0.a \
		%/libapi-ms-win-oobe-notification-l1-1-0.a \
		%/libapi-ms-win-perf-legacy-l1-1-0.a \
		%/libapi-ms-win-power-base-l1-1-0.a \
		%/libapi-ms-win-power-limitsmanagement-l1-1-0.a \
		%/libapi-ms-win-power-setting-l1-1-0.a \
		%/libapi-ms-win-power-setting-l1-1-1.a \
		%/libapi-ms-win-ro-typeresolution-l1-1-0.a \
		%/libapi-ms-win-ro-typeresolution-l1-1-1.a \
		%/libapi-ms-win-security-appcontainer-l1-1-0.a \
		%/libapi-ms-win-security-base-ansi-l1-1-0.a \
		%/libapi-ms-win-security-base-l1-1-0.a \
		%/libapi-ms-win-security-base-l1-2-0.a \
		%/libapi-ms-win-security-base-l1-2-1.a \
		%/libapi-ms-win-security-base-l1-2-2.a \
		%/libapi-ms-win-security-cpwl-l1-1-0.a \
		%/libapi-ms-win-security-credentials-l1-1-0.a \
		%/libapi-ms-win-security-cryptoapi-l1-1-0.a \
		%/libapi-ms-win-security-isolatedcontainer-l1-1-0.a \
		%/libapi-ms-win-security-isolatedcontainer-l1-1-1.a \
		%/libapi-ms-win-security-lsalookup-ansi-l2-1-0.a \
		%/libapi-ms-win-security-lsalookup-l2-1-0.a \
		%/libapi-ms-win-security-lsalookup-l2-1-1.a \
		%/libapi-ms-win-security-lsapolicy-l1-1-0.a \
		%/libapi-ms-win-security-provider-ansi-l1-1-0.a \
		%/libapi-ms-win-security-provider-l1-1-0.a \
		%/libapi-ms-win-security-sddl-ansi-l1-1-0.a \
		%/libapi-ms-win-security-sddl-l1-1-0.a \
		%/libapi-ms-win-security-systemfunctions-l1-1-0.a \
		%/libapi-ms-win-service-core-ansi-l1-1-0.a \
		%/libapi-ms-win-service-core-ansi-l1-1-1.a \
		%/libapi-ms-win-service-core-l1-1-0.a \
		%/libapi-ms-win-service-core-l1-1-1.a \
		%/libapi-ms-win-service-core-l1-1-2.a \
		%/libapi-ms-win-service-core-l1-1-3.a \
		%/libapi-ms-win-service-core-l1-1-4.a \
		%/libapi-ms-win-service-management-l1-1-0.a \
		%/libapi-ms-win-service-management-l2-1-0.a \
		%/libapi-ms-win-service-winsvc-l1-1-0.a \
		%/libapi-ms-win-shcore-obsolete-l1-1-0.a \
		%/libapi-ms-win-shcore-path-l1-1-0.a \
		%/libapi-ms-win-shcore-registry-l1-1-0.a \
		%/libapi-ms-win-shcore-registry-l1-1-1.a \
		%/libapi-ms-win-shcore-scaling-l1-1-0.a \
		%/libapi-ms-win-shcore-scaling-l1-1-1.a \
		%/libapi-ms-win-shcore-scaling-l1-1-2.a \
		%/libapi-ms-win-shcore-stream-l1-1-0.a \
		%/libapi-ms-win-shcore-stream-winrt-l1-1-0.a \
		%/libapi-ms-win-shcore-sysinfo-l1-1-0.a \
		%/libapi-ms-win-shcore-unicodeansi-l1-1-0.a \
		%/libapi-ms-win-shell-shdirectory-l1-1-0.a \
		%/libauthz.a \
		%/libbcrypt.a \
		%/libcabinet.a \
		%/libchakrart.a \
		%/libcrypt32.a \
		%/libcryptbase.a \
		%/libcryptnet.a \
		%/libd2d1.a \
		%/libd3d11.a \
		%/libd3d12.a \
		%/libd3dcompiler_47.a \
		%/libdfscli.a \
		%/libdhcpcsvc.a \
		%/libdhcpcsvc6.a \
		%/libdirectml.a \
		%/libdnsapi.a \
		%/libdsrole.a \
		%/libdwrite.a \
		%/libdxgi.a \
		%/libesent.a \
		%/libfltlib.a \
		%/libhid.a \
		%/libhrtfapo.a \
		%/libicu.a \
		%/libinkobjcore.a \
		%/libiphlpapi.a \
		%/liblogoncli.a \
		%/libmf.a \
		%/libmfplat.a \
		%/libmfreadwrite.a \
		%/libmfsensorgroup.a \
		%/libmmdevapi.a \
		%/libmpr.a \
		%/libmsajapi.a \
		%/libmscms.a \
		%/libmswsock.a \
		%/libncrypt.a \
		%/libnetutils.a \
		%/liboleaut32.a \
		%/libpowrprof.a \
		%/libprofapi.a \
		%/libpropsys.a \
		%/librometadata.a \
		%/librpcrt4.a \
		%/libsamcli.a \
		%/libschedcli.a \
		%/libsrvcli.a \
		%/libsspicli.a \
		%/libuiautomationcore.a \
		%/libuserenv.a \
		%/libwebauthn.a \
		%/libwebservices.a \
		%/libwebsocket.a \
		%/libwindows.ai.machinelearning.a \
		%/libwindows.data.pdf.a \
		%/libwindows.networking.a \
		%/libwindowscodecs.a \
		%/libwinhttp.a \
		%/libwkscli.a \
		%/libwldap32.a \
		%/libwpprecorderum.a \
		%/libws2_32.a \
		%/libxaudio2_9.a \
		%/libxmllite.a
	$(AM_V_at)rm -f $@
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(AM_V_at)$(RANLIB) $@

%/libpathcch.a: lib-common/pathcch.mri \
		%/libapi-ms-win-core-path-l1-1-0.a
	$(AM_V_at)rm -f $@
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(AM_V_at)$(RANLIB) $@

%/libruntimeobject.a: lib-common/runtimeobject.mri \
		%/libapi-ms-win-core-winrt-l1-1-0.a \
		%/libapi-ms-win-core-winrt-error-l1-1-0.a \
		%/libapi-ms-win-core-winrt-error-l1-1-1.a \
		%/libapi-ms-win-core-winrt-registration-l1-1-0.a \
		%/libapi-ms-win-core-winrt-robuffer-l1-1-0.a \
		%/libapi-ms-win-core-winrt-roparameterizediid-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-0.a \
		%/libapi-ms-win-ro-typeresolution-l1-1-0.a
	$(AM_V_at)rm -f $@
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(AM_V_at)$(RANLIB) $@

%/libsynchronization.a: lib-common/synchronization.mri \
		%/libapi-ms-win-core-synch-l1-2-0.a
	$(AM_V_at)rm -f $@
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(AM_V_at)$(RANLIB) $@

%/libwindowsapp.a: lib-common/windowsapp.mri \
		%/libapi-ms-win-appmodel-runtime-l1-1-0_windowsapp.a \
		%/libapi-ms-win-appmodel-runtime-l1-1-1_windowsapp.a \
		%/libapi-ms-win-appmodel-runtime-l1-1-2.a \
		%/libapi-ms-win-appmodel-runtime-l1-1-3.a \
		%/libapi-ms-win-core-atoms-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-com-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-com-l1-1-1_windowsapp.a \
		%/libapi-ms-win-core-com-l2-1-1.a \
		%/libapi-ms-win-core-com-midlproxystub-l1-1-0.a \
		%/libapi-ms-win-core-comm-l1-1-0.a \
		%/libapi-ms-win-core-comm-l1-1-1.a \
		%/libapi-ms-win-core-comm-l1-1-2.a \
		%/libapi-ms-win-core-console-l1-1-0.a \
		%/libapi-ms-win-core-console-l1-2-0.a \
		%/libapi-ms-win-core-console-l2-1-0.a \
		%/libapi-ms-win-core-console-l2-2-0.a \
		%/libapi-ms-win-core-console-l3-2-0.a \
		%/libapi-ms-win-core-datetime-l1-1-0.a \
		%/libapi-ms-win-core-datetime-l1-1-1.a \
		%/libapi-ms-win-core-datetime-l1-1-2.a \
		%/libapi-ms-win-core-debug-l1-1-0.a \
		%/libapi-ms-win-core-debug-l1-1-1.a \
		%/libapi-ms-win-core-delayload-l1-1-0.a \
		%/libapi-ms-win-core-delayload-l1-1-1.a \
		%/libapi-ms-win-core-enclave-l1-1-0.a \
		%/libapi-ms-win-core-errorhandling-l1-1-0.a \
		%/libapi-ms-win-core-errorhandling-l1-1-1_windowsapp.a \
		%/libapi-ms-win-core-errorhandling-l1-1-2.a \
		%/libapi-ms-win-core-errorhandling-l1-1-3_windowsapp.a \
		%/libapi-ms-win-core-featurestaging-l1-1-0.a \
		%/libapi-ms-win-core-featurestaging-l1-1-1.a \
		%/libapi-ms-win-core-fibers-l1-1-0.a \
		%/libapi-ms-win-core-fibers-l1-1-1.a \
		%/libapi-ms-win-core-fibers-l2-1-0_windowsapp.a \
		%/libapi-ms-win-core-fibers-l2-1-1.a \
		%/libapi-ms-win-core-file-ansi-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-file-ansi-l2-1-0_windowsapp.a \
		%/libapi-ms-win-core-file-fromapp-l1-1-0.a \
		%/libapi-ms-win-core-file-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-file-l1-2-0.a \
		%/libapi-ms-win-core-file-l1-2-2_windowsapp.a \
		%/libapi-ms-win-core-file-l2-1-0.a \
		%/libapi-ms-win-core-file-l2-1-2_windowsapp.a \
		%/libapi-ms-win-core-firmware-l1-1-0.a \
		%/libapi-ms-win-core-handle-l1-1-0.a \
		%/libapi-ms-win-core-heap-l1-1-0.a \
		%/libapi-ms-win-core-heap-l2-1-0_windowsapp.a \
		%/libapi-ms-win-core-heap-obsolete-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-interlocked-l1-1-0.a \
		%/libapi-ms-win-core-interlocked-l1-2-0.a \
		%/libapi-ms-win-core-io-l1-1-0.a \
		%/libapi-ms-win-core-io-l1-1-1_windowsapp.a \
		%/libapi-ms-win-core-job-l2-1-0_windowsapp.a \
		%/libapi-ms-win-core-kernel32-legacy-ansi-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-1_windowsapp.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-2_windowsapp.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-5_windowsapp.a \
		%/libapi-ms-win-core-largeinteger-l1-1-0.a \
		%/libapi-ms-win-core-libraryloader-l1-2-0_windowsapp.a \
		%/libapi-ms-win-core-libraryloader-l1-2-1.a \
		%/libapi-ms-win-core-libraryloader-l1-2-2.a \
		%/libapi-ms-win-core-libraryloader-l2-1-0.a \
		%/libapi-ms-win-core-localization-ansi-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-localization-l1-2-0_windowsapp.a \
		%/libapi-ms-win-core-localization-l1-2-1.a \
		%/libapi-ms-win-core-localization-l1-2-2.a \
		%/libapi-ms-win-core-localization-l2-1-0_windowsapp.a \
		%/libapi-ms-win-core-localization-obsolete-l1-2-0_windowsapp.a \
		%/libapi-ms-win-core-memory-l1-1-0.a \
		%/libapi-ms-win-core-memory-l1-1-1_windowsapp.a \
		%/libapi-ms-win-core-memory-l1-1-2_windowsapp.a \
		%/libapi-ms-win-core-memory-l1-1-3.a \
		%/libapi-ms-win-core-memory-l1-1-5_windowsapp.a \
		%/libapi-ms-win-core-memory-l1-1-6_windowsapp.a \
		%/libapi-ms-win-core-memory-l1-1-7_windowsapp.a \
		%/libapi-ms-win-core-namedpipe-ansi-l1-1-0.a \
		%/libapi-ms-win-core-namedpipe-ansi-l1-1-1.a \
		%/libapi-ms-win-core-namedpipe-l1-1-0.a \
		%/libapi-ms-win-core-namedpipe-l1-2-1.a \
		%/libapi-ms-win-core-namedpipe-l1-2-2.a \
		%/libapi-ms-win-core-namespace-ansi-l1-1-0.a \
		%/libapi-ms-win-core-namespace-l1-1-0.a \
		%/libapi-ms-win-core-normalization-l1-1-0.a \
		%/libapi-ms-win-core-path-l1-1-0.a \
		%/libapi-ms-win-core-privateprofile-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-privateprofile-l1-1-1_windowsapp.a \
		%/libapi-ms-win-core-processenvironment-ansi-l1-1-0.a \
		%/libapi-ms-win-core-processenvironment-l1-1-0.a \
		%/libapi-ms-win-core-processenvironment-l1-2-0_windowsapp.a \
		%/libapi-ms-win-core-processsnapshot-l1-1-0.a \
		%/libapi-ms-win-core-processthreads-l1-1-0.a \
		%/libapi-ms-win-core-processthreads-l1-1-1.a \
		%/libapi-ms-win-core-processthreads-l1-1-2_windowsapp.a \
		%/libapi-ms-win-core-processthreads-l1-1-3_windowsapp.a \
		%/libapi-ms-win-core-processtopology-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-processtopology-obsolete-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-profile-l1-1-0.a \
		%/libapi-ms-win-core-psapi-ansi-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-psapi-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-psm-appnotify-l1-1-0.a \
		%/libapi-ms-win-core-realtime-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-realtime-l1-1-1.a \
		%/libapi-ms-win-core-realtime-l1-1-2.a \
		%/libapi-ms-win-core-registry-l1-1-0.a \
		%/libapi-ms-win-core-registry-l1-1-1.a \
		%/libapi-ms-win-core-registry-l1-1-2.a \
		%/libapi-ms-win-core-registry-l2-1-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-1-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-2-0_windowsapp.a \
		%/libapi-ms-win-core-shutdown-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-slapi-l1-1-0.a \
		%/libapi-ms-win-core-string-l1-1-0.a \
		%/libapi-ms-win-core-string-l2-1-0_windowsapp.a \
		%/libapi-ms-win-core-string-obsolete-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-string-obsolete-l1-1-1.a \
		%/libapi-ms-win-core-stringansi-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-synch-ansi-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-synch-l1-1-0.a \
		%/libapi-ms-win-core-synch-l1-2-0.a \
		%/libapi-ms-win-core-synch-l1-2-1.a \
		%/libapi-ms-win-core-sysinfo-l1-1-0.a \
		%/libapi-ms-win-core-sysinfo-l1-2-0_windowsapp.a \
		%/libapi-ms-win-core-sysinfo-l1-2-1_windowsapp.a \
		%/libapi-ms-win-core-sysinfo-l1-2-3_windowsapp.a \
		%/libapi-ms-win-core-sysinfo-l1-2-5.a \
		%/libapi-ms-win-core-sysinfo-l1-2-6.a \
		%/libapi-ms-win-core-systemtopology-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-threadpool-l1-2-0.a \
		%/libapi-ms-win-core-threadpool-legacy-l1-1-0.a \
		%/libapi-ms-win-core-timezone-l1-1-0.a \
		%/libapi-ms-win-core-timezone-l1-1-1.a \
		%/libapi-ms-win-core-toolhelp-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-url-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-util-l1-1-0.a \
		%/libapi-ms-win-core-versionansi-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-versionansi-l1-1-1_windowsapp.a \
		%/libapi-ms-win-core-version-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-version-l1-1-1_windowsapp.a \
		%/libapi-ms-win-core-windowsceip-l1-1-0.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-1.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-2.a \
		%/libapi-ms-win-core-winrt-error-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-winrt-error-l1-1-1_windowsapp.a \
		%/libapi-ms-win-core-winrt-l1-1-0.a \
		%/libapi-ms-win-core-winrt-registration-l1-1-0.a \
		%/libapi-ms-win-core-winrt-robuffer-l1-1-0.a \
		%/libapi-ms-win-core-winrt-roparameterizediid-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-wow64-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-wow64-l1-1-1_windowsapp.a \
		%/libapi-ms-win-core-xstate-l2-1-0_windowsapp.a \
		%/libapi-ms-win-devices-config-l1-1-1_windowsapp.a \
		%/libapi-ms-win-devices-config-l1-1-2_windowsapp.a \
		%/libapi-ms-win-devices-query-l1-1-0_windowsapp.a \
		%/libapi-ms-win-eventing-classicprovider-l1-1-0_windowsapp.a \
		%/libapi-ms-win-eventing-consumer-l1-1-0.a \
		%/libapi-ms-win-eventing-controller-l1-1-0_windowsapp.a \
		%/libapi-ms-win-eventing-legacy-l1-1-0_windowsapp.a \
		%/libapi-ms-win-eventing-obsolete-l1-1-0_windowsapp.a \
		%/libapi-ms-win-eventing-provider-l1-1-0.a \
		%/libapi-ms-win-eventlog-legacy-l1-1-0.a \
		%/libapi-ms-win-gaming-deviceinformation-l1-1-0.a \
		%/libapi-ms-win-gaming-expandedresources-l1-1-0.a \
		%/libapi-ms-win-gaming-tcui-l1-1-0.a \
		%/libapi-ms-win-gaming-tcui-l1-1-1.a \
		%/libapi-ms-win-gaming-tcui-l1-1-2.a \
		%/libapi-ms-win-gaming-tcui-l1-1-3.a \
		%/libapi-ms-win-gaming-tcui-l1-1-4.a \
		%/libapi-ms-win-mm-time-l1-1-0_windowsapp.a \
		%/libapi-ms-win-ntuser-sysparams-l1-1-0_windowsapp.a \
		%/libapi-ms-win-power-base-l1-1-0_windowsapp.a \
		%/libapi-ms-win-power-setting-l1-1-0_windowsapp.a \
		%/libapi-ms-win-ro-typeresolution-l1-1-0.a \
		%/libapi-ms-win-ro-typeresolution-l1-1-1.a \
		%/libapi-ms-win-security-appcontainer-l1-1-0.a \
		%/libapi-ms-win-security-base-ansi-l1-1-0_windowsapp.a \
		%/libapi-ms-win-security-base-l1-1-0_windowsapp.a \
		%/libapi-ms-win-security-base-l1-2-0_windowsapp.a \
		%/libapi-ms-win-security-base-l1-2-1.a \
		%/libapi-ms-win-security-base-l1-2-2.a \
		%/libapi-ms-win-security-cpwl-l1-1-0_windowsapp.a \
		%/libapi-ms-win-security-cryptoapi-l1-1-0_windowsapp.a \
		%/libapi-ms-win-security-isolatedcontainer-l1-1-0.a \
		%/libapi-ms-win-security-lsalookup-ansi-l2-1-0.a \
		%/libapi-ms-win-security-lsalookup-l2-1-0_windowsapp.a \
		%/libapi-ms-win-security-lsapolicy-l1-1-0_windowsapp.a \
		%/libapi-ms-win-security-provider-ansi-l1-1-0.a \
		%/libapi-ms-win-security-provider-l1-1-0.a \
		%/libapi-ms-win-security-sddl-ansi-l1-1-0.a \
		%/libapi-ms-win-security-sddl-l1-1-0.a \
		%/libapi-ms-win-security-systemfunctions-l1-1-0_windowsapp.a \
		%/libapi-ms-win-service-core-l1-1-0_windowsapp.a \
		%/libapi-ms-win-service-management-l1-1-0_windowsapp.a \
		%/libapi-ms-win-service-winsvc-l1-1-0_windowsapp.a \
		%/libapi-ms-win-shcore-obsolete-l1-1-0_windowsapp.a \
		%/libapi-ms-win-shcore-stream-winrt-l1-1-0.a \
		%/libbcrypt_windowsapp.a \
		%/libcabinet_windowsapp.a \
		%/libchakrart_windowsapp.a \
		%/libcoremessaging_windowsapp.a \
		%/libcrypt32_windowsapp.a \
		%/libd3d11_windowsapp.a \
		%/libd3d12_windowsapp.a \
		%/libd3dcompiler_47_windowsapp.a \
		%/libdhcpcsvc6_windowsapp.a \
		%/libdhcpcsvc_windowsapp.a \
		%/libdiagnosticdataquery_windowsapp.a \
		%/libdirectml_windowsapp.a \
		%/libdnsapi_windowsapp.a \
		%/libdxgi_windowsapp.a \
		%/libesent_windowsapp.a \
		%/libhid_windowsapp.a \
		%/libhrtfapo_windowsapp.a \
		%/libicu.a \
		%/libinkobjcore_windowsapp.a \
		%/libiphlpapi_windowsapp.a \
		%/libmfplat_windowsapp.a \
		%/libmfsensorgroup_windowsapp.a \
		%/libmf_windowsapp.a \
		%/libmmdevapi_windowsapp.a \
		%/libmpr_windowsapp.a \
		%/libmsajapi_windowsapp.a \
		%/libmscms_windowsapp.a \
		%/libmswsock_windowsapp.a \
		%/libncrypt_windowsapp.a \
		%/libnetutils_windowsapp.a \
		%/libntdll_windowsapp.a \
		%/liboleaut32_windowsapp.a \
		%/libpowrprof_windowsapp.a \
		%/libpropsys_windowsapp.a \
		%/libpsapi_windowsapp.a \
		%/librometadata.a \
		%/librpcrt4_windowsapp.a \
		%/libsrvcli_windowsapp.a \
		%/libsspicli_windowsapp.a \
		%/libuiautomationcore_windowsapp.a \
		%/liburlmon_windowsapp.a \
		%/libwebauthn_windowsapp.a \
		%/libwebservices_windowsapp.a \
		%/libwindows.ai.machinelearning.a \
		%/libwindows.data.pdf.a \
		%/libwindows.networking.a \
		%/libwindowscodecs_windowsapp.a \
		%/libwinhttp_windowsapp.a \
		%/libwintrust_windowsapp.a \
		%/libwkscli_windowsapp.a \
		%/libwlanapi_windowsapp.a \
		%/libws2_32_windowsapp.a \
		%/libxaudio2_9_windowsapp.a
	$(AM_V_at)rm -f $@
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(AM_V_at)$(RANLIB) $@

%/libwindowscoreheadless_apiset.a: lib-common/windowscoreheadless_apiset.mri \
		%/libapi-ms-win-appmodel-runtime-l1-1-0.a \
		%/libapi-ms-win-appmodel-runtime-l1-1-1.a \
		%/libapi-ms-win-appmodel-runtime-l1-1-2.a \
		%/libapi-ms-win-appmodel-runtime-l1-1-3.a \
		%/libapi-ms-win-core-apiquery-l2-1-0.a \
		%/libapi-ms-win-core-atoms-l1-1-0.a \
		%/libapi-ms-win-core-backgroundtask-l1-1-0.a \
		%/libapi-ms-win-core-calendar-l1-1-0.a \
		%/libapi-ms-win-core-com-l1-1-0.a \
		%/libapi-ms-win-core-com-l1-1-1.a \
		%/libapi-ms-win-core-com-l1-1-2.a \
		%/libapi-ms-win-core-com-l1-1-3.a \
		%/libapi-ms-win-core-com-midlproxystub-l1-1-0.a \
		%/libapi-ms-win-core-comm-l1-1-0.a \
		%/libapi-ms-win-core-comm-l1-1-1.a \
		%/libapi-ms-win-core-comm-l1-1-2.a \
		%/libapi-ms-win-core-console-l1-1-0.a \
		%/libapi-ms-win-core-console-l1-2-0.a \
		%/libapi-ms-win-core-console-l1-2-1.a \
		%/libapi-ms-win-core-console-l2-1-0.a \
		%/libapi-ms-win-core-console-l2-2-0.a \
		%/libapi-ms-win-core-console-l3-2-0.a \
		%/libapi-ms-win-core-datetime-l1-1-0.a \
		%/libapi-ms-win-core-datetime-l1-1-1.a \
		%/libapi-ms-win-core-datetime-l1-1-2.a \
		%/libapi-ms-win-core-debug-l1-1-0.a \
		%/libapi-ms-win-core-debug-l1-1-1.a \
		%/libapi-ms-win-core-debug-l1-1-2.a \
		%/libapi-ms-win-core-debug-minidump-l1-1-0.a \
		%/libapi-ms-win-core-delayload-l1-1-0.a \
		%/libapi-ms-win-core-delayload-l1-1-1.a \
		%/libapi-ms-win-core-enclave-l1-1-0.a \
		%/libapi-ms-win-core-enclave-l1-1-1.a \
		%/libapi-ms-win-core-errorhandling-l1-1-0.a \
		%/libapi-ms-win-core-errorhandling-l1-1-1.a \
		%/libapi-ms-win-core-errorhandling-l1-1-2.a \
		%/libapi-ms-win-core-errorhandling-l1-1-3.a \
		%/libapi-ms-win-core-featurestaging-l1-1-0.a \
		%/libapi-ms-win-core-featurestaging-l1-1-1.a \
		%/libapi-ms-win-core-fibers-l1-1-0.a \
		%/libapi-ms-win-core-fibers-l1-1-1.a \
		%/libapi-ms-win-core-fibers-l2-1-0.a \
		%/libapi-ms-win-core-fibers-l2-1-1.a \
		%/libapi-ms-win-core-file-ansi-l1-1-0.a \
		%/libapi-ms-win-core-file-ansi-l2-1-0.a \
		%/libapi-ms-win-core-file-fromapp-l1-1-0.a \
		%/libapi-ms-win-core-file-l1-1-0.a \
		%/libapi-ms-win-core-file-l1-2-0.a \
		%/libapi-ms-win-core-file-l1-2-1.a \
		%/libapi-ms-win-core-file-l1-2-2.a \
		%/libapi-ms-win-core-file-l1-2-3.a \
		%/libapi-ms-win-core-file-l2-1-0.a \
		%/libapi-ms-win-core-file-l2-1-1.a \
		%/libapi-ms-win-core-file-l2-1-2.a \
		%/libapi-ms-win-core-file-l2-1-3.a \
		%/libapi-ms-win-core-firmware-l1-1-0.a \
		%/libapi-ms-win-core-handle-l1-1-0.a \
		%/libapi-ms-win-core-heap-l1-1-0.a \
		%/libapi-ms-win-core-heap-l2-1-0.a \
		%/libapi-ms-win-core-heap-obsolete-l1-1-0.a \
		%/libapi-ms-win-core-interlocked-l1-1-0.a \
		%/libapi-ms-win-core-interlocked-l1-2-0.a \
		%/libapi-ms-win-core-io-l1-1-0.a \
		%/libapi-ms-win-core-io-l1-1-1.a \
		%/libapi-ms-win-core-job-l1-1-0.a \
		%/libapi-ms-win-core-job-l2-1-0.a \
		%/libapi-ms-win-core-job-l2-1-1.a \
		%/libapi-ms-win-core-kernel32-legacy-ansi-l1-1-0.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-0.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-1.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-2.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-3.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-4.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-5.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-6.a \
		%/libapi-ms-win-core-largeinteger-l1-1-0.a \
		%/libapi-ms-win-core-libraryloader-l1-2-0.a \
		%/libapi-ms-win-core-libraryloader-l1-2-1.a \
		%/libapi-ms-win-core-libraryloader-l1-2-2.a \
		%/libapi-ms-win-core-libraryloader-l2-1-0.a \
		%/libapi-ms-win-core-localization-ansi-l1-1-0.a \
		%/libapi-ms-win-core-localization-l1-2-0.a \
		%/libapi-ms-win-core-localization-l1-2-1.a \
		%/libapi-ms-win-core-localization-l1-2-2.a \
		%/libapi-ms-win-core-localization-l1-2-3.a \
		%/libapi-ms-win-core-localization-l1-2-4.a \
		%/libapi-ms-win-core-localization-l2-1-0.a \
		%/libapi-ms-win-core-localization-obsolete-l1-2-0.a \
		%/libapi-ms-win-core-memory-l1-1-0.a \
		%/libapi-ms-win-core-memory-l1-1-1.a \
		%/libapi-ms-win-core-memory-l1-1-2.a \
		%/libapi-ms-win-core-memory-l1-1-3.a \
		%/libapi-ms-win-core-memory-l1-1-4.a \
		%/libapi-ms-win-core-memory-l1-1-5.a \
		%/libapi-ms-win-core-memory-l1-1-6.a \
		%/libapi-ms-win-core-memory-l1-1-7.a \
		%/libapi-ms-win-core-namedpipe-ansi-l1-1-0.a \
		%/libapi-ms-win-core-namedpipe-ansi-l1-1-1.a \
		%/libapi-ms-win-core-namedpipe-l1-1-0.a \
		%/libapi-ms-win-core-namedpipe-l1-2-1.a \
		%/libapi-ms-win-core-namedpipe-l1-2-2.a \
		%/libapi-ms-win-core-namespace-ansi-l1-1-0.a \
		%/libapi-ms-win-core-namespace-l1-1-0.a \
		%/libapi-ms-win-core-normalization-l1-1-0.a \
		%/libapi-ms-win-core-path-l1-1-0.a \
		%/libapi-ms-win-core-perfcounters-l1-1-0.a \
		%/libapi-ms-win-core-privateprofile-l1-1-0.a \
		%/libapi-ms-win-core-privateprofile-l1-1-1.a \
		%/libapi-ms-win-core-processenvironment-ansi-l1-1-0.a \
		%/libapi-ms-win-core-processenvironment-l1-1-0.a \
		%/libapi-ms-win-core-processenvironment-l1-2-0.a \
		%/libapi-ms-win-core-processsnapshot-l1-1-0.a \
		%/libapi-ms-win-core-processthreads-l1-1-0.a \
		%/libapi-ms-win-core-processthreads-l1-1-1.a \
		%/libapi-ms-win-core-processthreads-l1-1-2.a \
		%/libapi-ms-win-core-processthreads-l1-1-3.a \
		%/libapi-ms-win-core-processthreads-l1-1-4.a \
		%/libapi-ms-win-core-processtopology-l1-1-0.a \
		%/libapi-ms-win-core-processtopology-obsolete-l1-1-0.a \
		%/libapi-ms-win-core-processtopology-obsolete-l1-1-1.a \
		%/libapi-ms-win-core-profile-l1-1-0.a \
		%/libapi-ms-win-core-psapi-ansi-l1-1-0.a \
		%/libapi-ms-win-core-psapi-l1-1-0.a \
		%/libapi-ms-win-core-psm-appnotify-l1-1-0.a \
		%/libapi-ms-win-core-quirks-l1-1-0.a \
		%/libapi-ms-win-core-quirks-l1-1-1.a \
		%/libapi-ms-win-core-realtime-l1-1-0.a \
		%/libapi-ms-win-core-realtime-l1-1-1.a \
		%/libapi-ms-win-core-realtime-l1-1-2.a \
		%/libapi-ms-win-core-registry-l1-1-0.a \
		%/libapi-ms-win-core-registry-l1-1-1.a \
		%/libapi-ms-win-core-registry-l1-1-2.a \
		%/libapi-ms-win-core-registry-l2-1-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-1-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-2-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-2-1.a \
		%/libapi-ms-win-core-shutdown-ansi-l1-1-0.a \
		%/libapi-ms-win-core-shutdown-l1-1-0.a \
		%/libapi-ms-win-core-shutdown-l1-1-1.a \
		%/libapi-ms-win-core-sidebyside-ansi-l1-1-0.a \
		%/libapi-ms-win-core-sidebyside-l1-1-0.a \
		%/libapi-ms-win-core-slapi-l1-1-0.a \
		%/libapi-ms-win-core-state-helpers-l1-1-0.a \
		%/libapi-ms-win-core-string-l1-1-0.a \
		%/libapi-ms-win-core-string-l2-1-0.a \
		%/libapi-ms-win-core-string-l2-1-1.a \
		%/libapi-ms-win-core-string-obsolete-l1-1-0.a \
		%/libapi-ms-win-core-string-obsolete-l1-1-1.a \
		%/libapi-ms-win-core-stringansi-l1-1-0.a \
		%/libapi-ms-win-core-synch-ansi-l1-1-0.a \
		%/libapi-ms-win-core-synch-l1-1-0.a \
		%/libapi-ms-win-core-synch-l1-2-0.a \
		%/libapi-ms-win-core-synch-l1-2-1.a \
		%/libapi-ms-win-core-sysinfo-l1-1-0.a \
		%/libapi-ms-win-core-sysinfo-l1-2-0.a \
		%/libapi-ms-win-core-sysinfo-l1-2-1.a \
		%/libapi-ms-win-core-sysinfo-l1-2-2.a \
		%/libapi-ms-win-core-sysinfo-l1-2-3.a \
		%/libapi-ms-win-core-sysinfo-l1-2-4.a \
		%/libapi-ms-win-core-sysinfo-l1-2-5.a \
		%/libapi-ms-win-core-sysinfo-l1-2-6.a \
		%/libapi-ms-win-core-systemtopology-l1-1-0.a \
		%/libapi-ms-win-core-systemtopology-l1-1-1.a \
		%/libapi-ms-win-core-threadpool-l1-2-0.a \
		%/libapi-ms-win-core-threadpool-legacy-l1-1-0.a \
		%/libapi-ms-win-core-timezone-l1-1-0.a \
		%/libapi-ms-win-core-timezone-l1-1-1.a \
		%/libapi-ms-win-core-toolhelp-l1-1-0.a \
		%/libapi-ms-win-core-toolhelp-l1-1-1.a \
		%/libapi-ms-win-core-url-l1-1-0.a \
		%/libapi-ms-win-core-util-l1-1-0.a \
		%/libapi-ms-win-core-util-l1-1-1.a \
		%/libapi-ms-win-core-version-l1-1-0.a \
		%/libapi-ms-win-core-version-l1-1-1.a \
		%/libapi-ms-win-core-versionansi-l1-1-0.a \
		%/libapi-ms-win-core-versionansi-l1-1-1.a \
		%/libapi-ms-win-core-windowsceip-l1-1-0.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-0.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-1.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-2.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-3.a \
		%/libapi-ms-win-core-winrt-error-l1-1-0.a \
		%/libapi-ms-win-core-winrt-error-l1-1-1.a \
		%/libapi-ms-win-core-winrt-l1-1-0.a \
		%/libapi-ms-win-core-winrt-registration-l1-1-0.a \
		%/libapi-ms-win-core-winrt-robuffer-l1-1-0.a \
		%/libapi-ms-win-core-winrt-roparameterizediid-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-1.a \
		%/libapi-ms-win-core-wow64-l1-1-0.a \
		%/libapi-ms-win-core-wow64-l1-1-1.a \
		%/libapi-ms-win-core-wow64-l1-1-2.a \
		%/libapi-ms-win-core-wow64-l1-1-3.a \
		%/libapi-ms-win-core-xstate-l2-1-0.a \
		%/libapi-ms-win-core-xstate-l2-1-1.a \
		%/libapi-ms-win-devices-config-l1-1-1.a \
		%/libapi-ms-win-devices-config-l1-1-2.a \
		%/libapi-ms-win-devices-query-l1-1-0.a \
		%/libapi-ms-win-devices-query-l1-1-1.a \
		%/libapi-ms-win-devices-swdevice-l1-1-0.a \
		%/libapi-ms-win-devices-swdevice-l1-1-1.a \
		%/libapi-ms-win-eventing-classicprovider-l1-1-0.a \
		%/libapi-ms-win-eventing-consumer-l1-1-0.a \
		%/libapi-ms-win-eventing-consumer-l1-1-1.a \
		%/libapi-ms-win-eventing-controller-l1-1-0.a \
		%/libapi-ms-win-eventing-legacy-l1-1-0.a \
		%/libapi-ms-win-eventing-obsolete-l1-1-0.a \
		%/libapi-ms-win-eventing-provider-l1-1-0.a \
		%/libapi-ms-win-eventing-tdh-l1-1-0.a \
		%/libapi-ms-win-eventing-tdh-l1-1-1.a \
		%/libapi-ms-win-gaming-deviceinformation-l1-1-0.a \
		%/libapi-ms-win-mm-time-l1-1-0.a \
		%/libapi-ms-win-ntuser-sysparams-l1-1-0.a \
		%/libapi-ms-win-oobe-notification-l1-1-0.a \
		%/libapi-ms-win-perf-legacy-l1-1-0.a \
		%/libapi-ms-win-power-base-l1-1-0.a \
		%/libapi-ms-win-power-limitsmanagement-l1-1-0.a \
		%/libapi-ms-win-power-setting-l1-1-0.a \
		%/libapi-ms-win-power-setting-l1-1-1.a \
		%/libapi-ms-win-ro-typeresolution-l1-1-0.a \
		%/libapi-ms-win-ro-typeresolution-l1-1-1.a \
		%/libapi-ms-win-security-appcontainer-l1-1-0.a \
		%/libapi-ms-win-security-base-ansi-l1-1-0.a \
		%/libapi-ms-win-security-base-l1-1-0.a \
		%/libapi-ms-win-security-base-l1-2-0.a \
		%/libapi-ms-win-security-base-l1-2-1.a \
		%/libapi-ms-win-security-base-l1-2-2.a \
		%/libapi-ms-win-security-cpwl-l1-1-0.a \
		%/libapi-ms-win-security-credentials-l1-1-0.a \
		%/libapi-ms-win-security-cryptoapi-l1-1-0.a \
		%/libapi-ms-win-security-isolatedcontainer-l1-1-0.a \
		%/libapi-ms-win-security-isolatedcontainer-l1-1-1.a \
		%/libapi-ms-win-security-lsalookup-ansi-l2-1-0.a \
		%/libapi-ms-win-security-lsalookup-l2-1-0.a \
		%/libapi-ms-win-security-lsalookup-l2-1-1.a \
		%/libapi-ms-win-security-lsapolicy-l1-1-0.a \
		%/libapi-ms-win-security-provider-ansi-l1-1-0.a \
		%/libapi-ms-win-security-provider-l1-1-0.a \
		%/libapi-ms-win-security-sddl-ansi-l1-1-0.a \
		%/libapi-ms-win-security-sddl-l1-1-0.a \
		%/libapi-ms-win-security-systemfunctions-l1-1-0.a \
		%/libapi-ms-win-service-core-ansi-l1-1-0.a \
		%/libapi-ms-win-service-core-ansi-l1-1-1.a \
		%/libapi-ms-win-service-core-l1-1-0.a \
		%/libapi-ms-win-service-core-l1-1-1.a \
		%/libapi-ms-win-service-core-l1-1-2.a \
		%/libapi-ms-win-service-core-l1-1-3.a \
		%/libapi-ms-win-service-core-l1-1-4.a \
		%/libapi-ms-win-service-management-l1-1-0.a \
		%/libapi-ms-win-service-management-l2-1-0.a \
		%/libapi-ms-win-service-winsvc-l1-1-0.a \
		%/libapi-ms-win-shcore-obsolete-l1-1-0.a \
		%/libapi-ms-win-shcore-path-l1-1-0.a \
		%/libapi-ms-win-shcore-registry-l1-1-0.a \
		%/libapi-ms-win-shcore-registry-l1-1-1.a \
		%/libapi-ms-win-shcore-scaling-l1-1-0.a \
		%/libapi-ms-win-shcore-scaling-l1-1-1.a \
		%/libapi-ms-win-shcore-scaling-l1-1-2.a \
		%/libapi-ms-win-shcore-stream-l1-1-0.a \
		%/libapi-ms-win-shcore-stream-winrt-l1-1-0.a \
		%/libapi-ms-win-shcore-sysinfo-l1-1-0.a \
		%/libapi-ms-win-shcore-unicodeansi-l1-1-0.a \
		%/libapi-ms-win-shell-shdirectory-l1-1-0.a \
		%/libauthz.a \
		%/libbcrypt.a \
		%/libcabinet.a \
		%/libchakrart.a \
		%/libcrypt32.a \
		%/libcryptbase.a \
		%/libcryptnet.a \
		%/libdfscli.a \
		%/libdhcpcsvc.a \
		%/libdnsapi.a \
		%/libdsrole.a \
		%/libdwrite.a \
		%/libfltlib.a \
		%/libhid.a \
		%/libhrtfapo.a \
		%/libiphlpapi.a \
		%/liblogoncli.a \
		%/libmmdevapi.a \
		%/libmpr.a \
		%/libmsajapi.a \
		%/libmscms.a \
		%/libmswsock.a \
		%/libncrypt.a \
		%/libnetutils.a \
		%/libpowrprof.a \
		%/libprofapi.a \
		%/libpropsys.a \
		%/librometadata.a \
		%/librpcrt4.a \
		%/libsamcli.a \
		%/libschedcli.a \
		%/libsrvcli.a \
		%/libsspicli.a \
		%/libuserenv.a \
		%/libwebauthn.a \
		%/libwebservices.a \
		%/libwebsocket.a \
		%/libwindows.ai.machinelearning.a \
		%/libwindows.data.pdf.a \
		%/libwindows.networking.a \
		%/libwindowscodecs.a \
		%/libwinhttp.a \
		%/libwkscli.a \
		%/libwlanapi.a \
		%/libwldap32.a \
		%/libwpprecorderum.a \
		%/libxaudio2_9.a \
		%/libxmllite.a
	$(AM_V_at)rm -f $@
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(AM_V_at)$(RANLIB) $@

%/libvfw32.a: lib-common/vfw32.mri \
		%/libmsvfw32.a \
		%/libavifil32.a \
		%/libavicap32.a
	$(AM_V_at)rm -f $@
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(AM_V_at)$(RANLIB) $@

%/libucrt.a: lib-common/ucrt.mri %/libucrt_extra.a \
		%/libapi-ms-win-crt-conio-l1-1-0.a %/libapi-ms-win-crt-convert-l1-1-0.a %/libapi-ms-win-crt-environment-l1-1-0.a \
		%/libapi-ms-win-crt-filesystem-l1-1-0.a %/libapi-ms-win-crt-heap-l1-1-0.a %/libapi-ms-win-crt-locale-l1-1-0.a \
		%/libapi-ms-win-crt-math-l1-1-0.a %/libapi-ms-win-crt-multibyte-l1-1-0.a %/libapi-ms-win-crt-private-l1-1-0.a \
		%/libapi-ms-win-crt-process-l1-1-0.a %/libapi-ms-win-crt-runtime-l1-1-0.a %/libapi-ms-win-crt-stdio-l1-1-0.a \
		%/libapi-ms-win-crt-string-l1-1-0.a %/libapi-ms-win-crt-time-l1-1-0.a %/libapi-ms-win-crt-utility-l1-1-0.a
	$(AM_V_at)rm -f $@
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(AM_V_at)$(RANLIB) $@

# The same as libucrt.a above, but without the -private lib and with some more
# statically linked functions.
%/libucrtapp.a: lib-common/ucrtapp.mri %/libucrt_extra.a %/libucrtapp_extra.a \
		%/libapi-ms-win-crt-conio-l1-1-0.a %/libapi-ms-win-crt-convert-l1-1-0.a %/libapi-ms-win-crt-environment-l1-1-0.a \
		%/libapi-ms-win-crt-filesystem-l1-1-0.a %/libapi-ms-win-crt-heap-l1-1-0.a %/libapi-ms-win-crt-locale-l1-1-0.a \
		%/libapi-ms-win-crt-math-l1-1-0.a %/libapi-ms-win-crt-multibyte-l1-1-0.a \
		%/libapi-ms-win-crt-process-l1-1-0.a %/libapi-ms-win-crt-runtime-l1-1-0.a %/libapi-ms-win-crt-stdio-l1-1-0.a \
		%/libapi-ms-win-crt-string-l1-1-0.a %/libapi-ms-win-crt-time-l1-1-0.a %/libapi-ms-win-crt-utility-l1-1-0.a
	$(AM_V_at)rm -f $@
	$(AM_V_GEN)cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(AM_V_at)$(RANLIB) $@

lib32/%.def: lib32/%.def.in
	$(AM_V_GEN)$(MKDIR_P) $(@D) && $(CPP) -x c $(CPPFLAGS32) $< -Wp,-w -P -I$(top_srcdir)/def-include > $@

lib64/%.def: lib64/%.def.in
	$(AM_V_GEN)$(MKDIR_P) $(@D) && $(CPP) -x c $(CPPFLAGS64) $< -Wp,-w -P -I$(top_srcdir)/def-include > $@

libarm32/%.def: libarm32/%.def.in
	$(AM_V_GEN)$(MKDIR_P) $(@D) && $(CPP) -x c $(CPPFLAGSARM32) $< -Wp,-w -P -I$(top_srcdir)/def-include > $@

libarm64/%.def: libarm64/%.def.in
	$(AM_V_GEN)$(MKDIR_P) $(@D) && $(CPP) -x c $(CPPFLAGSARM64) $< -Wp,-w -P -I$(top_srcdir)/def-include > $@

lib32/%.def: lib-common/%.def.in
	$(AM_V_GEN)$(MKDIR_P) $(@D) && $(CPP) -x c $(CPPFLAGS32) $< -Wp,-w -P -I$(top_srcdir)/def-include > $@

lib64/%.def: lib-common/%.def.in
	$(AM_V_GEN)$(MKDIR_P) $(@D) && $(CPP) -x c $(CPPFLAGS64) $< -Wp,-w -P -I$(top_srcdir)/def-include | sed -E 's/^([^ ]+)@[0-9]+( |$$)/\1\2/' > $@

libarm32/%.def: lib-common/%.def.in
	$(AM_V_GEN)$(MKDIR_P) $(@D) && $(CPP) -x c $(CPPFLAGSARM32) $< -Wp,-w -P -I$(top_srcdir)/def-include | sed -E 's/^([^ ]+)@[0-9]+( |$$)/\1\2/' > $@

libarm64/%.def: lib-common/%.def.in
	$(AM_V_GEN)$(MKDIR_P) $(@D) && $(CPP) -x c $(CPPFLAGSARM64) $< -Wp,-w -P -I$(top_srcdir)/def-include | sed -E 's/^([^ ]+)@[0-9]+( |$$)/\1\2/' > $@

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
  $(top_srcdir)/lib-common/*.def \
  $(top_srcdir)/lib32/*.def \
  $(top_srcdir)/lib64/*.def \
  $(top_srcdir)/libarm32/*.def \
  $(top_srcdir)/lib32/*.mri \
  $(top_srcdir)/lib64/*.mri \
  $(top_srcdir)/libarm32/*.mri \
  $(top_srcdir)/lib-common/*.def.in \
  $(top_srcdir)/lib32/*.def.in \
  $(top_srcdir)/lib64/*.def.in \
  $(top_srcdir)/libarm32/*.def.in \
  $(top_srcdir)/def-include/*.def.in \
  include/filetime_to_time64.h \
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
  misc/ftw.c \
  profile/gcrt0.c \
  profile/COPYING \
  profile/CYGWIN_LICENSE \
  stdio/scanf2-argcount-template.c

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
  testcases/t_aligned_alloc \
  testcases/t_ansi_io \
  testcases/t_findfirst \
  testcases/t_float  \
  testcases/t_fstat \
  testcases/t_intrinc \
  testcases/t_imagebase \
  testcases/t_matherr \
  testcases/t_nullptrexception \
  testcases/t_readdir \
  testcases/t_snprintf \
  testcases/t_snprintf0 \
  testcases/t_snprintf1 \
  testcases/t_swprintf \
  testcases/t_swprintf0 \
  testcases/t_swprintf1 \
  testcases/t_snwprintf \
  testcases/t_snwprintf0 \
  testcases/t_snwprintf1 \
  testcases/t_stprintf_a \
  testcases/t_stprintf_u \
  testcases/t_stprintf0_a \
  testcases/t_stprintf0_u \
  testcases/t_stprintf1_a \
  testcases/t_stprintf1_u \
  testcases/t_setjmp \
  testcases/t_sigv \
  testcases/t_speed_powl \
  testcases/t_stat \
  testcases/t_stdint \
  testcases/t_time \
  testcases/t_tls1 \
  testcases/t_trycatch \
  testcases/t_stat_slash \
  testcases/t_vsscanf \
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


# Don't delete the implicit intermediate files after building.
.PRECIOUS: lib32/lib%.a lib32/%.def lib64/lib%.a lib64/%.def libarm32/lib%.a libarm32/%.def libarm64/lib%.a libarm64/%.def
