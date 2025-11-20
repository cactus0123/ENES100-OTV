#ifndef TOPOGRAPHY_H
#define TOPOGRAPHY_H

// Topography detection constants
#define NUM_POINTS 9
#define TOLERANCE 0.10
#define SAMPLES_PER_POINT 5

// Topography classification
char detectTopography(float distances[NUM_POINTS]);
void normalizeDistances(float distances[NUM_POINTS], float normalized[NUM_POINTS]);

#endif

