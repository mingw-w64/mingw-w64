/* This is simple DLL library which does not use thread local storage */
__attribute__((dllexport))
int function(void) { return 42; }
