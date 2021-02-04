//constantes de pines
const int greenLEDPin=9;
const int redLEDPin=11; 
const int blueLEDPin=10;
//constantes del botópn
const int redSensorPin=A0;
const int greenSensorPin=A1;
const int blueSensorPin=A2;
//variables
int redValue = 0;
int greenValue= 0;
int blueValue= 0;

int redSensorValue=0;
int greenSensorValue=0;
int blueSensorValue=0;

int redSensorMinValue = 1023;
int greenSensorMinValue = 1023;
int blueSensorMinValue = 1023;

int redSensorMaxValue = 0;
int greenSensorMaxValue = 0;
int blueSensorMaxValue = 0;

//variables de mi pito

int switchState = 0;
bool isTheButtonBeingPressed = false;
bool pimPimFlag = false;

int buttonPin = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(greenLEDPin,OUTPUT);
  pinMode(redLEDPin,OUTPUT);
  pinMode(blueLEDPin,OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  calibrate();
  pinMode(buttonPin, INPUT);
 
}


void calibrate() {
    digitalWrite(LED_BUILTIN, HIGH);
  while (millis()<5000){
    //Páginas 74 y 75
    redSensorValue = analogRead(redSensorPin);
    greenSensorValue = analogRead(greenSensorPin);
    blueSensorValue = analogRead(blueSensorPin);
    if(redSensorValue > redSensorMaxValue)
    {
      redSensorMaxValue = redSensorValue;
    }
    if(redSensorValue < redSensorMinValue)
    {
      redSensorMinValue = redSensorValue;
    }
     if(greenSensorValue > greenSensorMaxValue)
    {
      greenSensorMaxValue = greenSensorValue;
    }
    if(greenSensorValue < greenSensorMinValue)
    {
      greenSensorMinValue = greenSensorValue;
    }
     if(blueSensorValue > blueSensorMaxValue)
    {
      blueSensorMaxValue = blueSensorValue;
    }
    if(blueSensorValue < blueSensorMinValue)
    {
      blueSensorMinValue = blueSensorValue;
    }
  }
   digitalWrite(LED_BUILTIN, LOW);
}



void loop() {
  switchState = digitalRead(buttonPin);
 if (switchState == HIGH){
  if (isTheButtonBeingPressed == false){
    //if (pimPimFlag == false){
    //pimPimFlag = true;
    //}
    //else {
    //pimPimFlag = false;
    //}
    pimPimFlag = !pimPimFlag;
    isTheButtonBeingPressed = true;
  }
 }
else {
  isTheButtonBeingPressed = false;

}

  
  if (pimPimFlag == true){
 nose();
} //llave del final del loop
  else{
    analogWrite(redLEDPin, 0);
    analogWrite(greenLEDPin, 0);
    analogWrite(blueLEDPin, 0);
  }
}

void nose() {
    // put your main code here, to run repeatedly:
redSensorValue = analogRead(redSensorPin);
delay(5);
greenSensorValue = analogRead(greenSensorPin);
delay(5);
blueSensorValue = analogRead(blueSensorPin);
Serial.print("Raw Sensor Values \t Red: ");
Serial.print(redSensorValue);
Serial.print("\t Green: ");
Serial.print(greenSensorValue);
Serial.print("\t Blue");
Serial.println(blueSensorValue);
redValue = map(redSensorValue, 0,1023,0,255);
greenValue = map(greenSensorValue ,0,1023,0,255);
blueValue = map(blueSensorValue, 0,1023,0,255);
Serial.print("Mapped Sensor Values \t Red: ");
Serial.print(redValue);
Serial.print("\t Green: ");
Serial.print(greenValue);
Serial.print("\t Blue");
Serial.println(blueValue);
analogWrite(redLEDPin, redValue);
analogWrite(greenLEDPin, greenValue);
analogWrite(blueLEDPin, blueValue);
}
