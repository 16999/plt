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
  "\nPLAYER STATUS = " + to_string(this->playerStatus) +
  "\nLIFE = " + to_string(this->life) +
  "\nDAMAGE = " + to_string(this->damage)+
  "\nTank : X = " + to_string((int)this->tank.getX()) +
  "; Y = " + to_string((int)this->tank.getY()) +
  "; Phi = " + to_string((int)this->tank.getAngle()) +
  "\nWeapon : X = " + to_string((int)this->weapon.getX()) +
  "; Y = " + to_string((int)this->weapon.getY()) +
  "; Phi = " + to_string((int)this->weapon.getAngle());
  return data;
}

void Player::setID(int ID)
{
  this->ID = ID;
}

void Player::setTankType(int tankType)
{
  this->tankType = tankType;
}

void Player::setPlayerStatus(int playerStatus)
{
  this->playerStatus = playerStatus;
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

const Weapon& Player::getWeapon() const
{
  return this->weapon;
}

int Player::getTankType() const
{
  return this->tankType;
}

void Player::setData(int ID, int tankType)
{
  int lifeVector[] = {60,80,100};
  int damageVector[] = {25,20,15};
  int IDvectorX[] = {70,430};
  int IDvectorY[] = {363,364};
  this->ID = ID;
  this->tankType = tankType;
  this->life = lifeVector[ID];
  this->damage = damageVector[ID];
  this->playerStatus = 999;
  this->tank.setX(IDvectorX[this->ID]);
  this->tank.setY(IDvectorY[this->ID]);
}

void Player::move(int elemType, float dx, float dy)
{
  switch(elemType)
  {
    case TANK: this->tank.move(dx,dy); break;
    case WEAPON: this->weapon.move(dx,dy); break;
    default: break;
  }

}
