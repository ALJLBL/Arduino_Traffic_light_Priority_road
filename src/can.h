#include <mcp_can.h>

MCP_CAN CAN(10);

//===========================================================//
//========================変数宣言============================//
//===========================================================//
int pinCan = 2;
extern int g_recvFlag;

//===========================================================//
//==================関数プロトタイプ宣言=======================//
//===========================================================//
void canInit();
void recvHandler();
void can_recv();