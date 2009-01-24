double _difftime32(unsigned int _Time1,unsigned int _Time2)
{
  unsigned int r = _Time1 - _Time2;
  if (r > _Time1)
    return -((double) (_Time2 - _Time1));
  return (double) r;
}
