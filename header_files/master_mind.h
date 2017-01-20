#ifndef MASTER_MIND_H
#define MASTER_MIND_H

#include <stdio.h>
#include "./rotary_encoder.h"
#include "./touch_switch.h"
#include "./tilt_switch.h"

class MasterMind {
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
