#include "Element.h"
using namespace state;

Element::Element()
{
    float x,y;
}

Element::~Element()
{

}

float Element::getX() const
{
  return this->x;
}

float Element::getY() const
{
  return this->y;
}

float Element::getAngle() const
{
  return this->angle;
}

void Element::setX(float x)
{
  this->x = x;
}

void Element::setY(float y)
{
  this->y = y;
}

void Element::setAngle(float angle)
{
  this->angle = angle;
}

void Element::move(float dx, float dy)
{
  this->x += dx;
  this->y += dy;
}

void Element::turn(float dPhi)
{
  this->angle += dPhi;
}
