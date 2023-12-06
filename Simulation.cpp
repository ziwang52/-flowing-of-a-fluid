#include <iostream>
#include "graph1.h"
#include "Simulation.h"

using namespace std;

Simulation::Simulation()
{
   Faucet faucet;
   Container container;
  pos.setPoint(0, 0);
  fluid.getStart();
 
  waterRate = 0;
}



void Simulation::setContainer(Container container)
{
  this->container= container;
}

Container Simulation::getContainer()
{
  return container;
}
Faucet Simulation::getFaucet()
{
  return faucet;
}
void  Simulation::setFaucet(Faucet faucet)
{
 this->faucet=faucet;
}

int Simulation::getWaterRate()
{
  return waterRate;
}
void Simulation::setWaterRate(int waterRate)
{
this-> waterRate =waterRate;
}
void Simulation::draw()
{
  int wall = 0;
  int ground = 0;
  int pipe =0;

  // wall
  wall = drawRect(0, 0, 55, 400);
  setColor(wall, 200, 200, 200);

  //ground
  ground = drawRect(0, 400, 640, 80);
  setColor(ground, 71, 35, 35);
  // cyliner
  container.draw();

  faucet.draw();

  pipe = drawLine(55, 55, faucet.getPosition().getX(), 55, 5);
  setColor(pipe, 80, 80, 80);

}

void Simulation::start()
{
  int covertH = 0.0;
  double convertV = 0.0;
  const double PI = 3.14159;
  int i = 0;
  int fluidFill = 0;

  convertV = 3785411.78 * getWaterRate() / 60;

  covertH = convertV / (PI * pow(container.getRadius(), 2));

  faucet.turnOn();

  Color fluid_color = faucet.getFluid().getColor();


  for (i = 1; i <= (container.getHeight() / covertH); i++)
  {
    Sleep(1000);
    fluidFill = drawRect(60, 400 - covertH * i, container.getRadius() * 2, covertH);
    setColor(fluidFill, fluid_color.getRed(), fluid_color.getGreen(), fluid_color.getBlue());
//draw a black line to turn off 
      if(i== (container.getHeight() / covertH))
        {
        int line1 = drawLine( container.getRadius()+52 , 73, container.getRadius()+52 , 400- container.getHeight(), 3);

          setColor(line1, 0, 0, 0);
 
        }
 }

}