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

engine::Action AdvancedAI::run(state::State currentState)
{
  switch (currentState.getCurrentPlayer().getStatus())
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
        this->optimalAngle = RAD_TO_DEG*0.5*asin((currentState.getAdversePlayer().getTank().getX()-currentState.getCurrentPlayer().getTank().getX())*this->w);
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
    break;
    case SHOOTING:
      std::cout << "w = " << this->w << endl;
      if(currentState.getCurrentPlayer().getTank().getTurret().getBullet().getBlocType(currentState.getMap()) != state::NOTHING || currentState.getCurrentPlayer().getTank().getTurret().getBullet().intersects(currentState.getAdversePlayer().getTank()) == true)
      {
        this->w += this->k*(currentState.getCurrentPlayer().getTank().getTurret().getBullet().getX() - currentState.getAdversePlayer().getTank().getX());
      }
      return NO_ACTION;
    break;
    case GAMEOVER:
      return START_GAME;
    break;
    default :
      return NO_ACTION;
    break;
  }
}
