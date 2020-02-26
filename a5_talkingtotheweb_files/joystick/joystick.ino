// constant variable for the x joystick sensor
const int x = A0;    
// constant variable for the y joystick sensor
const int y = A1;

// x value will change depending on
// the joystick movement in x
int xval = 0;
// y value will change depending on
// the joystick movement in y
int yval = 0;

// the setup routine runs once when pressed reset
void setup() {
  // initialize serial communications at 9600 bps
  Serial.begin(9600); 
}

// the loop routine runs over and over again forever
void loop() {
  // reads in the state of the x joystick sensor
  xval = analogRead(x);
  // reads in the state of the y joystick sensor
  yval = analogRead(y);

  // sends an array format to serial
  // for p5.js to read
  // prints starting bracket to serial
  Serial.print("[");
  // prints x joystick sensor state to serial
  Serial.print(xval);
  // prints a comma with a space to serial
  Serial.print(", ");
  // prints y joystick sensor state to serial
  Serial.print(yval);
  // prints closing bracket with a new line to serial
  Serial.println("]");
}
