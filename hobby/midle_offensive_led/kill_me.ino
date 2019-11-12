/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
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
#include <Keypad.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {30,31,32,33}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {34,35,36,37}; //connect to the column pinouts of the keypad

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("PUSH DA BUTTON");
  Serial.begin(9600);
}

void change_screen(char* first, char* second){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(first);
      lcd.setCursor(0, 1);
      lcd.print(second);
  }

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  //lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);
  
   char customKey = customKeypad.getKey();

   if(customKey == '1'){
      change_screen("PLEASE!!","KILL ME!!");
    }
    if(customKey == '2'){
      change_screen("LICKMAB","ALLS!!!");
    }
    if(customKey == '3'){
      change_screen("DONT BLAME ME","FOR BEING STUPID");
    }
    if(customKey == '4'){
      change_screen("tHiS IS nOt HArd","fUckFAce");
    }
    if(customKey == '5'){
      change_screen("I AM","ALIVEE!!!!!!");
    }
     if(customKey == '6'){
      change_screen("I would sell you","for a buck...");
    }
     if(customKey == '7'){
      change_screen("I am in here!","HELLO....");
    }
     if(customKey == '8'){
      change_screen("i -= -1","is the standard");
    }
    
  
  if (customKey){
    Serial.println(customKey);
  }
    
  
}
