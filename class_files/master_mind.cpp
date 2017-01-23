#include "./../header_files/master_mind.h"

volatile int combInput[3]; // dunno what to name this, essentially globalCounter to be passed
int incr; // increment to be passed over

MasterMind::MasterMind(RotaryEncoder* re, TouchSwitch* tos, TiltSwitch* tis) {
  rotaryEncoder = re;
  touchSwitch = tos;
  tiltSwitch = tis;
}

MasterMind::~MasterMind(void) { }

void MasterMind::startGame() {
  while(1) {
    rotaryEncoder->checkStatus();
    combInput = rotaryEncoder->getGlobalCounter();
    touchSwitch->checkStatus();
    tiltSwitch->checkStatus();
  }
}

int MasterMind::menu() {
  int choice;

  std::cout << "Welcome to this really bad game menu <text pending>\n";
  std::cout << "0 - Easy(default)\n";
  std::cout << "1 - Normal\n";
  std::cout << "2 - Hard\n";
  std::cin >> choice;

  return choice;
}

void MasterMind::setDifficulty(int x) {
  difficulty = x;
}

void MasterMind::resetGame() {
  increment = 0;
  incr = 0;
}
