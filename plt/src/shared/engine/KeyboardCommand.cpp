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

void KeyboardCommand::run(Engine& ngine)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      ngine.setAction(MOVE_LEFT);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      ngine.setAction(MOVE_RIGHT);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
      ngine.setAction(TURN_ANTICLOCKWISE);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
      ngine.setAction(TURN_CLOCKWISE);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
      ngine.setAction(FIRE);
    else
      ngine.setAction(NO_ACTION);
}
