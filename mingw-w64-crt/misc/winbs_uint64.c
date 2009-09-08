unsigned long long __cdecl _byteswap_uint64(unsigned long long _Int64);

unsigned long long __cdecl _byteswap_uint64(unsigned long long _Int64)
{
#ifdef _WIN64
  unsigned long long retval;
  __asm__ __volatile__ ("bswapq %[retval]" : [retval] "=rm" (retval) : "[retval]" (_Int64));
  return retval;
#else
  union {
    long long int64part;
    struct {
      unsigned long lowpart;
      unsigned long hipart;
    };
  } retval;
  retval.int64part = _Int64;
  __asm__ __volatile__ ("bswapl %[lowpart]\n"
    "bswapl %[hipart]\n"
    : [lowpart] "=rm" (retval.hipart), [hipart] "=rm" (retval.lowpart)  : "[lowpart]" (retval.lowpart), "[hipart]" (retval.hipart));
  return retval.int64part;
#endif
}
