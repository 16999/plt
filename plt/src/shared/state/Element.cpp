#include "Element.h"
using namespace state;

Element::Element()
{

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

float Element::getPhi() const
{
  return this->phi;
}

void Element::setX(float x)
{
  this->x = x;
}

void Element::setY(float y)
{
  this->y = y;
}

void Element::setPhi(float phi)
{
  this->phi = phi;
}

void Element::move(float dx, float dy)
{
  this->x += dx;
  this->y += dy;
}

void Element::turn(float dPhi)
{
  this->phi += dPhi;
}
