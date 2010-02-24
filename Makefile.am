if HEADER
  MAYBE_HEADER = mingw-w64-headers
endif

if CRT
  MAYBE_CRT = mingw-w64-crt
endif

if LIBRARIES_MANGLE
  MAYBE_LIBRARIES_MANGLE = mingw-w64-libraries/libmangle
endif

if LIBRARIES_PSEH
  MAYBE_LIBRARIES_PSEH = mingw-w64-libraries/pseh
endif

if TOOLS_GENDEF
  MAYBE_TOOLS_GENDEF = mingw-w64-tools/gendef
endif

SUBDIRS = $(MAYBE_HEADER) $(MAYBE_CRT) $(MAYBE_LIBRARIES_MANGLE) $(MAYBE_LIBRARIES_PSEH) $(MAYBE_TOOLS_GENDEF)

DISTCHECK_CONFIGURE_FLAGS = --with-headers --with-crt --with-libraries=all --with-tools=all

