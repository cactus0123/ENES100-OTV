#ifndef COMM_H
#define COMM_H

// Model classification buckets
#define TOPO_A 0
#define TOPO_B 1
#define TOPO_C 2

#include <Arduino.h>
// Note: Enes100.h is included in comm.cpp, not here, to avoid multiple definition errors

// ENES100 communication functions
void initComm();
bool isConnected();
void identifyTopography();
float getX();
float getY();
float getTheta();
bool isVisible();
String getCoords();
void sendMessage(String message);

#endif

