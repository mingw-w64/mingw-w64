#include <assert.h>
#include <stdlib.h>

void (__cdecl *exit_ptr)(int) = exit;

int main()
{
  assert (exit_ptr != NULL);
  exit_ptr (EXIT_SUCCESS);
  _exit (EXIT_FAILURE);
}
