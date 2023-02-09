//Dr. Fernando Aldana Franco.
//1 de febrero de 2023
//Laboratorio de Electromagnetismo, Electrónica y Control.
//Facultad de Ingeniería Mecánica y Eléctrica - Xalapa.
//Universidad Veracruzana.
//Señal de error con sensor de temperatura.
/*Adquiere la señal de retroalimentación mediante el sensor BMP280 mediante la biblioteca BMP280
 * Genera la señal de error mediante la referencia de una temperatura. Imprime los resultados en la 
 * terminal serial
*/
//Declaración de bibliotecas para el sensor
#include <Wire.h> //I2C
#include "Adafruit_BMP280.h" //Biblioteca del sensor

Adafruit_BMP280 sentemp; //Crea el objeto del sensor, se llama sentemp 

#define referencia 21.2 //Define la referencia de la temperatura

float temperatura=0.0; //Variable para leer la temperatura, inicia en 0.
float error=0; //Variable parea calcular el error, inicia en 0.
void setup() {
  Serial.begin(9600); //Inicia el la comunicación serial
  Serial.println(F("BMP280 test")); //Comienza la prueba del sensor

  if (!sentemp.begin()) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!")); //Si no detecta el sensor, genera un mensaje de error
    while (1);
  }
  //En caso de estar conectado el sensor, imprime las características
  sentemp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Modo de operación */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Presion oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtrado. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Tiempo Standby. */
}

void loop() 
{
    //Medición de la temperatura
    Serial.println("Temperatura = ");
    temperatura=sentemp.readTemperature(); //Función de lectura de la temperatura
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
