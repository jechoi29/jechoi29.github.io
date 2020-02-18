/*
  Blink

  Turns on LEDs, repeatedly (modified example code that is in the public domain).

  http://www.arduino.cc/en/Tutorial/Blink
  
  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman
*/


/* 
  The setup function runs once when you press reset or power the board.
*/
void setup() {
  // initialize digital pin 12 LED_BUILTIN as an output
  pinMode(12, OUTPUT);
  // initialize digital pin 10 LED_BUILTIN as an output
  pinMode(10, OUTPUT);
  // initialize digital pin 8 LED_BUILTIN as an output
  pinMode(8, OUTPUT);
  // initialize digital pin 6 LED_BUILTIN as an output
  pinMode(6, OUTPUT);
}

/*
  The loop function runs over and over again forever.
  Turns on individual LEDs, then turns each LED off.
*/
void loop() {
  /*
    Turn individual LEDs on (by making voltage level HIGH)
    operation pattern turns on pin 12, 8, 10, then 6.
  */
  
  // turn the LED on pin 12
  digitalWrite(12, HIGH);
  // wait for half a second (500ms)
  delay(500);     
  // turn the LED on pin 8       
  digitalWrite(8, HIGH);
  // wait for half a second (500ms)
  delay(500);
  // turn the LED on pin 10              
  digitalWrite(10, HIGH); 
  // wait for half a second (500ms)  
  delay(500);         
  // turn the LED on pin 6
  digitalWrite(6, HIGH); 
  // wait for half a second (500ms)    
  delay(500);               

  /* 
    Once individual LEDs are on, turn pins off (by making voltage level LOW)
    in descending order pin 12 to 6. 
  */
  
  // turn the LED off pin 12
  digitalWrite(12, LOW);
  // wait for quarter of a second (250ms)   
  delay(250);   
  // turn the LED off pin 10          
  digitalWrite(10, LOW);    
  // wait for quarter of a second (250ms)
  delay(250);   
  // turn the LED off pin 8
  digitalWrite(8, LOW);   
  // wait for quarter of a second (250ms)
  delay(250);               
  // turn the LED off pin 6
  digitalWrite(6, LOW);  
  // wait for quarter of a second (250ms)
  delay(250);               
}
