#include "Turret.h"
using namespace state;



Turret::Turret()
{
  this->next = &this->bullet;
}

Bullet& Turret::getBullet()
{
  return this->bullet;
}
/*
void Turret::update(float dx, float dy, float dPhi, Map map)
{
  this->x += dx;
  this->y += dy;
  if ((this->phi > -180 && dPhi < 0) || (this->phi < 0 && dPhi > 0))
  {
    this->phi += dPhi;
    this->bullet.update(dx,dy,dPhi,map);
  }
  else
  {
    this->bullet.update(dx,dy,0,map);
  }
}*/
