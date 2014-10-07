int sensorValue;
int sensorLow = 1023 ;
int sensorHigh = 0 ;
int bassPin = 9;
int treblePin = 10;

const int ledPin = 13;
const int mapTrebleHigh = 3000;
const int mapBassLow = 50;
const int beepMap[3] = {1100, 1200, 1500};

int beepmapCounter = 0;
int skipCounter = 0;

int readSensor() {
    return analogRead(A0);
}

int getPitch(int sensorValue, boolean treble) {
    return map(sensorValue, sensorLow, sensorHigh, mapBassLow, mapTrebleHigh);
}

void setup() {
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);

    while(millis() < 5000){
       sensorValue = analogRead(A0);
       if(sensorValue > sensorHigh){
           sensorHigh = sensorValue;
           } else if (sensorValue < sensorLow) {
              sensorLow = sensorValue;
          }
      }

      digitalWrite(ledPin, LOW);
  }

void loop() {
    if (skipCounter++ == 51)
    {
        if (beepmapCounter++ == 3)
        {
            beepmapCounter = 0;
        }
        delay(500);
        skipCounter = 0;
        tone(treblePin, beepMap[beepmapCounter], 100);
        delay(500);
    }  else {
        delay(10);    
    }
    sensorValue = readSensor(); 
    tone(bassPin, getPitch(sensorValue, true), 10);

}


