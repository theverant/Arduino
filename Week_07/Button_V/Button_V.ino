/*
  Button V

  Fade LED up and down based on a defined step in values.

  The circuit:
  - LED attached from pin 11 to ground through 220 ohm resistor
  - pushbutton attached to pin 7 from +5V
  - pushbutton attached to pin 8 from +5V

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  Theverant, 2022.

  This example code is in the public domain.

  Built on Button and Fade examples.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
  
*/

// constants won't change. They're used here to set pin numbers:
const int upPin = 8;     // the number of the pushbutton pin
const int downPin = 7; // the number of the other pushbutton pin
const int ledPin =  11;      // the number of the LED pin


// variables will change:

int brightness = 50;  // how bright the LED is to start with
int brightStep = 5;   // the step between brightness changes

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
  if (digitalRead(upPin) == HIGH && brightness < 255) { // && adds the condition that brightness must also be less than 255
    brightness = brightness + brightStep; // this creates a new value of brightness (starting value) + brightStep
    Serial.println(brightness); // println means print the stated value to a new line
  }
  if (digitalRead(downPin) == HIGH && brightness > 0) {
    brightness = brightness - brightStep; // the -- command means "subtract 1 from the stored value"
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

  // set the brightness of pin 11:
  analogWrite(ledPin, brightness);
}
