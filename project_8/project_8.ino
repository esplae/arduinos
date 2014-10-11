const int switchPin = 8 ;

unsigned long currentTime = 0 ;
unsigned long previousTime = 0 ;
unsigned long previousTick = 0 ;

boolean countUp = true;
boolean tickState = true;
int switchState = 0 ;
int prevSwitchState = 0 ; 

int tones[10] = { 320, 339, 440, 291, 499, 300, 100, 200, 300, 340 };

int led = 2 ;

long interval = 1000 ;

long tickerval = interval / 600;

void setup() { 
	for (int x = 2; x <8; x++){
		pinMode(x, OUTPUT);
	}
	pinMode(11, OUTPUT);
	pinMode(switchPin, INPUT);
	Serial.begin(9600);
}

void loop() {
	currentTime = millis();

	if(currentTime - previousTime > interval){
		timeIsUp();	
	} else if (currentTime - previousTick > tickerval) {
		doBlinkingLight();
	}
	doSwitchChangedCheck();
}

void timeIsUp() {
	previousTime = currentTime ;
	digitalWrite(led, HIGH);
	if (countUp){
		led++ ;	
		if(led > 7){
			// TIMES UP!!!
			for (int i = 1; i < 11; i++ ){
				tone(11, tones[i]);
				delay(100);
			}
		}
	} else {
		led--;
		if (led < 0)
		{
			// TIMES UP!!!
			for (int i = 1; i < 4; i++ ){
				tone(11, tones[i]);
				delay(100);
			}
		}
	}	
}

void doBlinkingLight() {
	previousTick = currentTime ;
	tickState = !tickState;
	if (tickState) {
		digitalWrite(led, HIGH);
	} else {
		digitalWrite(led, LOW);
	}
}

void doSwitchChangedCheck() {
	switchState = digitalRead(switchPin);
	Serial.println(switchState);
	if(switchState!= prevSwitchState){
		for (int x = 2; x < 8; x++){
			digitalWrite(x, LOW);
		}
		countUp = !countUp;
		if (countUp) {
			led = 2 ;
		} else {
			led = 7;
		}
		previousTime = currentTime ;
		noTone(11);

	}
	prevSwitchState = switchState ;	
}