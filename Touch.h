

#ifndef _Touch_H__
#define _Touch_H__

#include "Arduino.h"

class Touch {
  private:


  public:
    bool pressPrev;
    bool pressNext;
    bool pressCancel;
    bool pressOk;
    
    Touch();
    ~Touch();
    void ScanTouch();
    void disattach();
};

#endif
