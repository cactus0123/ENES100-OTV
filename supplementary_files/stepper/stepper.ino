

// Pin assignments
const int CW  = 50;  
const int CCW = 48;  

void setup() {
  Serial.begin(9600);
  // Set control pins as outputs
  pinMode(CW, OUTPUT);
  pinMode(CCW, OUTPUT);

  Serial.println("Finished Setup");
  delay(1000);

}

// void spinCCW(int dur) {
//   Serial.println("CCW");
//   digitalWrite(CCW, HIGH);  
//   digitalWrite(CW, LOW);    
//   delay(dur); 
// }

// void spinCW(int dur) {
//   Serial.println("CW");
//   digitalWrite(CCW, LOW);  
//   digitalWrite(CW, HIGH);    
//   delay(dur); 
// }

// void stopStepper(int dur) {
//   Serial.println("Stop");
//   digitalWrite(CCW, LOW);
//   digitalWrite(CCW, LOW);
//   delay(dur);
// }

void loop() {
}
