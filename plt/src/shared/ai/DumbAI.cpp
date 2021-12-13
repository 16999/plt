#include "DumbAI.h"
using namespace ai;



DumbAI::DumbAI()
{
  srand(time(NULL));
  this->maxIteration = 12;
}

DumbAI::~DumbAI()
{

}

engine::Action DumbAI::run(state::State& aiState)
{
  if (this->iteration == 0)
  {
    switch(rand()%4)  //selectionne au hasard une action parmi un déplacement gauche/droite ou une rotation (anti)horaire
    {
      case 0 : this->preAction = engine::MOVE_LEFT; break;
      case 1 : this->preAction = engine::MOVE_RIGHT; break;
      case 2 : this->preAction = engine::TURN_ANTICLOCKWISE; break;
      case 3 : this->preAction = engine::TURN_CLOCKWISE; break;
      default : break;
    }
  }

  if (this->iteration < this->maxIteration)
  {
    this->action = this->preAction;
    this->iteration++;
  }
  else
  {
    this->action = engine::FIRE;
    this->iteration = 0;
  }

  return this->action;
}
