long double
atanl (long double x)
{
  long double res;

  asm ("fld1\n\t"
       "fpatan"
       : "=t" (res) : "0" (x));
  return res;
}
