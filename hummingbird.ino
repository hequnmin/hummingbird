

#include <string>
#include <iostream>

#include "Menu.h"
#include "Touch.h"
#include "Config.h"
 
using namespace std;

Menu menu;
Touch touch;
Config config;

bool displayMainMenu = true;
bool displayLanguageInterface =false;

bool pressPrev = false;
bool pressNext = false;
bool pressCancel = false;
bool pressOk = false;
 
void setup() {
  Serial.begin(115200);

  Serial.println("Setup...");

  menu.InitDisplay();
}




void loop() {
  
  touch.ScanTouch();

  // 显示主菜单
  if (displayMainMenu) {
    menu.DisplayMainMenu();
  }

  // 显示语言界面
  if (displayLanguageInterface) {
    menu.DisplayLanguageInterface();
  }

  if (!pressCancel && touch.pressCancel) {
    displayMainMenu = true;
    displayLanguageInterface = false;
  }

  // 按下
  if (!pressNext && touch.pressNext) {
    menu.CursorNext();
  } 
  pressNext = touch.pressNext;

  if (!pressPrev && touch.pressPrev) {
    menu.CursorPrev();
  }
  pressPrev = touch.pressPrev;

  if (menu.getCursor() == 1 && (!pressOk && touch.pressOk)) {
    displayMainMenu = false;
    displayLanguageInterface = true;
  }
  
}
