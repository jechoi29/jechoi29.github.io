#include <LiquidCrystal.h> // import pre-installed LiquidCrystal Library

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // connect Arduino to LCD Display (RS, E, D4, D5, D6, D7 are the LCD pins)

void setup() { // the setup routine runs once when pressed reset
  lcd.begin(16, 2); // initialize the interface to the LCD screen (16 col, 2 rows)
  lcd.print("hello, world!"); // print "hello, world!" to LCD Display
}

void loop() {
  
}
