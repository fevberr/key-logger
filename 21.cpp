#include "01.h"
#include "21.h"
#include "23.h"
std::wstring 21() {
    mtx.lock();
    std::wstring r;
    while (!queue.empty()) {
        r += queue.front();
        queue.pop();
    }
    mtx.unlock();
    if (r.empty()) return L"";
    return 23(r);
}
