// Thu 24 Feb 12:33:53 UTC 2022
#include <Arduino.h>

#define BLUE 1
#define RED 2
#define GREEN 3
#define ORANGE 4
#define YELLOW 5

void cpl(int PIN) {
  bool state = digitalRead(PIN);
  state = !state;
  digitalWrite(PIN, state);
}


void setup(void) {
  pinMode(BLUE, 1); // output
  pinMode(RED, 1);
  pinMode(GREEN, 1);
  pinMode(ORANGE, 1);
  pinMode(YELLOW, 1);
}

void loop(void) {
  cpl(BLUE); cpl(RED); cpl(GREEN); cpl(ORANGE); cpl(YELLOW);
  delay(800);
}

// END.
