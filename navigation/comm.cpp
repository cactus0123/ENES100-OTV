#include "comm.h"
#include <stdlib.h>
#include <math.h>
#include <Enes100.h>

// Configuration
const int TX = 62;   // NOTE: Conflicts with stepper motor pin 9
const int RX = 63;  // NOTE: Conflicts with motor pin 10
const int ROOM_NUM = 1120;
const int ARDUCODE = 15;

int comp_int(const void *a, const void *b) {
  int x = *(int*)a;
  int y = *(int*)b;
  return x - y;   // ascending
}

void initComm() {
  Serial.println("Beginning Connection");
  delay(1000);
  Enes100.begin("Smokey", FIRE, ARDUCODE, ROOM_NUM, TX, RX);
  delay(1000);
  Serial.println(Enes100.isConnected() ? "connected" : "not connected");
  Enes100.println("Hello World, Team Smokey is connected!");
}

bool isConnected() {
  return Enes100.isConnected();
}

void identifyTopography() {
  int ids[10];
  int sum = 0;

  for(int i = 0; i < 10; i++) {
    ids[i] = Enes100.MLGetPrediction(2);
    sum += ids[i];
  }
  
  float mean = sum / 10.0;
  int roundedMean = (int)round(mean);
  
  if (roundedMean == TOPO_A) {
    Serial.println("Identified Face: A");
    Enes100.mission(TOPOGRAPHY, TOP_A);
  }
  else if(roundedMean == TOPO_B) {
    Serial.println("Identified Face: B");
    Enes100.mission(TOPOGRAPHY, TOP_B); 
  }
  else if(roundedMean == TOPO_C) {
    Serial.println("Identified Face: C");
    Enes100.mission(TOPOGRAPHY, TOP_C);
  }
  else {
    Serial.println("Invalid Identification, try repositioning OTV");
  }
}

float getX() {
  return Enes100.getX();
}

float getY() {
  return Enes100.getY();
}

float getTheta() {
  return Enes100.getTheta();
}

bool isVisible() {
  return Enes100.isVisible();
}

String getCoords() {
  if (Enes100.isVisible()) {
    float x = getX();
    float y = getY();
    float theta = getTheta();
    String result = "Position: (";
    result += String(x);
    result += ", ";
    result += String(y);
    result += ", ";
    result += String(theta);
    result += ")";
    return result;
  } else {
    return "OTV is not visible";
  }
}

void sendMessage(String message) {
  Enes100.println(message);
}

