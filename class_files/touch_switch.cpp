#include "./../header_files/touch_switch.h"

TouchSwitch::TouchSwitch(void) {
  pinMode(TouchPin, INPUT);
}

TouchSwitch::~TouchSwitch(void) { }

int TouchSwitch::checkStatus(void) {
  return digitalRead(TouchPin);
}
