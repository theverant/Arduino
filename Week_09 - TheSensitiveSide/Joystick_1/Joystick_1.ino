/*
www.elegoo.com
2016.12.09
Modified by Theverant. 2020  COVID19 sucks!
*/

// Arduino pin numbers
const int SW_pin = 4; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

void setup() {
  pinMode(SW_pin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  Serial.print("Switch:  ");
  Serial.println(digitalRead(SW_pin)); 
  //println = print line and carriage return (next print command happens on new line)
  Serial.print("X-axis: ");
  Serial.println(analogRead(X_pin));
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n"); // /n is a carriage return. Two puts two empty line spaces between this block and the block in the next loop
  delay(10);
}