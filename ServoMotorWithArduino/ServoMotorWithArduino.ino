/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/
int i;
int iMax = ;
void setup() {
  Serial.begin(9600);
}

void loop() {
  for (i = 0; i < iMax; i++) {
    digitalWrite(6, HIGH);
    delayMicroseconds(1400);
    digitalWrite(6, LOW);
    delay(20);
  }
  for (i = 0; i < iMax; i++) {
    digitalWrite(6, HIGH);
    delayMicroseconds(1600);
    digitalWrite(6, LOW);
    delay(20);
  }
}
