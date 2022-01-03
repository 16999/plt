#include "Physics.h"
using namespace engine;



Physics::Physics()
{
  //this->v0 = 6;
  //this->g = 0.06;
}

Physics::~Physics()
{

}

float Physics::getDx() const
{
  return this->dx;
}

float Physics::getDy() const
{
  return this->dy;
}

void Physics::setDx(float dx)
{
  this->dx = dx;
}

void Physics::setDy(float dy)
{
  this->dy = dy;
}
