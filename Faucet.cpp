#include <iostream>
#include "graph1.h"
#include <cmath>
#include "Fluid.h"
#include "Faucet.h"
#include "GenPoint.h"
#include"Container.h"

using namespace std;

Faucet::Faucet()
{
	pos.setPoint(0,0);
	fluid.setFillLine(0) ;
	Container container;
}

void Faucet::turnOn()
{

	int line = drawLine(pos.getX() + 55, pos.getY()+72, pos.getX()+55 ,400, 2);
	Color color = fluid.getColor();
	setColor(line, color.getRed(), color.getGreen(), color.getBlue());
}

void Faucet::turnOff()
{
 
	int line = drawLine(pos.getX() + 55, pos.getY() + 72, pos.getX() + 55, 400-fluid.getFillLine(), 2);
	setColor(line,200,0,0);
}

void Faucet::setPosition(GenPoint upper)
{
	pos.setPoint(upper.getX(), upper.getY());
}

GenPoint Faucet::getPosition()
{
	return pos;
}

void Faucet::setFluid(Fluid fluid)
{
	this->fluid.setStart(fluid.getStart());
	this->fluid.setEnd(fluid.getEnd());
	this->fluid.setFluidName(fluid.getFluidName());
}

Fluid Faucet::getFluid()
{
	return fluid;
}

void Faucet::draw()
{
	displayBMP("faucet.BMP", pos.getX(), 17);
}