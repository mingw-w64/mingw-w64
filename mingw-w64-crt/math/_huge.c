/* For UCRT, positive infinity */
#include <_mingw.h>
#undef _HUGE
static double _HUGE = __builtin_huge_val();
double * __MINGW_IMP_SYMBOL(_HUGE) = &_HUGE;
