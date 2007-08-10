#include <math.h>
#include <complex.h>

/* cacos ( Z ) =  pi/2 - casin ( Z ) */

double complex cacos (double complex Z)
{
  double complex Res  = casin (Z);
  __real__ Res = M_PI_2 - __real__ Res;
  __imag__ Res = - __imag__ Res;
  return Res;
}
