#include "lcd.h"

rgb_lcd lcd;

void lcd_init() {
    lcd.begin(16, 2);
    lcd.setRGB(255, 255, 255);
}
