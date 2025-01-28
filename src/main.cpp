#include <Arduino.h>
#include <lcd.h>
#include <can.h>
#include <timer.h>
#include <err.h>
#include <light.h>
#include <serial.h>


//===========================================================//
//========================変数宣言============================//
//===========================================================//
unsigned long id_recv;    // 受信ID
unsigned long id_send = 0x104;  // 送信ID
unsigned char data_recv;  // 受信データ
unsigned char data_send = 1;  // 送信データ
unsigned long time_recv;  // 受信時刻


//===========================================================//
//=====================セットアップ===========================//
//===========================================================//
void setup() {
  // シリアル通信初期化
  serialInit();

  // CAN初期化
  canInit();

  // LCD初期化
  lcd_init();

  // タイマ初期化
  timerInit();
}


//===========================================================//
//======================MAIN LOOP============================//
//===========================================================//
void loop() {
  // int serialData = serialRead();
  // if (serialData != -1) {
  //   data_send = (unsigned char)serialData;
  // }

  // CAN送信
  // if (g_send_flag) {
  //   can_send(0x104, data_send);
  // }

  // CAN受信
  can_recv(&id_recv, &data_recv, &time_recv, 0);

  // LCD更新 - タイマーフラグに基づいて更新
  updateLCD(data_recv);

  // エラーチェック
  // err_check(time_recv, &data_recv);
}
