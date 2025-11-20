/*
 * RCWL-1601 manual sweep topography test
 * --------------------------------------
 * Move the sensor by hand between readings (~25 mm steps across 215 mm face).
 * The program waits 3 seconds after each measurement so you can reposition.
 * Outputs raw distances, normalized profile, and detected topography (A/B/C).
 */

const int trigPin = 7;
const int echoPin = 6;

const int numPoints = 9;        // number of manual positions
const float tolerance = 0.10;   // classification threshold
const int samplesPerPoint = 5;  // median filter size
const int moveDelay = 3000;     // ms to reposition sensor manually

float distances[numPoints];

// === Function: single distance reading in cm ===
float readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 25000L); // timeout 25 ms (~4.3 m)

  // If no pulse detected within 25 ms, return -1 instead of NaN
  if (duration == 0) return -1.0;
  return duration * 0.0343 / 2.0; // distance [cm]
}

// === Function: median of N samples ===
float medianDistance(int samples = 5) {
  float buf[15];
  int n = samples;
  for (int i = 0; i < n; i++) {
    buf[i] = readDistance();
    delay(10);
  }
  // simple bubble sort
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (buf[j] < buf[i]) {
        float t = buf[i]; buf[i] = buf[j]; buf[j] = t;
      }
    }
  }
  return buf[n / 2]; // median
}

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.println("=== RCWL-1601 Manual Sweep Test ===");
  Serial.println("Move sensor left-to-right across the block when prompted.\n");
}

void loop() {
  // Collect distance data manually
  for (int i = 0; i < numPoints; i++) {
    Serial.print("Position "); Serial.print(i + 1);
    Serial.print(" of "); Serial.print(numPoints);
    Serial.println(" → Hold steady...");

    float d = medianDistance(samplesPerPoint);
    if (d < 0) {
      Serial.println("No echo detected - check wiring or angle.");
      distances[i] = 0;   // placeholder
    } else {
      distances[i] = d;
      Serial.print("Measured: "); Serial.print(d, 2); Serial.println(" cm");
    }

    if (i < numPoints - 1) {
      Serial.println("Reposition sensor ~25 mm to the right...");
      delay(moveDelay);
    }
  }

  // Normalize
  float minV = distances[0], maxV = distances[0];
  for (int i = 1; i < numPoints; i++) {
    if (distances[i] < minV) minV = distances[i];
    if (distances[i] > maxV) maxV = distances[i];
  }
  float norm[numPoints];
  for (int i = 0; i < numPoints; i++)
    norm[i] = (distances[i] - minV) / max(0.001, (maxV - minV));

  // Compute left/middle/right averages
  int seg = numPoints / 3;
  float L = 0, M = 0, R = 0;
  for (int i = 0; i < seg; i++) L += norm[i];
  for (int i = seg; i < 2 * seg; i++) M += norm[i];
  for (int i = 2 * seg; i < numPoints; i++) R += norm[i];
  L /= seg; M /= seg; R /= (numPoints - 2 * seg);

  // Classification
  char side = '?';
  if (L > M + tolerance && M > R + tolerance) side = 'A';
  else if (L > M + tolerance && R > M + tolerance) side = 'B';
  else if (M > L + tolerance && M > R + tolerance) side = 'C';

  // Print results
  Serial.println("\n----- Sweep Results -----");
  Serial.print("Raw distances (cm): ");
  for (int i = 0; i < numPoints; i++) {
    Serial.print(distances[i], 2); Serial.print(" ");
  }
  Serial.println();

  Serial.print("Normalized: ");
  for (int i = 0; i < numPoints; i++) {
    Serial.print(norm[i], 2); Serial.print(" ");
  }
  Serial.println();

  Serial.print("Averages -> L: "); Serial.print(L, 2);
  Serial.print("  M: "); Serial.print(M, 2);
  Serial.print("  R: "); Serial.println(R, 2);

  Serial.print("Detected Side: "); Serial.println(side);
  Serial.println("--------------------------\n");

  Serial.println("Restarting in 5 seconds...");
  delay(5000);
}