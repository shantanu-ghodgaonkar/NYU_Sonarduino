#define inc 2
#define dec 3
#define stp 18


void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(18, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), printInc, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), printDec, FALLING);
  attachInterrupt(digitalPinToInterrupt(18), stop, FALLING);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

void printInc() {
  noInterrupts();
  Serial.println("INCREASE SPEED");
  delay(50);
  interrupts();
}
void printDec() {
  noInterrupts();
  Serial.println("DECREASE SPEED");
  delay(50);
  interrupts();
}
void stop() {
  noInterrupts();
  Serial.println("STOP");
  delay(50);
  interrupts();
}
