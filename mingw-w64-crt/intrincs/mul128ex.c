#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
#include <windows.h>

/* for __x86_64 only */

LONG64 MultiplyExtract128(LONG64 Multiplier,LONG64 Multiplicand,BYTE Shift) {
      LONG64 extractedProduct;
      LONG64 highProduct;
      LONG64 lowProduct;
      lowProduct = Multiply128(Multiplier,Multiplicand,&highProduct);
      extractedProduct = (LONG64)ShiftRight128((LONG64)lowProduct,(LONG64)highProduct,Shift);
      return extractedProduct;
}

