#ifndef ERR_H
#define ERR_H
#include <Arduino.h>

//===========================================================//
//========================変数宣言============================//
//===========================================================//
extern uint8_t g_err_status;    // エラーステータス
extern bool g_err_check_flag;    // エラーチェックフラグ

//===========================================================//
//==================関数プロトタイプ宣言=======================//
//===========================================================//
void err_check(unsigned long time_recv, unsigned char* data_recv);

#endif // ERR_H