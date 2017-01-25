#include "./../header_files/tilt_switch.h"

TiltSwitch::TiltSwitch(void) {
  pinMode(TiltPin, INPUT);
}

TiltSwitch::~TiltSwitch(void) { }

int TiltSwitch::checkStatus(void) {
  return digitalRead(TiltPin);
}
