// #include <Arduino.h>

#define outputA 2
#define outputB 3
#define btn 18
int counter = 0;
int aState;
int btnState;
unsigned long lastButtonPress = 0;

// Defines Tirg and Echo pins of the Ultrasonic Sensor
// const int trigPin = 10;
// const int echoPin = 11;
#define pingPin 7
#define servo 6
const int iMax = 40;
// Variables for the duration and the distance
long duration;
int distance;
int i;

void setup() {
  pinMode(servo, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
  pinMode(outputA, INPUT);
  pinMode(outputB, INPUT);
  pinMode(13, OUTPUT);
  pinMode(4, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(outputA), updateCounter, CHANGE);
  attachInterrupt(digitalPinToInterrupt(btn), buttonClicked, LOW);
  Serial.begin(9600);
}
void loop() {
  // rotates the servo motor from 15 to 165 degrees
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  
  Serial.print(i); // Sends the current degree into the Serial Port
  Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(distance); // Sends the distance value into the Serial Port
  Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
  // Repeats the previous lines from 165 to 15 degrees
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
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

void updateCounter() {
  aState = digitalRead(outputA);
  if (digitalRead(outputB) != aState) {
      if(counter <50 )counter++;
  } else {
    if (counter>-50)counter--;
  }
  Serial.print("Position: ");
  Serial.println(counter);
}

void buttonClicked() {  //ADD CODE FOR EMERGENCY STOP
  btnState = digitalRead(btn);
  if (btnState == LOW) {
    if (millis() - lastButtonPress > 50) {
      Serial.println("Button pressed!");
    }
    lastButtonPress = millis();
  }
  delay(1);
  while (1) {
    Serial.println("EMERGENCY STOP | RESET ARDUINO");
    delay(1000);
  }
}