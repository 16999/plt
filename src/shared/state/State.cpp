#include "State.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace state;
using namespace std;

#define BLOC_SIZE 36
#define MAP_WIDTH 20
#define MAP_HEIGHT 15


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
  this->status = MOVING;
}

void State::setStatus(Status status)
{
  this->status = status;
}

Status State::getStatus() const
{
  return this->status;
}

BlocType State::getBlocType (Element element)
{
  BlocType ret;
  int index = floor(element.getX()/BLOC_SIZE)+(MAP_WIDTH*floor(element.getY()/BLOC_SIZE));

  if (index >= 0 && index < MAP_WIDTH*MAP_HEIGHT)
  {
    char val = this->map.getBloc()[index];
    switch (val)
    {
      case 0x7 : ret = LEFT_BORDER;  break;
      case 0x8 : ret = PRACTICABLE;  break;
      case 0x9 : ret = RIGHT_BORDER;  break;
      default : ret = NOTHING; break;
    }
  }
  else
  {
      ret = INVALID;
  }

  return ret;
}

void State::endGame ()
{

}
