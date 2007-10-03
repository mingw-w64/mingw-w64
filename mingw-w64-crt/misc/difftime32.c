double _difftime32(unsigned int _Time1,unsigned int _Time2)
{
  unsigned int r = _Time2 - _Time1;
  if (r > _Time2)
    return -((double) (_Time1 - _Time2));
  return (double) r;
}
