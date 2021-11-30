/*
 * 
 * 
#define Tiempo 5000 // En milisegundos.
const int LED2 = 2;
const int pulsador12 = 12;

unsigned long now = millis();
unsigned long tic = 0;
boolean comienzo = false;

// Función cuando se produce la interrupción.
void IRAM_ATTR pulsado() {
  digitalWrite(LED2, HIGH);
  comienzo = true;
  tic = millis();
}

void setup() {
  Serial.begin(115200);  
  pinMode(pulsador12, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pulsador12), pulsado, RISING);

  pinMode(LED2, OUTPUT);
  digitalWrite(LED2, LOW);
}

void loop() {
  now = millis();
  if(comienzo && (now - tic > (Tiempo))) {
    digitalWrite(LED2, LOW);
    comienzo = false;
  }
}
 * 
 * 
 * 
 */
