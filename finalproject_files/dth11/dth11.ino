#include <dht.h> // import DHTLib Library

#define DHT11_PIN A0 // analog pin sensor is connected

dht DHT; // create an instance of dht class 

void setup(){ // the setup routine runs once when pressed reset
  Serial.begin(9600); // initialize serial communications at 9600 bps
  Serial.println("DHT11 Humidity & Temperature Sensor"); // print to serial monitor
  delay(1000); // wait before accessing the sensor
}

void loop(){ // the loop routine runs over and over again forever
  DHT.read11(DHT11_PIN); // read the temperature and humidity
  Serial.print("Temp: "); // print "Temp: " to serial monitor
  Serial.print(DHT.temperature); // print temperature detected from the sensor to serial monitor
  Serial.print("C "); // print "C " to serial monitor
  Serial.print("Humidity: "); // print "Humidity: " to serial monitor
  Serial.print(DHT.humidity); // print humidity detected from sensor to serial monitor
  Serial.println("% "); // print to serial monitor
  delay(3000); // wait 3 seconds
}
