
#include <windows.h>

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, VOID* reserved)
{
    return TRUE;
}

LONG __declspec(dllexport) Blue(void)
{
    const HWND window = GetForegroundWindow();
    SetClassLongPtrA(window,
                     GCL_HBRBACKGROUND,
                     (LONG) CreateSolidBrush(RGB(0, 0, 64)));
    RedrawWindow(window, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
    return 1;
}

