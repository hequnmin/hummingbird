
#include <string.h>
#include <stdio.h>

#include "Menu.h"
#include "Config.h"

#include <Arduino.h>

#include <U8g2lib.h>
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

//U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display
U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ D1, /* data=*/ D2, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display
//U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ 5, /* data=*/ 4, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display

Config config;

Menu::Menu() {

}

Menu::~Menu() {
  
}

void Menu::InitDisplay() {
  u8g2.begin();
  u8g2.enableUTF8Print();
  u8g2.setFont(u8g2_font_wqy12_t_gb2312b);
}

void Menu::DisplayHelloWorld() {

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

void Menu::DisplayMainMenu() {
  
  u8g2.setFontDirection(0);
  u8g2.setFontMode(0);
  u8g2.firstPage();
  short int menuCount = sizeof(menus) / sizeof(menus[0]);
  short int menuCursor = cursor;
  do {
    u8g2.setFont(u8g2_font_wqy12_t_gb2312b);
    for (short int i = 0; i < menuCount; i++ ) { 
      u8g2.setCursor(rowSpace, (i + 1) * rowHeight);
      u8g2.print(menus[i]);
    }

    //游标
    u8g2.setFont(u8g2_font_unifont_t_symbols);
    u8g2.drawGlyph(2, (menuCursor + 1) * rowHeight, 0x23f5);
  } while ( u8g2.nextPage() );
}

short int Menu::getCursor() {
  return cursor;
}

void Menu::setCursor(short int var) {
  cursor = var;
}

void Menu::CursorPrev() {
  if (cursor > 0) {
    cursor = cursor - 1;
  }
}

void Menu::CursorNext() {
  short int menuCount = sizeof(menus) / sizeof(menus[0]);
  if (cursor < (menuCount - 1)) {
    cursor = cursor + 1;
  }
}

void Menu::DisplayLanguageInterface() {
  u8g2.setFont(u8g2_font_wqy12_t_gb2312b);
  u8g2.setFontDirection(0);
  u8g2.setFontMode(0);
  u8g2.firstPage();

  do {
    u8g2.setFontRefHeightAll();   
    u8g2.userInterfaceMessage("", "中文-简体", "English", " OK \n Cancel ");
  } while ( u8g2.nextPage() );
}

void Menu::DisplayHelpInterface() {
  u8g2.setFont(u8g2_font_wqy12_t_gb2312b);
  u8g2.setFontDirection(0);
  u8g2.setFontMode(0);
  u8g2.firstPage();
  do {
    u8g2.setCursor(rowSpace, rowHeight);
    u8g2.print("版本:" + config.getVersion());
    u8g2.setCursor(rowSpace, 2 * rowHeight);
    u8g2.print("序列号:" + config.getChipid());
  } while ( u8g2.nextPage() );
}

//uint8_t Menu::userInterface(uint8_t currentSelection) {
//  current_selection = u8g2.userInterfaceSelectionList(
//    "Cloud Types",
//    currentSelection, 
//    string_list);
//  return current_selection;
//}

uint8_t Menu::userInterface(uint8_t pos, const char *menus) {
  u8g2.setFontDirection(0);
  u8g2.setFontMode(0);
  u8g2.firstPage();
  uint8_t menuCount = GetStringLineCnt(menus);
  uint8_t menuCursor = pos;
  if (pos > menuCount) menuCursor = menuCount;
  if (pos < 1) menuCursor = 1;
  
  do {
    u8g2.setFont(u8g2_font_wqy12_t_gb2312b);
    for (short int i = 0; i < menuCount; i++ ) { 
      u8g2.setCursor(rowSpace, (i + 1) * rowHeight);
//      u8g2.print(GetStringLineStart(i, menus));
      u8g2.print(GetStringLineIndex(i, menus));
      
    }

    //游标
    u8g2.setFont(u8g2_font_unifont_t_symbols);
    u8g2.drawGlyph(2, menuCursor * rowHeight, 0x23f5);
  } while ( u8g2.nextPage() );
  
  return menuCursor;
}

uint8_t Menu::GetStringLineCnt(const char *str) {
  char e;
  uint8_t line_cnt = 1;
  if ( str == NULL )
    return 0;
  for(;;) {
    e = *str;
    if ( e == '\0' )
      break;
    str++;
    if ( e == '\n' )
      line_cnt++;
  }
  return line_cnt;
}

const char *Menu::GetStringLineStart(uint8_t line_idx, const char *str)
{
  char e;
  uint8_t line_cnt = 1;
  
  if ( line_idx == 0 )
    return str;

  for(;;) {
    e = *str;
    if ( e == '\0' )
      break;
    str++;
    if ( e == '\n' ) {
      if ( line_cnt == line_idx )
        return str;
      line_cnt++;
    }
  }
  return NULL;  /* line not found */
}
