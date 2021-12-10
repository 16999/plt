#include "Bullet.h"
#include <math.h>
using namespace state;



Bullet::Bullet()
{
  this->v0 = 6;
  this->g = 0.06;
}

void Bullet::init()
{
  this->t = 0;
}

void Bullet::update()
{
  if (this->t == 0)
    this->theta = this->phi;
  this->vx = this->v0*cos(this->theta/57.2958);
  this->vy = this->v0*sin(this->theta/57.2958) + this->g * this->t;
  this->phi = 57.2958*atan(this->vy/this->vx)+180*(this->vx<0);
  this->t++;
}

float Bullet::getVx() const
{
  return this->vx;
}

float Bullet::getVy() const
{
  return this->vy;
}

float Bullet::getTheta() const
{
  return this->theta;
}

float Bullet::getG() const
{
  return this->g;
}

float Bullet::getV0() const
{
  return this->v0;
}
