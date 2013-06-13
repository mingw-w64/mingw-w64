#include <windows.h>
#include <stdlib.h>

static _invalid_parameter_handler handler;

_invalid_parameter_handler __cdecl __MINGW_IMP_SYMBOL(_set_invalid_parameter_handler)(_invalid_parameter_handler new_handler)
{
    return InterlockedExchangePointer(&handler, new_handler);
}

_invalid_parameter_handler __cdecl __MINGW_IMP_SYMBOL(_get_invalid_parameter_handler)(void)
{
    return handler;
}
