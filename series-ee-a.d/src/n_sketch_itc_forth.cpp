// ITC-Forth.ino
// https://github.com/CharleyShattuck/Steno-Keyboard-Arduino.git

#include <Arduino.h>

#define RAM_SIZE 0x1200
#define S0 0x1000
#define R0 0x0f00

// "registers"
int S = S0; // data stack pointer
int R = R0; // return stack pointer
int I = 0; // instruction pointer
int W = 0; // working register

// const int memory [] { 0x00,0x7E,0x7E,0x18,0x18,0x18,0x18,0x00,};
const int memory [] { 0x00,0x7E,0x7E,0x18,0x18,0x18,0x18,0x00,3,0};

/*
const int memory [] {
  1, // print A
  2, // delay 1 sec
  3, // branch
  0, // to this address
};
*/

void runForth () {
next:
  W = memory [I++];
  delay(1000); // kludge
  switch (W) {
    case 0x00:
    Zero:
      Serial.print(0x00, HEX);
      Serial.write (' ');
      goto next;
    case 0x7E:
    l0x7e:
      Serial.print(0x7E, HEX);
      Serial.write (' ');
      goto next;
// const int memory [] { 0x00,0x7E,0x7E,0x18,0x18,0x18,0x18,0x00,3,0};
    case 0x18:
    l0x18:
      Serial.print(0x18, HEX);
      Serial.write (' ');
      goto next;
    case 2:
    _delay:
      delay (1000);
      goto next;
    case 3:
    branch:
      Serial.println("EOS."); // end of stanza
      I = memory [I];
      goto next;
  }
}

void setup () {
  delay(700);
  Serial.begin (9600);
  while(!Serial);
  delay(200);
  I = 0;
  S = S0;
  R = R0;
  runForth ();
}

void loop () {
  while (1) {
//    Serial.write ('A');
//    delay (1000); 
  };
}
