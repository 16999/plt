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

void AdvancedAI::run(engine::Engine& ngine)
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
        ngine.setAction(this->preAction);
      }
      else if (this->iteration == this->maxIteration)
      {
        this->optimalAngle = RAD_TO_DEG*0.5*asin((ngine.getCurrentState().getAdversePlayer().getTank().getX()-ngine.getCurrentState().getCurrentPlayer().getTank().getX())*this->w);
        if (this->optimalAngle > 0)
          this->optimalAngle = 0;
        else if (this->optimalAngle < -180)
          this->optimalAngle = -180;
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
          this->updateWeight = true;
          ngine.setAction(FIRE);
        }
      }
    break;
    case SHOOTING:
      if(this->updateWeight == true)
      {
        std::cout << "w = " << this->w << endl;
        this->w += this->k*this->lastBulletDelta;
        this->updateWeight = false;
      }
      this->lastBulletDelta = (ngine.getCurrentState().getCurrentPlayer().getTank().getTurret().getBullet().getX() - ngine.getCurrentState().getAdversePlayer().getTank().getX());
      ngine.setAction(NO_ACTION);
    break;
    case GAMEOVER:
      ngine.setAction(START_GAME);
    break;
    default :
      ngine.setAction(NO_ACTION);
    break;
  }
}
