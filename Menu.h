

#ifndef _Menu_H__
#define _Menu_H__

#include <Arduino.h>

#include <iostream>
#include <list>

using namespace std;

class Menu {
  private:
    short int cursor = 0;
    
  public:
    String menus[3] = {"开始", "设置...", "帮助..."};
//  String menus[3] = {"Start ", "Seting...", " Help..."};
    
    Menu();
    ~Menu();

    short int getCursor();
    void setCursor(short int var);
    
    void up();
    void down();
    
};

#endif
