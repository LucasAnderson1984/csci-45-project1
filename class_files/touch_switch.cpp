#include "./../header_files/touch_switch.h"

TouchSwitch::TouchSwitch() {
  int tmp = 0;
  pinMode(TouchPin, INPUT);
}

TouchSwitch::~TouchSwitch() { }

void TouchSwitch::LED(int color) {
  pinMode(Gpin, OUTPUT);
  pinMode(Rpin, OUTPUT);

  if (color == 0) {
    digitalWrite(Rpin, HIGH);
    digitalWrite(Gpin, LOW);
  } else if (color == 1) {
    digitalWrite(Rpin, LOW);
    digitalWrite(Gpin, HIGH);
  } else {
    printf("LED Error");
  }
}

void TouchSwitch::InputPrint(int x) {    
  if (x != tmp) {
    if (x == 0)
      printf("...ON\n");

    if (x == 1)
      printf("OFF..\n");

    tmp = x;

    if (increment < 4) {
      comInput[increment] = globalCounter;
      ++increment;
    }

  }
}

void TouchSwitch::checkStatus(void) {
  LED(digitalRead(TouchPin));
  Input(digitalRead(TouchPin));
}
