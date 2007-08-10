long double
atan2l (long double y, long double x)
{
  long double res;
  asm ("fpatan" : "=t" (res) : "u" (y), "0" (x) : "st(1)");
  return res;
}
