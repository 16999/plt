#include "DumbAI.h"
using namespace ai;
using namespace engine;
using namespace state;



DumbAI::DumbAI(int commandID)
{
  this->commandID = commandID;
  srand(time(NULL));
  this->maxIteration = 12;
}

DumbAI::~DumbAI()
{

}

engine::Action DumbAI::run(state::State currentState)
{
  switch (currentState.getCurrentPlayer().getStatus())
  {
    case MOVING:
      if (this->iteration == 0)
      {
        switch(rand()%4)  //selectionne au hasard une action parmi un déplacement gauche/droite ou une rotation (anti)horaire
        {
          case 0 : this->preAction = MOVE_LEFT; break;
          case 1 : this->preAction = MOVE_RIGHT; break;
          case 2 : this->preAction = TURN_ANTICLOCKWISE; break;
          case 3 : this->preAction = TURN_CLOCKWISE; break;
          default : break;
        }
      }

      if (this->iteration < this->maxIteration)
      {
        this->iteration++;
        return this->preAction;
      }
      else
      {
        this->iteration = 0;
        return FIRE;
      }
    break;
    case GAMEOVER:
      return START_GAME;
    break;
    default :
      return NO_ACTION;
    break;
  }
}
