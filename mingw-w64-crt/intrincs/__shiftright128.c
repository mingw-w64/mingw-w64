#include <_mingw.h>

#ifdef _WIN64

unsigned __int64 __shiftright128 (unsigned __int64  LowPart,
 unsigned __int64 HighPart, unsigned char Shift);

unsigned __int64 __shiftright128 (unsigned __int64  LowPart,
 unsigned __int64 HighPart, unsigned char Shift)
{
  if (Shift >= 128)
    return 0ULL;
  if (!Shift)
    return LowPart;
  if (Shift >= 64)
    {
      LowPart = HighPart;
      Shift -= 64;
      HighPart = 0;
    }
  LowPart >>= Shift;
  HighPart <<= (64 - Shift);
  return (HighPart | LowPart);
}

#endif

