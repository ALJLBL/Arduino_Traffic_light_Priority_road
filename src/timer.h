#ifndef TIMER_H
#define TIMER_H

#include <MsTimer2.h>

//===========================================================//
//========================変数宣言============================//
//===========================================================//

extern bool g_timer_flag;    // タイマフラグ
extern bool g_flash_flag;    // フラッシュフラグ
extern bool g_send_flag;    // 送信フラグ
extern bool g_lcd_flag;    // LCDフラグ
extern bool g_err_check_flag;    // エラーチェックフラグ

//===========================================================//
//==================関数プロトタイプ宣言=======================//
//===========================================================//
void timerInit();
void timerHandler();

#endif
