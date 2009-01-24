double _difftime64(unsigned long long _Time1,unsigned long long _Time2)
{
  unsigned long long r = _Time1 - _Time2;
  if (r > _Time1)
    return -((double) (_Time2 - _Time1));
  return (double) r;
}
