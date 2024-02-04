/*
  ▄████▄   ▒█████   ██▓     ▒█████   █    ██  ██▀███      ███▄ ▄███▓ ██▓▒██   ██▒▓██   ██▓▄▄▄█████▓ ▒█████   █     █░███▄    █ 
▒██▀ ▀█  ▒██▒  ██▒▓██▒    ▒██▒  ██▒ ██  ▓██▒▓██ ▒ ██▒   ▓██▒▀█▀ ██▒▓██▒▒▒ █ █ ▒░ ▒██  ██▒▓  ██▒ ▓▒▒██▒  ██▒▓█░ █ ░█░██ ▀█   █ 
▒▓█    ▄ ▒██░  ██▒▒██░    ▒██░  ██▒▓██  ▒██░▓██ ░▄█ ▒   ▓██    ▓██░▒██▒░░  █   ░  ▒██ ██░▒ ▓██░ ▒░▒██░  ██▒▒█░ █ ░█▓██  ▀█ ██▒
▒▓▓▄ ▄██▒▒██   ██░▒██░    ▒██   ██░▓▓█  ░██░▒██▀▀█▄     ▒██    ▒██ ░██░ ░ █ █ ▒   ░ ▐██▓░░ ▓██▓ ░ ▒██   ██░░█░ █ ░█▓██▒  ▐▌██▒
▒ ▓███▀ ░░ ████▓▒░░██████▒░ ████▓▒░▒▒█████▓ ░██▓ ▒██▒   ▒██▒   ░██▒░██░▒██▒ ▒██▒  ░ ██▒▓░  ▒██▒ ░ ░ ████▓▒░░░██▒██▓▒██░   ▓██░
░ ░▒ ▒  ░░ ▒░▒░▒░ ░ ▒░▓  ░░ ▒░▒░▒░ ░▒▓▒ ▒ ▒ ░ ▒▓ ░▒▓░   ░ ▒░   ░  ░░▓  ▒▒ ░ ░▓ ░   ██▒▒▒   ▒ ░░   ░ ▒░▒░▒░ ░ ▓░▒ ▒ ░ ▒░   ▒ ▒ 
  ░  ▒     ░ ▒ ▒░ ░ ░ ▒  ░  ░ ▒ ▒░ ░░▒░ ░ ░   ░▒ ░ ▒░   ░  ░      ░ ▒ ░░░   ░▒ ░ ▓██ ░▒░     ░      ░ ▒ ▒░   ▒ ░ ░ ░ ░░   ░ ▒░
░        ░ ░ ░ ▒    ░ ░   ░ ░ ░ ▒   ░░░ ░ ░   ░░   ░    ░      ░    ▒ ░ ░    ░   ▒ ▒ ░░    ░      ░ ░ ░ ▒    ░   ░    ░   ░ ░ 
░ ░          ░ ░      ░  ░    ░ ░     ░        ░               ░    ░   ░    ░   ░ ░                  ░ ░      ░            ░ 
░                                                                                ░ ░                                          



    .....                                    _                                                                s    
 .H8888888h.  ~-.    .uef^"                 u                                                                :8    
 888888888888x  `> :d88E                   88Nu.   u.                .u    .                  u.    u.      .88    
X~     `?888888hx~ `888E            .u    '88888.o888c      .u     .d88B :@8c        u      x@88k u@88c.   :888ooo 
'      x8.^"*88*"   888E .z8k    ud8888.   ^8888  8888   ud8888.  ="8888f8888r    us888u.  ^"8888""8888" -*8888888 
 `-:- X8888x        888E~?888L :888'8888.   8888  8888 :888'8888.   4888>'88"  .@88 "8888"   8888  888R    8888    
      488888>       888E  888E d888 '88%"   8888  8888 d888 '88%"   4888> '    9888  9888    8888  888R    8888    
    .. `"88*        888E  888E 8888.+"      8888  8888 8888.+"      4888>      9888  9888    8888  888R    8888    
  x88888nX"      .  888E  888E 8888L       .8888b.888P 8888L       .d888L .+   9888  9888    8888  888R   .8888Lu= 
 !"*8888888n..  :   888E  888E '8888c. .+   ^Y8888*""  '8888c. .+  ^"8888*"    9888  9888   "*88*" 8888"  ^%888*   
'    "*88888888*   m888N= 888>  "88888%       `Y"       "88888%       "Y"      "888*""888"    ""   'Y"      'Y"    
        ^"***"`     `Y"   888     "YP'                    "YP'                  ^Y"   ^Y'                          
                         J88"                                                                                      
                         @%                                                                                        
                       :"                                                                                          

🄯2022 - copyleft




*/

#include <LiquidCrystal.h> // LCD library

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 13, en = 12, d4 = 11, d5 = 8, d6 = 7, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Rotary Encoder Inputs
#define CLK 2
#define DT 3
#define SW 4


//LED Pins

const int rPin = 10;
const int gPin = 9;
const int bPin = 6;

int counter = 0;
int currentStateCLK;
int lastStateCLK;
int rValue = 50;
int gValue = 50;
int bValue = 50;
String currentDir = "";
unsigned long lastButtonPress = 0;
int buttonCounter = 1;



void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  //Set LED pins
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);

  // Set encoder pins as inputs
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);

  // Setup Serial Monitor
  Serial.begin(9600);

  // set first numbers
  lcd.setCursor(1, 0);
  lcd.print("R:");
  lcd.print(rValue);
  lcd.setCursor(9, 0);
  lcd.print("G:");
  lcd.print(gValue);
  lcd.setCursor(1, 1);
  lcd.print("B:");
  lcd.print(bValue);


  // Read the initial state of CLK
  lastStateCLK = digitalRead(CLK);
}

void loop() {

  //Red Adjustments
  if (buttonCounter == 1) {

    // Read the current state of CLK
    currentStateCLK = digitalRead(CLK);

    // If last and current state of CLK are different, then pulse occurred
    // React to only 1 state change to avoid double count
    if (currentStateCLK != lastStateCLK  && currentStateCLK == 1) {

      // If the DT state is different than the CLK state then
      // the encoder is rotating CCW so decrement
      if (digitalRead(DT) != currentStateCLK) {
        rValue --;

      } else {
        // Encoder is rotating CW so increment
        rValue ++;

      }
      if (rValue >= 255) {
        rValue = 255;
      }
      if (rValue <= 0) {
        rValue = 0;
      }

      // FIX NUMBA SPILL
      if (rValue >= 255) {
        rValue = 255;
      }
      
      if (rValue <= 0) {
        rValue = 0;
      }
      
      Serial.print("rValue: ");
      Serial.println(rValue);
      // LCD STUUUUFFF
      // set the cursor to column 0, line 1
      // (note: line 1 is the second row, since counting begins with 0):
      //   lcd.clear() ;

      //print values
      lcd.setCursor(1, 0);
      lcd.print("     ");
      lcd.setCursor(1, 0);
      lcd.print("R:");
      lcd.print(rValue);

    }
    // R Marker
    lcd.setCursor(0, 0);
    lcd.print(">");
    lcd.setCursor(8, 0);
    lcd.print(" ");
    lcd.setCursor(0, 1);
    lcd.print(" ");
    // Remember last CLK state
    lastStateCLK = currentStateCLK;
  }

  // ADJUST GREEN VALUE
  if (buttonCounter == 2) {
    // Read the current state of CLK
    currentStateCLK = digitalRead(CLK);

    // If last and current state of CLK are different, then pulse occurred
    // React to only 1 state change to avoid double count
    if (currentStateCLK != lastStateCLK  && currentStateCLK == 1) {

      // If the DT state is different than the CLK state then
      // the encoder is rotating CCW so decrement
      if (digitalRead(DT) != currentStateCLK) {
        gValue --;

      } else {
        // Encoder is rotating CW so increment
        gValue ++;

      }
      // FIX NUMBA SPILL
      if (gValue >= 255) {
        gValue = 255;
      }
      
      if (gValue <= 0) {
        gValue = 0;
      }


      // LCD STUUUUFFF
      // set the cursor to column 0, line 1
      // (note: line 1 is the second row, since counting begins with 0):

      // UFT
      //  lcd.clear() ;

      // We all need values

      lcd.setCursor(9, 0);
      lcd.print("     ");
      lcd.setCursor(9, 0);
      lcd.print("G:");
      lcd.print(gValue);

    }

    // Serial.print("gValue: ");
    // Serial.println(gValue);
    //chuck that triangle on the r-dud
    lcd.setCursor(8, 0);
    lcd.print(">");
    lcd.setCursor(0, 1);
    lcd.print(" ");
    lcd.setCursor(0, 0);
    lcd.print(" ");
    // Remember last CLK state
    lastStateCLK = currentStateCLK;
  }

  // BLUE PERIOD
  if (buttonCounter == 3) {

    // Read the current state of CLK
    currentStateCLK = digitalRead(CLK);

    // If last and current state of CLK are different, then pulse occurred
    // React to only 1 state change to avoid double count
    if (currentStateCLK != lastStateCLK  && currentStateCLK == 1) {

      // If the DT state is different than the CLK state then
      // the encoder is rotating CCW so decrement
      if (digitalRead(DT) != currentStateCLK) {
        bValue --;

      } else {
        // Encoder is rotating CW so increment
        bValue ++;

      }

            // FIX NUMBA SPILL
      if (bValue >= 255) {
        bValue = 255;
      }
      
      if (bValue <= 0) {
        bValue = 0;
      }
      
      Serial.print("bValue: ");
      Serial.println(bValue);
      // LCD STUUUUFFF
      //lcd.clear() ;

      lcd.setCursor(1, 1);
      lcd.print("     ");
      lcd.setCursor(1, 1);
      lcd.print("B:");
      lcd.print(bValue);

    }
    //chuck that triangle on the bloo
    lcd.setCursor(0, 1);
    lcd.print(">");
    lcd.setCursor(8, 0);
    lcd.print(" ");
    lcd.setCursor(0, 0);
    lcd.print(" ");


    // Remember last CLK state
    lastStateCLK = currentStateCLK;
  }


  // CLICKING BUTTON CHANGES SELECTION
  int btnState = digitalRead(SW);

  //If we detect LOW signal, button is pressed
  if (btnState == LOW) {
    //if 50ms have passed since last LOW pulse, it means that the
    //button has been pressed, released and pressed again
    if (millis() - lastButtonPress > 1000) {
      buttonCounter ++;
      if (buttonCounter == 4) {
        buttonCounter = 1;

       // Serial.print("button counter: ");
       // Serial.println(buttonCounter);
      }

      // Remember last button press event
      lastButtonPress = millis();
    }

    // Put in a slight delay to help#include <LiquidCrystal.h> // LCD library
    delay(2);

  }

  //GLOW THAT LED
  analogWrite(rPin, rValue);
  analogWrite(gPin, gValue);
  analogWrite(bPin, bValue);

}
