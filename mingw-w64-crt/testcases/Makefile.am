TEST_CFLAGS=-Wno-format -Wno-unused-parameter -Wno-error=unused-function
AM_CFLAGS=@ADD_C_CXX_WARNING_FLAGS@ @ADD_C_ONLY_WARNING_FLAGS@ $(TEST_CFLAGS) -Wno-missing-prototypes
AM_CXXFLAGS=@ADD_C_CXX_WARNING_FLAGS@ @ADD_CXX_ONLY_WARNING_FLAGS@ $(TEST_CFLAGS)

# Testsuite options
#

#old
#  tstwassert_win \
#  tstwinmain \
#  tstwassert \
#  testcases_tstwinmain_LDADD = -lgdi32

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
  t_findfirst \
  t_float  \
  t_fseeki64 \
  t_fseeki64_ftelli64 \
  t_fstat \
  t_fstat_f64 \
  t_fstat_t64 \
  t_fstat_t64_f64 \
  t_intrinc \
  t_imagebase \
  t_lfs \
  t_lseeki64 \
  t_matherr \
  t_mbrlen \
  t_mbrtowc \
  t_mbsrtowcs \
  t_nullptrexception \
  t_printf_g_width \
  t_readdir \
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
  t_sigv \
  t_speed_powl \
  t_stat \
  t_stat_f64 \
  t_stat_t64 \
  t_stat_t64_f64 \
  t_stdint \
  t_time \
  t_tls1 \
  t_tmpfile \
  t_trycatch \
  t_stat_slash \
  t_utime \
  t_vsscanf \
  t_wcrtomb \
  t_wcsrtombs \
  t_wcstok_s \
  t_wctob \
  t_wreaddir \
  t_fseeko64

EXTRA_DIST = \
  t_snprintf_tmpl.h \
  t_snwprintf_tmpl.h \
  t_stprintf_tmpl.h \
  t_swprintf_tmpl.h

tstmaincpp_SOURCES = tstmaincpp.cpp
t_trycatch_SOURCES = t_trycatch.cpp
t_trycatch_LDFLAGS = -static
t_intrinc_CFLAGS = -std=c99 $(AM_CFLAGS)

if ENABLE_TESTS_UNICODE
  testcase_progs += t_municode t_tmain t__wstat_all
  t_municode_CFLAGS = -municode $(AM_CFLAGS)
  t_tmain_CFLAGS = -municode -D_UNICODE $(AM_CFLAGS)
  t__wstat_all_CFLAGS = -municode $(AM_CFLAGS)
endif

# Do not specify TESTS = check_PROGRAMS, because some TESTS
# may not be check_PROGRAMS.
check_LIBRARIES =
check_PROGRAMS = $(testcase_progs)
TESTS = $(testcase_progs)
XFAIL_TESTS = \
  t_nullptrexception

# Include the complex math testcase fragment.
include complex/Makefile.am
