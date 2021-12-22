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
  this->delta = 20;
  this->epsilon = 3;
}

HeuristicAI::~HeuristicAI()
{

}

void HeuristicAI::run(engine::Engine& ngine)
{
  switch (ngine.getCurrentState().getCurrentPlayer().getStatus())
  {
    case MOVING:
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
        ngine.setAction(this->preAction);
        this->iteration++;
      }
      else if (this->iteration == this->maxIteration)
      {
        this->optimalAngle = RAD_TO_DEG*0.5*asin((ngine.getCurrentState().getAdversePlayer().getTank().getX()-ngine.getCurrentState().getCurrentPlayer().getTank().getX())*this->physics.getG()/pow(this->physics.getV0(),2)) + rand()%this->delta - rand()%this->delta - 90;
        this->iteration++;
      }
      else
      {
        if (this->optimalAngle - this->epsilon > ngine.getCurrentState().getCurrentPlayer().getTank().getTurret().getPhi())
          ngine.setAction(TURN_CLOCKWISE);
        else if (this->optimalAngle + this->epsilon < ngine.getCurrentState().getCurrentPlayer().getTank().getTurret().getPhi())
          ngine.setAction(TURN_ANTICLOCKWISE);
        else
        {
          ngine.setAction(FIRE);
          this->iteration = 0;
        }
      }
    break;
    case GAMEOVER:
      ngine.setAction(FIRE);
    break;
    default :
      ngine.setAction(NO_ACTION);
    break;
  }
}
