#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <math.h>
using namespace engine;




//sf::Mutex engine_mutex;

Engine::Engine()
{
  this->currentState.setStatus(state::MOVING);
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

bool Engine::update(state::State& currentState, Action action)
{
  if (this->currentState.getStatus() == state::MOVING)
  {
    switch(action)
    {
      case MOVE_LEFT :
        if (currentState.getBlocType(currentState.getPlayer(currentState.getTurnID()).getTank()) != state::LEFT_BORDER)
        {
          currentState.getPlayer(currentState.getTurnID()).getTank().move(-3,0);
          currentState.getPlayer(currentState.getTurnID()).getTurret().move(-3,0);
          currentState.getPlayer(currentState.getTurnID()).getBullet().move(-3,0);
        }
      break;
      case MOVE_RIGHT :
        if (currentState.getBlocType(currentState.getPlayer(currentState.getTurnID()).getTank()) != state::RIGHT_BORDER)
        {
          currentState.getPlayer(currentState.getTurnID()).getTank().move(3,0);
          currentState.getPlayer(currentState.getTurnID()).getTurret().move(3,0);
          currentState.getPlayer(currentState.getTurnID()).getBullet().move(3,0);
        }
      break;
      case TURN_ANTICLOCKWISE :
        if (currentState.getPlayer(currentState.getTurnID()).getTurret().getAngle() > -180)
        {
          currentState.getPlayer(currentState.getTurnID()).getTurret().turn(-3);
          currentState.getPlayer(currentState.getTurnID()).getBullet().turn(-3);
        }
      break;
      case TURN_CLOCKWISE :
        if (currentState.getPlayer(currentState.getTurnID()).getTurret().getAngle() < 0)
        {
          currentState.getPlayer(currentState.getTurnID()).getTurret().turn(3);
          currentState.getPlayer(currentState.getTurnID()).getBullet().turn(3);
        }
      break;
      case FIRE :
        this->currentState.setStatus(state::SHOOTING);
      break;
      default : return false;
    }
  }
  else if (this->currentState.getStatus() == state::SHOOTING)
  {

    if(currentState.getBlocType(currentState.getPlayer(currentState.getTurnID()).getBullet()) == state::NOTHING)
    {
        currentState.getPlayer(currentState.getTurnID()).getBullet().update();
        currentState.getPlayer(currentState.getTurnID()).getBullet().move(currentState.getPlayer(currentState.getTurnID()).getBullet().getVx(),currentState.getPlayer(currentState.getTurnID()).getBullet().getVy());
    }
    else
    {
      currentState.nextTurnID();
      this->currentState.setStatus(state::MOVING);
    }

  }


  return true;
}

state::State& Engine::getCurrentState()
{
  return currentState;
}
