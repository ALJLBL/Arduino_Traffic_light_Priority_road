#include <can.h>

// CAN初期化
void canInit() {
    // 初期化
    if (CAN.begin(MCP_ANY, CAN_250KBPS, MCP_8MHZ) == CAN_OK) {
        Serial.println("CAN init OK");
    } else {
        Serial.println("CAN init Error");
    }

    // CAN Mode設定
    CAN.setMode(MCP_NORMAL);

    // CAn受信フィルタとマスク
    CAN.init_Mask(0, 0, 0x7FF);       // マスク0を設定
    CAN.init_Filt(0, 0, 0x100);       // フィルタ0を設定（ID: 0x100のみ受信）
    CAN.init_Filt(1, 0, 0x100);       // フィルタ1を設定（ID: 0x100のみ受信）
}

// CAN受信割り込みハンドラ
void recvHandler() {
  g_recvFlag = 1;
}

// 受信したデータを保存
void can_recv(unsigned long* id, unsigned char* data, unsigned long* time) {
    if(g_recvFlag) {
        g_recvFlag = 0;
        unsigned char data_recv[8];
        unsigned char len = 0;
        if (CAN.readMsgBuf(id, &len, data_recv) == CAN_OK) {
            // 受信データを保存(優先道路信号の場合、data[1]を保存)
            *data = data_recv[1];
            // 受信時刻を保存
            *time = millis();
        }
    }
}

