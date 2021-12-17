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

float Physics::getT() const
{
  return this->t;
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

float Physics::getTheta() const
{
  return this->theta;
}

void Physics::setInc(float inc)
{
  this->inc = inc;
}

void Physics::setG(float g)
{
  this->g = g;
}

void Physics::setT(float t)
{
  this->t = t;
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

void Physics::setTheta(float theta)
{
  this->theta = theta;
}
