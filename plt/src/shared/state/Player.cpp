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
  "STATUS=" + to_string((int)this->status) +
  " - ID=" + to_string(this->ID) +
  " - TYPE=" + to_string(this->tankType) +
  " - LIFE=" + to_string(this->life) +
  " - DAMAGE=" + to_string(this->damage)+
  " - Tank:(" + to_string((int)this->tank.getX()) +
  ";" + to_string((int)this->tank.getY()) +
  ";" + to_string((int)this->tank.getPhi()) +
  "d)";
  if (this->status == GAMEOVER)
    data += " - PRESS ENTER TO START GAME";
  return data;
}

int Player::getID() const
{
  return this->ID;
}

Status Player::getStatus() const
{
  return this->status;
}

void Player::setStatus(Status status)
{
  this->status = status;
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
  this->tank.setX0(this->tank.getWidth()/2);
  this->tank.setY0(this->tank.getHeight());
  this->tank.getTurret().setX(IDvectorX[ID]);
  this->tank.getTurret().setY(IDvectorY[ID]-62);
  this->tank.getTurret().setX0(0);
  this->tank.getTurret().setY0(this->tank.getTurret().getHeight()/2);
  this->tank.getTurret().setPhi(IDvectorPhi[ID]);
  this->tank.getTurret().getBullet().setX(IDvectorX[ID]);
  this->tank.getTurret().getBullet().setY(IDvectorY[ID]-62);
  this->tank.getTurret().getBullet().setX0(this->tank.getTurret().getBullet().getWidth()/2);
  this->tank.getTurret().getBullet().setY0(this->tank.getTurret().getBullet().getHeight()/2);
  this->tank.getTurret().getBullet().setPhi(IDvectorPhi[ID]);
}
