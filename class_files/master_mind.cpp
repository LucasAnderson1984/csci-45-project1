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

void MasterMind::resetGame(void) {
  increment = 0;
  incr = 0;
}

void MasterMind::createLockCombination(void) {
  for (int i = 0; i < 3; i++)
    lockCombination[i] = rand() % 100;
}

void MasterMind::assignRotaryTurnValues(int diff) {
  switch(diff) {
    case 0:
      incrementValues = [2, 3];
      decrementValues = [2, 3];
      break;
    case 1:
      incrementValues = [3, 7];
      decrementValues = [5, 5];
      break;
    case 2:
      incrementValues = [11, 19];
      decrementValues = [6, 15];
      break;
  }
}

void MasterMind::updateCurrentValue(void) {
  if (rotaryEncoder > 0)
    currentValue += incrementValues[touchSwitchValue];

  if (rotaryEncoder < 0)
    currentValue -= decrementValues[touchSwitchValue];

  checkStatus();

  touchSwitchValue = 0;
  rotaryEncoderValue = 0;
}

void MasterMind::checkStatus(void) {
  if (lockCombination < 3)
    if (currentValue == lockCombination[currentLockPosition]) {
      LEDSwitch(currentLockPosition);
      currentLockPosition++;
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
      ditalWrite(GreenPinTwo, HIGH);
      digitalWrite(RedPinTwo, LOW);
      break;
    case 2:
      cout << "You found the third value of the combination" << endl;
      ditalWrite(GreenPinThree, HIGH);
      digitalWrite(RedPinThree, LOW);
      break;
  }
}
