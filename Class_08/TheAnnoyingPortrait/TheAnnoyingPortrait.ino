/*
  _____ _              _                           _                 ___           _             _ _
  |__   | |__   ___    /_\  _ __  _ __   ___  _   _(_)_ __   __ _    / _ \___  _ __| |_ _ __ __ _(_| |_
   / /\| '_ \ / _ \  //_\\| '_ \| '_ \ / _ \| | | | | '_ \ / _` |  / /_)/ _ \| '__| __| '__/ _` | | __|
  / /  | | | |  __/ /  _  | | | | | | | (_) | |_| | | | | | (_| | / ___| (_) | |  | |_| | | (_| | | |_
  \/   |_| |_|\___| \_/ \_|_| |_|_| |_|\___/ \__, |_|_| |_|\__, | \/    \___/|_|   \__|_|  \__,_|_|\__|
                                            |___/         |___/
     ________  ________  ________  ________  ________  ________  ________  ________  ________
    ╱        ╲╱    ╱   ╲╱        ╲╱    ╱   ╲╱        ╲╱        ╲╱        ╲╱    ╱   ╲╱        ╲
   ╱        _╱         ╱         ╱         ╱         ╱         ╱         ╱         ╱        _╱
  ╱       ╱╱         ╱        _╱╲        ╱        _╱        _╱         ╱         ╱╱       ╱
  ╲_____╱╱ ╲___╱____╱╲________╱  ╲______╱╲________╱╲____╱___╱╲___╱____╱╲__╱_____╱ ╲______╱
  🄯2021

*/

#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(12, 11);  // Initialize sensor that uses digital pins 12 and 11.
int dist; // create variable for distance measurement
const int toggleButton = 2; // our input button
int toggleState = 0; // create variable for storing button press
int toggle = 0; // create toggle state for turning input on and off
int indicator = 13; // create indicator light
int prevDist; // placeholder for previous distance
int zoom; // zoom level
;

void setup () {
  pinMode(toggleButton, INPUT);
  pinMode(indicator, OUTPUT);
  Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
}

void loop () {
  toggleState = digitalRead(toggleButton);
  // check if the pushbutton is pressed. If it is, the toggleButton is HIGH:
  if (toggleState == HIGH && toggle == 0) {
    toggle = 1;       //reverse toggleState
    toggleState = LOW; // push reading low until next cycle
    Serial.println(toggle);
  }
  if (toggleState == HIGH && toggle == 1) {
    toggle = 0;       //reverse toggleState
    toggleState = LOW; // push reading low until next cycle
    Serial.println(toggle);
  }
  if (toggle == 0) {
    digitalWrite(indicator, HIGH);
  } else {
    digitalWrite(indicator, LOW);
    distance();
  }

  // Serial.println(toggle);
  delay(250);
}

void distance () {
  prevDist = dist; // store previous distance reading
  dist = (distanceSensor.measureDistanceCm()); // take new reading
  if (dist >= prevDist) {
    zoom = ++zoom;
  }
    if (dist <= prevDist) {
    zoom = --zoom;
  }
  
  Serial.println(dist);
}
