#include "HeuristicAI.h"
#include <math.h>
using namespace ai;
#define RAD_TO_DEG 57.2958


HeuristicAI::HeuristicAI()
{
  srand(time(NULL));
}

HeuristicAI::~HeuristicAI()
{

}

engine::Action HeuristicAI::run(state::State& aiState)
{
  if (this->iteration == 0)
  {
    switch(rand()%2)  //selectionne au hasard une action parmi un déplacement gauche/droite ou une rotation (anti)horaire
    {
      case 0 : this->preAction = engine::MOVE_LEFT; break;
      case 1 : this->preAction = engine::MOVE_RIGHT; break;
      default : break;
    }
  }

  if (this->iteration < 12)
  {
    this->action = this->preAction;
    this->iteration++;
  }
  else if (this->iteration == 12)
  {
    this->optimalAngle = RAD_TO_DEG*0.5*asin((aiState.getAdversePlayer().getTank().getX()-aiState.getCurrentPlayer().getTank().getX())*aiState.getCurrentPlayer().getBullet().getG()/pow(aiState.getCurrentPlayer().getBullet().getV0(),2)) - 90;
    this->epsilon = 2;
    this->iteration++;
  }
  else
  {
    if (this->optimalAngle - this->epsilon > aiState.getCurrentPlayer().getTurret().getPhi())
    {
      this->action = engine::TURN_CLOCKWISE;
    }
    else if (this->optimalAngle + this->epsilon < aiState.getCurrentPlayer().getTurret().getPhi())
    {
      this->action = engine::TURN_ANTICLOCKWISE;
    }
    else
    {
      this->action = engine::FIRE;
      this->iteration = 0;
    }
  }

  return this->action;
}
