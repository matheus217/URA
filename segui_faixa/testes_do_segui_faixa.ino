#include "Segui_Faixa.h"

//Mdireito = 86 -> 180 max (frente)
//Mesquerdo = 85 -> 0 max (frente)
//sensordireito -> 1 nao detecta, 0 detecta
//sensorEsquerdo -> 0 nao detecta, 1 detecta

Segui_Faixa motor;
bool sensorD, sensorE;
int pinsensorD = 13;
int pinsensorE = 8;
char inicial;
bool fluxo;

void setup() {
  pinMode(pinsensorD,INPUT);
  pinMode(pinsensorE,INPUT);
  motor.setup(11,10);
  motor.parar();
  sensorD = true; 
  sensorE = false;
  

}

void loop() {
  Serial.begin(9600);

  sensorD = digitalRead(pinsensorD);
  sensorE = digitalRead(pinsensorE);

  //Serial.println(sensor);
  //delay(300);

 if(Serial.available())
 {
  
  inicial = Serial.read();
  Serial.end();
 }
 
    
  if((inicial=='a'))
  {
    Serial.println("entrei");
    motor.correcao(sensorE, sensorD);
  }
  else if(inicial=='p')
  {
    motor.parar();
  }
  
  delay(50);
  
  }
  
  
