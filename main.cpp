#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>
#include "./header_files/rotary_encoder.h"
#include "./header_files/touch_switch.h"
#include "./header_files/tilt_switch.h"
#include "./header_files/master_mind.h"

int main(void)
{
  if(wiringPiSetupGpio() < 0) {
    fprintf(stderr, "Unable to setup wiringPi:%s\n",strerror(errno));
    return 1;
  }

  RotaryEncoder *rotaryEncoder = new RotaryEncoder();
  TouchSwitch *touchSwitch = new TouchSwitch();
  TiltSwitch *tiltSwitch = new TiltSwitch();
  MasterMind masterMind(rotaryEncoder, touchSwitch, tiltSwitch);

  if(wiringPiISR(SwitchPin, INT_EDGE_FALLING, RotaryEncoder::btnISR) < 0) {
    fprintf(stderr, "Unable to init ISR\n",strerror(errno));
    return 1;
  }

  masterMind.startGame();

  return 0;
}
