#ifndef SEGUI_FAIXA_H
#define SEGUI_FAIXA_H
#include <Arduino.h>
#include <Servo.h>

class Segui_Faixa
{
  public:

  Segui_Faixa();
  void setup(int pindireito ,int pinesquerdo);
  void incial(int stopdireito ,int stopesquerdo);
  void andar(int direito, int esquerdo);
  void parar();
  void correcao(int senEsquerdo, int sendireito);
  char getfluxo();

  private:

  Servo Mdireito, Mesquerdo;
  bool fluxo;
    
};

#endif
