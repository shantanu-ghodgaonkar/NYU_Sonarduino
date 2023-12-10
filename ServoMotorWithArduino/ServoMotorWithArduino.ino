/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/
int i;
// int iMax = 40;
// int iMax = 45;
// int iMax = 50;
int iMax = 55;
#define servo 6
void setup() {
  pinMode(servo, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // for (i = 0; i < iMax; i++) {
  //   digitalWrite(servo, HIGH);
  //   delayMicroseconds(1400);
  //   digitalWrite(servo, LOW);
  //   delay(20);
  // }
  // for (i = 0; i < iMax; i++) {
  //   digitalWrite(servo, HIGH);
  //   delayMicroseconds(1600);
  //   digitalWrite(servo, LOW);
  //   delay(20);
  // }

  // for (i = 0; i < iMax; i++) {
  //   digitalWrite(servo, HIGH);
  //   delayMicroseconds(1420);
  //   digitalWrite(servo, LOW);
  //   delay(20);
  // }
  // for (i = 0; i < iMax; i++) {
  //   digitalWrite(servo, HIGH);
  //   delayMicroseconds(1580);
  //   digitalWrite(servo, LOW);
  //   delay(20);
  // }

  // for (i = 0; i < iMax; i++) {
  //   digitalWrite(servo, HIGH);
  //   delayMicroseconds(1440);
  //   digitalWrite(servo, LOW);
  //   delay(20);
  // }
  // for (i = 0; i < iMax; i++) {
  //   digitalWrite(servo, HIGH);
  //   delayMicroseconds(1560);
  //   digitalWrite(servo, LOW);
  //   delay(20);
  // }

  for (i = 0; i < iMax+5; i++) {
    digitalWrite(servo, HIGH);
    delayMicroseconds(1460);
    digitalWrite(servo, LOW);
    delay(20);
  }
  for (i = 0; i < iMax; i++) {
    digitalWrite(servo, HIGH);
    delayMicroseconds(1540);
    digitalWrite(servo, LOW);
    delay(20);
  }
}
