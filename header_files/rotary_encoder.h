#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H

#include <iostream>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPi.h>

#define SwitchPin             22
#define ClockwiseTurn         16
#define CounterclockwiseTurn  27

class RotaryEncoder {
  private:
    unsigned char flag;
    unsigned char Last_RoB_Status;
    unsigned char Current_RoB_Status;

  public:
    RotaryEncoder(void);
    ~RotaryEncoder(void);

    static volatile int globalCounter;
    static void btnISR(void);
    int rotaryDeal(void);
};
#endif
