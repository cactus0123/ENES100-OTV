#include <Enes100.h>
#include <stdlib.h>

// Model's corresponsing classification buckets
#define A 0
#define C 1
#define B 3

/* 
** Pins 12 and 13 work for mega
** Uno can use whatever
const int TX = 12;
const int RX = 13;
*/

const int TX = 9;
const int RX = 10;
const int ROOM_NUM = 1120;
const int ARDUCODE = 566;

char coordinates[100] = {0};

void setup() {
  Serial.begin(9600);
  Serial.println("Beginning Connection");
  delay(1000);
  Enes100.begin("Smokey", FIRE, ARDUCODE, ROOM_NUM, TX, RX);
  delay(1000);
  Serial.println(Enes100.isConnected() ? "connected" : "not connected");
  Enes100.println("Hello World, Team Smokey is connected!");
}

int comp_int(const void *a, const void *b) {
  int x = *(int*)a;
  int y = *(int*)b;
  return x - y;   // ascending
}

void identify_topography() {
  int ids[10];

  for(int i = 0; i < 10; i++) {
    ids[i] = Enes100.MLGetPrediction(1);
  }
  qsort(ids, 10, sizeof(int), comp_int);
  
  if (ids[4] == A) {
    Serial.println("Identified Face: A");
    Enes100.mission(TOPOGRAPHY, TOP_A);
  }
  else if(ids[4] == B) {
    Serial.println("Identified Face: B");
    Enes100.mission(TOPOGRAPHY, TOP_B); 
  }
  else if(ids[4] == C) {
    Serial.println("Identified Face: C");
    Enes100.mission(TOPOGRAPHY, TOP_C);
  }
  else {
    Serial.println("Invalid Identification, try repositioning OTV");
  }

}

void loop() {

  //Serial.println(Enes100.isVisible() ? "OTV is visible" : "OTV is not visible");
  //sprintf(coordinates, "Position: (%s, %s)", String(Enes100.getX()), String(Enes100.getY()));
  //Serial.println(coordinates);
  // Serial.print("Coordinates: (");
  // Serial.print(Enes100.getX());
  // Serial.print(", ");
  // Serial.print(Enes100.getY());
  // Serial.println(")");

  //Serial.println(Enes100.MLGetPrediction(1));
  identify_topography();
}
