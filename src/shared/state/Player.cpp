#include "Player.h"
#include <iostream>
#include <string>
using namespace state;
using namespace std;



Player::Player()
{

}

Player::~Player()
{

}

std::string Player::getTextData() const
{
  std::string data =
  "PLAYER ID = " + to_string(this->ID) +
  "\nTANK TYPE = " + to_string(this->tankType) +
  "\nLIFE = " + to_string(this->life) +
  "\nDAMAGE = " + to_string(this->damage)+
  "\nTank : X = " + to_string((int)this->tank.getX()) +
  "; Y = " + to_string((int)this->tank.getY()) +
  "; Phi = " + to_string((int)this->tank.getAngle()) +
  "\nWeapon : X = " + to_string((int)this->bullet.getX()) +
  "; Y = " + to_string((int)this->bullet.getY()) +
  "; Phi = " + to_string((int)this->bullet.getAngle());
  return data;
}

int Player::getID() const
{
  return this->ID;
}

void Player::setID(int ID)
{
  this->ID = ID;
}

void Player::setTankType(TankType tankType)
{
  this->tankType = tankType;
}

void Player::setLife(int life)
{
  this->life = life;
}

void Player::setDamage(int damage)
{
  this->damage = damage;
}

const Tank& Player::getTank() const
{
  return this->tank;
}

const Turret& Player::getTurret() const
{
  return this->turret;
}

const Bullet& Player::getBullet() const
{
  return this->bullet;
}

TankType Player::getTankType() const
{
  return this->tankType;
}

void Player::setData(int ID, TankType tankType)
{
  int lifeVector[] = {60,80,100};
  int damageVector[] = {25,20,15};
  int IDvectorX[] = {70,530};
  int IDvectorY[] = {433,433};
  this->ID = ID;
  this->tankType = tankType;
  this->life = lifeVector[ID];
  this->damage = damageVector[ID];
  this->tank.setX(IDvectorX[ID]);
  this->tank.setY(IDvectorY[ID]);
  this->turret.setX(IDvectorX[ID]);
  this->turret.setY(IDvectorY[ID]-62);
  this->turret.setAngle(-90);
  this->bullet.setX(IDvectorX[ID]);
  this->bullet.setY(IDvectorY[ID]-62);
  this->bullet.setAngle(-90);
}

void Player::move(ElemType elemType, float dx, float dy)
{
  switch(elemType)
  {
    case TANK: this->tank.move(dx,dy); break;
    case TURRET: this->turret.move(dx,dy); break;
    case BULLET: this->bullet.move(dx,dy); break;
    default: break;
  }

}

void Player::turn(ElemType elemType, float dPhi)
{
  switch(elemType)
  {
    case TANK: this->tank.turn(dPhi); break;
    case TURRET: this->turret.turn(dPhi); break;
    case BULLET: this->bullet.turn(dPhi); break;
    default: break;
  }

}
