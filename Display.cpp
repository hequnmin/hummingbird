

#include "Display.h"

#include <Arduino.h>

#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ D4, /* data=*/ D5, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display

Display::Display() {
  currentX = rowSpace;
  currentY = rowHeight;
}

void Display::init(){
  u8g2.begin();
  u8g2.enableUTF8Print();
}

void Display::print(const char* var) {
  u8g2.setFont(u8g2_font_wqy12_t_gb2312b);
  u8g2.setFontDirection(0);
  u8g2.firstPage();
  do {
    u8g2.setCursor(currentX, currentY);
    u8g2.print(var);  
  } while ( u8g2.nextPage() );
}

void Display::HelloWorld() {

  u8g2.setFont(u8g2_font_wqy12_t_gb2312b);
  u8g2.setFontDirection(0);
  u8g2.firstPage();
  do {
    u8g2.setCursor(currentX, currentY);
    u8g2.print("Hello World!");
    u8g2.setCursor(currentX, currentY + rowHeight);
    u8g2.print("爱因斯坦《相对论》");    
  } while ( u8g2.nextPage() );
}

Display::~Display() {
  disattach();
}

void Display::disattach() {

}
