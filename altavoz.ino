int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;

//variables de mi pito

int switchState = 0;
bool isTheButtonBeingPressed = false;
bool play = false;

int buttonPin = 2;

void setup() {
  
  pinMode (ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  while (millis () < 5000) {

    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  digitalWrite(ledPin, LOW);
}

void loop() {
  checkButton();
  if (play) {
    sound();
  
  }
}

void checkButton(){
  switchState = digitalRead(buttonPin);
  if (switchState == HIGH){
  if (isTheButtonBeingPressed == false){
    play = !play;
    isTheButtonBeingPressed = true;
  }
}
else{
  isTheButtonBeingPressed = false;
}
}

void sound() {

 sensorValue = analogRead(A0);
 int pitch =
 map(sensorValue, sensorLow, sensorHigh, 50, 4000);

 tone (8,pitch,20);

 delay (10);
  
}
  
