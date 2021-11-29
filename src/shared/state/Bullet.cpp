#include "Bullet.h"
#include <math.h>
using namespace state;

Bullet::Bullet()
{
  this->v0 = 5;
  this->g = 0.05;
  this->t = 0;
}

void Bullet::init()
{

}

void Bullet::update()
{
  if (t == 0)
  {
    this->theta = this->angle;
  }

  this->vx = this->v0*cos(this->theta/57.2958);
  this->vy = this->v0*sin(this->theta/57.2958) + this->g * this->t;

  if (this->vx > 0)
    this->angle = 57.2958*atan(this->vy/this->vx);
  else
    this->angle = 57.2958*atan(this->vy/this->vx)+180;

  t++;
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
