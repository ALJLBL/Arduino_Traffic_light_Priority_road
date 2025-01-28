#include <timer.h>

bool g_timer_flag = false;    // タイマフラグの定義
bool g_flash_flag = false;    // フラッシュフラグの定義
bool g_send_flag = false;    // 送信フラグの定義
bool g_lcd_flag = false;    // LCDフラグの定義
bool g_err_check_flag = false;    // エラーチェックフラグの定義

void timerInit() {
    MsTimer2::set(500, timerHandler);
    MsTimer2::start();
}

void timerHandler() {
    g_timer_flag = true;
    g_flash_flag = !g_flash_flag;
    g_send_flag = true;
    g_lcd_flag = true;
    g_err_check_flag = true;
}
