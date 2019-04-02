/*
 * 
 * https://github.com/ThingPulse/esp8266-oled-ssd1306
 * 
 */

//#include <Wire.h>
//#include "SSD1306Wire.h"
//
////SSD1306Wire display(ADDRESS, SDA, SDC);
//SSD1306Wire display(0x3c, D3, D4);

#include <Wire.h>  
#include "SH1106Wire.h"

#include <ArduinoJson.h>
#include <SD.h>
#include <SPI.h>

#define _DURATION 3000
#define _ROW_PIX 12

#define TouchPin16 16
#define TouchPin2 5
#define TouchPin3 4
#define TouchPin4 0


//SH1106Wire display(ADDRESS, SDA, SDC);
SH1106Wire display(0x3c, D3, D4);

//Config


//Menu
//char jsonMenu[] = "";

long timeSinceLastModeSwitch = 0;
int indexMenu = 0;

boolean upPress = false;
boolean TouchStatus2=false;
boolean TouchStatus3=false;
boolean TouchStatus4=false;



DynamicJsonDocument docMenu(1024);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial) continue;

  JsonArray menus = docMenu.createNestedArray("menus");
  menus.add("Hand Action");
  menus.add("Auto Action");
  menus.add("Status Info");
  menus.add("Setting...");
  menus.add("Help...");
  docMenu["active"] = 0;  
  
  //serializeJson(docMenu, Serial);

  pinMode(TouchPin16, INPUT);
  pinMode(TouchPin2, INPUT);
  pinMode(TouchPin3, INPUT);
  pinMode(TouchPin4, INPUT);

  Serial.println();

  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
}

//void readTouch(){
//  TouchStatus1=digitalRead(TouchPin1);
//  TouchStatus2=digitalRead(TouchPin2);
//  TouchStatus3=digitalRead(TouchPin3);
//  TouchStatus4=digitalRead(TouchPin4);
//  delay(10);
//}

void upTouch(){
  boolean before = upPress;
  upPress = digitalRead(TouchPin16);
  if (!before && upPress) {
    int intActive = docMenu["active"];
    int intSize = docMenu["menus"].size();
    docMenu["active"] = (intActive + 1) % intSize;
  }
  delay(10);
}

void loop() {
  upTouch();

  displayMenu();
  delay(10);
  
}



void displayMenu() {
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  for (int i = 0; i < docMenu["menus"].size(); i++ ) {
    display.drawString(6, i * _ROW_PIX, docMenu["menus"][i]);
  }
  int intActive = docMenu["active"];
  display.drawString(0, _ROW_PIX * intActive, "|");
  display.display();
}

//void drawFontFaceDemo() {
//    // Font Demo1
//    // create more fonts at http://oleddisplay.squix.ch/
//    display.setTextAlignment(TEXT_ALIGN_LEFT);
//    display.setFont(ArialMT_Plain_10);
//    display.drawString(0, 0, "Hello world");
//    display.setFont(ArialMT_Plain_16);
//    display.drawString(0, 10, "Hello world");
//    display.setFont(ArialMT_Plain_24);
//    display.drawString(0, 26, "Hello world");
//}
