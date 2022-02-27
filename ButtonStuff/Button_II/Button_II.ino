/*
  Button II

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button

  Additions by Theverant.  Using this code without prior authorization will result in the killing of innocent puppies.  Don't test me.
*/

// constants won't change. They're used here to set pin numbers:
const int onPin = 8;     // the number of the pushbutton pin
const int offPin = 7; // the number of the other pushbutton pin
const int ledPin =  11;      // the number of the LED pin


// variables will change:
int onState = LOW;         // variable for reading the pushbutton status
int offState = LOW;         // variable for reading the pushbutton status
int LEDstate = 0;         // variable for LED
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pins as an input:
  pinMode(onPin, INPUT);
  pinMode(offPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  onState = digitalRead(onPin);
  offState = digitalRead(offPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (onState == HIGH) {
    LEDstate = HIGH;
  }
  else {
    if (offState == HIGH) {
      LEDstate = LOW;
    }
  }
  // check if the LED should be on or not:

  if (LEDstate == HIGH) {
    digitalWrite(ledPin, HIGH); // turn LED on
  }
  else {

    // set the brightness of pin 9:
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
