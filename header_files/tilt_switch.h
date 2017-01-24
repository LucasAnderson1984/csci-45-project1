#ifndef TILT_SWITCH_H
#define TILT_SWITCH_H

#include <iostream>
#include <wiringPi.h>

#define TiltPin 25

class TiltSwitch {
  private:
  public:
    TiltSwitch(void);
    ~TiltSwitch(void);
    int checkStatus(void);
};
#endif
