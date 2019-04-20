

#include "Touch.h"

#include "Arduino.h"

#define pinPrev 16
#define pinNext 5
#define pinCancel 4
#define pinOk 0


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
