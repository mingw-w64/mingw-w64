#include <stdio.h>
#include <limits.h>

unsigned long long a = ULLONG_MAX;

int
main()
{
  __mingw_printf ("MINGW : %llu\n", a);
  printf ("MSVCRT: %llu\n", a);
  return 0;
}
