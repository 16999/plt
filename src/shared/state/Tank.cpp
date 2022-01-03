#include "Tank.h"
using namespace state;



Tank::Tank()
{
  this->width = 84;
  this->height = 69;
  this->next = &this->turret;
}

Turret& Tank::getTurret()
{
  return this->turret;
}
