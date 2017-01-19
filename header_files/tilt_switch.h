#ifndef TILT_SWITCH_H
#define TILT_SWITCH_H

#include <stdio.h>
#include <wiringPi.h>

#define TiltPin 0
#define Gpin 1
#define Rpin 2

class TiltSwitch {
  private:
    void LED(char* color);
  public:
    TiltSwitch(void);
    ~TiltSwitch(void);
    void checkStatus(void);
};
#endif
