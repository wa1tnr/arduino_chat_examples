// inbound to IDE 03:34z
// NIS version
// zolkal  terbpia 03:34z last offline edit

#include <Arduino.h>

#if 0
 decimal 122           2 base !  . 01111010  ok
 decimal 122  255 xor  2 base !  . 10000101  ok
#endif

// further reading here:
// https://github.com/CsCrazy85/DatavisionLCD

#include <SoftwareSerial.h>
SoftwareSerial connection(10, 11, true);
uint8_t data;

void assign_data(uint8_t inbound) {
    data = inbound ;
}

#if 0 // not today - held for inspection
// POSSIBLE PROPER BITWISE INVERSION XOR
void sometimes_inverted() {
    uint8_t not_flipped = data;
    uint8_t flipped = not_flipped ^ 255; // xor
    // UNDO ONLY: // flipped = not_flipped;
    data = flipped;
}
#endif // no hooks!

void update() { // low level driver
    // sometimes_inverted(); likely do NOT need to invert at all in the embedded
    // data of this sketch. the softserial 'already handles that' and acts as a
    // universal filter, most likely. anything sent to it (using regular
    // positive number notation) gets converted on the fly, is the guess here.

    connection.write(data);
    delay(1);
}

void prep_data_write() { // D18 %00010010 0x12
    assign_data(18);  update();
}

void local_lc_init() {
    // COMMAND = 8 home w/out Clearing Top
    // Case 8 serout MONITOR,BAUD,(%00010001,%10000000) D17, D128
    assign_data(17);  update(); // 0x11
    assign_data(128); update(); // 0x80

    // COMMAND = 1 GOTO Top Display
    // Case 1 serout MONITOR,BAUD,($12)  %00010010  D18
    assign_data(18);  update();
}

void strobe_like_a_dash_do() {
    int roof  = 65 + 26 + 1; // 'A' to 'Z' (intended)
    int floor = 65;
    prep_data_write();
    for (uint8_t strobed = floor; strobed < roof; strobed++) {
        assign_data(strobed); update();
    }
    delay(2500);
}

void printing() {
    uint8_t selected_byte = 65;
    prep_data_write();
    for (int index = 15; index > 0; index--) {
        assign_data(selected_byte); update();
    }
    delay(2500);
    // optional:
    strobe_like_a_dash_do(); // run the gamut!
    delay(2500);
}

#define LCD_BAUD 9600 // 4800 2400 also considered
void setup() {
    Serial.begin(9600);
    connection.begin(LCD_BAUD);
    delay(1000);
    local_lc_init();
}

void loop() {
    printing();
}
// NIS version
// inbound to IDE 
