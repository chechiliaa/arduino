// Definir variables
const int PinInterruptor = 8;
unsigned long TiempoPrevio = 0;
int EstadodelInterruptor = 0;
int EstadoPreviodelInterruptor = 0;
int indiceLedPin = 0;
long TiempoIntervalocadaLed = 1000; // Tiempo indicado en milisegundos, por tanto 1 segundo
const int ledPins[] = {
  2,
  4,
  3,
  5,
  7,
  6
};

// Configurar la placa Arduino
void setup() {
  for(int x = 2;x<8;x++){
    pinMode(x, OUTPUT);
   }
    pinMode(PinInterruptor, INPUT);
}
    
// Ejecucion del programa
void loop() {
  unsigned long TiempoActual = millis();
  if(TiempoActual - TiempoPrevio > TiempoIntervalocadaLed){
    TiempoPrevio = TiempoActual;
    digitalWrite(ledPins[indiceLedPin], HIGH);
    indiceLedPin++;
    if(indiceLedPin == 6){
      // todo parpadea
        for(int x = 2;x<8;x++){
          digitalWrite(x, LOW);
         }
        delay(500);
        for(int x = 2;x<8;x++){
          digitalWrite(x, HIGH);
         }
        delay(500);
    }
  }
  EstadodelInterruptor = digitalRead(PinInterruptor);
  if(EstadodelInterruptor != EstadoPreviodelInterruptor){
    for(int x = 2;x<8;x++){
      digitalWrite(x, LOW);
    }
    indiceLedPin = 0;
    TiempoPrevio = TiempoActual;
  }
  EstadoPreviodelInterruptor = EstadodelInterruptor;
}  
// Volver al comienzo del programa
