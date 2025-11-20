#ifndef FLAME_SENSOR_H
#define FLAME_SENSOR_H

// Flame sensor pin definitions
#define FLAME_0 A0
#define FLAME_1 A5
#define FLAME_2 A4
#define FLAME_3 A3

// Flame sensor functions
void initFlameSensors();
int readFlameSensor(int sensorNum);  // 0-3
bool isFlameDetected(int sensorNum, int threshold = 35);
void readAllFlameSensors(int values[4]);

#endif

