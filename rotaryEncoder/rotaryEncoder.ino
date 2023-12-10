#define outputA 2
#define outputB 3
#define btn 18

int counter = 0;
int aState;
int btnState;
unsigned long lastButtonPress = 0;
unsigned long currentMillis;
volatile bool buttonPressed = false;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(4, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
  pinMode(outputA, INPUT);
  pinMode(outputB, INPUT);
  attachInterrupt(digitalPinToInterrupt(outputA), checkPosition, CHANGE);
  attachInterrupt(digitalPinToInterrupt(btn), buttonClicked, LOW);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(4, HIGH);
}

void checkPosition() {
  currentMillis = millis();
  if (currentMillis - lastDebounceTime > debounceDelay) {
    lastDebounceTime = currentMillis;
    buttonPressed = true;
    aState = digitalRead(outputA);
    if (digitalRead(outputB) != aState) {
      counter++;
    } else {
      counter--;
    }
    Serial.print("Position: ");
    Serial.println(counter);
    delay(100);
  }
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