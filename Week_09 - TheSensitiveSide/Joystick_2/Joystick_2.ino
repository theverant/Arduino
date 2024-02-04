/*
  This mash up uses
    ShiftRegister74HC595 - Library for simplified control of 74HC595 shift registers.
    Developed and maintained by Timo Denk and contributers, since Nov 2014.
    Additional information is available at https://timodenk.com/blog/shift-register-arduino-library/
    Released into the public domain.
  

*/

#include <ShiftRegister74HC595.h>

// create a global shift register object
// parameters: <number of shift registers> (data pin, clock pin, latch pin)
ShiftRegister74HC595<1> sr(8, 9, 10);

const int SW_pin = 4; // digital pin connected to switch output
const int VRx_pin = 0; // analog pin connected to X output
const int VRy_pin = 1; // analog pin connected to Y output

int LEDpos, joyPos;

void setup() {
  pinMode(SW_pin, INPUT_PULLUP);
  Serial.begin(9600);
  LEDpos = 3;
}

void loop() {
  joyPos = analogRead(VRy_pin); // use VRy or VRx depending on which way the joystick is oriented
  joyPos = map(joyPos, 0, 1023, 1023, 0); // Invert the reading from the joystick comment/uncomment out this line as needed.

  if (joyPos > 525) {
    LEDpos = --LEDpos ;
    delay(150);
  } else {
    if (joyPos < 450) {
      LEDpos = ++LEDpos ;
    }
  }

  if (LEDpos == 8) {
    LEDpos = 7;
  }

  if (LEDpos < 0) {
    LEDpos = 0;
  }

if (digitalRead(SW_pin) == LOW) { // Read the button state
  sr.setAllLow();
  LEDpos = 3; //reset LED position
}

  // setting single pins - single moving light!
  sr.setAllLow(); // set all pins LOW
  sr.set(LEDpos, HIGH); // set single pin HIGH
  delay(150);
  //Serial.print (pos);
  //Serial.print("\n");
  Serial.print (joyPos);
  //Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  //Serial.print (lastPos);
}