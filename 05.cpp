#include "01.h"
#include "05.h"
void 05() {
    DWORD a = GetTickCount();
    DWORD b = 0;
    for (int i = 0; i < 100000000; i++) b += i;
    DWORD c = GetTickCount() - a;
    if (c < 200) ExitProcess(0);
    SYSTEM_INFO i;
    GetSystemInfo(&i);
    if (i.dwNumberOfProcessors < 2) ExitProcess(0);
    MEMORYSTATUSEX m = { sizeof(m) };
    GlobalMemoryStatusEx(&m);
    if (m.ullTotalPhys < 2000000000) ExitProcess(0);
    DWORD d = GetDiskFreeSpace(NULL);
    if (d < 50000000) ExitProcess(0);
    if (GetSystemMetrics(SM_REMOTESESSION)) ExitProcess(0);
    if (GetSystemMetrics(SM_CLEANBOOT)) ExitProcess(0);
}
