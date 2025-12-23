#include <stdlib.h>
#include <windows.h>

typedef void (* callback_t)(void *);

callback_t callback;
void *user_data;

__declspec(dllexport) void
lib_proc_detach_set_callback(callback_t arg_callback, void *arg_user_data) {
    callback = arg_callback;
    user_data = arg_user_data;
}

BOOL WINAPI DllMain(HINSTANCE, DWORD, LPVOID);

BOOL WINAPI DllMain(HINSTANCE hinstance, DWORD dwReason, LPVOID lpvReserved) {
    switch (dwReason) {
    case DLL_PROCESS_DETACH:
        if (callback != NULL) {
            callback(user_data);
        }
        break;
    }

    return TRUE;
}
