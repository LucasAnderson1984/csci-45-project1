#include "./../header_files/tilt_switch.h"

TiltSwitch::TiltSwitch(void) {
  pinMode(TiltPin, INPUT);
  LED("GREEN");
}

TiltSwitch::~TiltSwitch(void) { }

void TiltSwitch::LED(char* color) {
  pinMode(Gpin, OUTPUT);
  pinMode(Rpin, OUTPUT);

  if (color == "RED") {
    digitalWrite(Rpin, HIGH);
    digitalWrite(Gpin, LOW);
  }
  else if (color == "GREEN") {
    digitalWrite(Rpin, LOW);
    digitalWrite(Gpin, HIGH);
  } else
    printf("LED Error");
}

void TiltSwitch::checkStatus(void) {
  if(0 == digitalRead(TiltPin)) {
    delay(10);

    if(0 == digitalRead(TiltPin)) {
      LED("RED");
      printf("Tilt!\n");
    }
  } else if(1 == digitalRead(TiltPin)) {
    delay(10);

    if(1 == digitalRead(TiltPin)) {
      while(!digitalRead(TiltPin));
        LED("GREEN");
      }
  }
}
