//
//    FILE: ansi_performance.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: start of performance print statement.
//    DATE: 2021-12-13
//     URL: https://github.com/RobTillaart/ANSI
//    (c) : MIT
//


#include "ansi.h"

ANSI ansi(&Serial);

int t;
double d;

uint32_t start, stop;

void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.println(ANSI_LIB_VERSION);
  Serial.println();
  delay(100);

  start = micros();
  ansi.println("PERFORMANCE TEST ANSI TERMINAL PRINT");
  stop = micros();
  Serial.print("ANSITERM:\t");
  Serial.println(stop - start);
  delay(100);

  start = micros();
  Serial.println("PERFORMANCE TEST ANSI TERMINAL PRINT");
  stop = micros();
  Serial.print("SERIAL:\t\t");
  Serial.println(stop - start);
  Serial.println();
  delay(100);

  start = micros();
  ansi.clearScreen();
  stop = micros();
  Serial.print("ANSITERM:\t");
  Serial.println(stop - start);
  delay(100);

  start = micros();
  Serial.print("\033[2J\033[H");
  stop = micros();
  Serial.print("SERIAL:\t\t");
  Serial.println(stop - start);
  delay(100);

}

void loop()
{
}

// -- END OF FILE --
