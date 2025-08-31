/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define _DEBUG /* needed for _invalid_parameter */
#include <corecrt.h>
#undef _DEBUG
#include <stdlib.h>

void __cdecl _invalid_parameter(const wchar_t *expression, const wchar_t *function_name, const wchar_t *file_name, unsigned int line_number, uintptr_t reserved)
{
    _invalid_parameter_handler handler;

    /* TODO: Enable this code when mingw-w64 has _get_thread_local_invalid_parameter_handler() support */
#if 0
    handler = _get_thread_local_invalid_parameter_handler();
    if (handler) {
        handler(expression, function_name, file_name, line_number, reserved);
        return;
    }
#endif

    handler = _get_invalid_parameter_handler();
    if (handler) {
        handler(expression, function_name, file_name, line_number, reserved);
        return;
    }

    _invoke_watson(expression, function_name, file_name, line_number, reserved);
}
void (__cdecl *__MINGW_IMP_SYMBOL(_invalid_parameter))(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, uintptr_t) = _invalid_parameter;
