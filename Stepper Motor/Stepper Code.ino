
/*
  original code found at
  https://lastminuteengineers.com/28byj48-stepper-motor-arduino-tutorial/
  modified for your pleasure by Theverant
  watch for the // notes in void loop() !!!
*/

// Includes the Arduino Stepper Library
#include <Stepper.h>

// Defines the number of steps per rotation
const int stepsPerRevolution = 2038;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // Nothing to do (Stepper Library sets pins as outputs)
}

void loop() {
  // Rotate CW slowly
  myStepper.setSpeed(1);

  /*
    "setSpeed" defines how many RPMs (rotations per minute) 1 RPM == one full
    turn this motor can have up to 17 RPM, but any higher and it WILL stall
    likewise, you will have a bad time if you try a number less than 1
  */

  myStepper.step(stepsPerRevolution);

  /*
    "step" defines how many steps one rotation takes.  this is dependant
    on the particular motor.  Consult the sheets for the device you are using!
  */

  delay(1000);

  // Rotate CCW quickly
  myStepper.setSpeed(17); // do not exceed 17 RPM for this motor!

  myStepper.step(-stepsPerRevolution);
  delay(1000);


  /*
      "step" defines how many steps one rotation takes.  this is dependant
      on the particular motor.  Consult the sheets for the device you are using!
  */

  delay(1000);


  // Rotate CCW quickly
  myStepper.setSpeed(17);  //do not exceed 17 RPM for this motor!

  myStepper.step(-stepsPerRevolution);
  delay(1000);
}


