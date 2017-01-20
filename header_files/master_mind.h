#ifndef MASTER_MIND_H
#define MASTER_MIND_H

#include <stdio.h>
#include "./header_files/rotary_encoder.h"
#include "./header_files/touch_switch.h"
#include "./header_files/tilt_switch.h"

class MasterMind() {
  private:
    RotaryEncoder *rotaryEncoder;
    TouchSwitch *touchSwitch;
    TiltSwitch *tiltSwitch;

  public:
    MasterMind(RotaryEncoder, TouchSwitch, TiltSwitch);
    ~MasterMind(void);

    void startGame();
};
#endif
