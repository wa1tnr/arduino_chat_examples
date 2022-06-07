#if 0
  Variable speed - low or high is slow, mid is fast
  Tue  7 Jun 13:01:35 UTC 2022

  TODO: count down, not up. ;)
#endif

uint8_t count;

void setup() {
    Serial.begin(9600);
    Serial.println("operational.");
    count = 0; // base 60 foo idea here
}

void same_delay() {
  delay(1000);
}

void condx_delay(uint8_t counted) {
  if (counted > 52) {
    same_delay(); // delay(1000);
    return;
  }
  if (counted < 4) {
    same_delay();
    return;
  }
  delay(422); // fall-thru so that most of the loop runs faster.
}

void loop()  {
  condx_delay(count);
  count++; // increment
  if (count > 59) { // base 60 roll-over - modulo-60 foo
      count = 0;
  }
  Serial.print(" count is: ");
  Serial.print(count);
  Serial.print("   "); // no carriage return wanted right now.
}

// END.
