#include "AdvancedAI.h"
#include <math.h>
#include <iostream>
using namespace std;
using namespace ai;
using namespace engine;
using namespace state;
#define RAD_TO_DEG 57.2958


AdvancedAI::AdvancedAI(int commandID)
{
  this->commandID = commandID;
  srand(time(NULL));
  this->maxIteration = 12;
  this->epsilon = 3;
}

AdvancedAI::~AdvancedAI()
{

}

Action AdvancedAI::run(state::State& currentState, Status status)
{
  if (typeid(status) == typeid(new Moving))
  {
    if (this->iteration == 0)
    {
      switch(rand()%2)  //selectionne au hasard une action parmi un déplacement gauche/droite ou une rotation (anti)horaire
      {
        case 0 : this->preAction = MOVE_LEFT; break;
        case 1 : this->preAction = MOVE_RIGHT; break;
        default : break;
      }
    }

    if (this->iteration < this->maxIteration)
    {
      this->iteration++;
      return this->preAction;
    }
    else if (this->iteration == this->maxIteration)
    {
      this->optimalAngle = RAD_TO_DEG*0.5*asin((currentState.getAdversePlayer().getTank().getX()-currentState.getCurrentPlayer().getTank().getX())*this->w);
      if (this->optimalAngle > 0)
        this->optimalAngle = 0;
      else if (this->optimalAngle < -180)
        this->optimalAngle = -180;
      this->iteration++;
      return NO_ACTION;
    }
    else
    {
      if (this->optimalAngle - this->epsilon > currentState.getCurrentPlayer().getTank().getTurret().getPhi())
        return TURN_CLOCKWISE;
      else if (this->optimalAngle + this->epsilon < currentState.getCurrentPlayer().getTank().getTurret().getPhi())
        return TURN_ANTICLOCKWISE;
      else
      {
        this->iteration = 0;
        this->updateWeight = true;
        return FIRE;
      }
    }
  }
  else if (typeid(status) == typeid(new Shooting))
  {
    if(this->updateWeight == true)
    {
      std::cout << "w = " << this->w << endl;
      this->w += this->k*this->lastBulletDelta;
      this->updateWeight = false;
    }
    this->lastBulletDelta = (currentState.getCurrentPlayer().getTank().getTurret().getBullet().getX() - currentState.getAdversePlayer().getTank().getX());
    return NO_ACTION;
  }
  else if (typeid(status) == typeid(new Gameover))
    return START_GAME;
  else
    return NO_ACTION;
}
