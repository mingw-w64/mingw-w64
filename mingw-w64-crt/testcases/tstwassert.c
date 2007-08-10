#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char **argv)
{
  printf ("Is argc (%d) < 3 ?\n", argc);
  assert (argc < 3);
  printf ("No assert !\n");
  return 0;
}
