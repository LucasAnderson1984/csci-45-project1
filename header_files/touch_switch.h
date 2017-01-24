#ifndef TOUCH_SWITCH_H
#define TOUCH_SWITCH_H

#include <iostream>
#include <wiringPi.h>

#define TouchPin 23

class TouchSwitch {
  private:
  public:
    TouchSwitch(void);
    ~TouchSwitch(void);
    int checkStatus(void);
};
#endif
