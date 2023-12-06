#include <iostream>
#include <cmath>
#include "graph1.h"
#include "Container.h"

Container::Container()
{
   radius = 0;
   height = 0;
   pos.setPoint(0, 0);
   color.setCol(0,0,0);

}

void Container::setPosition(GenPoint pos)
{
   this->pos.setPoint(pos.getX(), pos.getY());
}

void Container::setRadius(int radius)
{
   this->radius = radius;
}

void Container::setHeight(int height)
{
  this->height = height;

}

void Container::setCol(Color color)
{
  this->color.setCol(color.getRed(), color.getGreen(),color.getBlue());
}

GenPoint Container::getPosition()
{
  return pos;
}

int Container::getRadius()
{
  return radius;
}

int Container::getHeight()
{
  return height;
}

Color Container::getColor()
{
  return color;
}

void Container::draw()
{
//leftline
  int line = 0;
  line = drawLine(pos.getX(), pos.getY(),pos.getX(),pos.getY() + height,5);
  setColor(line, color.getRed(), color.getGreen(), color.getBlue());
  // right line
  line = drawLine(pos.getX() + radius*2, pos.getY(), pos.getX()+ radius*2, pos.getY()+height,5);
  setColor(line, color.getRed(), color.getGreen(), color.getBlue());
//base line
line = drawLine( pos.getX(), pos.getY()+ height, pos.getX()+ radius*2, pos.getY()+height, 5);
setColor(line, color.getRed(), color.getGreen(), color.getBlue());



}
