// Includes the Servo library
#include <Servo.h>
#include <Arduino.h>

#define outputA 3
#define outputB 2
#define PIN_IN3 18
float counter = 0;
int aState;
int aLastState;
// Defines Tirg and Echo pins of the Ultrasonic Sensor
// const int trigPin = 10;
// const int echoPin = 11;
const int pingPin = 7;
float speedMul = 1;

// Variables for the duration and the distance
long duration;
int distance;

Servo myServo;  // Creates a servo object for controlling the servo motor

void setup() {
  // pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  // pinMode(echoPin, INPUT);   // Sets the echoPin as an Input
  // pinMode(pingPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(outputA), updateSpeedMul, CHANGE);
  // attachInterrupt(digitalPinToInterrupt(outputB), updateSpeedMul, CHANGE);
  Serial.begin(9600);
  myServo.attach(6);  // Defines on which pin is the servo motor attached
  // use TWO03 mode when PIN_IN1, PIN_IN2 signals are both LOW or HIGH in latch position.
  // encoderBtn = new EncoderButton(byte PIN_IN3);

  // register interrupt routine
}
void loop() {
  // rotates the servo motor from 15 to 165 degrees
  for (int i = 15; i <= 165; i++) {
    myServo.write(i);
    delay(30 * speedMul);
    distance = calculateDistance();  // Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree

    Serial.print(i);         // Sends the current degree into the Serial Port
    Serial.print(",");       // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    Serial.print(distance);  // Sends the distance value into the Serial Port
    Serial.print(".");       // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
  // Repeats the previous lines from 165 to 15 degrees
  for (int i = 165; i > 15; i--) {
    myServo.write(i);
    delay(30 * speedMul);
    distance = calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.println(".");
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

void updateSpeedMul() {
  aState = digitalRead(outputA);
  if (digitalRead(outputB) != aState) {
    counter+= 0.05;
    if(speedMul < 5.0) speedMul += 0.05;
  } else {
    counter-= 0.05;
    if(speedMul > 1.0) speedMul -= 0.05;
  }
  Serial.print("Position: ");
  Serial.println(counter);
  Serial.print("Speed Multiplier: ");
  Serial.println(speedMul);
}