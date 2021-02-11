int const potPin = A0;
int potVal;


//constantes de pines
const int greenLEDPin=9;
const int redLEDPin=11; 
const int blueLEDPin=10;

const int buttonPin= 2;


//
int switchState =0;
bool isTheButtonBeingPressed = false;
// Canal de RGB 0 = 0, 1 = R, 2 = G, 3 = B
int channel =0;


//variables
int redValue = 0;
int greenValue= 0;
int blueValue= 0;



void setup() {
  pinMode(greenLEDPin,OUTPUT);
  pinMode(redLEDPin,OUTPUT);
  pinMode(blueLEDPin,OUTPUT);
  Serial.begin(9600);
    pinMode(buttonPin, INPUT);
}

void loop() {

  switchState = digitalRead(buttonPin);

  //leer botón
  if(switchState==HIGH){
    if(isTheButtonBeingPressed == false){
       isTheButtonBeingPressed = true;
       channel ++;
       if (channel > 3)
       {
        channel = 0;
       }
    }
        Serial.print("Valor del canal (0 = 0, 1 = R, 2 = G, 3 = B): ");
        Serial.println(channel);
 
  }

else{
  isTheButtonBeingPressed = false;
}

  potVal = analogRead(potPin);
Serial.print("potVal: ");
Serial.println(potVal);
if (channel ==1){
  colorearRojo();
}
if (channel ==2){
  colorearVerde();
}
if (channel ==3){
  colorearAzul();
}

 delay(15);
  

}

void colorearRojo(){
  redValue = map(potVal,0,1023,0,255);
analogWrite(redLEDPin, redValue);
  
}

void colorearAzul(){
  blueValue = map(potVal,0,1023,0,255);
analogWrite(blueLEDPin, blueValue);
  
}

void colorearVerde(){
  greenValue = map(potVal,0,1023,0,255);
analogWrite(greenLEDPin, greenValue);
  
}
