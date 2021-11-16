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
  this->player.resize(2);
  this->player[0].setData(0,GREY_TANK);
  this->player[1].setData(1,GREEN_TANK);
  this->map.init("../res/map.hex");
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

void State::endGame ()
{

}
