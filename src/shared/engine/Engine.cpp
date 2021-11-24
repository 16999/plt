#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <math.h>
using namespace engine;


#include <unistd.h>
#include <iostream>
using namespace std;



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

bool Engine::apply(state::State& currentState, Action action)
{
  switch(action)
  {
    case MOVE_LEFT :
      if (currentState.getBlocType(currentState.getPlayer()[currentState.getTurnID()].getTank()) != state::LEFT_BORDER)
      {
        currentState.move(currentState.getTurnID(),state::TANK,-3,0);
        currentState.move(currentState.getTurnID(),state::TURRET,-3,0);
        currentState.move(currentState.getTurnID(),state::BULLET,-3,0);
      }
    break;
    case MOVE_RIGHT :
      if (currentState.getBlocType(currentState.getPlayer()[currentState.getTurnID()].getTank()) != state::RIGHT_BORDER)
      {
        currentState.getBlocType(currentState.getPlayer()[currentState.getTurnID()].getTank());
        currentState.move(currentState.getTurnID(),state::TANK,3,0);
        currentState.move(currentState.getTurnID(),state::TURRET,3,0);
        currentState.move(currentState.getTurnID(),state::BULLET,3,0);
      }
    break;
    case TURN_ANTICLOCKWISE :
    if (currentState.getPlayer()[currentState.getTurnID()].getTurret().getAngle() > -180)
    {
      currentState.turn(currentState.getTurnID(),state::TURRET,-3);
      currentState.turn(currentState.getTurnID(),state::BULLET,-3);
    }
    break;
    case TURN_CLOCKWISE :
    if (currentState.getPlayer()[currentState.getTurnID()].getTurret().getAngle() < 0)
    {
      currentState.turn(currentState.getTurnID(),state::TURRET,3);
      currentState.turn(currentState.getTurnID(),state::BULLET,3);
    }
    break;
    case FIRE :
      //currentState.getPlayer()[currentState.getTurnID()].setPlayerStatus(state::SHOOTING);

      /*while(currentState.getBlocType(currentState.getPlayer()[currentState.getTurnID()].getBullet()) == state::NOTHING)
      {
        currentState.move(currentState.getTurnID(),state::BULLET,1*cos(currentState.getPlayer()[currentState.getTurnID()].getBullet().getAngle()/57.2958),1*sin(currentState.getPlayer()[currentState.getTurnID()].getBullet().getAngle()/57.2958));
      }*/
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
