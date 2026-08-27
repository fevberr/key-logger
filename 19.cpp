#include "01.h"
#include "19.h"
int 19() {
    mtx.lock();
    int s = queue.size();
    mtx.unlock();
    return s;
}
