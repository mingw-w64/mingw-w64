#include <stdio.h>

extern unsigned int __ImageBase;

int main()
{
  printf ("%x\n", __ImageBase);
  return 0;
}

