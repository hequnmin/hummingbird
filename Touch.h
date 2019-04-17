

#ifndef _Touch_H__
#define _Touch_H__

#include "Arduino.h"

class Touch {
  private:
    byte pin1;
    byte pin2;
    byte pin3;
    byte pin4;

  public:
    Touch();
    ~Touch();
    byte ScanTouch();
    void disattach();
};

#endif
