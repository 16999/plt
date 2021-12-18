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
  "ID=" + to_string(this->ID) +
  " - TYPE=" + to_string(this->tankType) +
  " - LIFE=" + to_string(this->life) +
  " - DAMAGE=" + to_string(this->damage)+
  " - Tank:(" + to_string((int)this->tank.getX()) +
  ";" + to_string((int)this->tank.getY()) +
  ";" + to_string((int)this->tank.getPhi()) +
  "d)";
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

Tank& Player::getTank()
{
  return this->tank;
}

TankType Player::getTankType() const
{
  return this->tankType;
}

int Player::getLife() const
{
  return this->life;
}

int Player::getDamage() const
{
  return this->damage;
}

void Player::setData(int ID, TankType tankType)
{
  int lifeVector[] = {60,80,100};
  int damageVector[] = {25,20,15};
  int IDvectorX[] = {196,704};
  int IDvectorY[] = {433,433};
  int IDvectorPhi[] = {-45,-135};
  this->ID = ID;
  this->tankType = tankType;
  this->life = lifeVector[tankType];
  this->damage = damageVector[tankType];
  this->tank.setX(IDvectorX[ID]);
  this->tank.setY(IDvectorY[ID]);
  this->tank.getTurret().setX(IDvectorX[ID]);
  this->tank.getTurret().setY(IDvectorY[ID]-62);
  this->tank.getTurret().setPhi(IDvectorPhi[ID]);
  this->tank.getTurret().getBullet().setX(IDvectorX[ID]);
  this->tank.getTurret().getBullet().setY(IDvectorY[ID]-62);
  this->tank.getTurret().getBullet().setPhi(IDvectorPhi[ID]);
}
