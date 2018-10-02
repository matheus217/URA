#include "Segui_Faixa.h"

Segui_Faixa::Segui_Faixa(){

}

void Segui_Faixa::setup(int pindireito ,int pinesquerdo){

  Mdireito.attach(pindireito);
  Mesquerdo.attach(pinesquerdo);
  fluxo = false;

  
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

char Segui_Faixa::getfluxo(){

  if(fluxo==true)
  {
    return 'T';
  }
  if(fluxo==false)
  {
    return 'F';
  }
  
  }

void Segui_Faixa::correcao(int senEsquerdo, int sendireito)
{ 
  if((senEsquerdo==true) && (sendireito==false)) //sensor esquerdo detectou
  {
    if(fluxo!=true)
    {
      parar();
      delay(1000);
    }
    andar(95,85);
    //Serial.println("2");
    fluxo = true;
    Serial.print(" sensor esquerdo ");
    Serial.print(senEsquerdo);
    Serial.print(" sensor direito ");
    Serial.println(sendireito);
  }
  else if((senEsquerdo==false) && (sendireito==true)) //sensor direito detectou
  {
     if(fluxo!=true)
    {
      parar();
      delay(1000);
    }
    andar(86,80);
    //Serial.println("3");
    fluxo = true;
    Serial.print(" sensor esquerdo ");
    Serial.print(senEsquerdo);
    Serial.print(" sensor direito ");
    Serial.println(sendireito);
  }
  else if((senEsquerdo==false) && (sendireito==false))
  {
    //parar();
    fluxo = false;
    andar(95,80);
    Serial.print(" sensor esquerdo ");
    Serial.print(senEsquerdo);
    Serial.print(" sensor direito ");
    Serial.println(sendireito); 
  }
  else
  {
    parar();
      fluxo = false;
    //Serial.println("1");
    Serial.print(" sensor esquerdo ");
    Serial.print(senEsquerdo);
    Serial.print(" sensor direito ");
    Serial.println(sendireito);
  }
} 
