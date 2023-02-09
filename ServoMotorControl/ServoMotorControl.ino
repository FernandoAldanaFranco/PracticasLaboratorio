//Dr. fernando Aldana Franco.
//30 de enero de 2022
//Laboratorio de Electromagnetismo, Electrónica y Control.
//Facultad de Ingeniería Mecánica y Eléctrica - Xalapa.
//Universidad Veracruzana.
//Control de servomotores en una dirección.
/*Este programa permite el control de servomotores mediante la biblioteca servo.h
*/

#include <Servo.h> //Biblioteca para escribir al PWM

Servo servoMotor; //Se delcara el objeto servomotor 

void setup() {
  servoMotor.attach(3); //Inicia el servo en el PWM del pin 3

}

void loop() {
  servoMotor.write(0);//Servo a posición de origen
  delay(1000);
  servoMotor.write(90);//Servo a 90°
  delay(1000);
  servoMotor.write(180);//Servo a 180°
  delay(1000);
  servoMotor.write(270);//Servo a 270°
  delay(1000);
}
