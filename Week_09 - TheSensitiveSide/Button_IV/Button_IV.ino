/*
  Button IV

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

  Additions by Theverant, 2020.  Using this code without prior authorization will result in the killing of innocent puppies.  Don't test me.
*/

// constants won't change. They're used here to set pin numbers:
const int upPin = 8;     // the number of the pushbutton pin
const int downPin = 7; // the number of the other pushbutton pin
const int ledPin =  11;      // the number of the LED pin


// variables will change:

int brightness = 50;    // how bright the LED is to start with

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pins as an input:
  pinMode(upPin, INPUT);
  pinMode(downPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (digitalRead(upPin) == HIGH && brightness < 255) {
  brightness = ++brightness; // the ++ command means "add 1 to the stored value"
  Serial.println(upPin); // println means print the stated value to a new line
}
if (digitalRead(downPin) == HIGH && brightness > 0) {
  brightness = --brightness; // the -- command means "subtract 1 from the stored value"
  Serial.println(brightness); // println means print the stated value to a new line
}

if (brightness < 0) { //check brightness and if it is below 0
  brightness = 0; // make brightness 0
}

if (brightness > 255) { //check brightness and if it is above 255
  brightness = 255; // make brightness 255
  } 

// wait for 30 milliseconds to see the dimming effect
delay(30);

// set the brightness of pin 9:
analogWrite(ledPin, brightness);
}
