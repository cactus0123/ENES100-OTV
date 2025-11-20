// Ultrasonic Sensor Wire Mappings
// GND -> Red
// VCC -> White
// Echo -> Brown
// Trig -> Orange

const int ECHO = 9;
const int TRIG = 10;

void setup() {
  Serial.begin(115200);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  // Send a 10µs trigger pulse
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Measure echo return time (µs)
  long duration = pulseIn(ECHO, HIGH);

  // Convert time to distance (cm)
  float distance = duration * 0.0343 / 2.0;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(250);
}
