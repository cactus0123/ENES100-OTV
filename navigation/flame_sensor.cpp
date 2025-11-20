#include "flame_sensor.h"
#include <Arduino.h>

void initFlameSensors() {
  pinMode(FLAME_0, INPUT);
  pinMode(FLAME_1, INPUT);
  pinMode(FLAME_2, INPUT);
  pinMode(FLAME_3, INPUT);
}

int readFlameSensor(int sensorNum) {
  switch(sensorNum) {
    case 0: return analogRead(FLAME_0);
    case 1: return analogRead(FLAME_1);
    case 2: return analogRead(FLAME_2);
    case 3: return analogRead(FLAME_3);
    default: return -1;
  }
}

bool isFlameDetected(int sensorNum, int threshold) {
  int value = readFlameSensor(sensorNum);
  return (value < threshold && value >= 0);
}

void readAllFlameSensors(int values[4]) {
  values[0] = analogRead(FLAME_0);
  values[1] = analogRead(FLAME_1);
  values[2] = analogRead(FLAME_2);
  values[3] = analogRead(FLAME_3);
}

