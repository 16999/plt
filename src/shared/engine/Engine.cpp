#include "Engine.h"
#include <SFML/Graphics.hpp>
using namespace engine;



Engine::Engine()
{

}

Engine::~Engine()
{

}

state::State& Engine::getCurrentState()
{

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
    this->currentState.move(0,state::TANK,-0.5,0);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
    this->currentState.move(0,state::TANK,0.5,0);
  }
  /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
    this->currentState.move(0,state::TANK,0.5,0);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
    this->currentState.move(0,state::TANK,0.5,0);
  }*/

  return this->currentState;
}
