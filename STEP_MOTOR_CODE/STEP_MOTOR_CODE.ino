// Pin assignments
const int CW  = 8;   // Pin controlling Clockwise rotation
const int CCW = 9;   // Pin controlling Counterclockwise rotation

void setup() {
  // Set control pins as outputs
  pinMode(CW, OUTPUT);
  pinMode(CCW, OUTPUT);

  // Make sure both are LOW to start
  digitalWrite(CW, LOW);
  digitalWrite(CCW, LOW);
}

void loop() {
  // --- Rotate Clockwise ---
  digitalWrite(CW, HIGH);   // Send HIGH to CW input
  digitalWrite(CCW, LOW);   // Ensure CCW is off
  delay(3000);              // Run for 3 seconds

  // --- Stop motor ---
  digitalWrite(CW, LOW);
  digitalWrite(CCW, LOW);
  delay(1000);              // Pause 1 second

  // --- Rotate Counterclockwise ---
  digitalWrite(CCW, HIGH);  // Send HIGH to CCW input
  digitalWrite(CW, LOW);    // Ensure CW is off
  delay(3000);              // Run for 3 seconds

  // --- Stop motor again ---
  digitalWrite(CW, LOW);
  digitalWrite(CCW, LOW);
  delay(1000);              // Pause 1 second
}
