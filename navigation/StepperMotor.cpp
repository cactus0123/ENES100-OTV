#include "StepperMotor.h"
#include <Arduino.h>

void initStepperMotor() {
  pinMode(STEPPER_CW, OUTPUT);
  pinMode(STEPPER_CCW, OUTPUT);
  digitalWrite(STEPPER_CW, LOW);
  digitalWrite(STEPPER_CCW, LOW);
}

void stepperRotateCW() {
  digitalWrite(STEPPER_CW, HIGH);
  digitalWrite(STEPPER_CCW, LOW);
}

void stepperRotateCCW() {
  digitalWrite(STEPPER_CCW, HIGH);
  digitalWrite(STEPPER_CW, LOW);
}

void stepperStop() {
  digitalWrite(STEPPER_CW, LOW);
  digitalWrite(STEPPER_CCW, LOW);
}

