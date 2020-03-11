// Modified example code from Circuit Basics
// https://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/

// import the DHTLib Library
// to access necessary functions
#include <dht.h>
// import the LiquidCrystal Library
// to access necessary functions
// (pre-installed with the Arduino IDE)
#include <LiquidCrystal.h>

// set the pins the Arduino uses to
// connect to the LCD Display.
// RS, E, D4, D5, D6, D7 are the LCD pins
// RS is connected to pin 12
// E is connected to pin 11
// D4 is connected to pin 5 and so on...
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// create an instance of the dht class called DHT
dht DHT;

// analog pin A0 sensor is connected to
#define DHT11_PIN A0

// constant variable for the red LED,
// digital pin 13
const int red_LED = 13;

// the setup routine runs once when pressed reset
void setup(){
  // initialize the interface to the LCD screen,
  // specifying the dimensions (width and height)
  // of the display. The display has 16 columns and 2 rows
  lcd.begin(16, 2);
  // initialize digital pin 13, red_LED as an output
  pinMode(red_LED, OUTPUT);
}

// the loop routine runs over and over again forever
void loop(){
  // Read the temperature and humidity
  DHT.read11(DHT11_PIN);
  // place the cursor of the LCD Display on the
  // first column on the first row
  lcd.setCursor(0,0); 
  // print "Temp: " onto the LCD Display
  lcd.print("Temp: ");
  // print the detected temperature (in Celsius)
  // from the dht11 sensor onto the LCD Display
  lcd.print(DHT.temperature);
  // print the degree sign onto the LCD Display
  lcd.print((char)223);
  // print "C" (Celsius) onto the LCD Display
  lcd.print("C");
  // place the cursor of the LCD Display on the
  // first column on the second row
  lcd.setCursor(0,1);
  // print "Humidity: " onto the LCD Display
  lcd.print("Humidity: ");
  // print the detected humidity level from 
  // the dht11 sensor onto the LCD Display
  lcd.print(DHT.humidity);
  // print "%" (percent) onto the LCD Display
  lcd.print("%");
  // if the humidity level is
  // lower than 30 or higher than 50
  // turn on the LED, otherwise,
  // turn it off
  if (DHT.humidity < 30 || DHT.humidity > 50) {
    // turn the LED on by making
    // voltage level HIGH (max PWR)
    digitalWrite(red_LED, HIGH);   
  } else {
    // turn the red LED off by making
    // voltage level LOW (GND)
    digitalWrite(red_LED, LOW); 
  }
  // wait for 2 seconds 
  delay(2000);
}
