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
  "d) - Turret:(" + to_string((int)this->turret.getX()) +
  ";" + to_string((int)this->turret.getY()) +
  ";" + to_string((int)this->turret.getPhi()) +
  "d) - Bullet:(" + to_string((int)this->bullet.getX()) +
  ";" + to_string((int)this->bullet.getY()) +
  ";" + to_string((int)this->bullet.getPhi()) +
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

Turret& Player::getTurret()
{
  return this->turret;
}

Bullet& Player::getBullet()
{
  return this->bullet;
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
  this->turret.setX(IDvectorX[ID]);
  this->turret.setY(IDvectorY[ID]-62);
  this->turret.setPhi(IDvectorPhi[ID]);
  this->bullet.setX(IDvectorX[ID]);
  this->bullet.setY(IDvectorY[ID]-62);
  this->bullet.setPhi(IDvectorPhi[ID]);
}


void Player::move(float dx, float dy, Map map)
{
  if ((this->tank.getBlocType(map) != state::LEFT_BORDER && dx < 0) || (this->tank.getBlocType(map) != state::RIGHT_BORDER && dx > 0))
  {
    this->tank.move(dx,dy);
    this->turret.move(dx,dy);
    this->bullet.move(dx,dy);
  }
}

void Player::turn(float dPhi)
{
  if ((this->turret.getPhi() > -180 && dPhi < 0) || (this->turret.getPhi() < 0 && dPhi > 0))
  {
    this->turret.turn(dPhi);
    this->bullet.turn(dPhi);
  }
}
