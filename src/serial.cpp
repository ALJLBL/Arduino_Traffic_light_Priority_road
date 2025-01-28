#include <serial.h>
#include <Arduino.h>

void serialInit() {
    Serial.begin(9600);
}

int serialRead() {
    if (Serial.available() > 0) {
        char input = Serial.read();
        // Convert ASCII digit to actual number
        if (input >= '0' && input <= '9') {
            return input - '0';
        }
    }
    return -1;
}
