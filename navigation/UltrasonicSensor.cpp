#include "UltrasonicSensor.h"
#include <Arduino.h>

void initUltrasonicSensor() {
  pinMode(ULTRASONIC_TRIG, OUTPUT);
  pinMode(ULTRASONIC_ECHO, INPUT);
}

float readDistance() {
  digitalWrite(ULTRASONIC_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIG, LOW);

  long duration = pulseIn(ULTRASONIC_ECHO, HIGH, 35000L); // timeout 25 ms (~4.3 m)

  // If no pulse detected within 25 ms, return -1 instead of NaN
  if (duration == 0) return -1.0;
  return duration * 0.0343 / 2.0; // distance [cm]
}

float medianDistance(int samples) {
  float buf[15];
  int n = samples;
  if (n > 15) n = 15;  // Safety limit
  
  for (int i = 0; i < n; i++) {
    buf[i] = readDistance();
    delay(10);
  }
  
  // Simple bubble sort
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (buf[j] < buf[i]) {
        float t = buf[i];
        buf[i] = buf[j];
        buf[j] = t;
      }
    }
  }
  return buf[n / 2]; // median
}
