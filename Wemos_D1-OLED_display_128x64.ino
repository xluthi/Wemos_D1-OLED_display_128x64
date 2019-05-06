/* Demo/Test sketch for OLED display 128x64 on an ESP8266

   Copyright (C) 2019 Xavier Lüthi

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define PROGRAM "Wemos_D1-OLED_display_128x64"
#define VERSION 1
#define DEBUG
#include "xl_debug.h"

 
#define OLED_RESET -1
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 OLED(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
 
void setup()   {
  Serial.begin(115200);
  Serial.print(PROGRAM);
  Serial.print(", version: ");
  Serial.println(VERSION);

  pinMode(LED_BUILTIN, OUTPUT);  // initialize onboard LED as output
  
  OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  OLED.display(); // display default Adafruit Logo to confirm LCD is working correctly
  delay(2000);
  OLED.clearDisplay();

  //display a pixel in each corner of the screen
  OLED.drawPixel(0, 0, WHITE);
  OLED.drawPixel(127, 0, WHITE);
  for (int i = 2; i < 64; i+=2) {
    OLED.drawPixel(0, i, WHITE);
    OLED.drawPixel(127, i, WHITE);
  }
  
  OLED.drawPixel(0, 63, WHITE);
  OLED.drawPixel(127, 63, WHITE);
  
 
  //Add stuff into the 'display buffer'
  OLED.setTextSize(1);
  OLED.setTextColor(WHITE);
  OLED.setCursor(27,10);
  OLED.print("caroxav");
 
  OLED.display(); //output 'display buffer' to screen  
} 
 
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  OLED.clearDisplay();
  OLED.drawRoundRect(5, 5, 117, 53, 8, WHITE);
  OLED.display();
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  OLED.clearDisplay();
  OLED.setTextSize(1);
  OLED.setTextColor(WHITE);
  OLED.setCursor(27,10);
  OLED.print("caroxav");
  OLED.display();
  delay(1000);
}
