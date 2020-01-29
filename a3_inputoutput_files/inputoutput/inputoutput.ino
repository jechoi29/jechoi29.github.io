/*
  Analog input, analog output, serial output
  Example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/AnalogInOutSerial
*/

// constants will not change
// analog input pin that the photoresistor (LDR) is attached to
const int analogInLDRPin = A0;  
// analog output pin that the LED is attached to
const int analogOutPin = 9; 

// variables will change
// value read from the photoresistor (LDR)
int sensorValue = 0;
// value output to PWM (analog out) pin the LED is attached to
int outputValue = 0;        

// the setup routine runs once when you press reset
void setup() {
  // initialize serial communications at 9600 bps
  Serial.begin(9600);
  // initialize photoresistor (LDR) pin as an input
  pinMode(analogInLDRPin, INPUT);
  // initialize pin 9 as an output pin
  pinMode(analogOutPin, OUTPUT);
}

// the loop routine runs over and over again forever
void loop() {
  // read the analog input value or the photoresistor (LDR)
  sensorValue = analogRead(analogInLDRPin);
  
  // if it is dark, turn on blue LED
  if (sensorValue < 935 && sensorValue >= 54) {
    // turn on the blue LED (pin 9)
    digitalWrite(analogOutPin, HIGH);
    // indicate if it is dark to Serial Monitor
    // by printing a short message
    Serial.println("It is dark so LED on!"); 
  // but if it is light, fade LED
  } else {
    // map it to the range of the analog out (PWM pin)
    // sense range of values from 54 to 974
    // make LED from HIGH to LOW brightness
    outputValue = map(sensorValue, 54, 974, 255, 0);
    // change the analog out value to fade the blue LED's light
    analogWrite(analogOutPin, outputValue);
    // indicate if it is light to Serial Monitor
    // by printing a short message
    Serial.println("===It is light, fade LED!===");
  }
  
  // wait 10 milliseconds before looping again
  delay(10);
}
