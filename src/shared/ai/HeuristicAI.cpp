#include "HeuristicAI.h"
#include <math.h>
using namespace ai;
using namespace engine;
using namespace state;
#define RAD_TO_DEG 57.2958


HeuristicAI::HeuristicAI(int commandID)
{
  this->commandID = commandID;
  srand(time(NULL));
  this->maxIteration = 12;
  this->delta = 11;
  this->epsilon = 3;
}

HeuristicAI::~HeuristicAI()
{

}

Action HeuristicAI::run(state::State& currentState, Status status)
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
      this->optimalAngle = RAD_TO_DEG*0.5*asin((currentState.getAdversePlayer().getTank().getX()-currentState.getCurrentPlayer().getTank().getX())*currentState.getG()/pow(currentState.getSpeed(),2)) + rand()%this->delta - rand()%this->delta - 90;
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
        return FIRE;
      }
    }
  }
  else if (typeid(status) == typeid(new Gameover))
    return START_GAME;
  else
    return NO_ACTION;
}
