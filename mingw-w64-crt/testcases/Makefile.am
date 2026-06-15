# Compiler flags valid for both C and C++
TEST_CFLAGS=-Wno-format -Wno-unused-parameter -Wno-error=unused-function

AM_CFLAGS=@ADD_C_CXX_WARNING_FLAGS@ @ADD_C_ONLY_WARNING_FLAGS@ $(TEST_CFLAGS) -Wno-missing-prototypes
AM_CXXFLAGS=@ADD_C_CXX_WARNING_FLAGS@ @ADD_CXX_ONLY_WARNING_FLAGS@ $(TEST_CFLAGS)

# Used by t_safe_flush
libprocdetach.dll: libprocdetach.o
	$(LINK) -shared libprocdetach.o -o libprocdetach.dll

# Note that this list is usually sorted in alphabetical order.
# An exception is when variants of the same test are grouped together.
testcase_progs = \
  t__fstat_all \
  t__stat_all \
  t__sys_errlist \
  t_aligned_alloc \
  t_ansi_io \
  t_assert \
  t_btowc \
  t_char16_t \
  t_ctype \
  t_excpt_gcc_cpp \
  t_excpt_int_divzero \
  t_excpt_int_divzero_thrd \
  t_excpt_int_overflow \
  t_excpt_int_overflow_thrd \
  t_exp_denormal \
  t_expm1 \
  t_fctptr \
  t_findfirst \
  t_float  \
  t_fmod \
  t_format_Z \
  t_format_Z0 \
  t_format_Z1 \
  t_fseeki64 \
  t_fseeki64_ftelli64 \
  t_fseeko64 \
  t_fstat \
  t_fstat_f64 \
  t_fstat_t64 \
  t_fstat_t64_f64 \
  t_imagebase \
  t_intrinc \
  t_isfine \
  t_iswctype \
  t_ivma \
  t_lfs \
  t_lseeki64 \
  t_main \
  t_main_cpp \
  t_matherr \
  t_mbrlen \
  t_mbrtowc \
  t_mbsrtowcs \
  t_nullptrexception \
  t_printf \
  t_printf_g_width \
  t_readdir \
  t_safe_flush \
  t_setjmp \
  t_sigfpe \
  t_sigv \
  t_snprintf \
  t_snprintf0 \
  t_snprintf1 \
  t_snwprintf \
  t_snwprintf0 \
  t_snwprintf1 \
  t_speed_powl \
  t_stat \
  t_stat_f64 \
  t_stat_t64 \
  t_stat_t64_f64 \
  t_stat_slash \
  t_staticconstmember \
  t_stderr_buffering \
  t_stdint \
  t_stprintf_a \
  t_stprintf_u \
  t_stprintf0_a \
  t_stprintf0_u \
  t_stprintf1_a \
  t_stprintf1_u \
  t_swprintf \
  t_swprintf0 \
  t_swprintf1 \
  t_time \
  t_tls_ansi \
  t_tls_c11 \
  t_tmpfile \
  t_towctrans \
  t_trycatch \
  t_utime \
  t_vsscanf \
  t_wcrtomb \
  t_wcsrtombs \
  t_wcstok_s \
  t_wctob \
  t_wctype \
  t_wreaddir

# FIXME: the following tests are disabled on arm64ec; linking them statically
# with msvcrt.dll results in link error due to references to functions not
# available in msvcrt.dll, e.g. _strftime_l.
if !ARM64EC
testcase_progs += \
  t_iostream \
  t_wrongret
endif

# Most of the tests are C programs, but there are some C++ tests as well.
# For C++ targets, we have to explicitly specify source files so that
# Automake does not assume .c extension.
t_iostream_SOURCES = t_iostream.cpp
t_isfine_SOURCES = t_isfine.cpp
t_main_cpp_SOURCES = t_main_cpp.cpp
t_staticconstmember_SOURCES = t_staticconstmember.cpp
t_trycatch_SOURCES = t_trycatch.cpp
t_wrongret_SOURCES = t_wrongret.cpp

# On arm64ec, link all C++ tests statically; the toolchain (and the C++ DLL in
# PATH) may be regular native aarch64, but we build and run arm64ec binaries.
t_iostream_LDFLAGS = $(AM_LDFLAGS)
t_isfine_LDFLAGS = $(AM_LDFLAGS)
t_main_cpp_LDFLAGS = $(AM_LDFLAGS)
t_staticconstmember_LDFLAGS = $(AM_LDFLAGS)
t_trycatch_LDFLAGS = $(AM_LDFLAGS)
t_wrongret_LDFLAGS = $(AM_LDFLAGS)

if ARM64EC
t_iostream_LDFLAGS += -static
t_isfine_LDFLAGS += -static
t_main_cpp_LDFLAGS += -static
t_staticconstmember_LDFLAGS += -static
t_trycatch_LDFLAGS += -static
t_wrongret_LDFLAGS += -static
endif

# Compile t_intrinc in C99 mode
t_intrinc_CFLAGS = -std=c99 $(AM_CFLAGS)

# Link t_safe_flush against libprocdetach.dll
t_safe_flush_LDADD = libprocdetach.dll

# Compile t_tls_ansi in C89 mode
t_tls_ansi_CFLAGS = -std=c89 $(AM_CFLAGS)

# Compile t_tls_c11 in C11 mode
t_tls_c11_CFLAGS = -std=c11 $(AM_CFLAGS)

if ENABLE_TESTS_UNICODE
  # The following tests require compiler support for -municode option
  testcase_progs += \
    t__wstat_all \
    t_municode \
    t_tmain

  t_municode_CFLAGS = -municode $(AM_CFLAGS)
  t_tmain_CFLAGS = -municode -D_UNICODE $(AM_CFLAGS)
  t__wstat_all_CFLAGS = -municode $(AM_CFLAGS)
endif

check_LIBRARIES =

check_PROGRAMS = \
  $(testcase_progs)

# Do not specify TESTS = check_PROGRAMS, because some TESTS
# may not be check_PROGRAMS.
TESTS = \
  $(testcase_progs)

XFAIL_TESTS = \
  t_excpt_int_divzero \
  t_excpt_int_divzero_thrd \
  t_excpt_int_overflow \
  t_excpt_int_overflow_thrd \
  t_nullptrexception

# Include the complex math testcase fragment.
include complex/Makefile.am

EXTRA_DIST = \
  t_snprintf_tmpl.h \
  t_snwprintf_tmpl.h \
  t_stprintf_tmpl.h \
  t_swprintf_tmpl.h

CLEANFILES = \
  libprocdetach.dll
