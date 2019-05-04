
/*
 *            
 * 
 * 
 * 
 */


#include <string>
#include <iostream>

#include "Menu.h"
#include "Touch.h"
#include "Config.h"
 
using namespace std;

Menu menu;
Touch touch;
Config cf;

bool displayMainMenu = true;
bool displayLanguageInterface = false;
bool displayHelpInterface = false;

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

  // 显示帮助界面
  if (displayHelpInterface) {
    menu.DisplayHelpInterface();
  }

  if (!pressCancel && touch.pressCancel) {
    Serial.println("touch cancel.");
    displayMainMenu = true;
    displayLanguageInterface = false;
  }

  if (!pressNext && touch.pressNext) {
    menu.CursorNext();
  } 
  pressNext = touch.pressNext;

  if (!pressPrev && touch.pressPrev) {
    menu.CursorPrev();
  }
  pressPrev = touch.pressPrev;

  // 设置
  if (menu.getCursor() == 1 && (!pressOk && touch.pressOk)) {
    displayMainMenu = false;
    displayLanguageInterface = true;
  }

  // 帮助
  if (menu.getCursor() == 2) {
    if (!pressOk && touch.pressOk) {
      displayMainMenu = false;
      displayHelpInterface = true;
    } 
    if (!pressCancel && touch.pressCancel) {
      displayMainMenu = true;
      displayHelpInterface = false;
    }
  }
}
