

#ifndef _Menu_H__
#define _Menu_H__

#include <Arduino.h>

#include <iostream>
#include <list>

using namespace std;

class Menu {
  private:
    String menus[3] = {"Start", "Setting...", "Help..."};
    String menus_en[3] = {"Start", "Setting...", "Help..."};
    String menus_cn[3] = {"开始", "设置...", "帮助..."};
    unsigned int activeIndex = 0;
    
  public:
    Menu();
    ~Menu();

    String getMenu(unsigned int index);
    unsigned int getCount();
    unsigned int getActive();
    void up();
    void down();
    
};

#endif
