int const potPin = A0;
int potVal;


//constantes de pines
const int greenLEDPin=9;
const int redLEDPin=11; 
const int blueLEDPin=10;

const int buttonPin= 2;
int switchState = 0;

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
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.println(potVal);
  Serial.print(greenValue);
  greenValue = map(potVal ,0,1023,0,255);
  analogWrite(greenLEDPin, greenValue);

 delay(15);
  

}
