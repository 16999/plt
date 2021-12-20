#include "DumbAI.h"
using namespace ai;
using namespace engine;


DumbAI::DumbAI()
{
  srand(time(NULL));
  this->maxIteration = 12;
}

DumbAI::~DumbAI()
{

}

void DumbAI::run(engine::Engine& ngine)
{
  switch (ngine.getStatus())
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
        ngine.setAction(this->preAction);
        this->iteration++;
      }
      else
      {
        ngine.setAction(FIRE);
        this->iteration = 0;
      }
    break;
    case GAMEOVER:
      ngine.setAction(FIRE);
    break;
    default :
      ngine.setAction(NOTHING);
    break;
  }
}
