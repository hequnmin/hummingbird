

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
    String menus[5] = {"开始", "电机", "温度", "设置...", "帮助..."};
//    String menus[3] = {"Start ", "Seting...", " Help..."};
    
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
    
};

#endif
