/*
  LiquidCrystal Library - Hello World
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch prints "Hello World!" to the LCD
 and shows the time.
 
 No ᴉʇ poǝsu,ʇ' ʇɥɐʇ,s ɐ lᴉǝ˙  ┴ɥᴉs sʞǝʇɔɥ ʞlnƃǝp qʎ ┴ H Ǝ Λ Ǝ ɹ ∀ N ┴

 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int RsensorPin = A0;    // select the input pin for the potentiometer
int GsensorPin = A1;    // select the input pin for the potentiometer
int BsensorPin = A2;    // select the input pin for the potentiometer

int RsensorValue = 0;  // variable to store the value coming from the sensor
int GsensorValue = 0;  // variable to store the value coming from the sensor
int BsensorValue = 0;  // variable to store the value coming from the sensor

int rValue; //variable to store mapped value
int gValue;
int bValue;

int rLEDpin = 10;
int gLEDpin = 9;
int bLEDpin = 6;

void setup() {
  
  pinMode (rLEDpin, OUTPUT);
  pinMode (gLEDpin, OUTPUT);
  pinMode (bLEDpin, OUTPUT);  
  
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {

  RsensorValue = analogRead(RsensorPin);
  GsensorValue = analogRead(GsensorPin);
  BsensorValue = analogRead(BsensorPin);

  rValue = (RsensorValue/4);
  gValue = (GsensorValue/4);
  bValue = (BsensorValue/4);
  
  analogWrite (rLEDpin, rValue);
  analogWrite (gLEDpin, gValue);
  analogWrite (bLEDpin, bValue);

/*
//Serial sanity check™ 
Serial.print("R:");
Serial.print(rValue);
Serial.print(" | ");
Serial.print("G:");
Serial.print(gValue);
Serial.print(" | ");
Serial.print("B:");
Serial.println(bValue);
*/

  // Print to LCD
  //lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print("R:");
  lcd.print(rValue);
  lcd.setCursor(8, 0); 
  lcd.print("G:");
  lcd.print(gValue);
  lcd.setCursor(5, 1);
  lcd.print("B:");
  lcd.println(bValue);

// delay (2); //slow things down slightly

}









