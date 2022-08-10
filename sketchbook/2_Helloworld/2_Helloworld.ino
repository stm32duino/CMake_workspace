/*
This sketch is just a simple "hello world", transposed to the world of Arduino.
It uses Serial to print "hello world" every second.
*/

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600); // Initialize the Serial connection. 9600 is the standard baud rate value for Arduino.
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("hello world"); // print "hello world" to the Serial console
  delay(1000); // wait 1000ms (1s)
}
