#include "Tank.h"
using namespace state;



Tank::Tank()
{
  this->next = &this->turret;
}

Turret& Tank::getTurret()
{
  return this->turret;
}
/*
void Tank::update(float dx, float dy, float dPhi, Map map)
{
  this->phi += dPhi;
  if ((this->getBlocType(map) != state::LEFT_BORDER && dx < 0) || (this->getBlocType(map) != state::RIGHT_BORDER && dx > 0))
  {
    this->x += dx;
    this->y += dy;
    this->turret.update(dx,dy,dPhi,map);
  }
}*/
