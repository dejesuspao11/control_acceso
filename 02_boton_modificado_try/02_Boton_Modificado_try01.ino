//Boton modificado

// Se declara la constante "inputPin" y se le asigna el valor 7
// el 7 representa el número de pin al que está conectado el botón o interruptor
const int inputPin = 7;
// Se declara variable "lastButtonState" y se inicializa en LOW (apagado)
// esta variable indica el estado del botón antes de iniciar el loop
int lastButtonState = LOW;
// declaramos la variable "currentButtonState" que se utilizará para almacenar el estado actual del botón con cada iteración
int currentButtonState;
// se declara la variable "outputState" y se inicializa en 0
// esta variable se utiliza para representar el estado de salida deseado (en este caso cambiará entre 0 y 1 cuando se presione el botón)
int outputState = 0;

// se crea la función "setup"
void setup() {
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}

// en loop se lee el estado del pin de entrada (inputPin) utilizando la función "digitalRead()"
void loop() {
  // el estado obtenido se almacena en la variable "currentButtonState"
  currentButtonState = digitalRead(inputPin);
  
  // hacemos una comprobación condicional para verificar si el estado actual del botón (currentButtonState) es alto (HIGH)...
  // ... y si el estado anterior del botón (lastButtonState) es bajo (LOW)
  // esto indicaría que el botón acaba de ser presionado
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    // alterna el estado de salida (outputState) entre 0 y 1
    if (outputState == 0) {
      // si outputState es 0, se cambia a 1...
      outputState = 1;
      // ...si es 1, se cambia a 0
    } else {
      outputState = 0;
    }
    // imprime el valor actual de "outputState" a través del puerto serial utilizando "Serial.println()"
    Serial.println(outputState);
    // introduce un pequeño retraso de 50 milisegundos para evitar lecturas erroneas
    delay(50);
  }
  
  // actualiza el estado anterior del botón (lastButtonState) al estado actual del botón (currentButtonState)
  lastButtonState = currentButtonState;
} //fin!