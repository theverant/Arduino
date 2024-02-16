#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(13, 12);  // Initialize sensor that uses digital pins 13 and 12.
const int bled = 11;
const int gled = 10;
const int yled = 9;
const int rled = 5;
const int wled = 3;

int dist;

void setup () {
  pinMode(bled, OUTPUT);
  pinMode(gled, OUTPUT);
  pinMode(yled, OUTPUT);
  pinMode(rled, OUTPUT);
  pinMode(wled, OUTPUT);
  Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
}

void loop () {
  // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
  dist = (distanceSensor.measureDistanceCm());
  if (dist > 50) {
    digitalWrite (wled, HIGH);
  } else {
    digitalWrite (wled, LOW);
  }
  if ((dist > 40) && (dist < 50)){
    digitalWrite (rled, HIGH);
  } else {
    digitalWrite (rled, LOW);
  }
  if ((dist > 30) && (dist < 40)){
    digitalWrite (yled, HIGH);
  } else {
    digitalWrite (yled, LOW);
  }
  if ((dist > 20) && (dist < 30)){
    digitalWrite (gled, HIGH);
  } else {
    digitalWrite (gled, LOW);
  }

  if ((dist > 10) && (dist < 20)){
    digitalWrite (bled, HIGH);
  } else {
    digitalWrite (bled, LOW);
  }
  Serial.print(dist);
  delay(100);
}
