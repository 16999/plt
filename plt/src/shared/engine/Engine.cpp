#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
using namespace engine;
using namespace std;
#define RAD_TO_DEG 57.2958



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

void Engine::setAction(Action action)
{
  this->action = action;
}

Action Engine::getAction() const
{
  return this->action;
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

bool Engine::update(state::State& currentState, Action action)
{
  switch (this->status)
  {
    case MOVING:
      this->record.addAction(action);
      switch(action)
      {
        case MOVE_LEFT :
          currentState.getCurrentPlayer().getTank().update(-this->inc,0,0,currentState.getMap());
        break;
        case MOVE_RIGHT :
          currentState.getCurrentPlayer().getTank().update(this->inc,0,0,currentState.getMap());
        break;
        case TURN_ANTICLOCKWISE :
          currentState.getCurrentPlayer().getTank().getTurret().update(0,0,-this->inc,currentState.getMap());
        break;
        case TURN_CLOCKWISE :
          currentState.getCurrentPlayer().getTank().getTurret().update(0,0,this->inc,currentState.getMap());
        break;
        case FIRE :
          this->record.addTurn();
          this->t = 0;
          this->status = SHOOTING;
        break;
        default : return false;
      }
    break;

    case SHOOTING :
      if(currentState.getCurrentPlayer().getTank().getTurret().getBullet().getBlocType(currentState.getMap()) == state::NOTHING && currentState.getCollision() == false)
      {
        if (this->t == 0)
          this->theta = currentState.getCurrentPlayer().getTank().getTurret().getBullet().getPhi();
        this->vx = this->v0*cos(this->theta/RAD_TO_DEG);
        this->vy = this->v0*sin(this->theta/RAD_TO_DEG) + this->g * this->t;
        this->t++;
        currentState.getCurrentPlayer().getTank().getTurret().getBullet().setPhi(RAD_TO_DEG*atan(this->vy/this->vx)+180*(this->vx<0));
        currentState.getCurrentPlayer().getTank().getTurret().getBullet().update(this->vx,this->vy,0,currentState.getMap());
      }
      else
      {
        if (currentState.getCollision() == true)
        {
          std::cout << "HIT from player " << currentState.getTurnID() << "!" << endl;
          currentState.getAdversePlayer().setLife(currentState.getAdversePlayer().getLife()-currentState.getCurrentPlayer().getDamage());
        }
        currentState.getCurrentPlayer().getTank().getTurret().getBullet().setX(currentState.getCurrentPlayer().getTank().getTurret().getX());
        currentState.getCurrentPlayer().getTank().getTurret().getBullet().setY(currentState.getCurrentPlayer().getTank().getTurret().getY());
        currentState.getCurrentPlayer().getTank().getTurret().getBullet().setPhi(currentState.getCurrentPlayer().getTank().getTurret().getPhi());
        if (currentState.getAdversePlayer().getLife() > 0)
        {
          this->status = MOVING;
          currentState.nextTurnID();
        }
        else
        {
          this->status = GAMEOVER;
          this->record.addGame();
          currentState.endGame(currentState.getTurnID());
        }
      }
    break;

    case GAMEOVER :
      if(action == FIRE)
      {
          this->status = MOVING;
          currentState.startGame();
      }
    break;

    default : break;
  }

  return true;
}
