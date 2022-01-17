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

void HeuristicAI::run(engine::Engine& ngine)
{
  switch (ngine.getStatus())
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
        this->iteration++;
        return this->preAction;
      }
      else if (this->iteration == this->maxIteration)
      {
        this->optimalAngle = RAD_TO_DEG*0.5*asin((ngine.getCurrentState().getAdversePlayer().getTank().getX()-ngine.getCurrentState().getCurrentPlayer().getTank().getX())*ngine.getCurrentState().getG()/pow(ngine.getCurrentState().getSpeed(),2)) + rand()%this->delta - rand()%this->delta - 90;
        this->iteration++;
        ngine.setAction(NO_ACTION);
      }
      else
      {
        if (this->optimalAngle - this->epsilon > ngine.getCurrentState().getCurrentPlayer().getTank().getTurret().getPhi())
          ngine.setAction(TURN_CLOCKWISE);
        else if (this->optimalAngle + this->epsilon < ngine.getCurrentState().getCurrentPlayer().getTank().getTurret().getPhi())
          ngine.setAction(TURN_ANTICLOCKWISE);
        else
        {
          this->iteration = 0;
          ngine.setAction(FIRE);
        }
      }
    break;
    case GAMEOVER:
      ngine.setAction(START_GAME);
    break;
    default :
      ngine.setAction(NO_ACTION);
    break;
  }
}
