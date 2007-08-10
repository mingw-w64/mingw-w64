#include <ctype.h>
#undef iscsym
int
iscsym (int c)
{
	return __iscsym(c);
}
