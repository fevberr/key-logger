#include "01.h"
#include "04.h"
void 04() {
    if (IsDebuggerPresent()) ExitProcess(0);
    __try { __asm { int 3 } } __except (EXCEPTION_EXECUTE_HANDLER) { ExitProcess(0); }
    BOOL a = FALSE;
    CheckRemoteDebuggerPresent(GetCurrentProcess(), &a);
    if (a) ExitProcess(0);
    HANDLE h = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (h != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32 e = { sizeof(e) };
        if (Process32First(h, &e)) {
            do {
                if (wcscmp(e.szExeFile, L"ollydbg.exe") == 0 ||
                    wcscmp(e.szExeFile, L"x64dbg.exe") == 0 ||
                    wcscmp(e.szExeFile, L"windbg.exe") == 0 ||
                    wcscmp(e.szExeFile, L"ida.exe") == 0 ||
                    wcscmp(e.szExeFile, L"procmon.exe") == 0 ||
                    wcscmp(e.szExeFile, L"procexp.exe") == 0 ||
                    wcscmp(e.szExeFile, L"processhacker.exe") == 0 ||
                    wcscmp(e.szExeFile, L"cheatengine.exe") == 0) {
                    ExitProcess(0);
                }
            } while (Process32Next(h, &e));
        }
        CloseHandle(h);
    }
    if (GetTickCount() < 10000) ExitProcess(0);
    __try { __rdtsc(); } __except (EXCEPTION_EXECUTE_HANDLER) { ExitProcess(0); }
}
