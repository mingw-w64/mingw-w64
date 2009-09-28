
EXTRA_HEADERS = \
  include/*.c \
  include/*.dlg \
  include/*.h \
  include/*.h16 \
  include/*.hxx \
  include/*.rh \
  include/*.ver \
  include/sys/*.h \
  include/sec_api/*.h \
  include/sec_api/sys/*.h \
  include/GL/*.h

sysheaddir = $(includedir)/sys
secheaddir = $(includedir)/sec_api
secsysheaddir = $(includedir)/sec_api/sys
glheaddir = $(includedir)/GL
sdksheaddir = $(includedir)/sdks

include_HEADERS = @BASEHEAD_LIST@
syshead_HEADERS = @SYSHEAD_LIST@
sechead_HEADERS = @SECHEAD_LIST@
secsyshead_HEADERS = @SECSYSHEAD_LIST@
glhead_HEADERS = @GLHEAD_LIST@
sdkshead_HEADERS = @SDKSHEAD_LIST@

#Optional headers

ddkheaddir = $(includedir)/ddk
dxheaddir = $(includedir)

ddkhead_HEADERS = @DDKHEAD_LIST@
dxhead_HEADERS = @DXHEAD_LIST@


