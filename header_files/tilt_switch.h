#ifndef TILT_SWITCH_H
#define TILT_SWITCH_H

#include <stdio.h>
#include <wiringPi.h>

#define TiltPin 25
#define Gpin 19
#define Rpin 16

class TiltSwitch {
  private:
    void LED(char* color);
  public:
    TiltSwitch(void);
    ~TiltSwitch(void);
    void checkStatus(void);
};
#endif
