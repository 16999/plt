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

void Element::update(float dx, float dy, float dPhi, Map map)
{
  this->phi += dPhi;
  this->x += dx;
  this->y += dy;
  if (this->next != NULL)
    this->next->update(dx,dy,dPhi,map);
}

BlocType Element::getBlocType (Map map)
{
  BlocType ret;
  int index = floor(this->x/BLOC_SIZE)+(MAP_WIDTH*floor(this->y/BLOC_SIZE));

  if (index >= 0 && index < MAP_WIDTH*MAP_HEIGHT)
  {
    char val = map.getBloc()[index];
    switch (val)
    {
      case 0x7 : ret = LEFT_BORDER;  break;
      case 0x8 : ret = PRACTICABLE;  break;
      case 0x9 : ret = RIGHT_BORDER;  break;
      default : ret = NOTHING; break;
    }
  }
  else
  {
      ret = INVALID;
  }

  return ret;
}
