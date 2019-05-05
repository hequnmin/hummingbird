

#ifndef _Menu_H__
#define _Menu_H__

#include <Arduino.h>

#include <U8g2lib.h>
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

class Menu {
  private:
    short int cursor = 0;


    const short int rowHeight = 15;  //行像素
    const short int rowSpace = 15;   //前置空格像素
    const short int fontHeight = 15;

    const short int pageSize = 4;   //每页记录数
    
    short int currentX = 0;
    short int currentY = 0;
    
  public:
    const String menus[5] = {"开始", "电机", "温度", "设置...", "帮助..."};

    const char *string_list = 
      "Altocumulus\n"
      "Altostratus\n"
      "Cirrocumulus\n"
      "Cirrostratus\n"
      "Cirrus\n"
      "Cumulonimbus\n"
      "Cumulus\n"
      "Nimbostratus\n"
      "Stratocumulus\n"
      "Stratus";
    uint8_t current_selection = 1;
    
    
    Menu();
    ~Menu();
    
    void InitDisplay();

    void DisplayHelloWorld();
    void DisplayMainMenu();

    short int getCursor();
    void setCursor(short int var);
    
    void CursorPrev();
    void CursorNext();
    void DisplayLanguageInterface();
    void DisplayHelpInterface();

    uint8_t userInterface(uint8_t pos, const char *menus);

    uint8_t GetStringLineCnt(const char *str);
    const char *GetStringLineStart(uint8_t line_idx, const char *str);
    
};

#endif
