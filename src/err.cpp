#include <err.h>
#include <Arduino.h>
#include <can.h>

void err_check(unsigned long time_recv, unsigned char* data_recv) {
    if (!g_err_check_flag) {
        return;
    }
    g_err_check_flag = false;

    bool status_err_check = false;  // エラーチェックステータス

    // 2000ms以上受信がない場合、エラーステータスを2に設定
    if (millis() - time_recv > 2000) {
        g_err_status = 2;
        can_send(0x111, 2);
    }

    // エラーステータスが2の場合、受信があればエラーステータスを0に設定
    if (g_err_status == 2) {
        if (millis() - time_recv <= 2000) {
            g_err_status = 0;
        }
    }

    // 受信データが0,1,2,3以外の場合、受信データを3に設定
    status_err_check = (*data_recv != 0 && *data_recv != 1 && *data_recv != 2 && *data_recv != 3 && *data_recv != 4);
    // if (*data_recv == 4) {
    //     canInit();
    // }
    if (status_err_check) {
        *data_recv = 3;
        can_send(0x111, 1);
    }
    
}