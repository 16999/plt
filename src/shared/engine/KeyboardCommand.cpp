#include "KeyboardCommand.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace engine;
using namespace std;


KeyboardCommand::KeyboardCommand(int commandID)
{
  this->commandID = commandID;
}

KeyboardCommand::~KeyboardCommand()
{

}

Action KeyboardCommand::run(state::State& currentState, Status status)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      return MOVE_LEFT;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      return MOVE_RIGHT;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
      return TURN_ANTICLOCKWISE;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
      return TURN_CLOCKWISE;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
      return FIRE;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
      return START_GAME;
    else
      return NO_ACTION;
}
