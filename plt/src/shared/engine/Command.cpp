#include "Command.h"
#include <SFML/Graphics.hpp>
using namespace engine;


Action Command::convert(sf::Event event)
{
  switch(event.key.code)
  {
    case sf::Keyboard::Left : return MOVE_LEFT;       break;
    case sf::Keyboard::Right : return MOVE_RIGHT;     break;
    case sf::Keyboard::W : return TURN_ANTICLOCKWISE; break;
    case sf::Keyboard::X : return TURN_CLOCKWISE;     break;
    case sf::Keyboard::Space : return FIRE;           break;
    default : return NOTHING;
  }
}

void Command::setAction(Action action)
{
  this->action = action;
}

Action Command::getAction() const
{
  return this->action;
}
