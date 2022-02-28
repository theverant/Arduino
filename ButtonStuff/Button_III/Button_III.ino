/*
  Button III

  Turns on light emitting diode(LED) connected to digital pin 11,
  LED being fading when pressing button attached to pin 7.
  Pressing pushbutton attached to pin 8 resets LED to solid state.

  The circuit:
  - LED attached from pin 11 to ground through 220 ohm resistor
  - pushbutton attached to pin 7 from +5V
  - pushbutton attached to pin 8 from +5V

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  Based on the Button and fade examples.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button

  Kludge by Theverant, 2022.
*/

// constants won't change. They're used here to set pin numbers:
const int resetPin = 8;     // the number of the pushbutton pin
const int fadePin = 7; // the number of the other pushbutton pin
const int ledPin =  11;      // the number of the LED pin


// variables will change:
int resetState = HIGH;         // variable for reading the pushbutton status
int fadeState = LOW;         // variable for reading the pushbutton status
int LEDstate = 0;         // variable for LED
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pins as an input:
  pinMode(resetPin, INPUT);
  pinMode(fadePin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  resetState = digitalRead(resetPin);
  fadeState = digitalRead(fadePin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (resetState == HIGH) {
    LEDstate = HIGH;
  }
  else {
    if (fadeState == HIGH) {
      LEDstate = LOW;
    }
  }
  // check if the LED should be on or not:

  if (LEDstate == HIGH) {
    digitalWrite(ledPin, HIGH); // turn LED on
  }
  else {
    if (LEDstate == LOW) {

      // set the brightness of pin 11:
      analogWrite(ledPin, brightness);

      // change the brightness for next time through the loop:
      brightness = brightness + fadeAmount;

      // reverse the direction of the fading at the ends of the fade:
      if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
      }
      // wait for 30 milliseconds to see the dimming effect
      delay(30);
    } // turn LED off
  }
}
