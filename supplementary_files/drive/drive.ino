
// === Motor Pin Mapping ===
struct Motor {
  int in1;
  int in2;
  int en;
};

Motor motors[4] = {
  {2, 3, 5},    // Front-Left
  {4, 7, 6},    // Front-Right
  {12, 13, 10},    // Rear-Left
  {8, 11, 9}  // Rear-Right
};

int speedVal = 180;  // 0–255 PWM speed

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(motors[i].in1, OUTPUT);
    pinMode(motors[i].in2, OUTPUT);
    pinMode(motors[i].en, OUTPUT);
  }
}

// === Helper ===
void motorMove(int m, bool forward, int spd) {
  digitalWrite(motors[m].in1, forward ? HIGH : LOW);
  digitalWrite(motors[m].in2, forward ? LOW  : HIGH);
  analogWrite(motors[m].en, spd);
}

void stopAll() {
  for (int i = 0; i < 4; i++) {
    analogWrite(motors[i].en, 0);
  }
}

// === Movements ===
void moveForward(int spd) {
  for (int i = 0; i < 4; i++) motorMove(i, true, spd);
}

void moveBackward(int spd) {
  for (int i = 0; i < 4; i++) motorMove(i, false, spd);
}

void moveRight(int spd) {
  motorMove(0, false, spd);
  motorMove(1, true, spd);
  motorMove(2, true, spd);
  motorMove(3, false, spd);
}

void moveLeft(int spd) {
  motorMove(0, true, spd);
  motorMove(1, false, spd);
  motorMove(2, false, spd);
  motorMove(3, true, spd);
}

void rotateCW(int spd) {   // spin right
  motorMove(0, true, spd);
  motorMove(1, false, spd);
  motorMove(2, true, spd);
  motorMove(3, false, spd);
}

void rotateCCW(int spd) {  // spin left
  motorMove(0, false, spd);
  motorMove(1, true, spd);
  motorMove(2, false, spd);
  motorMove(3, true, spd);
}

// === Demo ===
void loop() {
  /*
  moveForward(speedVal); delay(1000);
  stopAll(); delay(500);
  moveBackward(speedVal); delay(1000);
  stopAll(); delay(500);
  moveLeft(speedVal); delay(1000);
  stopAll(); delay(500);
  moveRight(speedVal); delay(1000);
  stopAll(); delay(500);
  rotateCW(speedVal); delay(1000);
  stopAll(); delay(500);
  rotateCCW(speedVal); delay(1000);
  stopAll(); delay(2000);
  */

  rotateCW(255);
  delay(2700);
  stopAll();
  delay(1250);
  /*
  moveForward(200);
  delay(1000);
  moveForward(150);
  delay(1000);
  moveForward(100);
  delay(1000);
  stopAll();
  moveBackward(255);
  delay(1000);
  stopAll();

*/
}
