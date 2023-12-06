#include <iostream>
#include "graph1.h"
#include "Fluid.h"
#include <string>
#include "GenPoint.h"
#include "Color.h"
#include <cmath>

using namespace std;

Fluid::Fluid()
{
	start.setPoint(0,0);
	end.setPoint(0,0);
	container.getHeight();
	fluidName = "";
	fillLine = 0;
}

void Fluid::setStart(GenPoint start)
{
	this->start.setPoint(start.getX(), start.getY());
}

void Fluid::setEnd(GenPoint end)
{
	this->end.setPoint(end.getX(), end.getY());
}

void Fluid::setFluidName(string name)
{
	this->fluidName = name;
}

void Fluid::setFillLine(int fillLine)
{
	this->fillLine=fillLine;
}

GenPoint Fluid::getStart()
{
	return start;
}

GenPoint Fluid::getEnd()
{
	return end;
}

int Fluid::getFillLine()
{
	return fillLine;
}

Color Fluid::getColor()
{
	Color color;
	if (fluidName == "water")
		color.setCol(0, 0, 255);
	else if (fluidName == "oil")
		color.setCol(142, 70, 70);
	else
		color.setCol(255, 0, 255);

	return color;
}

string Fluid::getFluidName()
{
	return fluidName;
}