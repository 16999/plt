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

state::State Engine::getCurrentState()
{
  return this->currentState;
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

bool Engine::update()
{
  switch (this->status)
  {
    case MOVING:
      this->record.addAction(this->action);
      if (this->action == MOVE_LEFT && this->currentState.getCurrentPlayer().getTank().getBlocType(this->currentState.getMap()) != state::LEFT_BORDER)
        this->currentState.getCurrentPlayer().getTank().update(-this->inc,0,0);
      else if (this->action == MOVE_RIGHT && this->currentState.getCurrentPlayer().getTank().getBlocType(this->currentState.getMap()) != state::RIGHT_BORDER)
        this->currentState.getCurrentPlayer().getTank().update(this->inc,0,0);
      else if (this->action == TURN_ANTICLOCKWISE && this->currentState.getCurrentPlayer().getTank().getTurret().getPhi() > -180)
        this->currentState.getCurrentPlayer().getTank().getTurret().update(0,0,-this->inc);
      else if (this->action == TURN_CLOCKWISE && this->currentState.getCurrentPlayer().getTank().getTurret().getPhi() < 0)
        this->currentState.getCurrentPlayer().getTank().getTurret().update(0,0,this->inc);
      else if (this->action == FIRE)
      {
        this->record.addTurn();
        this->t = 0;
        this->status = SHOOTING;
      }
      else
        return false;
    break;

    case SHOOTING :
      if(this->currentState.getCurrentPlayer().getTank().getTurret().getBullet().getBlocType(this->currentState.getMap()) == state::NOTHING && this->currentState.getCurrentPlayer().getTank().getTurret().getBullet().checkCollision(this->currentState.getAdversePlayer().getTank()) == false)
      {
        if (this->t == 0)
          this->theta = this->currentState.getCurrentPlayer().getTank().getTurret().getBullet().getPhi();
        this->vx = this->v0*cos(this->theta/RAD_TO_DEG);
        this->vy = this->v0*sin(this->theta/RAD_TO_DEG) + this->g * this->t;
        this->t++;
        this->currentState.getCurrentPlayer().getTank().getTurret().getBullet().setPhi(RAD_TO_DEG*atan(this->vy/this->vx)+180*(this->vx<0));
        this->currentState.getCurrentPlayer().getTank().getTurret().getBullet().update(this->vx,this->vy,0);
      }
      else
      {
        if (this->currentState.getCurrentPlayer().getTank().getTurret().getBullet().checkCollision(this->currentState.getAdversePlayer().getTank()) == true)
        {
          std::cout << "HIT from player " << this->currentState.getTurnID() << "!" << endl;
          this->currentState.getAdversePlayer().setLife(this->currentState.getAdversePlayer().getLife()-this->currentState.getCurrentPlayer().getDamage());
        }
        this->currentState.getCurrentPlayer().getTank().getTurret().replace();
        if (this->currentState.getAdversePlayer().getLife() > 0)
        {
          this->status = MOVING;
          this->currentState.nextTurnID();
        }
        else
        {
          this->status = GAMEOVER;
          this->record.addGame();
          this->currentState.endGame();
        }
      }
    break;

    case GAMEOVER :
      if(this->action == FIRE)
      {
          this->status = MOVING;
          this->currentState.startGame();
      }
    break;

    default : break;
  }

  return true;
}
