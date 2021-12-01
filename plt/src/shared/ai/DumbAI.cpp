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
  {
    this->maxMove = 1 + rand()%50;
    this->maxTurn = this->maxMove + 1 + rand()%10;
    this->moveAction = engine::Action(1+rand()%2);
    this->turnAction = engine::Action(3+rand()%2);
  }

  if (this->iteration < this->maxTurn)
  {
    if (this->iteration < this->maxMove)
      this->action = this->moveAction;
    else
      this->action = this->turnAction;
    this->iteration++;
  }
  else
  {
    this->action = engine::FIRE;
    this->iteration = 0;
  }

  return this->action;
}
