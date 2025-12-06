/*
 * ENES100 Robot Navigation Code
 * Main navigation script combining all modules
 */

// Include all module headers
#include "drive.h"
//#include "flame_sensor.h"
#include "comm.h"

void setup() {
  Serial.begin(9600);
  delay(100);  // Give Serial time to initialize
  Serial.println("=== Initializing Robot Systems ===");
  initMotors();
  // initFlameSensors();
  // initStepperMotor();
  // initUltrasonicSensor();
  initComm();
  Serial.println("=== Initialization Complete ===");

  if (getY() > 0) {
    if (getY() < 1) {
      //180 degree turn
      if (getTheta() < -2.9 || getTheta() > 2.9) {
        rotateCCW(255);
        delay(9000);
        stopAll();
      }
      // OTV facing forwards
      else if (getTheta() < -1.4 || getTheta() > -1.6) {
        rotateCCW(255);
        delay(4500);
        stopAll();
      }

      // moveForward(255);
      // delay(5000);
      // stopAll();
    }
  }

  identifyTopography();
  // rotateCCW(255);
  // delay(2500); // rotate 90 degrees timing
  // stopAll();
  // delay(1250);
  // moveForward(255);
  // delay(10000);
  // stopAll();
  // delay(1250);
}

void loop() {
  // Your navigation logic here
  // Example: Check for flame, move, detect topography, etc.
  // Example usage:
  /*
  // Check flame sensors
  int flameValues[4];
  readAllFlameSensors(flameValues);
  
  // Move forward
  moveForward(speedVal);
  delay(1000);
  stopAll();
  
  // Read distance
  float dist = medianDistance(5);
  Serial.print("Distance: ");
  Serial.println(dist);
  
  // Identify topography
  identifyTopography();
  */
}

