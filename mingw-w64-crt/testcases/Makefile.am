# Compiler flags valid for both C and C++
TEST_CFLAGS=-Wno-format -Wno-unused-parameter -Wno-error=unused-function

AM_CFLAGS=@ADD_C_CXX_WARNING_FLAGS@ @ADD_C_ONLY_WARNING_FLAGS@ $(TEST_CFLAGS) -Wno-missing-prototypes
AM_CXXFLAGS=@ADD_C_CXX_WARNING_FLAGS@ @ADD_CXX_ONLY_WARNING_FLAGS@ $(TEST_CFLAGS)

# Used by t_safe_flush
libprocdetach.dll: libprocdetach.o
	$(LINK) -shared libprocdetach.o -o libprocdetach.dll

testcase_progs = \
  tstmainc \
  tstmaincpp \
  tstmain_sys_xxx \
  t__fstat_all \
  t__stat_all \
  t_aligned_alloc \
  t_ansi_io \
  t_assert \
  t_btowc \
  t_ctype \
  t_excpt_gcc_cpp \
  t_excpt_int_divzero \
  t_excpt_int_divzero_thrd \
  t_excpt_int_overflow \
  t_excpt_int_overflow_thrd \
  t_findfirst \
  t_float  \
  t_format_Z \
  t_format_Z0 \
  t_format_Z1 \
  t_fseeki64 \
  t_fseeki64_ftelli64 \
  t_fstat \
  t_fstat_f64 \
  t_fstat_t64 \
  t_fstat_t64_f64 \
  t_intrinc \
  t_imagebase \
  t_iswctype \
  t_lfs \
  t_lseeki64 \
  t_matherr \
  t_mbrlen \
  t_mbrtowc \
  t_mbsrtowcs \
  t_nullptrexception \
  t_printf_g_width \
  t_readdir \
  t_safe_flush \
  t_snprintf \
  t_snprintf0 \
  t_snprintf1 \
  t_swprintf \
  t_swprintf0 \
  t_swprintf1 \
  t_snwprintf \
  t_snwprintf0 \
  t_snwprintf1 \
  t_stprintf_a \
  t_stprintf_u \
  t_stprintf0_a \
  t_stprintf0_u \
  t_stprintf1_a \
  t_stprintf1_u \
  t_setjmp \
  t_sigfpe \
  t_sigv \
  t_speed_powl \
  t_stat \
  t_stat_f64 \
  t_stat_t64 \
  t_stat_t64_f64 \
  t_stderr_buffering \
  t_stdint \
  t_time \
  t_tls1 \
  t_tmpfile \
  t_trycatch \
  t_stat_slash \
  t_towctrans \
  t_utime \
  t_vsscanf \
  t_wcrtomb \
  t_wcsrtombs \
  t_wcstok_s \
  t_wctob \
  t_wctype \
  t_wreaddir \
  t_fseeko64

# Most of the tests are C programs, but there are some C++ tests as well.
# For C++ targets, we have to explicitly specify source files so that
# Automake does not assume .c extension.
tstmaincpp_SOURCES = tstmaincpp.cpp
t_trycatch_SOURCES = t_trycatch.cpp

# Compile t_intrinc in C99 mode
t_intrinc_CFLAGS = -std=c99 $(AM_CFLAGS)

# Link t_safe_flush against libprocdetach.dll
t_safe_flush_LDADD = libprocdetach.dll

# Link t_trycatch statically to make it easier to run it on arm64ec
t_trycatch_LDFLAGS = -static

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
