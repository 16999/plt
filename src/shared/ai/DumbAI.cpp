#include "DumbAI.h"
using namespace ai;



DumbAI::DumbAI()
{
  srand(time(NULL));
}

DumbAI::~DumbAI()
{

}

engine::Action DumbAI::run(state::State& aiState)
{
  if (this->iteration == 0)
    this->selectedAction = engine::Action(1+rand()%4);  //selectionne au hasard une action parmi un déplacement gauche/droite ou une rotation (anti)horaire

  if (this->iteration < 12)
  {
    this->action = this->selectedAction;
    this->iteration++;
  }
  else
  {
    this->action = engine::FIRE;
    this->iteration = 0;
  }

  return this->action;
}
