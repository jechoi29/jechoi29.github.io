var serial; // variable to hold an instance of the serialport library
var portName = '/dev/tty.usbmodem14201' //name of my port
var dataarray = []; //some data stored coming in over serial!


function setup() {

  serial = new p5.SerialPort();       // make a new instance of the serialport library
  serial.on('list', printList);       // set a callback function for the serialport list event
  serial.on('connected', serverConnected); // callback for connecting to the server
  serial.on('open', portOpen);        // callback for the port opening
  serial.on('data', serialEvent);     // callback for when new data arrives
  serial.on('error', serialError);    // callback for errors
  serial.on('close', portClose);      // callback for the port closing

  serial.list();                      // list the serial ports
  serial.open(portName);              // open a serial port
  createCanvas(1450, 825);            // create a canvas with specified size
  background(0x08, 0x16, 0x40);       // set the color of the background
}

// get the list of ports:
function printList(portList) {
 // portList is an array of serial port names
 for (var i = 0; i < portList.length; i++) {
 // Display the list the console:
   print(i + " " + portList[i]);
 }
}

// use for debugging
// check server connection
function serverConnected() {
  print('connected to server.');
}

// use for debugging
// check and print serial port open status
function portOpen() {
  print('the serial port opened.')
}

// use for debugging
// check and print serial port error
function serialError(err) {
  print('Something went wrong with the serial port. ' + err);
}

// use for debugging
// check and print serial port closed status
function portClose() {
  print('The serial port closed.');
}

// run when key is pressed
function keyPressed() {
  // send the key byte value to serial port
  serial.write(key);
}

// assign dataarray values from the serialEvent read in values
// (x and y values from the joystick sensor)
// dataarray[0] is the x value from the joystick
// dataarray[1] is the y value from the joystick
// because serial data from arduino was formatted
// like this '[x, y]'
function serialEvent() {
  if (serial.available()) { // if there is a serial data
    var datastring = serial.readLine(); // read in one line of the serial
    var newarray; // create an array
    try { // try parsing through the serial data in form of a string
      newarray = JSON.parse(datastring);
    } catch(err) { // if not, catch the error
        console.log(err);
    }
    // if it is a new array object being read,
    // assign the dataarrary to the newarray
    if (typeof(newarray) == 'object') {
      dataarray = newarray;
    }
    // print to console the datastring
    console.log("got back " + datastring);
  }
}

// draw on the webpage
function draw() {
  // set the background of the webpage
  background("#FFFFFF");
  // draw an ellipse (cirlce) according
  // to the movement of the joystick (100px by 100px)
  ellipse(dataarray[0], dataarray[1], 100, 100);

  // if x value of the joystick is 0,
  // change the background to blue
  if (dataarray[0] == 0) {
    // set background of webpage
    // to a blue hue hexcode
    background("#4357AD");
  }
  // else if x value of the joystick is 1023,
  // change the background to red
  else if (dataarray[0] == 1023) {
    // set background of webpage
    // to a red hue hexcode
    background("#F45B69");
    // send the key byte value
    // (javascript event code for a space)
    // to serial port
    serial.write(32);
  }
  // else if x value of the joystick is 0,
  // change the background to yellow
  else if (dataarray[1] == 0) {
    // set background of webpage
    // to a yellow hue hexcode
    background("#FCFC62");
  }
  // else if y value of the joystick is 1023,
  // change the background to green
  else if (dataarray[1] == 1023) {
    // set background of webpage
    // to a green hue hexcode
    background("#8ED081");
  }
}
