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

float Physics::getVx() const
{
  return this->vx;
}

float Physics::getVy() const
{
  return this->vy;
}

void Physics::setVx(float vx)
{
  this->vx = vx;
}

void Physics::setVy(float vy)
{
  this->vy = vy;
}
