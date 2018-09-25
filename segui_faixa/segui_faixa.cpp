#include "Segui_Faixa.h"

Segui_Faixa::Segui_Faixa(){

}

void Segui_Faixa::setup(int pindireito ,int pinesquerdo){

  Mdireito.attach(pindireito);
  Mesquerdo.attach(pinesquerdo);

  
}

void Segui_Faixa::incial(int stopdireito ,int stopesquerdo){

  Mdireito.write(stopdireito);
  Mesquerdo.write(stopesquerdo);
  
  
}

void Segui_Faixa::andar(int direito, int esquerdo){

  Mdireito.write(direito);
  Mesquerdo.write(esquerdo);
  
  
}

void Segui_Faixa::parar(){

 Mdireito.write(85);
 Mesquerdo.write(86);
 
}

void Segui_Faixa::correcao(int senEsquerdo, int sendireito)
{ 
  if((sendireito==true) && (senEsquerdo==true)) //sensor esquerdo detectou
  {
    parar();
    delay(100);
    andar(86,80);
    //Serial.println("2");
    Serial.print(" sensor esquerdo ");
    Serial.print(senEsquerdo);
    Serial.print(" sensor direito ");
    Serial.println(sendireito);
  }
  else if((sendireito==false) && (senEsquerdo==false)) //sensor direito detectou
  {
    parar();
    delay(100);
    andar(95,85);
    //Serial.println("3");
    Serial.print(" sensor esquerdo ");
    Serial.print(senEsquerdo);
    Serial.print(" sensor direito ");
    Serial.println(sendireito);
  }
  else if((sendireito==false) && (senEsquerdo==true))
  {
    //parar();
    andar(100,70);
    Serial.print(" sensor esquerdo ");
    Serial.print(senEsquerdo);
    Serial.print(" sensor direito ");
    Serial.println(sendireito); 
  }
  else
  {
    parar();
    //Serial.println("1");
    Serial.print(" sensor esquerdo ");
    Serial.print(senEsquerdo);
    Serial.print(" sensor direito ");
    Serial.println(sendireito);
  }
} 
