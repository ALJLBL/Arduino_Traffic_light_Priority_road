#include "lcd.h"
#include <Arduino.h>

rgb_lcd lcd;

void lcd_init() {
    lcd.begin(16, 2);
    lcd.setRGB(255, 255, 255);
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
