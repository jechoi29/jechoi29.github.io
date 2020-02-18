// imports the IR remote library
// to access necessary functions
#include <IRremote.h>

// constant variable for the IR receiver (sensor)
// that is connected to pin 7
const int RECV_PIN = 7;
// constructs an irrecv object
IRrecv irrecv(RECV_PIN);
// creates a variable to store IR receiver results 
decode_results results;
// analog PWM pin the blue LED attaches to
const int blueLED = 5;    
// analog PWM pin the LED strip attaches to
const int LEDstrip = 9;

// the setup routine runs once when pressed reset
void setup(){
  // initialize serial communications at 9600 bps
  Serial.begin(9600);
  // allows the IR receiver to start the receiving process
  irrecv.enableIRIn();
  // controls the light on the ardiuno and
  // indicates whether the receiver detects a signal
  irrecv.blink13(true);
  // initialize the blue LED (pin 5) as an output pin
  pinMode(blueLED, OUTPUT);
  // initialize the LED strip (pin 9) as an output pin
  pinMode(LEDstrip, OUTPUT);
}

// the loop routine runs over and over again forever
void loop(){
  // if IR code is received (returns true),
  // executes and stores IR code in results;
  // if IR code is not received (returns false),
  // does not execute
  if (irrecv.decode(&results)){
    // prints IR code as HEX to Serial Monitor
    // for troubleshooting purposes
    Serial.println(results.value, HEX);
    // checks if IR code HEX is equal to the HEX
    // that corresponds to "0", turns lights off
    if (results.value == 0xFF6897) {
      // turns off blue LED
      digitalWrite(blueLED, LOW);
      // turns off LED strip
      digitalWrite(LEDstrip, LOW);
    }
    // checks if IR code HEX is equal to the HEX
    // that corresponds to "1", turns lights on
    if (results.value == 0xFF30CF) {
      // turns on blue LED
      digitalWrite(blueLED, HIGH);
      // turns on LED strip
      digitalWrite(LEDstrip, HIGH);
    }
    // checks if IR code HEX is equal to the HEX
    // that corresponds to "2", blink lights
    if (results.value == 0xFF18E7) {
      // turns on blue LED
      digitalWrite(blueLED, HIGH);
      // turns on LED strip
      digitalWrite(LEDstrip, HIGH);
      // wait for 500 milliseconds
      delay(500);
      // turns off blue LED
      digitalWrite(blueLED, LOW);
      // turns off LED strip
      digitalWrite(LEDstrip, LOW);
      // wait for 500 milliseconds
      delay(500);
    }
    // checks if IR code HEX is equal to the HEX
    // that corresponds to "3", fade lights
    if (results.value == 0xFF7A85) {
      // turn on blue LED and LED strip,
      // use a loop to decreases the brightness
      // of the LED by 5, which shows the fade effect
      for (int bright = 255; bright >= 0; bright-=5) {
        // blue LED's brightness decreases by 5
        analogWrite(blueLED, bright);
        // LED strip's brightness decreases by 5
        analogWrite(LEDstrip, bright);
        // wait for 25 milliseconds 
        delay(25);
      }
     }
    // resets the receiver to detect 
    // another signal IR code
    irrecv.resume();
  }
}
