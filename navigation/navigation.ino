/*
 * ENES100 Robot Navigation Code
 * Main navigation script combining all modules
 */

// Include all module headers
//#include "drive.h"
//#include "flame_sensor.h"
//#include "comm.h"
#include "Enes100.h"

void setup() {
  Serial.begin(9600);
  delay(100);  // Give Serial time to initialize
  Serial.println("=== Initializing Robot Systems ===");
  
  // Initialize all modules
  //initMotors();
  //initFlameSensors();
  //initStepperMotor();
  //initUltrasonicSensor();
  //initComm();
  delay(1000);
  Enes100.begin("Smokey", FIRE, 566, 1120, 50, 53);
  delay(1000);
  Serial.println(Enes100.isConnected() ? "connected" : "not connected");

  
  Serial.println("=== Initialization Complete ===");
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

