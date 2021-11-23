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

Action Engine::convert(sf::Event event)
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

void Engine::setAction(Action action)
{
  this->action = action;
}

Action Engine::getAction() const
{
  return this->action;
}

bool Engine::apply(state::State& currentState, Action action)
{
  switch(action)
  {
    case MOVE_LEFT :
      currentState.move(currentState.getTurnID(),state::TANK,-2,0);
      currentState.move(currentState.getTurnID(),state::TURRET,-2,0);
      currentState.move(currentState.getTurnID(),state::BULLET,-2,0);
    break;
    case MOVE_RIGHT :
      currentState.move(currentState.getTurnID(),state::TANK,2,0);
      currentState.move(currentState.getTurnID(),state::TURRET,2,0);
      currentState.move(currentState.getTurnID(),state::BULLET,2,0);
    break;
    case TURN_ANTICLOCKWISE :
      currentState.turn(currentState.getTurnID(),state::TURRET,-2);
      currentState.turn(currentState.getTurnID(),state::BULLET,-2);
    break;
    case TURN_CLOCKWISE :
      currentState.turn(currentState.getTurnID(),state::TURRET,2);
      currentState.turn(currentState.getTurnID(),state::BULLET,2);
    break;
    case FIRE :
      currentState.nextTurnID();
    break;
    default : return false;
  }
  return true;
}

state::State& Engine::getCurrentState()
{
  return currentState;
}
