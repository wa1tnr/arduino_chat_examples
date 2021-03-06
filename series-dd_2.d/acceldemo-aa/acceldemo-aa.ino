// Basic demo for accelerometer readings from Adafruit LIS3DH

#include <SPI.h>
#include <Wire.h>

#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_SPIDevice.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LIS3DH.h>

/** I2C ADDRESS/BITS **/
// #define LIS3DH_DEFAULT_ADDRESS (0x18) // if SDO/SA0 is 3V, its 0x19

// Used for software SPI
// #define LIS3DH_CLK 13
// #define LIS3DH_MISO 12
// #define LIS3DH_MOSI 11
// Used for hardware & software SPI
// #define LIS3DH_CS 10

// software SPI
//Adafruit_LIS3DH lis = Adafruit_LIS3DH(LIS3DH_CS, LIS3DH_MOSI, LIS3DH_MISO, LIS3DH_CLK);
// hardware SPI
//Adafruit_LIS3DH lis = Adafruit_LIS3DH(LIS3DH_CS);
// I2C

Adafruit_LIS3DH lis = Adafruit_LIS3DH();

void setup(void) {
  delay(800);

  pinMode(13, 1);
  delay(200);
  digitalWrite(13,1);  // LED GOES ON
  delay(200);
  digitalWrite(13,0);  // LED GOES OFF (tried it without OFF here, first)
  delay(200);

  Serial.begin(9600);

  delay(800);

  while(!Serial);

  delay(800);

  // while (!Serial); // delay(10);     // will pause Zero, Leonardo, etc until serial console opens


  Serial.println("10 Feb Thu 21:44z");

  Serial.println("here we go LIS3DH test!");

  lis.begin(0x19);

  digitalWrite(13,1); //  LED DOES NOT LIGHT








  // if (! lis.begin(0x19)) {   // change this to 0x19 for alternative i2c address

   Serial.println("Couldnt start");

   // while (1) yield();

  // }


  Serial.println("LIS3DH found!");

  // lis.setRange(LIS3DH_RANGE_4_G);   // 2, 4, 8 or 16 G!

  Serial.print("Range = "); Serial.print(2 << lis.getRange());

  Serial.println("G");

  // lis.setDataRate(LIS3DH_DATARATE_50_HZ);
  Serial.print("Data rate set to: ");
  switch (lis.getDataRate()) {
    case LIS3DH_DATARATE_1_HZ: Serial.println("1 Hz"); break;
    case LIS3DH_DATARATE_10_HZ: Serial.println("10 Hz"); break;
    case LIS3DH_DATARATE_25_HZ: Serial.println("25 Hz"); break;
    case LIS3DH_DATARATE_50_HZ: Serial.println("50 Hz"); break;
    case LIS3DH_DATARATE_100_HZ: Serial.println("100 Hz"); break;
    case LIS3DH_DATARATE_200_HZ: Serial.println("200 Hz"); break;
    case LIS3DH_DATARATE_400_HZ: Serial.println("400 Hz"); break;

    case LIS3DH_DATARATE_POWERDOWN: Serial.println("Powered Down"); break;
    case LIS3DH_DATARATE_LOWPOWER_5KHZ: Serial.println("5 Khz Low Power"); break;
    case LIS3DH_DATARATE_LOWPOWER_1K6HZ: Serial.println("16 Khz Low Power"); break;
  }
}

void loop() {
  lis.read();      // get X Y and Z data at once
  // Then print out the raw data
  Serial.print("X:  "); Serial.print(lis.x);
  Serial.print("  \tY:  "); Serial.print(lis.y);
  Serial.print("  \tZ:  "); Serial.print(lis.z);

  /* Or....get a new sensor event, normalized */
  sensors_event_t event;
  lis.getEvent(&event);

  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("\t\tX: "); Serial.print(event.acceleration.x);
  Serial.print(" \tY: "); Serial.print(event.acceleration.y);
  Serial.print(" \tZ: "); Serial.print(event.acceleration.z);
  Serial.println(" m/s^2 ");

  Serial.println();

  delay(200);
}
