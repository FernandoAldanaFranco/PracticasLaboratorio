//Dr. Fernando Aldana Franco.
//Noviembre 2025
//Laboratorio de Electromagnetismo, Electrónica y Control.
//Facultad de Ingeniería Mecánica y Eléctrica - Xalapa.
//Universidad Veracruzana.
//Señal de error con sensor de temperatura.
/*Adquiere la señal de retroalimentación mediante el sensor LM75 mediante la biblioteca LM75 del gestor de blbliotecas
 * Genera la señal de error mediante la referencia de una temperatura. Imprime los resultados en la 
 * terminal serial
*/
//Declaración de bibliotecas para el sensor
#include <Wire.h> //I2C
#include <LM75.h>

LM75 sentemp; //Crea el objeto del sensor, se llama sentemp 

#define referencia 21.2 //Define la referencia de la temperatura

float temperatura=0.0; //Variable para leer la temperatura, inicia en 0.
float error=0; //Variable parea calcular el error, inicia en 0.
void setup() {
  Serial.begin(9600); //Inicia el la comunicación serial
  Serial.println(F("BMP280 test")); //Comienza la prueba del sensor
  sentemp.begin();
}

void loop() 
{
    //Medición de la temperatura
    Serial.println("Temperatura = ");
    temperatura=sentemp.getTemperature(); //Función de lectura de la temperatura
    Serial.print(temperatura);
    Serial.println(" *C");
    //Imprime referencia
    Serial.println("Referencia = ");
    Serial.print(referencia);
    //Imprime el error
    Serial.println("Error = ");
    error=referencia-temperatura; //Error es la diferencia de la referencia menos la señal sensada.
    Serial.print(error);
    //Linea en blanco
    Serial.println();
    //Repite cada segundo
    delay(1000);
}
