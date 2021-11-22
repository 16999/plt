#include "State.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace state;
using namespace std;



State::State ()
{
  std::cout << "Welcome to TANKS GAME" << endl;
  this->map.init("../res/map.hex");
  this->player.resize(2);
  this->player[0].setData(0,GREY_TANK);
  this->player[1].setData(1,GREEN_TANK);
}

State::~State ()
{
  this->player.end();
}

const Map& State::getMap() const
{
  return this->map;
}

const std::vector<Player>& State::getPlayer() const
{
  return this->player;
}

int State::getPlayerID() const
{
  return this->playerID;
}

int State::getTurnID() const
{
  return this->turnID;
}

void State::move (int ID, ElemType elemType, float dx, float dy)
{
  this->player[ID].move(elemType,dx,dy);
}

void State::turn (int ID, ElemType elemType, float dPhi)
{
  this->player[ID].turn(elemType,dPhi);
}

void State::nextTurnID ()
{
  this->turnID = 1 - this->turnID;
}

void State::endGame ()
{

}
