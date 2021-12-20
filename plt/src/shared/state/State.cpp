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
    if (this->turnID == this->playerID)
    {
      std::cout << "You won !" << endl;
      this->won++;
    }
    else
    {
      std::cout << "You lost !" << endl;
      this->lost++;
    }
    std::cout << "Won = " << this->won << " ; Lost = " << this->lost << " ; Efficiency = " << 100*this->won/(this->won+this->lost) << "%" << endl;
    this->turnID = 0;
}
