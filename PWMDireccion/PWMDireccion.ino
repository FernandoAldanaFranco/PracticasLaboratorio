//Dr. fernando Aldana Franco.
//30 de enero de 2022
//Laboratorio de Electromagnetismo, Electrónica y Control.
//Facultad de Ingeniería Mecánica y Eléctrica - Xalapa.
//Universidad Veracruzana.
//Control de motores con PWM con cambio de dirección.
/*Este programa permite el control de motores mediante un PWM propio que se encuentra en los canales digitales 2 y 3. 
 *El programa varia el ancho de pulso para que pueda ser conectado a los controles del L293D
*/

#define PIN_CONTROL 2 //Define el pin digital para el control
#define PIN_CONTROL_R 3 //Define el pin digital para el control en reversa

void setup() {
  pinMode(PIN_CONTROL, OUTPUT); //Declara ese canal digital como salida
  pinMode(PIN_CONTROL_R, OUTPUT); //Declara ese canal digital como salida
  digitalWrite(PIN_CONTROL, LOW); //Apaga el canal digital
  digitalWrite(PIN_CONTROL_R, LOW); //Apaga el canal digital

}

//Primer ciclo de trabajo a 50%
void ciclo_1(void){
  //Repite el ciclo 100 veces
  for(int i=0;i<200;i++)
  {
    digitalWrite(PIN_CONTROL, HIGH); //Señal en alto nivel
    delay(250); //250mS
    digitalWrite(PIN_CONTROL, LOW); //Señal en bajo nivel
    delay(250);
  }
}

//Segundo ciclo de trabajo a 80%
void ciclo_2(void){
  //Repite el ciclo 100 veces
  for(int i=0;i<200;i++)
  {
    digitalWrite(PIN_CONTROL, HIGH); //Señal en alto nivel
    delay(400); //400mS
    digitalWrite(PIN_CONTROL, LOW); //Señal en bajo nivel
    delay(100); //100mS
  }
}
//Tercer ciclo de trabajo a 20%
void ciclo_3(void){
  //Repite el ciclo 100 veces
  for(int i=0;i<200;i++)
  {
    digitalWrite(PIN_CONTROL, HIGH); //Señal en alto nivel
    delay(100);//100mS
    digitalWrite(PIN_CONTROL, LOW); //Señal en bajo nivel
    delay(400); //400mS
  }
}

//Cuarto ciclo de trabajo a 50%
void ciclo_1(void){
  //Repite el ciclo 100 veces
  for(int i=0;i<200;i++)
  {
    digitalWrite(PIN_CONTROL_R, HIGH); //Señal en alto nivel
    delay(250); //250mS
    digitalWrite(PIN_CONTROL_R, LOW); //Señal en bajo nivel
    delay(250);
  }
}

//Quinto ciclo de trabajo a 80%
void ciclo_2(void){
  //Repite el ciclo 100 veces
  for(int i=0;i<200;i++)
  {
    digitalWrite(PIN_CONTROL_R, HIGH); //Señal en alto nivel
    delay(400); //400mS
    digitalWrite(PIN_CONTROL_R, LOW); //Señal en bajo nivel
    delay(100); //100mS
  }
}
//Sexto ciclo de trabajo a 20%
void ciclo_3(void){
  //Repite el ciclo 100 veces
  for(int i=0;i<200;i++)
  {
    digitalWrite(PIN_CONTROL_R, HIGH); //Señal en alto nivel
    delay(100);//100mS
    digitalWrite(PIN_CONTROL_R, LOW); //Señal en bajo nivel
    delay(400); //400mS
  }
}
void loop() {
  digitalWrite(PIN_CONTROL_R, LOW); //Apaga el canal digital
  ciclo_1();
  ciclo_2();
  ciclo_3();  
  digitalWrite(PIN_CONTROL, LOW); //Apaga el canal digital
  ciclo_4();
  ciclo_5();
  ciclo_6();  
  digitalWrite(PIN_CONTROL, LOW); //Apaga el canal digital
  digitalWrite(PIN_CONTROL_R, LOW); //Apaga el canal digital
  delay(10000);
}
