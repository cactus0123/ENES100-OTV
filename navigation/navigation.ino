/*
 * ENES100 Robot Navigation Code
 * Main navigation script combining all modules
 */

// Include all module headers
#include <math.h>
#include "drive.h"
#include "UltrasonicSensor.h"
#include "comm.h"

#define PI 3.14159265

// angular velocity of OTV
const float omega = (PI / 9000);

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
      while (getTheta() > (-PI/2)) {
        rotateCW(255);
        delay(500);
        stopAll();
        delay(100);
      }

      stopAll();
      delay(100);
      rotateCCW(255);
      delay(ceil(abs(getTheta() + (PI / 2)) / omega) + 350);
      stopAll();
    }
    else {

      // initial rotation
      while (getTheta() > 0) {
        rotateCCW(100);
        delay(500);
        stopAll();
        delay(100);
      }

      //correct oversteer
      stopAll();
      delay(100);
      rotateCW(255);
      delay(ceil((PI + getTheta()) / omega) + 350);
      stopAll();

      // move to mission site
      moveForward(255);
      delay(6000);
      stopAll();
      delay(500);

      // identify topography      
      identifyTopography();

      //rotate in center
      while (getTheta() < (-PI/2) || getTheta() > (PI/2)) {
        rotateCCW(255);
        delay(500);
        stopAll();
        delay(100);
      }

      stopAll();
      delay(100);
      rotateCCW(255);
      delay(ceil(abs(getTheta() + (PI / 2)) / omega) + 350);
      stopAll();

    }
    


    //Move forward to first column
    while (getX() < 0.8) {
      moveForward(255);
      delay(250);
    }
    stopAll();
    delay(1000);

    // check if middle row is blocked
    sendMessage("Distance 1: " + String(readDistance()));
    if(readDistance() < 25) {
      // move left if middle row is blocked
      while (getY() < 1.5) {
        moveLeft(255);
        delay(250);
      }
      stopAll(); 
      delay(500); 

      // check if left row is blocked
      sendMessage("Distance 2: " + String(readDistance()));
      // move all the way right if left row is blocked
      if(readDistance() < 25) {
        while (getY() > 0.3) {
          moveRight(255);
          delay(250);
        }
        stopAll();

        while (getX() < 1.8) {
          moveForward(255);
          delay(250);
        }
        stopAll();

        while (getY() < 1) {
          moveLeft(255);
          delay(250);
        }
        stopAll();
      }
      else {
        while (getX() < 1.8) {
          moveForward(255);
          delay(250);
        }
        stopAll();

        while (getY() > 1.1) {
          moveRight(255);
          delay(250);
        }
        stopAll();
        
      }
    }
    // if middle row is not blocked, continue to row 2
    else {
      while (getX() < 1.8) {
        moveForward(255);
        delay(250);
      }
      stopAll();
    }

    /*
    ** SECOND ROW CODE
    */

    // check if middle row is blocked
    sendMessage("Distance 3: " + String(readDistance()));
    if(readDistance() < 25) {
      // move left if middle row is blocked
      while (getY() < 1.5) {
        moveLeft(255);
        delay(250);
      }
      stopAll(); 
      delay(500); 

      // check if left row is blocked
      sendMessage("Distance 4: " + String(readDistance()));
      if(readDistance() < 25) {
        // move all the way right if left row is blocked
        while (getY() > 0.3) {
          moveRight(255);
          delay(250);
        }
        stopAll();

        while (getX() < 3) {
          moveForward(255);
          delay(250);
        }
        stopAll();

        while (getY() < 1.5) {
          moveLeft(255);
          delay(250);
        }
        stopAll();
        delay(500);
      }
      else {
        while (getX() < 3) {
          moveForward(255);
          delay(250);
        }
        stopAll();
        
      }
    }
    // if middle row is not blocked, continue to finish
    else {
      while (getX() < 3) {
        moveForward(255);
        delay(250);
      }
      stopAll();

      while (getY() < 1.5) {
        moveLeft(255);
        delay(250);
      }
      stopAll();
      delay(500);

    }

    while (getX() < 3.8) {
      moveForward(255);
      delay(250);
    }
    stopAll();
    delay(1000);

  }

  // section to test code while OTV is not on field
  /*
  * Insert test code here
  * bla bla bla ....
  */
}

void loop() {
  Serial.println("Distance: " + String(readDistance()));
  sendMessage("Distance: " + String(readDistance()));
  delay(500);
}
