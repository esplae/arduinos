const int greenLEDPin = 9 ;
const int redLEDPin = 11 ;
const int blueLEDPin = 10 ;

const int redSensorPin = A0 ;
const int greenSensorPin = A1 ;
const int blueSensorPin = A2 ;

int redValue = 0 ;
int greenValue = 0 ;
int blueValue = 0 ;

int redSensorValue = 0 ;
int greenSensorValue = 0 ;
int blueSensorValue = 0 ;

int biggestColorPin = 0;

int getBiggestColorPin() {
	redSensorValue = analogRead(redSensorPin);
	delay(5);
	greenSensorValue = analogRead(greenSensorPin);
	delay(5);
	blueSensorValue = analogRead(blueSensorPin);
	Serial.print("Raw Sensor Values \t Red: ");
	Serial.print(redSensorValue);
	Serial.print("\t Green: ");
	Serial.print(greenSensorValue);
	Serial.print("\t Blue: ");
	Serial.println(blueSensorValue);

	redValue = redSensorValue/4;
	greenValue = greenSensorValue/4 ;
	blueValue = blueSensorValue/4;

	if (redValue > greenValue && redValue > blueValue) {
		return redLEDPin;
	} else if (greenValue > blueValue && greenValue > redValue) {
		return greenLEDPin;
	} else {
		return blueLEDPin;
	}
}

void setup() {
	Serial.begin(9600) ;

	pinMode(greenLEDPin, OUTPUT);
	pinMode(redLEDPin, OUTPUT);
	pinMode(blueLEDPin, OUTPUT);
}


void loop() {
	biggestColorPin = getBiggestColorPin();

	Serial.print("Mapped Sensor Values \t Red: ");
	Serial.print(redValue);
	Serial.print("\t Green: ");
	Serial.print(greenValue);
	Serial.print("\t Blue: ");
	Serial.println(blueValue);

	analogWrite(redLEDPin, 0);
	analogWrite(greenLEDPin, 0);
	analogWrite(blueLEDPin, 0);

	if (biggestColorPin == redLEDPin) {
		analogWrite(redLEDPin, redValue);
	} else if (biggestColorPin == greenLEDPin) {
		analogWrite(greenLEDPin, greenValue);
	} else if (biggestColorPin == blueLEDPin) {
		analogWrite(blueLEDPin, blueValue);
	}
}	
