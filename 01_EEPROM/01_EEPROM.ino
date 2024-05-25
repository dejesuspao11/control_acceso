//codigo hecho en clase (:

// EEPROM (Electrically Erasable Programmable Read-Only Memory)
// la librería EEPROM proporciona funciones para leer y escribir en la memoria
#include<EEPROM.h>
// variable "pos" inicializada en 0 ...
// ... esta variable se usará para seguir la posición actual de lectura en la memoria EEPROM
int pos = 0;
void setup() {
    //inicia puerto serial
  	Serial.begin(9600);

    // utilizaremos este "for" para escribir valores secuenciales en la memoria EEPROM...
    // iterando sobre los valores de "i" desde el 0 hasta 1023 (la EEPROM generalmente tiene 1024 bytes de capacidad)
  	for(int i=0; i<1024;i++)
    {
      // cada valor de "i" se escribe en la dirección correspondiente en la memoria EEPROM utilizando la función "EEPROM.write()"
      EEPROM.write(i,i);
    }
}

void loop() {
  // se lee el valor almacenado en la posición "pos" de la memoria EEPROM, el valor se almacena en la variable "val"
  int val = EEPROM.read(pos);
  // se imprime la posición actual "pos"
  Serial.print(pos);
  // se imprime un guion
  Serial.print(" - ");
  // se imprime el valor almacenado "val"
  Serial.println(val);

  // se incrementa la posición actual de "pos" en 1 
  // se verifica si ha alcanzado el límite de la memoria EEPROM (1024)
  // si "pos" es mayor o igual a 1024, se reinicia a 0 (para comenzar desde el principio de la memoria EEPROM)
  if(++pos>=1024) pos=0;
  // retraso de 500 milisegundos entre cada iteracion
  delay(500);
}