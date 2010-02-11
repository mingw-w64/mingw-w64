
EXTRA_HEADERS = \
  include/*.c \
  include/*.dlg \
  include/*.h \
  include/*.h16 \
  include/*.hxx \
  include/*.rh \
  include/*.ver \
  include/GL/*.h

baseheaddir = $(includedir)/../$(host)/include
sysheaddir = $(baseheaddir)/sys
secheaddir = $(baseheaddir)/sec_api
secsysheaddir = $(baseheaddir)/sec_api/sys
glheaddir = $(baseheaddir)/GL
sdksheaddir = $(baseheaddir)/sdks


if ENABLE_CRT
basehead_HEADERS = \
  crt/assert.h             crt/complex.h   crt/conio.h     crt/crtdbg.h    crt/crtdefs.h    crt/ctype.h       crt/direct.h           \
  crt/dirent.h             crt/dir.h       crt/dos.h       crt/eh.h        crt/errno.h      crt/fcntl.h       \
  crt/dvec.h               crt/ivec.h      crt/fvec.h      \
  crt/fenv.h               crt/float.h     crt/fpieee.h    crt/getopt.h    crt/ieeefp.h     crt/intrin.h      \
  crt/inttypes.h           crt/io.h        crt/libgen.h    crt/limits.h    crt/locale.h     crt/malloc.h      crt/math.h             \
  crt/mbctype.h            crt/mbstring.h  crt/mem.h       crt/memory.h    crt/_mingw.h     crt/_mingw_mac.h  crt/_mingw_print_pop.h \
  crt/_mingw_print_push.h  crt/new.h       crt/string.h    crt/strings.h   crt/dlfcn.h      crt/_mingw_float.h crt/_mingw_stdarg.h   \
  crt/excpt.h		   \
  crt/search.h             crt/sehmap.h    crt/setjmpex.h  crt/setjmp.h    crt/share.h      crt/stdarg.h      crt/stddef.h           \
  crt/stdexcpt.h           crt/stdint.h    crt/stdio.h     crt/stdlib.h    crt/syslimits.h  crt/tchar.h       crt/time.h             \
  crt/unistd.h             crt/utime.h     crt/vadefs.h    crt/varargs.h   crt/wchar.h      crt/xlocinfo.h    crt/xmath.h            \
  crt/ymath.h              crt/yvals.h
syshead_HEADERS = \
  crt/sys/cdefs.h  crt/sys/fcntl.h  crt/sys/file.h  crt/sys/locking.h  crt/sys/param.h    \
  crt/sys/stat.h   crt/sys/timeb.h  crt/sys/time.h  crt/sys/types.h    crt/sys/unistd.h   crt/sys/utime.h
sechead_HEADERS = \
  crt/sec_api/conio_s.h  crt/sec_api/crtdbg_s.h  crt/sec_api/io_s.h        crt/sec_api/mbstring_s.h  crt/sec_api/search_s.h \
  crt/sec_api/stdio_s.h  crt/sec_api/stdlib_s.h  crt/sec_api/stralign_s.h  crt/sec_api/string_s.h    crt/sec_api/tchar_s.h  \
  crt/sec_api/time_s.h   crt/sec_api/wchar_s.h
  crt/process.h
secsyshead_HEADERS = crt/sec_api/sys/timeb_s.h
sdkshead_HEADERS = crt/sdks/_mingw_directx.h crt/sdks/_mingw_ddk.h
else
basehead_HEADERS = 
syshead_HEADERS = 
sechead_HEADERS = 
secsyshead_HEADERS = 
sdkshead_HEADERS = 
endif


basehead_HEADERS += @BASEHEAD_LIST@
sdkshead_HEADERS += @SDKSHEAD_LIST@
glhead_HEADERS = @GLHEAD_LIST@


ddkheaddir = $(baseheaddir)/ddk
dxheaddir = $(baseheaddir)

ddkhead_HEADERS = @DDKHEAD_LIST@
dxhead_HEADERS = @DXHEAD_LIST@

DISTCHECK_CONFIGURE_FLAGS = --enable-sdk=all
