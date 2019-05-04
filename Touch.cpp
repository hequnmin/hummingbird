

#include "Touch.h"

#include "Arduino.h"

#define pinPrev 14
#define pinNext 12
#define pinCancel 13
#define pinOk 15


Touch::Touch() {
  pinMode(pinPrev, INPUT);
  pinMode(pinNext, INPUT);
  pinMode(pinCancel, INPUT);
  pinMode(pinOk, INPUT);

  digitalWrite(pinPrev, LOW);
  digitalWrite(pinNext, LOW);
  digitalWrite(pinCancel, LOW);
  digitalWrite(pinOk, LOW);
}

Touch::~Touch(){
   disattach();
}

void Touch::disattach()
{
  pinMode(pinPrev, INPUT);
  pinMode(pinNext, INPUT);
  pinMode(pinCancel, INPUT);
  pinMode(pinOk, INPUT);

  digitalWrite(pinPrev, LOW);
  digitalWrite(pinNext, LOW);
  digitalWrite(pinCancel, LOW);
  digitalWrite(pinOk, LOW);
}

void Touch::ScanTouch(){
  pressPrev = digitalRead(pinPrev);
  pressNext = digitalRead(pinNext);
  pressCancel = digitalRead(pinCancel);
  pressOk = digitalRead(pinOk);
}
