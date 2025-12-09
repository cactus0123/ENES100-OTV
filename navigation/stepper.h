#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

// Stepper motor pin definitions
// NOTE: Pins 8-9 conflict with drive motors - adjust if needed
#define stepPin 29   // Clockwise pin
#define dirPin 28   // Counterclockwise pin

// Stepper motor functions
void initStepperMotor();
void rotateStepper(bool direction, int speed, int revs);

#endif
