#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
 int check_UINT8_C =
      (-1 < UINT8_C (0)) == (-1 < (uint_least8_t) 0) ? 1 : -1;
int check_UINT16_C =
      (-1 < UINT16_C (0)) == (-1 < (uint_least16_t) 0) ? 1 : -1;
  if (check_UINT8_C == -1 || check_UINT16_C == -1)
   abort ();
  return 0;
}

