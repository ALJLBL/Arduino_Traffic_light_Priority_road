#include <serial.h>
#include <Arduino.h>


//===========================================================//
//========================関数定義============================//
//===========================================================//
void serialInit() {
    Serial.begin(9600);
}

int serialRead() {
    if (Serial.available() > 0) {
        char input = Serial.read();
        // 入力ASCIIコードから数値に変換
        if (input >= '0' && input <= '9') {
            return input - '0';
        }
    }
    return -1;
}
