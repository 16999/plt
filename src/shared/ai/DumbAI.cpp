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
  switch(rand()%201)
  {
    case 0 ... 49 : this->action = engine::MOVE_LEFT; break;
    case 50 ... 99 : this->action = engine::MOVE_RIGHT; break;
    case 100 ... 149 : this->action = engine::TURN_ANTICLOCKWISE; break;
    case 150 ... 199 : this->action = engine::TURN_CLOCKWISE; break;
    default : this->action = engine::FIRE; break;
  }

  return this->action;
}
