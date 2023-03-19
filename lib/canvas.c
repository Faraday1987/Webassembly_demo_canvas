
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <emscripten.h>

// Number of circles
#define NUM_CIRCLES 20

// Circle Struct
struct Circle {
  int x;  // x coordinate
  int y;  // y coordinate
  int r;  // circle radius
  int cr; // color - RED
  int cg; // color - GREEN
  int cb; // color - BLUE
};

// Circles variable
struct Circle circles[NUM_CIRCLES];

// Random number generator
int getRand(int max) {
  return (rand() % max);
}

// Init circle data and start render - JS
int main() {

  // Seed random number generator
  srand(time(NULL));

  // Create circles
  for( int i = 0; i < NUM_CIRCLES; i++ ) {

    // Radius
    int radius = getRand(50);

    // Coordinates
    int x = getRand(1000) + radius;
    int y = getRand(1000) + radius;

    // Fill circle struct
    circles[i].x = x;
    circles[i].y = y;
    circles[i].r = radius;
    circles[i].cr = getRand(255);
    circles[i].cg = getRand(255);
    circles[i].cb = getRand(255);

  }

  // Start JS rendering
  EM_ASM({ render($0, $1); }, NUM_CIRCLES*6, 6 );
}

// Return circles to JS
struct Circle * getCircles() {
  return circles;
}
