#if 0

  Tue  7 Jun 12:38:26 UTC 2022

#endif

uint8_t count;

void setup() {
    Serial.begin(9600);
    Serial.println("operational.");
    count = 0; // base 60 foo idea here
}

void loop()  {
  delay(8000); // expecting cognitive issues here ;)
  count++; // increment
  if (count > 59) { // base 60 roll-over - modulo-60 foo
      count = 0;
  }
  Serial.print(" count is: ");
  Serial.print(count);
  Serial.print("   "); // no carriage return wanted right now.
}

// END.
