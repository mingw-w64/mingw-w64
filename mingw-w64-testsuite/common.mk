CC = i686-pc-mingw32-gcc
X_OBJS = t_float t_matherr t_setjmp tstmain tstwassert
TEST_ROOT = ../mingw-w64-crt/testcases
C_OBJS = $(TEST_ROOT)/t_float.c $(TEST_ROOT)/t_matherr.c $(TEST_ROOT)/t_setjmp.c $(TEST_ROOT)/tstmain.c $(TEST_ROOT)/tstwassert.c
