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
void moveForward(int spd);
void moveBackward(int spd);
void moveRight(int spd);
void moveLeft(int spd);
void rotateCW(int spd);
void rotateCCW(int spd);

// External motor array (defined in .cpp)
extern Motor motors[4];
extern int speedVal;

#endif

