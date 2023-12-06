#ifndef SIMULATION_H
#define SIMULATION_H

#include "Faucet.h"
#include "Container.h"
#include"Fluid.h"
#include"GenPoint.h"

class Simulation
{
private:
  Faucet faucet;
  GenPoint pos;
  Fluid fluid;
  Container container;
  int waterRate;

public:
  Simulation();
  void setContainer(Container container);
  Container getContainer();
  void setFaucet(Faucet faucet);
  Faucet getFaucet();
  int getWaterRate();
  void setWaterRate(int waterRate);
  void draw();
  void start();
};
#endif
