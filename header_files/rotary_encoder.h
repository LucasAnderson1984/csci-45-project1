#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <time.h>

#define  RoAPin 17
#define  RoBPin 27
#define  SWPin  22

class RotaryEncoder {
  private:
    int greenLEDPin;
    int r;
    int redLEDPin;
    int tmp;

    unsigned char flag;
    unsigned char Last_RoB_Status;
    unsigned char Current_RoB_Status;

    void rotaryDeal(void);

  public:
    RotaryEncoder(void);
    ~RotaryEncoder(void);

    static volatile int globalCounter;
    static void btnISR(void);
    void checkStatus(void);
};
#endif
