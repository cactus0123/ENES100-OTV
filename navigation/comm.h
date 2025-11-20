#ifndef COMM_H
#define COMM_H

// Model classification buckets
#define TOPO_A 0
#define TOPO_C 1
#define TOPO_B 3

#include <Arduino.h>

// ENES100 communication functions
void initComm();
bool isConnected();
void identifyTopography();
float getX();
float getY();
bool isVisible();
String getCoords();

#endif

