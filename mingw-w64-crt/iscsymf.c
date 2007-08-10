#include <ctype.h>
#undef iscsymf

int
iscsymf (int c)
{
	return __iscsymf(c);
}
