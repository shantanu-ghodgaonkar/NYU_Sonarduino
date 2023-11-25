--(#1) Arduino Sweep Sketch

#include <Servo.h>

Servo myservo; // create a servo object to control a servo

int pos = 0;
 void setup()
 {
	myservo.attach(9); // Attaches the servo to pin 9 to the servo object

 }

void loop() 
{
	for(pos = 0; pos<= 180; pos +=1) // 0 deg to 180 deg
	{
		myservo.write(pos); // Tells to go to position in variable pos
		delay(15); // waits 15ms for the servo to reach to that position
	}

	for(pos = 180; pos>= 0; pos -= 1) // 180 deg to 0 deg
	{
		myservo.write(pos);	
		delay(15);
	}
}

-------------------------------------------------------------------------------------------------------------------------------------

--(#2)Arduino Knob Sketch

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer

int val;    // variable to read the value from the analog pin

void setup()
 {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
 }

void loop() 
{
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}
