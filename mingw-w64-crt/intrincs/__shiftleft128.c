#include <_mingw.h>

#ifdef _WIN64

unsigned __int64 __shiftleft128 (unsigned __int64  LowPart,
 unsigned __int64 HighPart, unsigned char Shift);

unsigned __int64 __shiftleft128 (unsigned __int64  LowPart,
 unsigned __int64 HighPart, unsigned char Shift)
{
  if (Shift >= 128)
    return 0ULL;
  if (!Shift)
    return HighPart;
  if (Shift >= 64)
    {
      HighPart = LowPart;
      Shift -= 64;
      LowPart = 0;
    }
  HighPart <<= Shift;
  LowPart >>= (64 - Shift);
  return (HighPart | LowPart);
}

#endif

