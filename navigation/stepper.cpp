#include "stepper.h"
#include <Arduino.h>

void initStepperMotor() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void rotateStepper(bool direction, int speed, int revs) {

  // true for clockwise, false for counterclockwise
  digitalWrite(dirPin, direction ? HIGH : LOW);

  for (int i = 0; i < revs * 200; i++) { // 200 steps per revolution
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000 / speed);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000 / speed);
  }
  
  delay(1000);
}

