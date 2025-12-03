

// Pin assignments
const int CW  = 50;  
const int CCW = 48;  

void setup() {
  // Set control pins as outputs
  pinMode(CW, OUTPUT);
  pinMode(CCW, OUTPUT);

  // Make sure both are HIGH to start
  digitalWrite(CW, HIGH);
  digitalWrite(CCW, HIGH);

  Serial.println("Finished Setup");
  delay(1000);
}

void loop() {

  // --- Rotate Counterclockwise ---
  Serial.println("CCW");
  digitalWrite(CCW, HIGH);  
  digitalWrite(CW, LOW);    
  delay(1000);              // Run for how many seconds needed before hit fire site

  // --- Stop motor ---
  digitalWrite(CW, HIGH);
  digitalWrite(CCW, HIGH);
  delay(1000);             



  // --- Rotate Clockwise ---
  Serial.println("CW");
  digitalWrite(CW, HIGH);   // Send HIGH to CW input
  digitalWrite(CCW, LOW);   // Ensure CCW is off
  delay(1000);   

  // --- Stop motor again ---
  digitalWrite(CW, HIGH);
  digitalWrite(CCW, HIGH);
  delay(1000);              // Pause 1 second
}
