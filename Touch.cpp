

#include "Touch.h"

#include "Arduino.h"

#define pinPrevious 16
#define pinNext 5
#define pinReturn 4
#define pinOk 0


Touch::Touch() {
  pinMode(pinPrevious, INPUT);
  pinMode(pinNext, INPUT);
  pinMode(pinReturn, INPUT);
  pinMode(pinOk, INPUT);

  digitalWrite(pinPrevious, LOW);
  digitalWrite(pinNext, LOW);
  digitalWrite(pinReturn, LOW);
  digitalWrite(pinOk, LOW);
}

Touch::~Touch(){
   disattach();
}

void Touch::disattach()
{
  pinMode(pinPrevious, INPUT);
  pinMode(pinNext, INPUT);
  pinMode(pinReturn, INPUT);
  pinMode(pinOk, INPUT);

  digitalWrite(pinPrevious, LOW);
  digitalWrite(pinNext, LOW);
  digitalWrite(pinReturn, LOW);
  digitalWrite(pinOk, LOW);
}
