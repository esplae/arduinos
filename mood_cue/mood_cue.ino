#include <Servo.h>

Servo servo;

const int servoPin = 9;
const int potentioPin = A0;
float rawPinValue;
float voltage;
float temperature;
int servoAngle;

int incomingByte;



void setup() {
	servo.attach(servoPin);
	Serial.begin(9600);
}

void loop() {
	if (Serial.available() > 0) {
		incomingByte = Serial.parseInt();

		Serial.print("I received: ");
		Serial.println(incomingByte);
		servo.write(incomingByte); 
	}
	delay(100);
}