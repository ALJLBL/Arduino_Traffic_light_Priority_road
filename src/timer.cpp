#include <timer.h>

void timerInit() {
    MsTimer2::set(500, timerHandler);
    MsTimer2::start();
}

void timerHandler() {
    g_timer_flag = 1;
}