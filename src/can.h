#ifndef CAN_H
#define CAN_H

#include <mcp_can.h>

//===========================================================//
//========================変数宣言============================//
//===========================================================//
extern MCP_CAN CAN;
extern int pinCan;
extern int g_recvFlag;

//===========================================================//
//==================関数プロトタイプ宣言=======================//
//===========================================================//
void canInit();
void recvHandler();
bool can_recv(unsigned long* id, unsigned char* data, unsigned long* time);
void can_send(unsigned long id, unsigned char data);

#endif // CAN_H
