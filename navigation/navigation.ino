/*
 * ENES100 Robot Navigation Code
 * Main navigation script combining all modules
 */

// Include all module headers
#include <math.h>
#include "drive.h"
#include "UltrasonicSensor.h"
#include "comm.h"

// angular velocity of OTV
const float omega = (3.14159265 / 9000);

void setup() {
  Serial.begin(9600);
  delay(100);  // Give Serial time to initialize
  Serial.println("=== Initializing Robot Systems ===");
  initMotors();
  // initFlameSensors();
  // initStepperMotor();
  initUltrasonicSensor();
  initComm();
  Serial.println("=== Initialization Complete ===");

  if (getY() > 0) {
    if (getY() < 1) {
      // initial rotation
      while (getTheta() < 0) {
        sendMessage(getCoords());
        rotateCCW(100);
        delay(500);
        stopAll();
        delay(100);
      }
      
      //correct oversteer
      stopAll();
      delay(100);
      rotateCW(255);
      delay(ceil(getTheta() / omega) + 350);
      stopAll();

      // move to mission site
      moveForward(255);
      delay(6000);
      stopAll();
      delay(500);

      // identify topography      
      identifyTopography();

      //rotate in center
      rotateCW(255);
        delay(5000);            //Test this
        stopAll();

        //Move forward
        moveForward(255);
          delay(250);

          
      if(readDistance() < 15) {
        stopAll();
        delay(250);
      }
  
  while (getY() < 1.5) {
    moveLeft(255);
    delay(250);
  }
  stopAll();
  
    if(readDistance() < 15) {
      while (getY() > 0.5) {
        moveRight(255);
        delay(250);
      }
      stopAll();
    else{
      moveForward(255)
      delay(2000);
      stopAll();
    }
        } 
    }
  }
   
    
  }
  
}

void loop() {
  
}
