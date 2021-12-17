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
          if (currentState.getBlocType(currentState.getCurrentPlayer().getTank()) != state::LEFT_BORDER)
          {
            currentState.getCurrentPlayer().getTank().move(-this->inc,0);
            currentState.getCurrentPlayer().getTurret().move(-this->inc,0);
            currentState.getCurrentPlayer().getBullet().move(-this->inc,0);
          }
        break;
        case MOVE_RIGHT :
          if (currentState.getBlocType(currentState.getCurrentPlayer().getTank()) != state::RIGHT_BORDER)
          {
            currentState.getCurrentPlayer().getTank().move(this->inc,0);
            currentState.getCurrentPlayer().getTurret().move(this->inc,0);
            currentState.getCurrentPlayer().getBullet().move(this->inc,0);
          }
        break;
        case TURN_ANTICLOCKWISE :
          if (currentState.getCurrentPlayer().getTurret().getPhi() > -180)
          {
            currentState.getCurrentPlayer().getTurret().turn(-this->inc);
            currentState.getCurrentPlayer().getBullet().turn(-this->inc);
          }
        break;
        case TURN_CLOCKWISE :
          if (currentState.getCurrentPlayer().getTurret().getPhi() < 0)
          {
            currentState.getCurrentPlayer().getTurret().turn(this->inc);
            currentState.getCurrentPlayer().getBullet().turn(this->inc);
          }
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
      if(currentState.getBlocType(currentState.getCurrentPlayer().getBullet()) == state::NOTHING && currentState.getCollision() == false)
      {
        if (this->t == 0)
          this->theta = currentState.getCurrentPlayer().getBullet().getPhi();
        this->vx = this->v0*cos(this->theta/RAD_TO_DEG);
        this->vy = this->v0*sin(this->theta/RAD_TO_DEG) + this->g * this->t;
        this->t++;
        currentState.getCurrentPlayer().getBullet().setPhi(RAD_TO_DEG*atan(this->vy/this->vx)+180*(this->vx<0));
        currentState.getCurrentPlayer().getBullet().move(this->vx,this->vy);
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
          this->record.addGame();
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
