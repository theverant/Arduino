#include <HCSR04.h>
#include <Servo.h>

UltraSonicDistanceSensor
 distanceSensor(7, 6); // Initialize sensor that uses digital pins 7 and 6.

Servo myservo; // create servo instance

int dist;
int arc;

void setup() {
  Serial.begin(9600); // We initialize serial connection so that we could print values from sensor.
  myservo.attach(9); // create servo instance on pin 9
}

void loop() {
  // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
  dist = (distanceSensor.measureDistanceCm()); // this uses the HCSR04  ultrasonic library and assigns the value to dist
  if (dist >= 76) { // if dis is greater or equal to 76
    dist = 75; // change dist to 75 so it is never greater than 75
  }
  arc = map(dist, 2, 75, 180, 0); // arc value is a mapped value of dist, assigning values between 2-75 to new values 180-0
  myservo.write(arc); // send this new arc value to the motor
  Serial.println(arc); // write the arc value, so we know what it is
  delay(5);
}
