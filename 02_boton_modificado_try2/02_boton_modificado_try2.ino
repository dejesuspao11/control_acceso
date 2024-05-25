//Boton modificado corregido (:

const int inputPin = 7;
int input7 = 0;
int lastState;

void setup() {
	pinMode(inputPin, INPUT);
	Serial.begin(9600); // inicalizacion del puerto serial
}

// // la función devuelve HIGH si el pin recibe voltaje y LOW en caso contrario
void loop() {
  // digitalRead lee el estado del pin de entrada (inputPin) y almacena su valor en la variable "input7"
	input7 = digitalRead(inputPin);
    // si el estado anterior (lastState) es LOW y el estado actual (input7) es HIGH significa que el boton fue presionado
  	if(lastState ==LOW && input7 == HIGH) {
  // si la condición anterior se cumple, se imprime "1" a través del puerto serial
	Serial.println("1");
    // usamos un retraso de 100 milisegundos
    delay(100);
	}
  // verifica si el estado anterior (lastState) es HIGH y el estado actual (input7) es LOW...
  // ...esto indicaría que el boton ya no esta siendo presionado
	else if(lastState == HIGH && input7 == LOW) {
  // si la condición anterior se cumple imprime "0"  
 	Serial.println("0");
    // retraso de 100 milisegundos
    delay(100);
	}
  // cambia el valor de "lastState" por el estado actual (el valor en "input7")
  lastState = input7;
} // fin (: