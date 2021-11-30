#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <math.h>
using namespace engine;




//sf::Mutex engine_mutex;

Engine::Engine()
{
  this->status = MOVING;
}

Engine::~Engine()
{

}

Command& Engine::getCommand()
{
  return this->command;
}

void Engine::setCommand(Command& command)
{
  this->command = command;
}

bool Engine::update(state::State& currentState, Action action)
{
  if (this->status == MOVING)
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
        currentState.getPlayer(currentState.getTurnID()).getBullet().init();
        this->status = SHOOTING;
      break;
      default : return false;
    }
  }
  else if (this->status == SHOOTING)
  {

    if(currentState.getBlocType(currentState.getPlayer(currentState.getTurnID()).getBullet()) == state::NOTHING)
    {
      currentState.getPlayer(currentState.getTurnID()).getBullet().update();
      currentState.getPlayer(currentState.getTurnID()).getBullet().move(currentState.getPlayer(currentState.getTurnID()).getBullet().getVx(),currentState.getPlayer(currentState.getTurnID()).getBullet().getVy());
    }
    else
    {
      currentState.getPlayer(currentState.getTurnID()).getBullet().setX(currentState.getPlayer(currentState.getTurnID()).getTurret().getX());
      currentState.getPlayer(currentState.getTurnID()).getBullet().setY(currentState.getPlayer(currentState.getTurnID()).getTurret().getY());
      currentState.getPlayer(currentState.getTurnID()).getBullet().setAngle(currentState.getPlayer(currentState.getTurnID()).getTurret().getAngle());
      currentState.nextTurnID();
      this->status = MOVING;
    }

  }

  //test();
  return true;
}
