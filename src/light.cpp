#include <light.h>
#include <Arduino.h>

void light_read() {
    int raw_light = analogRead(pinLight);               // 光センサの値を読み取る
    int light = map(raw_light, 0, 1023, 0, 100);        // 0-1023の値を0-100に変換
    Serial.print("Light level: ");                      // シリアルモニタに表示
    Serial.println(light);
}