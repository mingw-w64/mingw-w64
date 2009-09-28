#include <math.h>
#include <stdio.h>
#include <inttypes.h>

volatile long double in1 = -1.0L / 0.0L;
volatile long double in2 = 1.0L / 0.0L;

volatile long double ld1 = 3.51L;
volatile double ld2 = 3.51;
volatile float ld3 = 3.51F;

#define ARG1_FCT(NAME) \
  do {printf (#NAME ": %g %g %g\n", (double) NAME##l (ld1), \
    (double) NAME (ld2), \
    (double) NAME##f (ld3)); \
} while (0)

#define ARG2_FCT(NAME,VAL) \
  do {printf (#NAME ": %g %g %g\n", (double) NAME##l (ld1, VAL##L), \
    (double) NAME (ld2, VAL), \
    (double) NAME##f (ld3, VAL##f)); \
} while (0)

#define ARG3_FCT(NAME,VAL,VAL2) \
  do {printf (#NAME ": %g %g %g\n", (double) NAME##l (ld1, VAL##L, VAL2##L), \
    (double) NAME (ld2, VAL, VAL2), \
    (double) NAME##f (ld3, VAL##f, VAL2##f)); \
} while (0)

#define ARG2_FCTINT(NAME) \
  do {printf (#NAME ": %g %g %g\n", (double) NAME##l (ld1, 2), \
    (double) NAME (ld2, 2), \
    (double) NAME##f (ld3, 2)); \
} while (0)

#define ARG2_FCTPINT(NAME) \
  do { \
   int i = 0; \
   printf (#NAME ": %g", (double) NAME##l (ld1, &i)); \
   printf ("=%d", i); \
   printf (" %g", (double) NAME (ld2, &i)); \
   printf ("=%d", i); \
   printf (" %g", (double) NAME##f (ld3, &i)); \
   printf ("=%d\n", i); \
  } while(0)
  
#ifdef __WIN64__
#define printfmt PRIu64
#else
#define printfmt PRIu32
#endif

int main()
{
  printf ("sizeof(float)=%"printfmt", sizeof(double)=%"printfmt", sizeof(long double)=%"printfmt"\n", sizeof (float), sizeof(double), sizeof(long double));
  printf ("%g %g %g\n", (double) ld1, (double) ld2, (double) ld3);

  ARG1_FCT (sin);
  ARG1_FCT (cos);
  ARG1_FCT (tan);
  ARG1_FCT (sinh);
  ARG1_FCT (cosh);
  ARG1_FCT (tanh);
  ARG1_FCT (asin);
  ARG1_FCT (acos);
  ARG1_FCT (atan);
  ARG2_FCT (atan2, 0.5);
  ARG1_FCT (exp);
  ARG1_FCT (exp2);
  ARG2_FCT (pow, 2.0);
  ARG1_FCT (sqrt);
  ARG1_FCT (ceil);
  ARG1_FCT (floor);
  ARG1_FCT (fabs);
  // double __cdecl ldexp(double _X,int _Y);
  // double __cdecl frexp(double _X,int *_Y);
  // double __cdecl modf(double _X,double *_Y);
  ARG2_FCT(fmod, 2.5);
  ARG1_FCT (log1p);
  ARG1_FCT (log2);
  ARG1_FCT (logb);
  ARG1_FCT (tgamma);
  ARG1_FCT (lgamma);
  ARG1_FCT (erf);
  ARG1_FCT (erfc);
  ARG1_FCT (nearbyint);
  ARG1_FCT (rint);
  ARG1_FCT (lrint);
  ARG1_FCT (llrint);
  ARG1_FCT (lround);
  ARG1_FCT (llround);

  ARG1_FCT (log);
  ARG1_FCT (log10);
  ARG1_FCT (round);
  ARG1_FCT (trunc);
  ARG2_FCT (remainder, 2.0);
  ARG2_FCT (copysign, -1.0);
  ARG2_FCT (nexttoward, 0.5);
  ARG2_FCT (nexttoward, 0.5);
  ARG2_FCT (fdim, 0.5);
  ARG2_FCT (fmax, 0.5);
  ARG2_FCT (fmin, 0.5);
  ARG2_FCT (hypot, 1.5);
  ARG1_FCT (cbrt);
  ARG2_FCTPINT (frexp);
  ARG2_FCTINT (ldexp);
  ARG1_FCT (ilogb);
  ARG2_FCTINT (scalbn);
  ARG2_FCTINT (scalbln);
  ARG3_FCT (fma, 2.0, 1.5);
  printf ("%g is%s nan\n", (double) in1, isnan (in1) ? "" :" not");
  printf ("%g is%s inf\n", (double) in1, isinf (in1) ? "" :" not");
  __mingw_printf ("Ld:%Lg d:%g f:%g\n", ld1, ld2, (double) ld3);

  return 0;
}
