#include <stdlib.h>
#include <uchar.h>

int main (void)
{
	/* wchar_t should be compatible with char16_t on Windows */
	if (sizeof(wchar_t) != sizeof(char16_t))
		abort ();

	return 0;
}
