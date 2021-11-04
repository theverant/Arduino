/*
  Continuity Checker - Based on ^Button^
    A stupid simple program developed by Theverant
    Check whether your circuit connections connect!

  RED == NO CONNECT
  GREEN == THINGS CONNECT!!

*/

// constants won't change. They're used here to set pin numbers:
const int sensorPin = 10; // the number of the pushbutton pin
const int greenPin = 3;   // the number of "Connect" the LED pin
const int redPin = 5; // the number of the "No Connect" LED pin

// variables will change:
int sensorState = LOW; // variable for reading the pushbutton status

void setup() {
  // initialize the LED pins as outputs:
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  // initialize the sensor pin as an input:
  pinMode(sensorPin, INPUT_PULLUP);
}

void loop() {
  // read the state of the pushbutton value:
  sensorState = digitalRead(sensorPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (sensorState == HIGH) {
    // turn LED on:
    digitalWrite(greenPin, LOW);
  } else {
    // turn LED off:
    analogWrite(greenPin, 125);
  }
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (sensorState == HIGH) {
    // turn LED on:
    analogWrite(redPin, 125);
  } else {
    // turn LED off:
    digitalWrite(redPin, LOW);
  }

}
