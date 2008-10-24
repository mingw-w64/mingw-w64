unsigned short __cdecl _byteswap_ushort(unsigned short _Short);

unsigned short __cdecl _byteswap_ushort(unsigned short _Short)
{
  unsigned short retval;
  __asm__("rorw $8, %w[retval]" : [retval] "=rm" (retval) : "[retval]" (_Short));
  return retval;
}
