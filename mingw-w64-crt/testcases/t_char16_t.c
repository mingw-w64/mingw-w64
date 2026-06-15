#define COMPILETIME_CHECK

#if !defined(COMPILETIME_CHECK)
#include <stdlib.h>
#endif
#include <uchar.h>

int main (void)
{
/* wchar_t should compatible to char16_t on Windows */
#if defined(COMPILETIME_CHECK)
typedef int dummy[2 * (sizeof(wchar_t) == sizeof(char16_t)) - 1];
#else /*if defined(RUNTIME_CHECK)*/
	if (sizeof(wchar_t) != sizeof(char16_t))
		abort ();
#endif
	return 0;
}
