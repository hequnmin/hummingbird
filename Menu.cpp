

#include "Menu.h"

#include <Arduino.h>


Menu::Menu() {

}

Menu::~Menu() {
  
}

String Menu::getMenu(unsigned int index) {
  return menus[index];
}

unsigned int Menu::getCount() {
  return sizeof(menus);
}

unsigned int Menu::getActive() {
  return activeIndex;
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
