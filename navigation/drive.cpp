#include "drive.h"
#include <Arduino.h>

Motor motors[4] = {
  {2, 3, 5},    // Front-Left
  {4, 7, 6},    // Front-Right
  {12, 13, 10}, // Rear-Left
  {8, 11, 9}    // Rear-Right
};

int speedVal = 180;  // 0–255 PWM speed

void initMotors() {
  for (int i = 0; i < 4; i++) {
    pinMode(motors[i].in1, OUTPUT);
    pinMode(motors[i].in2, OUTPUT);
    pinMode(motors[i].en, OUTPUT);
  }
}

void motorMove(int m, bool forward, int spd) {
  digitalWrite(motors[m].in1, forward ? HIGH : LOW);
  digitalWrite(motors[m].in2, forward ? LOW  : HIGH);
  analogWrite(motors[m].en, spd);
}

void stopAll() {
  for (int i = 0; i < 4; i++) {
    analogWrite(motors[i].en, 0);
  }
}

void moveForward(int spd) {
  for (int i = 0; i < 4; i++) motorMove(i, true, spd);
}

void moveBackward(int spd) {
  for (int i = 0; i < 4; i++) motorMove(i, false, spd);
}

void moveRight(int spd) {
  motorMove(0, true, spd);
  motorMove(1, false, spd);
  motorMove(2, true, spd);
  motorMove(3, false, spd);
}

void moveLeft(int spd) {
  motorMove(0, false, spd);
  motorMove(1, true, spd);
  motorMove(2, false, spd);
  motorMove(3, true, spd);
}

void rotateCW(int spd) {
  motorMove(0, true, spd);
  motorMove(1, false, spd);
  motorMove(2, true, spd);
  motorMove(3, false, spd);
}

void rotateCCW(int spd) {
  motorMove(0, false, spd);  // backward
  motorMove(1, true, spd);   // forward
  motorMove(2, true, spd);   // backward
  motorMove(3, false, spd);  // forward
}

