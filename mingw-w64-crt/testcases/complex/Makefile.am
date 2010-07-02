# This Software is provided under the Zope Public License (ZPL) Version 2.1.
#
# Copyright (c) 2009, 2010 by the mingw-w64 project
#
# See the AUTHORS file for the list of contributors to the mingw-w64 project.
#
# This license has been certified as open source. It has also been designated
# as GPL compatible by the Free Software Foundation (FSF).
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
#   1. Redistributions in source code must retain the accompanying copyright
#      notice, this list of conditions, and the following disclaimer.
#   2. Redistributions in binary form must reproduce the accompanying
#      copyright notice, this list of conditions, and the following disclaimer
#      in the documentation and/or other materials provided with the
#      distribution.
#   3. Names of the copyright holders must not be used to endorse or promote
#      products derived from this software without prior written permission
#      from the copyright holders.
#   4. The right to distribute this software or to use it for any purpose does
#      not give you the right to use Servicemarks (sm) or Trademarks (tm) of
#      the copyright holders.  Use of them is covered by separate agreement
#      with the copyright holders.
#   5. If any files are modified, you must cause the modified files to carry
#      prominent notices stating that you changed the files and the date of
#      any change.
#
# Disclaimer
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY EXPRESSED
# OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
# EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
# OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
# LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
# EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# This testsuite automake fragment is meant to be included
# by the main automake Makefile.am
#
# Due to automake limitations, references are relative to the top level,
# and not the subdirectory in which this resides.

# Complex library check sources.
check_complex_lib_sources = \
  testcases/complex/complex_test.h \
  testcases/complex/cabs.c \
  testcases/complex/cacos.c \
  testcases/complex/cacosh.c \
  testcases/complex/carg.c \
  testcases/complex/casin.c \
  testcases/complex/casinh.c \
  testcases/complex/catan.c \
  testcases/complex/catanh.c \
  testcases/complex/ccos.c \
  testcases/complex/ccosh.c \
  testcases/complex/cexp.c \
  testcases/complex/cimag.c \
  testcases/complex/clog.c \
  testcases/complex/conj.c \
  testcases/complex/cpow.c \
  testcases/complex/cproj.c \
  testcases/complex/creal.c \
  testcases/complex/csin.c \
  testcases/complex/csinh.c \
  testcases/complex/csqrt.c \
  testcases/complex/ctan.c \
  testcases/complex/ctanh.c

complex_inc = -I$(top_srcdir)/complex

# 32 bit tests.
if LIB32

# Complex library support libs.
newcomplex_test_lib32 = \
  tests32/libnewcomplextestsf.a \
  tests32/libnewcomplextests.a \
  tests32/libnewcomplextestsld.a

# Build the libraries
check_LIBRARIES += $(newcomplex_test_lib32)

# Build the programs during make check.
check_PROGRAMS += $(newcomplex_tests32)

# Declare the tests.
TESTS += $(newcomplex_tests32)
# Remove these when completed.
XFAIL_TESTS += 

tests32_libnewcomplextestsf_a_CPPFLAGS= $(CPPFLAGS32) -D_NEW_COMPLEX_FLOAT=1 $(complex_inc) $(AM_CPPFLAGS)
tests32_libnewcomplextestsf_a_SOURCES = $(check_complex_lib_sources)
tests32_libnewcomplextests_a_CPPFLAGS= $(CPPFLAGS32) -D_NEW_COMPLEX_DOUBLE=1 $(complex_inc) $(AM_CPPFLAGS)
tests32_libnewcomplextests_a_SOURCES = $(check_complex_lib_sources)
tests32_libnewcomplextestsld_a_CPPFLAGS= $(CPPFLAGS32) -D_NEW_COMPLEX_LDOUBLE=1 $(complex_inc) $(AM_CPPFLAGS)
tests32_libnewcomplextestsld_a_SOURCES = $(check_complex_lib_sources)

# Complex library actual test programs.
newcomplex_tests32 = \
  tests32/cimag  \
  tests32/creal  \
  tests32/cabs   \
  tests32/cacos  \
  tests32/cacosh \
  tests32/carg   \
  tests32/casin  \
  tests32/casinh \
  tests32/catan  \
  tests32/catanh \
  tests32/ccos   \
  tests32/ccosh  \
  tests32/cexp   \
  tests32/clog   \
  tests32/conj   \
  tests32/cpow   \
  tests32/cproj  \
  tests32/csin   \
  tests32/csinh  \
  tests32/csqrt  \
  tests32/ctan   \
  tests32/ctanh

# Each test program is built with main.c, with TESTFUNC defined as the function
# the main test program calls all three abi versions of the function being
# tested.
tests32_cabs_SOURCES = testcases/complex/main.c
tests32_cabs_CPPFLAGS = $(CPPFLAGS32) -DTESTFUNC=cabs $(complex_inc) $(AM_CPPFLAGS)
tests32_cabs_LDFLAGS = $(LDFLAGS32) $(AM_LDFLAGS)
tests32_cabs_LDADD = $(newcomplex_test_lib32) $(LDADD)

tests32_cacos_SOURCES = testcases/complex/main.c
tests32_cacos_CPPFLAGS = $(CPPFLAGS32) -DTESTFUNC=cacos $(complex_inc) $(AM_CPPFLAGS)
tests32_cacos_LDFLAGS = $(LDFLAGS32) $(AM_LDFLAGS)
tests32_cacos_LDADD = $(newcomplex_test_lib32) $(LDADD)

tests32_cacosh_SOURCES = testcases/complex/main.c
tests32_cacosh_CPPFLAGS = $(CPPFLAGS32) -DTESTFUNC=cacosh $(complex_inc) $(AM_CPPFLAGS)
tests32_cacosh_LDFLAGS = $(LDFLAGS32) $(AM_LDFLAGS)
tests32_cacosh_LDADD = $(newcomplex_test_lib32) $(LDADD)

tests32_carg_SOURCES = testcases/complex/main.c
tests32_carg_CPPFLAGS = $(CPPFLAGS32) -DTESTFUNC=carg $(complex_inc) $(AM_CPPFLAGS)
tests32_carg_LDFLAGS = $(LDFLAGS32) $(AM_LDFLAGS)
tests32_carg_LDADD = $(newcomplex_test_lib32) $(LDADD)

tests32_casin_SOURCES = testcases/complex/main.c
tests32_casin_CPPFLAGS = $(CPPFLAGS32) -DTESTFUNC=casin $(complex_inc) $(AM_CPPFLAGS)
tests32_casin_LDFLAGS = $(LDFLAGS32) $(AM_LDFLAGS)
tests32_casin_LDADD = $(newcomplex_test_lib32) $(LDADD)

tests32_casinh_SOURCES = testcases/complex/main.c
tests32_casinh_CPPFLAGS = $(CPPFLAGS32) -DTESTFUNC=casinh $(complex_inc) $(AM_CPPFLAGS)
tests32_casinh_LDFLAGS = $(LDFLAGS32) $(AM_LDFLAGS)
tests32_casinh_LDADD = $(newcomplex_test_lib32) $(LDADD)

tests32_catan_SOURCES = testcases/complex/main.c
tests32_catan_CPPFLAGS = $(CPPFLAGS32) -DTESTFUNC=catan $(complex_inc) $(AM_CPPFLAGS)
tests32_catan_LDFLAGS = $(LDFLAGS32) $(AM_LDFLAGS)
tests32_catan_LDADD = $(newcomplex_test_lib32) $(LDADD)

tests32_catanh_SOURCES = testcases/complex/main.c
tests32_catanh_CPPFLAGS = $(CPPFLAGS32) -DTESTFUNC=catanh $(complex_inc) $(AM_CPPFLAGS)
tests32_catanh_LDFLAGS = $(LDFLAGS32) $(AM_LDFLAGS)
tests32_catanh_LDADD = $(newcomplex_test_lib32) $(LDADD)

tests32_ccos_SOURCES = testcases/complex/main.c
tests32_ccos_CPPFLAGS = $(CPPFLAGS32) -DTESTFUNC=ccos $(complex_inc) $(AM_CPPFLAGS)
tests32_ccos_LDFLAGS = $(LDFLAGS32) $(AM_LDFLAGS)
tests32_ccos_LDADD = $(newcomplex_test_lib32) $(LDADD)

tests32_ccosh_SOURCES = testcases/complex/main.c
tests32_ccosh_CPPFLAGS = $(CPPFLAGS32) -DTESTFUNC=ccosh $(complex_inc) $(AM_CPPFLAGS)
tests32_ccosh_LDFLAGS = $(LDFLAGS32) $(AM_LDFLAGS)
tests32_ccosh_LDADD = $(newcomplex_test_lib32) $(LDADD)

tests32_cexp_SOURCES = testcases/complex/main.c
tests32_cexp_CPPFLAGS = $(CPPFLAGS32) -DTESTFUNC=cexp $(complex_inc) $(AM_CPPFLAGS)
tests32_cexp_LDFLAGS = $(LDFLAGS32) $(AM_LDFLAGS)
tests32_cexp_LDADD = $(newcomplex_test_lib32) $(LDADD)

tests32_cimag_SOURCES = testcases/complex/main.c
tests32_cimag_CPPFLAGS = $(CPPFLAGS32) -DTESTFUNC=cimag $(complex_inc) $(AM_CPPFLAGS)
tests32_cimag_LDFLAGS = $(LDFLAGS32) $(AM_LDFLAGS)
tests32_cimag_LDADD = $(newcomplex_test_lib32) $(LDADD)

tests32_clog_SOURCES = testcases/complex/main.c
tests32_clog_CPPFLAGS = $(CPPFLAGS32) -DTESTFUNC=clog $(complex_inc) $(AM_CPPFLAGS)
tests32_clog_LDFLAGS = $(LDFLAGS32) $(AM_LDFLAGS)
tests32_clog_LDADD = $(newcomplex_test_lib32) $(LDADD)

tests32_conj_SOURCES = testcases/complex/main.c
tests32_conj_CPPFLAGS = $(CPPFLAGS32) -DTESTFUNC=conj $(complex_inc) $(AM_CPPFLAGS)
tests32_conj_LDFLAGS = $(LDFLAGS32) $(AM_LDFLAGS)
tests32_conj_LDADD = $(newcomplex_test_lib32) $(LDADD)

tests32_cpow_SOURCES = testcases/complex/main.c
tests32_cpow_CPPFLAGS = $(CPPFLAGS32) -DTESTFUNC=cpow $(complex_inc) $(AM_CPPFLAGS)
tests32_cpow_LDFLAGS = $(LDFLAGS32) $(AM_LDFLAGS)
tests32_cpow_LDADD = $(newcomplex_test_lib32) $(LDADD)

tests32_cproj_SOURCES = testcases/complex/main.c
tests32_cproj_CPPFLAGS = $(CPPFLAGS32) -DTESTFUNC=cproj $(complex_inc) $(AM_CPPFLAGS)
tests32_cproj_LDFLAGS = $(LDFLAGS32) $(AM_LDFLAGS)
tests32_cproj_LDADD = $(newcomplex_test_lib32) $(LDADD)

tests32_creal_SOURCES = testcases/complex/main.c
tests32_creal_CPPFLAGS = $(CPPFLAGS32) -DTESTFUNC=creal $(complex_inc) $(AM_CPPFLAGS)
tests32_creal_LDFLAGS = $(LDFLAGS32) $(AM_LDFLAGS)
tests32_creal_LDADD = $(newcomplex_test_lib32) $(LDADD)

tests32_csin_SOURCES = testcases/complex/main.c
tests32_csin_CPPFLAGS = $(CPPFLAGS32) -DTESTFUNC=csin $(complex_inc) $(AM_CPPFLAGS)
tests32_csin_LDFLAGS = $(LDFLAGS32) $(AM_LDFLAGS)
tests32_csin_LDADD = $(newcomplex_test_lib32) $(LDADD)

tests32_csinh_SOURCES = testcases/complex/main.c
tests32_csinh_CPPFLAGS = $(CPPFLAGS32) -DTESTFUNC=csinh $(complex_inc) $(AM_CPPFLAGS)
tests32_csinh_LDFLAGS = $(LDFLAGS32) $(AM_LDFLAGS)
tests32_csinh_LDADD = $(newcomplex_test_lib32) $(LDADD)

tests32_csqrt_SOURCES = testcases/complex/main.c
tests32_csqrt_CPPFLAGS = $(CPPFLAGS32) -DTESTFUNC=csqrt $(complex_inc) $(AM_CPPFLAGS)
tests32_csqrt_LDFLAGS = $(LDFLAGS32) $(AM_LDFLAGS)
tests32_csqrt_LDADD = $(newcomplex_test_lib32) $(LDADD)

tests32_ctan_SOURCES = testcases/complex/main.c
tests32_ctan_CPPFLAGS = $(CPPFLAGS32) -DTESTFUNC=ctan $(complex_inc) $(AM_CPPFLAGS)
tests32_ctan_LDFLAGS = $(LDFLAGS32) $(AM_LDFLAGS)
tests32_ctan_LDADD = $(newcomplex_test_lib32) $(LDADD)

tests32_ctanh_SOURCES = testcases/complex/main.c
tests32_ctanh_CPPFLAGS = $(CPPFLAGS32) -DTESTFUNC=ctanh $(complex_inc) $(AM_CPPFLAGS)
tests32_ctanh_LDFLAGS = $(LDFLAGS32) $(AM_LDFLAGS)
tests32_ctanh_LDADD = $(newcomplex_test_lib32) $(LDADD)

endif LIB32

# 64 bit tests.
if LIB64

# Complex library support libs.
newcomplex_test_lib64 = \
  tests64/libnewcomplextestsf.a \
  tests64/libnewcomplextests.a \
  tests64/libnewcomplextestsld.a

# Build the libraries
check_LIBRARIES += $(newcomplex_test_lib64)

# Build the programs during make check.
check_PROGRAMS += $(newcomplex_tests64)

# Declare the tests.
TESTS += $(newcomplex_tests64)
XFAIL_TESTS += 

tests64_libnewcomplextestsf_a_CPPFLAGS= $(CPPFLAGS64) -D_NEW_COMPLEX_FLOAT=1 $(complex_inc) $(AM_CPPFLAGS)
tests64_libnewcomplextestsf_a_SOURCES = $(check_complex_lib_sources)
tests64_libnewcomplextests_a_CPPFLAGS= $(CPPFLAGS64) -D_NEW_COMPLEX_DOUBLE=1 $(complex_inc) $(AM_CPPFLAGS)
tests64_libnewcomplextests_a_SOURCES = $(check_complex_lib_sources)
tests64_libnewcomplextestsld_a_CPPFLAGS= $(CPPFLAGS64) -D_NEW_COMPLEX_LDOUBLE=1 $(complex_inc) $(AM_CPPFLAGS)
tests64_libnewcomplextestsld_a_SOURCES = $(check_complex_lib_sources)

# Complex library actual test programs.
newcomplex_tests64 = \
  tests64/cimag  \
  tests64/creal  \
  tests64/cabs   \
  tests64/cacos  \
  tests64/cacosh \
  tests64/carg   \
  tests64/casin  \
  tests64/casinh \
  tests64/catan  \
  tests64/catanh \
  tests64/ccos   \
  tests64/ccosh  \
  tests64/cexp   \
  tests64/clog   \
  tests64/conj   \
  tests64/cpow   \
  tests64/cproj  \
  tests64/csin   \
  tests64/csinh  \
  tests64/csqrt  \
  tests64/ctan   \
  tests64/ctanh

# Each test program is built with main.c, with TESTFUNC defined as the function
# the main test program calls all three abi versions of the function being
# tested.
tests64_cabs_SOURCES = testcases/complex/main.c
tests64_cabs_CPPFLAGS = $(CPPFLAGS64) -DTESTFUNC=cabs $(complex_inc) $(AM_CPPFLAGS)
tests64_cabs_LDFLAGS = $(LDFLAGS64) $(AM_LDFLAGS)
tests64_cabs_LDADD = $(newcomplex_test_lib64) $(LDADD)

tests64_cacos_SOURCES = testcases/complex/main.c
tests64_cacos_CPPFLAGS = $(CPPFLAGS64) -DTESTFUNC=cacos $(complex_inc) $(AM_CPPFLAGS)
tests64_cacos_LDFLAGS = $(LDFLAGS64) $(AM_LDFLAGS)
tests64_cacos_LDADD = $(newcomplex_test_lib64) $(LDADD)

tests64_cacosh_SOURCES = testcases/complex/main.c
tests64_cacosh_CPPFLAGS = $(CPPFLAGS64) -DTESTFUNC=cacosh $(complex_inc) $(AM_CPPFLAGS)
tests64_cacosh_LDFLAGS = $(LDFLAGS64) $(AM_LDFLAGS)
tests64_cacosh_LDADD = $(newcomplex_test_lib64) $(LDADD)

tests64_carg_SOURCES = testcases/complex/main.c
tests64_carg_CPPFLAGS = $(CPPFLAGS64) -DTESTFUNC=carg $(complex_inc) $(AM_CPPFLAGS)
tests64_carg_LDFLAGS = $(LDFLAGS64) $(AM_LDFLAGS)
tests64_carg_LDADD = $(newcomplex_test_lib64) $(LDADD)

tests64_casin_SOURCES = testcases/complex/main.c
tests64_casin_CPPFLAGS = $(CPPFLAGS64) -DTESTFUNC=casin $(complex_inc) $(AM_CPPFLAGS)
tests64_casin_LDFLAGS = $(LDFLAGS64) $(AM_LDFLAGS)
tests64_casin_LDADD = $(newcomplex_test_lib64) $(LDADD)

tests64_casinh_SOURCES = testcases/complex/main.c
tests64_casinh_CPPFLAGS = $(CPPFLAGS64) -DTESTFUNC=casinh $(complex_inc) $(AM_CPPFLAGS)
tests64_casinh_LDFLAGS = $(LDFLAGS64) $(AM_LDFLAGS)
tests64_casinh_LDADD = $(newcomplex_test_lib64) $(LDADD)

tests64_catan_SOURCES = testcases/complex/main.c
tests64_catan_CPPFLAGS = $(CPPFLAGS64) -DTESTFUNC=catan $(complex_inc) $(AM_CPPFLAGS)
tests64_catan_LDFLAGS = $(LDFLAGS64) $(AM_LDFLAGS)
tests64_catan_LDADD = $(newcomplex_test_lib64) $(LDADD)

tests64_catanh_SOURCES = testcases/complex/main.c
tests64_catanh_CPPFLAGS = $(CPPFLAGS64) -DTESTFUNC=catanh $(complex_inc) $(AM_CPPFLAGS)
tests64_catanh_LDFLAGS = $(LDFLAGS64) $(AM_LDFLAGS)
tests64_catanh_LDADD = $(newcomplex_test_lib64) $(LDADD)

tests64_ccos_SOURCES = testcases/complex/main.c
tests64_ccos_CPPFLAGS = $(CPPFLAGS64) -DTESTFUNC=ccos $(complex_inc) $(AM_CPPFLAGS)
tests64_ccos_LDFLAGS = $(LDFLAGS64) $(AM_LDFLAGS)
tests64_ccos_LDADD = $(newcomplex_test_lib64) $(LDADD)

tests64_ccosh_SOURCES = testcases/complex/main.c
tests64_ccosh_CPPFLAGS = $(CPPFLAGS64) -DTESTFUNC=ccosh $(complex_inc) $(AM_CPPFLAGS)
tests64_ccosh_LDFLAGS = $(LDFLAGS64) $(AM_LDFLAGS)
tests64_ccosh_LDADD = $(newcomplex_test_lib64) $(LDADD)

tests64_cexp_SOURCES = testcases/complex/main.c
tests64_cexp_CPPFLAGS = $(CPPFLAGS64) -DTESTFUNC=cexp $(complex_inc) $(AM_CPPFLAGS)
tests64_cexp_LDFLAGS = $(LDFLAGS64) $(AM_LDFLAGS)
tests64_cexp_LDADD = $(newcomplex_test_lib64) $(LDADD)

tests64_cimag_SOURCES = testcases/complex/main.c
tests64_cimag_CPPFLAGS = $(CPPFLAGS64) -DTESTFUNC=cimag $(complex_inc) $(AM_CPPFLAGS)
tests64_cimag_LDFLAGS = $(LDFLAGS64) $(AM_LDFLAGS)
tests64_cimag_LDADD = $(newcomplex_test_lib64) $(LDADD)

tests64_clog_SOURCES = testcases/complex/main.c
tests64_clog_CPPFLAGS = $(CPPFLAGS64) -DTESTFUNC=clog $(complex_inc) $(AM_CPPFLAGS)
tests64_clog_LDFLAGS = $(LDFLAGS64) $(AM_LDFLAGS)
tests64_clog_LDADD = $(newcomplex_test_lib64) $(LDADD)

tests64_conj_SOURCES = testcases/complex/main.c
tests64_conj_CPPFLAGS = $(CPPFLAGS64) -DTESTFUNC=conj $(complex_inc) $(AM_CPPFLAGS)
tests64_conj_LDFLAGS = $(LDFLAGS64) $(AM_LDFLAGS)
tests64_conj_LDADD = $(newcomplex_test_lib64) $(LDADD)

tests64_cpow_SOURCES = testcases/complex/main.c
tests64_cpow_CPPFLAGS = $(CPPFLAGS64) -DTESTFUNC=cpow $(complex_inc) $(AM_CPPFLAGS)
tests64_cpow_LDFLAGS = $(LDFLAGS64) $(AM_LDFLAGS)
tests64_cpow_LDADD = $(newcomplex_test_lib64) $(LDADD)

tests64_cproj_SOURCES = testcases/complex/main.c
tests64_cproj_CPPFLAGS = $(CPPFLAGS64) -DTESTFUNC=cproj $(complex_inc) $(AM_CPPFLAGS)
tests64_cproj_LDFLAGS = $(LDFLAGS64) $(AM_LDFLAGS)
tests64_cproj_LDADD = $(newcomplex_test_lib64) $(LDADD)

tests64_creal_SOURCES = testcases/complex/main.c
tests64_creal_CPPFLAGS = $(CPPFLAGS64) -DTESTFUNC=creal $(complex_inc) $(AM_CPPFLAGS)
tests64_creal_LDFLAGS = $(LDFLAGS64) $(AM_LDFLAGS)
tests64_creal_LDADD = $(newcomplex_test_lib64) $(LDADD)

tests64_csin_SOURCES = testcases/complex/main.c
tests64_csin_CPPFLAGS = $(CPPFLAGS64) -DTESTFUNC=csin $(complex_inc) $(AM_CPPFLAGS)
tests64_csin_LDFLAGS = $(LDFLAGS64) $(AM_LDFLAGS)
tests64_csin_LDADD = $(newcomplex_test_lib64) $(LDADD)

tests64_csinh_SOURCES = testcases/complex/main.c
tests64_csinh_CPPFLAGS = $(CPPFLAGS64) -DTESTFUNC=csinh $(complex_inc) $(AM_CPPFLAGS)
tests64_csinh_LDFLAGS = $(LDFLAGS64) $(AM_LDFLAGS)
tests64_csinh_LDADD = $(newcomplex_test_lib64) $(LDADD)

tests64_csqrt_SOURCES = testcases/complex/main.c
tests64_csqrt_CPPFLAGS = $(CPPFLAGS64) -DTESTFUNC=csqrt $(complex_inc) $(AM_CPPFLAGS)
tests64_csqrt_LDFLAGS = $(LDFLAGS64) $(AM_LDFLAGS)
tests64_csqrt_LDADD = $(newcomplex_test_lib64) $(LDADD)

tests64_ctan_SOURCES = testcases/complex/main.c
tests64_ctan_CPPFLAGS = $(CPPFLAGS64) -DTESTFUNC=ctan $(complex_inc) $(AM_CPPFLAGS)
tests64_ctan_LDFLAGS = $(LDFLAGS64) $(AM_LDFLAGS)
tests64_ctan_LDADD = $(newcomplex_test_lib64) $(LDADD)

tests64_ctanh_SOURCES = testcases/complex/main.c
tests64_ctanh_CPPFLAGS = $(CPPFLAGS64) -DTESTFUNC=ctanh $(complex_inc) $(AM_CPPFLAGS)
tests64_ctanh_LDFLAGS = $(LDFLAGS64) $(AM_LDFLAGS)
tests64_ctanh_LDADD = $(newcomplex_test_lib64) $(LDADD)

endif LIB64
