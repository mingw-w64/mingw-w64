

CC = cl.exe
LD = $(CC)

SRCDIR = ..

OBJS =
!if "$(MACHINE)" == "x64"
OBJS = $(SRCDIR)\vcdiv64.obj
!endif


default: runtest cov fntcov test_transpose
extended: default karatsuba_fnt karatsuba_fnt2 ppro_mulmod
extended_gmp: extended mpd_mpz_add mpd_mpz_divmod mpd_mpz_mul mpd_mpz_sub
extended_deccheck: extended_gmp deccheck


# dectest
runtest:\
Makefile runtest.c $(SRCDIR)\io.h     $(SRCDIR)\mpdecimal.h $(SRCDIR)\memory.h \
                   $(SRCDIR)\mptest.h $(SRCDIR)\mptypes.h   $(SRCDIR)\$(USELIB) \
                   malloc_fail.c malloc_fail.h
	$(CC) -I$(SRCDIR) $(UFLAGS) $(CFLAGS) runtest.c malloc_fail.c $(SRCDIR)\$(USELIB)

# coverage
cov:\
cov.c $(SRCDIR)\mpdecimal.h $(SRCDIR)\mptypes.h $(SRCDIR)\$(USELIB) \
      malloc_fail.c malloc_fail.h
	$(CC) -I$(SRCDIR) $(UFLAGS) $(CFLAGS) cov.c malloc_fail.c $(SRCDIR)\$(USELIB)

fntcov:\
fntcov.c $(SRCDIR)\mpdecimal.h $(SRCDIR)\mptypes.h $(SRCDIR)\$(USELIB) \
         malloc_fail.c malloc_fail.h
	$(CC) -I$(SRCDIR) $(UFLAGS) $(CFLAGS) fntcov.c malloc_fail.c $(SRCDIR)\$(USELIB)

# extended tests
karatsuba_fnt:\
Makefile karatsuba_fnt.c $(SRCDIR)\mpdecimal.h  $(SRCDIR)\mptypes.h \
                         $(SRCDIR)\mptest.h     $(SRCDIR)\$(USELIB)
	$(CC) -I$(SRCDIR) $(UFLAGS) $(CFLAGS) karatsuba_fnt.c $(SRCDIR)\$(USELIB)
karatsuba_fnt2:\
Makefile karatsuba_fnt2.c $(SRCDIR)\mpdecimal.h  $(SRCDIR)\mptypes.h \
                          $(SRCDIR)\mptest.h     $(SRCDIR)\$(USELIB)
	$(CC) -I$(SRCDIR) $(UFLAGS) $(CFLAGS) karatsuba_fnt2.c $(SRCDIR)\$(USELIB)
ppro_mulmod:\
Makefile ppro_mulmod.c $(SRCDIR)\mpdecimal.h    $(SRCDIR)\constants.h \
                       $(SRCDIR)\numbertheory.h $(SRCDIR)\mptypes.h \
                       $(SRCDIR)\mptest.h       $(SRCDIR)\umodarith.h \
                       $(SRCDIR)\typearith.h    $(SRCDIR)\$(USELIB)
	$(CC) -I$(SRCDIR) $(UFLAGS) $(CFLAGS) ppro_mulmod.c $(SRCDIR)\$(USELIB)
test_transpose:\
Makefile test_transpose.c $(SRCDIR)\bits.h      $(SRCDIR)\mpdecimal.h \
                          $(SRCDIR)\constants.h $(SRCDIR)\mptypes.h \
                          $(SRCDIR)\mptest.h    $(SRCDIR)\typearith.h \
                          $(SRCDIR)\transpose.h $(SRCDIR)\$(USELIB)
	$(CC) -I$(SRCDIR) $(UFLAGS) -wd4273 $(CFLAGS) test_transpose.c $(SRCDIR)\constants.c $(OBJS) $(SRCDIR)\$(USELIB)

# gmp tests
mpd_mpz_add:\
Makefile mpd_mpz_add.c $(SRCDIR)\mpdecimal.h $(SRCDIR)\mptypes.h $(SRCDIR)\$(USELIB)
	$(CC) -I$(SRCDIR) -I"$(GMPINC)" $(UFLAGS) $(CFLAGS) mpd_mpz_add.c $(SRCDIR)\$(USELIB) "$(GMPLIB)"
mpd_mpz_divmod:\
Makefile mpd_mpz_divmod.c $(SRCDIR)\mpdecimal.h $(SRCDIR)\mptypes.h $(SRCDIR)\$(USELIB)
	$(CC) -I$(SRCDIR) -I"$(GMPINC)" $(UFLAGS) $(CFLAGS) mpd_mpz_divmod.c $(SRCDIR)\$(USELIB) "$(GMPLIB)"
mpd_mpz_mul:\
Makefile mpd_mpz_mul.c $(SRCDIR)\mpdecimal.h $(SRCDIR)\mptypes.h $(SRCDIR)\$(USELIB)
	$(CC) -I$(SRCDIR) -I"$(GMPINC)" $(UFLAGS) $(CFLAGS) mpd_mpz_divmod.c $(SRCDIR)\$(USELIB) "$(GMPLIB)"
mpd_mpz_sub:\
Makefile mpd_mpz_sub.c $(SRCDIR)\mpdecimal.h $(SRCDIR)\mptypes.h $(SRCDIR)\$(USELIB)
	$(CC) -I$(SRCDIR) -I"$(GMPINC)" $(UFLAGS) $(CFLAGS) mpd_mpz_sub.c $(SRCDIR)\$(USELIB) "$(GMPLIB)"

# tests against decNumber
deccheck:\
Makefile deccheck.c $(SRCDIR)\io.h  $(SRCDIR)\mpdecimal.h $(SRCDIR)\memory.h \
                    $(SRCDIR)\mptest.h $(SRCDIR)\mptypes.h $(SRCDIR)\$(USELIB)
	copy ..\vcstdint.h ..\stdint.h
	$(CC) -I$(SRCDIR) /IdecNumber /wd4244 $(UFLAGS) $(CFLAGS) deccheck.c \
	decNumber\decNumber.c decNumber\decContext.c $(SRCDIR)\$(USELIB)


FORCE:

clean: FORCE
	-@if exist *.obj del *.obj
	-@if exist *.dll del *.dll
	-@if exist *.exp del *.exp
	-@if exist *.lib del *.lib
	-@if exist *.ilk del *.ilk
	-@if exist *.pdb del *.pdb
	-@if exist *.pgc del *.pgc
	-@if exist *.pgd del *.pgd
	-@if exist *.manifest del *.manifest
	-@if exist *.exe del *.exe

distclean: FORCE
	nmake clean
	-@if exist testdata rd /q /s testdata
	-@if exist decNumber rd /q /s decNumber
	-@if exist *.zip del /q *.zip
	-@if exist ..\stdint.h del ..\stdint.h
	-@if exist Makefile del Makefile



