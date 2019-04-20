

#include "Menu.h"

#include <Arduino.h>


Menu::Menu() {

}

Menu::~Menu() {
  
}

short int Menu::getCursor() {
  return cursor;
}

void Menu::setCursor(short int var) {
  cursor = var;
}

void Menu::up() {
  if (cursor < (sizeof(menus) - 1)) {
    cursor = cursor + 1;
  }
}
void Menu::down() {
  if (cursor > 0) {
    cursor = cursor - 1;
  }
}
