#include <stdio.h>

int main(int argc, char **argv)
{
  printf ("%I32d\n", argc);
  printf ("%I32d\n", (long) argc);
  printf ("%I64d\n", (long long) argc);
  return 0;
}

