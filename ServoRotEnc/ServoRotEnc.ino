/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/
int i;
int iMax = 40;
#define outputA 2
#define outputB 3
#define btn 18
#define servo 6

int counter = 0;
int aState;
int btnState;
unsigned long lastButtonPress = 0;
int servoCWspd = 1450;
int servoCCWspd = 1550;

void setup() {
  pinMode(4, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
  pinMode(outputA, INPUT);
  pinMode(outputB, INPUT);
  attachInterrupt(digitalPinToInterrupt(outputA), checkPosition, CHANGE);
  attachInterrupt(digitalPinToInterrupt(btn), buttonClicked, LOW);
  pinMode(servo, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(4, HIGH);
  for (i = 0; i < iMax; i++) {
    digitalWrite(servo, HIGH);
    delayMicroseconds(servoCWspd);
    digitalWrite(servo, LOW);
    delay(20);
  }
  for (i = 0; i < iMax; i++) {
    digitalWrite(servo, HIGH);
    delayMicroseconds(servoCCWspd);
    digitalWrite(servo, LOW);
    delay(20);
  }
}

void checkPosition() {
  aState = digitalRead(outputA);
  if (digitalRead(outputB) != aState) {
    if (servoCWspd > 1400) {
      servoCWspd -= 10;
      servoCCWspd += 10;
      iMax += 20;
    }
  } else {
    if (servoCWspd < 1475) {
      servoCWspd += 10;
      servoCCWspd -= 10;
      iMax -= 20;
    }
  }
  Serial.print("CW SPD: ");
  Serial.print(servoCWspd);
  Serial.print("\tCCW SPD: ");
  Serial.print(servoCCWspd);
  Serial.print("\tiMAX: ");
  Serial.println(iMax);
  delay(10);
}

void buttonClicked() {
  btnState = digitalRead(btn);
  if (btnState == LOW) {
    if (millis() - lastButtonPress > 50) {
      Serial.println("Button pressed!");
    }
    lastButtonPress = millis();
  }
  delay(1);
}