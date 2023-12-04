#define outputA 2
#define outputB 3
#define btn 18

int counter = 0;
int aState;
int btnState;
unsigned long lastButtonPress = 0;

void setup() {
  pinMode(btn, INPUT_PULLUP);
  pinMode(outputA, INPUT);
  pinMode(outputB, INPUT);
  attachInterrupt(digitalPinToInterrupt(outputA), checkPosition, CHANGE);
  attachInterrupt(digitalPinToInterrupt(btn), buttonClicked, LOW);

  Serial.begin(9600);
}

void loop() {
}

void checkPosition() {
  aState = digitalRead(outputA);
  if (digitalRead(outputB) != aState) {dxt
    counter++;
  } else {
    counter--;
  }
  Serial.print("Position: ");
  Serial.println(counter);
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