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
          if (currentState.getBlocType(currentState.getCurrentPlayer().getTank()) != state::LEFT_BORDER)
          {
            currentState.getCurrentPlayer().getTank().move(-3,0);
            currentState.getCurrentPlayer().getTurret().move(-3,0);
            currentState.getCurrentPlayer().getBullet().move(-3,0);
          }
        break;
        case MOVE_RIGHT :
          if (currentState.getBlocType(currentState.getCurrentPlayer().getTank()) != state::RIGHT_BORDER)
          {
            currentState.getCurrentPlayer().getTank().move(3,0);
            currentState.getCurrentPlayer().getTurret().move(3,0);
            currentState.getCurrentPlayer().getBullet().move(3,0);
          }
        break;
        case TURN_ANTICLOCKWISE :
          if (currentState.getCurrentPlayer().getTurret().getPhi() > -180)
          {
            currentState.getCurrentPlayer().getTurret().turn(-3);
            currentState.getCurrentPlayer().getBullet().turn(-3);
          }
        break;
        case TURN_CLOCKWISE :
          if (currentState.getCurrentPlayer().getTurret().getPhi() < 0)
          {
            currentState.getCurrentPlayer().getTurret().turn(3);
            currentState.getCurrentPlayer().getBullet().turn(3);
          }
        break;
        case FIRE :
          currentState.getCurrentPlayer().getBullet().init();
          this->status = SHOOTING;
        break;
        default : return false;
      }
    break;

    case SHOOTING :
      if(currentState.getBlocType(currentState.getCurrentPlayer().getBullet()) == state::NOTHING && currentState.getCollision() == false)
      {
        currentState.getCurrentPlayer().getBullet().update();
        currentState.getCurrentPlayer().getBullet().move(currentState.getCurrentPlayer().getBullet().getVx(),currentState.getCurrentPlayer().getBullet().getVy());
      }
      else
      {
        if (currentState.getCollision() == true)
        {
          std::cout << "HIT from player " << currentState.getTurnID() << "!" << endl;
          currentState.getAdversePlayer().setLife(currentState.getAdversePlayer().getLife()-currentState.getCurrentPlayer().getDamage());
        }
        currentState.getCurrentPlayer().getBullet().setX(currentState.getCurrentPlayer().getTurret().getX());
        currentState.getCurrentPlayer().getBullet().setY(currentState.getCurrentPlayer().getTurret().getY());
        currentState.getCurrentPlayer().getBullet().setPhi(currentState.getCurrentPlayer().getTurret().getPhi());
        if (currentState.getAdversePlayer().getLife() > 0)
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
