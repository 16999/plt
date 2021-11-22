#include "Command.h"
#include <SFML/Graphics.hpp>
using namespace engine;


Command::Command()
{

}

Command::~Command()
{

}

Action Command::getAction() const
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
    return MOVE_LEFT;}
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
    return MOVE_RIGHT;}
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
    return TURN_ANTICLOCKWISE;}
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
    return TURN_CLOCKWISE;}
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
    return FIRE;}
  else{
    return NOTHING;}
}
