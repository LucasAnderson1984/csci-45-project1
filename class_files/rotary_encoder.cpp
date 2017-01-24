#include "./../header_files/rotary_encoder.h"

RotaryEncoder::RotaryEncoder(void) {
  pullUpDnControl(SwitchPin, PUD_UP);
}

RotaryEncoder::~RotaryEncoder(void) { }

void RotaryEncoder::btnISR(void) { }

int RotaryEncoder::rotaryDeal(void) {
  Last_RoB_Status = digitalRead(CounterclockwiseTurn);

  while(!digitalRead(ClockwiseTurn)) {
    Current_RoB_Status = digitalRead(CounterclockwiseTurn);
    flag = 1;
  }

  if(flag == 1) {
    flag = 0;

    if((Last_RoB_Status == 0) && (Current_RoB_Status == 1))
      return 1;

    if((Last_RoB_Status == 1) && (Current_RoB_Status == 0))
      return -1;
  }
}
