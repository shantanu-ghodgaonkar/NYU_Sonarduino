#include <Arduino.h>
#include <Servo.h>

#define inc 2
#define dec 3
#define stp 18
#define pingPin 7
#define servo 6
int speed = 15;
// Variables for the duration and the distance
long duration;
int distance;
int i;
Servo myServo;
void setup() {
  pinMode(servo, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(inc, INPUT);
  pinMode(dec, INPUT);
  pinMode(stp, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), printInc, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), printDec, FALLING);
  attachInterrupt(digitalPinToInterrupt(18), stop, FALLING);
  Serial.begin(9600);
  myServo.attach(servo);
}
void loop() {
  digitalWrite(13, HIGH);
  digitalWrite(4, HIGH);
  // rotates the servo motor from 15 to 165 degrees
  for (int i = 15; i <= 165; i++) {
    myServo.write(i);
    delay(speed);
    distance = calculateDistance();  // Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree

    Serial.print(i);         // Sends the current degree into the Serial Port
    Serial.print(",");       // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    Serial.print(distance);  // Sends the distance value into the Serial Port
    Serial.print(".");       // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
  // Repeats the previous lines from 165 to 15 degrees
  for (int i = 165; i > 15; i--) {
    myServo.write(i);
    delay(speed);
    distance = calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance() {

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  distance = duration / 29 / 2;
  return distance;
}

void printInc() {
  noInterrupts();
  Serial.println("INCREASE SPEED");
  if (speed > 5) speed -= 5;
  Serial.print("Current Speed: ");
  Serial.println(speed);
  delay(50);
  interrupts();
}
void printDec() {
  noInterrupts();
  Serial.println("DECREASE SPEED");
  if (speed < 30) speed+= 5;
  Serial.print("Current Speed: ");
  Serial.println(speed);
  delay(50);
  interrupts();
}

void stop() {
  while (1) {
    Serial.println("999,999.");
    delay(1000);
  }
}