extern double __cdecl frexp(double _X,int *_Y);

float frexpf (float x, int* expn)
  {return (float)frexp(x, expn);}
