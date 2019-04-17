///*
// * 
// * https://github.com/ThingPulse/esp8266-oled-ssd1306
// * 
// */
//
//
//#include <Wire.h>  
//#include "SH1106Wire.h"
//
//#include <ArduinoJson.h>
//
//#define _DURATION 3000
//#define _ROW_PIX 12
//
//#define pinPrevious 16
//#define pinNext 5
//#define pinReturn 4
//#define pinOk 0
//
//
////SH1106Wire display(ADDRESS, SDA, SDC);
//SH1106Wire display(0x3c, D5, D4);
//
////Config
//
//
////Menu
////char jsonMenu[] = "";
//
//long timeSinceLastModeSwitch = 0;
//int indexMenu = 0;
//
//boolean touchPrevious = false;
//boolean touchNext = false;
//boolean touchReturn = false;
//boolean touchOk = false;
//
//
//
//DynamicJsonDocument docMenu(1024);
//
//void setup() {
//  // put your setup code here, to run once:
//  Serial.begin(115200);
//  // while (!Serial) continue;
//  Serial.println("Setup...");
//
//  display.init();
//  display.flipScreenVertically();
//  display.setFont(ArialMT_Plain_10);
//  display.setTextAlignment(TEXT_ALIGN_LEFT);
//  display.clear();
//  display.drawString(6, 0, "Setup...");
//  delay(1000);
//  display.drawString(6, 12, "Display init...");
//  delay(1000);
//  display.display();
//
//  JsonArray menus = docMenu.createNestedArray("menus");
//  menus.add("Hand Action");
//  menus.add("Auto Action");
//  menus.add("Status Info");
//  menus.add("Setting...");
//  menus.add("Help...");
//  docMenu["active"] = 0;  
//  
//  //serializeJson(docMenu, Serial);
//
//  pinMode(pinPrevious, INPUT);
//  pinMode(pinNext, INPUT);
//  pinMode(pinReturn, INPUT);
//  pinMode(pinOk, INPUT);
//
//  Serial.println("Setup completed.");
//  
//}
//
//
//void ScanTouch(){
//  int intSize = docMenu["menus"].size();
//  int intActive = docMenu["active"];
//  
//  boolean beforePrevious = touchPrevious;
//  boolean beforeNext = touchNext;
//  touchPrevious = digitalRead(pinPrevious);
//  touchNext = digitalRead(pinNext);
//  if (!beforePrevious && touchPrevious && intActive > 0) {
//    docMenu["active"] = (intActive - 1) % intSize;
//  }
//  if (!beforeNext && touchNext && intActive < (intSize - 1) ) {
//    docMenu["active"] = (intActive + 1) % intSize;
//  }
//}
//
//void loop() {
//  ScanTouch();
//
//  displayMenu();
//  delay(10);
//  
//}
//
//
//
//void displayMenu() {
//  display.clear();
//  display.setTextAlignment(TEXT_ALIGN_LEFT);
//  for (int i = 0; i < docMenu["menus"].size(); i++ ) {
//    display.drawString(6, i * _ROW_PIX, docMenu["menus"][i]);
//  }
//  int intActive = docMenu["active"];
//  display.drawString(0, _ROW_PIX * intActive, "|");
//  display.display();
//}
