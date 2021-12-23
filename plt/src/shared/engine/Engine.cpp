#include "Engine.h"
#include <iostream>
#include <math.h>
using namespace engine;
using namespace state;
using namespace std;
#define RAD_TO_DEG 57.2958



Engine::Engine()
{
  std::cout << "Engine launched" << endl;
  this->currentState.getCurrentPlayer().setStatus(GAMEOVER);
  this->currentState.getAdversePlayer().setStatus(AWAITING);
}

Engine::~Engine()
{
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

void Engine::update(Command* command)
{

  if(this->currentState.getTurnID() == command->getCommandID())
    this->action = command->run(this->currentState);

  switch (this->currentState.getCurrentPlayer().getStatus())
  {
    case MOVING:
      this->record.addAction(this->action);
      if (this->action == MOVE_LEFT && this->currentState.getCurrentPlayer().getTank().getBlocType(this->currentState.getMap()) != state::LEFT_BORDER)
        this->currentState.getCurrentPlayer().getTank().place(-this->currentState.getSpeed()/2,0,0);
      else if (this->action == MOVE_RIGHT && this->currentState.getCurrentPlayer().getTank().getBlocType(this->currentState.getMap()) != state::RIGHT_BORDER)
        this->currentState.getCurrentPlayer().getTank().place(this->currentState.getSpeed()/2,0,0);
      else if (this->action == TURN_ANTICLOCKWISE && this->currentState.getCurrentPlayer().getTank().getTurret().getPhi() > -180)
        this->currentState.getCurrentPlayer().getTank().getTurret().place(0,0,-this->currentState.getSpeed()/2);
      else if (this->action == TURN_CLOCKWISE && this->currentState.getCurrentPlayer().getTank().getTurret().getPhi() < 0)
        this->currentState.getCurrentPlayer().getTank().getTurret().place(0,0,this->currentState.getSpeed()/2);
      else if (this->action == FIRE)
      {
        this->record.addTurn();
        this->vx = this->currentState.getSpeed()*cos(this->currentState.getCurrentPlayer().getTank().getTurret().getBullet().getPhi()/RAD_TO_DEG);
        this->vy = this->currentState.getSpeed()*sin(this->currentState.getCurrentPlayer().getTank().getTurret().getBullet().getPhi()/RAD_TO_DEG);
        this->currentState.getCurrentPlayer().setStatus(SHOOTING);
      }
    break;

    case SHOOTING :
      if(this->currentState.getCurrentPlayer().getTank().getTurret().getBullet().getBlocType(this->currentState.getMap()) == state::NOTHING && this->currentState.getCurrentPlayer().getTank().getTurret().getBullet().intersects(this->currentState.getAdversePlayer().getTank()) == false)
      {
        this->vy += this->currentState.getG();
        this->currentState.getCurrentPlayer().getTank().getTurret().getBullet().setPhi(RAD_TO_DEG*atan(this->vy/this->vx)+180*(this->vx<0));
        this->currentState.getCurrentPlayer().getTank().getTurret().getBullet().place(this->vx,this->vy,0);
      }
      else
      {
        if (this->currentState.getCurrentPlayer().getTank().getTurret().getBullet().intersects(this->currentState.getAdversePlayer().getTank()) == true)
        {
          std::cout << "HIT from player " << this->currentState.getTurnID() << "!" << endl;
          this->currentState.getAdversePlayer().setLife(this->currentState.getAdversePlayer().getLife()-this->currentState.getCurrentPlayer().getDamage());
        }
        this->currentState.getCurrentPlayer().getTank().getTurret().replace();    //replace le tir à la même position et au même angle que la tourette lorsqu'une cible est touchée
        if (this->currentState.getAdversePlayer().getLife() > 0)
        {
          this->currentState.getCurrentPlayer().setStatus(AWAITING);
          this->currentState.getAdversePlayer().setStatus(MOVING);
          this->currentState.nextTurnID();
        }
        else
        {
          this->currentState.getCurrentPlayer().setStatus(GAMEOVER);
          this->record.addGame();
          this->currentState.endGame();
        }
      }
    break;

    case GAMEOVER :
      if(this->action == START_GAME)
      {
          this->currentState.getCurrentPlayer().setStatus(MOVING);
          this->currentState.startGame();
      }
    break;

    case AWAITING :
    break;

    default : break;
  }
}
