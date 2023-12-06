#ifndef FAUCET_H
#define FAUCET_H

#include "GenPoint.h"
#include "Fluid.h"
#include"Container.h"

class Faucet
{
private:
  GenPoint pos;
  Fluid fluid;
  Container container;  

public:
  Faucet();
  void turnOn();
  void turnOff();
  void setPosition(GenPoint upper);
  GenPoint getPosition();
  void setFluid(Fluid fluid);
  Fluid getFluid();
  void draw();

};

#endif