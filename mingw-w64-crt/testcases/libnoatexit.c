/* This is simple DLL library which does not use atexit callback */

/* Tentative symbol __mingw_dll_atexit_table_func_ptr is mingw-w64 internal
 * symbol only for DLL libraries. It is non-NULL if the DLL library is using atexit.
 */
int (__cdecl *const __mingw_dll_atexit_table_func_ptr)(int) __attribute__((common)); /* tentative */

__attribute__((dllexport))
int is_atexit_included(void) { return !!__mingw_dll_atexit_table_func_ptr; }
