#include "HeuristicAI.h"
#include <math.h>
using namespace ai;
#define RAD_TO_DEG 57.2958


HeuristicAI::HeuristicAI()
{
  srand(time(NULL));
  this->maxIteration = 12;
  this->epsilon = 20;
}

HeuristicAI::~HeuristicAI()
{

}

void HeuristicAI::run(engine::Engine& ngine)
{
  switch (ngine.getStatus())
  {
    case engine::MOVING:
      if (this->iteration == 0)
      {
        switch(rand()%2)  //selectionne au hasard une action parmi un déplacement gauche/droite ou une rotation (anti)horaire
        {
          case 0 : this->preAction = engine::MOVE_LEFT; break;
          case 1 : this->preAction = engine::MOVE_RIGHT; break;
          default : break;
        }
      }

      if (this->iteration < this->maxIteration)
      {
        ngine.setAction(this->preAction);
        this->iteration++;
      }
      else if (this->iteration == this->maxIteration)
      {
        this->optimalAngle = RAD_TO_DEG*0.5*asin((ngine.getCurrentState().getAdversePlayer().getTank().getX()-ngine.getCurrentState().getCurrentPlayer().getTank().getX())*this->physics.getG()/pow(this->physics.getV0(),2)) + rand()%this->epsilon - rand()%this->epsilon - 90;
        this->iteration++;
      }
      else
      {
        if (this->optimalAngle - this->physics.getInc() > ngine.getCurrentState().getCurrentPlayer().getTank().getTurret().getPhi())
          ngine.setAction(engine::TURN_CLOCKWISE);
        else if (this->optimalAngle + this->physics.getInc() < ngine.getCurrentState().getCurrentPlayer().getTank().getTurret().getPhi())
          ngine.setAction(engine::TURN_ANTICLOCKWISE);
        else
        {
          ngine.setAction(engine::FIRE);
          this->iteration = 0;
        }
      }
    break;
    case engine::GAMEOVER:
      ngine.setAction(engine::FIRE);
    break;
    default :
      ngine.setAction(engine::NOTHING);
    break;
  }
}
