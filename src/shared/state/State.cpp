#include "State.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace state;
using namespace std;

#define BLOC_SIZE 36
#define MAP_WIDTH 25
#define MAP_HEIGHT 15


State::State ()
{
  this->turnID = 0;
  this->speed = 6;
  this->g = 0.06;
  this->map.init("../res/map0.hex");
  this->player.resize(2);
  this->player[0].setData(0,GREEN_TANK);
  this->player[1].setData(1,GREY_TANK);
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

Player& State::getCurrentPlayer()
{
  return this->player[this->turnID];
}

Player& State::getAdversePlayer()
{
  return this->player[1-this->turnID];
}

int State::getPlayerID() const
{
  return this->playerID;
}

int State::getTurnID() const
{
  return this->turnID;
}

void State::setTurnID(int turnID)
{
  this->turnID = turnID;
}

float State::getG() const
{
  return this->g;
}

float State::getSpeed() const
{
  return this->speed;
}

void State::setG(float g)
{
  this->g = g;
}

void State::setSpeed(float speed)
{
  this->speed = speed;
}


void State::nextTurnID ()
{
  this->turnID = 1 - this->turnID;
}

void State::setPlayerID(int playerID)
{
  this->playerID = playerID;
}

void State::startGame ()
{
  std::cout << "GAME START" << endl;
  this->player[0].setData(0,this->player[0].getTankType());
  this->player[1].setData(1,this->player[1].getTankType());
}

void State::endGame ()
{
    this->player[this->turnID].incScore();
    if (this->turnID == this->playerID)
      std::cout << "You won !" << endl;
    else
      std::cout << "You lost !" << endl;
    std::cout << "Won = " << this->player[this->playerID].getScore() << " ; Lost = " << this->player[1-this->playerID].getScore() << endl;
}
