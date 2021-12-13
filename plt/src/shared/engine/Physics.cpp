#include "Physics.h"
using namespace engine;



Physics::Physics()
{
  this->inc = 3;
  this->v0 = 6;
  this->g = 0.06;
}

Physics::~Physics()
{

}

float Physics::getInc() const
{
  return this->inc;
}

float Physics::getG() const
{
  return this->g;
}

float Physics::getV0() const
{
  return this->v0;
}
