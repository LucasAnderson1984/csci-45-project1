#include "./../header_files/master_mind.h"

MasterMind::MasterMind(RotaryEncoder re, TouchSwitch tos, TiltSwitch tis) {
  rotaryEncoder = re;
  touchSwitch = tos;
  tiltSwitch = tis;
}

MasterMind::~MasterMind(void) { }

void MasterMind::startGame() {
  while(1) {
    rotaryEncoder->checkStatus();
    touchSwitch->checkStatus();
    tiltSwitch->checkStatus();
  }
}
