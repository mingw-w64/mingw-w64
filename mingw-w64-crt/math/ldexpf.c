extern double __cdecl ldexp(double _X,int _Y);
float ldexpf (float x, int expn)
  {return (float) ldexp (x, expn);}
