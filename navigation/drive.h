#ifndef DRIVE_H
#define DRIVE_H

// Motor Pin Mapping
struct Motor {
  int in1;
  int in2;
  int en;
};

// Motor control functions
void initMotors();
void motorMove(int m, bool forward, int spd);
void stopAll();
void moveForward(int spd, bool reverse = false);
void moveBackward(int spd, bool reverse = false);
void moveRight(int spd, bool reverse = false);
void moveLeft(int spd, bool reverse = false);
void rotateCW(int spd, bool reverse = false);
void rotateCCW(int spd, bool reverse = false);

// External motor array (defined in .cpp)
extern Motor motors[4];
extern int speedVal;

#endif

