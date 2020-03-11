// Modified example code from Circuit Basics
// https://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/

#include <dht.h>           // import the DHTLib Library for necessary functions
#include <LiquidCrystal.h> // import the pre-installed LiquidCrystal Library

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // connect Arduino to LCD Display (RS, E, D4, D5, D6, D7 are the LCD pins)

dht DHT;                   // create an instance of the dht class called DHT

#define DHT11_PIN A0       // analog pin A0 sensor is connected to

const int red_LED = 13;    // constant variable for the red LED

// the setup routine runs once when pressed reset
void setup(){
  lcd.begin(16, 2);         // initialize the interface to the LCD screen (16 col, 2 rows)
  pinMode(red_LED, OUTPUT); // initialize digital pin 13, red_LED as an output
}

// the loop routine runs over and over again forever
void loop(){
  DHT.read11(DHT11_PIN);      // read the temperature and humidity
  lcd.setCursor(0,0);         // place the cursor of the LCD Display on the first col on the first row
  lcd.print("Temp: ");        // print "Temp: " onto the LCD Display
  lcd.print(DHT.temperature); // print the detected temperature (in Celsius) from dht11 sensor to LCD Display
  lcd.print((char)223);       // print the degree sign onto the LCD Display
  lcd.print("C");             // print "C" (Celsius) onto the LCD Display
  lcd.setCursor(0,1);         // place the cursor of the LCD Display on the first col on the second row
  lcd.print("Humidity: ");    // print "Humidity: " onto the LCD Display
  lcd.print(DHT.humidity);    // print the detected humidity level from the dht11 sensor onto the LCD Display
  lcd.print("%");             // print "%" (percent) onto the LCD Display
  
  if (DHT.humidity < 30 || DHT.humidity > 50) { // if the humidity level is lower than 30 or higher than 50
    digitalWrite(red_LED, HIGH);   // turn the LED on by making voltage level HIGH (max PWR)
  } else {
    digitalWrite(red_LED, LOW);    // turn the red LED off by making voltage level LOW (GND)
  }
  
  delay(2000); // wait for 2 seconds 
}
