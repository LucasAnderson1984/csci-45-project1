#ifndef MASTER_MIND_H
#define MASTER_MIND_H

#include <stdio.h>
#include <iostream>
#include "./rotary_encoder.h"
#include "./touch_switch.h"
#include "./tilt_switch.h"

class MasterMind {
  private:
    RotaryEncoder *rotaryEncoder;
    TouchSwitch *touchSwitch;
    TiltSwitch *tiltSwitch;
    int difficulty;
    int increment;  // For touch switch input to go from input 1-3 [0-2]
    int comInput[3];  // combination (game) input

  public:
    MasterMind(RotaryEncoder*, TouchSwitch*, TiltSwitch*);
    ~MasterMind(void);

    void startGame();
    int menu();
    void setDifficulty(int x);
    void resetGame();
};
#endif
