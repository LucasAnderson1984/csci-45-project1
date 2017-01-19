#ifndef TOUCH_SWITCH_H
#define TOUCH_SWITCH_H

#include <stdio.h>
#include <wiringPi.h>

#define TouchPin 23
#define Gpin 26
#define Rpin 20

class TouchSwitch {
  private:
    int tmp;
  public:
    TouchSwitch(void);
    ~TouchSwitch(void);
};
#endif
