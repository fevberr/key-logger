#include "01.h"
#include "15.h"
void 15() {
    HANDLE h = CreateFile(L"\\\\.\\syscache32", GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
    if (h != INVALID_HANDLE_VALUE) {
        DWORD b;
        DeviceIoControl(h, 0x80002000, NULL, 0, NULL, 0, &b, NULL);
        CloseHandle(h);
    }
}
