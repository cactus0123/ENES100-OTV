#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

// Stepper motor pin definitions
// NOTE: Pins 8-9 conflict with drive motors - adjust if needed
#define STEPPER_CW  8   // Clockwise pin
#define STEPPER_CCW 9   // Counterclockwise pin

// Stepper motor functions
void initStepperMotor();
void stepperRotateCW();
void stepperRotateCCW();
void stepperStop();

#endif

