


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

    const byte rowHeight = 15;  //行像素
    const byte rowSpace = 4;   //前置空格像素
    byte currentX;
    byte currentY;


  public:
    Display();
    ~Display();

    void init();
    
    void HelloWorld();

    void print(const char* var);
    
    void disattach();
};

#endif
