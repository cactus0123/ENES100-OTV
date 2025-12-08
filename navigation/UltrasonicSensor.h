#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

// Ultrasonic sensor pin definitions
// NOTE: Adjust pins to avoid conflicts with other modules
#define ULTRASONIC_TRIG 42   // Brown
#define ULTRASONIC_ECHO 40   // Changed from 9 to avoid conflict

// Ultrasonic sensor functions
void initUltrasonicSensor();
float readDistance();  // Returns distance in cm, -1 if no echo
float medianDistance(int samples = 5);  // Returns median of N samples

#endif
