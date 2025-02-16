#include <can.h>


//===========================================================//
//========================変数宣言============================//
//===========================================================//
MCP_CAN CAN(10);
int pinCan = 2;
int pinLight = A0;
bool g_recvFlag = 0;
bool g_recvFlag_err = 0;
uint8_t g_err_status = 0;


//===========================================================//
//========================関数定義============================//
//===========================================================//
// CAN初期化
void canInit() {
    // CAN割り込み
    attachInterrupt(digitalPinToInterrupt(pinCan), recvHandler, FALLING);

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
  can_recv(&id_recv, &data_recv, &time_recv, 1);
}

// 受信したデータを保存
bool can_recv(unsigned long* id, unsigned char* data, unsigned long* time, uint8_t position) {
    bool err_flag = false;  // エラーフラグ
    // 受信フラグが立っている場合、CAN受信
    //if(digitalRead(pinCan) == LOW || g_recvFlag) {
        g_recvFlag = 0;

        unsigned char data_recv[8]; // 8個のunsigned char型の要素を持つ配列を定義
        unsigned char len = 0;      // 受信データの長さを格納

        // 受信データがある場合、CAN受信
        while(CAN.checkReceive() == CAN_MSGAVAIL) {
            if ((CAN.readMsgBuf(id, &len, data_recv) == CAN_OK)) {
                if (*id == 0x100) {
                    // 受信データを保存
                    *data = data_recv[position];
                    // 受信確認フレームを送信
                    if (data_recv[3] == 1) {
                        delay(100);
                        can_send(0x104, 0);
                    }
                    // 受信時刻を保存
                    *time = millis();
                    // 受信データをシリアルモニタに表示
                    Serial.print("Recv from 0x");
                    Serial.print(*id, HEX);
                    Serial.print(" : ");
                    Serial.println(*data);
                    err_flag = 0;
                }
            } else {
                Serial.println("CAN recv Error !!!");
                err_flag = 1;
                break;
            }
        }
    //}
    return err_flag;
}

// CAN送信
void can_send(unsigned long id, unsigned char data) {
    // 送信するdataのサイズを確認
    uint8_t len = sizeof(data);
    // 送信フラグが立っている場合、CAN送信
    if(CAN.sendMsgBuf(id, len, &data) == CAN_OK) {
        Serial.print("Send to 0x");
        Serial.print(id, HEX);
        Serial.print(" : ");
        Serial.println(data);
    } else {
        Serial.print("Send to 0x");
        Serial.print(id, HEX);
        Serial.println(" Error !!!");
    }
}
