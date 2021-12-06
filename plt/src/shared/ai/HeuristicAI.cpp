#include "HeuristicAI.h"
#include <math.h>
using namespace ai;

#include <iostream>
using namespace std;


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
    this->optimalAngle = 57.2958*0.5*atan((aiState.getPlayer(aiState.getTurnID()).getTank().getX()-aiState.getPlayer(1-aiState.getTurnID()).getTank().getX())*aiState.getPlayer(aiState.getTurnID()).getBullet().getG()/pow(aiState.getPlayer(aiState.getTurnID()).getBullet().getV0(),2)) - 180*(aiState.getTurnID() == 1);
    this->iteration++;
  }
  else
  {
    if (this->optimalAngle > aiState.getPlayer(aiState.getTurnID()).getTurret().getAngle() + this->epsilon)
    {
      this->action = engine::TURN_CLOCKWISE;
    }
    else if (this->optimalAngle < aiState.getPlayer(aiState.getTurnID()).getTurret().getAngle() - this->epsilon)
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
