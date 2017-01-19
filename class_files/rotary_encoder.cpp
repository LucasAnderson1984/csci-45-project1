#include "./../header_files/rotary_encoder.h"

volatile int RotaryEncoder::globalCounter;

RotaryEncoder::RotaryEncoder(void) {
  srand(time(NULL));
  r = (rand() % 200) - 100;
  redLEDPin = 12;
  greenLEDPin = 6;
  tmp = 0;
  globalCounter = 0;
  printf("Random: %d\n", r);

  pinMode(SWPin, INPUT);
  pinMode(RoAPin, INPUT);
  pinMode(RoBPin, INPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);

  pullUpDnControl(SWPin, PUD_UP);
}

RotaryEncoder::~RotaryEncoder(void) { }

void RotaryEncoder::btnISR(void) {
  globalCounter = 0;
}

void RotaryEncoder::rotaryDeal(void) {
  Last_RoB_Status = digitalRead(RoBPin);

  while(!digitalRead(RoAPin)) {
    Current_RoB_Status = digitalRead(RoBPin);
    flag = 1;
  }

  if(flag == 1) {
    flag = 0;

    if((Last_RoB_Status == 0) && (Current_RoB_Status == 1))
      globalCounter++;

    if((Last_RoB_Status == 1) && (Current_RoB_Status == 0))
      globalCounter--;
  }
}

void RotaryEncoder::checkStatus(void) {
  rotaryDeal();

  if (tmp != globalCounter) {
    printf("%d\n", globalCounter);
    tmp = globalCounter;
  }

  if(globalCounter == r) {
    digitalWrite(redLEDPin, 0);
    digitalWrite(greenLEDPin, 1);
  } else {
    digitalWrite(redLEDPin, 1);
    digitalWrite(greenLEDPin, 0);
  }
}
