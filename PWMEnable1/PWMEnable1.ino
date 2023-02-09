//Dr. fernando Aldana Franco.
//30 de enero de 2022
//Laboratorio de Electromagnetismo, Electrónica y Control.
//Facultad de Ingeniería Mecánica y Eléctrica - Xalapa.
//Universidad Veracruzana.
//Control de motores con PWM.
/*Este programa permite el control de motores mediante un PWM propio que se encuentra en el canal digital 2. 
 *El programa varia el ancho de pulso para que pueda ser conectado opr el habilitador del L293D
*/

#define PIN_CONTROL 2 //Define el pin digital para el control

void setup() {
  pinMode(PIN_CONTROL, OUTPUT); //Declara ese canal digital como salida
  digitalWrite(PIN_CONTROL, LOW); //Apaga el canal digital

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
void loop() {
  ciclo_1();
  ciclo_2();
  ciclo_3();  
  delay(10000);
}
