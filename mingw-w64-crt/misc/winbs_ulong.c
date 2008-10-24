unsigned long __cdecl _byteswap_ulong (unsigned long _Long);

unsigned long __cdecl _byteswap_ulong (unsigned long _Long)
{
  unsigned long retval;
  __asm__("bswapl %[retval]" : [retval] "=rm" (retval) : "[retval]" (_Long));
  return retval;
}
