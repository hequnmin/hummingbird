

#include <string>
#include <iostream>

//#include "Menu.h"
#include "Display.h"
#include "Config.h"
 
using namespace std;

//Menu menu;
Display display;
Config config;
 
void setup() {


  Serial.begin(115200);

  Serial.println("Setup...");

  display.init();
}




void loop() {



//  display.HelloWorld();
  display.MainMenu();

//  String ver = config.getVersion();
//  Serial.print("Version:");
//  Serial.println(ver);

//  display.print("爱因斯坦");
  
//  delay(3000);

//  display.displayMenu();
  
}
