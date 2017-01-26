#ifndef MASTER_MIND_H
#define MASTER_MIND_H

#include <alsa/asoundlib.h>
#include <alsa/pcm.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <wiringPi.h>
#include "./rotary_encoder.h"
#include "./touch_switch.h"
#include "./tilt_switch.h"

using namespace std;

#define BUFFER_LEN 48000

//Green Pins
#define GreenPinOne   6
#define GreenPinTwo   19
#define GreenPinThree 26

//Red Pins
#define RedPinOne   12
#define RedPinTwo   16
#define RedPinThree 20

class MasterMind {
  private:
    RotaryEncoder *rotaryEncoder;
    TouchSwitch *touchSwitch;
    TiltSwitch *tiltSwitch;

    float buffer [BUFFER_LEN];
    int currentLockPosition;
    int currentValue;
    int decrementValues[2];
    static char *device;
    int difficulty;
    int f;
    snd_pcm_sframes_t frames;
    int fs;
    snd_pcm_t *handle;
    int incrementValues[2];
    int lockCombination[3];
    snd_output_t *output = NULL;
    int rotaryEncoderValue;
    int rotaryValue;
    int temp;
    int tiltSwitchValue;
    int touchSwitchValue;
    int err;



    void assignRotaryTurnValues(int);
    void checkStatus(void);
    void createLockCombination(void);
    void LEDSwitch(int);
    void updateCurrentValue(void);

  public:
    MasterMind(RotaryEncoder*, TouchSwitch*, TiltSwitch*);
    ~MasterMind(void);

    int menu(void);
    void setDifficulty(int x);
    void startGame(void);
};
#endif
