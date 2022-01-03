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
