#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
using namespace engine;
using namespace std;



//sf::Mutex engine_mutex;

Engine::Engine()
{
  std::cout << "Engine launched\nPRESS SPACE TO PLAY" << endl;
  this->status = GAMEOVER;
}

Engine::~Engine()
{

}

Status Engine::getStatus() const
{
  return this->status;
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
  switch (this->status)
  {
    case MOVING:
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
          if (currentState.getPlayer(currentState.getTurnID()).getTurret().getPhi() > -180)
          {
            currentState.getPlayer(currentState.getTurnID()).getTurret().turn(-3);
            currentState.getPlayer(currentState.getTurnID()).getBullet().turn(-3);
          }
        break;
        case TURN_CLOCKWISE :
          if (currentState.getPlayer(currentState.getTurnID()).getTurret().getPhi() < 0)
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
    break;

    case SHOOTING :
      if(currentState.getBlocType(currentState.getPlayer(currentState.getTurnID()).getBullet()) == state::NOTHING && currentState.getCollision() == false)
      {
        currentState.getPlayer(currentState.getTurnID()).getBullet().update();
        currentState.getPlayer(currentState.getTurnID()).getBullet().move(currentState.getPlayer(currentState.getTurnID()).getBullet().getVx(),currentState.getPlayer(currentState.getTurnID()).getBullet().getVy());
      }
      else
      {
        if (currentState.getCollision() == true)
        {
          std::cout << "HIT from player " << currentState.getTurnID() << "!" << endl;
          currentState.getPlayer(1-currentState.getTurnID()).setLife(currentState.getPlayer(1-currentState.getTurnID()).getLife()-currentState.getPlayer(currentState.getTurnID()).getDamage());
        }
        currentState.getPlayer(currentState.getTurnID()).getBullet().setX(currentState.getPlayer(currentState.getTurnID()).getTurret().getX());
        currentState.getPlayer(currentState.getTurnID()).getBullet().setY(currentState.getPlayer(currentState.getTurnID()).getTurret().getY());
        currentState.getPlayer(currentState.getTurnID()).getBullet().setPhi(currentState.getPlayer(currentState.getTurnID()).getTurret().getPhi());
        if (currentState.getPlayer(1-currentState.getTurnID()).getLife() > 0)
        {
          this->status = MOVING;
          currentState.nextTurnID();
        }
        else
        {
          this->status = GAMEOVER;
          currentState.endGame(currentState.getTurnID());
        }
      }
    break;

    case GAMEOVER :
      switch(action)
      {
        case FIRE :
          this->status = MOVING;
          currentState.startGame();
        break;
        default : break;
      }
    break;

    default : break;
  }

  return true;
}
