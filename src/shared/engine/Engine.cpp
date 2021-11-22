#include "Engine.h"
#include <SFML/Graphics.hpp>
using namespace engine;

//sf::Mutex engine_mutex;

Engine::Engine()
{

}

Engine::~Engine()
{

}

state::State& Engine::getCurrentState()
{
  return this->currentState;
}


void Engine::setCurrentState (state::State& currentState)
{
  this->currentState = currentState;
}

void Engine::update()
{
  //engine_mutex.lock();
  switch(this->command.getAction())
  {
    case MOVE_LEFT :
      this->currentState.move(this->currentState.getTurnID(),state::TANK,-2,0);
      this->currentState.move(this->currentState.getTurnID(),state::TURRET,-2,0);
      this->currentState.move(this->currentState.getTurnID(),state::BULLET,-2,0);
    break;
    case MOVE_RIGHT :
      this->currentState.move(this->currentState.getTurnID(),state::TANK,2,0);
      this->currentState.move(this->currentState.getTurnID(),state::TURRET,2,0);
      this->currentState.move(this->currentState.getTurnID(),state::BULLET,2,0);
    break;
    case TURN_ANTICLOCKWISE :
      this->currentState.turn(this->currentState.getTurnID(),state::TURRET,-2);
      this->currentState.turn(this->currentState.getTurnID(),state::BULLET,-2);
    break;
    case TURN_CLOCKWISE :
      this->currentState.turn(this->currentState.getTurnID(),state::TURRET,2);
      this->currentState.turn(this->currentState.getTurnID(),state::BULLET,2);
    break;
    case FIRE :
      this->currentState.nextTurnID();
    break;
    default : break;
  }
  //engine_mutex.lock();
  //sf::sleep(sf::milliseconds(20));
}
