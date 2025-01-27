#include <err.h>
#include <Arduino.h>

unsigned long last_recv_time = 0;

void err_check(unsigned long time_recv) {
    if (g_recvFlag_err) {
        last_recv_time = millis();
    }
}