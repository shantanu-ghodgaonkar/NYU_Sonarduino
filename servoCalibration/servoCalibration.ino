/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

// #include <Servo.h>

// Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards


void setup() {
  Serial.begin(9600);
}

void loop() {
  digitalWrite(6, HIGH);
  delayMicroseconds (1500);
  digitalWrite(6, LOW);
  delay(20);
}
