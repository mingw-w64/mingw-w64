
baseheaddir = $(includedir)/../$(host)/include
sysheaddir = $(baseheaddir)/sys
secheaddir = $(baseheaddir)/sec_api
secsysheaddir = $(baseheaddir)/sec_api/sys
glheaddir = $(baseheaddir)/GL
wshelperheaddir = $(baseheaddir)/mingw_inc
sdksheaddir = $(baseheaddir)/sdks

basehead_HEADERS = @BASEHEAD_LIST@
syshead_HEADERS = @SYSHEAD_LIST@
sechead_HEADERS = @SECHEAD_LIST@
secsyshead_HEADERS = @SECSYSHEAD_LIST@
glhead_HEADERS = @GLHEAD_LIST@
wshelperhead_HEADERS = @WSHELPERHEAD_LIST@
sdkshead_HEADERS = _mingw_directx.h _mingw_ddk.h

ddkheaddir = $(baseheaddir)/ddk
dxheaddir = $(baseheaddir)

ddkhead_HEADERS = @DDKHEAD_LIST@
dxhead_HEADERS = @DXHEAD_LIST@

EXTRA_DIST = ChangeLog-2009
DISTCHECK_CONFIGURE_FLAGS = --enable-sdk=all

EXTRA_HEADERS = \
  include/*.c \
  include/*.dlg \
  include/*.h \
  include/*.h16 \
  include/*.hxx \
  include/*.rh \
  include/*.ver \
  include/GL/*.h \
  include/mingw_inc/*.h \
  crt/*.h \
  crt/sys/*.h \
  crt/sec_api/*.h \
  crt/sec_api/sys/*.h \
  direct-x/include/*.h \
  direct-x/include/*.idl \
  ddk/include/ddk/*.h

BUILT_SOURCES = \
  _mingw_directx.h \
  _mingw_ddk.h

_mingw_directx.h: $(srcdir)/crt/sdks/_mingw_directx.h.in
	$(SED) s/MINGW_HAS_DX$$/@MINGW_HAS_DX@/ $< > $@

_mingw_ddk.h: $(srcdir)/crt/sdks/_mingw_ddk.h.in
	$(SED) s/MINGW_HAS_DDK$$/@MINGW_HAS_DDK@/ $< > $@
