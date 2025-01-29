#include <err.h>
#include <Arduino.h>
#include <can.h>


//===========================================================//
//========================関数定義============================//
//===========================================================//
void err_check(unsigned long time_recv, unsigned char* data_recv) {
    if (!g_err_check_flag) {
        return;
    }
    g_err_check_flag = false;

    bool status_err_check = false;  // エラーチェックステータス

    // 2000ms以上受信がない場合、受信データを4に設定 、CAN初期化、Cエラーコード送信
    if (millis() - time_recv > 2000) {
        Serial.print("Last Recv Time : ");
        Serial.println(millis() - time_recv);

        *data_recv = 4;

        canInit();
        can_send(0x111, 2);
    }

    // エラーステータスが2の場合、受信があればエラーステータスを0に設定
    // if (*data_recv == 2) {
    //     if (millis() - time_recv <= 2000) {
    //         *data_recv = 0;
    //     }
    // }

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