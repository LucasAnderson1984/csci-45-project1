#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "./header_files/rotary_encoder.h"

#define TouchPin 23
#define Gpin 26
#define Rpin 20

int tmp = 0;

void LED(int color)
{
  pinMode(Gpin, OUTPUT);
  pinMode(Rpin, OUTPUT);

  if (color == 0) {
    digitalWrite(Rpin, HIGH);
    digitalWrite(Gpin, LOW);
  } else if (color == 1) {
    digitalWrite(Rpin, LOW);
    digitalWrite(Gpin, HIGH);
  } else {
    printf("LED Error");
  }
}

void Print(int x){
  if (x != tmp) {
    if (x == 0)
      printf("...ON\n");

    if (x == 1)
      printf("OFF..\n");

    tmp = x;
  }
}

int main(void)
{
  if(wiringPiSetupGpio() < 0) {
    fprintf(stderr, "Unable to setup wiringPi:%s\n",strerror(errno));
    return 1;
  }

  RotaryEncoder rotaryEncoder;
  pinMode(TouchPin, INPUT);

  if(wiringPiISR(SWPin, INT_EDGE_FALLING, RotaryEncoder::btnISR) < 0) {
    fprintf(stderr, "Unable to init ISR\n",strerror(errno));
    return 1;
  }

  while(1){
    rotaryEncoder.checkStatus();
    LED(digitalRead(TouchPin));
    Print(digitalRead(TouchPin));
  }

  return 0;
}
