#include "Segui_Faixa.h"

//Mesquerdo = 86 -> 180 max (frente)
//Mdireito = 85 -> 0 max (frente)
//sensorEsquerdo -> 1 nao detecta, 0 detecta
//sensordireito -> 1 nao detecta, 0 detecta

Segui_Faixa motor;
bool sensorD, sensorE;
int pinsensorD = 8;
int pinsensorE = 13;
char inicial;

void setup() {
  pinMode(pinsensorD,INPUT);
  pinMode(pinsensorE,INPUT);
  motor.setup(10,11);
  motor.parar();
  //sensorD = false; 
  //sensorE = true;
  

}

void loop() {
  Serial.begin(9600);

  sensorD = digitalRead(pinsensorD);
  sensorE = digitalRead(pinsensorE);
  Serial.println(motor.getfluxo());

  //Serial.println(sensor);
  //delay(300);

 if(Serial.available())
 {
  
  inicial = Serial.read();
  Serial.end();
 }

 Serial.println(motor.getfluxo());
    
  if((inicial=='a'))
  {
    Serial.println("entrei");
    motor.correcao(sensorE, sensorD);
  }
  else if(inicial=='p')
  {
    motor.parar();
  }
  
  delay(1000);
  
  }
  
  
