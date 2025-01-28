#ifndef CAN_H
#define CAN_H

#include <mcp_can.h>

//===========================================================//
//========================変数宣言============================//
//===========================================================//
extern MCP_CAN CAN;
extern int pinCan;
extern bool g_recvFlag;     // 受信フラグ
extern bool g_send_flag;    // 送信フラグ
extern uint8_t g_err_status;    // エラーステータス
extern unsigned long id_recv;    // 受信ID
extern unsigned long id_send;    // 送信ID
extern unsigned char data_recv;  // 受信データ
extern unsigned long time_recv;  // 受信時刻

//===========================================================//
//==================関数プロトタイプ宣言=======================//
//===========================================================//
void canInit();
void recvHandler();
bool can_recv(unsigned long* id, unsigned char* data, unsigned long* time, uint8_t position);
void can_send(unsigned long id, unsigned char data);

#endif // CAN_H
