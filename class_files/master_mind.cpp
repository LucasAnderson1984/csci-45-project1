#include "./../header_files/master_mind.h"

MasterMind::MasterMind(RotaryEncoder* re, TouchSwitch* tos, TiltSwitch* tis) {
  srand(time(NULL));

  rotaryEncoder = re;
  touchSwitch = tos;
  tiltSwitch = tis;

  currentLockPosition = 0;
  currentValue = 0;
}

MasterMind::~MasterMind(void) { }

void MasterMind::startGame() {
  digitalWrite(GreenPinOne, LOW);
  digitalWrite(GreenPinTwo, LOW);
  digitalWrite(GreenPinThree, LOW);
  digitalWrite(RedPinOne, HIGH);
  digitalWrite(RedPinTwo, HIGH);
  digitalWrite(RedPinThree, HIGH);

  createLockCombination();
  difficulty = menu();
  cout << "Difficulty: "<< difficulty << endl;
  assignRotaryTurnValues(difficulty);

  while(currentLockPosition < 3) {
    tiltSwitchValue = tiltSwitch->checkStatus();
    rotaryEncoderValue = rotaryEncoder->rotaryDeal();
    touchSwitchValue = touchSwitch->checkStatus();

    delay(20);

    updateCurrentValue();
  }

  cout << "Congratulations, you opened the lock" << endl;
}

int MasterMind::menu(void) {
  int choice = 0;

  cout << "Welcome to this really bad game menu <text pending>\n";
  cout << "0 - Easy(default)\n";
  cout << "1 - Normal\n";
  cout << "2 - Hard\n";
  cin >> choice;

  return choice;
}

void MasterMind::setDifficulty(int x) {
  difficulty = x;
}

void MasterMind::createLockCombination(void) {
  for (int i = 0; i < 3; i++)
    lockCombination[i] = rand() % 100;

  cout << lockCombination[0] << "-";
  cout << lockCombination[1] << "-";
  cout << lockCombination[2] << endl;
}

void MasterMind::assignRotaryTurnValues(int diff) {
  switch(diff) {
    case 0:
      incrementValues[0] = 2;
      incrementValues[1] = 3;
      decrementValues[0] = 2;
      decrementValues[1] = 3;
      break;
    case 1:
      incrementValues[0] = 3;
      incrementValues[1] = 7;
      decrementValues[0] = 5;
      decrementValues[1] = 5;
      break;
    case 2:
      incrementValues[0] = 11;
      incrementValues[1] = 19;
      decrementValues[0] = 6;
      decrementValues[1] = 15;
      break;
  }
}

void MasterMind::updateCurrentValue(void) {
  if (rotaryEncoder > 0)
    currentValue += incrementValues[touchSwitchValue];

  if (rotaryEncoder < 0)
    currentValue -= decrementValues[touchSwitchValue];

  checkStatus();
  cout << currentValue << endl;
  touchSwitchValue = 0;
  rotaryEncoderValue = 0;
}

void MasterMind::checkStatus(void) {
  if (currentLockPosition < 3)
    if (currentValue == lockCombination[currentLockPosition]) {
      LEDSwitch(currentLockPosition);
      currentLockPosition++;
    } else {
      cout << "That is not the right number" << endl;
    }
}

void MasterMind::LEDSwitch(int position) {
  switch(position) {
    case 0:
      cout << "You found the first value of the combination" << endl;
      digitalWrite(GreenPinOne, HIGH);
      digitalWrite(RedPinOne, LOW);
      break;
    case 1:
      cout << "You found the second value of the combination" << endl;
      digitalWrite(GreenPinTwo, HIGH);
      digitalWrite(RedPinTwo, LOW);
      break;
    case 2:
      cout << "You found the third value of the combination" << endl;
      digitalWrite(GreenPinThree, HIGH);
      digitalWrite(RedPinThree, LOW);
      break;
  }
}
