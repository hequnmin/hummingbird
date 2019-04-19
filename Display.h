


#ifndef _Display_H__
#define _Display_H__

#include "Arduino.h"

#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

class Display {
  private:
    byte pin1;

    const short int rowHeight = 17;  //行像素
    const short int rowSpace = 6;   //前置空格像素
    const short int fontHeight = 15;
    
    byte currentX;
    byte currentY;


  public:
    Display();
    ~Display();

    void init();
    
    void HelloWorld();

    void print(const char* var);
    
    void disattach();

    void MainMenu();
    void SettingMenu();
    void LanguageInterface();
};

#endif
