#include <LiquidCrystal.h>

#define LCD_E   12
#define LCD_RS  A6
#define LCD_D4  6
#define LCD_D5  8
#define LCD_D6  9
#define LCD_D7  10
#define LCD_BL  11    // back light
#define LCD_VO  13    // contrast (on / off to spare energy)
#define LCD_ON  MOSI  // power on LCD

byte pins[] = {LCD_E, LCD_RS, LCD_D4, LCD_D5, LCD_D6, LCD_D7, LCD_VO};

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

void setup() {
  // testPins(); // just to test connections with oscilloscope
  pinMode(LCD_BL, OUTPUT);
  digitalWrite(LCD_BL, HIGH); // backlight
  pinMode(LCD_ON, HIGH); // LCD on / off
  digitalWrite(LCD_ON, HIGH); // backlight
  pinMode(13, INPUT); // contrast control / turned off in this version
  delay(10);
  lcd.begin(16, 2);
  lcd.print("hello, world!");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
}


void testPins() {
  for (byte i = 0; i < sizeof(pins); i++) {
    pinMode(pins[i], OUTPUT);
  }
  while (true) {
    for (byte i = 0; i < sizeof(pins); i++) {
      digitalWrite(pins[i], HIGH);
    }
    delay(10);
    for (byte i = 0; i < sizeof(pins); i++) {
      digitalWrite(pins[i], LOW);
    }
    delay(10);
  }
}


