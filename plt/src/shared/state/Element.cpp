#include "Element.h"
#include <math.h>
using namespace state;

#define BLOC_SIZE 36
#define MAP_WIDTH 25
#define MAP_HEIGHT 15



Element::Element()
{
  this->x = 0;
  this->y = 0;
  this->phi = 0;
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

float Element::getX0() const
{
  return this->x0;
}

float Element::getY0() const
{
  return this->y0;
}

float Element::getPhi() const
{
  return this->phi;
}

float Element::getWidth() const
{
  return this->width;
}

float Element::getHeight() const
{
  return this->height;
}

void Element::setX(float x)
{
  this->x = x;
}

void Element::setY(float y)
{
  this->y = y;
}

void Element::setX0(float x0)
{
  this->x0 = x0;
}

void Element::setY0(float y0)
{
  this->y0 = y0;
}

void Element::setPhi(float phi)
{
  this->phi = phi;
}

void Element::setWidth(float width)
{
  this->width = width;
}

void Element::setHeight(float height)
{
  this->height = height;
}

void Element::update(float dx, float dy, float dPhi)
{
  this->phi += dPhi;
  this->x += dx;
  this->y += dy;
  if (this->next != NULL)
    this->next->update(dx,dy,dPhi);
}

void Element::replace()
{
  if (this->next != NULL)
  {
    this->next->setX(this->x);
    this->next->setY(this->y);
    this->next->setPhi(this->phi);
    this->next->replace();
  }
}

BlocType Element::getBlocType (Map map)
{
  int index = floor(this->x/BLOC_SIZE)+(MAP_WIDTH*floor(this->y/BLOC_SIZE));

  if (index >= 0 && index < MAP_WIDTH*MAP_HEIGHT)
  {
    char val = map.getBloc()[index];
    switch (val)
    {
      case 0x7 : return LEFT_BORDER;  break;
      case 0x8 : return PRACTICABLE;  break;
      case 0x9 : return RIGHT_BORDER;  break;
      default : return NOTHING; break;
    }
  }
  else
  {
      return INVALID;
  }
}

bool Element::intersects (Element element)
{
  if ((element.getX() - element.getX0() < this->x - this->x0 + this->width)
  && (element.getX() - element.getX0() + element.getWidth() > this->x - this->x0)
  && (element.getY() - element.getY0() < this->y - this->y0 + this->height)
  && (element.getY() - element.getY0() + element.getHeight() > this->y - this->y0))
    return true;
  else
    return false;
}
