

#include "Menu.h"

#include <Arduino.h>


Menu::Menu() {

}

Menu::~Menu() {
  
}

short int Menu::getActive() {
  return activeIndex;
}

void Menu::setActive(short int var) {
  activeIndex = var;
}

void Menu::up() {
  if (activeIndex < (sizeof(menus) - 1)) {
    activeIndex = activeIndex + 1;
  }
}
void Menu::down() {
  if (activeIndex > 0) {
    activeIndex = activeIndex - 1;
  }
}
