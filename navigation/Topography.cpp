#include "Topography.h"
#include <Arduino.h>

void normalizeDistances(float distances[NUM_POINTS], float normalized[NUM_POINTS]) {
  // Find min and max
  float minV = distances[0], maxV = distances[0];
  for (int i = 1; i < NUM_POINTS; i++) {
    if (distances[i] < minV) minV = distances[i];
    if (distances[i] > maxV) maxV = distances[i];
  }
  
  // Normalize
  float range = max(0.001, (maxV - minV));
  for (int i = 0; i < NUM_POINTS; i++) {
    normalized[i] = (distances[i] - minV) / range;
  }
}

char detectTopography(float distances[NUM_POINTS]) {
  float norm[NUM_POINTS];
  normalizeDistances(distances, norm);
  
  // Compute left/middle/right averages
  int seg = NUM_POINTS / 3;
  float L = 0, M = 0, R = 0;
  for (int i = 0; i < seg; i++) L += norm[i];
  for (int i = seg; i < 2 * seg; i++) M += norm[i];
  for (int i = 2 * seg; i < NUM_POINTS; i++) R += norm[i];
  L /= seg;
  M /= seg;
  R /= (NUM_POINTS - 2 * seg);
  
  // Classification
  if (L > M + TOLERANCE && M > R + TOLERANCE) return 'A';
  else if (L > M + TOLERANCE && R > M + TOLERANCE) return 'B';
  else if (M > L + TOLERANCE && M > R + TOLERANCE) return 'C';
  else return '?';
}

