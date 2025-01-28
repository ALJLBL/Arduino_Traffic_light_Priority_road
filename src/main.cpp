#include <Arduino.h>
#include <lcd.h>
#include <can.h>
#include <timer.h>
#include <err.h>


//===========================================================//
//========================変数宣言============================//
//===========================================================//
unsigned long id_recv;    // 受信ID
unsigned char data_recv;  // 受信データ
unsigned char data_send;  // 送信データ
unsigned long time_recv;  // 受信時刻


//===========================================================//
//=====================セットアップ===========================//
//===========================================================//
void setup() {
  // シリアル通信初期化
  Serial.begin(9600);

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
  // CAN送信
  can_send(0x100, g_err_status);

  // CAN受信
  can_recv(&id_recv, &data_recv, &time_recv, 0);

  

  // LCD更新 - タイマーフラグに基づいて更新
  if (g_lcd_flag) {
    g_lcd_flag = false;
    updateLCD(data_recv);
  }

  // エラーチェック
  err_check(time_recv, &data_recv);
}
