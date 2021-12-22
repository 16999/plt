#include "Physics.h"
using namespace engine;



Physics::Physics()
{
  this->v0 = 6;
  this->g = 0.06;
}

Physics::~Physics()
{

}

float Physics::getG() const
{
  return this->g;
}

float Physics::getV0() const
{
  return this->v0;
}

float Physics::getVx() const
{
  return this->vx;
}

float Physics::getVy() const
{
  return this->vy;
}

void Physics::setG(float g)
{
  this->g = g;
}

void Physics::setV0(float v0)
{
  this->v0 = v0;
}

void Physics::setVx(float vx)
{
  this->vx = vx;
}

void Physics::setVy(float vy)
{
  this->vy = vy;
}
