#include "lcd.h"
#include <Arduino.h>

rgb_lcd lcd;


//===========================================================//
//========================関数定義============================//
//===========================================================//
void lcd_init() {
    lcd.begin(16, 2);
    lcd.setRGB(255, 0, 0);
    
    byte upArrow[8] = {
        0b00100,
        0b01110,
        0b10101,
        0b00100,
        0b00100,
        0b00100,
        0b00000,
        0b00000
    };

    byte leftArrow[8] = {
        0b00000,
        0b00000,
        0b00100,
        0b01000,
        0b11111,
        0b01000,
        0b00100,
        0b00000
    };

    byte rughtArrow[8] = {
        0b00000,
        0b00000,
        0b00100,
        0b00010,
        0b11111,
        0b00010,
        0b00100,
        0b00000
    };

    lcd.createChar(0, upArrow);
    lcd.createChar(1, leftArrow);
    lcd.createChar(2, rughtArrow);
}

// LCD 更新関数
void updateLCD(uint8_t status) {
    if (g_lcd_flag) {
        g_lcd_flag = 0;

        lcd.clear();
        lcd.setCursor(0, 0);

        switch (status) {
            case 0:
                // バックライトを赤に
                lcd.setRGB(255, 0, 0);
                break;
            case 1:
                // バックライトを緑に
                lcd.setRGB(0, 255, 0);
                lcd.setCursor(6, 0);
                lcd.write(byte(1));
                lcd.setCursor(7, 0);
                lcd.write(byte(0));
                lcd.setCursor(8, 0);
                lcd.write(byte(0));
                lcd.setCursor(9, 0);
                lcd.write(byte(2));
                break;
            case 2:
                // バックライトを黄色に
                lcd.setRGB(255, 255, 0);
                break;
            case 3:
                // バックライトを赤点滅
                if (g_flash_flag) {
                    lcd.setRGB(255, 0, 0);
                } else {
                    lcd.setRGB(0, 0, 0);
                }
                break;

            default:
                // バックライトを赤点滅
                if (g_flash_flag) {
                    lcd.setRGB(255, 0, 0);
                } else {
                    lcd.setRGB(0, 0, 0);
                }
                break;
        }
    }
}
