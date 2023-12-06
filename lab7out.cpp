//Zi Wang
//Lab7out
//fluid fill

#include"Container.h"
#include"Fluid.h"
#include"Faucet.h"
#include"Simulation.h"
#include <iostream>
#include<cmath>
#include <iomanip>
#include <string>
#include "graph1.h"
using namespace std;

int main()
{
  //Variable Declaration/Initialization
  int height = 0;
  int radius = 0;
  int waterRate = 0;
  int r = 0;
  int b = 0;
  int g = 0;
  string fluidName = "";
  char repeat;
  Container container;
  Simulation simulation;
  Color col;
  GenPoint position;
  GenPoint FluidStart;
  GenPoint FluidEnd;
  GenPoint UpperLeft;
  GenPoint FaucetPos;
  Fluid fluid;
  Faucet faucet;


  //Display the graphics
  displayGraphics();

  //Continually simulate

  do
  {
    

    do
    {
      //Get the fluid rate (Add Data Validation)
      cout << "Enter fluid rate between 1 to 30 gallons/minute: ";
      cin >> waterRate;
      if (waterRate < 1 || waterRate>30)
      {
        cout << "Error invalid input. try again.\n";
      }
    } while (waterRate < 1 || waterRate>30);

   do
   {
      //Get the Container's radius/height/color (Add Data Validation)
    cout<<"Enter radius of container (between 10 and 255): ";
    cin>> radius;
     if (radius < 10 || radius>285)
    {
        cout<<"Error invalid input. try again.\n";
    }
   }  while(radius<10||radius>285);

   do
   {
     //Get the Container's radius/height/color (Add Data Validation)
     cout << "Enter height of container (between 10 and 300): ";
     cin >> height;
     if (height < 10 || height>300)
     {
       cout << "Error invalid input. try again.\n";
     }
   } while (height < 10 || height>300);

   do
  {

    cout<<"Enter color of container: ";
    cin>>r>>g>>b;

    if (r < 0 || r>255 || g < 0 || g>255 || b < 0 || b>255)
    {
      cout<<"Error invalid input. R/G/B values  try again";
    }   
   }while (r < 0 || r>255 || g < 0 || g>255 || b < 0 || b>255);


// prompt for fluid name
   cout << "Enter fluid name <water, oil, diesel>: ";
    cin>>fluidName;


    //Set the Containers radius/height /color
    col.setCol(r,g,b);
    container.setRadius(radius);
    container.setHeight(height);
    container.setCol(col);
    
    //Compute the Container upper left coordinate based on the height
     position.setPoint(60, 400-height);
    
  //Set the Container’s position
      container.setPosition(position);
  
    //Hint: 55, 400 - height
    //set the start and end
      FluidStart.setPoint(60 + radius - 64, height);
      FluidEnd.setPoint(60 + radius - 5, 400 - height);

      //set the fluid
      fluid.setStart(FluidStart);
      fluid.setEnd(FluidEnd);
      fluid.setFluidName(fluidName);
      fluid.setFillLine(container.getHeight());

      //set the faucet
      FaucetPos.setPoint(60 + radius - 64, 0);
      faucet.setPosition(FaucetPos);
      faucet.setFluid(fluid);
     

      //setter for waterrate
      simulation.setWaterRate(waterRate);
    //Setter for the Simulation
      simulation.setContainer(container);
      simulation.setWaterRate(waterRate);
      simulation.setFaucet(faucet);
      simulation.draw();
      simulation.start();
      container.draw();
 
    //Repeat the simulation?
    cout << "Repeat the simulation (y/n)? ";
    cin >> repeat;

    clearGraphics();
    system("cls");

  } while (repeat == 'y');

  return 0;
}
