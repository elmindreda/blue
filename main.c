
#include <windows.h>

static BOOL CALLBACK thread_window_callback(HWND window, LPARAM lParam)
{
    SetClassLongPtrA(window,
                     GCL_HBRBACKGROUND,
                     (LONG) CreateSolidBrush(RGB(0, 0, 64)));
    RedrawWindow(window, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
}

LONG __declspec(dllexport) blue(void)
{
    EnumThreadWindows(GetCurrentThreadId(), thread_window_callback, 0);
    return 1;
}

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, VOID* reserved)
{
    return TRUE;
}

