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

void moveForward(int spd, bool reverse) {
  for (int i = 0; i < 4; i++) motorMove(i, !reverse, spd);
}

void moveBackward(int spd, bool reverse) {
  for (int i = 0; i < 4; i++) motorMove(i, reverse, spd);
}

void moveRight(int spd, bool reverse) {
  motorMove(0, !reverse, spd);
  motorMove(1, reverse, spd);
  motorMove(2, reverse, spd);
  motorMove(3, !reverse, spd);
}

void moveLeft(int spd, bool reverse) {
  motorMove(0, reverse, spd);
  motorMove(1, !reverse, spd);
  motorMove(2, !reverse, spd);
  motorMove(3, reverse, spd);
}

void rotateCCW(int spd, bool reverse) {
  motorMove(0, reverse, spd);
  motorMove(1, !reverse, spd);
  motorMove(2, reverse, spd);
  motorMove(3, !reverse, spd);
}

void rotateCW(int spd, bool reverse) {
  motorMove(0, !reverse, spd);
  motorMove(1, reverse, spd);
  motorMove(2, !reverse, spd);
  motorMove(3, reverse, spd);
}

