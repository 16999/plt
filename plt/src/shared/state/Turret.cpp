#include "Turret.h"
using namespace state;



Turret::Turret()
{
  this->width = 40;
  this->height = 12;
  this->next = &this->bullet;
}

Bullet& Turret::getBullet()
{
  return this->bullet;
}

void Turret::replaceBullet()
{
  this->next->setX(this->x);
  this->next->setY(this->y);
  this->next->setPhi(this->phi);
}
