/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fade
*/

// constants will not change
const int ledFade = 9;    // the PWM pin the LED is attached to
const int buttonPin = 2;  // the number of the pushbutton pin

// variable will change
int buttonState = 0;   // variable for reading the pushbutton status

// the setup routine runs once when you press reset
void setup() {
  // initialize the pushbutton pin as an input
  pinMode(buttonPin, INPUT);
  
  // use a loop to initialize each pin as an output
  for (int thisPin = 7; thisPin <= 9; thisPin++) {
    // declare pin 7, 8, and 9 to be an output
    pinMode(thisPin, OUTPUT);
  }
}

// the loop routine runs over and over again forever
void loop() {
  // read the status of the pushbutton's value
  buttonState = digitalRead(buttonPin);
  
  // check if the pushbutton is pressed (on HIGH)
  if (buttonState == HIGH) {
    
    // use a loop to turn on digital LEDs
    for (int thisPin = 7; thisPin < 9; thisPin++) {
      // turn on pin 7 and 8
      digitalWrite(thisPin, HIGH);
      // wait 500 milliseconds
      delay(500);
    }

    // turn on the analog LED, use a loop to increase the
    // brightness of the LED of pin 9 by 1 (this LED will
    // show the fade effect)
    for (int brightness = 0; brightness <= 255; brightness++) {
      // analog LED's brightness increases by 1
      analogWrite(ledFade, brightness);
      // wait for 10 milliseconds 
      delay(10);
    }
    
    // wait for 30 milliseconds to see the dimming effect
    delay(30);

  // if button is not pressed (on LOW), turn off pins or
  // leave them off  
  } else {
    // use a loop to turn off all LEDs
    for (int thisPin = 9; thisPin >= 7; thisPin--) {
      // turn off pin 9, 8, and 7 in this order
      digitalWrite(thisPin, LOW);
      // wait for 500 milliseconds
      delay(500);
    }
  }
}
