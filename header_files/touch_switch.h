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
    void LED(int);
    void InputPrint(int);
  public:
    TouchSwitch(void);
    ~TouchSwitch(void);
    void checkStatus(void);
};
#endif
